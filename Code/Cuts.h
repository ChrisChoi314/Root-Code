//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jun 17 14:12:27 2022 by ROOT version 5.34/30
// from TTree track/dE/dx information
// found on file: ../../radb.root
//////////////////////////////////////////////////////////

#ifndef Cuts_h
#define Cuts_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Cuts {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           exp;
   Int_t           run;
   Int_t           event;
   Double_t        d0;
   Double_t        z0;
   Double_t        dz;
   Double_t        dr;
   Double_t        dphi;
   Double_t        vx0;
   Double_t        vy0;
   Double_t        vz0;
   Double_t        tanlambda;
   Double_t        phi0;
   Double_t        chi2;
   Double_t        nCDChits;
   Int_t           inCDC;
   Int_t           track;
   Double_t        length;
   Int_t           charge;
   Double_t        costh;
   Double_t        pF;
   Double_t        p;
   Double_t        pt;
   Double_t        ioasym;
   Double_t        phi;
   Double_t        pdg;
   Double_t        mean;
   Double_t        dedx;
   Double_t        dedxnosat;
   Double_t        dedxerr;
   Double_t        eop;
   Double_t        e;
   Double_t        e1_9;
   Double_t        e9_21;
   Int_t           klmLayers;
   Double_t        scale;
   Double_t        coscor;
   Double_t        cosedgecor;
   Double_t        rungain;
   Double_t        chiE;
   Double_t        chiMu;
   Double_t        chiPi;
   Double_t        chiK;
   Double_t        chiP;
   Double_t        chiD;
   Double_t        pmeanE;
   Double_t        pmeanMu;
   Double_t        pmeanPi;
   Double_t        pmeanK;
   Double_t        pmeanP;
   Double_t        pmeanD;
   Double_t        presE;
   Double_t        presMu;
   Double_t        presPi;
   Double_t        presK;
   Double_t        presP;
   Double_t        presD;
   Int_t           lNHits;
   Int_t           lNHitsUsed;
   Int_t           lNHitsCombined[55];   //[lNHits]
   Int_t           lWireLongestHit[55];   //[lNHits]
   Int_t           lLayer[55];   //[lNHits]
   Double_t        lPath[55];   //[lNHits]
   Double_t        lDedx[55];   //[lNHits]
   Int_t           hNHits;
   Int_t           hLWire[110];   //[hNHits]
   Int_t           hWire[110];   //[hNHits]
   Int_t           hLayer[110];   //[hNHits]
   Double_t        hPath[110];   //[hNHits]
   Double_t        hDedx[110];   //[hNHits]
   Double_t        hADCRaw[110];   //[hNHits]
   Double_t        hADCCorr[110];   //[hNHits]
   Double_t        hDoca[110];   //[hNHits]
   Double_t        hNDoca[110];   //[hNHits]
   Double_t        hNDocaRS[110];   //[hNHits]
   Double_t        hEnta[110];   //[hNHits]
   Double_t        hEntaRS[110];   //[hNHits]
   Double_t        hDriftT[110];   //[hNHits]
   Double_t        hDriftD[110];   //[hNHits]
   Double_t        hFacnlADC[110];   //[hNHits]
   Double_t        hWireGain[110];   //[hNHits]
   Double_t        hTwodcor[110];   //[hNHits]
   Double_t        hOnedcor[110];   //[hNHits]

   // List of branches
   TBranch        *b_exp;   //!
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_d0;   //!
   TBranch        *b_z0;   //!
   TBranch        *b_dz;   //!
   TBranch        *b_dr;   //!
   TBranch        *b_dphi;   //!
   TBranch        *b_vx0;   //!
   TBranch        *b_vy0;   //!
   TBranch        *b_vz0;   //!
   TBranch        *b_tanlambda;   //!
   TBranch        *b_phi0;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_nCDChits;   //!
   TBranch        *b_inCDC;   //!
   TBranch        *b_track;   //!
   TBranch        *b_length;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_costh;   //!
   TBranch        *b_pF;   //!
   TBranch        *b_p;   //!
   TBranch        *b_pt;   //!
   TBranch        *b_ioasym;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_pdg;   //!
   TBranch        *b_mean;   //!
   TBranch        *b_dedx;   //!
   TBranch        *b_dedxnosat;   //!
   TBranch        *b_dedxerr;   //!
   TBranch        *b_eop;   //!
   TBranch        *b_e;   //!
   TBranch        *b_e1_9;   //!
   TBranch        *b_e9_21;   //!
   TBranch        *b_klmLayers;   //!
   TBranch        *b_scale;   //!
   TBranch        *b_coscor;   //!
   TBranch        *b_cosedgecor;   //!
   TBranch        *b_rungain;   //!
   TBranch        *b_chiE;   //!
   TBranch        *b_chiMu;   //!
   TBranch        *b_chiPi;   //!
   TBranch        *b_chiK;   //!
   TBranch        *b_chiP;   //!
   TBranch        *b_chiD;   //!
   TBranch        *b_pmeanE;   //!
   TBranch        *b_pmeanMu;   //!
   TBranch        *b_pmeanPi;   //!
   TBranch        *b_pmeanK;   //!
   TBranch        *b_pmeanP;   //!
   TBranch        *b_pmeanD;   //!
   TBranch        *b_presE;   //!
   TBranch        *b_presMu;   //!
   TBranch        *b_presPi;   //!
   TBranch        *b_presK;   //!
   TBranch        *b_presP;   //!
   TBranch        *b_presD;   //!
   TBranch        *b_lNHits;   //!
   TBranch        *b_lNHitsUsed;   //!
   TBranch        *b_lNHitsCombined;   //!
   TBranch        *b_lWireLongestHit;   //!
   TBranch        *b_lLayer;   //!
   TBranch        *b_lPath;   //!
   TBranch        *b_lDedx;   //!
   TBranch        *b_hNHits;   //!
   TBranch        *b_hLWire;   //!
   TBranch        *b_hWire;   //!
   TBranch        *b_hLayer;   //!
   TBranch        *b_hPath;   //!
   TBranch        *b_hDedx;   //!
   TBranch        *b_hADCRaw;   //!
   TBranch        *b_hADCCorr;   //!
   TBranch        *b_hDoca;   //!
   TBranch        *b_hNDoca;   //!
   TBranch        *b_hNDocaRS;   //!
   TBranch        *b_hEnta;   //!
   TBranch        *b_hEntaRS;   //!
   TBranch        *b_hDriftT;   //!
   TBranch        *b_hDriftD;   //!
   TBranch        *b_hFacnlADC;   //!
   TBranch        *b_hWireGain;   //!
   TBranch        *b_hTwodcor;   //!
   TBranch        *b_hOnedcor;   //!

   Cuts(TTree *tree=0);
   virtual ~Cuts();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Cuts_cxx
