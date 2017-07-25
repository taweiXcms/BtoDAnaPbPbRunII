#include <iostream>
#include "branchStruct.h"
using namespace std;

int numofbins = 100;
const int nBins=1;
double ptBins[nBins+1] = {5, 7};
const int nHist = 47;
bool ispp = 0;
string inputmc;
string inputdata;

enum var {bmass, bpt, by, bsvpv, bsvpvnorm, blxybs, breslxybs, bdoca, btheta, balpha, bchicl, bd0d, btk1pt, btk1ptnorm, btk1eta, btk1Dxy, btk1DxyNorm, btk1thetastar, btk1thetastar_uf, bresmass, brespt, breseta, bressvpv, bressvpvnorm, bresalpha, bresalphatosv, breschicl, brestk1pt, brestk2pt, brestk1ptNorm, brestk2ptNorm, brestk1eta, brestk2eta, brestk1Dxy, brestk2Dxy, brestk1DxyNorm, brestk2DxyNorm, brestk1thetastar, brestk1thetastar_uf, brestk2thetastar, brestk2thetastar_uf, bmaxtkpt, bmintkpt, bdpiptasym, bdpiangle, bdpiptasym_uf, bdpiangle_uf};

struct parset{string names; float histmin; float histmax;};
struct parset settings[nHist] = {
	{"Mass", 5, 6},
	{"Pt", float(ptBins[0]), float(ptBins[1])},
	{"Y", 0, 2.6},
	{"Svpv", 0, 0.3},
	{"SvpvNorm", 0, 12},
	{"LxyBS", 0, 1000},
	{"ResLxyBS", 0, 1000},
	{"DOCA", 0, 0.02},
	{"CosTheta", 0.997, 1.0001},
	{"Alpha", 0., 1.2},
	{"ChiCL", 0.01, 2.},
	{"D0", 0, 0.15},
	{"Tk1pt", 0, float(ptBins[1])},
	{"Tk1ptNorm", 0, 0.05},
	{"Tk1eta", -2, 2.},
	{"Tk1Dxy", 0, 0.15},
	{"Tk1DxyNorm", 0, 15},
	{"Tk1ThetaStar", 0, 3.2},
	{"Tk1ThetaStar_uf", 0, 3.2},
	{"ResMass", 1.8, 1.95},
	{"ResPt", 0, float(ptBins[1])},
	{"ResEta", -2, 2},
	{"ResSvpv", 0, 0.3},
	{"ResSvpvNorm", 0, 12},
	{"ResAlpha", 0., 1.2},
	{"ResAlphaToSV", 0., 0.3},
	{"ResChiCL", 0.01, 2.},
	{"Restk1pt", 0, float(ptBins[1])},
	{"Restk2pt", 0, float(ptBins[1])},
	{"Restk1ptNorm", 0, 0.05},
	{"Restk2ptNorm", 0, 0.05},
	{"Restk1eta", -2, 2},
	{"Restk2eta", -2, 2},
	{"Restk1Dxy", 0, 0.08},
	{"Restk2Dxy", 0, 0.08},
	{"Restk1DxyNorm", 0, 15},
	{"Restk2DxyNorm", 0, 15},
	{"Restk1ThetaStar", 0, 3.2},
	{"Restk1ThetaStar_uf", 0, 3.2},
	{"Restk2ThetaStar", 0, 3.2},
	{"Restk2ThetaStar_uf", 0, 3.2},
	{"Maxtkpt", 0, float(ptBins[1])},
	{"Mintkpt", 0, float(ptBins[1]-3.)},
	{"DPiPtAsym", -1, 1},
	{"DPiAngle", 0, 3.14},
	{"DPiPtAsym_uf", -1, 1},
	{"DPiAngle_uf", 0, 3.14},
};

void readTree(bool isMC, TH1D* hist[], string input);
void initHist(bool isMC, TH1D* hist[]);
void plotting(TH1D* hist1[], TH1D* hist2[], TCanvas* c[]);

