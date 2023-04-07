#define Tryit_cxx
#include "Tryit.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void Tryit::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Tryit.C
//      Root > Tryit t
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

   TH2F* PvsCos = new TH2F("PvsCos","PvsCos", 100, -1., 1., 160, -8., 8.);
   TH1F* dedx1 = new TH1F("dedx1","dedx1", 100, 0.5, 1.5);

   TH2F* NvsCos = new TH2F("NvsCos","NvsCos", 400, -1., 1.,400, 0., 55.);
   TH2F* dedxvsP = new TH2F("dedxvsP","dedxvsP", 400, -50., 50., 400, 0., 2.);

   TH2F* h30negent = new TH2F("h30negent", "h30negent", 400,-2,2,400,1.5,1.8);
   TH2F* h50negent = new TH2F("h50negent", "h50negent", 400,-2,2,400,1.5,1.8);

   TH2F* h30_wide = new TH2F("h30_wide","h30_wide", 400,-2,2,400,1.5,1.8);

   //   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   for (Long64_t jentry=0; jentry<250000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      PvsCos->Fill(costh, pF);
      dedx1->Fill(dedx);
      NvsCos->Fill(costh, hNHits);
      dedxvsP->Fill(pF, dedx);
      for (int i = 0;i < hNHits;i++) {
        if (hLayer[i] == 30 && abs(hEnta[i]+1.5708)<0.01) {
          h30negent->Fill(hDoca[i], hPath[i]);
        }
        else if (hLayer[i] == 50 && abs(hEnta[i]+1.5708)<0.01) {
          h50negent->Fill(hDoca[i], hPath[i]);
        }
        if (hLayer[i] == 30 && abs(hEnta[i]+1.5708)<0.1) {
          h30_wide->Fill(hDoca[i], hPath[i]);
        }
       }


    }
    TCanvas *Plots = new TCanvas("Plots","",650,650);
    Plots->Divide(2,2);
    Plots->cd(1);
    PvsCos->Draw();

    Plots->cd(2);
    dedx1->Draw();
    dedx1->Fit("gaus");

    Plots->cd(3);
    NvsCos->Draw();

    Plots->cd(4);
    dedxvsP->Draw();

    Plots->SaveAs("Tryit1.pdf");

    TCanvas *Plots1 = new TCanvas("Plots1","",650,450);
    Plots1->Divide(2,1);

    Plots1->cd(1);
    h30negent->Draw();
    h50negent->SetMarkerColor(kRed);
    h50negent->Draw("same");

    Plots1->cd(2);
    h30_wide->Draw();
    Plots->SaveAs("Tryit2.pdf");
}
