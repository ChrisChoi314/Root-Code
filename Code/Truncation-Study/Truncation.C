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
#include <fstream>
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
   double truncCuts[] = {0,.75, .05,.75, .1,.75, .15,.75, .05,.55,.05,.65,.05,
                         .7,.05,.75,.05,.8,.05,.85};
   int numCuts = 10;
   double step = (highedge - lowedge)/nbins;
   TH1F* dedxPlot[numCuts][nbins];
   TH1F* dedxHist[numCuts];

   double LowerL = 0;
   double LowerU = 1;
   double UpperL = 0;
   double UpperU = 1; 
   int LowerNum = (LowerU - LowerL)/.02;
   int UpperNum = (UpperU - UpperL)/.02; 

   TH1F* LowerTrunc[LowerNum];
   TH1F* UpperTrunc[UpperNum];

   for (int i = 0; i < numCuts; ++i) {
      for ( int j = 0; j < nbins; ++j ){
        dedxPlot[i][j] = new TH1F(TString::Format("dedx %d %d",i, j),
                              TString::Format("momentum bin %d; truncation %d;",j, i),100,0,2);
      }
      dedxHist[i] = new TH1F(TString::Format("dedx hist %d",i),
                            TString::Format("Truncation: %f - %f",truncCuts[i*2]
                            ,truncCuts[i*2+1]),100,.4,1.6);
   }

   for (int i = 0; i < LowerNum;++i) {
      LowerTrunc[i] = new TH1F(TString::Format("dedx %d",i),TString::Format("Truncation: %f - 1",LowerL+.02*i),100, 0,6);
      //std::cout << LowerL+.02*i << std::endl;
   }
   for (int i = 0; i < UpperNum;++i) {
      UpperTrunc[i] = new TH1F(TString::Format("dedx  %d",i),TString::Format("Truncation: 0 - %f",UpperU-.02*i),100,0,2);
      //std::cout << UpperU-.02*i << std::endl;
   }

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

