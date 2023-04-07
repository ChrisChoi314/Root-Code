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

   TH2F* DiffvEnta = new TH2F("diff plot1", "MyPath - hPath vs hEnta",200, -M_PI, M_PI,200, -.35, .35);
   TH2F* DiffvLayer = new TH2F("diff plot2","MyPath - hPath vs Layer",56,-.5,55.5,200, -.35, .35);
   TH2F* DiffvDoca = new TH2F("diff plot3","MyPath - hPath vs hDoca",200,-1,1,200, -.35, .35);
   TH2F* DiffvPath = new TH2F("diff plot4","MyPath - hPath vs hPath",200,0,2.7,200, -.35, .35);

   TH2F* Lay02d = new TH2F("diff plot5","hPath vs MyPath, Layer 0, r_down = 0.5",400,0,1.5,400, 0,1.5);
   TH1F* Lay01d = new TH1F("diff plot 6", "MyPath - hPath, Layer 0, r_down = 0.5", 200, -.1, .1);

   TH2F* Lay552d = new TH2F("diff plot6","hPath vs MyPath, Layer 55, r_up = 0.91",400,0,3.5,400, 0,3.5);
   TH1F* Lay551d = new TH1F("diff plot7", "MyPath - hPath, Layer 55, r_up = 0.91", 400, -.02,.02);  //-.5,2 is the original

   DedxDriftCell * cells[numLayers] = {};
   for (int i = 0; i < numLayers; ++i) {
      cells[i] = MakeCell(i);

      /*hPathvMyPath[i] = new TH2F(TString::Format("Layer: %d",i),TString::Format("hPath vs MyPath,Layer: %d",i)
      ,800,0,2.7,800, 0, 2.7);

      hPathvMyPathDiff[i] = new TH1F(TString::Format("Layer: %d",i),TString::Format("MyPath - hPath,Layer: %d",i)
      ,200,0,.35);*/
   }
   TH1F* entAng = new TH1F("enta", "Entrance Angles, Layer 52, close to 0", 200, -.1, .1);

   TH2F* PathPlotEnta0 = new TH2F("pathplot1","hPath vs MyPath, Layer 52, hEnta ~ 0",800,.5,2, 800,.5,2);
   TH2F* PathPlotEntaPi2 = new TH2F("pathplot2","hPath vs MyPath, Layer 52, hEnta ~ +/- pi/2",800,1.6,1.8, 800, 1.6,1.8);

   TH1F* DiffEnta0 = new TH1F("diff1", "MyPath - hPath,  Layer 52, hEnta ~ 0", 100, -.02, .02);
   TH1F* DiffEntaPi2 = new TH1F("diff2", "MyPath - hPath, Layer 52, hEnta ~ +/- pi/2", 100, -.001, .001);

   TH2F* diffvWireNum = new TH2F("wirenum", "MyPath - hPath vs hLWire, Layer 52", 384, -.5, 383.5, 200, -.02,.02);
   TH1F* SumofDiff = new TH1F("diff3", "Sum of MyPath - hPath per track", 200, -.15,.15);

   for (Long64_t jentry=0; jentry<500000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (inCDC && fabs(dr)<1 && fabs(dz)<1) {
         double sum = 0;
         for (int j = 0;j < hNHits;++j) { 
            double mypath = cells[hLayer[j]]->dx(hDoca[j],hEnta[j]);  
            if (hLayer[j] == 52) { 
               diffvWireNum->Fill(hLWire[j],mypath - hPath[j]);
            }
            sum += (mypath - hPath[j]);
            if (hLayer[j] == 52) {
               /*if (fabs(hEnta[j]) < .05  ) {
                  PathPlotEnta0->Fill(mypath, hPath[j]);
                  DiffEnta0->Fill(mypath - hPath[j]);                  
               }
               else if ( fabs(hEnta[j] - M_PI_2 ) < .05 || fabs(hEnta[j] + M_PI_2 ) < .05 ){
                  PathPlotEntaPi2->Fill(mypath, hPath[j]);
                  DiffEntaPi2->Fill(mypath - hPath[j]);
               }
               DiffvEnta->Fill(hEnta[j],mypath - hPath[j]);
            DiffvLayer->Fill(hLayer[j], mypath - hPath[j]);
            DiffvDoca->Fill(hDoca[j],mypath - hPath[j]);    
            DiffvPath->Fill(hPath[j],mypath - hPath[j]); */
               if (fabs(mypath - hPath[j]) > .0000001 ){
                  Lay552d->Fill(mypath, hPath[j]);
                  Lay551d->Fill(mypath - hPath[j]);
               }
         
            }
            /*if (hLayer[j] == 3) {
               Lay02d->Fill(mypath, hPath[j]);
               Lay01d->Fill(mypath - hPath[j]);
            }*/

            /*if (std::fabs(mypath - hPath[j])> .3 ) std::cout<< 
            TString::Format("Layer: %d, myPath: %f,hPath: %f,enta: %f, doca: %f",
            hLayer[j],mypath, hPath[j], hEnta[j], hDoca[j]) << std::endl;*/
  
         }    
         SumofDiff->Fill(sum);
      }
   }

   /*TCanvas *c1 = new TCanvas("c1", "c1", 1000,1000);
   c1->Divide(2,2);
   c1->cd(1);
   PathPlotEnta0->Draw();
   c1->cd(2);
   DiffEnta0->Draw();
   gPad->SetLogy();

   c1->cd(3);
   PathPlotEntaPi2->Draw();
   c1->cd(4);
   DiffEntaPi2->Draw();
   gPad->SetLogy();
   //c1->SaveAs("Layer52-Enta0andPi2.pdf");

   TCanvas *c2 = new TCanvas("c2", "c2", 1000,1000);
   c2->Divide(2,2);
   c2->cd(1);
   DiffvDoca->Draw();
   c2->cd(2);
   DiffvEnta->Draw();
   c2->cd(3);
   DiffvLayer->Draw();
   c2->cd(4);
   DiffvPath->Draw();
   //c2->SaveAs("DiffvVarious.pdf");*/

   TCanvas *c3 = new TCanvas("c3", "c3", 1400,1000);
   c3->Divide(2,2);
   /*c3->cd(1);
   Lay02d->Draw();
   c3->cd(2);
   Lay01d->Draw();
   gPad->SetLogy();*/

   c3->cd(1);
   Lay552d->Draw();
   c3->cd(2);
   Lay551d->Draw();
   //c3->SaveAs("Layer0-55-NewSizes.pdf");

   TCanvas *c5 = new TCanvas("c5", "c5", 1000,1000);
   diffvWireNum->Draw();
   c5->SaveAs("DiffvsWireNum-Layer52.pdf");

   TCanvas *c4 = new TCanvas("c4", "c4", 1000,1000);
   SumofDiff->Draw();
   gPad->SetLogy();
   c4->SaveAs("SumofDiff.pdf");
   
}
