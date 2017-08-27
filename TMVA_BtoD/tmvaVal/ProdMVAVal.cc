#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#include "../prefilter.h"
#define MAX_XB       20000

void ProdMVAVal(string colsys = "pp", float ptMin = 5, float ptMax = 7, string mvatype = "MLP", int varStage = 5, TString inputS = "", TString inputB = ""){

	void makeoutput(TString infname, TString ofname, string colsys, string mvatype, int varStage);

	isPbPb = (colsys=="pp") ? 0 : 1;
	ptmin = ptMin;
	ptmax = ptMax;

	TString outfile1 =Form("MVAfiles/%s_%s_%.0f_%.0f_varStage%d_DATA.root",mvatype.c_str(),colsys.c_str(),ptMin,ptMax,varStage) ;
	makeoutput(inputB,outfile1,colsys,mvatype,varStage);
	TString outfile2 =Form("MVAfiles/%s_%s_%.0f_%.0f_varStage%d_MC.root",mvatype.c_str(),colsys.c_str(),ptMin,ptMax,varStage) ;
	makeoutput(inputS,outfile2,colsys,mvatype,varStage);
}
void makeoutput(TString infname, TString ofname, string colsys, string mvatype, int varStage){
	// Read the input tree
	TFile *inf = new TFile(infname);
	TTree *t = (TTree*)inf->Get("ntBptoD0pi");
	Int_t   Dsize;
	Float_t Dtrk1Pt[MAX_XB];
	Float_t DRestrk1Pt[MAX_XB];
	Float_t DRestrk2Pt[MAX_XB];
	Float_t Dtrk1Eta[MAX_XB];
    Float_t DRestrk1Eta[MAX_XB];
    Float_t DRestrk2Eta[MAX_XB];
	Float_t Dtrk1Dxy[MAX_XB];
	Float_t Dtrk1D0Err[MAX_XB];
	Float_t DRestrk1Dxy[MAX_XB];
	Float_t DRestrk1D0Err[MAX_XB];
	Float_t DRestrk2Dxy[MAX_XB];
	Float_t DRestrk2D0Err[MAX_XB];
	Float_t Dalpha[MAX_XB];
	Float_t DtktkRes_alpha[MAX_XB];
	Float_t DtktkRes_alphaToSV[MAX_XB];
	Float_t DtktkRes_angleToTrk1[MAX_XB];
	Float_t DtktkRes_unfitted_angleToTrk1[MAX_XB];
	Float_t DsvpvDistance[MAX_XB];
	Float_t DsvpvDisErr[MAX_XB];
	Float_t DtktkRes_svpvDistance[MAX_XB];
	Float_t DtktkRes_svpvDisErr[MAX_XB];
	Float_t DtktkRes_ptAsymToTrk1[MAX_XB];
	Float_t DtktkRes_unfitter_ptAsymToTrk1[MAX_XB];
    Float_t Dtrk1thetastar[MAX_XB];
    Float_t DRestrk1thetastar[MAX_XB];
    Float_t DRestrk2thetastar[MAX_XB];
    Float_t Dtrk1thetastar_uf[MAX_XB];
    Float_t DRestrk1thetastar_uf[MAX_XB];
    Float_t DRestrk2thetastar_uf[MAX_XB];
    Float_t Ddca[MAX_XB];
    Float_t DtktkRes_dca[MAX_XB];
    Float_t DtktkRes_dcaToSV[MAX_XB];
	Float_t DtktkRespt[MAX_XB];
	Float_t DtktkRes_unfitted_pt[MAX_XB];
	Float_t Dchi2cl[MAX_XB];
	Float_t DtktkRes_chi2cl[MAX_XB];
	t->SetBranchAddress("Dsize", &Dsize);
	t->SetBranchAddress("Dtrk1Pt", Dtrk1Pt);
	t->SetBranchAddress("DRestrk1Pt", DRestrk1Pt);
	t->SetBranchAddress("DRestrk2Pt", DRestrk2Pt);
	t->SetBranchAddress("Dtrk1Eta", Dtrk1Eta);
	t->SetBranchAddress("DRestrk1Eta", DRestrk1Eta);
	t->SetBranchAddress("DRestrk2Eta", DRestrk2Eta);
	t->SetBranchAddress("Dtrk1Dxy", Dtrk1Dxy);
	t->SetBranchAddress("Dtrk1D0Err", Dtrk1D0Err);
	t->SetBranchAddress("DRestrk1Dxy", DRestrk1Dxy);
	t->SetBranchAddress("DRestrk1D0Err", DRestrk1D0Err);
	t->SetBranchAddress("DRestrk2Dxy", DRestrk2Dxy);
	t->SetBranchAddress("DRestrk2D0Err", DRestrk2D0Err);
	t->SetBranchAddress("Dalpha", Dalpha);
	t->SetBranchAddress("DtktkRes_alpha", DtktkRes_alpha);
	t->SetBranchAddress("DtktkRes_alphaToSV", DtktkRes_alphaToSV);
	t->SetBranchAddress("DtktkRes_angleToTrk1", DtktkRes_angleToTrk1);
	t->SetBranchAddress("DtktkRes_unfitted_angleToTrk1", DtktkRes_unfitted_angleToTrk1);
	t->SetBranchAddress("DsvpvDistance", DsvpvDistance);
	t->SetBranchAddress("DsvpvDisErr", DsvpvDisErr);
	t->SetBranchAddress("DtktkRes_svpvDistance", DtktkRes_svpvDistance);
	t->SetBranchAddress("DtktkRes_svpvDisErr", DtktkRes_svpvDisErr);
	t->SetBranchAddress("DtktkRes_ptAsymToTrk1", DtktkRes_ptAsymToTrk1);
	t->SetBranchAddress("DtktkRes_unfitter_ptAsymToTrk1", DtktkRes_unfitter_ptAsymToTrk1);
	t->SetBranchAddress("Dtrk1thetastar", Dtrk1thetastar);
	t->SetBranchAddress("DRestrk1thetastar", DRestrk1thetastar);
	t->SetBranchAddress("DRestrk2thetastar", DRestrk2thetastar);
	t->SetBranchAddress("Dtrk1thetastar_uf", Dtrk1thetastar_uf);
	t->SetBranchAddress("DRestrk1thetastar_uf", DRestrk1thetastar_uf);
	t->SetBranchAddress("DRestrk2thetastar_uf", DRestrk2thetastar_uf);
	t->SetBranchAddress("Ddca", Ddca);
	t->SetBranchAddress("DtktkRes_dca", DtktkRes_dca);
	t->SetBranchAddress("DtktkRes_dcaToSV", DtktkRes_dcaToSV);
	t->SetBranchAddress("DtktkRespt", DtktkRespt);
	t->SetBranchAddress("DtktkRes_unfitted_pt", DtktkRes_unfitted_pt);
	t->SetBranchAddress("Dchi2cl", Dchi2cl);
	t->SetBranchAddress("DtktkRes_chi2cl", DtktkRes_chi2cl);

	// Declare the TMVA reader
	TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );
	TString weightfile = Form("../myTMVA/dataset/weights/TMVA_%s_%s_%.0f_%.0f_varStage%d.weights.xml",mvatype.c_str(),colsys.c_str(),ptmin,ptmax,varStage);
	TString methodName = Form("%s method",mvatype.c_str());
	Float_t __Dtrk1Pt;
	Float_t __DRestrk1Pt;
	Float_t __DRestrk2Pt;
	Float_t __Dtrk1Eta;
    Float_t __DRestrk1Eta;
    Float_t __DRestrk2Eta;
	Float_t __Dtrk1Dxy_Over_Dtrk1D0Err;
	Float_t __DRestrk1Dxy_Over_DRestrk1D0Err;
	Float_t __DRestrk2Dxy_Over_DRestrk2D0Err;
	Float_t __Dalpha;
	Float_t __DtktkRes_alpha;
	Float_t __DtktkRes_alphaToSV;
	Float_t __DtktkRes_angleToTrk1;
	Float_t __DtktkRes_unfitted_angleToTrk1;
	Float_t __DsvpvDistance_Over_DsvpvDisErr;
	Float_t __DtktkRes_svpvDistance_Over_DtktkRes_svpvDisErr;
	Float_t __DtktkRes_ptAsymToTrk1;
	Float_t __DtktkRes_unfitter_ptAsymToTrk1;
    Float_t __Dtrk1thetastar;
    Float_t __DRestrk1thetastar;
    Float_t __DRestrk2thetastar;
    Float_t __Dtrk1thetastar_uf;
    Float_t __DRestrk1thetastar_uf;
    Float_t __DRestrk2thetastar_uf;
    Float_t __Ddca;
    Float_t __DtktkRes_dca;
    Float_t __DtktkRes_dcaToSV;
	Float_t __DtktkRespt;
	Float_t __DtktkRes_unfitted_pt;
	Float_t __Dchi2cl;
	Float_t __DtktkRes_chi2cl;
	if(varStage>=1){
		reader->AddVariable("Dtrk1Pt",                                   &__Dtrk1Pt);
		reader->AddVariable("DRestrk1Pt",                                &__DRestrk1Pt);
		reader->AddVariable("DRestrk2Pt",                                &__DRestrk2Pt);
	}
	if(varStage>=2){
		reader->AddVariable("Dtrk1Dxy/Dtrk1D0Err",                       &__Dtrk1Dxy_Over_Dtrk1D0Err);
		reader->AddVariable("DRestrk1Dxy/DRestrk1D0Err",                 &__DRestrk1Dxy_Over_DRestrk1D0Err);
		reader->AddVariable("DRestrk2Dxy/DRestrk2D0Err",                 &__DRestrk2Dxy_Over_DRestrk2D0Err);
	}
	if(varStage>=3){
		reader->AddVariable("Dalpha",                                    &__Dalpha);
		reader->AddVariable("DtktkRes_alpha",                            &__DtktkRes_alpha);
		reader->AddVariable("DtktkRes_alphaToSV",                        &__DtktkRes_alphaToSV);
	}
	if(varStage>=4){
		reader->AddVariable("Dtrk1Eta",                                  &__Dtrk1Eta);
		reader->AddVariable("DRestrk1Eta",                               &__DRestrk1Eta);
		reader->AddVariable("DRestrk2Eta",                               &__DRestrk2Eta);
	}
	if(varStage>=5){
		//reader->AddVariable("DtktkRes_angleToTrk1",                      &__DtktkRes_angleToTrk1);
		reader->AddVariable("DtktkRes_unfitted_angleToTrk1",               &__DtktkRes_unfitted_angleToTrk1);
	}
	if(varStage>=6){
		//reader->AddVariable("Dtrk1thetastar",                            &__Dtrk1thetastar);
		//reader->AddVariable("DRestrk1thetastar",                         &__DRestrk1thetastar);
		//reader->AddVariable("DRestrk2thetastar",                         &__DRestrk2thetastar);
		reader->AddVariable("Dtrk1thetastar_uf",                           &__Dtrk1thetastar_uf);
		reader->AddVariable("DRestrk1thetastar_uf",                        &__DRestrk1thetastar_uf);
		reader->AddVariable("DRestrk2thetastar_uf",                        &__DRestrk2thetastar_uf);
	}
	if(varStage>=7){
		//reader->AddVariable("DtktkRes_ptAsymToTrk1",                     &__DtktkRes_ptAsymToTrk1);
		reader->AddVariable("DtktkRes_unfitter_ptAsymToTrk1",            &__DtktkRes_unfitter_ptAsymToTrk1);
	}
	if(varStage>=8){
		//reader->AddVariable("DtktkRespt",                                &__DtktkRespt);
		reader->AddVariable("DtktkRes_unfitted_pt",                      &__DtktkRes_unfitted_pt);
	}
	if(varStage>=9){
		reader->AddVariable("DsvpvDistance/DsvpvDisErr",                 &__DsvpvDistance_Over_DsvpvDisErr);
		reader->AddVariable("DtktkRes_svpvDistance/DtktkRes_svpvDisErr", &__DtktkRes_svpvDistance_Over_DtktkRes_svpvDisErr);
	}
	if(varStage>=10){
		reader->AddVariable("Ddca",                                      &__Ddca);
		reader->AddVariable("DtktkRes_dca",                              &__DtktkRes_dca);
		reader->AddVariable("DtktkRes_dcaToSV",                          &__DtktkRes_dcaToSV);
	}
	if(varStage>=11){
		reader->AddVariable("Dchi2cl",                                   &__Dchi2cl);
		reader->AddVariable("DtktkRes_chi2cl",                           &__DtktkRes_chi2cl);
	}
	reader->BookMVA( methodName, weightfile );	

	TFile *outf = new TFile(ofname,"recreate");

	string varname = Form("%sStage%d_pt%.0fto%.0f",mvatype.c_str(),varStage,ptmin,ptmax);
	TTree *mvaTree = new TTree(varname.c_str(),varname.c_str());
	float MVAVal[MAX_XB];
	mvaTree->Branch("Dsize",&Dsize,"Dsize/I");
	mvaTree->Branch(varname.c_str(),  MVAVal,  Form("%s[Dsize]/F",varname.c_str()));
	for(int i=0;i<t->GetEntries();i++)
	{
		t->GetEntry(i);
		if(i%1000000==0) cout <<i<<" / "<<t->GetEntries()<<endl;
		for(int j=0;j<Dsize;j++)
		{
			__Dtrk1Pt                                        = Dtrk1Pt[j];
			__DRestrk1Pt                                     = DRestrk1Pt[j];
			__DRestrk2Pt                                     = DRestrk2Pt[j];
			__Dtrk1Eta                                       = Dtrk1Eta[j];
			__DRestrk1Eta                                    = DRestrk1Eta[j];
			__DRestrk2Eta                                    = DRestrk2Eta[j];
			__Dtrk1Dxy_Over_Dtrk1D0Err                       = Dtrk1Dxy[j]/Dtrk1D0Err[j];
			__DRestrk1Dxy_Over_DRestrk1D0Err                 = DRestrk1Dxy[j]/DRestrk1D0Err[j];
			__DRestrk2Dxy_Over_DRestrk2D0Err                 = DRestrk2Dxy[j]/DRestrk2D0Err[j];
			__Dalpha                                         = Dalpha[j];
			__DtktkRes_alpha                                 = DtktkRes_alpha[j];
			__DtktkRes_alphaToSV                             = DtktkRes_alphaToSV[j];
			__DtktkRes_angleToTrk1                           = DtktkRes_angleToTrk1[j];
			__DtktkRes_unfitted_angleToTrk1                  = DtktkRes_unfitted_angleToTrk1[j];
			__DsvpvDistance_Over_DsvpvDisErr                 = DsvpvDistance[j]/DsvpvDisErr[j];
			__DtktkRes_svpvDistance_Over_DtktkRes_svpvDisErr = DtktkRes_svpvDistance[j]/DtktkRes_svpvDisErr[j];
			__DtktkRes_ptAsymToTrk1                          = DtktkRes_ptAsymToTrk1[j];
			__DtktkRes_unfitter_ptAsymToTrk1                 = DtktkRes_unfitter_ptAsymToTrk1[j];
			__Dtrk1thetastar                                 = Dtrk1thetastar[j];
			__DRestrk1thetastar                              = DRestrk1thetastar[j];
			__DRestrk2thetastar                              = DRestrk2thetastar[j];
			__Dtrk1thetastar_uf                              = Dtrk1thetastar_uf[j];
			__DRestrk1thetastar_uf                           = DRestrk1thetastar_uf[j];
			__DRestrk2thetastar_uf                           = DRestrk2thetastar_uf[j];
			__Ddca                                           = Ddca[j];
			__DtktkRes_dca                                   = DtktkRes_dca[j];
			__DtktkRes_dcaToSV                               = DtktkRes_dcaToSV[j];
			__DtktkRespt                                     = DtktkRespt[j];
			__DtktkRes_unfitted_pt                           = DtktkRes_unfitted_pt[j];
			__Dchi2cl                                        = Dchi2cl[j];
			__DtktkRes_chi2cl                                = DtktkRes_chi2cl[j];
			MVAVal[j] = reader->EvaluateMVA(methodName);
		}
		mvaTree->Fill();
	}
	outf->cd();
	outf->Write();
	outf->Close();
}
