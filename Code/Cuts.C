#define Cuts_cxx
#include "Cuts.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <TProfile.h>
#include <TRandom.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "TVector3.h"
#include "TMath.h"

void Cuts::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Cuts.C
//      Root > Cuts t
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

   TH1F * cosOn = new TH1F("stats0" , "Cos with inCDC true",100,-.9,1.);
   TH1F * cosOff = new TH1F("stats1" , "Cos with inCDC false",100,-.9,1.);
   TH1F * histDr = new TH1F("stats2" , "dr",100,0,.03);
   TH1F * histDz = new TH1F("stats3" , "dz",100,-.3,.3);
   TH2F* drvsdz = new TH2F("stats4","dr vs dz", 100, -.3, .3, 100, 0.,.03);


   TH1F * cosPos = new TH1F("stats5" , "Cos for positive tracks only",400,-.9,1.);
   TH1F * cosNeg = new TH1F("stats6" , "Cos for negative tracks only",400,-.9,1.);
   TH1F * hNCoscent = new TH1F("stats7" , "hNHits for costh in the center",80,-.5,79.5);
   TH1F * hNpTcut = new TH1F("stats8" , "hNHits for costh in the center with pT > .25",80,-.5,79.5);
   TH1F * lNCoscent = new TH1F("stats9" , "lNHits for costh in the center",60,-.5,59.5);
   TH1F * lNpTcut = new TH1F("stats10" , "lNHits for costh in the center with pT > .25",60,-.5,59.5);

   TH2F * hNcos = new TH2F("stats11" , "hNHits vs costh in the center",100,-.6,.8, 80,-.5,79.5);
   TH2F * lNcos = new TH2F("stats12" , "lNHits vs costh in the center",100,-.6,.8,60, -.5,59.5);

   TH1F * inTrueL = new TH1F("stats13" , "Cos with inCDC, left portion",100,-.88,-.86);
   TH1F * inTrueR = new TH1F("stats14" , "Cos with inCDC, right portion",100,.95,.97);
   TH1F * inFalL = new TH1F("stats15" , "Cos with inCDC false, left portion",100,-.87,-.86);
   TH1F * inFalR = new TH1F("stats16" , "Cos with inCDC false, right portion",100,.95,.96);

   //the monitoring plots
   /*TH1F * cosPos = new TH1F("stats5" , "Cos for positive tracks only",100,-.9,1.);
   TH1F * cosNeg = new TH1F("stats6" , "Cos for negative tracks only",100,-.9,1.);
   TH1F * hNCoscent = new TH1F("stats7" , "hNHits for costh in the center",100,0,100);
   TH1F * hNpTcut = new TH1F("stats8" , "hNHits for costh in the center with pT > .25",100,0,100);
   TH1F * lNCoscent = new TH1F("stats9" , "lNHits for costh in the center",100,0,60);
   TH1F * lNpTcut = new TH1F("stats10" , "lNHits for costh in the center with pT > .25",100,0,60);*/

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if (inCDC) {
         cosOn-> Fill(costh);
         inTrueL->Fill(costh);
         inTrueR->Fill(costh);

      }
      else {
         cosOff -> Fill(costh);
         inFalL->Fill(costh);
         inFalR->Fill(costh);
      }

      histDr->Fill(dr);
      histDz->Fill(dz);
      drvsdz->Fill(dz,dr);
      // if (Cut(ientry) < 0) continue;
      if (inCDC && fabs(dr)<1 && fabs(dz)<1) {
         if (pF > 0) {
            cosPos->Fill(costh);
         }
         else {
            cosNeg->Fill(costh);
         }
         if (costh >= -.6 && costh < .8) {
            hNCoscent->Fill(hNHits);
            lNCoscent->Fill(lNHits);
            if (pF * sqrt(1- costh*costh) ) {
               hNpTcut->Fill(hNHits);
               lNpTcut->Fill(lNHits);
            }
         }
         hNcos->Fill(costh, hNHits);
         lNcos->Fill(costh,lNHits);
      }
   }

   TCanvas *c = new TCanvas("c", "c", 800,800);
   c->Draw();
   TPad *p1 = new TPad("p1","p1",0.05,0.55,0.95,0.95);
   p1->Draw();
   p1->Divide(2,1);
   TPad *p11 = (TPad*)p1->cd(1);
   cosOn->Draw();
   TPad *p12 = (TPad*)p1->cd(2);
   cosOff->Draw();

   c->cd(0);
   TPad *p2 = new TPad("p1","p1",0.1,0.05,0.9,0.45);
   p2->Draw();
   p2->Divide(3,1);
   TPad *p21 = (TPad*)p2->cd(1);
   histDr->Draw();

   TPad *p22 = (TPad*)p2->cd(2);
   histDz->Draw();

   TPad *p23 = (TPad*)p2->cd(3);
   drvsdz->Draw();



   c->SaveAs("Cuts-inCDC-drdz.pdf");

   TCanvas *c2 = new TCanvas("c2","",1000,650);
   c2->Divide(4,2);

   c2->cd(1);
   cosPos->Draw();


   c2->cd(2);
   hNCoscent->Draw();

   c2->cd(3);
   lNCoscent->Draw();

   c2->cd(4);
   hNcos->Draw();

   c2->cd(5);
   cosNeg->Draw();

   c2->cd(6);
   hNpTcut->Draw();

   c2->cd(7);
   lNpTcut->Draw();

   c2->cd(8);
   lNcos->Draw();

   c2->SaveAs("Cuts-costh-hlNHits.pdf");

   TCanvas *c3 = new TCanvas("c3", "c3", 1000,800);
   c3->Draw();
   TPad *b1 = new TPad("p1","p1",0.05,0.55,0.95,0.95);
   b1->Draw();
   b1->Divide(2,1);
   TPad *b11 = (TPad*)b1->cd(1);
   cosOn->Draw();
   TPad *b12 = (TPad*)b1->cd(2);
   cosOff->Draw();
   b12->SetLogy();

   c3->cd(0);
   TPad *b2 = new TPad("b2","b2",0.05,0.05,0.95,0.45);
   b2->Draw();
   b2->Divide(4,1);
   TPad *b21 = (TPad*)b2->cd(1);
   inTrueL->Draw();
   TPad *b22 = (TPad*)b2->cd(2);
   inTrueR->Draw();
   TPad *b23 = (TPad*)b2->cd(3);
   inFalL->Draw();
   TPad *b24 = (TPad*)b2->cd(4);
   inFalR->Draw();

   c3->SaveAs("Cuts-closeup-CDC-extra.pdf");

}
