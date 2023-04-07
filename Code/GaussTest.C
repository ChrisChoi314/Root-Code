#define GaussTest_cxx
#include "GaussTest.h"
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
#include <cmath>

void GaussTest::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L GaussTest.C
//      Root > GaussTest t
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
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   TH1F * HStatHBin = new TH1F("stats0" , "dedx plot high stat, high bin",150,0,2);
   TH1F * HStatLBin = new TH1F("stats1" , "dedx plot high stat, low bin",15,0,2);
   TH1F * LStatHBin = new TH1F("stats2" , "dedx plot low stat, high bin",150,0,2);
   TH1F * LStatLBin = new TH1F("stats3" , "dedx plot low stat, low bin",15,0,2);

   double lowedge = HStatHBin-> GetXaxis()->GetXmin();
   double highedge = HStatHBin-> GetXaxis()->GetXmax();
   int Hbins = HStatHBin->GetSize() - 2;
   int Lbins = HStatLBin->GetSize() - 2;
   double Hstep = (highedge -lowedge)/Hbins;
   double Lstep = (highedge -lowedge)/Lbins;

   for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if (pF>=7&&pF<8){
         LStatHBin->Fill(dedx);
         LStatLBin->Fill(dedx);
      }
      HStatHBin->Fill(dedx);
      HStatLBin->Fill(dedx);
   }
   int entryNum = HStatHBin->GetEntries();
   double p2 = HStatHBin->GetRMS();
   double p0 = Hstep*entryNum/ (sqrt(2*3.14159265)* p2);
   double p1 = HStatHBin->GetMean();
   cout<<"High Stat, high bins initial params: p0: "<<p0<<"p1: "<<p1<<"p2: "<<p2<<endl;
   TF1 * gausFit0 = new TF1("gausFit0", "gaus");
   gausFit0 -> SetParameters(p0,p1,p2);
   HStatHBin->Fit("gausFit0");

   entryNum = HStatLBin->GetEntries();
   p2 = HStatLBin->GetRMS();
   p0 = Lstep*entryNum/ (sqrt(2*3.14159265)* p2);
   p1 = HStatLBin->GetMean();
   cout<<"High Stat, low bins initial params: p0: "<<p0<<"p1: "<<p1<<"p2: "<<p2<<endl;
   TF1 * gausFit1 = new TF1("gausFit1", "gaus");
   gausFit1 -> SetParameters(p0,p1,p2);
   HStatLBin->Fit("gausFit1");

   entryNum = LStatHBin->GetEntries();
   p2 = LStatHBin->GetRMS();
   p0 = Hstep*entryNum/ (sqrt(2*3.14159265)* p2);
   p1 = LStatHBin->GetMean();
   cout<<"low Stat, high bins initial params: p0: "<<p0<<"p1: "<<p1<<"p2: "<<p2<<endl;
   TF1 * gausFit2 = new TF1("gausFit2", "gaus");
   gausFit2 -> SetParameters(p0,p1,p2);
   LStatHBin->Fit("gausFit2");

   entryNum = LStatLBin->GetEntries();
   p2 = LStatLBin->GetRMS();
   p0 = Lstep*entryNum/ (sqrt(2*3.14159265)* p2);
   p1 = LStatLBin->GetMean();
   cout<<"low Stat, low bins initial params: p0: "<<p0<<"p1: "<<p1<<"p2: "<<p2<<endl;
   TF1 * gausFit3 = new TF1("gausFit3", "gaus");
   gausFit3 -> SetParameters(p0,p1,p2);
   LStatLBin->Fit("gausFit3");
   //histo->Fit("gaus");
   //TF1 * fit = histo->GetFunction("gaus");
   TCanvas* c1 = new TCanvas("Dedx diff stats and bins","", 650,600);
   c1->Divide(2,2);
   c1->cd(1);
   gStyle->SetOptFit(0001);
   HStatHBin->Draw();
   c1->cd(2);
   HStatLBin->Draw();
   c1->cd(3);
   LStatHBin->Draw();
   c1->cd(4);
   LStatLBin->Draw();
   c1 -> SaveAs("MixedStatsBins-InitParam.pdf");

}
