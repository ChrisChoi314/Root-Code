#define ResFit_cxx
#include "ResFit.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TH1D.h>

#include <TProfile.h>
#include <TRandom.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "TVector3.h"
#include "TMath.h"


void ResFit::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L ResFit.C
//      Root > ResFit t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   const int nbins = 80;
   double lowedge = -8.0;
   double highedge = 8.0;
   double step = (highedge -lowedge)/nbins;
   TH1F* dedxPlot[nbins];
   for( int i = 0; i < nbins; ++i ){
     dedxPlot[i] = new TH1F(TString::Format("dedx%d",i),TString::Format("pbin1 %d; dE/dx;",i),100,0,2);
   }
   TH1F* dedxLPlot[nbins];
   for( int i = 0; i < nbins; ++i ){
     dedxLPlot[i] = new TH1F(TString::Format("dedxL%d",i),TString::Format("pbin1 %d;dE/dxL;",i),100,0,2);
   }

   /*double coslowedge = -.9;
   double coshighedge = 1.0;
   double cosstep = (coshighedge - coslowedge)/nbins;
   TH1F* cosPlot[nbins];
   for( int i = 0; i < nbins; ++i ){
     cosPlot[i] = new TH1F(TString::Format("costh%d",i),TString::Format("cbin1 %d costh",i),100,0,2);
   }*/

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   int nLooped = 0;
   int nBadLay = 0;
   int nBadRaw = 0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      // Check if layer-level can be reproduced

      nLooped += 1;
      double_t mydedx = MyLayers(.05,.75);
      if(fabs( (mydedx - dedxnosat) ) > 1.e-6){
        nBadLay += 1;
      }
      double_t mydedx2 = MyLayersFull(0,.05,.75);
      if(fabs( (mydedx2 - dedxnosat) ) > 1.e-6){
         nBadRaw += 1;
      }
   }
   cout << "LAYER CHECK: reproduce results tolerance 1e-6" << endl;
   cout << "From Raw data:  " << nBadRaw //Raw
        << " bad out of " << nLooped << endl;
   cout << "From Lay data:  " << nBadLay  //Lay
        << " bad out of " << nLooped << endl;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if( (jentry/100000)*100000 == jentry ) cout << jentry << endl;
      double_t mydedx = MyLayersFull(0,.05,.75);
      for( int i = 0; i < nbins; ++i ){
      	if(inCDC && fabs(dr)<1 && fabs(dz)<1){
      	  if (pF>=(lowedge+i*step)&&pF<(lowedge+(i+1)*step)) {
               //Fill first set of dedx values here (currently set to default dedxnosat)!!
               dedxPlot[i]->Fill(dedxnosat);
               //Fill second set of dedx values here (currently set to layer recalculation)!!
               dedxLPlot[i]->Fill(mydedx);
      	  }
      	}
      }

// EVENT LOOP
   }
   TH1F * meanplot = new TH1F("meanplot","meanplot",nbins, lowedge, highedge);
   TH1F * meanplotL = new TH1F("meanplotL","meanplotL",nbins, lowedge, highedge);

   TH1F * resplot = new TH1F("resplot","resplot",nbins, lowedge, highedge);
   TH1F * resplotL = new TH1F("resplotL","resplotL",nbins, lowedge, highedge);

   TH1F * resomean = new TH1F("resomean","resomean",nbins, lowedge, highedge);
   TH1F * resomeanL = new TH1F("resomeanL","resomeanL",nbins, lowedge, highedge);

   TH1F * ratio = new TH1F("ratio","ratio", nbins, lowedge, highedge);

