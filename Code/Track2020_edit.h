//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Feb 29 17:46:31 2020 by ROOT version 5.34/30
// from TTree track/dE/dx information
// found on file: protons_proc11.root
//////////////////////////////////////////////////////////

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TChain.h"
#include "TList.h"
#include "TDirectory.h"
#include "TSystemDirectory.h"

#ifndef Track2020_h
#define Track2020_h

#include <TROOT.h>

#include "TMath.h"

#include <iostream>
#include <vector>
#include <stdio.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Track2020 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           exp;
   Int_t           run;
   Int_t           event;
   Double_t        phi;
   Double_t        vx0;
   Double_t        vy0;
   Double_t        vz0;
   Double_t        db;
   Double_t        dz;
   Double_t        chi2;
   Int_t           track;
   Double_t        length;
   Int_t           charge;
   Double_t        costh;
   Double_t        pF;
   Double_t        pdg;
   Double_t        ioasym;
   Double_t        eop;
   Int_t           klmLayers;
   Double_t        scale;
   Double_t        coscor;
   Double_t        rungain;
   Double_t        mean;
   Double_t        dedx;
   Double_t        dedxnosat;
   Double_t        dedxerr;
   Double_t        chiE;
   Double_t        chiMu;
   Double_t        chiPi;
   Double_t        chiK;
   Double_t        chiP;
   Double_t        chiD;
   Int_t           lNHits;
   Int_t           lNHitsUsed;
   Int_t           lNHitsCombined[55];   //[lNHits]
   Int_t           lWireLongestHit[55];   //[lNHits]
   Int_t           lLayer[55];   //[lNHits]
   Double_t        lPath[55];   //[lNHits]
   Double_t        lDedx[55];   //[lNHits]
   Int_t           hNHits;
   Int_t           hLWire[75];   //[hNHits]
   Int_t           hWire[75];   //[hNHits]
   Int_t           hLayer[75];   //[hNHits]
   Double_t        hPath[75];   //[hNHits]
   Double_t        hDedx[75];   //[hNHits]
   Double_t        hADCRaw[75];   //[hNHits]
   Double_t        hDoca[75];   //[hNHits]
   Double_t        hNDoca[75];   //[hNHits]
   Double_t        hNDocaRS[75];   //[hNHits]
   Double_t        hEnta[75];   //[hNHits]
   Double_t        hEntaRS[75];   //[hNHits]
   Double_t        hDriftT[75];   //[hNHits]
   Double_t        hWireGain[75];   //[hNHits]
   Double_t        hTwodcor[75];   //[hNHits]
   Double_t        hOnedcor[75];   //[hNHits]

   // List of branches
   TBranch        *b_exp;   //!
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_vx0;   //!
   TBranch        *b_vy0;   //!
   TBranch        *b_vz0;   //!
   TBranch        *b_db;   //!
   TBranch        *b_dz;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_track;   //!
   TBranch        *b_length;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_costh;   //!
   TBranch        *b_pF;   //!
   TBranch        *b_pdg;   //!
   TBranch        *b_ioasym;   //!
   TBranch        *b_eop;   //!
   TBranch        *b_klmLayers;   //!
   TBranch        *b_scale;   //!
   TBranch        *b_coscor;   //!
   TBranch        *b_rungain;   //!
   TBranch        *b_mean;   //!
   TBranch        *b_dedx;   //!
   TBranch        *b_dedxnosat;   //!
   TBranch        *b_dedxerr;   //!
   TBranch        *b_chiE;   //!
   TBranch        *b_chiMu;   //!
   TBranch        *b_chiPi;   //!
   TBranch        *b_chiK;   //!
   TBranch        *b_chiP;   //!
   TBranch        *b_chiD;   //!
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
   TBranch        *b_hDoca;   //!
   TBranch        *b_hNDoca;   //!
   TBranch        *b_hNDocaRS;   //!
   TBranch        *b_hEnta;   //!
   TBranch        *b_hEntaRS;   //!
   TBranch        *b_hDriftT;   //!
   TBranch        *b_hWireGain;   //!
   TBranch        *b_hTwodcor;   //!
   TBranch        *b_hOnedcor;   //!

   Track2020(TChain *tree=0);
   virtual ~Track2020();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   //   virtual Double_t     ADCmap(Double_t ADC);
   virtual Double_t     MyHits(Int_t imode);
   virtual Double_t     MyLayers();
   virtual Double_t     MyLayersFull(Int_t imode);
   virtual Double_t     MyLayersFullMap(Int_t imode);
   virtual Double_t     MyLayersFullBug(Int_t imode);
   virtual Double_t     MyTrunc(vector<double> dedxlist);
};

