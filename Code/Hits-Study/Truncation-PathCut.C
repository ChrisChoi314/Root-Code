#define Truncation_cxx
#include "Truncation.h"

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include <TStyle.h>
#include "TChain.h"
#include "TList.h"
#include "TDirectory.h"
#include "TSystemDirectory.h"
#include <TROOT.h>
#include "TMath.h"
#include "TLegend.h"
#include <TF1.h>
#include <TH1D.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

void Truncation::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Truncation.C
//      Root > Truncation t
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
   double lowedge = -8.;
   double highedge = 8.;
   int hitMode[] = {0,1,2,3};
   int modeNum = 4; //10
   double step = (highedge - lowedge)/nbins;
   TH1F* dedxPlot[modeNum][nbins];
   TH1F* dedxHist[modeNum];
   for (int i = 0; i < modeNum; ++i) {
      for ( int j = 0; j < nbins; ++j ){
        dedxPlot[i][j] = new TH1F(TString::Format("dedx %d %d",i, j),
                              TString::Format("momentum bin %f-%f {Myhits mode: %d}"
                              ,lowedge+step*j,lowedge+step*(j+1), i),100,0,2);
      }
      /*dedxHist[i] = new TH1F(TString::Format("dedx hist %d",i),
                            TString::Format("Truncation: %f - %f",truncCuts[i*2]
                            ,truncCuts[i*2+1]),100,.4,1.6);*/
   }

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   //The loop that just checks for bad entries
   int nBad[modeNum] = {};
   int nLooped = 0;
   for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      // Check if layer-level can be reproduced

      nLooped += 1;

      for (int i = 0; i < modeNum; ++i) {
         if(fabs( (MyHits(i,.05,.75) - dedxnosat) ) > 1.e-6){
           nBad[i] += 1;
         }
      }
   }
   for (int i = 0; i < modeNum; ++i) {
      cout << hitMode[i]<< ": "<<
            nBad[i] << " bad out of " << nLooped << endl;
   }

   for (Long64_t jentry=0; jentry<800000;jentry++) {    // 3500000 is the usual lim
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if( (jentry/100000)*100000 == jentry ) cout << jentry << endl;
      // if (Cut(ientry) < 0) continue;
      for (int i = 0; i < modeNum; ++i) {
         for ( int j = 0; j < nbins; ++j ){
            if (inCDC && fabs(dr)<1 && fabs(dz)<1) {
         	  if (pF>=(lowedge+j*step)&&pF<(lowedge+(j+1)*step) ) {
                     dedxPlot[i][j]->Fill(MyHits(i,.05,.75));
         	  }
         	}
         }
      }

   }


   TH1F * mean[modeNum];
   for ( int i = 0; i < modeNum; ++i ){
      mean[i] = new TH1F(TString::Format("mean %d", i),
               TString::Format("Mean of dedx"),nbins, lowedge, highedge);
   }
   TH1F * res[modeNum];
   for ( int i = 0; i < modeNum; ++i ){
      res[i] = new TH1F(TString::Format("resolution %d", i),
               TString::Format("Resolution of dedx"),nbins, lowedge, highedge);
   }
   TH1F * resmean[modeNum];
   for ( int i = 0; i < modeNum; ++i ){
      resmean[i] = new TH1F(TString::Format("res/mean %d", i),
               TString::Format("Resolution/Mean"),nbins, lowedge, highedge);
   }
   TH1F * ratio[modeNum];
   for ( int i = 0; i < modeNum; ++i ){
      ratio[i] = new TH1F(TString::Format("Ratio of dedx %d", i),
               TString::Format("Ratio"),nbins, lowedge, highedge);
   }

