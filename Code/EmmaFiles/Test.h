//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug  2 17:27:26 2022 by ROOT version 5.34/30
// from TTree Dst_recon/
// found on file: /mnt/data/EmmaAna/DstToD0pi_D0Topipipi0_NAv6_17240300_APSApril2021.root
//////////////////////////////////////////////////////////

#ifndef Test_h
#define Test_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMax__experiment_ = 1;
   const Int_t kMax__run_ = 1;
   const Int_t kMax__event_ = 1;
   const Int_t kMax__production_ = 1;
   const Int_t kMax__candidate_ = 1;
   const Int_t kMax__ncandidates_ = 1;
   const Int_t kMax__weight_ = 1;

class Test {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           __experiment__;
   Int_t           __run__;
   Int_t           __event__;
   Int_t           __production__;
   Int_t           __candidate__;
   Int_t           __ncandidates__;
   Double_t        __weight__;
   Double_t        Dst_fitStatus;
   Double_t        delM;
   Double_t        delMErr;
   Double_t        Dst_M;
   Double_t        Dst_ErrM;
   Double_t        Dst_SigM;
   Double_t        Dst_InvM;
   Double_t        Dst_px;
   Double_t        Dst_py;
   Double_t        Dst_pz;
   Double_t        Dst_pt;
   Double_t        Dst_p;
   Double_t        Dst_E;
   Double_t        Dst_distance;
   Double_t        Dst_significanceOfDistance;
   Double_t        Dst_dx;
   Double_t        Dst_dy;
   Double_t        Dst_dz;
   Double_t        Dst_x;
   Double_t        Dst_y;
   Double_t        Dst_z;
   Double_t        Dst_x_uncertainty;
   Double_t        Dst_y_uncertainty;
   Double_t        Dst_z_uncertainty;
   Double_t        Dst_dr;
   Double_t        Dst_dphi;
   Double_t        Dst_dcosTheta;
   Double_t        Dst_prodVertexX;
   Double_t        Dst_prodVertexY;
   Double_t        Dst_prodVertexZ;
   Double_t        Dst_prodVertexXErr;
   Double_t        Dst_prodVertexYErr;
   Double_t        Dst_prodVertexZErr;
   Double_t        Dst_chiProb;
   Double_t        Dst_flightTime;
   Double_t        Dst_flightDistance;
   Double_t        Dst_flightTimeErr;
   Double_t        Dst_flightDistanceErr;
   Double_t        Dst_CMS_px;
   Double_t        Dst_CMS_py;
   Double_t        Dst_CMS_pz;
   Double_t        Dst_CMS_pt;
   Double_t        Dst_CMS_p;
   Double_t        Dst_CMS_E;
   Double_t        Dst_charge;
   Double_t        D0_M;
   Double_t        D0_ErrM;
   Double_t        D0_SigM;
   Double_t        D0_InvM;
   Double_t        D0_px;
   Double_t        D0_py;
   Double_t        D0_pz;
   Double_t        D0_pt;
   Double_t        D0_p;
   Double_t        D0_E;
   Double_t        D0_distance;
   Double_t        D0_significanceOfDistance;
   Double_t        D0_dx;
   Double_t        D0_dy;
   Double_t        D0_dz;
   Double_t        D0_x;
   Double_t        D0_y;
   Double_t        D0_z;
   Double_t        D0_x_uncertainty;
   Double_t        D0_y_uncertainty;
   Double_t        D0_z_uncertainty;
   Double_t        D0_dr;
   Double_t        D0_dphi;
   Double_t        D0_dcosTheta;
   Double_t        D0_prodVertexX;
   Double_t        D0_prodVertexY;
   Double_t        D0_prodVertexZ;
   Double_t        D0_prodVertexXErr;
   Double_t        D0_prodVertexYErr;
   Double_t        D0_prodVertexZErr;
   Double_t        D0_chiProb;
   Double_t        D0_flightTime;
   Double_t        D0_flightDistance;
   Double_t        D0_flightTimeErr;
   Double_t        D0_flightDistanceErr;
   Double_t        D0_CMS_cosTheta;
   Double_t        D0_CMS_p;
   Double_t        D0_CMS_E;
   Double_t        D0_charge;
   Double_t        D0_flightDistSig;
   Double_t        D0_flightTimeSig;
   Double_t        pip_M;
   Double_t        pip_ErrM;
   Double_t        pip_SigM;
   Double_t        pip_InvM;
   Double_t        pip_px;
   Double_t        pip_py;
   Double_t        pip_pz;
   Double_t        pip_pt;
   Double_t        pip_p;
   Double_t        pip_E;
   Double_t        pip_dr;
   Double_t        pip_dx;
   Double_t        pip_dy;
   Double_t        pip_dz;
   Double_t        pip_d0;
   Double_t        pip_z0;
   Double_t        pip_pValue;
   Double_t        pip_ndf;
   Double_t        pip_nCDCHits;
   Double_t        pip_nPXDHits;
   Double_t        pip_nSVDHits;
   Double_t        pip_nVXDHits;
   Double_t        pip_d0Err;
   Double_t        pip_z0Err;
   Double_t        pip_phi0;
   Double_t        pip_phi0Err;
   Double_t        pip_dphi;
   Double_t        pip_phi;
   Double_t        pip_cosTheta;
   Double_t        pip_CMS_cosTheta;
   Double_t        pip_CMS_p;
   Double_t        pip_CMS_E;
   Double_t        pip_thetaInCDCAcceptance;
   Double_t        pip_charge;
   Double_t        pip_pionID;
   Double_t        pip_pionpairID;
   Double_t        pip_pionID_CDC;
   Double_t        pip_pionpairID_CDC;
   Double_t        pip_pionID_TOP;
   Double_t        pip_pionpairID_TOP;
   Double_t        pip_pionID_ARICH;
   Double_t        pip_pionpairID_ARICH;
   Double_t        pip_pionID_CDC_TOP_ARICH;
   Double_t        pip_pionpairID_CDC_TOP_ARICH;
   Double_t        pim_M;
   Double_t        pim_ErrM;
   Double_t        pim_SigM;
   Double_t        pim_InvM;
   Double_t        pim_px;
   Double_t        pim_py;
   Double_t        pim_pz;
   Double_t        pim_pt;
   Double_t        pim_p;
   Double_t        pim_E;
   Double_t        pim_dr;
   Double_t        pim_dx;
   Double_t        pim_dy;
   Double_t        pim_dz;
   Double_t        pim_d0;
   Double_t        pim_z0;
   Double_t        pim_pValue;
   Double_t        pim_ndf;
   Double_t        pim_nCDCHits;
   Double_t        pim_nPXDHits;
   Double_t        pim_nSVDHits;
   Double_t        pim_nVXDHits;
   Double_t        pim_d0Err;
   Double_t        pim_z0Err;
   Double_t        pim_phi0;
   Double_t        pim_phi0Err;
   Double_t        pim_dphi;
   Double_t        pim_phi;
   Double_t        pim_cosTheta;
   Double_t        pim_CMS_cosTheta;
   Double_t        pim_CMS_p;
   Double_t        pim_CMS_E;
   Double_t        pim_thetaInCDCAcceptance;
   Double_t        pim_charge;
   Double_t        pim_pionID;
   Double_t        pim_pionpairID;
   Double_t        pim_pionID_CDC;
   Double_t        pim_pionpairID_CDC;
   Double_t        pim_pionID_TOP;
   Double_t        pim_pionpairID_TOP;
   Double_t        pim_pionID_ARICH;
   Double_t        pim_pionpairID_ARICH;
   Double_t        pim_pionID_CDC_TOP_ARICH;
   Double_t        pim_pionpairID_CDC_TOP_ARICH;
   Double_t        pis_M;
   Double_t        pis_ErrM;
   Double_t        pis_SigM;
   Double_t        pis_InvM;
   Double_t        pis_px;
   Double_t        pis_py;
   Double_t        pis_pz;
   Double_t        pis_pt;
   Double_t        pis_p;
   Double_t        pis_E;
   Double_t        pis_dr;
   Double_t        pis_dx;
   Double_t        pis_dy;
   Double_t        pis_dz;
   Double_t        pis_d0;
   Double_t        pis_z0;
   Double_t        pis_pValue;
   Double_t        pis_ndf;
   Double_t        pis_nCDCHits;
   Double_t        pis_nPXDHits;
   Double_t        pis_nSVDHits;
   Double_t        pis_nVXDHits;
   Double_t        pis_d0Err;
   Double_t        pis_z0Err;
   Double_t        pis_phi0;
   Double_t        pis_phi0Err;
   Double_t        pis_dphi;
   Double_t        pis_phi;
   Double_t        pis_cosTheta;
   Double_t        pis_CMS_cosTheta;
   Double_t        pis_CMS_p;
   Double_t        pis_CMS_E;
   Double_t        pis_thetaInCDCAcceptance;
   Double_t        pis_charge;
   Double_t        pis_pionID;
   Double_t        pis_pionpairID;
   Double_t        pis_pionID_CDC;
   Double_t        pis_pionpairID_CDC;
   Double_t        pis_pionID_TOP;
   Double_t        pis_pionpairID_TOP;
   Double_t        pis_pionID_ARICH;
   Double_t        pis_pionpairID_ARICH;
   Double_t        pis_pionID_CDC_TOP_ARICH;
   Double_t        pis_pionpairID_CDC_TOP_ARICH;
   Double_t        pi0_M;
   Double_t        pi0_ErrM;
   Double_t        pi0_SigM;
   Double_t        pi0_InvM;
   Double_t        pi0_px;
   Double_t        pi0_py;
   Double_t        pi0_pz;
   Double_t        pi0_pt;
   Double_t        pi0_p;
   Double_t        pi0_E;
   Double_t        pi0_distance;
   Double_t        pi0_significanceOfDistance;
   Double_t        pi0_dx;
   Double_t        pi0_dy;
   Double_t        pi0_dz;
   Double_t        pi0_x;
   Double_t        pi0_y;
   Double_t        pi0_z;
   Double_t        pi0_x_uncertainty;
   Double_t        pi0_y_uncertainty;
   Double_t        pi0_z_uncertainty;
   Double_t        pi0_dr;
   Double_t        pi0_dphi;
   Double_t        pi0_dcosTheta;
   Double_t        pi0_prodVertexX;
   Double_t        pi0_prodVertexY;
   Double_t        pi0_prodVertexZ;
   Double_t        pi0_prodVertexXErr;
   Double_t        pi0_prodVertexYErr;
   Double_t        pi0_prodVertexZErr;
   Double_t        pi0_chiProb;
   Double_t        pi0_flightTime;
   Double_t        pi0_flightDistance;
   Double_t        pi0_flightTimeErr;
   Double_t        pi0_flightDistanceErr;
   Double_t        pi0_d0Err;
   Double_t        pi0_z0Err;
   Double_t        pi0_phi0;
   Double_t        pi0_phi0Err;
   Double_t        pi0_phi;
   Double_t        pi0_cosTheta;
   Double_t        pi0_CMS_cosTheta;
   Double_t        pi0_CMS_p;
   Double_t        pi0_CMS_E;
   Double_t        pi0_daughterDiffOfPhi;
   Double_t        pi0_daughterAngle;
   Double_t        pi0_cosHelicityAngleMomentum;
   Double_t        gamma1_M;
   Double_t        gamma1_ErrM;
   Double_t        gamma1_SigM;
   Double_t        gamma1_InvM;
   Double_t        gamma1_px;
   Double_t        gamma1_py;
   Double_t        gamma1_pz;
   Double_t        gamma1_pt;
   Double_t        gamma1_p;
   Double_t        gamma1_E;
   Double_t        gamma1_CMS_cosTheta;
   Double_t        gamma1_CMS_p;
   Double_t        gamma1_CMS_E;
   Double_t        gamma1_thetaInCDCAcceptance;
   Double_t        gamma1_thetaInECLAcceptance;
   Double_t        gamma1_thetaInEECLAcceptance;
   Double_t        gamma1_thetaInBECLAcceptance;
   Double_t        gamma1_clusterPulseShapeDiscriminationMVA;
   Double_t        gamma1_clusterHasPulseShapeDiscrimination;
   Double_t        gamma1_clusterNumberOfHadronDigits;
   Double_t        gamma1_clusterDeltaLTemp;
   Double_t        gamma1_minC2TDist;
   Double_t        gamma1_nECLClusterTrackMatches;
   Double_t        gamma1_clusterZernikeMVA;
   Double_t        gamma1_clusterReg;
   Double_t        gamma1_clusterAbsZernikeMoment40;
   Double_t        gamma1_clusterAbsZernikeMoment51;
   Double_t        gamma1_clusterBelleQuality;
   Double_t        gamma1_clusterClusterID;
   Double_t        gamma1_clusterConnectedRegionID;
   Double_t        gamma1_clusterE1E9;
   Double_t        gamma1_clusterE9E21;
   Double_t        gamma1_clusterE9E25;
   Double_t        gamma1_clusterEoP;
   Double_t        gamma1_clusterErrorE;
   Double_t        gamma1_clusterErrorPhi;
   Double_t        gamma1_clusterErrorTheta;
   Double_t        gamma1_clusterErrorTiming;
   Double_t        gamma1_clusterHighestE;
   Double_t        gamma1_clusterHasFailedErrorTiming;
   Double_t        gamma1_clusterHasFailedTiming;
   Double_t        gamma1_clusterHasNPhotons;
   Double_t        gamma1_clusterHasNeutralHadron;
   Double_t        gamma1_clusterLAT;
   Double_t        gamma1_clusterNHits;
   Double_t        gamma1_clusterPhi;
   Double_t        gamma1_clusterR;
   Double_t        gamma1_clusterSecondMoment;
   Double_t        gamma1_clusterTheta;
   Double_t        gamma1_clusterTiming;
   Double_t        gamma1_clusterTrackMatch;
   Double_t        gamma1_goodBelleGamma;
   Double_t        gamma2_M;
   Double_t        gamma2_ErrM;
   Double_t        gamma2_SigM;
   Double_t        gamma2_InvM;
   Double_t        gamma2_px;
   Double_t        gamma2_py;
   Double_t        gamma2_pz;
   Double_t        gamma2_pt;
   Double_t        gamma2_p;
   Double_t        gamma2_E;
   Double_t        gamma2_CMS_cosTheta;
   Double_t        gamma2_CMS_p;
   Double_t        gamma2_CMS_E;
   Double_t        gamma2_thetaInCDCAcceptance;
   Double_t        gamma2_thetaInECLAcceptance;
   Double_t        gamma2_thetaInEECLAcceptance;
   Double_t        gamma2_thetaInBECLAcceptance;
   Double_t        gamma2_clusterPulseShapeDiscriminationMVA;
   Double_t        gamma2_clusterHasPulseShapeDiscrimination;
   Double_t        gamma2_clusterNumberOfHadronDigits;
   Double_t        gamma2_clusterDeltaLTemp;
   Double_t        gamma2_minC2TDist;
   Double_t        gamma2_nECLClusterTrackMatches;
   Double_t        gamma2_clusterZernikeMVA;
   Double_t        gamma2_clusterReg;
   Double_t        gamma2_clusterAbsZernikeMoment40;
   Double_t        gamma2_clusterAbsZernikeMoment51;
   Double_t        gamma2_clusterBelleQuality;
   Double_t        gamma2_clusterClusterID;
   Double_t        gamma2_clusterConnectedRegionID;
   Double_t        gamma2_clusterE1E9;
   Double_t        gamma2_clusterE9E21;
   Double_t        gamma2_clusterE9E25;
   Double_t        gamma2_clusterEoP;
   Double_t        gamma2_clusterErrorE;
   Double_t        gamma2_clusterErrorPhi;
   Double_t        gamma2_clusterErrorTheta;
   Double_t        gamma2_clusterErrorTiming;
   Double_t        gamma2_clusterHighestE;
   Double_t        gamma2_clusterHasFailedErrorTiming;
   Double_t        gamma2_clusterHasFailedTiming;
   Double_t        gamma2_clusterHasNPhotons;
   Double_t        gamma2_clusterHasNeutralHadron;
   Double_t        gamma2_clusterLAT;
   Double_t        gamma2_clusterNHits;
   Double_t        gamma2_clusterPhi;
   Double_t        gamma2_clusterR;
   Double_t        gamma2_clusterSecondMoment;
   Double_t        gamma2_clusterTheta;
   Double_t        gamma2_clusterTiming;
   Double_t        gamma2_clusterTrackMatch;
   Double_t        gamma2_goodBelleGamma;
   Double_t        gamma1_phi;
   Double_t        gamma1_cosTheta;
   Double_t        gamma2_phi;
   Double_t        gamma2_cosTheta;
   Double_t        mpippim;
   Double_t        mpippim2;
   Double_t        mpippi0;
   Double_t        mpippi02;
   Double_t        mpimpi0;
   Double_t        mpimpi02;
   Double_t        mpippi02_prefit;
   Double_t        mpimpi02_prefit;
   Double_t        mpippim2_prefit;
   Double_t        mpippi02_vfit;
   Double_t        mpimpi02_vfit;
   Double_t        mpippim2_vfit;
   Double_t        Dst_M_vfit;
   Double_t        delM_vfit;
   Double_t        D0_M_vfit;
   Double_t        Dst_chiProb_vfit;
   Double_t        Dst_M_prefit;
   Double_t        delM_prefit;
   Double_t        D0_M_prefit;
   Double_t        pi0_M_prefit;
   Double_t        rank_Dstp_mfit;
   Double_t        rank_Dstm_mfit;
   Double_t        rank_Dstp_vfit;
   Double_t        rank_Dstm_vfit;
   Double_t        rank_Dstp_prefit;
   Double_t        rank_Dstm_prefit;
   Double_t        rank_Dstp_mfit_noprefit;
   Double_t        rank_Dstm_mfit_noprefit;
   Double_t        rank_Dstp_vfit_noprefit;
   Double_t        rank_Dstm_vfit_noprefit;
   Double_t        rank_Dstp_mfit_newmw;
   Double_t        rank_Dstm_mfit_newmw;
   Double_t        rank_Dstp_vfit_newmw;
   Double_t        rank_Dstm_vfit_newmw;
   Double_t        rank_Dstp_mfit_noprefit_newmw;
   Double_t        rank_Dstm_mfit_noprefit_newmw;
   Double_t        rank_Dstp_vfit_noprefit_newmw;
   Double_t        rank_Dstm_vfit_noprefit_newmw;