#endif


  std::vector<TString> getFiles(const char *dirname="/mnt/data/BelleIIData/prod4/release-01-02-09/calib_radee/", const char *pref="widget", const char *ext=".root") {
  //std::vector<TString> getFiles(const char *dirname="/mnt/data/BelleIIData/prod4c/BII-3814/hlt_hadron/", const char *pref="widget", const char *ext=".root") {
  //  std::vector<TString> getFiles(const char *dirname="/mnt/data/BelleIIData/[prod4b/BII-3814/hlt_hadron/", const char *pref="widget", const char *ext=".root") {
  //  std::vector<TString> getFiles(const char *dirname="/mnt/data/BelleIIData/prod4/release-01-02-09/hlt_hadron/", const char *pref="widget", const char *ext=".root") {
  std::vector<TString> fnames;
  TSystemDirectory dir(dirname, dirname);
  TList *files = dir.GetListOfFiles();
  if (files) {
    TSystemFile *file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
      fname = file->GetName();
      if (!file->IsDirectory() && fname.EndsWith(ext) && fname.BeginsWith(pref)) {
	TString fullname = TString::Format("%s",dirname)+fname.Data();
	fnames.push_back(fullname);
	cout << fullname << endl;
      }
    }
  }

  return fnames;
}

void prepareSamples(){
 
  TChain* track = new TChain("track");
  std::vector<TString> fnames = getFiles();
  int nfiles = fnames.size();
  for( int i = 0; i < nfiles; ++i ){
    track->AddFile(fnames[i]);
  }
  //  return track;
}


#ifdef Track2020_cxx
Track2020::Track2020(TChain *tree) : fChain(0) 
{

  // NEW single-file read when using a TChain
  tree = new TChain("track");
  //  tree->AddFile("/mnt/data/BelleIIData/prod2-2/release-01-02-03/DB00000382/widget.prod2-2.hlt_hadron.root");
  //  tree->AddFile("/mnt/data/BelleIIData/prod4/release-01-02-09/hlt_hadron.widget.root");
  //tree->AddFile("/mnt/data/BelleIIData/prod4/release-01-02-09/new_calib_radee.widget.root");
  //      tree->AddFile("/mnt/data/BelleIIData/preprod5/hlt_hadron.new.root");
  //      tree->AddFile("/mnt/data/BelleIIData/preprod5/hlt_bhabha.new.root");
  //    tree->AddFile("/mnt/data/BelleIIData/prod4/release-01-02-09/hlt_bhabha.widget.root");
  //tree->AddFile("/home/rbriere/radbha_pp6_widget.root");
  //    tree->AddFile("/home/rbriere/prod7_hadron.root");
  //      tree->AddFile("/home/rbriere/had_proc10.root");
  //              tree->AddFile("/home/rbriere/protons_proc11.root");
  //tree->AddFile("/home/rbriere/radb.root");
    tree->AddFile("/home/rbriere/radb_4866.root");
  //          tree->AddFile("/home/rbriere/testProtons_PID2212.root");
  //    tree->AddFile("/home/rbriere/prod7_bhabha.root");
  Init(tree);
  /*
  */

  /*
  // OLD single-file read when NOT using a TChain
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/jvbennett/firstData/newMultiTracks.root");
      if (!f || !f->IsOpen()) {
	f = new TFile("/home/jvbennett/firstData/newMultiTracks.root");
      }
      f->GetObject("track",tree);

   }
   Init(tree);
*/

  /*
  // Multi-file chain
  // Multi-file TChain
  tree = new TChain("track");
  std::vector<TString> fnames = getFiles();
  int nfiles = fnames.size();
  for( int i = 1; i < nfiles; ++i ){
    tree->AddFile(fnames[i]);
  }
   Init(tree);
  */
}

// /mnt/data/BelleIIData/prod2-2/release-01-02-03/DB00000382/widget

