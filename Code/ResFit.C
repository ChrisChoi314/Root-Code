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
   TH1F* dedx75Plot[nbins];
   for( int i = 0; i < nbins; ++i ){
     dedx75Plot[i] = new TH1F(TString::Format("dedx%d",i),TString::Format("pbin1 %d; dE/dx;",i),100,0,2);
   }
   TH1F* dedx55Plot[nbins];
   for( int i = 0; i < nbins; ++i ){
     dedx55Plot[i] = new TH1F(TString::Format("dedxL%d",i),TString::Format("pbin1 %d;dE/dxL;",i),100,0,2);
   }

   TH1F* dedxL75Plot[nbins];
   for( int i = 0; i < nbins; ++i ){
     dedxL75Plot[i] = new TH1F(TString::Format("dedx1%d",i),TString::Format("pbin1 %d; dE/dx;",i),100,0,2);
   }
   TH1F* dedxL55Plot[nbins];
   for( int i = 0; i < nbins; ++i ){
     dedxL55Plot[i] = new TH1F(TString::Format("dedxL1%d",i),TString::Format("pbin1 %d;dE/dxL;",i),100,0,2);
   }

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   int nLooped = 0;
   int nBad75 = 0;
   int nBad55 = 0;
   int nBadL75 = 0;
   int nBadL55 = 0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      // Check if layer-level can be reproduced

      nLooped += 1;
      double_t mydedx75 = MyLayers(.05,.75);
      if(fabs( (mydedx75 - dedxnosat) ) > 1.e-6){
        nBad75 += 1;                               //originally nBadLay
      }
      double_t mydedx55 = MyLayers(.05,.55);
      if(fabs( (mydedx55 - dedxnosat) ) > 1.e-6){
         nBad55 += 1;
      }
      double_t mydedxL75 = MyLayersFull(0,.05,.75);
      if(fabs( (mydedxL75 - dedxnosat) ) > 1.e-6){
        nBadL75 += 1;                               //originally nBadLay
      }
      double_t mydedxL55 = MyHits(0,.05,.75);
      if(fabs( (mydedxL55 - dedxnosat) ) > 1.e-6){
         nBadL55 += 1;
      }
   }
   cout << "LAYER CHECK MyLayers: reproduce results tolerance 1e-6" << endl;
   cout << "From .55 data:  " << nBad55 //Raw
        << " bad out of " << nLooped << endl;
   cout << "From .75 data:  " << nBad75  //Lay
        << " bad out of " << nLooped << endl;
   cout << "LAYER CHECK MyLayersFull: reproduce results tolerance 1e-6" << endl;
   cout << "From .55 data:  " << nBadL55 //Raw
        << " bad out of " << nLooped << endl;
   cout << "From .75 data:  " << nBadL75  //Lay
        << " bad out of " << nLooped << endl;

   for (Long64_t jentry=0; jentry<2000000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if( (jentry/100000)*100000 == jentry ) cout << jentry << endl;
      for( int i = 0; i < nbins; ++i ){
      	if(inCDC && fabs(dr)<1 && fabs(dz)<1){
      	  if (pF>=(lowedge+i*step)&&pF<(lowedge+(i+1)*step)) {
             double_t mydedx75 = MyLayers(.05,.75);
             double_t mydedx55 = MyLayers(.05,.55);
             double_t mydedxL75 = MyLayersFull(0,.05,.75);
             double_t mydedxL55 = MyHits(0,.05,.75);
               dedx75Plot[i]->Fill(mydedx75);
               dedx55Plot[i]->Fill(mydedx55);
               dedxL75Plot[i]->Fill(mydedxL75);
               dedxL55Plot[i]->Fill(mydedxL55);
      	  }
      	}
      }

// EVENT LOOP
   }
   TH1F * meanplot75 = new TH1F("meanplot","meanplot",nbins, lowedge, highedge);
   TH1F * meanplot55 = new TH1F("meanplotL","meanplotL",nbins, lowedge, highedge);

   TH1F * resplot75 = new TH1F("resplot","resplot",nbins, lowedge, highedge);
   TH1F * resplot55 = new TH1F("resplotL","resplotL",nbins, lowedge, highedge);

   TH1F * resomean75 = new TH1F("resomean","resomean",nbins, lowedge, highedge);
   TH1F * resomean55 = new TH1F("resomeanL","resomeanL",nbins, lowedge, highedge);

   TH1F * ratio = new TH1F("ratio","ratio", nbins, lowedge, highedge);

   TH1F * meanplotL75 = new TH1F("meanplot1","meanplot1",nbins, lowedge, highedge);
   TH1F * meanplotL55 = new TH1F("meanplotL1","meanplotL1",nbins, lowedge, highedge);

   TH1F * resplotL75 = new TH1F("resplot1","resplot1",nbins, lowedge, highedge);
   TH1F * resplotL55 = new TH1F("resplotL1","resplotL1",nbins, lowedge, highedge);

   TH1F * resomeanL75 = new TH1F("resomean1","resomean1",nbins, lowedge, highedge);
   TH1F * resomeanL55 = new TH1F("resomeanL1","resomeanL1",nbins, lowedge, highedge);

   TH1F * ratioL = new TH1F("ratioL","ratioL", nbins, lowedge, highedge);