   // List of branches
   TBranch        *b___experiment__;   //!
   TBranch        *b___run__;   //!
   TBranch        *b___event__;   //!
   TBranch        *b___production__;   //!
   TBranch        *b___candidate__;   //!
   TBranch        *b___ncandidates__;   //!
   TBranch        *b___weight__;   //!
   TBranch        *b_Dst_fitStatus;   //!
   TBranch        *b_delM;   //!
   TBranch        *b_delMErr;   //!
   TBranch        *b_Dst_M;   //!
   TBranch        *b_Dst_ErrM;   //!
   TBranch        *b_Dst_SigM;   //!
   TBranch        *b_Dst_InvM;   //!
   TBranch        *b_Dst_px;   //!
   TBranch        *b_Dst_py;   //!
   TBranch        *b_Dst_pz;   //!
   TBranch        *b_Dst_pt;   //!
   TBranch        *b_Dst_p;   //!
   TBranch        *b_Dst_E;   //!
   TBranch        *b_Dst_distance;   //!
   TBranch        *b_Dst_significanceOfDistance;   //!
   TBranch        *b_Dst_dx;   //!
   TBranch        *b_Dst_dy;   //!
   TBranch        *b_Dst_dz;   //!
   TBranch        *b_Dst_x;   //!
   TBranch        *b_Dst_y;   //!
   TBranch        *b_Dst_z;   //!
   TBranch        *b_Dst_x_uncertainty;   //!
   TBranch        *b_Dst_y_uncertainty;   //!
   TBranch        *b_Dst_z_uncertainty;   //!
   TBranch        *b_Dst_dr;   //!
   TBranch        *b_Dst_dphi;   //!
   TBranch        *b_Dst_dcosTheta;   //!
   TBranch        *b_Dst_prodVertexX;   //!
   TBranch        *b_Dst_prodVertexY;   //!
   TBranch        *b_Dst_prodVertexZ;   //!
   TBranch        *b_Dst_prodVertexXErr;   //!
   TBranch        *b_Dst_prodVertexYErr;   //!
   TBranch        *b_Dst_prodVertexZErr;   //!
   TBranch        *b_Dst_chiProb;   //!
   TBranch        *b_Dst_flightTime;   //!
   TBranch        *b_Dst_flightDistance;   //!
   TBranch        *b_Dst_flightTimeErr;   //!
   TBranch        *b_Dst_flightDistanceErr;   //!
   TBranch        *b_Dst_CMS_px;   //!
   TBranch        *b_Dst_CMS_py;   //!
   TBranch        *b_Dst_CMS_pz;   //!
   TBranch        *b_Dst_CMS_pt;   //!
   TBranch        *b_Dst_CMS_p;   //!
   TBranch        *b_Dst_CMS_E;   //!
   TBranch        *b_Dst_charge;   //!
   TBranch        *b_D0_M;   //!
   TBranch        *b_D0_ErrM;   //!
   TBranch        *b_D0_SigM;   //!
   TBranch        *b_D0_InvM;   //!
   TBranch        *b_D0_px;   //!
   TBranch        *b_D0_py;   //!
   TBranch        *b_D0_pz;   //!
   TBranch        *b_D0_pt;   //!
   TBranch        *b_D0_p;   //!
   TBranch        *b_D0_E;   //!
   TBranch        *b_D0_distance;   //!
   TBranch        *b_D0_significanceOfDistance;   //!
   TBranch        *b_D0_dx;   //!
   TBranch        *b_D0_dy;   //!
   TBranch        *b_D0_dz;   //!
   TBranch        *b_D0_x;   //!
   TBranch        *b_D0_y;   //!
   TBranch        *b_D0_z;   //!
   TBranch        *b_D0_x_uncertainty;   //!
   TBranch        *b_D0_y_uncertainty;   //!
   TBranch        *b_D0_z_uncertainty;   //!
   TBranch        *b_D0_dr;   //!
   TBranch        *b_D0_dphi;   //!
   TBranch        *b_D0_dcosTheta;   //!
   TBranch        *b_D0_prodVertexX;   //!
   TBranch        *b_D0_prodVertexY;   //!
   TBranch        *b_D0_prodVertexZ;   //!
   TBranch        *b_D0_prodVertexXErr;   //!
   TBranch        *b_D0_prodVertexYErr;   //!
   TBranch        *b_D0_prodVertexZErr;   //!
   TBranch        *b_D0_chiProb;   //!
   TBranch        *b_D0_flightTime;   //!
   TBranch        *b_D0_flightDistance;   //!
   TBranch        *b_D0_flightTimeErr;   //!
   TBranch        *b_D0_flightDistanceErr;   //!
   TBranch        *b_D0_CMS_cosTheta;   //!
   TBranch        *b_D0_CMS_p;   //!
   TBranch        *b_D0_CMS_E;   //!
   TBranch        *b_D0_charge;   //!
   TBranch        *b_D0_flightDistSig;   //!
   TBranch        *b_D0_flightTimeSig;   //!
   TBranch        *b_pip_M;   //!
   TBranch        *b_pip_ErrM;   //!
   TBranch        *b_pip_SigM;   //!
   TBranch        *b_pip_InvM;   //!
   TBranch        *b_pip_px;   //!
   TBranch        *b_pip_py;   //!
   TBranch        *b_pip_pz;   //!
   TBranch        *b_pip_pt;   //!
   TBranch        *b_pip_p;   //!
   TBranch        *b_pip_E;   //!
   TBranch        *b_pip_dr;   //!
   TBranch        *b_pip_dx;   //!
   TBranch        *b_pip_dy;   //!
   TBranch        *b_pip_dz;   //!
   TBranch        *b_pip_d0;   //!
   TBranch        *b_pip_z0;   //!
   TBranch        *b_pip_pValue;   //!
   TBranch        *b_pip_ndf;   //!
   TBranch        *b_pip_nCDCHits;   //!
   TBranch        *b_pip_nPXDHits;   //!
   TBranch        *b_pip_nSVDHits;   //!
   TBranch        *b_pip_nVXDHits;   //!
   TBranch        *b_pip_d0Err;   //!
   TBranch        *b_pip_z0Err;   //!
   TBranch        *b_pip_phi0;   //!
   TBranch        *b_pip_phi0Err;   //!
   TBranch        *b_pip_dphi;   //!
   TBranch        *b_pip_phi;   //!
   TBranch        *b_pip_cosTheta;   //!
   TBranch        *b_pip_CMS_cosTheta;   //!
   TBranch        *b_pip_CMS_p;   //!
   TBranch        *b_pip_CMS_E;   //!
   TBranch        *b_pip_thetaInCDCAcceptance;   //!
   TBranch        *b_pip_charge;   //!
   TBranch        *b_pip_pionID;   //!
   TBranch        *b_pip_pionpairID;   //!
   TBranch        *b_pip_pionID_CDC;   //!
   TBranch        *b_pip_pionpairID_CDC;   //!
   TBranch        *b_pip_pionID_TOP;   //!
   TBranch        *b_pip_pionpairID_TOP;   //!
   TBranch        *b_pip_pionID_ARICH;   //!
   TBranch        *b_pip_pionpairID_ARICH;   //!
   TBranch        *b_pip_pionID_CDC_TOP_ARICH;   //!
   TBranch        *b_pip_pionpairID_CDC_TOP_ARICH;   //!
   TBranch        *b_pim_M;   //!
   TBranch        *b_pim_ErrM;   //!
   TBranch        *b_pim_SigM;   //!
   TBranch        *b_pim_InvM;   //!
   TBranch        *b_pim_px;   //!
   TBranch        *b_pim_py;   //!
   TBranch        *b_pim_pz;   //!
   TBranch        *b_pim_pt;   //!
   TBranch        *b_pim_p;   //!
   TBranch        *b_pim_E;   //!
   TBranch        *b_pim_dr;   //!
   TBranch        *b_pim_dx;   //!
   TBranch        *b_pim_dy;   //!
   TBranch        *b_pim_dz;   //!
   TBranch        *b_pim_d0;   //!
   TBranch        *b_pim_z0;   //!
   TBranch        *b_pim_pValue;   //!
   TBranch        *b_pim_ndf;   //!
   TBranch        *b_pim_nCDCHits;   //!
   TBranch        *b_pim_nPXDHits;   //!
   TBranch        *b_pim_nSVDHits;   //!
   TBranch        *b_pim_nVXDHits;   //!
   TBranch        *b_pim_d0Err;   //!
   TBranch        *b_pim_z0Err;   //!
   TBranch        *b_pim_phi0;   //!
   TBranch        *b_pim_phi0Err;   //!
   TBranch        *b_pim_dphi;   //!
   TBranch        *b_pim_phi;   //!
   TBranch        *b_pim_cosTheta;   //!
   TBranch        *b_pim_CMS_cosTheta;   //!
   TBranch        *b_pim_CMS_p;   //!
   TBranch        *b_pim_CMS_E;   //!
   TBranch        *b_pim_thetaInCDCAcceptance;   //!
   TBranch        *b_pim_charge;   //!
   TBranch        *b_pim_pionID;   //!
   TBranch        *b_pim_pionpairID;   //!
   TBranch        *b_pim_pionID_CDC;   //!
   TBranch        *b_pim_pionpairID_CDC;   //!
   TBranch        *b_pim_pionID_TOP;   //!
   TBranch        *b_pim_pionpairID_TOP;   //!
   TBranch        *b_pim_pionID_ARICH;   //!
   TBranch        *b_pim_pionpairID_ARICH;   //!
   TBranch        *b_pim_pionID_CDC_TOP_ARICH;   //!
   TBranch        *b_pim_pionpairID_CDC_TOP_ARICH;   //!
   TBranch        *b_pis_M;   //!
   TBranch        *b_pis_ErrM;   //!
   TBranch        *b_pis_SigM;   //!
   TBranch        *b_pis_InvM;   //!
   TBranch        *b_pis_px;   //!
   TBranch        *b_pis_py;   //!
   TBranch        *b_pis_pz;   //!
   TBranch        *b_pis_pt;   //!
   TBranch        *b_pis_p;   //!
   TBranch        *b_pis_E;   //!
   TBranch        *b_pis_dr;   //!
   TBranch        *b_pis_dx;   //!
   TBranch        *b_pis_dy;   //!
   TBranch        *b_pis_dz;   //!
   TBranch        *b_pis_d0;   //!
   TBranch        *b_pis_z0;   //!
   TBranch        *b_pis_pValue;   //!
   TBranch        *b_pis_ndf;   //!
   TBranch        *b_pis_nCDCHits;   //!
   TBranch        *b_pis_nPXDHits;   //!
   TBranch        *b_pis_nSVDHits;   //!
   TBranch        *b_pis_nVXDHits;   //!
   TBranch        *b_pis_d0Err;   //!
   TBranch        *b_pis_z0Err;   //!
   TBranch        *b_pis_phi0;   //!
   TBranch        *b_pis_phi0Err;   //!
   TBranch        *b_pis_dphi;   //!
   TBranch        *b_pis_phi;   //!
   TBranch        *b_pis_cosTheta;   //!
   TBranch        *b_pis_CMS_cosTheta;   //!
   TBranch        *b_pis_CMS_p;   //!
   TBranch        *b_pis_CMS_E;   //!
   TBranch        *b_pis_thetaInCDCAcceptance;   //!
   TBranch        *b_pis_charge;   //!
   TBranch        *b_pis_pionID;   //!
   TBranch        *b_pis_pionpairID;   //!
   TBranch        *b_pis_pionID_CDC;   //!
   TBranch        *b_pis_pionpairID_CDC;   //!
   TBranch        *b_pis_pionID_TOP;   //!
   TBranch        *b_pis_pionpairID_TOP;   //!
   TBranch        *b_pis_pionID_ARICH;   //!
   TBranch        *b_pis_pionpairID_ARICH;   //!
   TBranch        *b_pis_pionID_CDC_TOP_ARICH;   //!
   TBranch        *b_pis_pionpairID_CDC_TOP_ARICH;   //!
   TBranch        *b_pi0_M;   //!
   TBranch        *b_pi0_ErrM;   //!
   TBranch        *b_pi0_SigM;   //!
   TBranch        *b_pi0_InvM;   //!
   TBranch        *b_pi0_px;   //!
   TBranch        *b_pi0_py;   //!
   TBranch        *b_pi0_pz;   //!
   TBranch        *b_pi0_pt;   //!
   TBranch        *b_pi0_p;   //!
   TBranch        *b_pi0_E;   //!
   TBranch        *b_pi0_distance;   //!
   TBranch        *b_pi0_significanceOfDistance;   //!
   TBranch        *b_pi0_dx;   //!
   TBranch        *b_pi0_dy;   //!
   TBranch        *b_pi0_dz;   //!
   TBranch        *b_pi0_x;   //!
   TBranch        *b_pi0_y;   //!
   TBranch        *b_pi0_z;   //!
   TBranch        *b_pi0_x_uncertainty;   //!
   TBranch        *b_pi0_y_uncertainty;   //!
   TBranch        *b_pi0_z_uncertainty;   //!
   TBranch        *b_pi0_dr;   //!
   TBranch        *b_pi0_dphi;   //!
   TBranch        *b_pi0_dcosTheta;   //!
   TBranch        *b_pi0_prodVertexX;   //!
   TBranch        *b_pi0_prodVertexY;   //!
   TBranch        *b_pi0_prodVertexZ;   //!
   TBranch        *b_pi0_prodVertexXErr;   //!
   TBranch        *b_pi0_prodVertexYErr;   //!
   TBranch        *b_pi0_prodVertexZErr;   //!
   TBranch        *b_pi0_chiProb;   //!
   TBranch        *b_pi0_flightTime;   //!
   TBranch        *b_pi0_flightDistance;   //!
   TBranch        *b_pi0_flightTimeErr;   //!
   TBranch        *b_pi0_flightDistanceErr;   //!
   TBranch        *b_pi0_d0Err;   //!
   TBranch        *b_pi0_z0Err;   //!
   TBranch        *b_pi0_phi0;   //!
   TBranch        *b_pi0_phi0Err;   //!
   TBranch        *b_pi0_phi;   //!
   TBranch        *b_pi0_cosTheta;   //!
   TBranch        *b_pi0_CMS_cosTheta;   //!
   TBranch        *b_pi0_CMS_p;   //!
   TBranch        *b_pi0_CMS_E;   //!
   TBranch        *b_pi0_daughterDiffOfPhi;   //!
   TBranch        *b_pi0_daughterAngle;   //!
   TBranch        *b_pi0_cosHelicityAngleMomentum;   //!
   TBranch        *b_gamma1_M;   //!
   TBranch        *b_gamma1_ErrM;   //!
   TBranch        *b_gamma1_SigM;   //!
   TBranch        *b_gamma1_InvM;   //!
   TBranch        *b_gamma1_px;   //!
   TBranch        *b_gamma1_py;   //!
   TBranch        *b_gamma1_pz;   //!
   TBranch        *b_gamma1_pt;   //!
   TBranch        *b_gamma1_p;   //!
   TBranch        *b_gamma1_E;   //!
   TBranch        *b_gamma1_CMS_cosTheta;   //!
   TBranch        *b_gamma1_CMS_p;   //!
   TBranch        *b_gamma1_CMS_E;   //!
   TBranch        *b_gamma1_thetaInCDCAcceptance;   //!
   TBranch        *b_gamma1_thetaInECLAcceptance;   //!
   TBranch        *b_gamma1_thetaInEECLAcceptance;   //!
   TBranch        *b_gamma1_thetaInBECLAcceptance;   //!
   TBranch        *b_gamma1_clusterPulseShapeDiscriminationMVA;   //!
   TBranch        *b_gamma1_clusterHasPulseShapeDiscrimination;   //!
   TBranch        *b_gamma1_clusterNumberOfHadronDigits;   //!
   TBranch        *b_gamma1_clusterDeltaLTemp;   //!
   TBranch        *b_gamma1_minC2TDist;   //!
   TBranch        *b_gamma1_nECLClusterTrackMatches;   //!
   TBranch        *b_gamma1_clusterZernikeMVA;   //!
   TBranch        *b_gamma1_clusterReg;   //!
   TBranch        *b_gamma1_clusterAbsZernikeMoment40;   //!
   TBranch        *b_gamma1_clusterAbsZernikeMoment51;   //!
   TBranch        *b_gamma1_clusterBelleQuality;   //!
   TBranch        *b_gamma1_clusterClusterID;   //!
   TBranch        *b_gamma1_clusterConnectedRegionID;   //!
   TBranch        *b_gamma1_clusterE1E9;   //!
   TBranch        *b_gamma1_clusterE9E21;   //!
   TBranch        *b_gamma1_clusterE9E25;   //!
   TBranch        *b_gamma1_clusterEoP;   //!
   TBranch        *b_gamma1_clusterErrorE;   //!
   TBranch        *b_gamma1_clusterErrorPhi;   //!
   TBranch        *b_gamma1_clusterErrorTheta;   //!
   TBranch        *b_gamma1_clusterErrorTiming;   //!
   TBranch        *b_gamma1_clusterHighestE;   //!
   TBranch        *b_gamma1_clusterHasFailedErrorTiming;   //!
   TBranch        *b_gamma1_clusterHasFailedTiming;   //!
   TBranch        *b_gamma1_clusterHasNPhotons;   //!
   TBranch        *b_gamma1_clusterHasNeutralHadron;   //!
   TBranch        *b_gamma1_clusterLAT;   //!
   TBranch        *b_gamma1_clusterNHits;   //!
   TBranch        *b_gamma1_clusterPhi;   //!
   TBranch        *b_gamma1_clusterR;   //!
   TBranch        *b_gamma1_clusterSecondMoment;   //!
   TBranch        *b_gamma1_clusterTheta;   //!
   TBranch        *b_gamma1_clusterTiming;   //!
   TBranch        *b_gamma1_clusterTrackMatch;   //!
   TBranch        *b_gamma1_goodBelleGamma;   //!
   TBranch        *b_gamma2_M;   //!
   TBranch        *b_gamma2_ErrM;   //!
   TBranch        *b_gamma2_SigM;   //!
   TBranch        *b_gamma2_InvM;   //!
   TBranch        *b_gamma2_px;   //!
   TBranch        *b_gamma2_py;   //!
   TBranch        *b_gamma2_pz;   //!
   TBranch        *b_gamma2_pt;   //!
   TBranch        *b_gamma2_p;   //!
   TBranch        *b_gamma2_E;   //!
   TBranch        *b_gamma2_CMS_cosTheta;   //!
   TBranch        *b_gamma2_CMS_p;   //!
   TBranch        *b_gamma2_CMS_E;   //!
   TBranch        *b_gamma2_thetaInCDCAcceptance;   //!
   TBranch        *b_gamma2_thetaInECLAcceptance;   //!
   TBranch        *b_gamma2_thetaInEECLAcceptance;   //!
   TBranch        *b_gamma2_thetaInBECLAcceptance;   //!
   TBranch        *b_gamma2_clusterPulseShapeDiscriminationMVA;   //!
   TBranch        *b_gamma2_clusterHasPulseShapeDiscrimination;   //!
   TBranch        *b_gamma2_clusterNumberOfHadronDigits;   //!
   TBranch        *b_gamma2_clusterDeltaLTemp;   //!
   TBranch        *b_gamma2_minC2TDist;   //!
   TBranch        *b_gamma2_nECLClusterTrackMatches;   //!
   TBranch        *b_gamma2_clusterZernikeMVA;   //!
   TBranch        *b_gamma2_clusterReg;   //!
   TBranch        *b_gamma2_clusterAbsZernikeMoment40;   //!
   TBranch        *b_gamma2_clusterAbsZernikeMoment51;   //!
   TBranch        *b_gamma2_clusterBelleQuality;   //!
   TBranch        *b_gamma2_clusterClusterID;   //!
   TBranch        *b_gamma2_clusterConnectedRegionID;   //!
   TBranch        *b_gamma2_clusterE1E9;   //!
   TBranch        *b_gamma2_clusterE9E21;   //!
   TBranch        *b_gamma2_clusterE9E25;   //!
   TBranch        *b_gamma2_clusterEoP;   //!
   TBranch        *b_gamma2_clusterErrorE;   //!
   TBranch        *b_gamma2_clusterErrorPhi;   //!
   TBranch        *b_gamma2_clusterErrorTheta;   //!
   TBranch        *b_gamma2_clusterErrorTiming;   //!
   TBranch        *b_gamma2_clusterHighestE;   //!
   TBranch        *b_gamma2_clusterHasFailedErrorTiming;   //!
   TBranch        *b_gamma2_clusterHasFailedTiming;   //!
   TBranch        *b_gamma2_clusterHasNPhotons;   //!
   TBranch        *b_gamma2_clusterHasNeutralHadron;   //!
   TBranch        *b_gamma2_clusterLAT;   //!
   TBranch        *b_gamma2_clusterNHits;   //!
   TBranch        *b_gamma2_clusterPhi;   //!
   TBranch        *b_gamma2_clusterR;   //!
   TBranch        *b_gamma2_clusterSecondMoment;   //!
   TBranch        *b_gamma2_clusterTheta;   //!
   TBranch        *b_gamma2_clusterTiming;   //!
   TBranch        *b_gamma2_clusterTrackMatch;   //!
   TBranch        *b_gamma2_goodBelleGamma;   //!
   TBranch        *b_gamma1_phi;   //!
   TBranch        *b_gamma1_cosTheta;   //!
   TBranch        *b_gamma2_phi;   //!
   TBranch        *b_gamma2_cosTheta;   //!
   TBranch        *b_mpippim;   //!
   TBranch        *b_mpippim2;   //!
   TBranch        *b_mpippi0;   //!
   TBranch        *b_mpippi02;   //!
   TBranch        *b_mpimpi0;   //!
   TBranch        *b_mpimpi02;   //!
   TBranch        *b_mpippi02_prefit;   //!
   TBranch        *b_mpimpi02_prefit;   //!
   TBranch        *b_mpippim2_prefit;   //!
   TBranch        *b_mpippi02_vfit;   //!
   TBranch        *b_mpimpi02_vfit;   //!
   TBranch        *b_mpippim2_vfit;   //!
   TBranch        *b_Dst_M_vfit;   //!
   TBranch        *b_delM_vfit;   //!
   TBranch        *b_D0_M_vfit;   //!
   TBranch        *b_Dst_chiProb_vfit;   //!
   TBranch        *b_Dst_M_prefit;   //!
   TBranch        *b_delM_prefit;   //!
   TBranch        *b_D0_M_prefit;   //!
   TBranch        *b_pi0_M_prefit;   //!
   TBranch        *b_rank_Dstp_mfit;   //!
   TBranch        *b_rank_Dstm_mfit;   //!
   TBranch        *b_rank_Dstp_vfit;   //!
   TBranch        *b_rank_Dstm_vfit;   //!
   TBranch        *b_rank_Dstp_prefit;   //!
   TBranch        *b_rank_Dstm_prefit;   //!
   TBranch        *b_rank_Dstp_mfit_noprefit;   //!
   TBranch        *b_rank_Dstm_mfit_noprefit;   //!
   TBranch        *b_rank_Dstp_vfit_noprefit;   //!
   TBranch        *b_rank_Dstm_vfit_noprefit;   //!
   TBranch        *b_rank_Dstp_mfit_newmw;   //!
   TBranch        *b_rank_Dstm_mfit_newmw;   //!
   TBranch        *b_rank_Dstp_vfit_newmw;   //!
   TBranch        *b_rank_Dstm_vfit_newmw;   //!
   TBranch        *b_rank_Dstp_mfit_noprefit_newmw;   //!
   TBranch        *b_rank_Dstm_mfit_noprefit_newmw;   //!
   TBranch        *b_rank_Dstp_vfit_noprefit_newmw;   //!
   TBranch        *b_rank_Dstm_vfit_noprefit_newmw;   //!