// std::vector<TString> getFiles(const char *dirname="/mnt/data/BelleIIData/prod4/release-01-02-09/hlt_hadron/", const char *pref="widget", const char *ext=".root") {

Track2020::~Track2020()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Track2020::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Track2020::LoadTree(Long64_t entry)
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

void Track2020::Init(TChain *tree)
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
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("vx0", &vx0, &b_vx0);
   fChain->SetBranchAddress("vy0", &vy0, &b_vy0);
   fChain->SetBranchAddress("vz0", &vz0, &b_vz0);
   fChain->SetBranchAddress("db", &db, &b_db);
   fChain->SetBranchAddress("dz", &dz, &b_dz);
   fChain->SetBranchAddress("chi2", &chi2, &b_chi2);
   fChain->SetBranchAddress("track", &track, &b_track);
   fChain->SetBranchAddress("length", &length, &b_length);
   fChain->SetBranchAddress("charge", &charge, &b_charge);
   fChain->SetBranchAddress("costh", &costh, &b_costh);
   fChain->SetBranchAddress("pF", &pF, &b_pF);
   fChain->SetBranchAddress("pdg", &pdg, &b_pdg);
   fChain->SetBranchAddress("ioasym", &ioasym, &b_ioasym);
   fChain->SetBranchAddress("eop", &eop, &b_eop);
   fChain->SetBranchAddress("klmLayers", &klmLayers, &b_klmLayers);
   fChain->SetBranchAddress("scale", &scale, &b_scale);
   fChain->SetBranchAddress("coscor", &coscor, &b_coscor);
   fChain->SetBranchAddress("rungain", &rungain, &b_rungain);
   fChain->SetBranchAddress("mean", &mean, &b_mean);
   fChain->SetBranchAddress("dedx", &dedx, &b_dedx);
   fChain->SetBranchAddress("dedxnosat", &dedxnosat, &b_dedxnosat);
   fChain->SetBranchAddress("dedxerr", &dedxerr, &b_dedxerr);
   fChain->SetBranchAddress("chiE", &chiE, &b_chiE);
   fChain->SetBranchAddress("chiMu", &chiMu, &b_chiMu);
   fChain->SetBranchAddress("chiPi", &chiPi, &b_chiPi);
   fChain->SetBranchAddress("chiK", &chiK, &b_chiK);
   fChain->SetBranchAddress("chiP", &chiP, &b_chiP);
   fChain->SetBranchAddress("chiD", &chiD, &b_chiD);
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
   fChain->SetBranchAddress("hDoca", hDoca, &b_hDoca);
   fChain->SetBranchAddress("hNDoca", hNDoca, &b_hNDoca);
   fChain->SetBranchAddress("hNDocaRS", hNDocaRS, &b_hNDocaRS);
   fChain->SetBranchAddress("hEnta", hEnta, &b_hEnta);
   fChain->SetBranchAddress("hEntaRS", hEntaRS, &b_hEntaRS);
   fChain->SetBranchAddress("hDriftT", hDriftT, &b_hDriftT);
   fChain->SetBranchAddress("hWireGain", hWireGain, &b_hWireGain);
   fChain->SetBranchAddress("hTwodcor", hTwodcor, &b_hTwodcor);
   fChain->SetBranchAddress("hOnedcor", hOnedcor, &b_hOnedcor);
   Notify();
}

Bool_t Track2020::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Track2020::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Track2020::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Track2020_cxx

// **********************************
// *** Saturation Correction Code ***
// **********************************

//double m_alpha= 1.40893e-02;
//double m_gamma= -9.69681e-04;
//double m_delta= 1.44238e-02;
//double m_power= 1.62013e+00;
double m_alpha= +0.03;
double m_gamma= -0.02;
double m_delta= 1.0e-01;
double m_power= 1.0e+00;
double m_ratio= 1.0;


// function to convert measured ionization (D) to actual ionization (I)
double D2I(const double& cosTheta, const double& D) 
{
  //cout<<"DedxCorrecSvc::D2I"<<endl;
  double absCosTheta   = fabs(cosTheta);
  double projection    = pow(absCosTheta,m_power) + m_delta;   // Projected length on wire
  double chargeDensity = D/projection;
  double numerator     = 1 + m_alpha*chargeDensity;
  double denominator   = 1 + m_gamma*chargeDensity;
  double I             = D;
 
  //if(denominator > 0.1)
 
  I = D * m_ratio* numerator/denominator;
 
  return I;
}