//Fitting:
   double_t mu, bincent, muerr, binerr, res, reserr;
   double_t muL, bincentL, muerrL, binerrL, resL, reserrL;

   for( int i = 0; i < nbins; ++i ){
       dedxPlot[i]->Fit("gaus");
       TF1 * fit = dedxPlot[i]->GetFunction("gaus");
       mu = fit->GetParameter(1);
       muerr = fit->GetParError(1);
       res = fit->GetParameter(2);
       reserr = fit->GetParError(2);
       bincent = lowedge+0.5*step+i*step;
       //binerr=0;
       meanplot -> Fill(bincent,mu);
       meanplot -> SetBinError(i+1,muerr);
       resplot -> Fill(bincent,res);
       resplot -> SetBinError(i+1,reserr);
       resomean->Fill(bincent, res/mu);


       dedxLPlot[i]->Fit("gaus");
       TF1 * fitL = dedxLPlot[i]->GetFunction("gaus");
       fitL ->SetLineColor(kViolet);
       muL = fitL->GetParameter(1);
       muerrL = fitL->GetParError(1);
       resL = fitL->GetParameter(2);
       reserrL = fitL->GetParError(2);
       bincentL = lowedge+0.5*step+i*step;
       //binerrL=0;
       meanplotL -> Fill(bincentL,muL);
       meanplotL -> SetBinError(i+1,muerrL);
       resplotL -> Fill(bincentL,resL);
       resplotL -> SetBinError(i+1,reserrL);
       resomeanL->Fill(bincentL, resL/muL);

       ratio -> Fill(bincentL, (resL/muL)/(res/mu));
   }

   meanplot -> GetYaxis() -> SetRangeUser(0,2);
   meanplotL -> GetYaxis() -> SetRangeUser(0,2);

   resplot -> GetYaxis() -> SetRangeUser(0,0.2);
   resplotL -> GetYaxis() -> SetRangeUser(0,0.2);

   resomean -> GetYaxis() -> SetRangeUser(0,0.2);
   resomeanL -> GetYaxis() -> SetRangeUser(0,0.2);

   ratio -> GetYaxis() -> SetRangeUser(0.9,1.1);

   /*meanplot -> GetYaxis() -> SetRangeUser(.85,1.15);
   resplot -> GetYaxis() -> SetRangeUser(.5,.15);
   resomean -> GetYaxis() -> SetRangeUser(0,0.2);*/

   //Plotting Mean vs Momentum and resolution plots!
   TCanvas* p2 = new TCanvas("Mean vs Momentum","", 650,600);
   p2->Divide(1,4);
   p2->cd(1);
   meanplot->Draw();
   meanplotL->SetMarkerColor(kRed);
   meanplotL->SetLineColor(kRed);
   meanplotL->Draw("same");
   p2->cd(2);
   resplot->Draw();
   resplotL->SetMarkerColor(kRed);
   resplotL->SetLineColor(kRed);
   resplotL->Draw("same");
   p2->cd(3);
   gPad->SetGrid();
   resomean->Draw();
   resomeanL->SetMarkerColor(kRed);
   resomeanL->SetLineColor(kRed);
   resomeanL->Draw("same");
   p2-> cd(4);
   gPad->SetGrid();
   ratio->Draw();
   p2 -> SaveAs("MeanResPlot10.pdf");


//Plotting dedx histograms
   TCanvas* p3 = new TCanvas("dedx Plot", "", 650, 600);
   p3 -> Divide(2,4);
   p3-> cd(1);
   dedxPlot[0] -> Draw();
   dedxLPlot[0] -> SetLineColor(kBlack);
   dedxLPlot[0]->Draw("same");
   p3 -> Print("dedxplots55.pdf[");
   for (int i = 1; i<nbins; i++){
      p3->cd(i%8+1);
      dedxPlot[i] -> Draw();
      dedxLPlot[i] -> SetLineColor(kBlack);
      dedxLPlot[i]->Draw("same");
      if((i+1)%8 ==0){
         p3->Print("dedxplots55.pdf");
         gPad->Clear();
      }
   }
   p3 -> Print("dedxplots55.pdf]");
   gPad->Clear();

   /*TCanvas* p2 = new TCanvas("Mean vs Momentum","", 650,600);
   p2->Divide(1,4);
   p2->cd(1);
   meanplot->Draw();
   p2->cd(2);
   resplot->Draw();
   p2->SaveAs("TruncationPlot1.pdf");

   TCanvas* p1 = new TCanvas("blank canvas to prevent overwriting","", 650,600);

   TH1F * cosmeanplot = new TH1F("cosmeanplot","cosmeanplot",nbins, coslowedge, coshighedge);
   TH1F * cosresplot = new TH1F("cosresplot","cosresplot",nbins, coslowedge, coshighedge);
   TH1F * cosresomean = new TH1F("cosresomean","cosresomean",nbins,coslowedge, coshighedge);

//Fitting for costh:
   for( int i = 0; i < nbins; ++i ){
       cosPlot[i]->Fit("gaus");
       TF1 * cosfit = cosPlot[i]->GetFunction("gaus");
       mu = cosfit->GetParameter(1);
       muerr = cosfit->GetParError(1);
       res = cosfit->GetParameter(2);
       reserr = cosfit->GetParError(2);
       bincent = coslowedge+0.5*cosstep+i*cosstep;

       cosmeanplot -> Fill(bincent,mu);
       cosmeanplot -> SetBinError(i+1,muerr);
       cosresplot -> Fill(bincent,res);
       cosresplot -> SetBinError(i+1,reserr);
       cosresomean->Fill(bincent, res/mu);
   }

   cosmeanplot -> GetYaxis() -> SetRangeUser(.85,1.15);
   cosresplot -> GetYaxis() -> SetRangeUser(.5,.15);
   cosresomean -> GetYaxis() -> SetRangeUser(0,0.2);

   //Plotting Mean vs Momentum and resolution plots!
   TCanvas* p3 = new TCanvas("Mean vs Cos theta","", 650,600);
   p3->Divide(1,2);
   p3->cd(1);
   cosmeanplot->Draw();
   p3->cd(2);
   cosresplot->Draw();
   p3->SaveAs("ResFit_Cos.pdf");?*/

}
