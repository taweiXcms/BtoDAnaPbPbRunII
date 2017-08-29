#include "TChain.h"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#include "listOfVar.h"
#include "fList.h"
#define MAX_XB       20000
bool isPbPb;
float ptmin;
float ptmax;
void makeoutput(TString ofname, string colsys, string mvatype, int varStage);
int nFiles = sizeof(inFileNames)/sizeof(string);

//const int nBins=2;
//float ptBins[nBins+1] = {5, 7, 10};
//float MVACutVal[nBins] = {-1, -1};
//string MVAfname[nBins] = {"TMVA_MLP_pp_5_7_varStage3.weights.xml", "TMVA_MLP_pp_7_10_varStage3.weights.xml"};
//string MVAtype[nBins] = {"MLP", "MLP"};

const int nBins=3;
float ptBins[nBins+1] = {5, 7, 10, 15};
//float MVACutVal[nBins] = {-0.045243, -0.060866, -0.063513};//efficiency all 0.1 
float MVACutVal[nBins] = {0.059537, 0.043997, 0.057870};//efficiency all 0.01 
string MVAfname[nBins] = {"TMVA_BDT_pp_5_7_varStage3.weights.xml", "TMVA_BDT_pp_7_10_varStage3.weights.xml", "TMVA_BDT_pp_10_15_varStage3.weights.xml"};
string MVAtype[nBins] = {"BDT", "BDT", "BDT"};

//const int nBins=0;
//float ptBins[nBins+1] = {0};
//float MVACutVal[nBins] = {};
//string MVAfname[nBins] = {};
//string MVAtype[nBins] = {};