// Convert actual ionization (I) to measured ionization (D)
double I2D(const double& cosTheta, const double& I) 
{
  // cout<<" DedxCorrecSvc::I2D"<<endl;
  double absCosTheta = fabs(cosTheta);
  double projection  = pow(absCosTheta,m_power) + m_delta;   // Projected length on wire
 
  // Do the quadratic to compute d of the electron
  double a =  m_alpha / projection;
  double b =  1 - m_gamma / projection*(I/m_ratio);
  double c = -I/m_ratio;
 
  if(b==0 && a==0){
    cout<<"both a and b coefficients for hadron correction are 0"<<endl;
    return I;
  }

  double D = a != 0? (-b + sqrt(b*b - 4.0*a*c))/(2.0*a) : -c/b;
  if(D<0){
    cout<<"D is less 0! will try another solution"<<endl;
    D=a != 0? (-b - sqrt(b*b + 4.0*a*c))/(2.0*a) : -c/b;
    if(D<0){
      cout<<"D is still less 0! just return uncorrected value"<<endl;
      return I;
 
    }
  }
 
  return D;
}

// **********************************
// *** Electronic Non-Linearity  ***
// **********************************
Double_t ADCmap(const double& ADC)
{
// piecewise linear map
// y values are the saturated ADC readout
// x are the corrected ADC values
  double x[11] = {
      0.0, 200.0, 248.5, 344.0, 487.0, 642.5,
      787.6, 932.6,1171.0,1471.5,1906.7
  };
  double y[11] = {
      0.0, 200.0, 248.5, 344.0, 475.9, 572.4,
      634.5, 682.8, 758.6, 827.6, 910.3 
  };

  int ibin = 9;
  for(int i = 0; i<10; i++){
    if(ADC >= y[i] && ADC < y[i+1]) {ibin = i;}
  }

  // Invert
  double ADCnew =  x[ibin]
                + (ADC-y[ibin])/(y[ibin+1]-y[ibin])*(x[ibin+1]-x[ibin]);

  return ADCnew;
}

// **********************************
// *** dE/dx Re-calculation Code  ***
// **********************************


// ****************************************************
// HIT-LEVEL : test new methods, etc.
// ****************************************************
Double_t  Track2020::MyHits(Int_t imode)
{
  // PLAY with my own summing, etc.
  // HIT LEVEL 
  
  int lastlayer = 0;

  float corr;
  int myhNHits = 0;
  vector<double> dedxlist;
  
  for (int idx=0; idx<hNHits; ++idx){

    // drop hits after "curling" in B field...
    if( hLayer[idx] >= lastlayer ){
      lastlayer = hLayer[idx];
            
      corr = scale*coscor*rungain*hWireGain[idx]*hPath[idx]*hOnedcor[idx]*hTwodcor[idx]/sqrt(1-costh*costh);

      if( hPath[idx]>0.2 && corr!=0){
	dedxlist.push_back(hADCRaw[idx]/corr);
      }
      
      myhNHits++;
      
    }
    
  }  


  myhdedx = MyTrunc(dedxlist);
  
  double_t return_val = 0;
  if(imode == 0)  return_val = myhdedx;
     
  return return_val;

  // ***********************

}

// ****************************************************
// LAYER LEVEL : cross-check to reproduce public dE/dx
// Using calibrated Layer-level info (not ADCRaw, etc.)
// ****************************************************
Double_t  Track2020::MyLayers()
{
  vector<double> dedxlist;
  float mymean = 0.;
  float corr = 1.;
  int mylNHits = 0;
  
  // *** UPDATE *** UPDATE *** UPDATE *** UPDATE ***
  for (int idx=0; idx<lNHits; ++idx){
    mymean += lDedx[idx];     
    dedxlist.push_back(lDedx[idx]);    
    mylNHits++;      
  }
  
  //      if( mylNHits==0 ){ mylNHits = 1;}
  mymean = mymean/lNHits;
  double mydedx = MyTrunc(dedxlist);

  /*
  cout << "dedxnosat, mydedx:  " << dedxnosat << ", " << mydedx  << ", " 
       << lNHitsUsed << endl;
  double mydedx_final=  D2I(costh, I2D(costh,1.00)/1.00*mydedx);
  cout << "dedx, mydedx_final:  " << dedx << ", " << mydedx_final  << ", " 
       << lNHitsUsed << endl;
  */

  return mydedx;
  
}

