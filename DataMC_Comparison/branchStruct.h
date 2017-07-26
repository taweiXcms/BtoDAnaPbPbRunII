#include <TTree.h>
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphAsymmErrors.h>
#include <TLorentzVector.h>
#include "TLegendEntry.h"
#define MAX_XB       20000
#define MAX_GEN      6000
#define PION_MASS   0.13957018
#define D0_MASS 1.8648

TTree* nt;
TTree* ntHlt;
TTree* ntSkim;
TTree* ntHi;
TTree* ntGen;
//pp
int     pBeamScrapingFilter;
int     pPAprimaryVertexFilter;
int     HLT_DmesonPPTrackingGlobal_Dpt8_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt15_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt20_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt30_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt50_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt8ForPPRef_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt15ForPPRef_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt20ForPPRef_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt30ForPPRef_v1;
int     HLT_DmesonPPTrackingGlobal_Dpt50ForPPRef_v1;
//pbpb
int     pclusterCompatibilityFilter;
int     pprimaryVertexFilter;
int     phfCoincFilter3;
int     hiBin;
int 	HLT_HIDmesonHITrackingGlobal_Dpt20_v1;
int 	HLT_HIDmesonHITrackingGlobal_Dpt40_v1;
int 	HLT_HIDmesonHITrackingGlobal_Dpt60_v1;
int 	HLT_HIDmesonHITrackingGlobal_Dpt20_v2;
int 	HLT_HIDmesonHITrackingGlobal_Dpt40_v2;
int 	HLT_HIDmesonHITrackingGlobal_Dpt60_v2;

//common
int     RunNo;
int     EvtNo;
int     LumiNo;
float   pthatweight;
float   maxDgenpt;
float   pthat;
int     Gsize;
float   Gpt[MAX_GEN];
float   Gy[MAX_GEN];
//float   GpdgId[MAX_GEN];   
//float   GisSignal[MAX_GEN];
int   GpdgId[MAX_GEN];   
int   GisSignal[MAX_GEN];

int     Dsize;
float   Dgen[MAX_XB];
float   Dgenpt[MAX_XB];
float   PVz;
bool    Dtrk1highPurity[MAX_XB];
float   Dtrk1Pt[MAX_XB];
float   Dtrk1Eta[MAX_XB];
float   Dtrk1Phi[MAX_XB];
float   Dtrk1PtErr[MAX_XB];
float   Dtrk1Dxy[MAX_XB];
float   Dtrk1D0Err[MAX_XB];
float   Dtrk1thetastar[MAX_XB];
float   Dtrk1thetastar_uf[MAX_XB];
float   Dmass[MAX_XB];
float   Dpt[MAX_XB];
float   Deta[MAX_XB];
float   Dphi[MAX_XB];
float   Dy[MAX_XB];
float   Dd0[MAX_XB];
float   Dd0Err[MAX_XB];
float   Ddxyz[MAX_XB];
float   DdxyzErr[MAX_XB];
float   Dchi2ndf[MAX_XB];
float   Dchi2cl[MAX_XB];
float   Ddtheta[MAX_XB];
float   Dlxy[MAX_XB];
float   Dalpha[MAX_XB];
float   DsvpvDistance[MAX_XB];
float   DsvpvDisErr[MAX_XB];
float   DsvpvDistance_2D[MAX_XB];
float   DsvpvDisErr_2D[MAX_XB];
float   DlxyBS[MAX_XB];
float   DlxyBSErr[MAX_XB];
float   DMaxDoca[MAX_XB];
float   DMaxTkPt[MAX_XB];
float   DMinTkPt[MAX_XB];
float   DtktkResmass[MAX_XB];
float   DtktkRespt[MAX_XB];
float   DtktkReseta[MAX_XB];
float   DtktkResphi[MAX_XB];
float   DtktkRes_chi2ndf[MAX_XB];
float   DtktkRes_chi2cl[MAX_XB];
float   DtktkRes_alpha[MAX_XB];
float   DtktkRes_svpvDistance[MAX_XB];
float   DtktkRes_svpvDisErr[MAX_XB];
float   DtktkRes_alphaToSV[MAX_XB];
float   DtktkRes_angleToTrk1[MAX_XB];
float   DtktkRes_unfitted_angleToTrk1[MAX_XB];
float   DtktkRes_ptAsymToTrk1[MAX_XB];
float   DtktkRes_unfitter_ptAsymToTrk1[MAX_XB];
float   DtktkRes_lxyBS[MAX_XB];
float   DtktkRes_lxyBSErr[MAX_XB];
bool	DRestrk1highPurity[MAX_XB];
float   DRestrk1Pt[MAX_XB];
float   DRestrk1Eta[MAX_XB];
float   DRestrk1Phi[MAX_XB];
float	DRestrk1PtErr[MAX_XB];
bool 	DRestrk2highPurity[MAX_XB];
float   DRestrk2Pt[MAX_XB];
float   DRestrk2Eta[MAX_XB];
float   DRestrk2Phi[MAX_XB];
float	DRestrk2PtErr[MAX_XB];
float	DRestrk1Dxy[MAX_XB];
float	DRestrk2Dxy[MAX_XB];
float	DRestrk1D0Err[MAX_XB];
float	DRestrk2D0Err[MAX_XB];
float   DRestrk1thetastar[MAX_XB];
float   DRestrk2thetastar[MAX_XB];
float   DRestrk1thetastar_uf[MAX_XB];
float   DRestrk2thetastar_uf[MAX_XB];

