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
   const int numLayers = 56;

   TH2F* hPathvMyPath[numLayers] = {};
   TH1F* hPathvMyPathDiff[numLayers] = {};
   DedxDriftCell * cells[numLayers] = {} ;
   for (int i = 0; i < numLayers; ++i) {
      cells[i] = MakeCell(i);

      hPathvMyPath[i] = new TH2F(TString::Format("Layer: %d",i),TString::Format("hPath vs MyPath,Layer: %d",i)
      ,800,0,2.7,800, 0, 2.7);

      hPathvMyPathDiff[i] = new TH1F(TString::Format("Layer: %d",i),TString::Format("MyPath - hPath,Layer: %d",i)
      ,200,-.15,.15);
   }

   TH2F* PathPlot = new TH2F("pathplot","hPath vs MyPath, Layer 0, r_down = .500",800,0,3, 800, 0,3);

   TH1F* hPaths = new TH1F("hpaths", "MyPath - hPath, Layer 0, r_down = .500", 200, -.35, .35);
   TH1F* myPaths = new TH1F("mypaths", "My Path Calculation", 200, 0, 4);

   TH1F* diffperTrack = new TH1F("diff", "Amount of MyPath - hPath that are > 0 per track", 55, -.5, 54.5);

   for (Long64_t jentry=0; jentry<500000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      int differences = 0;
      for (int j = 0;j < hNHits;++j) {
         //std::cout << "mypath: " << cells[hLayer[j]]->dx(hDoca[j],hEnta[j]) << " hPath: " << hPath[j] << std::endl;
         //if (hLayer[i] == 0) {// && fabs(hEnta[i] - M_PI/2) < .02 && fabs(hDoca[i]) < .6  ) {
            double mypath = cells[hLayer[j]]->dx(hDoca[j],hEnta[j]);
            hPathvMyPath[hLayer[j]]->Fill(mypath, hPath[j]);

            hPathvMyPathDiff[hLayer[j]]->Fill(mypath - hPath[j]);

            if (fabs(mypath - hPath[j]) > .00001 ) {
               differences += 1;
            } 
            /*PathPlot->Fill(mypath, hPath[i]);
            hPaths->Fill(mypath - hPath[i]);*/
         //}
         /*double mypath = cells[hLayer[i]]->dx(hDoca[i],hEnta[i]);
         PathPlot->Fill(mypath, hPath[i]);
         hPaths->Fill(mypath - hPath[i]);
         myPaths->Fill(mypath);*/
      }
      if (differences != 0)  diffperTrack->Fill(differences);
   }

  
   /*TCanvas* c4[9] = {};

   for (int i =0;i<7;++i) {
      c4[i] = new TCanvas(TString::Format("path lenghs %d",i),"", 1900,1400);
      c4[i] -> Divide(4,4);
      for (int j = 0;j<16;++j) {
         c4[i]-> cd(j+1);
         if (j%2== 0) {
            hPathvMyPath[8*i+j/2]->Draw();
         }
         else {
            gPad->SetLogy();
            hPathvMyPathDiff[8*i+j/2]->Draw();
         }
      }
      c4[i]->SaveAs(TString::Format("Layers_%dto%d.pdf",8*i,8*i+7 ));
   }*/
   TCanvas* c5 = new TCanvas("c5","c5", 1000,1000);
   diffperTrack->Draw();
   gPad->SetLogy();
   c5->SaveAs("DiffPerTrack.pdf");
}