//Fitting:
   double_t mu, bincent, muerr, binerr, res, reserr;
   double_t mu1, bincent1, muerr1, binerr1, res1, reserr1;

   for( int i = 0; i < nbins; ++i ){
       dedx75Plot[i]->Fit("gaus");
       TF1 * fit = dedx75Plot[i]->GetFunction("gaus");
       mu = fit->GetParameter(1);
       muerr = fit->GetParError(1);
       res = fit->GetParameter(2);
       reserr = fit->GetParError(2);
       bincent = lowedge+0.5*step+i*step;
       meanplot75 -> Fill(bincent,mu);
       meanplot75 -> SetBinError(i+1,muerr);
       resplot75 -> Fill(bincent,res);
       resplot75 -> SetBinError(i+1,reserr);
       resomean75->Fill(bincent, res/mu);

       dedx55Plot[i]->Fit("gaus");
       TF1 * fit1 = dedx55Plot[i]->GetFunction("gaus");
       mu1 = fit1->GetParameter(1);
       muerr1 = fit1->GetParError(1);
       res1 = fit1->GetParameter(2);
       reserr1 = fit1->GetParError(2);
       bincent1 = lowedge+0.5*step+i*step;
       meanplot55 -> Fill(bincent1,mu1);
       meanplot55 -> SetBinError(i+1,muerr1);
       resplot55 -> Fill(bincent1,res1);
       resplot55 -> SetBinError(i+1,reserr1);
       resomean55->Fill(bincent1, res1/mu1);

       ratio -> Fill(bincent1, (res1/mu1)/(res/mu));

       dedxL75Plot[i]->Fit("gaus");
       TF1 * fit2 = dedxL75Plot[i]->GetFunction("gaus");
       fit2 ->SetLineColor(kViolet);
       mu = fit2->GetParameter(1);
       muerr = fit2->GetParError(1);
       res = fit2->GetParameter(2);
       reserr = fit2->GetParError(2);
       bincent = lowedge+0.5*step+i*step;
       meanplotL75 -> Fill(bincent,mu);
       meanplotL75 -> SetBinError(i+1,muerr);
       resplotL75 -> Fill(bincent,res);
       resplotL75 -> SetBinError(i+1,reserr);
       resomeanL75->Fill(bincent, res/mu);

       dedxL55Plot[i]->Fit("gaus");
       TF1 * fit3 = dedxL55Plot[i]->GetFunction("gaus");
       fit3 ->SetLineColor(kViolet);
       mu1 = fit3->GetParameter(1);
       muerr1 = fit3->GetParError(1);
       res1 = fit3->GetParameter(2);
       reserr1 = fit3->GetParError(2);
       bincent1 = lowedge+0.5*step+i*step;
       meanplotL55 -> Fill(bincent1,mu1);
       meanplotL55 -> SetBinError(i+1,muerr1);
       resplotL55 -> Fill(bincent1,res1);
       resplotL55 -> SetBinError(i+1,reserr1);
       resomeanL55->Fill(bincent1, res1/mu1);

       ratioL -> Fill(bincent1, (res1/mu1)/(res/mu));
   }

   meanplot75 -> GetYaxis() -> SetRangeUser(0,2);
   meanplotL75 -> GetYaxis() -> SetRangeUser(.8,1.2);

   resplot75 -> GetYaxis() -> SetRangeUser(0,0.2);
   resplotL75 -> GetYaxis() -> SetRangeUser(0.04,0.12);

   resomean75 -> GetYaxis() -> SetRangeUser(0,0.2);
   resomeanL75 -> GetYaxis() -> SetRangeUser(.04,0.12);

   ratio -> GetYaxis() -> SetRangeUser(0.9,1.1);

   meanplot55 -> GetYaxis() -> SetRangeUser(0,2);
   meanplotL55 -> GetYaxis() -> SetRangeUser(.8,1.2);

   resplot55 -> GetYaxis() -> SetRangeUser(0,0.2);
   resplotL55 -> GetYaxis() -> SetRangeUser(0.04,0.12);

   resomean55 -> GetYaxis() -> SetRangeUser(0,0.2);
   resomeanL55 -> GetYaxis() -> SetRangeUser(0.04,0.12);

   ratioL -> GetYaxis() -> SetRangeUser(0.9,1.1);

   /*meanplot -> GetYaxis() -> SetRangeUser(.85,1.15);
   resplot -> GetYaxis() -> SetRangeUser(.5,.15);
   resomean -> GetYaxis() -> SetRangeUser(0,0.2);*/

   //Plotting Mean vs Momentum and resolution plots!
   /*TCanvas* p2 = new TCanvas("Mean vs Momentum","", 650,600);
   p2->Divide(1,4);
   p2->cd(1);
   meanplot75->Draw();
   meanplot55->SetMarkerColor(kRed);
   meanplot55->SetLineColor(kRed);
   meanplot55->Draw("same");
   p2->cd(2);
   resplot75->Draw();
   resplot55->SetMarkerColor(kRed);
   resplot55->SetLineColor(kRed);
   resplot55->Draw("same");
   p2->cd(3);
   gPad->SetGrid();
   resomean75->Draw();
   resomean55->SetMarkerColor(kRed);
   resomean55->SetLineColor(kRed);
   resomean55->Draw("same");
   p2-> cd(4);
   gPad->SetGrid();
   ratio->Draw();
   p2 -> SaveAs("dedx_55vs75.pdf");*/

   TCanvas* p3 = new TCanvas("Mean vs Momentum L","", 650,600);
   p3->Divide(1,4);
   p3->cd(1);
   meanplotL75->Draw();
   meanplotL55->SetMarkerColor(kRed);
   meanplotL55->SetLineColor(kRed);
   meanplotL55->Draw("same");
   p3->cd(2);
   resplotL75->Draw();
   resplotL55->SetMarkerColor(kRed);
   resplotL55->SetLineColor(kRed);
   resplotL55->Draw("same");
   p3->cd(3);
   resomeanL75->Draw();
   resomeanL55->SetMarkerColor(kRed);
   resomeanL55->SetLineColor(kRed);
   resomeanL55->Draw("same");
   p3-> cd(4);
   ratioL->Draw();
}