void setAddressTree(TFile* inf, bool ispp, bool isMC){
    nt = (TTree*)inf->Get("ntBptoD0pi");
    ntHlt = (TTree*)inf->Get("ntHlt");
    ntSkim = (TTree*)inf->Get("ntSkim");
    ntHi = (TTree*)inf->Get("ntHi");
    ntGen = (TTree*)inf->Get("ntGen");
	if(ispp){
		ntSkim->SetBranchAddress("pBeamScrapingFilter",&pBeamScrapingFilter);
		ntSkim->SetBranchAddress("pPAprimaryVertexFilter",&pPAprimaryVertexFilter);
		ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt8_v1",&HLT_DmesonPPTrackingGlobal_Dpt8_v1);
		ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt15_v1",&HLT_DmesonPPTrackingGlobal_Dpt15_v1);
		ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt20_v1",&HLT_DmesonPPTrackingGlobal_Dpt20_v1);
		ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt30_v1",&HLT_DmesonPPTrackingGlobal_Dpt30_v1);
		ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt50_v1",&HLT_DmesonPPTrackingGlobal_Dpt50_v1);
		if(isMC){
			ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt8ForPPRef_v1",&HLT_DmesonPPTrackingGlobal_Dpt8ForPPRef_v1);
			ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt15ForPPRef_v1",&HLT_DmesonPPTrackingGlobal_Dpt15ForPPRef_v1);
			ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt20ForPPRef_v1",&HLT_DmesonPPTrackingGlobal_Dpt20ForPPRef_v1);
			ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt30ForPPRef_v1",&HLT_DmesonPPTrackingGlobal_Dpt30ForPPRef_v1);
			ntHlt->SetBranchAddress("HLT_DmesonPPTrackingGlobal_Dpt50ForPPRef_v1",&HLT_DmesonPPTrackingGlobal_Dpt50ForPPRef_v1);
		}
	}
	else{
		ntSkim->SetBranchAddress("pclusterCompatibilityFilter",&pclusterCompatibilityFilter);
		ntSkim->SetBranchAddress("pprimaryVertexFilter",&pprimaryVertexFilter);
		ntSkim->SetBranchAddress("phfCoincFilter3",&phfCoincFilter3);
		ntHi->SetBranchAddress("hiBin",&hiBin);
		ntHlt->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v1",&HLT_HIDmesonHITrackingGlobal_Dpt20_v1);
		ntHlt->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_v1",&HLT_HIDmesonHITrackingGlobal_Dpt40_v1);
		ntHlt->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_v1",&HLT_HIDmesonHITrackingGlobal_Dpt60_v1);
		if(isMC){
			ntHlt->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v2",&HLT_HIDmesonHITrackingGlobal_Dpt20_v2);
			ntHlt->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_v2",&HLT_HIDmesonHITrackingGlobal_Dpt40_v2);
			ntHlt->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_v2",&HLT_HIDmesonHITrackingGlobal_Dpt60_v2);
		}
	}

	if(isMC){
		ntHi->SetBranchAddress("pthatweight",&pthatweight);
		ntHi->SetBranchAddress("maxDgenpt",&maxDgenpt);
		ntHi->SetBranchAddress("pthat",&pthat);
		ntGen->SetBranchAddress("Gsize",&Gsize);
		ntGen->SetBranchAddress("Gpt",Gpt);
		ntGen->SetBranchAddress("Gy",Gy);
		ntGen->SetBranchAddress("GpdgId",GpdgId);
		ntGen->SetBranchAddress("GisSignal",GisSignal);
	}
	nt->SetBranchAddress("Dsize",&Dsize);
	nt->SetBranchAddress("Dgen",Dgen);
	nt->SetBranchAddress("Dgenpt",Dgenpt);
	nt->SetBranchAddress("PVz",&PVz);

	nt->SetBranchAddress("Dtrk1highPurity",Dtrk1highPurity);
	nt->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
	nt->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
	nt->SetBranchAddress("Dtrk1Phi",Dtrk1Phi);
	nt->SetBranchAddress("Dtrk1PtErr",Dtrk1PtErr);
	nt->SetBranchAddress("Dtrk1Dxy",Dtrk1Dxy);
	nt->SetBranchAddress("Dtrk1D0Err",Dtrk1D0Err);
	nt->SetBranchAddress("Dtrk1thetastar",Dtrk1thetastar);
	nt->SetBranchAddress("Dtrk1thetastar_uf",Dtrk1thetastar_uf);
	nt->SetBranchAddress("Dmass",Dmass);
	nt->SetBranchAddress("Dpt",Dpt);
	nt->SetBranchAddress("Deta",Deta);
	nt->SetBranchAddress("Dphi",Dphi);
	nt->SetBranchAddress("Dy",Dy);
	nt->SetBranchAddress("Dd0",Dd0);
	nt->SetBranchAddress("Dd0Err",Dd0Err);
	nt->SetBranchAddress("Ddxyz",Ddxyz);
	nt->SetBranchAddress("DdxyzErr",DdxyzErr);
	nt->SetBranchAddress("Dchi2ndf",Dchi2ndf);
	nt->SetBranchAddress("Dchi2cl",Dchi2cl);
	nt->SetBranchAddress("Ddtheta",Ddtheta);
	nt->SetBranchAddress("Dlxy",Dlxy);
	nt->SetBranchAddress("Dalpha",Dalpha);
	nt->SetBranchAddress("DsvpvDistance",DsvpvDistance);
	nt->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);
	nt->SetBranchAddress("DsvpvDistance_2D",DsvpvDistance_2D);
	nt->SetBranchAddress("DsvpvDistance_2D",DsvpvDistance_2D);
	nt->SetBranchAddress("DtktkRes_chi2ndf",DtktkRes_chi2ndf);
	nt->SetBranchAddress("DtktkRes_chi2cl",DtktkRes_chi2cl);
	nt->SetBranchAddress("DtktkRes_alpha",DtktkRes_alpha);
	nt->SetBranchAddress("DtktkRes_svpvDistance",DtktkRes_svpvDistance);
	nt->SetBranchAddress("DtktkRes_svpvDisErr",DtktkRes_svpvDisErr);
	nt->SetBranchAddress("DlxyBS",DlxyBS);
	nt->SetBranchAddress("DlxyBSErr",DlxyBSErr);
	nt->SetBranchAddress("DMaxDoca",DMaxDoca);
	nt->SetBranchAddress("DtktkRes_alphaToSV",DtktkRes_alphaToSV);
	nt->SetBranchAddress("DtktkRes_angleToTrk1",DtktkRes_angleToTrk1);
	nt->SetBranchAddress("DtktkRes_unfitted_angleToTrk1",DtktkRes_unfitted_angleToTrk1);
	nt->SetBranchAddress("DtktkRes_ptAsymToTrk1",DtktkRes_ptAsymToTrk1);
	nt->SetBranchAddress("DtktkRes_unfitter_ptAsymToTrk1",DtktkRes_unfitter_ptAsymToTrk1);
	nt->SetBranchAddress("DMaxTkPt",DMaxTkPt);
	nt->SetBranchAddress("DMinTkPt",DMinTkPt);
	nt->SetBranchAddress("DtktkResmass",DtktkResmass);
	nt->SetBranchAddress("DtktkRespt",DtktkRespt);
	nt->SetBranchAddress("DtktkReseta",DtktkReseta);
	nt->SetBranchAddress("DtktkResphi",DtktkResphi);
	nt->SetBranchAddress("DtktkRes_lxyBS",DtktkRes_lxyBS);
	nt->SetBranchAddress("DtktkRes_lxyBSErr",DtktkRes_lxyBSErr);
	nt->SetBranchAddress("DRestrk1highPurity",DRestrk1highPurity);
	nt->SetBranchAddress("DRestrk1Pt",DRestrk1Pt);
	nt->SetBranchAddress("DRestrk1Eta",DRestrk1Eta);
	nt->SetBranchAddress("DRestrk1Phi",DRestrk1Phi);
	nt->SetBranchAddress("DRestrk1PtErr",DRestrk1PtErr);
	nt->SetBranchAddress("DRestrk1Dxy",DRestrk1Dxy);
	nt->SetBranchAddress("DRestrk1D0Err",DRestrk1D0Err);
	nt->SetBranchAddress("DRestrk2highPurity",DRestrk2highPurity);
	nt->SetBranchAddress("DRestrk2Pt",DRestrk2Pt);
	nt->SetBranchAddress("DRestrk2Eta",DRestrk2Eta);
	nt->SetBranchAddress("DRestrk2Phi",DRestrk2Phi);
	nt->SetBranchAddress("DRestrk2PtErr",DRestrk2PtErr);
	nt->SetBranchAddress("DRestrk2Dxy",DRestrk2Dxy);
	nt->SetBranchAddress("DRestrk2D0Err",DRestrk2D0Err);
	nt->SetBranchAddress("DRestrk1thetastar",DRestrk1thetastar);
	nt->SetBranchAddress("DRestrk2thetastar",DRestrk2thetastar);
	nt->SetBranchAddress("DRestrk1thetastar_uf",DRestrk1thetastar_uf);
	nt->SetBranchAddress("DRestrk2thetastar_uf",DRestrk2thetastar_uf);
}