void compare(){
	string label = "";
	if(ispp){
		label = "pp"; 
        inputmc = "/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170717_pp_BuToD0Pi_20151212_v2_DfinderMC_pp_20170423_BtoD0Pi_pthatweight.root";
        inputdata ="/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170717_MinimumBias_DfinderData_pp_20170423_BtoD0Pi_Dpt5EvtSkim/Dntuple_20170717_MinimumBias2_DfinderData_pp_20170423_BtoD0Pi_Dpt5EvtSkim.root";
    }
	else{
		label = "PbPb";
		//inputmc = "/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170717_PbPb_BuToD0Pi_20151212_DfinderMC_PbPb_20170720_BtoD0Pi_40FilesEach_pthatweight.root";
		inputmc = "/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170717_PbPb_BuToD0Pi_20151212_DfinderMC_PbPb_20170720_BtoD0Pi_100FilesEach_pthatweight.root";
		inputdata = "/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170717_HIMinimumBias2_DfinderData_PbPb_20170717_Golden_BtoD0Pi_Dpt5EvtSkim_10Files.root";
	}

	TH1D* histMC[nHist];
	initHist(1, histMC);
	readTree(1, histMC, inputmc);
	TH1D* histData[nHist];
	initHist(0, histData);
	readTree(0, histData, inputdata);
    TCanvas* c[nHist];
    TCanvas* cdummy;
    cdummy =  new TCanvas(Form("cdummy"),"",600,600);
    cdummy->SaveAs(Form("plots_%s/all.pdf(", label.c_str()));
	plotting(histMC, histData, c);
    cdummy->SaveAs(Form("plots_%s/all.pdf)", label.c_str()));

	TFile *outf= new TFile(Form("results_%s.root", label.c_str()), "recreate"); 
	outf->cd();
	for(int i = 0; i < nHist; i++){
		histMC[i]->Write();
	}
	outf->Write();
	outf->Close();
}

