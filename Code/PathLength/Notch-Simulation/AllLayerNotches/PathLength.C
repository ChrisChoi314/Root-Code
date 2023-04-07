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
   /*const int numLayers = 56;
   float docaLow = -1.09;
   float docaHi = -.88;
   float docaBin = 400;
   float entLow = -.05;
   float entHi = .01;
   float entBin = 400;
   float entInc = .03;
   float docInc = 0;*/
   
   //int numLayers = 56;
   int layersToUse[] = {2,10,16,22,28,34,40,46, 50,51,52,53,54,55};
   
   //for the local left view
   /*float docaLow = -1.1;
   float docaHi = -.9;
   float docaBin = 500;
   float entLow = -.06;
   float entHi = .02;
   float entBin = 500;
   float entInc = 0;
   float docInc = 0;*/

   //for the local right view
   /*float docaLow = .9;
   float docaHi = 1.1;
   float docaBin = 500;
   float entLow = -.02;
   float entHi = .06;
   float entBin = 500;
   float entInc = 0;
   float docInc = 0;*/


   //for the global view
   float docaLow = -2;
   float docaHi = 2;
   float docaBin = 500;
   float entLow = -M_PI;
   float entHi = M_PI;
   float entBin = 500;
   float entInc = 0;
   float docInc = 0;
   
   Double_t CDCinfo[] = {
      //Superlayer 1, layers 0-7
      160,16.8,.5,.5,.3299,   //nWire, r, r_down, r_up, half-width
      160,17.8,.5,.5,.3495,
      160,18.8,.5,.5,.3691,
      160,19.8,.5,.5,.3888,
      160,20.8,.5,.5,.4084,
      160,21.8,.5,.5,.4280,
      160,22.8,.5,.5,.4477,
      160,23.8,.5,.5,.4673,
      //Superlayer 2, layers 8-13
      160,25.70,1.4,.91,.5046,
      160,27.52,.91,.91,.5404,
      160,29.34,.91,.91,.5761,
      160,31.16,.91,.91,.6118,
      160,32.98,.91,.91,.6476,
      160,34.80,.91,.86,.6833,
      //Superlayer 3, layers 14-19
      192,36.52,0.86,0.91,0.5976,
      192,38.34,0.91,0.91,0.6273,
      192,40.16,0.91,0.91,0.6571,
      192,41.98,0.91,0.91,0.6869,
      192,43.80,0.91,0.91,0.7167,
      192,45.57,0.86,1.06,0.7456,
      //Superlayer 4, layers 20-25
      224,47.69,1.06,0.86,0.6689,
      224,49.46,0.91,0.91,0.6937,
      224,51.28,0.91,0.91,0.7192,
      224,53.10,0.91,0.91,0.7447,
      224,54.92,0.91,0.91,0.7703,
      224,56.69,0.86,0.86,0.7951,
      //Superlayer 5, layers 26-31
      256,58.41,0.86,0.86,0.7168,
      256,60.18,0.91,0.91,0.7385,
      256,62.00,0.91,0.91,0.7609,
      256,63.82,0.91,0.91,0.7832,
      256,65.64,0.91,0.91,0.8055,
      256,67.41,0.86,1.06,0.8272,
      //Superlayer 6, layers 32-37
      288,69.53,1.06,0.86,0.7585,
      288,71.30,0.91,0.91,0.7778,
      288,73.12,0.91,0.91,0.7976,
      288,74.94,0.91,0.91,0.8175,
      288,76.76,0.91,0.91,0.8373,
      288,78.53,0.86,0.86,0.8566,
      //Superlayer 7, layers 38-43
      320,80.25,0.86,0.86,0.7879,
      320,82.02,0.91,0.91,0.8052,
      320,83.84,0.91,0.91,0.8231,
      320,85.66,0.91,0.91,0.8410,
      320,87.48,0.91,0.91,0.8588,
      320,89.25,0.86,1.06,0.8762,
      //Superlayer 8, layers 44-49
      352,91.37,1.06,0.86,0.8155,
      352,93.14,0.91,0.91,0.8313,
      352,94.96,0.91,0.91,0.8475,
      352,96.78,0.91,0.91,0.8638,
      352,98.60,0.91,0.91,0.8800,
      352,100.37,0.86,0.86,0.8958,
      //Superlayer 9, layers 50-55
      384,102.09,0.86,0.86,0.8352,
      384,103.86,0.91,0.91,0.8497,
      384,105.68,0.91,0.91,0.8646,
      384,107.50,0.91,0.91,0.8795,
      384,109.32,0.91,0.91,0.8944,
      384,111.14,0.91,0.91,0.9093
   };
   int numLayers = 14;
   double mom = 0.5;

   TH2F* notches[numLayers] = {};
   DedxDriftCell * cells[numLayers] = {} ;
   for (int i = 0; i < numLayers; ++i) {
      cells[i] = MakeCell(layersToUse[i]);

      notches[i] = new TH2F(TString::Format("Notch Layer: %d",layersToUse[i]),
      TString::Format("hEnta vs hNDoca, Data from track, Layer: %d",layersToUse[i]), docaBin,
      docaLow,docaHi,entBin,entLow,entHi);
   }

   TH1F * lastLayer = new TH1F("data1", TString::Format("Last Layer a track went through, -.6 < costh < .8, pF*sinth > %f", mom ), 56, -.5,55.5);

   for (Long64_t jentry=0; jentry<500000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      /*for (int j = 0; j < hNHits ; ++j) {
         
         
         for (int i = 0; i < numLayers; ++i) {
            if (hLayer[j] == layersToUse[i]) {
               notches[i]->Fill(hNDoca[j], hEnta[j]);
            }
         }
      }*/
      if (fabs(pF*sqrt(1 - costh*costh)) > mom && (costh > -.6 && costh < .8) ) lastLayer->Fill(hLayer[hNHits-1]);

      
   }

   /*for (int i = 0; i < numLayers; ++i) {
      for (float docaIdx = docaLow-entInc*i/56; docaIdx < docaHi-entInc*i/56;docaIdx += (docaHi - docaLow)/docaBin ) {
         for (float entIdx = entLow-entInc*i/56; entIdx < entHi-entInc*i/56;
              entIdx += (entHi - entLow)/entBin ) {
            double mypath = cells[i]->dx(docaIdx*CDCinfo[layersToUse[i]*5+4],entIdx);
            if (mypath != 0) {
               notches[i]->Fill(docaIdx,entIdx,mypath);
            }
         }
      }
   }*/
   /*TCanvas *c1[3] = {};
   for (int i = 0; i < 3; ++i) {
      c1[i] = new TCanvas(TString::Format("c%d", i), TString::Format("c%d", i)
      , 1900,1300);
   }

   for (int i = 0 ; i < 3; ++i) {
      c1[i]->Divide(5,4);
      for (int j = 0; j < 20; ++j) {
         if (i != 2) {
            c1[i]->cd(j+1);
            notches[i*20 + j]->Draw();
         }
         else {
            if (j < 16) {
               c1[i]->cd(j+1);
               notches[i*20 + j]->Draw();
            }
         }
      }
      if (i != 2) {
         c1[i]->SaveAs(TString::Format("Global-Layers-%dto%d-Fix.pdf",20*i, 20*i + 19));
      }
      else {
         c1[i]->SaveAs(TString::Format("Global-Layers-%dto%d-Fix.pdf",20*i, 20*i + 15));
      }*/

   TCanvas * c2 = new TCanvas("c2", "c2",1000,1000); //1900,950); 
   /*c2->Divide(5,3);
   for (int i = 0 ; i < 14; ++i) {
      c2->cd(i+1); 
      notches[i]->Draw();
      gStyle->SetOptStat(0);
   }
   c2->SaveAs("BothNotch-RealData.pdf");*/
   lastLayer->Draw();
   gPad->SetLogy();
   c2->SaveAs("LastLayer-Mom500.pdf");
}