   Test(TTree *tree=0);
   virtual ~Test();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Test_cxx
Test::Test(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/mnt/data/EmmaAna/DstToD0pi_D0Topipipi0_NAv6_17240300_APSApril2021.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/mnt/data/EmmaAna/DstToD0pi_D0Topipipi0_NAv6_17240300_APSApril2021.root");
      }
      f->GetObject("Dst_recon",tree);

   }
   Init(tree);
}

Test::~Test()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Test::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Test::LoadTree(Long64_t entry)
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

void Test::Init(TTree *tree)
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

   fChain->SetBranchAddress("__experiment__", &__experiment__, &b___experiment__);
   fChain->SetBranchAddress("__run__", &__run__, &b___run__);
   fChain->SetBranchAddress("__event__", &__event__, &b___event__);
   fChain->SetBranchAddress("__production__", &__production__, &b___production__);
   fChain->SetBranchAddress("__candidate__", &__candidate__, &b___candidate__);
   fChain->SetBranchAddress("__ncandidates__", &__ncandidates__, &b___ncandidates__);
   fChain->SetBranchAddress("__weight__", &__weight__, &b___weight__);
   fChain->SetBranchAddress("Dst_fitStatus", &Dst_fitStatus, &b_Dst_fitStatus);
   fChain->SetBranchAddress("delM", &delM, &b_delM);
   fChain->SetBranchAddress("delMErr", &delMErr, &b_delMErr);
   fChain->SetBranchAddress("Dst_M", &Dst_M, &b_Dst_M);
   fChain->SetBranchAddress("Dst_ErrM", &Dst_ErrM, &b_Dst_ErrM);
   fChain->SetBranchAddress("Dst_SigM", &Dst_SigM, &b_Dst_SigM);
   fChain->SetBranchAddress("Dst_InvM", &Dst_InvM, &b_Dst_InvM);
   fChain->SetBranchAddress("Dst_px", &Dst_px, &b_Dst_px);
   fChain->SetBranchAddress("Dst_py", &Dst_py, &b_Dst_py);
   fChain->SetBranchAddress("Dst_pz", &Dst_pz, &b_Dst_pz);
   fChain->SetBranchAddress("Dst_pt", &Dst_pt, &b_Dst_pt);
   fChain->SetBranchAddress("Dst_p", &Dst_p, &b_Dst_p);
   fChain->SetBranchAddress("Dst_E", &Dst_E, &b_Dst_E);
   fChain->SetBranchAddress("Dst_distance", &Dst_distance, &b_Dst_distance);
   fChain->SetBranchAddress("Dst_significanceOfDistance", &Dst_significanceOfDistance, &b_Dst_significanceOfDistance);
   fChain->SetBranchAddress("Dst_dx", &Dst_dx, &b_Dst_dx);
   fChain->SetBranchAddress("Dst_dy", &Dst_dy, &b_Dst_dy);
   fChain->SetBranchAddress("Dst_dz", &Dst_dz, &b_Dst_dz);
   fChain->SetBranchAddress("Dst_x", &Dst_x, &b_Dst_x);
   fChain->SetBranchAddress("Dst_y", &Dst_y, &b_Dst_y);
   fChain->SetBranchAddress("Dst_z", &Dst_z, &b_Dst_z);
   fChain->SetBranchAddress("Dst_x_uncertainty", &Dst_x_uncertainty, &b_Dst_x_uncertainty);
   fChain->SetBranchAddress("Dst_y_uncertainty", &Dst_y_uncertainty, &b_Dst_y_uncertainty);
   fChain->SetBranchAddress("Dst_z_uncertainty", &Dst_z_uncertainty, &b_Dst_z_uncertainty);
   fChain->SetBranchAddress("Dst_dr", &Dst_dr, &b_Dst_dr);
   fChain->SetBranchAddress("Dst_dphi", &Dst_dphi, &b_Dst_dphi);
   fChain->SetBranchAddress("Dst_dcosTheta", &Dst_dcosTheta, &b_Dst_dcosTheta);
   fChain->SetBranchAddress("Dst_prodVertexX", &Dst_prodVertexX, &b_Dst_prodVertexX);
   fChain->SetBranchAddress("Dst_prodVertexY", &Dst_prodVertexY, &b_Dst_prodVertexY);
   fChain->SetBranchAddress("Dst_prodVertexZ", &Dst_prodVertexZ, &b_Dst_prodVertexZ);
   fChain->SetBranchAddress("Dst_prodVertexXErr", &Dst_prodVertexXErr, &b_Dst_prodVertexXErr);
   fChain->SetBranchAddress("Dst_prodVertexYErr", &Dst_prodVertexYErr, &b_Dst_prodVertexYErr);
   fChain->SetBranchAddress("Dst_prodVertexZErr", &Dst_prodVertexZErr, &b_Dst_prodVertexZErr);
   fChain->SetBranchAddress("Dst_chiProb", &Dst_chiProb, &b_Dst_chiProb);
   fChain->SetBranchAddress("Dst_flightTime", &Dst_flightTime, &b_Dst_flightTime);
   fChain->SetBranchAddress("Dst_flightDistance", &Dst_flightDistance, &b_Dst_flightDistance);
   fChain->SetBranchAddress("Dst_flightTimeErr", &Dst_flightTimeErr, &b_Dst_flightTimeErr);
   fChain->SetBranchAddress("Dst_flightDistanceErr", &Dst_flightDistanceErr, &b_Dst_flightDistanceErr);
   fChain->SetBranchAddress("Dst_CMS_px", &Dst_CMS_px, &b_Dst_CMS_px);
   fChain->SetBranchAddress("Dst_CMS_py", &Dst_CMS_py, &b_Dst_CMS_py);
   fChain->SetBranchAddress("Dst_CMS_pz", &Dst_CMS_pz, &b_Dst_CMS_pz);
   fChain->SetBranchAddress("Dst_CMS_pt", &Dst_CMS_pt, &b_Dst_CMS_pt);
   fChain->SetBranchAddress("Dst_CMS_p", &Dst_CMS_p, &b_Dst_CMS_p);
   fChain->SetBranchAddress("Dst_CMS_E", &Dst_CMS_E, &b_Dst_CMS_E);
   fChain->SetBranchAddress("Dst_charge", &Dst_charge, &b_Dst_charge);
   fChain->SetBranchAddress("D0_M", &D0_M, &b_D0_M);
   fChain->SetBranchAddress("D0_ErrM", &D0_ErrM, &b_D0_ErrM);
   fChain->SetBranchAddress("D0_SigM", &D0_SigM, &b_D0_SigM);
   fChain->SetBranchAddress("D0_InvM", &D0_InvM, &b_D0_InvM);
   fChain->SetBranchAddress("D0_px", &D0_px, &b_D0_px);
   fChain->SetBranchAddress("D0_py", &D0_py, &b_D0_py);
   fChain->SetBranchAddress("D0_pz", &D0_pz, &b_D0_pz);
   fChain->SetBranchAddress("D0_pt", &D0_pt, &b_D0_pt);
   fChain->SetBranchAddress("D0_p", &D0_p, &b_D0_p);
   fChain->SetBranchAddress("D0_E", &D0_E, &b_D0_E);
   fChain->SetBranchAddress("D0_distance", &D0_distance, &b_D0_distance);
   fChain->SetBranchAddress("D0_significanceOfDistance", &D0_significanceOfDistance, &b_D0_significanceOfDistance);
   fChain->SetBranchAddress("D0_dx", &D0_dx, &b_D0_dx);
   fChain->SetBranchAddress("D0_dy", &D0_dy, &b_D0_dy);
   fChain->SetBranchAddress("D0_dz", &D0_dz, &b_D0_dz);
   fChain->SetBranchAddress("D0_x", &D0_x, &b_D0_x);
   fChain->SetBranchAddress("D0_y", &D0_y, &b_D0_y);
   fChain->SetBranchAddress("D0_z", &D0_z, &b_D0_z);
   fChain->SetBranchAddress("D0_x_uncertainty", &D0_x_uncertainty, &b_D0_x_uncertainty);
   fChain->SetBranchAddress("D0_y_uncertainty", &D0_y_uncertainty, &b_D0_y_uncertainty);
   fChain->SetBranchAddress("D0_z_uncertainty", &D0_z_uncertainty, &b_D0_z_uncertainty);
   fChain->SetBranchAddress("D0_dr", &D0_dr, &b_D0_dr);
   fChain->SetBranchAddress("D0_dphi", &D0_dphi, &b_D0_dphi);
   fChain->SetBranchAddress("D0_dcosTheta", &D0_dcosTheta, &b_D0_dcosTheta);
   fChain->SetBranchAddress("D0_prodVertexX", &D0_prodVertexX, &b_D0_prodVertexX);
   fChain->SetBranchAddress("D0_prodVertexY", &D0_prodVertexY, &b_D0_prodVertexY);
   fChain->SetBranchAddress("D0_prodVertexZ", &D0_prodVertexZ, &b_D0_prodVertexZ);
   fChain->SetBranchAddress("D0_prodVertexXErr", &D0_prodVertexXErr, &b_D0_prodVertexXErr);
   fChain->SetBranchAddress("D0_prodVertexYErr", &D0_prodVertexYErr, &b_D0_prodVertexYErr);
   fChain->SetBranchAddress("D0_prodVertexZErr", &D0_prodVertexZErr, &b_D0_prodVertexZErr);
   fChain->SetBranchAddress("D0_chiProb", &D0_chiProb, &b_D0_chiProb);
   fChain->SetBranchAddress("D0_flightTime", &D0_flightTime, &b_D0_flightTime);
   fChain->SetBranchAddress("D0_flightDistance", &D0_flightDistance, &b_D0_flightDistance);
   fChain->SetBranchAddress("D0_flightTimeErr", &D0_flightTimeErr, &b_D0_flightTimeErr);
   fChain->SetBranchAddress("D0_flightDistanceErr", &D0_flightDistanceErr, &b_D0_flightDistanceErr);
   fChain->SetBranchAddress("D0_CMS_cosTheta", &D0_CMS_cosTheta, &b_D0_CMS_cosTheta);
   fChain->SetBranchAddress("D0_CMS_p", &D0_CMS_p, &b_D0_CMS_p);
   fChain->SetBranchAddress("D0_CMS_E", &D0_CMS_E, &b_D0_CMS_E);
   fChain->SetBranchAddress("D0_charge", &D0_charge, &b_D0_charge);
   fChain->SetBranchAddress("D0_flightDistSig", &D0_flightDistSig, &b_D0_flightDistSig);
   fChain->SetBranchAddress("D0_flightTimeSig", &D0_flightTimeSig, &b_D0_flightTimeSig);
   fChain->SetBranchAddress("pip_M", &pip_M, &b_pip_M);
   fChain->SetBranchAddress("pip_ErrM", &pip_ErrM, &b_pip_ErrM);
   fChain->SetBranchAddress("pip_SigM", &pip_SigM, &b_pip_SigM);
   fChain->SetBranchAddress("pip_InvM", &pip_InvM, &b_pip_InvM);
   fChain->SetBranchAddress("pip_px", &pip_px, &b_pip_px);
   fChain->SetBranchAddress("pip_py", &pip_py, &b_pip_py);
   fChain->SetBranchAddress("pip_pz", &pip_pz, &b_pip_pz);
   fChain->SetBranchAddress("pip_pt", &pip_pt, &b_pip_pt);
   fChain->SetBranchAddress("pip_p", &pip_p, &b_pip_p);
   fChain->SetBranchAddress("pip_E", &pip_E, &b_pip_E);
   fChain->SetBranchAddress("pip_dr", &pip_dr, &b_pip_dr);
   fChain->SetBranchAddress("pip_dx", &pip_dx, &b_pip_dx);
   fChain->SetBranchAddress("pip_dy", &pip_dy, &b_pip_dy);
   fChain->SetBranchAddress("pip_dz", &pip_dz, &b_pip_dz);
   fChain->SetBranchAddress("pip_d0", &pip_d0, &b_pip_d0);
   fChain->SetBranchAddress("pip_z0", &pip_z0, &b_pip_z0);
   fChain->SetBranchAddress("pip_pValue", &pip_pValue, &b_pip_pValue);
   fChain->SetBranchAddress("pip_ndf", &pip_ndf, &b_pip_ndf);
   fChain->SetBranchAddress("pip_nCDCHits", &pip_nCDCHits, &b_pip_nCDCHits);
   fChain->SetBranchAddress("pip_nPXDHits", &pip_nPXDHits, &b_pip_nPXDHits);
   fChain->SetBranchAddress("pip_nSVDHits", &pip_nSVDHits, &b_pip_nSVDHits);
   fChain->SetBranchAddress("pip_nVXDHits", &pip_nVXDHits, &b_pip_nVXDHits);
   fChain->SetBranchAddress("pip_d0Err", &pip_d0Err, &b_pip_d0Err);
   fChain->SetBranchAddress("pip_z0Err", &pip_z0Err, &b_pip_z0Err);
   fChain->SetBranchAddress("pip_phi0", &pip_phi0, &b_pip_phi0);
   fChain->SetBranchAddress("pip_phi0Err", &pip_phi0Err, &b_pip_phi0Err);
   fChain->SetBranchAddress("pip_dphi", &pip_dphi, &b_pip_dphi);
   fChain->SetBranchAddress("pip_phi", &pip_phi, &b_pip_phi);
   fChain->SetBranchAddress("pip_cosTheta", &pip_cosTheta, &b_pip_cosTheta);
   fChain->SetBranchAddress("pip_CMS_cosTheta", &pip_CMS_cosTheta, &b_pip_CMS_cosTheta);
   fChain->SetBranchAddress("pip_CMS_p", &pip_CMS_p, &b_pip_CMS_p);
   fChain->SetBranchAddress("pip_CMS_E", &pip_CMS_E, &b_pip_CMS_E);
   fChain->SetBranchAddress("pip_thetaInCDCAcceptance", &pip_thetaInCDCAcceptance, &b_pip_thetaInCDCAcceptance);
   fChain->SetBranchAddress("pip_charge", &pip_charge, &b_pip_charge);
   fChain->SetBranchAddress("pip_pionID", &pip_pionID, &b_pip_pionID);
   fChain->SetBranchAddress("pip_pionpairID", &pip_pionpairID, &b_pip_pionpairID);
   fChain->SetBranchAddress("pip_pionID_CDC", &pip_pionID_CDC, &b_pip_pionID_CDC);
   fChain->SetBranchAddress("pip_pionpairID_CDC", &pip_pionpairID_CDC, &b_pip_pionpairID_CDC);
   fChain->SetBranchAddress("pip_pionID_TOP", &pip_pionID_TOP, &b_pip_pionID_TOP);
   fChain->SetBranchAddress("pip_pionpairID_TOP", &pip_pionpairID_TOP, &b_pip_pionpairID_TOP);
   fChain->SetBranchAddress("pip_pionID_ARICH", &pip_pionID_ARICH, &b_pip_pionID_ARICH);
   fChain->SetBranchAddress("pip_pionpairID_ARICH", &pip_pionpairID_ARICH, &b_pip_pionpairID_ARICH);
   fChain->SetBranchAddress("pip_pionID_CDC_TOP_ARICH", &pip_pionID_CDC_TOP_ARICH, &b_pip_pionID_CDC_TOP_ARICH);
   fChain->SetBranchAddress("pip_pionpairID_CDC_TOP_ARICH", &pip_pionpairID_CDC_TOP_ARICH, &b_pip_pionpairID_CDC_TOP_ARICH);
   fChain->SetBranchAddress("pim_M", &pim_M, &b_pim_M);
   fChain->SetBranchAddress("pim_ErrM", &pim_ErrM, &b_pim_ErrM);
   fChain->SetBranchAddress("pim_SigM", &pim_SigM, &b_pim_SigM);
   fChain->SetBranchAddress("pim_InvM", &pim_InvM, &b_pim_InvM);
   fChain->SetBranchAddress("pim_px", &pim_px, &b_pim_px);
   fChain->SetBranchAddress("pim_py", &pim_py, &b_pim_py);
   fChain->SetBranchAddress("pim_pz", &pim_pz, &b_pim_pz);
   fChain->SetBranchAddress("pim_pt", &pim_pt, &b_pim_pt);
   fChain->SetBranchAddress("pim_p", &pim_p, &b_pim_p);
   fChain->SetBranchAddress("pim_E", &pim_E, &b_pim_E);
   fChain->SetBranchAddress("pim_dr", &pim_dr, &b_pim_dr);
   fChain->SetBranchAddress("pim_dx", &pim_dx, &b_pim_dx);
   fChain->SetBranchAddress("pim_dy", &pim_dy, &b_pim_dy);
   fChain->SetBranchAddress("pim_dz", &pim_dz, &b_pim_dz);
   fChain->SetBranchAddress("pim_d0", &pim_d0, &b_pim_d0);
   fChain->SetBranchAddress("pim_z0", &pim_z0, &b_pim_z0);
   fChain->SetBranchAddress("pim_pValue", &pim_pValue, &b_pim_pValue);
   fChain->SetBranchAddress("pim_ndf", &pim_ndf, &b_pim_ndf);
   fChain->SetBranchAddress("pim_nCDCHits", &pim_nCDCHits, &b_pim_nCDCHits);
   fChain->SetBranchAddress("pim_nPXDHits", &pim_nPXDHits, &b_pim_nPXDHits);
   fChain->SetBranchAddress("pim_nSVDHits", &pim_nSVDHits, &b_pim_nSVDHits);
   fChain->SetBranchAddress("pim_nVXDHits", &pim_nVXDHits, &b_pim_nVXDHits);
   fChain->SetBranchAddress("pim_d0Err", &pim_d0Err, &b_pim_d0Err);
   fChain->SetBranchAddress("pim_z0Err", &pim_z0Err, &b_pim_z0Err);
   fChain->SetBranchAddress("pim_phi0", &pim_phi0, &b_pim_phi0);
   fChain->SetBranchAddress("pim_phi0Err", &pim_phi0Err, &b_pim_phi0Err);
   fChain->SetBranchAddress("pim_dphi", &pim_dphi, &b_pim_dphi);
   fChain->SetBranchAddress("pim_phi", &pim_phi, &b_pim_phi);
   fChain->SetBranchAddress("pim_cosTheta", &pim_cosTheta, &b_pim_cosTheta);
   fChain->SetBranchAddress("pim_CMS_cosTheta", &pim_CMS_cosTheta, &b_pim_CMS_cosTheta);
   fChain->SetBranchAddress("pim_CMS_p", &pim_CMS_p, &b_pim_CMS_p);
   fChain->SetBranchAddress("pim_CMS_E", &pim_CMS_E, &b_pim_CMS_E);
   fChain->SetBranchAddress("pim_thetaInCDCAcceptance", &pim_thetaInCDCAcceptance, &b_pim_thetaInCDCAcceptance);
   fChain->SetBranchAddress("pim_charge", &pim_charge, &b_pim_charge);
   fChain->SetBranchAddress("pim_pionID", &pim_pionID, &b_pim_pionID);
   fChain->SetBranchAddress("pim_pionpairID", &pim_pionpairID, &b_pim_pionpairID);
   fChain->SetBranchAddress("pim_pionID_CDC", &pim_pionID_CDC, &b_pim_pionID_CDC);
   fChain->SetBranchAddress("pim_pionpairID_CDC", &pim_pionpairID_CDC, &b_pim_pionpairID_CDC);
   fChain->SetBranchAddress("pim_pionID_TOP", &pim_pionID_TOP, &b_pim_pionID_TOP);
   fChain->SetBranchAddress("pim_pionpairID_TOP", &pim_pionpairID_TOP, &b_pim_pionpairID_TOP);
   fChain->SetBranchAddress("pim_pionID_ARICH", &pim_pionID_ARICH, &b_pim_pionID_ARICH);
   fChain->SetBranchAddress("pim_pionpairID_ARICH", &pim_pionpairID_ARICH, &b_pim_pionpairID_ARICH);
   fChain->SetBranchAddress("pim_pionID_CDC_TOP_ARICH", &pim_pionID_CDC_TOP_ARICH, &b_pim_pionID_CDC_TOP_ARICH);
   fChain->SetBranchAddress("pim_pionpairID_CDC_TOP_ARICH", &pim_pionpairID_CDC_TOP_ARICH, &b_pim_pionpairID_CDC_TOP_ARICH);
   fChain->SetBranchAddress("pis_M", &pis_M, &b_pis_M);
   fChain->SetBranchAddress("pis_ErrM", &pis_ErrM, &b_pis_ErrM);
   fChain->SetBranchAddress("pis_SigM", &pis_SigM, &b_pis_SigM);
   fChain->SetBranchAddress("pis_InvM", &pis_InvM, &b_pis_InvM);
   fChain->SetBranchAddress("pis_px", &pis_px, &b_pis_px);
   fChain->SetBranchAddress("pis_py", &pis_py, &b_pis_py);
   fChain->SetBranchAddress("pis_pz", &pis_pz, &b_pis_pz);
   fChain->SetBranchAddress("pis_pt", &pis_pt, &b_pis_pt);
   fChain->SetBranchAddress("pis_p", &pis_p, &b_pis_p);
   fChain->SetBranchAddress("pis_E", &pis_E, &b_pis_E);
   fChain->SetBranchAddress("pis_dr", &pis_dr, &b_pis_dr);
   fChain->SetBranchAddress("pis_dx", &pis_dx, &b_pis_dx);
   fChain->SetBranchAddress("pis_dy", &pis_dy, &b_pis_dy);
   fChain->SetBranchAddress("pis_dz", &pis_dz, &b_pis_dz);
   fChain->SetBranchAddress("pis_d0", &pis_d0, &b_pis_d0);
   fChain->SetBranchAddress("pis_z0", &pis_z0, &b_pis_z0);
   fChain->SetBranchAddress("pis_pValue", &pis_pValue, &b_pis_pValue);
   fChain->SetBranchAddress("pis_ndf", &pis_ndf, &b_pis_ndf);
   fChain->SetBranchAddress("pis_nCDCHits", &pis_nCDCHits, &b_pis_nCDCHits);
   fChain->SetBranchAddress("pis_nPXDHits", &pis_nPXDHits, &b_pis_nPXDHits);
   fChain->SetBranchAddress("pis_nSVDHits", &pis_nSVDHits, &b_pis_nSVDHits);
   fChain->SetBranchAddress("pis_nVXDHits", &pis_nVXDHits, &b_pis_nVXDHits);
   fChain->SetBranchAddress("pis_d0Err", &pis_d0Err, &b_pis_d0Err);
   fChain->SetBranchAddress("pis_z0Err", &pis_z0Err, &b_pis_z0Err);
   fChain->SetBranchAddress("pis_phi0", &pis_phi0, &b_pis_phi0);
   fChain->SetBranchAddress("pis_phi0Err", &pis_phi0Err, &b_pis_phi0Err);
   fChain->SetBranchAddress("pis_dphi", &pis_dphi, &b_pis_dphi);
   fChain->SetBranchAddress("pis_phi", &pis_phi, &b_pis_phi);
   fChain->SetBranchAddress("pis_cosTheta", &pis_cosTheta, &b_pis_cosTheta);
   fChain->SetBranchAddress("pis_CMS_cosTheta", &pis_CMS_cosTheta, &b_pis_CMS_cosTheta);
   fChain->SetBranchAddress("pis_CMS_p", &pis_CMS_p, &b_pis_CMS_p);
   fChain->SetBranchAddress("pis_CMS_E", &pis_CMS_E, &b_pis_CMS_E);
   fChain->SetBranchAddress("pis_thetaInCDCAcceptance", &pis_thetaInCDCAcceptance, &b_pis_thetaInCDCAcceptance);
   fChain->SetBranchAddress("pis_charge", &pis_charge, &b_pis_charge);
   fChain->SetBranchAddress("pis_pionID", &pis_pionID, &b_pis_pionID);
   fChain->SetBranchAddress("pis_pionpairID", &pis_pionpairID, &b_pis_pionpairID);
   fChain->SetBranchAddress("pis_pionID_CDC", &pis_pionID_CDC, &b_pis_pionID_CDC);
   fChain->SetBranchAddress("pis_pionpairID_CDC", &pis_pionpairID_CDC, &b_pis_pionpairID_CDC);
   fChain->SetBranchAddress("pis_pionID_TOP", &pis_pionID_TOP, &b_pis_pionID_TOP);
   fChain->SetBranchAddress("pis_pionpairID_TOP", &pis_pionpairID_TOP, &b_pis_pionpairID_TOP);
   fChain->SetBranchAddress("pis_pionID_ARICH", &pis_pionID_ARICH, &b_pis_pionID_ARICH);
   fChain->SetBranchAddress("pis_pionpairID_ARICH", &pis_pionpairID_ARICH, &b_pis_pionpairID_ARICH);
   fChain->SetBranchAddress("pis_pionID_CDC_TOP_ARICH", &pis_pionID_CDC_TOP_ARICH, &b_pis_pionID_CDC_TOP_ARICH);
   fChain->SetBranchAddress("pis_pionpairID_CDC_TOP_ARICH", &pis_pionpairID_CDC_TOP_ARICH, &b_pis_pionpairID_CDC_TOP_ARICH);
   fChain->SetBranchAddress("pi0_M", &pi0_M, &b_pi0_M);
   fChain->SetBranchAddress("pi0_ErrM", &pi0_ErrM, &b_pi0_ErrM);
   fChain->SetBranchAddress("pi0_SigM", &pi0_SigM, &b_pi0_SigM);
   fChain->SetBranchAddress("pi0_InvM", &pi0_InvM, &b_pi0_InvM);
   fChain->SetBranchAddress("pi0_px", &pi0_px, &b_pi0_px);
   fChain->SetBranchAddress("pi0_py", &pi0_py, &b_pi0_py);
   fChain->SetBranchAddress("pi0_pz", &pi0_pz, &b_pi0_pz);
   fChain->SetBranchAddress("pi0_pt", &pi0_pt, &b_pi0_pt);
   fChain->SetBranchAddress("pi0_p", &pi0_p, &b_pi0_p);
   fChain->SetBranchAddress("pi0_E", &pi0_E, &b_pi0_E);
   fChain->SetBranchAddress("pi0_distance", &pi0_distance, &b_pi0_distance);
   fChain->SetBranchAddress("pi0_significanceOfDistance", &pi0_significanceOfDistance, &b_pi0_significanceOfDistance);
   fChain->SetBranchAddress("pi0_dx", &pi0_dx, &b_pi0_dx);
   fChain->SetBranchAddress("pi0_dy", &pi0_dy, &b_pi0_dy);
   fChain->SetBranchAddress("pi0_dz", &pi0_dz, &b_pi0_dz);
   fChain->SetBranchAddress("pi0_x", &pi0_x, &b_pi0_x);
   fChain->SetBranchAddress("pi0_y", &pi0_y, &b_pi0_y);
   fChain->SetBranchAddress("pi0_z", &pi0_z, &b_pi0_z);
   fChain->SetBranchAddress("pi0_x_uncertainty", &pi0_x_uncertainty, &b_pi0_x_uncertainty);
   fChain->SetBranchAddress("pi0_y_uncertainty", &pi0_y_uncertainty, &b_pi0_y_uncertainty);
   fChain->SetBranchAddress("pi0_z_uncertainty", &pi0_z_uncertainty, &b_pi0_z_uncertainty);
   fChain->SetBranchAddress("pi0_dr", &pi0_dr, &b_pi0_dr);
   fChain->SetBranchAddress("pi0_dphi", &pi0_dphi, &b_pi0_dphi);
   fChain->SetBranchAddress("pi0_dcosTheta", &pi0_dcosTheta, &b_pi0_dcosTheta);
   fChain->SetBranchAddress("pi0_prodVertexX", &pi0_prodVertexX, &b_pi0_prodVertexX);
   fChain->SetBranchAddress("pi0_prodVertexY", &pi0_prodVertexY, &b_pi0_prodVertexY);
   fChain->SetBranchAddress("pi0_prodVertexZ", &pi0_prodVertexZ, &b_pi0_prodVertexZ);
   fChain->SetBranchAddress("pi0_prodVertexXErr", &pi0_prodVertexXErr, &b_pi0_prodVertexXErr);
   fChain->SetBranchAddress("pi0_prodVertexYErr", &pi0_prodVertexYErr, &b_pi0_prodVertexYErr);
   fChain->SetBranchAddress("pi0_prodVertexZErr", &pi0_prodVertexZErr, &b_pi0_prodVertexZErr);
   fChain->SetBranchAddress("pi0_chiProb", &pi0_chiProb, &b_pi0_chiProb);
   fChain->SetBranchAddress("pi0_flightTime", &pi0_flightTime, &b_pi0_flightTime);
   fChain->SetBranchAddress("pi0_flightDistance", &pi0_flightDistance, &b_pi0_flightDistance);
   fChain->SetBranchAddress("pi0_flightTimeErr", &pi0_flightTimeErr, &b_pi0_flightTimeErr);
   fChain->SetBranchAddress("pi0_flightDistanceErr", &pi0_flightDistanceErr, &b_pi0_flightDistanceErr);
   fChain->SetBranchAddress("pi0_d0Err", &pi0_d0Err, &b_pi0_d0Err);
   fChain->SetBranchAddress("pi0_z0Err", &pi0_z0Err, &b_pi0_z0Err);
   fChain->SetBranchAddress("pi0_phi0", &pi0_phi0, &b_pi0_phi0);
   fChain->SetBranchAddress("pi0_phi0Err", &pi0_phi0Err, &b_pi0_phi0Err);