// ****************************************************
// LAYER LEVEL : cross-check to reproduce public dE/dx
//   >>>>> Redo from ADCRaw, redo hit-combining...
// ****************************************************
Double_t  Track2020::MyLayersFull(Int_t imode)
{
  vector<double> dedxlist;
  float mymean = 0.;
  int   mylNHits = 0;

  int bad16[37] = {
     44,     45,     61,     62,     63,
    112,    113,    114,    140,    142,
    152,    154,    164,    166,    178,
    187,    190,    199,    202,    206,
    207,    208,    211,    299,    347,
    363,    379,    463,    481,    499,
    635,    657,    679,    701,    723,
    745,    846
  };

  float sumdE, sumdx;
  float corr;

  int curLayer = hLayer[0];  
  sumdE = 0.;
  sumdx = 0.;
  for (int idx=0; idx<hNHits; ++idx){

          //This works for prod6
    //        corr = scale*coscor*rungain*hWireGain[idx]*hOnedcor[idx]/sqrt(1-costh*costh);
          //This works for prod7 I HOPE
    //    corr = scale*coscor*rungain*hWireGain[idx]*hOnedcor[idx]*hTwodcor[idx]/sqrt(1-costh*costh);

    //This works for proc11 I HOPE
    //        corr = scale*coscor*rungain*hWireGain[idx]*hOnedcor[idx]*hTwodcor[idx]/sqrt(1-costh*costh);

	//  No empirical cell corrections
        corr = scale*coscor*rungain*hWireGain[idx]/sqrt(1-costh*costh);



    //Cut (most) bad wires
    int use = 1;
    int icard;
    for(int i=0; i<37; ++i){
      icard = hWire[idx]/16;
      if( icard == bad16[i]){
	    use = 0;
	  }
    }


    // imode 91-94 ADC Raw cuts
    if(hADCRaw[idx]<25 && imode==94 ) corr = 0;
    if(hADCRaw[idx]<18 && imode==93 ) corr = 0;
    if(hADCRaw[idx]<12 && imode==92 ) corr = 0;
    if(hADCRaw[idx]< 6 && imode==91 ) corr = 0;

    // imode 9: turn off bad wires
    if(use==0 && imode==9 ) corr = 0;

    // imode 10: no bad wires; also turn off inner layers
    if(  use==0  && imode==10 ) corr = 0;
    if(hLayer[idx]<20 && imode==10 ) corr = 0;
    
      double ecorr;
      if( (imode == 77) || (imode == 78) ){
	ecorr = 1.0 + 0.1*((abs(hEnta[idx])-0.2)/0.5);	      
	if( abs(hEnta[idx])<0.2 ) {ecorr = 1.0;}
	if( abs(hEnta[idx])>0.7 ) {ecorr = 1.1;}
	corr *= ecorr;
      }

      if(imode==78 && hEnta[idx]<0) {corr = corr/0.98;}

    // sumdx OUTSIDE = emulate bug; INSIDE = fixed
    if(corr != 0){
      sumdx += hPath[idx];
      sumdE += hADCRaw[idx]/corr;
    }
    // no more hits in this layer (last hit on track or next hit changing layer)
    if( idx==hNHits-1 || hLayer[idx+1]!=curLayer){
      if( sumdx!=0 && sumdE!=0){
	dedxlist.push_back(sumdE/sumdx);    
        if( imode==1 ) cout << "lyr, ldedx, sumdx  " << hLayer[idx] << " , " 
			    << sumdE/sumdx << " , " << sumdx << endl;
      }
      //get ready for new layer
      sumdE = 0.;
      sumdx = 0.;
      if(idx<hNHits-1) curLayer = hLayer[idx+1];
      //      if(imode == -1) {cout << "done, layer " << hLayer[idx] << endl;}
    }

    // drop inward part of curlers...
    if(idx<hNHits-1 && hLayer[idx+1]<hLayer[idx]) break;

  }

  mymean = mymean/lNHits;
  double mydedx = MyTrunc(dedxlist);


  if(imode == -1){
    cout << "Layer aves from my code TWEAKED" << endl;
    for(unsigned int ii=0; ii<dedxlist.size(); ii++){
      //      cout << "Layer, lDedx: " << dedxlist[ii]*dedxnosat/mydedx << endl;
      cout << "Layer, lDedx: " << dedxlist[ii] << endl;
    }
  }

  /*
  if(imode == -1){
    cout << "Hit Dump" << endl;
    for(int ii=0; ii<hNHits; ii++){
      cout << "Layer, hADCRaw, hPath, hEnta: " 
           << hLayer[ii] << " ; " << hADCRaw[ii] << " ; " 
           << hPath[ii]  << " ; " << hEnta[ii]   <<endl;
    }
  }
  */
  

  /*
  cout << "FULL dedxnosat, mydedx:  " << dedxnosat << ", " << mydedx  << ", " 
       << lNHitsUsed << endl;
  double mydedx_final=  D2I(costh, I2D(costh,1.00)/1.00*mydedx);
  cout << "FULL dedx, mydedx_final:  " << dedx << ", " << mydedx_final  << ", " 
       << lNHitsUsed << ", " << dedxlist.size() << ", " << hNHits << endl;
  */

  return mydedx;

}

