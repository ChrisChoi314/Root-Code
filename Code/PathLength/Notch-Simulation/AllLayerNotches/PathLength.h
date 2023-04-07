//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul  6 11:30:17 2022 by ROOT version 5.34/30
// from TTree track/dE/dx information
// found on file: /mnt/data/widget.33.e24.electron.radee.root
//////////////////////////////////////////////////////////

#ifndef PathLength_h
#define PathLength_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <cmath>
#include <iostream>
#include <vector>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
class DedxPoint {

public:

  /** The default constructor sets the coordinates to zero. */
  DedxPoint() : m_x(0), m_y(0), m_valid(true) {}

  /** Construct a point DedxPoint object from x and y coordinates. */
  DedxPoint(double x, double y) : m_x(x), m_y(y), m_valid(true) {}

  /** Helper function to return the x-coordinates of a DedxPoint */
  double getX() const { return m_x; }

  /** Helper function to return the y-coordinates of a DedxPoint */
  double getY() const { return m_y; }

  /** Set the x and y coordinates of a DedxPoint */
  void setPoint(double x, double y)
  {
    m_x = x;
    m_y = y;
  }

  /** Calculate the distance between this and another point */
  double length(const DedxPoint& p)
  {
    // horizontal line
    if (m_y == p.getY()) return std::abs(m_x - p.getX());
    // vertical line
    else if (m_x == p.getX()) return std::abs(m_y - p.getY());
    // else use Pythagorean Theorem
    else return std::sqrt((m_x - p.getX()) * (m_x - p.getX()) +
                            (m_y - p.getY()) * (m_y - p.getY()));
  }

  /** Check whether this point lies within the endpoints of a line */
  bool isValid() const { return m_valid; }

  /** Mark this point as invalid (exists outside a DedxDriftCell) */
  void setInvalid() { m_valid = false; }

private:

  double m_x; /**< the x-coordinate of the DedxPoint */
  double m_y; /**< the y-coordinate of the DedxPoint */
  bool m_valid; /**< used to check if the point lies inside a boundary */

};

/** A class to hold the endpoints and slope of a line.
 *
 * This class is useful in determining the path length of a track through
 * a CDC cell.
 */
class DedxLine {

public:

  /** A line is definied either by a point and a slope, or by endpoints.
   * If a single point is given, both endpoints are given by the same
   * point (length = 0). */

  /** Default constructor */
  DedxLine(): m_m(0), m_vertical(false) {}

  /** Construct a DedxLine from the given DedxPoint and slope */
  DedxLine(const DedxPoint& p, const double slope) : m_p1(p), m_p2(p), m_m(slope), m_vertical(false) {}

  /** Construct a DedxLine from two DedxPoints */
  DedxLine(const DedxPoint& p1, const DedxPoint& p2) : m_p1(p1), m_p2(p2), m_vertical(false)
  {
    //check if the line is vertical (set vertical flag if it is)
    if (p1.getX() == p2.getX()) {
      m_m = -10000.0;
      m_vertical = true;
    } else
      m_m = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
  }

  /** Helper function to return the slope */
  double getSlope() const { return m_m; }