//    fChain->SetBranchAddress("pi0_dphi", &pi0_dphi, &b_pi0_dphi);
   fChain->SetBranchAddress("pi0_phi", &pi0_phi, &b_pi0_phi);
   fChain->SetBranchAddress("pi0_cosTheta", &pi0_cosTheta, &b_pi0_cosTheta);
   fChain->SetBranchAddress("pi0_CMS_cosTheta", &pi0_CMS_cosTheta, &b_pi0_CMS_cosTheta);
   fChain->SetBranchAddress("pi0_CMS_p", &pi0_CMS_p, &b_pi0_CMS_p);
   fChain->SetBranchAddress("pi0_CMS_E", &pi0_CMS_E, &b_pi0_CMS_E);
   fChain->SetBranchAddress("pi0_daughterDiffOfPhi", &pi0_daughterDiffOfPhi, &b_pi0_daughterDiffOfPhi);
   fChain->SetBranchAddress("pi0_daughterAngle", &pi0_daughterAngle, &b_pi0_daughterAngle);
   fChain->SetBranchAddress("pi0_cosHelicityAngleMomentum", &pi0_cosHelicityAngleMomentum, &b_pi0_cosHelicityAngleMomentum);
   fChain->SetBranchAddress("gamma1_M", &gamma1_M, &b_gamma1_M);
   fChain->SetBranchAddress("gamma1_ErrM", &gamma1_ErrM, &b_gamma1_ErrM);
   fChain->SetBranchAddress("gamma1_SigM", &gamma1_SigM, &b_gamma1_SigM);
   fChain->SetBranchAddress("gamma1_InvM", &gamma1_InvM, &b_gamma1_InvM);
   fChain->SetBranchAddress("gamma1_px", &gamma1_px, &b_gamma1_px);
   fChain->SetBranchAddress("gamma1_py", &gamma1_py, &b_gamma1_py);
   fChain->SetBranchAddress("gamma1_pz", &gamma1_pz, &b_gamma1_pz);
   fChain->SetBranchAddress("gamma1_pt", &gamma1_pt, &b_gamma1_pt);
   fChain->SetBranchAddress("gamma1_p", &gamma1_p, &b_gamma1_p);
   fChain->SetBranchAddress("gamma1_E", &gamma1_E, &b_gamma1_E);
   fChain->SetBranchAddress("gamma1_CMS_cosTheta", &gamma1_CMS_cosTheta, &b_gamma1_CMS_cosTheta);
   fChain->SetBranchAddress("gamma1_CMS_p", &gamma1_CMS_p, &b_gamma1_CMS_p);
   fChain->SetBranchAddress("gamma1_CMS_E", &gamma1_CMS_E, &b_gamma1_CMS_E);
   fChain->SetBranchAddress("gamma1_thetaInCDCAcceptance", &gamma1_thetaInCDCAcceptance, &b_gamma1_thetaInCDCAcceptance);
   fChain->SetBranchAddress("gamma1_thetaInECLAcceptance", &gamma1_thetaInECLAcceptance, &b_gamma1_thetaInECLAcceptance);
   fChain->SetBranchAddress("gamma1_thetaInEECLAcceptance", &gamma1_thetaInEECLAcceptance, &b_gamma1_thetaInEECLAcceptance);
   fChain->SetBranchAddress("gamma1_thetaInBECLAcceptance", &gamma1_thetaInBECLAcceptance, &b_gamma1_thetaInBECLAcceptance);
   fChain->SetBranchAddress("gamma1_clusterPulseShapeDiscriminationMVA", &gamma1_clusterPulseShapeDiscriminationMVA, &b_gamma1_clusterPulseShapeDiscriminationMVA);
   fChain->SetBranchAddress("gamma1_clusterHasPulseShapeDiscrimination", &gamma1_clusterHasPulseShapeDiscrimination, &b_gamma1_clusterHasPulseShapeDiscrimination);
   fChain->SetBranchAddress("gamma1_clusterNumberOfHadronDigits", &gamma1_clusterNumberOfHadronDigits, &b_gamma1_clusterNumberOfHadronDigits);
   fChain->SetBranchAddress("gamma1_clusterDeltaLTemp", &gamma1_clusterDeltaLTemp, &b_gamma1_clusterDeltaLTemp);
   fChain->SetBranchAddress("gamma1_minC2TDist", &gamma1_minC2TDist, &b_gamma1_minC2TDist);
   fChain->SetBranchAddress("gamma1_nECLClusterTrackMatches", &gamma1_nECLClusterTrackMatches, &b_gamma1_nECLClusterTrackMatches);
   fChain->SetBranchAddress("gamma1_clusterZernikeMVA", &gamma1_clusterZernikeMVA, &b_gamma1_clusterZernikeMVA);
   fChain->SetBranchAddress("gamma1_clusterReg", &gamma1_clusterReg, &b_gamma1_clusterReg);
   fChain->SetBranchAddress("gamma1_clusterAbsZernikeMoment40", &gamma1_clusterAbsZernikeMoment40, &b_gamma1_clusterAbsZernikeMoment40);
   fChain->SetBranchAddress("gamma1_clusterAbsZernikeMoment51", &gamma1_clusterAbsZernikeMoment51, &b_gamma1_clusterAbsZernikeMoment51);
   fChain->SetBranchAddress("gamma1_clusterBelleQuality", &gamma1_clusterBelleQuality, &b_gamma1_clusterBelleQuality);
   fChain->SetBranchAddress("gamma1_clusterClusterID", &gamma1_clusterClusterID, &b_gamma1_clusterClusterID);
   fChain->SetBranchAddress("gamma1_clusterConnectedRegionID", &gamma1_clusterConnectedRegionID, &b_gamma1_clusterConnectedRegionID);
   fChain->SetBranchAddress("gamma1_clusterE1E9", &gamma1_clusterE1E9, &b_gamma1_clusterE1E9);
   fChain->SetBranchAddress("gamma1_clusterE9E21", &gamma1_clusterE9E21, &b_gamma1_clusterE9E21);
   fChain->SetBranchAddress("gamma1_clusterE9E25", &gamma1_clusterE9E25, &b_gamma1_clusterE9E25);
   fChain->SetBranchAddress("gamma1_clusterEoP", &gamma1_clusterEoP, &b_gamma1_clusterEoP);
   fChain->SetBranchAddress("gamma1_clusterErrorE", &gamma1_clusterErrorE, &b_gamma1_clusterErrorE);
   fChain->SetBranchAddress("gamma1_clusterErrorPhi", &gamma1_clusterErrorPhi, &b_gamma1_clusterErrorPhi);
   fChain->SetBranchAddress("gamma1_clusterErrorTheta", &gamma1_clusterErrorTheta, &b_gamma1_clusterErrorTheta);
   fChain->SetBranchAddress("gamma1_clusterErrorTiming", &gamma1_clusterErrorTiming, &b_gamma1_clusterErrorTiming);
   fChain->SetBranchAddress("gamma1_clusterHighestE", &gamma1_clusterHighestE, &b_gamma1_clusterHighestE);
   fChain->SetBranchAddress("gamma1_clusterHasFailedErrorTiming", &gamma1_clusterHasFailedErrorTiming, &b_gamma1_clusterHasFailedErrorTiming);
   fChain->SetBranchAddress("gamma1_clusterHasFailedTiming", &gamma1_clusterHasFailedTiming, &b_gamma1_clusterHasFailedTiming);
   fChain->SetBranchAddress("gamma1_clusterHasNPhotons", &gamma1_clusterHasNPhotons, &b_gamma1_clusterHasNPhotons);
   fChain->SetBranchAddress("gamma1_clusterHasNeutralHadron", &gamma1_clusterHasNeutralHadron, &b_gamma1_clusterHasNeutralHadron);
   fChain->SetBranchAddress("gamma1_clusterLAT", &gamma1_clusterLAT, &b_gamma1_clusterLAT);
   fChain->SetBranchAddress("gamma1_clusterNHits", &gamma1_clusterNHits, &b_gamma1_clusterNHits);
   fChain->SetBranchAddress("gamma1_clusterPhi", &gamma1_clusterPhi, &b_gamma1_clusterPhi);
   fChain->SetBranchAddress("gamma1_clusterR", &gamma1_clusterR, &b_gamma1_clusterR);
   fChain->SetBranchAddress("gamma1_clusterSecondMoment", &gamma1_clusterSecondMoment, &b_gamma1_clusterSecondMoment);
   fChain->SetBranchAddress("gamma1_clusterTheta", &gamma1_clusterTheta, &b_gamma1_clusterTheta);
   fChain->SetBranchAddress("gamma1_clusterTiming", &gamma1_clusterTiming, &b_gamma1_clusterTiming);
   fChain->SetBranchAddress("gamma1_clusterTrackMatch", &gamma1_clusterTrackMatch, &b_gamma1_clusterTrackMatch);
   fChain->SetBranchAddress("gamma1_goodBelleGamma", &gamma1_goodBelleGamma, &b_gamma1_goodBelleGamma);
   fChain->SetBranchAddress("gamma2_M", &gamma2_M, &b_gamma2_M);
   fChain->SetBranchAddress("gamma2_ErrM", &gamma2_ErrM, &b_gamma2_ErrM);
   fChain->SetBranchAddress("gamma2_SigM", &gamma2_SigM, &b_gamma2_SigM);
   fChain->SetBranchAddress("gamma2_InvM", &gamma2_InvM, &b_gamma2_InvM);
   fChain->SetBranchAddress("gamma2_px", &gamma2_px, &b_gamma2_px);
   fChain->SetBranchAddress("gamma2_py", &gamma2_py, &b_gamma2_py);
   fChain->SetBranchAddress("gamma2_pz", &gamma2_pz, &b_gamma2_pz);
   fChain->SetBranchAddress("gamma2_pt", &gamma2_pt, &b_gamma2_pt);
   fChain->SetBranchAddress("gamma2_p", &gamma2_p, &b_gamma2_p);
   fChain->SetBranchAddress("gamma2_E", &gamma2_E, &b_gamma2_E);
   fChain->SetBranchAddress("gamma2_CMS_cosTheta", &gamma2_CMS_cosTheta, &b_gamma2_CMS_cosTheta);
   fChain->SetBranchAddress("gamma2_CMS_p", &gamma2_CMS_p, &b_gamma2_CMS_p);
   fChain->SetBranchAddress("gamma2_CMS_E", &gamma2_CMS_E, &b_gamma2_CMS_E);
   fChain->SetBranchAddress("gamma2_thetaInCDCAcceptance", &gamma2_thetaInCDCAcceptance, &b_gamma2_thetaInCDCAcceptance);
   fChain->SetBranchAddress("gamma2_thetaInECLAcceptance", &gamma2_thetaInECLAcceptance, &b_gamma2_thetaInECLAcceptance);
   fChain->SetBranchAddress("gamma2_thetaInEECLAcceptance", &gamma2_thetaInEECLAcceptance, &b_gamma2_thetaInEECLAcceptance);
   fChain->SetBranchAddress("gamma2_thetaInBECLAcceptance", &gamma2_thetaInBECLAcceptance, &b_gamma2_thetaInBECLAcceptance);
   fChain->SetBranchAddress("gamma2_clusterPulseShapeDiscriminationMVA", &gamma2_clusterPulseShapeDiscriminationMVA, &b_gamma2_clusterPulseShapeDiscriminationMVA);
   fChain->SetBranchAddress("gamma2_clusterHasPulseShapeDiscrimination", &gamma2_clusterHasPulseShapeDiscrimination, &b_gamma2_clusterHasPulseShapeDiscrimination);
   fChain->SetBranchAddress("gamma2_clusterNumberOfHadronDigits", &gamma2_clusterNumberOfHadronDigits, &b_gamma2_clusterNumberOfHadronDigits);
   fChain->SetBranchAddress("gamma2_clusterDeltaLTemp", &gamma2_clusterDeltaLTemp, &b_gamma2_clusterDeltaLTemp);
   fChain->SetBranchAddress("gamma2_minC2TDist", &gamma2_minC2TDist, &b_gamma2_minC2TDist);
   fChain->SetBranchAddress("gamma2_nECLClusterTrackMatches", &gamma2_nECLClusterTrackMatches, &b_gamma2_nECLClusterTrackMatches);
   fChain->SetBranchAddress("gamma2_clusterZernikeMVA", &gamma2_clusterZernikeMVA, &b_gamma2_clusterZernikeMVA);
   fChain->SetBranchAddress("gamma2_clusterReg", &gamma2_clusterReg, &b_gamma2_clusterReg);
   fChain->SetBranchAddress("gamma2_clusterAbsZernikeMoment40", &gamma2_clusterAbsZernikeMoment40, &b_gamma2_clusterAbsZernikeMoment40);
   fChain->SetBranchAddress("gamma2_clusterAbsZernikeMoment51", &gamma2_clusterAbsZernikeMoment51, &b_gamma2_clusterAbsZernikeMoment51);
   fChain->SetBranchAddress("gamma2_clusterBelleQuality", &gamma2_clusterBelleQuality, &b_gamma2_clusterBelleQuality);
   fChain->SetBranchAddress("gamma2_clusterClusterID", &gamma2_clusterClusterID, &b_gamma2_clusterClusterID);
   fChain->SetBranchAddress("gamma2_clusterConnectedRegionID", &gamma2_clusterConnectedRegionID, &b_gamma2_clusterConnectedRegionID);
   fChain->SetBranchAddress("gamma2_clusterE1E9", &gamma2_clusterE1E9, &b_gamma2_clusterE1E9);
   fChain->SetBranchAddress("gamma2_clusterE9E21", &gamma2_clusterE9E21, &b_gamma2_clusterE9E21);
   fChain->SetBranchAddress("gamma2_clusterE9E25", &gamma2_clusterE9E25, &b_gamma2_clusterE9E25);
   fChain->SetBranchAddress("gamma2_clusterEoP", &gamma2_clusterEoP, &b_gamma2_clusterEoP);
   fChain->SetBranchAddress("gamma2_clusterErrorE", &gamma2_clusterErrorE, &b_gamma2_clusterErrorE);
   fChain->SetBranchAddress("gamma2_clusterErrorPhi", &gamma2_clusterErrorPhi, &b_gamma2_clusterErrorPhi);
   fChain->SetBranchAddress("gamma2_clusterErrorTheta", &gamma2_clusterErrorTheta, &b_gamma2_clusterErrorTheta);
   fChain->SetBranchAddress("gamma2_clusterErrorTiming", &gamma2_clusterErrorTiming, &b_gamma2_clusterErrorTiming);
   fChain->SetBranchAddress("gamma2_clusterHighestE", &gamma2_clusterHighestE, &b_gamma2_clusterHighestE);
   fChain->SetBranchAddress("gamma2_clusterHasFailedErrorTiming", &gamma2_clusterHasFailedErrorTiming, &b_gamma2_clusterHasFailedErrorTiming);
   fChain->SetBranchAddress("gamma2_clusterHasFailedTiming", &gamma2_clusterHasFailedTiming, &b_gamma2_clusterHasFailedTiming);
   fChain->SetBranchAddress("gamma2_clusterHasNPhotons", &gamma2_clusterHasNPhotons, &b_gamma2_clusterHasNPhotons);
   fChain->SetBranchAddress("gamma2_clusterHasNeutralHadron", &gamma2_clusterHasNeutralHadron, &b_gamma2_clusterHasNeutralHadron);
   fChain->SetBranchAddress("gamma2_clusterLAT", &gamma2_clusterLAT, &b_gamma2_clusterLAT);
   fChain->SetBranchAddress("gamma2_clusterNHits", &gamma2_clusterNHits, &b_gamma2_clusterNHits);
   fChain->SetBranchAddress("gamma2_clusterPhi", &gamma2_clusterPhi, &b_gamma2_clusterPhi);
   fChain->SetBranchAddress("gamma2_clusterR", &gamma2_clusterR, &b_gamma2_clusterR);
   fChain->SetBranchAddress("gamma2_clusterSecondMoment", &gamma2_clusterSecondMoment, &b_gamma2_clusterSecondMoment);
   fChain->SetBranchAddress("gamma2_clusterTheta", &gamma2_clusterTheta, &b_gamma2_clusterTheta);
   fChain->SetBranchAddress("gamma2_clusterTiming", &gamma2_clusterTiming, &b_gamma2_clusterTiming);
   fChain->SetBranchAddress("gamma2_clusterTrackMatch", &gamma2_clusterTrackMatch, &b_gamma2_clusterTrackMatch);
   fChain->SetBranchAddress("gamma2_goodBelleGamma", &gamma2_goodBelleGamma, &b_gamma2_goodBelleGamma);
   fChain->SetBranchAddress("gamma1_phi", &gamma1_phi, &b_gamma1_phi);
   fChain->SetBranchAddress("gamma1_cosTheta", &gamma1_cosTheta, &b_gamma1_cosTheta);
   fChain->SetBranchAddress("gamma2_phi", &gamma2_phi, &b_gamma2_phi);
   fChain->SetBranchAddress("gamma2_cosTheta", &gamma2_cosTheta, &b_gamma2_cosTheta);
   fChain->SetBranchAddress("mpippim", &mpippim, &b_mpippim);
   fChain->SetBranchAddress("mpippim2", &mpippim2, &b_mpippim2);
   fChain->SetBranchAddress("mpippi0", &mpippi0, &b_mpippi0);
   fChain->SetBranchAddress("mpippi02", &mpippi02, &b_mpippi02);
   fChain->SetBranchAddress("mpimpi0", &mpimpi0, &b_mpimpi0);
   fChain->SetBranchAddress("mpimpi02", &mpimpi02, &b_mpimpi02);
   fChain->SetBranchAddress("mpippi02_prefit", &mpippi02_prefit, &b_mpippi02_prefit);
   fChain->SetBranchAddress("mpimpi02_prefit", &mpimpi02_prefit, &b_mpimpi02_prefit);
   fChain->SetBranchAddress("mpippim2_prefit", &mpippim2_prefit, &b_mpippim2_prefit);
   fChain->SetBranchAddress("mpippi02_vfit", &mpippi02_vfit, &b_mpippi02_vfit);
   fChain->SetBranchAddress("mpimpi02_vfit", &mpimpi02_vfit, &b_mpimpi02_vfit);
   fChain->SetBranchAddress("mpippim2_vfit", &mpippim2_vfit, &b_mpippim2_vfit);
   fChain->SetBranchAddress("Dst_M_vfit", &Dst_M_vfit, &b_Dst_M_vfit);
   fChain->SetBranchAddress("delM_vfit", &delM_vfit, &b_delM_vfit);
   fChain->SetBranchAddress("D0_M_vfit", &D0_M_vfit, &b_D0_M_vfit);
   fChain->SetBranchAddress("Dst_chiProb_vfit", &Dst_chiProb_vfit, &b_Dst_chiProb_vfit);
   fChain->SetBranchAddress("Dst_M_prefit", &Dst_M_prefit, &b_Dst_M_prefit);
   fChain->SetBranchAddress("delM_prefit", &delM_prefit, &b_delM_prefit);
   fChain->SetBranchAddress("D0_M_prefit", &D0_M_prefit, &b_D0_M_prefit);
   fChain->SetBranchAddress("pi0_M_prefit", &pi0_M_prefit, &b_pi0_M_prefit);
   fChain->SetBranchAddress("rank_Dstp_mfit", &rank_Dstp_mfit, &b_rank_Dstp_mfit);
   fChain->SetBranchAddress("rank_Dstm_mfit", &rank_Dstm_mfit, &b_rank_Dstm_mfit);
   fChain->SetBranchAddress("rank_Dstp_vfit", &rank_Dstp_vfit, &b_rank_Dstp_vfit);
   fChain->SetBranchAddress("rank_Dstm_vfit", &rank_Dstm_vfit, &b_rank_Dstm_vfit);
   fChain->SetBranchAddress("rank_Dstp_prefit", &rank_Dstp_prefit, &b_rank_Dstp_prefit);
   fChain->SetBranchAddress("rank_Dstm_prefit", &rank_Dstm_prefit, &b_rank_Dstm_prefit);
   fChain->SetBranchAddress("rank_Dstp_mfit_noprefit", &rank_Dstp_mfit_noprefit, &b_rank_Dstp_mfit_noprefit);
   fChain->SetBranchAddress("rank_Dstm_mfit_noprefit", &rank_Dstm_mfit_noprefit, &b_rank_Dstm_mfit_noprefit);
   fChain->SetBranchAddress("rank_Dstp_vfit_noprefit", &rank_Dstp_vfit_noprefit, &b_rank_Dstp_vfit_noprefit);
   fChain->SetBranchAddress("rank_Dstm_vfit_noprefit", &rank_Dstm_vfit_noprefit, &b_rank_Dstm_vfit_noprefit);
   fChain->SetBranchAddress("rank_Dstp_mfit_newmw", &rank_Dstp_mfit_newmw, &b_rank_Dstp_mfit_newmw);
   fChain->SetBranchAddress("rank_Dstm_mfit_newmw", &rank_Dstm_mfit_newmw, &b_rank_Dstm_mfit_newmw);
   fChain->SetBranchAddress("rank_Dstp_vfit_newmw", &rank_Dstp_vfit_newmw, &b_rank_Dstp_vfit_newmw);
   fChain->SetBranchAddress("rank_Dstm_vfit_newmw", &rank_Dstm_vfit_newmw, &b_rank_Dstm_vfit_newmw);
   fChain->SetBranchAddress("rank_Dstp_mfit_noprefit_newmw", &rank_Dstp_mfit_noprefit_newmw, &b_rank_Dstp_mfit_noprefit_newmw);
   fChain->SetBranchAddress("rank_Dstm_mfit_noprefit_newmw", &rank_Dstm_mfit_noprefit_newmw, &b_rank_Dstm_mfit_noprefit_newmw);
   fChain->SetBranchAddress("rank_Dstp_vfit_noprefit_newmw", &rank_Dstp_vfit_noprefit_newmw, &b_rank_Dstp_vfit_noprefit_newmw);
   fChain->SetBranchAddress("rank_Dstm_vfit_noprefit_newmw", &rank_Dstm_vfit_noprefit_newmw, &b_rank_Dstm_vfit_noprefit_newmw);
   Notify();
}

Bool_t Test::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Test::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Test_cxx