//Fitting:[i][j]
   double_t mu, bincent, muerr, binerr, reso, reserr;
   double_t resmu[nbins];

   TF1 * fit[modeNum][nbins];

   for(int j = 0; j < nbins;++j) {
     dedxPlot[0][j]->Fit("gaus");
     fit[0][j] = dedxPlot[0][j]->GetFunction("gaus");
     mu = fit[0][j]->GetParameter(1);
     reso = fit[0][j]->GetParameter(2);
     resmu[j] = reso/mu;
   }

   for( int i = 0; i < modeNum; ++i ){
      for(int j = 0; j < nbins;++j) {
        dedxPlot[i][j]->Fit("gaus");
        fit[i][j] = dedxPlot[i][j]->GetFunction("gaus");
        mu = fit[i][j]->GetParameter(1);
        muerr = fit[i][j]->GetParError(1);
        reso = fit[i][j]->GetParameter(2);
        reserr = fit[i][j]->GetParError(2);
        bincent = lowedge+0.5*step+j*step;
        mean[i] -> Fill(bincent,mu);
        mean[i] -> SetBinError(j+1,muerr);
        res[i] -> Fill(bincent,reso);
        res[i] -> SetBinError(j+1,reserr);
        resmean[i]->Fill(bincent, reso/mu);
        ratio[i] -> Fill(bincent, (reso/mu)/resmu[j]);
      }
      mean[i]->GetYaxis()->SetRangeUser(.7,1.2);
      res[i]->GetYaxis()->SetRangeUser(0.04,.15);
      resmean[i]->GetYaxis()->SetRangeUser(0.06,.12);
      ratio[i]->GetYaxis()->SetRangeUser(.9,1.3);
   }


   TCanvas* c1 = new TCanvas("Mean vs Momentum hits","", 1500,800);
   c1->Divide(1,4);
   c1->cd(1);
   mean[0]->SetMarkerColor(kRed);
   mean[0]->SetLineColor(kRed);
   mean[0]->Draw("same");
   mean[2]->SetMarkerColor(kBlack);
   mean[2]->SetLineColor(kBlack);
   mean[2]->Draw("same");
   mean[1]->SetMarkerColor(kBlue);
   mean[1]->SetLineColor(kBlue);
   mean[1]->Draw("same");
   mean[3]->SetMarkerColor(kGreen);
   mean[3]->SetLineColor(kGreen);
   mean[3]->Draw("same");

   c1->cd(2);
   res[0]->SetMarkerColor(kRed);
   res[0]->SetLineColor(kRed);
   res[0]->Draw("same");
   res[2]->SetMarkerColor(kBlack);
   res[2]->SetLineColor(kBlack);
   res[2]->Draw("same");
   res[1]->SetMarkerColor(kBlue);
   res[1]->SetLineColor(kBlue);
   res[1]->Draw("same");
   res[3]->SetMarkerColor(kGreen);
   res[3]->SetLineColor(kGreen);
   res[3]->Draw("same");

   c1->cd(3);
   resmean[0]->SetMarkerColor(kRed);
   resmean[0]->SetLineColor(kRed);
   resmean[0]->Draw("same");
   resmean[2]->SetMarkerColor(kBlack);
   resmean[2]->SetLineColor(kBlack);
   resmean[2]->Draw("same");
   resmean[1]->SetMarkerColor(kBlue);
   resmean[1]->SetLineColor(kBlue);
   resmean[1]->Draw("same");
   resmean[3]->SetMarkerColor(kGreen);
   resmean[3]->SetLineColor(kGreen);
   resmean[3]->Draw("same");

   c1->cd(4);
   ratio[0]->SetMarkerColor(kRed);
   ratio[0]->SetLineColor(kRed);
   ratio[0]->Draw("same");
   ratio[2]->SetMarkerColor(kBlack);
   ratio[2]->SetLineColor(kBlack);
   ratio[2]->Draw("same");
   ratio[1]->SetMarkerColor(kBlue);
   ratio[1]->SetLineColor(kBlue);
   ratio[1]->Draw("same");
   ratio[3]->SetMarkerColor(kGreen);
   ratio[3]->SetLineColor(kGreen);
   ratio[3]->Draw("same");

   c1->cd(1);
   TLegend* legend = new TLegend(.85,.6,1,1);
   for (int i =0;i< modeNum;++i) {
      legend->AddEntry(ratio[i], TString::Format("Mode: %d", hitMode[i]),"l");
   }
   legend->Draw();

   //c1 -> SaveAs("Cut-resmean.pdf");

   /*TCanvas* c2 = new TCanvas("Mean vs Momentum keep75","", 1500,800);

   c2->Divide(1,4);
   c2->cd(1);
   mean[4]->SetMarkerColor(kRed);
   mean[4]->SetLineColor(kRed);
   mean[4]->Draw("same");
   mean[1]->SetMarkerColor(kBlack);
   mean[1]->SetLineColor(kBlack);
   mean[1]->Draw("same");
   mean[5]->SetMarkerColor(kBlue);
   mean[5]->SetLineColor(kBlue);
   mean[5]->Draw("same");
   mean[6]->SetMarkerColor(kGreen);
   mean[6]->SetLineColor(kGreen);
   mean[6]->Draw("same");
   mean[8]->SetMarkerColor(kOrange);
   mean[8]->SetLineColor(kOrange);
   mean[8]->Draw("same");
   mean[9]->SetMarkerColor(kViolet);
   mean[9]->SetLineColor(kViolet);
   mean[9]->Draw("same");

   c2->cd(2);
   res[4]->SetMarkerColor(kRed);
   res[4]->SetLineColor(kRed);
   res[4]->Draw("same");
   res[1]->SetMarkerColor(kBlack);
   res[1]->SetLineColor(kBlack);
   res[1]->Draw("same");
   res[5]->SetMarkerColor(kBlue);
   res[5]->SetLineColor(kBlue);
   res[5]->Draw("same");
   res[6]->SetMarkerColor(kGreen);
   res[6]->SetLineColor(kGreen);
   res[6]->Draw("same");
   res[8]->SetMarkerColor(kOrange);
   res[8]->SetLineColor(kOrange);
   res[8]->Draw("same");
   res[9]->SetMarkerColor(kViolet);
   res[9]->SetLineColor(kViolet);
   res[9]->Draw("same");

   c2->cd(3);
   resmean[4]->SetMarkerColor(kRed);
   resmean[4]->SetLineColor(kRed);
   resmean[4]->Draw("same");
   resmean[1]->SetMarkerColor(kBlack);
   resmean[1]->SetLineColor(kBlack);
   resmean[1]->Draw("same");
   resmean[5]->SetMarkerColor(kBlue);
   resmean[5]->SetLineColor(kBlue);
   resmean[5]->Draw("same");
   resmean[6]->SetMarkerColor(kGreen);
   resmean[6]->SetLineColor(kGreen);
   resmean[6]->Draw("same");
   resmean[8]->SetMarkerColor(kOrange);
   resmean[8]->SetLineColor(kOrange);
   resmean[8]->Draw("same");
   resmean[9]->SetMarkerColor(kViolet);
   resmean[9]->SetLineColor(kViolet);
   resmean[9]->Draw("same");

   c2->cd(4);
   ratio[4]->SetMarkerColor(kRed);
   ratio[4]->SetLineColor(kRed);
   ratio[4]->Draw("same");
   ratio[1]->SetMarkerColor(kBlack);
   ratio[1]->SetLineColor(kBlack);
   ratio[1]->Draw("same");
   ratio[5]->SetMarkerColor(kBlue);
   ratio[5]->SetLineColor(kBlue);
   ratio[5]->Draw("same");
   ratio[6]->SetMarkerColor(kGreen);
   ratio[6]->SetLineColor(kGreen);
   ratio[6]->Draw("same");
   ratio[8]->SetMarkerColor(kOrange);
   ratio[8]->SetLineColor(kOrange);
   ratio[8]->Draw("same");
   ratio[9]->SetMarkerColor(kViolet);
   ratio[9]->SetLineColor(kViolet);
   ratio[9]->Draw("same");

   c2->cd(1);
   TLegend* legend1 = new TLegend(.85,.6,1,1);
   legend1->AddEntry(ratio[4], TString::Format("Truncation: %f - %f",truncCuts[4*2]
   ,truncCuts[4*2+1]),"l");
   legend1->AddEntry(ratio[5], TString::Format("Truncation: %f - %f",truncCuts[5*2]
   ,truncCuts[5*2+1]),"l");
   legend1->AddEntry(ratio[6], TString::Format("Truncation: %f - %f",truncCuts[6*2]
   ,truncCuts[6*2+1]),"l");
   legend1->AddEntry(ratio[1], TString::Format("Truncation: %f - %f",truncCuts[1*2]
   ,truncCuts[1*2+1]),"l");
   legend1->AddEntry(ratio[8], TString::Format("Truncation: %f - %f",truncCuts[8*2]
   ,truncCuts[8*2+1]),"l");
   legend1->AddEntry(ratio[9], TString::Format("Truncation: %f - %f",truncCuts[9*2]
   ,truncCuts[9*2+1]),"l");
   legend1->Draw();

   c2 -> SaveAs("Truncation_keep75.png");*/
   TLegend* legend3[modeNum][nbins-50];
   for (int i = 0;i < modeNum;++i) {
      for (int j = 25;j<nbins-25;++j) {
         legend3[i][j] = new TLegend(.85,.45,1,.55);
      }
   }

   TCanvas* c4[4] = {};

   for (int i =0;i<modeNum;++i) {
      c4[i] = new TCanvas(TString::Format("dedx %d",i),"", 1800,1000);
      c4[i] -> Divide(6,5);
      for (int j = 25;j<nbins-25;++j) {
         c4[i]->cd(j-24);
         gStyle->SetOptFit(0001);
         dedxPlot[i][j]->Draw();
         mu = fit[i][j]->GetParameter(1);
         reso = fit[i][j]->GetParameter(2);

         legend3[i][j]->AddEntry(dedxPlot[i][j], TString::Format("%f",reso/mu),"");
         legend3[i][j]->Draw();
      }
      c4[i]->SaveAs(TString::Format("Cut-Mode%d.pdf",i));
   }

}