Cuts::Cuts(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/mnt/data/widget.33.e24.electron.radee.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/mnt/data/widget.33.e24.electron.radee.root");
      }
      f->GetObject("track",tree);

   }
   Init(tree);
}

Cuts::~Cuts()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Cuts::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Cuts::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Cuts::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("exp", &exp, &b_exp);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("d0", &d0, &b_d0);
   fChain->SetBranchAddress("z0", &z0, &b_z0);
   fChain->SetBranchAddress("dz", &dz, &b_dz);
   fChain->SetBranchAddress("dr", &dr, &b_dr);
   fChain->SetBranchAddress("dphi", &dphi, &b_dphi);
   fChain->SetBranchAddress("vx0", &vx0, &b_vx0);
   fChain->SetBranchAddress("vy0", &vy0, &b_vy0);
   fChain->SetBranchAddress("vz0", &vz0, &b_vz0);
   fChain->SetBranchAddress("tanlambda", &tanlambda, &b_tanlambda);
   fChain->SetBranchAddress("phi0", &phi0, &b_phi0);
   fChain->SetBranchAddress("chi2", &chi2, &b_chi2);
   fChain->SetBranchAddress("nCDChits", &nCDChits, &b_nCDChits);
   fChain->SetBranchAddress("inCDC", &inCDC, &b_inCDC);
   fChain->SetBranchAddress("track", &track, &b_track);
   fChain->SetBranchAddress("length", &length, &b_length);
   fChain->SetBranchAddress("charge", &charge, &b_charge);
   fChain->SetBranchAddress("costh", &costh, &b_costh);
   fChain->SetBranchAddress("pF", &pF, &b_pF);
   fChain->SetBranchAddress("p", &p, &b_p);
   fChain->SetBranchAddress("pt", &pt, &b_pt);
   fChain->SetBranchAddress("ioasym", &ioasym, &b_ioasym);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("pdg", &pdg, &b_pdg);
   fChain->SetBranchAddress("mean", &mean, &b_mean);
   fChain->SetBranchAddress("dedx", &dedx, &b_dedx);
   fChain->SetBranchAddress("dedxnosat", &dedxnosat, &b_dedxnosat);
   fChain->SetBranchAddress("dedxerr", &dedxerr, &b_dedxerr);
   fChain->SetBranchAddress("eop", &eop, &b_eop);
   fChain->SetBranchAddress("e", &e, &b_e);
   fChain->SetBranchAddress("e1_9", &e1_9, &b_e1_9);
   fChain->SetBranchAddress("e9_21", &e9_21, &b_e9_21);
   fChain->SetBranchAddress("klmLayers", &klmLayers, &b_klmLayers);
   fChain->SetBranchAddress("scale", &scale, &b_scale);
   fChain->SetBranchAddress("coscor", &coscor, &b_coscor);
   fChain->SetBranchAddress("cosedgecor", &cosedgecor, &b_cosedgecor);
   fChain->SetBranchAddress("rungain", &rungain, &b_rungain);
   fChain->SetBranchAddress("chiE", &chiE, &b_chiE);
   fChain->SetBranchAddress("chiMu", &chiMu, &b_chiMu);
   fChain->SetBranchAddress("chiPi", &chiPi, &b_chiPi);
   fChain->SetBranchAddress("chiK", &chiK, &b_chiK);
   fChain->SetBranchAddress("chiP", &chiP, &b_chiP);
   fChain->SetBranchAddress("chiD", &chiD, &b_chiD);
   fChain->SetBranchAddress("pmeanE", &pmeanE, &b_pmeanE);
   fChain->SetBranchAddress("pmeanMu", &pmeanMu, &b_pmeanMu);
   fChain->SetBranchAddress("pmeanPi", &pmeanPi, &b_pmeanPi);
   fChain->SetBranchAddress("pmeanK", &pmeanK, &b_pmeanK);
   fChain->SetBranchAddress("pmeanP", &pmeanP, &b_pmeanP);
   fChain->SetBranchAddress("pmeanD", &pmeanD, &b_pmeanD);
   fChain->SetBranchAddress("presE", &presE, &b_presE);
   fChain->SetBranchAddress("presMu", &presMu, &b_presMu);
   fChain->SetBranchAddress("presPi", &presPi, &b_presPi);
   fChain->SetBranchAddress("presK", &presK, &b_presK);
   fChain->SetBranchAddress("presP", &presP, &b_presP);
   fChain->SetBranchAddress("presD", &presD, &b_presD);
   fChain->SetBranchAddress("lNHits", &lNHits, &b_lNHits);
   fChain->SetBranchAddress("lNHitsUsed", &lNHitsUsed, &b_lNHitsUsed);
   fChain->SetBranchAddress("lNHitsCombined", lNHitsCombined, &b_lNHitsCombined);
   fChain->SetBranchAddress("lWireLongestHit", lWireLongestHit, &b_lWireLongestHit);
   fChain->SetBranchAddress("lLayer", lLayer, &b_lLayer);
   fChain->SetBranchAddress("lPath", lPath, &b_lPath);
   fChain->SetBranchAddress("lDedx", lDedx, &b_lDedx);
   fChain->SetBranchAddress("hNHits", &hNHits, &b_hNHits);
   fChain->SetBranchAddress("hLWire", hLWire, &b_hLWire);
   fChain->SetBranchAddress("hWire", hWire, &b_hWire);
   fChain->SetBranchAddress("hLayer", hLayer, &b_hLayer);
   fChain->SetBranchAddress("hPath", hPath, &b_hPath);
   fChain->SetBranchAddress("hDedx", hDedx, &b_hDedx);
   fChain->SetBranchAddress("hADCRaw", hADCRaw, &b_hADCRaw);
   fChain->SetBranchAddress("hADCCorr", hADCCorr, &b_hADCCorr);
   fChain->SetBranchAddress("hDoca", hDoca, &b_hDoca);
   fChain->SetBranchAddress("hNDoca", hNDoca, &b_hNDoca);
   fChain->SetBranchAddress("hNDocaRS", hNDocaRS, &b_hNDocaRS);
   fChain->SetBranchAddress("hEnta", hEnta, &b_hEnta);
   fChain->SetBranchAddress("hEntaRS", hEntaRS, &b_hEntaRS);
   fChain->SetBranchAddress("hDriftT", hDriftT, &b_hDriftT);
   fChain->SetBranchAddress("hDriftD", hDriftD, &b_hDriftD);
   fChain->SetBranchAddress("hFacnlADC", hFacnlADC, &b_hFacnlADC);
   fChain->SetBranchAddress("hWireGain", hWireGain, &b_hWireGain);
   fChain->SetBranchAddress("hTwodcor", hTwodcor, &b_hTwodcor);
   fChain->SetBranchAddress("hOnedcor", hOnedcor, &b_hOnedcor);
   Notify();
}

Bool_t Cuts::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Cuts::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Cuts::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Cuts_cxx
