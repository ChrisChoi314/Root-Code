#define PathLength_cxx
#include "PathLength.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLegend.h"
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
   TH1F* sumofAbsInner = new TH1F("plot1", "|hDoca| + |hEnta|, diff < .0000001", 200,0, 3);
   TH1F* sumofAbsOuter = new TH1F("plot2", "|hDoca| + |hEnta|, diff > .0000001", 200,0, 3);
   for (int i = 0; i < numLayers; ++i) {
      cells[i] = MakeCell(i);

      /*hPathvMyPath[i] = new TH2F(TString::Format("Layer: %d",i),TString::Format("hPath vs MyPath,Layer: %d",i)
      ,800,0,2.7,800, 0, 2.7);

      hPathvMyPathDiff[i] = new TH1F(TString::Format("Layer: %d",i),TString::Format("MyPath - hPath,Layer: %d",i)
      ,200,0,.35);*/
   }
   /*float docaLow = -.36;
   float docaHi = -.29;
   float docaBin = 400;
   float entLow = -.04;
   float entHi = .02;
   float entBin = 400;*/

   float docaLow = .29;
   float docaHi = .36;
   float docaBin = 400;
   float entLow = -.02;
   float entHi = .04;
   float entBin = 400;

   /*float docaLow = -1.25;
   float docaHi = 1.25;
   float docaBin = 400;
   float entLow = -M_PI;
   float entHi = M_PI;
   float entBin = 400;*/

   double alpha = 1.19;

   TH2F* notch = new TH2F("plot", "hEnta vs hDoca, abs(MyPath - hPath) > .0000001, Layer 52",docaBin,
      docaLow,docaHi,entBin,entLow, entHi);

   TH2F* notch1 = new TH2F("plot1", "hEnta vs hDoca, abs(MyPath - hPath) > .0000001, Layer 52",docaBin,
      docaLow,docaHi,entBin,entLow, entHi);

   int64_t index = 0;
   FILE *f = fopen("test.txt", "w");
   fclose(f);

   for (Long64_t jentry=0; jentry<500000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      for (int j = 0; j < hNHits ; ++j) {
         if (hLayer[j] == 0 ){//&& hLWire[j] >= 0 && hLWire[j] < 50) {
            double mypath = cells[hLayer[j]]->dx(hDoca[j], hEnta[j]);

            /*if (index == 270959) {
               std::cout << "=======================\n";
               std::cout << jentry << ' ' << ientry << ' ' << nb << ' ' << nbytes << ' ' << j << ' ' << hDoca[j] << ' '
                  << hEnta[j] << ' ' << std::endl;
               printf("%.24lf, %.24lf, %.24lf\n", mypath, hPath[j], mypath - hPath[j]);
            }
            index++;

            FILE *f = fopen("test.txt", "a");
            fprintf(f, "%.24lf\n%.24lf\n", mypath, hPath[j]);
            fclose(f);
         //if (mypath == 0) {
            if (fabs(mypath - hPath[j]) < 0.0000001) {
               notch->Fill(hDoca[j], hEnta[j]);
               sumofAbsInner->Fill(fabs(hDoca[j]) + alpha*fabs(hEnta[j]));
            }
            else sumofAbsOuter->Fill(fabs(hDoca[j]) + alpha*fabs(hEnta[j]));
            
            if (fabs(hDoca[j]) + alpha*fabs(hEnta[j]) > .92)
               notch1->Fill(hDoca[j], hEnta[j]);
            */
         //}
         }
      }
   }

   /*TH2F* EntvDoca = new TH2F("notch test","hEnta vs hDoca, Layer 0, only MyPath = 0",docaBin,
      docaLow,docaHi,entBin,entLow, entHi);

   for (float docaIdx = docaLow; docaIdx < docaHi;docaIdx += (docaHi - docaLow)/docaBin ) {
      for (float entIdx = entLow; entIdx < entHi;entIdx += (entHi - entLow)/entBin ) {
         double mypath = cells[0]->dx(docaIdx,entIdx);
         if (mypath != 0) {
            EntvDoca->Fill(docaIdx,entIdx,mypath);
         }
      }
   }*/

   TCanvas *c2 = new TCanvas("c2", "c2", 1200,1200);
   //c1->Divide(2,1);
   //EntvDoca->Draw();
   //c1->cd(1);
   notch->Draw();

   notch1->SetMarkerColor(kRed);
   notch1->SetLineColor(kRed);
   notch1->Draw("same");
   notch->SetMarkerColor(kBlack);
   notch->SetLineColor(kBlack);
   notch->Draw("same");
   //c1->cd(2);
   //gPad->SetLogy();
   //gStyle->SetOptStat(0);
   //gPad->SetGridx();
   //gPad->SetGridy();
   //c2->SaveAs("EntaVDoca-Layer52-Diff0.pdf");

   TCanvas *c1 = new TCanvas("c1", "c1", 1200,1200);

   sumofAbsInner->SetMarkerColor(kRed);
   sumofAbsInner->SetLineColor(kRed);
   sumofAbsInner->Draw("same");
   sumofAbsOuter->SetMarkerColor(kBlack);
   sumofAbsOuter->SetLineColor(kBlack);
   sumofAbsOuter->Draw("same");
   TLegend* legend = new TLegend(.85,.6,1,.75);
   legend->AddEntry(sumofAbsInner, "Diff < .0000001","l");
   legend->AddEntry(sumofAbsOuter, "Diff > .0000001","l");
   legend->Draw();

   c1->SaveAs("SumOfAbs-Layer52.pdf");
}