// ****************************************************
// LAYER LEVEL : cross-check to reproduce public dE/dx
//   >>>>> Redo from ADCRaw, redo hit-combining...
// ****************************************************
Double_t  Track2020::MyLayersFullMap(Int_t imode)
{
  vector<double> dedxlist;
  float mymean = 0.;
  int   mylNHits = 0;

  int bad16[37] = {
     44,     45,     61,     62,     63,
    112,    113,    114,    140,    142,
    152,    154,    164,    166,    178,
    187,    190,    199,    202,    206,
    207,    208,    211,    299,    347,
    363,    379,    463,    481,    499,
    635,    657,    679,    701,    723,
    745,    846
  };

  float sumdE, sumdx;
  float corr;

  int curLayer = hLayer[0];  
  sumdE = 0.;
  sumdx = 0.;
  for (int idx=0; idx<hNHits; ++idx){

          //This works for prod6
    //        corr = scale*coscor*rungain*hWireGain[idx]*hOnedcor[idx]/sqrt(1-costh*costh);
          //This works for prod7 I HOPE
    //    corr = scale*coscor*rungain*hWireGain[idx]*hOnedcor[idx]*hTwodcor[idx]/sqrt(1-costh*costh);

    //This works for proc11 I HOPE
        corr = scale*coscor*rungain*hWireGain[idx]*hOnedcor[idx]*hTwodcor[idx]/sqrt(1-costh*costh);



    //Cut (most) bad wires
    int use = 1;
    int icard;
    for(int i=0; i<37; ++i){
      icard = hWire[idx]/16;
      if( icard == bad16[i]){
	    use = 0;
	  }
    }


    /*
    // non-lin map scale factor: ORIGINAL
    double sf = 1.0;
    if( imode == 1){ sf = 1.0; }
    if( imode == 2 ){
      sf =  1.6; 
    }
    if( imode == 3 ){
      sf =  1.6*hWireGain[idx];
    }
    if( imode == 4 ){
      sf =  1.6*hWireGain[idx];
      if( hLayer[idx]<8 ) {sf =  hWireGain[idx];}
    }
    */

    // non-lin map scale factor: TEST
    double sf = 1.0;
    if( imode == 1){ sf = 1.0; }
    if( imode == 2 ){
      sf =  1.6; 
    }
    if( imode == 3 ){
      sf =  1.6;
      if(hLayer[idx]<8) sf = 1.8;
    }
    if( imode == 4 ){
      sf =  1.6;
      if(hLayer[idx]<8) sf = 1.4;
    }


    if(corr != 0){
      sumdx += hPath[idx];

      // USE non-linearity function!!!
      if( imode == 0) {
	sumdE += hADCRaw[idx]/corr;
      }
      if( imode != 0) {
	sumdE += ( sf*ADCmap(hADCRaw[idx]/sf) )/corr;
      }

    }

    // no more hits in this layer 
    //         (last hit on track or next hit changing layer)
    if( idx==hNHits-1 || hLayer[idx+1]!=curLayer){
      if( sumdx!=0 && sumdE!=0){
	dedxlist.push_back(sumdE/sumdx);    
      //get ready for new layer
      sumdE = 0.;
      sumdx = 0.;
      if(idx<hNHits-1) curLayer = hLayer[idx+1];
    }

    // drop inward part of curlers...
    if(idx<hNHits-1 && hLayer[idx+1]<hLayer[idx]) break;

    }
  }
  mymean = mymean/lNHits;
  double mydedx = MyTrunc(dedxlist);


  return mydedx;

}

