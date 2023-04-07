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


   DedxDriftCell * cells[numLayers] = {} ;
   for (int i = 0; i < numLayers; ++i) {
      cells[i] = MakeCell(i, );
   }
   int numTests = 6;
   DedxDriftCell * cells[numTests] = {};
   TH2F* MyPathvhPaths[numTests] = {};
   TH1F* DiffHists[numTests] = {};
   for (int i = 0; i < numTests; ++i) {
      double radius = 54.92;//105.675+ i*.005;
      double r_down = .915-i*.001;
      double r_up = .905 + i*.001;
      cells[i] = MakeCell(24,radius, r_down,r_up);
      MyPathvhPaths[i] = new TH2F(TString::Format("Plot %d",i ),TString::Format("hPath vs MyPath,Layer 24, R:%f,r_down:%f, r_up:%f",radius, r_down, r_up),800,.3,3, 800,.3,3);
      DiffHists[i] = new TH1F(TString::Format("Plot: %d",i ),TString::Format("MyPath - hPath, Layer 24,R:%f,r_down:%f, r_up:%f",radius, r_down, r_up),100, -.02,.02);
   }

   for (Long64_t jentry=0; jentry<200000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (inCDC && fabs(dr)<1 && fabs(dz)<1) {
         for (int j = 0;j < hNHits;++j) { 
            if (hLayer[j] == 24) {
               for (int i = 0 ; i < numTests;++i) {
                  double mypath = cells[i]->dx(hDoca[j],hEnta[j]);  
                  MyPathvhPaths[i]->Fill(mypath, hPath[j]);
                  DiffHists[i]->Fill(mypath - hPath[j]);     
               } 
            }    
         }    
      }
   }

   TCanvas *c1 = new TCanvas("c1", "c1", 2200,1200);
   c1->Divide(4,3);
   for (int i = 0 ; i < numTests;++i) {
      c1 ->cd(2*i+1);
      MyPathvhPaths[i]->Draw();
      c1->cd(2*i+2);
      DiffHists[i]->Draw();
      gPad->SetLogy();
   }
   c1->SaveAs("Layer24r_up-interval001.pdf");
}