void readTree(bool isMC, TH1D* hist[], string input){
    TFile* inf = new TFile(input.c_str());
    TTree* nt = (TTree*)inf->Get("ntBptoD0pi");
    TTree* ntHlt = (TTree*)inf->Get("ntHlt");
    TTree* ntSkim = (TTree*)inf->Get("ntSkim");
    TTree* ntHi = (TTree*)inf->Get("ntHi");
    TTree* ntGen = (TTree*)inf->Get("ntGen");
	setAddressTree(nt, ntHlt, ntSkim, ntHi, ntGen, ispp, isMC);
	int nevents_total = nt->GetEntries();
	if(!isMC) nevents_total = int(nevents_total*0.1);
//	nevents_total = 200000;
	float weight = 1;
    for(int entry=0; entry<nevents_total; entry++){
	    if ((entry%10000) == 0) printf("Loading event #%d of %d.\n",entry,nevents_total);
    	nt->GetEntry(entry);
    	ntHlt->GetEntry(entry);
    	ntSkim->GetEntry(entry);
    	ntHi->GetEntry(entry);
		if(isMC) ntGen->GetEntry(entry);
	    for(int g=0; g<Gsize; g++){
        }
	    for(int d=0; d<Dsize; d++){
			bool pass = false;
			if(isMC) weight = pthatweight;
			else weight = 1;
			// baseline cuts
			if(!(1
				&& TMath::Abs(Dy[d])<1.0
				&& Dmass[d]>5&&Dmass[d]<6
				&& Dtrk1highPurity[d] && abs(Dtrk1Eta[d])<1.5 && Dtrk1Pt[d]>0.5 && Dtrk1PtErr[d]/Dtrk1Pt[d]<0.3
				&& DRestrk1highPurity[d] && abs(DRestrk1Eta[d])<1.5 && DRestrk1Pt[d]>0.5 && DRestrk1PtErr[d]/DRestrk1Pt[d]<0.3
				&& DRestrk2highPurity[d] && abs(DRestrk2Eta[d])<1.5 && DRestrk2Pt[d]>0.5 && DRestrk1PtErr[d]/DRestrk1Pt[d]<0.3
				&& fabs(DtktkResmass[d]-1.87)<0.03
				&& Dpt[d]>ptBins[0] && Dpt[d]<ptBins[1]
				&& Dchi2cl[d]>0.05
				&& DtktkRes_chi2cl[d]>0.05
				&& Dalpha[d]<3.2
				&& DtktkRes_alpha[d]<3.2
				&& DtktkRes_alphaToSV[d]<3.2
				&& (DsvpvDistance[d]/DsvpvDisErr[d])>0.0
				&& (DtktkRes_svpvDistance[d]/DtktkRes_svpvDisErr[d])>0.0
			)) continue;
			if(ispp){
				if(1
				&& (!isMC || (Dgen[d]==23333))
				&& abs(PVz)<15
				&& pBeamScrapingFilter
				&& pPAprimaryVertexFilter
//				&& ((!isMC && (HLT_DmesonPPTrackingGlobal_Dpt8_v1 || HLT_DmesonPPTrackingGlobal_Dpt15_v1 || HLT_DmesonPPTrackingGlobal_Dpt20_v1 || HLT_DmesonPPTrackingGlobal_Dpt30_v1 || HLT_DmesonPPTrackingGlobal_Dpt50_v1)) || isMC) 
//				&& (!isMC || (isMC && (HLT_DmesonPPTrackingGlobal_Dpt8ForPPRef_v1 || HLT_DmesonPPTrackingGlobal_Dpt15ForPPRef_v1 || HLT_DmesonPPTrackingGlobal_Dpt20ForPPRef_v1 || HLT_DmesonPPTrackingGlobal_Dpt30ForPPRef_v1 || HLT_DmesonPPTrackingGlobal_Dpt50ForPPRef_v1)) )
//				&& ( (!isMC && (HLT_L1MinimumBiasHF1OR_part1_v1||HLT_L1MinimumBiasHF1OR_part2_v1||HLT_L1MinimumBiasHF1OR_part3_v1||HLT_L1MinimumBiasHF1OR_part4_v1||HLT_L1MinimumBiasHF1OR_part5_v1||HLT_L1MinimumBiasHF1OR_part6_v1||HLT_L1MinimumBiasHF1OR_part7_v1||HLT_L1MinimumBiasHF1OR_part8_v1||HLT_L1MinimumBiasHF1OR_part9_v1||HLT_L1MinimumBiasHF1OR_part10_v1||HLT_L1MinimumBiasHF1OR_part11_v1||HLT_L1MinimumBiasHF1OR_part12_v1||HLT_L1MinimumBiasHF1OR_part13_v1||HLT_L1MinimumBiasHF1OR_part14_v1||HLT_L1MinimumBiasHF1OR_part15_v1||HLT_L1MinimumBiasHF1OR_part16_v1||HLT_L1MinimumBiasHF1OR_part17_v1||HLT_L1MinimumBiasHF1OR_part18_v1||HLT_L1MinimumBiasHF1OR_part19_v1)) || isMC)

				// Additional cuts
//				&& abs(Dtrk1Eta[d])<1.0 && abs(DRestrk1Eta[d])<1.0 && abs(DRestrk2Eta[d])<1.0
//				&& Dtrk1Pt[d]>1. && DRestrk1Pt[d]>1. && DRestrk2Pt[d]>1.
//				&& Dalpha[d]<0.3
//				&& (DsvpvDistance[d]/DsvpvDisErr[d])>3.
//				&& (DtktkRes_svpvDistance[d]/DtktkRes_svpvDisErr[d])>2.0
//				&& DtktkRespt[d]>2.0
//				&& DtktkRes_ptAsymToTrk1[d]>-0.8 && DtktkRes_ptAsymToTrk1[d]<0.65
				){
					pass = true;
				}
			}//if pp
			else{	
				if(1
                && (!isMC || (Dgen[d]==23333))
				&& abs(PVz)<15
				&& pclusterCompatibilityFilter
				&& pprimaryVertexFilter
				&& phfCoincFilter3
//				&& ( (!isMC && (HLT_HIDmesonHITrackingGlobal_Dpt20_v1 || HLT_HIDmesonHITrackingGlobal_Dpt40_v1 || HLT_HIDmesonHITrackingGlobal_Dpt60_v1)) 
//					|| (isMC && (HLT_HIDmesonHITrackingGlobal_Dpt20_v2 || HLT_HIDmesonHITrackingGlobal_Dpt40_v2 || HLT_HIDmesonHITrackingGlobal_Dpt60_v2)) )
//
				){
					pass = true;
				}
			}//if pbpb
            if(pass){
				hist[bmass]->Fill(Dmass[d], weight);
			}
			if(pass && (isMC || (!isMC && (Dmass[d]-5.279)>0.2&&(Dmass[d]-5.279)<0.5))){
			    TLorentzVector* Bp = new TLorentzVector;
			    TLorentzVector* D0 = new TLorentzVector;
			    TLorentzVector* Pi = new TLorentzVector;
				Bp->SetPtEtaPhiM(Dpt[d], Deta[d], Dphi[d], Dmass[d]);
				D0->SetPtEtaPhiM(DtktkRespt[d], DtktkReseta[d], DtktkResphi[d], DtktkResmass[d]);
				Pi->SetPtEtaPhiM(Dtrk1Pt[d], Dtrk1Eta[d], Dtrk1Phi[d], PION_MASS);
				hist[bpt]->Fill(Dpt[d], weight);
				hist[by]->Fill(fabs(Dy[d]), weight);
				hist[bsvpv]->Fill(DsvpvDistance[d], weight);
				hist[bsvpvnorm]->Fill(DsvpvDistance[d]/DsvpvDisErr[d], weight);
				hist[blxybs]->Fill(DlxyBS[d]/DlxyBSErr[d], weight);
				hist[breslxybs]->Fill(DtktkRes_lxyBS[d]/DtktkRes_lxyBSErr[d], weight);
				hist[bdoca]->Fill(DMaxDoca[d], weight);
				hist[btheta]->Fill(cos(Ddtheta[d]), weight);
				hist[balpha]->Fill(Dalpha[d], weight);
				hist[bchicl]->Fill(Dchi2cl[d], weight);
				//hist[bd0d]->Fill(Dd0[d]/Dd0Err[d], weight);
				hist[bd0d]->Fill(Dd0[d], weight);
				hist[btk1pt]->Fill(Dtrk1Pt[d], weight);
				hist[btk1ptnorm]->Fill(Dtrk1PtErr[d]/Dtrk1Pt[d], weight);
				hist[btk1eta]->Fill(Dtrk1Eta[d], weight);
				hist[btk1Dxy]->Fill(fabs(Dtrk1Dxy[d]), weight);
				hist[btk1DxyNorm]->Fill(fabs(Dtrk1Dxy[d]/Dtrk1D0Err[d]), weight);
				hist[btk1thetastar]->Fill(Dtrk1thetastar[d], weight);
				hist[btk1thetastar_uf]->Fill(Dtrk1thetastar_uf[d], weight);
				hist[bresmass]->Fill(DtktkResmass[d], weight);
				hist[brespt]->Fill(DtktkRespt[d], weight);
				hist[breseta]->Fill(DtktkReseta[d], weight);
				hist[bressvpv]->Fill(DtktkRes_svpvDistance[d],  weight);
				hist[bressvpvnorm]->Fill(DtktkRes_svpvDistance[d]/DtktkRes_svpvDisErr[d], weight);
				hist[bresalpha]->Fill(DtktkRes_alpha[d], weight);
                hist[bresalphatosv]->Fill(DtktkRes_alphaToSV[d], weight);
				hist[breschicl]->Fill(DtktkRes_chi2cl[d], weight);
				hist[brestk1pt]->Fill(DRestrk1Pt[d], weight);
				hist[brestk2pt]->Fill(DRestrk2Pt[d], weight);
				hist[brestk1ptNorm]->Fill(DRestrk1PtErr[d]/DRestrk1Pt[d], weight);
				hist[brestk2ptNorm]->Fill(DRestrk2PtErr[d]/DRestrk2Pt[d], weight);
				hist[brestk1eta]->Fill(DRestrk1Eta[d], weight);
				hist[brestk2eta]->Fill(DRestrk2Eta[d], weight);
				hist[brestk1Dxy]->Fill(fabs(DRestrk1Dxy[d]), weight);
				hist[brestk2Dxy]->Fill(fabs(DRestrk2Dxy[d]), weight);
				hist[brestk1DxyNorm]->Fill(fabs(DRestrk1Dxy[d]/DRestrk1D0Err[d]), weight);
				hist[brestk2DxyNorm]->Fill(fabs(DRestrk2Dxy[d]/DRestrk2D0Err[d]), weight);
				hist[brestk1thetastar]->Fill(DRestrk1thetastar[d], weight);
				hist[brestk1thetastar_uf]->Fill(DRestrk1thetastar_uf[d], weight);
				hist[brestk2thetastar]->Fill(DRestrk2thetastar[d], weight);
				hist[brestk2thetastar_uf]->Fill(DRestrk2thetastar_uf[d], weight);
                hist[bmaxtkpt]->Fill(DMaxTkPt[d], weight);
                hist[bmintkpt]->Fill(DMinTkPt[d], weight);
                hist[bdpiptasym]->Fill(DtktkRes_ptAsymToTrk1[d], weight);
                hist[bdpiangle]->Fill(DtktkRes_angleToTrk1[d], weight);
                hist[bdpiptasym_uf]->Fill(DtktkRes_unfitter_ptAsymToTrk1[d], weight);
                hist[bdpiangle_uf]->Fill(DtktkRes_unfitted_angleToTrk1[d], weight);
			}
        }//Bsize loop
	}//event loop
}

