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
#include <iostream>
#include <cmath>

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
   int hitMode[] = {8,9};
   int modeNum = 2; 
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

   int nbins1 = 24;
   double lowedge1 = -3.;
   double highedge1 = 3.;
   double step1 = (highedge1 - lowedge1)/nbins1;
   TH1F* hitsPerMomBin[modeNum][nbins1];
   for (int i = 0; i < modeNum; ++i) {
      for (int j = 0; j < nbins1; ++j) {
         hitsPerMomBin[i][j] = new TH1F(TString::Format("hits %d %d",i, j),TString::Format("momentum bin %f-%f"
                                 ,lowedge1+step1*j,lowedge1+step1*(j+1)),50,-.5,49.5);
      }
   }

   TH1F * Axial = new TH1F("plot 1", "Hits per track for Axial Layers excluding superlayer 1",50,-.5,49.5);
   TH1F * Stereo = new TH1F("plot 2", "Hits per track for Stereo Layers excluding superlayer 1",50,-.5,49.5);

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   for (Long64_t jentry=0; jentry<2500000;jentry++) {    // 3500000 is the usual lim
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if( (jentry/100000)*100000 == jentry ) std::cout << jentry << std::endl;
      // if (Cut(ientry) < 0) continue;
      
      for (int i = 0; i < modeNum ; ++i) {
         /*for (int j = 0; j < nbins; ++j) {
            if (inCDC && fabs(dr)<1 && fabs(dz)<1 && fabs(pF*sqrt(1 - costh*costh)) > .3 && (costh > -.6 && costh < .8) ) {
               if (pF>=(lowedge+j*step)&&pF<(lowedge+(j+1)*step) ) {
                  dedxPlot[i][j]->Fill(MyHits(hitMode[i],.05,.75));
               }
            }
         }*/
         for (int j = 0; j < nbins1; ++j) {
            if (inCDC && fabs(dr)<1 && fabs(dz)<1 && fabs(pF*sqrt(1 - costh*costh)) > .3 && (costh > -.6 && costh < .8) ) {
               if (pF>=(lowedge1+j*step1)&&pF<(lowedge1+(j+1)*step1) ) {
                  hitsPerMomBin[i][j]->Fill(MyHits(hitMode[i],.05,.75));
               }
            }
         }
      }
      if (inCDC && fabs(dr)<1 && fabs(dz)<1 && fabs(pF*sqrt(1 - costh*costh)) > .3 && (costh > -.6 && costh < .8) ) {
         Axial->Fill(MyHits(8,.05,.75));
         Stereo->Fill(MyHits(9, .05,.75));
      
      }
   }
   TH1F * mean1[modeNum];
   for ( int i = 0; i < modeNum; ++i ){
      mean1[i] = new TH1F(TString::Format("mean %d", i),
               TString::Format("Mean of Hits per Track"),nbins1, lowedge1, highedge1);
   }
   for(int i = 0; i < modeNum; ++i){
      for(int j = 0; j < nbins1; ++j) {
         double bincent = lowedge1+0.5*step1+j*step1;
         /*if (hitsPerMomBin[i][j]->GetEntries() > 1) { 
            hitsPerMomBin[i][j]->Fit("gaus");
            mean1[i] -> Fill(bincent,hitsPerMomBin[i][j]->GetFunction("gaus")->GetParameter(1));
         }
         else {*/
            mean1[i] -> Fill(bincent,hitsPerMomBin[i][j]->GetMean());
         //}
      }
   }
   TCanvas* c2 = new TCanvas("c2","c2", 1800,900);
   mean1[0]->SetMarkerColor(kRed);
   mean1[0]->SetLineColor(kRed);
   mean1[0]->Draw("same");
   mean1[1]->SetMarkerColor(kBlack);
   mean1[1]->SetLineColor(kBlack);
   mean1[1]->Draw("same");
   gStyle->SetOptStat(0);

   TLegend* legend = new TLegend(.89,.8,1,.95);
   for (int i =0;i< modeNum;++i) {
      legend->AddEntry(mean1[i], TString::Format("Mode: %d", hitMode[i]),"l");
   }
   legend->Draw();

   c2->SaveAs("NoGaussZoom1-HitsvsMom.pdf");

   /*TH1F * mean[modeNum];
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
      if (dedxPlot[0][j]->GetEntries() > 1) {
         dedxPlot[0][j]->Fit("gaus");
         fit[0][j] = dedxPlot[0][j]->GetFunction("gaus");
         mu = fit[0][j]->GetParameter(1);
         reso = fit[0][j]->GetParameter(2);
         resmu[j] = reso/mu;
      }
   }

   for( int i = 0; i < modeNum; ++i ){
      for(int j = 0; j < nbins;++j) {
         if (dedxPlot[i][j]->GetEntries() > 1) {
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
         mean[i]->GetYaxis()->SetRangeUser(.95,1.05);
         res[i]->GetYaxis()->SetRangeUser(0.07,.13);
         resmean[i]->GetYaxis()->SetRangeUser(0.07,.12);
         ratio[i]->GetYaxis()->SetRangeUser(.95,1.1);
      }
   }


   TCanvas* c1 = new TCanvas("Mean vs Momentum hits","", 1500,800);
   c1->Divide(1,4);
   c1->cd(1);
   mean[0]->SetMarkerColor(kRed);
   mean[0]->SetLineColor(kRed);
   mean[0]->Draw("same");
   mean[1]->SetMarkerColor(kBlack);
   mean[1]->SetLineColor(kBlack);
   mean[1]->Draw("same");

   c1->cd(2);
   res[0]->SetMarkerColor(kRed);
   res[0]->SetLineColor(kRed);
   res[0]->Draw("same");
   res[1]->SetMarkerColor(kBlack);
   res[1]->SetLineColor(kBlack);
   res[1]->Draw("same");

   c1->cd(3);
   resmean[0]->SetMarkerColor(kRed);
   resmean[0]->SetLineColor(kRed);
   resmean[0]->Draw("same");
   resmean[1]->SetMarkerColor(kBlack);
   resmean[1]->SetLineColor(kBlack);
   resmean[1]->Draw("same");

   c1->cd(4);
   ratio[0]->SetMarkerColor(kRed);
   ratio[0]->SetLineColor(kRed);
   ratio[0]->Draw("same");
   ratio[1]->SetMarkerColor(kBlack);
   ratio[1]->SetLineColor(kBlack);
   ratio[1]->Draw("same");

   c1->cd(1);
   TLegend* legend = new TLegend(.85,.6,1,1);
   for (int i =0;i< modeNum;++i) {
      legend->AddEntry(ratio[i], TString::Format("Mode: %d", hitMode[i]),"l");
   }
   legend->Draw();

   c1 -> SaveAs("MyLayersFullAxial-resmean.pdf");*/

   
   
   /*TLegend* legend3[modeNum][nbins-50];
   for (int i = 0;i < modeNum;++i) {
      for (int j = 25;j<nbins-25;++j) {
         legend3[i][j] = new TLegend(.85,.45,1,.55);
      }
   }

   TCanvas* c4[modeNum] = {};

   for (int i =0;i<modeNum;++i) {
      c4[i] = new TCanvas(TString::Format("dedx %d",i),"", 1800,1000);
      c4[i] -> Divide(6,5);
      for (int j = 25;j<nbins-25;++j) {
         c4[i]->cd(j-24);
         gStyle->SetOptFit(0001);
         if (dedxPlot[i][j]->GetEntries() > 1) {
            dedxPlot[i][j]->Draw();
            mu = fit[i][j]->GetParameter(1);
            reso = fit[i][j]->GetParameter(2);

            legend3[i][j]->AddEntry(dedxPlot[i][j], TString::Format("%f",reso/mu),"");
            legend3[i][j]->Draw();
         }
      }
      c4[i]->SaveAs(TString::Format("MyLayersFullAxial-Mode%d.pdf",hitMode[i]));
   }*/


   TCanvas* c4[modeNum] = {};

   for (int i =0;i<modeNum;++i) {
      c4[i] = new TCanvas(TString::Format("dedx %d",i),"", 1000,1000);
      c4[i] -> Divide(6,4);
      for (int j = 0;j<nbins1;++j) {
         c4[i]->cd(j+1);
         gStyle->SetOptFit(0001);
         hitsPerMomBin[i][j]->Draw();
      }
      c4[i]->SaveAs(TString::Format("NoGaussZoom1-HitsperMom-Mode%d.pdf",hitMode[i]));
   }

   /*TCanvas *c3 = new TCanvas("c3", "c3", 1800,1000);
   c3->Divide(3,1);
   c3->cd(1);
   Axial->SetMarkerColor(kRed);
   Axial->SetLineColor(kRed);
   Axial->Draw("same");
   Stereo->SetMarkerColor(kBlack);
   Stereo->SetLineColor(kBlack);
   Stereo->Draw("same");
   c3->cd(2);
   Axial->Draw();
   c3->cd(3);
   Stereo->Draw();

   c3->SaveAs("AxialStereo-histogram.pdf"); */
}