  /** Find the intersection of this and another line */
  DedxPoint intersection(const DedxLine& l)
  {
    double x, y;
    DedxPoint intP;

    // First check if the lines will intersect.
    // Also check for special cases of horizontal or
    // vertical lines.
    if (m_m == l.m_m) {
      //B2WARNING("Lines are parallel, will not intersect...");
      intP.setInvalid();
      intP.setPoint(0, 0);
      return intP;
    } else if (m_m == 0.0) {
      y = m_p1.getY();
      x = (y - l.m_p1.getY()) / l.m_m + l.m_p1.getX();
    } else if (l.m_m == 0.0) {
      y = l.m_p1.getY();
      x = (y - m_p1.getY()) / m_m + m_p1.getX();
    } else if (m_vertical) {
      x = m_p1.getX();
      y = l.m_p1.getY() + l.m_m * (x - l.m_p1.getX());
    } else if (l.isVertical()) {
      x = l.m_p1.getX();
      y = m_p1.getY() + m_m * (x - m_p1.getX());
    } else {
      x = ((l.m_p1.getY() - l.m_m * l.m_p1.getX()) - (m_p1.getY() - m_m * m_p1.getX())) / (m_m - l.m_m);
      y = m_p1.getY() + m_m * (x - m_p1.getX());
    }

    // This is the point of intersection
    intP.setPoint(x, y);

    // Check if the point falls outside the endpoints of the line.
    // This is useful for calculating the track length (dx).
    if ((x > m_p1.getX() && x > m_p2.getX()) ||
        (x < m_p1.getX() && x < m_p2.getX()))
      intP.setInvalid();
    if ((y > m_p1.getY() && y > m_p2.getY()) ||
        (y < m_p1.getY() && y < m_p2.getY()))
      intP.setInvalid();

    // Check if the DedxLine was made from a point and make sure the
    // point is not outside the cell
    /*if (l.m_p1.getX() == l.m_p2.getX() && l.m_p1.getY() == l.m_p2.getY() &&
        ((l.m_p1.getX() > m_p1.getX() && l.m_p1.getX() > m_p2.getX()) ||
         (l.m_p1.getX() < m_p1.getX() && l.m_p1.getX() < m_p2.getX())) &&
        ((l.m_p1.getY() > m_p1.getY() && l.m_p1.getY() > m_p2.getY()) ||
         (l.m_p1.getY() < m_p1.getY() && l.m_p1.getY() < m_p2.getY())))
      intP.setInvalid();*/

    return intP;
  }

  /** The m_vertical flag is used for the special case of a vertical line */
  bool isVertical() const { return m_vertical; }

  /** Mark this DedxLine as being vertical */
  void setVertical() { m_vertical = true; }

private:

  DedxPoint m_p1 ;    /**< First endpoint */
  DedxPoint m_p2;     /**< Second endpoint */
  double m_m;     /**< Slope of the line */
  int m_vertical; /**< If the line is vertical, this is set to true. */

};

/** A class to hold the geometry of a cell
 *
 * This class is used to actually calculate the path length of a track
 * moving through a given cell.
 */
class DedxDriftCell {

public:

  /** Construct a DedxDriftCell from four different DedxLines (sides) */
  DedxDriftCell(const DedxLine& left, const DedxLine& top, const DedxLine& right, const DedxLine& bot) : m_Left(left), m_Top(top),
    m_Right(right), m_Bot(bot), m_isValid(true) {}

  /** Construct a DedxDriftCell from four different DedxPoints (corners) */
  DedxDriftCell(const DedxPoint& tl, const DedxPoint& tr, const DedxPoint& br, const DedxPoint& bl) :  m_Left(bl, tl), m_Top(tl, tr),
    m_Right(tr, br), m_Bot(br, bl), m_isValid(true) {}

  /** Check if this is a valid calculation (number of intersections = 2) */
  bool isValid() { return m_isValid; }

  /** Calculate the path length through this cell for a track with a given
   * DedxPoint Of Closest Approach (poca) and entrance angle (entAng) */
  double dx(const DedxPoint& poca, double entAng)
  {
    // The path length (dx) is the length of the track in this cell.
    double Dx = 0;

    // The DedxPoint Of Closest Approach (poca) is useful for a reference point
    // to construct a line that represents the track.
    DedxLine track = DedxLine(poca, std::tan(M_PI_2 - entAng));

    // Find the points of intersection with each cell boundary
    DedxPoint intLeft = m_Left.intersection(track);
    DedxPoint intTop = m_Top.intersection(track);
    DedxPoint intRight = m_Right.intersection(track);
    DedxPoint intBot = m_Bot.intersection(track);

    std::vector<DedxPoint> endpoints;
    if (intLeft.isValid())
      endpoints.push_back(intLeft);
    if (intTop.isValid())
      endpoints.push_back(intTop);
    if (intRight.isValid())
      endpoints.push_back(intRight);
    if (intBot.isValid())
      endpoints.push_back(intBot);

    // Make sure we only get two intersections!
    if (endpoints.size() == 2) {
      Dx = endpoints[0].length(endpoints[1]);
      if (Dx == 0)
        m_isValid = false;
    } else
      m_isValid = false;

    return Dx;
  }