/*
   //The loop that just checks for bad entries
   int nBad[numCuts] = {};
   int nLooped = 0;
   for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      // Check if layer-level can be reproduced

      nLooped += 1;

      for (int i = 0; i < numCuts; ++i) {
         if(fabs( (MyLayersFull(0,truncCuts[i*2],truncCuts[i*2+1]) - dedxnosat) ) > 1.e-6){
           nBad[i] += 1;
         }
      }
   }
   for (int i = 0; i < numCuts; ++i) {
      cout << truncCuts[i*2] << "-" << truncCuts[i*2+1] << ": "<<
            nBad[i] << " bad out of " << nLooped << endl;
   }*/

   for (Long64_t jentry=0; jentry< 1500000;jentry++) {    // 3500000 is the usual lim
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if( (jentry/100000)*100000 == jentry ) cout << jentry << endl;
      // if (Cut(ientry) < 0) continue;
      /*for (int i = 0; i < numCuts; ++i) {
         for ( int j = 0; j < nbins; ++j ){
            if (inCDC && fabs(dr)<1 && fabs(dz)<1) {
         	  if (pF>=(lowedge+j*step)&&pF<(lowedge+(j+1)*step) ) {
                 dedxPlot[i][j]->Fill(MyLayersFull(0,truncCuts[i*2],truncCuts[i*2+1]));
         	  }
         	}
         }
         if (inCDC && fabs(dr)<1 && fabs(dz)<1 && fabs(pF)<2.5 && fabs(pF)>.3){
            dedxHist[i]->Fill(MyLayersFull(0,truncCuts[i*2],truncCuts[i*2+1]));
         }
      }*/
      if (inCDC && fabs(dr)<1 && fabs(dz)<1) {
         for (int i = 0; i < LowerNum;++i) {
            LowerTrunc[i]->Fill(MyLayersFull(0,LowerL+.02*i,LowerU ));
         }
         for (int i = 0; i < UpperNum;++i) {
            UpperTrunc[i]->Fill(MyLayersFull(0,UpperL, UpperU-.02*i));
         }
      }
   }

   /*TH1F * mean[numCuts];
   for ( int i = 0; i < numCuts; ++i ){
      mean[i] = new TH1F(TString::Format("mean %d", i),
               TString::Format("Mean of dedx"),nbins, lowedge, highedge);
   }
   TH1F * res[numCuts];
   for ( int i = 0; i < numCuts; ++i ){
      res[i] = new TH1F(TString::Format("resolution %d", i),
               TString::Format("Resolution of dedx"),nbins, lowedge, highedge);
   }
   TH1F * resmean[numCuts];
   for ( int i = 0; i < numCuts; ++i ){
      resmean[i] = new TH1F(TString::Format("res/mean %d", i),
               TString::Format("Resolution/Mean"),nbins, lowedge, highedge);
   }
   TH1F * ratio[numCuts];
   for ( int i = 0; i < numCuts; ++i ){
      ratio[i] = new TH1F(TString::Format("Ratio of dedx %d", i),
               TString::Format("Ratio"),nbins, lowedge, highedge);
   }

//Fitting:[i][j]
   double_t mu, bincent, muerr, binerr, reso, reserr;
   double_t resmu[nbins];

   TF1 * fit[numCuts][nbins];

   for(int j = 0; j < nbins;++j) {
     dedxPlot[7][j]->Fit("gaus");
     fit[7][j] = dedxPlot[7][j]->GetFunction("gaus");
     mu = fit[7][j]->GetParameter(1);
     reso = fit[7][j]->GetParameter(2);
     resmu[j] = reso/mu;
   }

   TH1F * mean1[modeNum];
   for ( int i = 0; i < modeNum; ++i ){
      mean1[i] = new TH1F(TString::Format("mean %d", i),
               TString::Format("Mean of Hits per Track"),nbins1, lowedge1, highedge1);
   }
   for(int i = 0; i < modeNum; ++i){
      for(int j = 0; j < nbins1; ++j) {
         double bincent = lowedge1+0.5*step1+j*step1;
         if (hitsPerMomBin[i][j]->GetEntries() > 1) { 
            hitsPerMomBin[i][j]->Fit("gaus");
            mean1[i] -> Fill(bincent,hitsPerMomBin[i][j]->GetFunction("gaus")->GetParameter(1));
         }
         else {
            mean1[i] -> Fill(bincent,hitsPerMomBin[i][j]->GetMean());
         //}
      }
   }
   */
   TH1F* Lower = new TH1F("Lower Trunc", "Resolution/mean vs Lower Truncation Percentage, with Upper trunc = 1",LowerNum,LowerL-.01,LowerU-.01);
   TH1F* Upper = new TH1F("Upper Trunc", "Resolution/mean vs Upper Truncation Percentage, with Lower trunc = 0",UpperNum,UpperL-.01,UpperU-.01);
   for (int i = 0; i < LowerNum;++i) {
      if (LowerTrunc[i]->GetEntries() > 1) {
      LowerTrunc[i]->Fit("gaus");
      double mean = LowerTrunc[i]->GetFunction("gaus")->GetParameter(1);
      double resolution = LowerTrunc[i]->GetFunction("gaus")->GetParameter(2);
      Lower->Fill(LowerL+.02*i , resolution/mean);
      }
   }
   for (int i = 0; i < UpperNum;++i) {
      if (UpperTrunc[i]->GetEntries() > 1) {
         UpperTrunc[i]->Fit("gaus");
      double mean = UpperTrunc[i]->GetFunction("gaus")->GetParameter(1);
      double resolution = UpperTrunc[i]->GetFunction("gaus")->GetParameter(2);
      Upper->Fill(UpperU-.02*i ,resolution/mean);
      }
   }

   TCanvas* c2 = new TCanvas("c2","c2", 1800,900);
   c2->Divide(1,2);
   c2->cd(1);
   Lower->Draw();
   gStyle->SetOptStat(0);
   c2->cd(2);
   Upper->Draw();
   gStyle->SetOptStat(0);

   /*TCanvas* c5 = new TCanvas("c5","c5", 1800, 900);
   c5->Divide(10,5);
   for (int i = 0; i < 50;++i) {
      c5->cd(i+1);
      LowerTrunc[i]->Draw();
   }*/


   c2->SaveAs("UpperLowerFull.pdf");


   for( int i = 0; i < numCuts; ++i ){
      /*for(int j = 0; j < nbins;++j) {
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
      ratio[i]->GetYaxis()->SetRangeUser(.9,1.3);*/

      //dedxHist[i]->Fit("gaus");

      
   }



   /*TCanvas* c1 = new TCanvas("Mean vs Momentum keep 05","", 1500,800);
   c1->Divide(1,4);
   c1->cd(1);
   mean[0]->SetMarkerColor(kRed);
   mean[0]->SetLineColor(kRed);
   mean[0]->Draw("same");
   mean[1]->SetMarkerColor(kBlack);
   mean[1]->SetLineColor(kBlack);
   mean[1]->Draw("same");
   mean[2]->SetMarkerColor(kBlue);
   mean[2]->SetLineColor(kBlue);
   mean[2]->Draw("same");
   mean[3]->SetMarkerColor(kGreen);
   mean[3]->SetLineColor(kGreen);
   mean[3]->Draw("same");

   c1->cd(2);
   res[0]->SetMarkerColor(kRed);
   res[0]->SetLineColor(kRed);
   res[0]->Draw("same");
   res[1]->SetMarkerColor(kBlack);
   res[1]->SetLineColor(kBlack);
   res[1]->Draw("same");
   res[2]->SetMarkerColor(kBlue);
   res[2]->SetLineColor(kBlue);
   res[2]->Draw("same");
   res[3]->SetMarkerColor(kGreen);
   res[3]->SetLineColor(kGreen);
   res[3]->Draw("same");

   c1->cd(3);
   resmean[0]->SetMarkerColor(kRed);
   resmean[0]->SetLineColor(kRed);
   resmean[0]->Draw("same");
   resmean[1]->SetMarkerColor(kBlack);
   resmean[1]->SetLineColor(kBlack);
   resmean[1]->Draw("same");
   resmean[2]->SetMarkerColor(kBlue);
   resmean[2]->SetLineColor(kBlue);
   resmean[2]->Draw("same");
   resmean[3]->SetMarkerColor(kGreen);
   resmean[3]->SetLineColor(kGreen);
   resmean[3]->Draw("same");

   c1->cd(4);
   ratio[0]->SetMarkerColor(kRed);
   ratio[0]->SetLineColor(kRed);
   ratio[0]->Draw("same");
   ratio[1]->SetMarkerColor(kBlack);
   ratio[1]->SetLineColor(kBlack);
   ratio[1]->Draw("same");
   ratio[2]->SetMarkerColor(kBlue);
   ratio[2]->SetLineColor(kBlue);
   ratio[2]->Draw("same");
   ratio[3]->SetMarkerColor(kGreen);
   ratio[3]->SetLineColor(kGreen);
   ratio[3]->Draw("same");

   c1->cd(1);
   TLegend* legend = new TLegend(.85,.65,1,1);
   legend->AddEntry(ratio[0], TString::Format("Truncation: %f - %f",truncCuts[0*2]
   ,truncCuts[0*2+1]),"l");
   legend->AddEntry(ratio[1], TString::Format("Truncation: %f - %f",truncCuts[1*2]
   ,truncCuts[1*2+1]),"l");
   legend->AddEntry(ratio[2], TString::Format("Truncation: %f - %f",truncCuts[2*2]
   ,truncCuts[2*2+1]),"l");
   legend->AddEntry(ratio[3], TString::Format("Truncation: %f - %f",truncCuts[3*2]
   ,truncCuts[3*2+1]),"l");
   legend->Draw();

   c1 -> SaveAs("Truncation_keep05.png");

   TCanvas* c2 = new TCanvas("Mean vs Momentum keep75","", 1500,800);

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

   /*TF1 * fitHist[numCuts];

   TCanvas* c3 = new TCanvas("dedx","", 1500,800);
   c3->Divide(5,2);
   TLegend* legend3[numCuts];
   for (int i = 0;i < numCuts;++i) {
      legend3[i] = new TLegend(.85,.9,1,1);
   }

   for (int i =0;i<numCuts;++i) {
      c3->cd(i+1);
      gStyle->SetOptFit(0001);
      dedxHist[i]->Draw();

      dedxHist[i]->Fit("gaus");
      fitHist[i] = dedxHist[i]->GetFunction("gaus");
      mu = fitHist[i]->GetParameter(1);
      reso = fitHist[i]->GetParameter(2);

      legend3[i]->AddEntry(dedxHist[i], TString::Format("res/mean: %f",reso/mu),"l");
      legend3[i]->Draw();
   }
   c3->SaveAs("Truncation_dedxFit.png");*/

}