void ProdMVAValAndMerge(string colsys = "pp", float ptMin = 5, float ptMax = 7, string mvatype = "MLP", int varStage = 3, TString inputS = "", TString inputB = ""){
	isPbPb = (colsys=="pp") ? 0 : 1;
	ptmin = ptMin;
	ptmax = ptMax;
//	for(int f=0; f<nFiles; f++){
//		TString outfile1 = Form("Data%d.root",f) ;
//		makeoutput(inFileNames[f].c_str(),outfile1,colsys,mvatype,varStage);
//	}
	makeoutput("DataSkimMerge.root",colsys,mvatype,varStage);
}
void addtochain(TChain* root){
    for (int i=0; i<nFiles; i++) {root->Add(inFileNames[i].c_str());}
}
void makeoutput(TString ofname, string colsys, string mvatype, int varStage){
	// Read the input tree
    TChain* nt= new TChain("ntBptoD0pi");
    TChain* ntGen = new TChain("ntGen");
    TChain* ntHlt = new TChain("ntHlt");
    TChain* ntHi = new TChain("ntHi");
    TChain* ntSkim = new TChain("ntSkim");
    addtochain(nt);
    addtochain(ntGen);
    addtochain(ntHlt);
    addtochain(ntHi);
    addtochain(ntSkim);
	readBR(nt);

	TFile *outf = new TFile(ofname,"recreate");
	TTree* nt_new = new TTree("ntBptoD0pi","ntBptoD0pi");
	buildBR(nt_new);
    TTree* ntGen_new = ntGen->CloneTree(0);
    TTree* ntHlt_new = ntHlt->CloneTree(0);
    TTree* ntHi_new = ntHi->CloneTree(0);
    TTree* ntSkim_new = ntSkim->CloneTree(0);

	// Declare the TMVA reader
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

	TMVA::Reader *reader[nBins];
	float MVAVal[3][MAX_XB];
	TTree *mvaTree = new TTree("mvaSkimTree","mvaSkimTree");
	mvaTree->Branch("Dsize",&new_Dsize,"Dsize/I");
	for(int m=0; m<nBins; m++){
		reader[m] = new TMVA::Reader( "!Color:!Silent" );
		TString weightfile = MVAfname[m];
		if(varStage>=1){
			reader[m]->AddVariable("Dtrk1Pt",                                   &__Dtrk1Pt);
			reader[m]->AddVariable("DRestrk1Pt",                                &__DRestrk1Pt);
			reader[m]->AddVariable("DRestrk2Pt",                                &__DRestrk2Pt);
		}
		if(varStage>=2){
			reader[m]->AddVariable("Dtrk1Dxy/Dtrk1D0Err",                       &__Dtrk1Dxy_Over_Dtrk1D0Err);
			reader[m]->AddVariable("DRestrk1Dxy/DRestrk1D0Err",                 &__DRestrk1Dxy_Over_DRestrk1D0Err);
			reader[m]->AddVariable("DRestrk2Dxy/DRestrk2D0Err",                 &__DRestrk2Dxy_Over_DRestrk2D0Err);
		}
		if(varStage>=3){
			reader[m]->AddVariable("Dalpha",                                    &__Dalpha);
			reader[m]->AddVariable("DtktkRes_alpha",                            &__DtktkRes_alpha);
			reader[m]->AddVariable("DtktkRes_alphaToSV",                        &__DtktkRes_alphaToSV);
		}
		if(varStage>=4){
			reader[m]->AddVariable("Dtrk1Eta",                                  &__Dtrk1Eta);
			reader[m]->AddVariable("DRestrk1Eta",                               &__DRestrk1Eta);
			reader[m]->AddVariable("DRestrk2Eta",                               &__DRestrk2Eta);
		}
		if(varStage>=5){
			//reader[m]->AddVariable("DtktkRes_angleToTrk1",                      &__DtktkRes_angleToTrk1);
			reader[m]->AddVariable("DtktkRes_unfitted_angleToTrk1",               &__DtktkRes_unfitted_angleToTrk1);
		}
		if(varStage>=6){
			//reader[m]->AddVariable("Dtrk1thetastar",                            &__Dtrk1thetastar);
			//reader[m]->AddVariable("DRestrk1thetastar",                         &__DRestrk1thetastar);
			//reader[m]->AddVariable("DRestrk2thetastar",                         &__DRestrk2thetastar);
			reader[m]->AddVariable("Dtrk1thetastar_uf",                           &__Dtrk1thetastar_uf);
			reader[m]->AddVariable("DRestrk1thetastar_uf",                        &__DRestrk1thetastar_uf);
			reader[m]->AddVariable("DRestrk2thetastar_uf",                        &__DRestrk2thetastar_uf);
		}
		if(varStage>=7){
			//reader[m]->AddVariable("DtktkRes_ptAsymToTrk1",                     &__DtktkRes_ptAsymToTrk1);
			reader[0]->AddVariable("DtktkRes_unfitter_ptAsymToTrk1",            &__DtktkRes_unfitter_ptAsymToTrk1);
		}
		if(varStage>=8){
			//reader[m]->AddVariable("DtktkRespt",                                &__DtktkRespt);
			reader[m]->AddVariable("DtktkRes_unfitted_pt",                      &__DtktkRes_unfitted_pt);
		}
		if(varStage>=9){
			reader[m]->AddVariable("DsvpvDistance/DsvpvDisErr",                 &__DsvpvDistance_Over_DsvpvDisErr);
			reader[m]->AddVariable("DtktkRes_svpvDistance/DtktkRes_svpvDisErr", &__DtktkRes_svpvDistance_Over_DtktkRes_svpvDisErr);
		}
		if(varStage>=10){
			reader[m]->AddVariable("Ddca",                                      &__Ddca);
			reader[m]->AddVariable("DtktkRes_dca",                              &__DtktkRes_dca);
			reader[m]->AddVariable("DtktkRes_dcaToSV",                          &__DtktkRes_dcaToSV);
		}
		if(varStage>=11){
			reader[m]->AddVariable("Dchi2cl",                                   &__Dchi2cl);
			reader[m]->AddVariable("DtktkRes_chi2cl",                           &__DtktkRes_chi2cl);
		}
		reader[m]->BookMVA( Form("%s method", MVAtype[m].c_str()), weightfile );	
		string varname = Form("%sStage%d_pt%.0f_%.0f",MVAtype[m].c_str(), varStage, ptBins[m], ptBins[m+1]);
		mvaTree->Branch(varname.c_str(),  MVAVal[m],  Form("%s[Dsize]/F",varname.c_str()));
	}

	bool passMVA = false;
	for(int i=0;i<nt->GetEntries();i++)
//	for(int i=0;i<1000000;i++)
	{
        nt->GetEntry(i);
        ntGen->GetEntry(i);
        ntHlt->GetEntry(i);
        ntHi->GetEntry(i);
        ntSkim->GetEntry(i);
		new_Dsize = 0;
		if(i%1000000==0) cout <<i<<" / "<<nt->GetEntries()<<endl;
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

			passMVA = true;
			for(int m=0; m<nBins; m++){
				MVAVal[m][new_Dsize] = reader[m]->EvaluateMVA(Form("%s method",MVAtype[m].c_str()));
				if(Dpt[j]>ptBins[m] && Dpt[j]<ptBins[m+1]){
					if(MVAVal[m][new_Dsize]<MVACutVal[m]) passMVA = false;
				}
				
			}
			if(passMVA){
				copyBR(new_Dsize, j);
				new_Dsize++;	
			}
		}
		mvaTree->Fill();
        nt_new->Fill();
        ntHlt_new->Fill();
        ntHi_new->Fill();
        ntSkim_new->Fill();
        ntGen_new->Fill();
	}
	outf->cd();
	outf->Write();
	outf->Close();
}