  /** Calculate the path length through this cell for a track with a given
   * Distance Of Closest Approach (doca) and entrance angle (entAng) */
  double dx(double doca, double entAng)
  {
    // The path length (dx) is the length of the track in this cell.
    double Dx = 0;

    // The DedxPoint Of Closest Approach (poca) is useful for a reference point
    // to construct a line that represents the track.
    const DedxPoint poca = DedxPoint(doca * std::abs(std::cos(entAng)), -1.0 * doca * std::sin(entAng));
    DedxLine track = DedxLine(poca, std::tan(M_PI_2 - entAng));

    // Find the points of intersection with each cell boundary
    DedxPoint intLeft = m_Left.intersection(track);
    DedxPoint intTop = m_Top.intersection(track);
    DedxPoint intRight = m_Right.intersection(track);
    DedxPoint intBot = m_Bot.intersection(track);

    std::vector< DedxPoint > endpoints;
    if (intLeft.isValid())
      endpoints.push_back(intLeft);
    if (intTop.isValid())
      endpoints.push_back(intTop);
    if (intRight.isValid())
      endpoints.push_back(intRight);
    if (intBot.isValid())
      endpoints.push_back(intBot);

    // Make sure we only get two intersections!
    if (endpoints.size() == 2) {
      Dx = endpoints[0].length(endpoints[1]);
      if (Dx == 0)
        m_isValid = false;
    } else
      m_isValid = false;

    return Dx;
  }

private:

  DedxLine m_Left;    /**< the left boundary of the cell */
  DedxLine m_Top;     /**< the left boundary of the cell */
  DedxLine m_Right;   /**< the left boundary of the cell */
  DedxLine m_Bot;     /**< the left boundary of the cell */
  bool m_isValid; /**< does the hit land in this cell */
};
class PathLength {
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
   Int_t           lNHitsCombined[56];   //[lNHits]
   Int_t           lWireLongestHit[56];   //[lNHits]
   Int_t           lLayer[56];   //[lNHits]
   Double_t        lPath[56];   //[lNHits]
   Double_t        lDedx[56];   //[lNHits]
   Int_t           hNHits;
   Int_t           hLWire[137];   //[hNHits]
   Int_t           hWire[137];   //[hNHits]
   Int_t           hLayer[137];   //[hNHits]
   Double_t        hPath[137];   //[hNHits]
   Double_t        hDedx[137];   //[hNHits]
   Double_t        hADCRaw[137];   //[hNHits]
   Double_t        hADCCorr[137];   //[hNHits]
   Double_t        hDoca[137];   //[hNHits]
   Double_t        hNDoca[137];   //[hNHits]
   Double_t        hNDocaRS[137];   //[hNHits]
   Double_t        hEnta[137];   //[hNHits]
   Double_t        hEntaRS[137];   //[hNHits]
   Double_t        hDriftT[137];   //[hNHits]
   Double_t        hDriftD[137];   //[hNHits]
   Double_t        hFacnlADC[137];   //[hNHits]
   Double_t        hWireGain[137];   //[hNHits]
   Double_t        hTwodcor[137];   //[hNHits]
   Double_t        hOnedcor[137];   //[hNHits]

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

   PathLength(TTree *tree=0);
   virtual ~PathLength();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   DedxDriftCell*    MakeCell(int idx);
};

#endif

#ifdef PathLength_cxx
PathLength::PathLength(TTree *tree) : fChain(0)
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

PathLength::~PathLength()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t PathLength::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t PathLength::LoadTree(Long64_t entry)
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

void PathLength::Init(TTree *tree)
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

Bool_t PathLength::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void PathLength::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t PathLength::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

DedxDriftCell* PathLength::MakeCell(int idx) {
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
   double radius = CDCinfo[idx*5+1];
   double outer = radius + CDCinfo[idx*5+3];
   double inner = radius - CDCinfo[idx*5+2];

   double topHeight = CDCinfo[idx*5+3];
   double bottomHeight = CDCinfo[idx*5+2];
   double cellHeight = topHeight + bottomHeight;
   double topHalfWidth = M_PI * outer / CDCinfo[idx*5];
   double bottomHalfWidth = M_PI * inner / CDCinfo[idx*5];

   DedxPoint tl = DedxPoint(-topHalfWidth, topHeight);
   const DedxPoint tr = DedxPoint(topHalfWidth, topHeight);
   const DedxPoint br = DedxPoint(bottomHalfWidth, -bottomHeight);
   const DedxPoint bl = DedxPoint(-bottomHalfWidth, -bottomHeight);
   DedxDriftCell* c = new DedxDriftCell(tl, tr, br, bl);
   //cout << tl.length(br) << endl;
   return c;
}
#endif // #ifdef PathLength_cxx
