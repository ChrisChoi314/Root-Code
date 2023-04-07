#define PathLength_cxx
#include "PathLength.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void PathLength::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L PathLength.C
//      Root > PathLength t
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

   double mom = .3;
   double coscut1 = -.5;
   double coscut2 = .7;

   int layer = 13;

   TH1F * lastLayer = new TH1F("data1", TString::Format("Last Layer a track went through, -.5 < costh < .7, pF*sinth > %f", mom ), 56, -.5,55.5);

   TH2F * pTvLL = new TH2F("data2", "pT vs Last Layer a track went through, -.5 < costh < .7", 56, -.5,55.5,200, -5.5,5.5);

   TH2F * pTvcos = new TH2F("data3", TString::Format("pT vs costh,-.5 < costh < .7, layer %d", layer), 200, -.5,.7, 200, -5.5,5.5);

   TH2F * entvdoc = new TH2F("data4", TString::Format("hEnta vs hDoca for last hit of track, abs(pT) > .3, layer %d ",layer), 200,-1.6,1.6,200, -2,2);

   for (Long64_t jentry=0; jentry<500000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      int maxLayer = 0;
      int maxLayerIdx = 0;
      for (int i = 0; i < hNHits; ++i) {
         if( hLayer[i] >= maxLayer ){
            maxLayer = hLayer[i];
            maxLayerIdx = i;
         }
      }
      if (fabs(pF*sqrt(1 - costh*costh)) > mom && (costh > coscut1 && costh < coscut2) ) lastLayer->Fill(maxLayer);
      if (costh > -.5 && costh < .7 && maxLayer == layer) {
         pTvLL->Fill(maxLayer, pF*sqrt(1 - costh*costh));
         pTvcos->Fill(costh, pF*sqrt(1 - costh*costh));
         if (fabs(pF*sqrt(1- costh*costh)) > .3) entvdoc -> Fill(hDoca[maxLayerIdx], hEnta[maxLayerIdx]);
      }
   }
/*
   TCanvas * c2 = new TCanvas("c2", "c2",1000,1000); //1900,950); 
   lastLayer->Draw();
   gPad->SetLogy();
   c2->SaveAs("LastLayer-tight.pdf");*/

   TCanvas * c1 = new TCanvas("c1", "c1",1000,1000); //1900,950); 
   c1->Divide(2,2);
   c1->cd(1);
   pTvLL->Draw();
   c1->cd(2);
   pTvcos->Draw();
   c1->cd(3);
   entvdoc->Draw();
   //c1->SaveAs(TString::Format("Layer%d.pdf",layer ) );
}