// ****************************************************
// LAYER LEVEL : cross-check to reproduce public dE/dx
//   >>>>> Redo from ADCRaw, redo hit-combining...
// ****************************************************
Double_t  Track2020::MyLayersFullBug(Int_t imode)
{
  vector<double> dedxlist;
  float mymean = 0.;
  int   mylNHits = 0;

  float sumdE, sumdx;
  float corr;

  int curLayer = hLayer[0];  
  sumdE = 0.;
  sumdx = 0.;
  for (int idx=0; idx<hNHits; ++idx){

    corr = scale*coscor*rungain*hWireGain[idx]*hOnedcor[idx]/sqrt(1-costh*costh);


    // sumdx OUTSIDE = emulate bug; INSIDE = fixed
    sumdx += hPath[idx];
    if(corr != 0){
      sumdE += hADCRaw[idx]/corr;
    }
    // no more hits in this layer (last hit on track or next hit changing layer)
    if( idx==hNHits-1 || hLayer[idx+1]!=curLayer){
      if( sumdx!=0 && sumdE!=0){
	dedxlist.push_back(sumdE/sumdx);    
        if( imode==1 ) cout << "lyr, ldedx, sumdx  " << hLayer[idx] << " , " 
			    << sumdE/sumdx << " , " << sumdx << endl;
      }
      //get ready for new layer
      sumdE = 0.;
      sumdx = 0.;
      if(idx<hNHits-1) curLayer = hLayer[idx+1];
      //      cout << "done, layer " << hLayer[idx] << endl;
    }

    // drop inward part of curlers...
    if(idx<hNHits-1 && hLayer[idx+1]<hLayer[idx]) break;

  }
  
  mymean = mymean/lNHits;
  double mydedx = MyTrunc(dedxlist);

  /*
  cout << "FULL dedxnosat, mydedx:  " << dedxnosat << ", " << mydedx  << ", " 
       << lNHitsUsed << endl;
  double mydedx_final=  D2I(costh, I2D(costh,1.00)/1.00*mydedx);
  cout << "FULL dedx, mydedx_final:  " << dedx << ", " << mydedx_final  << ", " 
       << lNHitsUsed << ", " << dedxlist.size() << ", " << hNHits << endl;
  */

  return mydedx;

}


// ***********************
// *** Truncation Tool ***
// ***********************
Double_t Track2020::MyTrunc(vector<double> dedxlist)
{
  // recalculate the truncated value
  std::sort(dedxlist.begin(),dedxlist.end());
  
  // KLUDGE
  int nHits = dedxlist.size();

  int lb = int(nHits * 0.05 + 0.51);
  int ub = int(nHits * 0.75 + 0.51);
  int ntrunc = 0;
  double mydedx = 0.;

  for( int j = 0; j < nHits; ++j ){
    if( j >= lb && j < ub){
      mydedx += dedxlist[j];
      ntrunc++;
    }
  }
  
  if(ntrunc>0){
    mydedx = mydedx/ntrunc;
  }
  else{
    mydedx = 0;
  }  

  return mydedx;
}

// ***********************
// *** Truncation Tool ***
// ***********************
void MyTruncLimits(int nHits)
{
  int lb = int(nHits * 0.05 + 0.51);
  int ub = int(nHits * 0.75 + 0.51);


  /*
  for( int j = 0; j < nHits; ++j ){
    if( j >= lb && j < ub){
      mydedx += dedxlist[j];
      ntrunc++;
    }
  }
  */

  cout << "0<->nHits-1; lo, hi (incl.), frac " << nHits << " , " 
       << lb << " , " << ub-1 << " , " << float(ub-lb)/nHits << endl;

}
