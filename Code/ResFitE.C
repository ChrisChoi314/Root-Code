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
   const int nbins = 80;
   double lowedge = -.8;
   double highedge = .9;
   double step = (highedge -lowedge)/nbins;
   TH1F* dedx75Plot[nbins];
   for( int i = 0; i < nbins; ++i ){
     dedx75Plot[i] = new TH1F(TString::Format("dedx%d",i),TString::Format("cos bin1 %d; dE/dx;",i),100,0,2);
   }
   TH1F* dedx55Plot[nbins];
   for( int i = 0; i < nbins; ++i ){
     dedx55Plot[i] = new TH1F(TString::Format("dedxL%d",i),TString::Format("cos bin1 %d;dE/dxL;",i),100,0,2);
   }


   if (fChain == 0) return;
   Long64_t nbytes = 0, nb = 0;
   Long64_t nentries = fChain->GetEntriesFast();

   for (Long64_t jentry=0; jentry<1000000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //if( (jentry/100000)*100000 == jentry ) cout << jentry << endl;
      for( int i = 0; i < nbins; ++i ){
      	if (inCDC && fabs(dr)<1 && fabs(dz)<1 && fabs(pF) <= 3){
      	  if (costh>=(lowedge+i*step)&&costh<(lowedge+(i+1)*step)) {
             double_t mydedx75 = MyLayersFull(0,.05,.75);
             double_t mydedx55 = MyLayers(.05,.75);
               dedx75Plot[i]->Fill(mydedx75);
               dedx55Plot[i]->Fill(mydedx55);
               sanCheck->Fill(pF);
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
   }

   meanplot75 -> GetYaxis() -> SetRangeUser(.6,1.2);
   resplot75 -> GetYaxis() -> SetRangeUser(0.04,0.15);
   resomean75 -> GetYaxis() -> SetRangeUser(0.04,0.18);
   ratio -> GetYaxis() -> SetRangeUser(0.9,1.1);

   meanplot55 -> GetYaxis() -> SetRangeUser(.6,1.2);
   resplot55 -> GetYaxis() -> SetRangeUser(0.04,0.15);
   resomean55 -> GetYaxis() -> SetRangeUser(0.04,0.18);
   /*meanplot -> GetYaxis() -> SetRangeUser(.85,1.15);
   resplot -> GetYaxis() -> SetRangeUser(.5,.15);
   resomean -> GetYaxis() -> SetRangeUser(0,0.2);*/

   //Plotting Mean vs Momentum and resolution plots!
   TCanvas* p2 = new TCanvas("Mean vs Cos","", 650,600);
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
   p2 -> SaveAs("dedxMLFvML-Cos.pdf");

   TCanvas* p3= new TCanvas("Momentum","", 650,600);
   sanCheck -> Draw();
}