void initHist(bool isMC, TH1D* hist[]){
	string label = "";
	string mc = "";
	if(ispp) label = "pp";
	else label = "PbPb";
	if(isMC) mc = "MC";
	else mc = "Data";
	string title;
	for(int i = 0; i < nHist; i++){
    	title = Form("%s_%s_%s", settings[i].names.c_str(), label.c_str(), mc.c_str());
		hist[i] = new TH1D(title.c_str(), title.c_str(), numofbins, settings[i].histmin, settings[i].histmax);	
		hist[i]->SetMinimum(0);
	}
}

void plotting(TH1D* hist1[], TH1D* hist2[], TCanvas* c[]){
	string label = "";
	if(ispp) label = "pp";
	else label = "PbPb";
	for(int i = 0; i < nHist; i++){
		c[i] =  new TCanvas(Form("c%d",i),"",600,600);
        c[i]->cd();
		if(hist1[i]->Integral() != 0)
			hist1[i]->Scale(hist2[i]->Integral()/hist1[i]->Integral());

		hist1[i]->SetLineColor(2);
		hist1[i]->SetMarkerColor(2);
		hist1[i]->SetLineWidth(3);
		hist2[i]->SetLineColor(1);
		hist2[i]->SetMarkerColor(1);
		hist2[i]->SetLineWidth(3);

		hist2[i]->SetMarkerSize(1);
		hist1[i]->SetMaximum(max(hist1[i]->GetMaximum(), hist2[i]->GetMaximum())*1.4);
		//hist1[i]->SetMaximum(hist2[i]->GetMaximum()*1.4);
		hist1[i]->Draw("hist");
		hist1[i]->Draw("same e");
		//hist2[i]->Draw("same hist");
		hist2[i]->Draw("same pe");

		TLegend *lg=new TLegend(0.84,0.84,0.94,0.94,"");
		lg->SetBorderSize(0);
		lg->SetLineColor(0);
		lg->SetFillColor(0);
		lg->SetFillStyle(1001);
		lg->SetTextFont(42);
		lg->SetTextSize(0.045);
		TLegendEntry *lgmc = lg->AddEntry(hist1[i],"MC","pl");
		TLegendEntry *lgdata = lg->AddEntry(hist2[i],"Data","pl");
		lg->Draw();

		c[i]->SaveAs(Form("plots_%s/%s.pdf", label.c_str(), settings[i].names.c_str()));
		c[i]->SaveAs(Form("plots_%s/all.pdf", label.c_str()));
    }
}
