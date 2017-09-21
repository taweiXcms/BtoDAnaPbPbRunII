#include "TFile.h"
#include "TTree.h"
#include "TH2.h"
#include "TH2.h"
#include "TCanvas.h"
void plotSth(){
	TCanvas* c = new TCanvas("c","",600,600); c->cd();
	TFile *f = new TFile("../test/ntB_pp_Data_5_7.root");
    TTree *t = (TTree*)f->Get("ntBptoD0pi");
	t->AddFriend("MLPStage5");
	string exp;
	string ptcut = "Dpt>5&&Dpt<7";
	exp = "(Dmass-5.279)>0.2&&(Dmass-5.279)<0.5";
	TH1D *mva1 = new TH1D("mva1",Form("MLP %s",exp.c_str()),100,0,1);
	t->Project("mva1 ", "MLPStage5",Form("%s&&%s",ptcut.c_str(),exp.c_str()));
	mva1->Draw();
	c->SaveAs("MVAVal1.png");

	exp = "(Dmass-5.279)>-0.1&&(Dmass-5.279)<0.1";
	mva1 = new TH1D("mva2",Form("MLP %s",exp.c_str()),100,0,1);
	t->Project("mva2 ", "MLPStage5",Form("%s&&%s",ptcut.c_str(),exp.c_str()));
	mva1->Draw();
	c->SaveAs("MVAVal2.png");

	exp = "(Dmass-5.279)<-0.1";
	mva1 = new TH1D("mva3",Form("MLP %s",exp.c_str()),100,0,1);
	t->Project("mva3 ", "MLPStage5",Form("%s&&%s",ptcut.c_str(),exp.c_str()));
	mva1->Draw();
	c->SaveAs("MVAVal3.png");

	TH2D *corr = new TH2D("corr","corr",50,5,6,100,0,1);
	t->Project("corr","MLPStage5:Dmass",Form("%s",ptcut.c_str()));
	corr->Draw("COLZ");
	c->SaveAs("MVAvsDmass.png");

	f = new TFile("../test/ntB_pp_MC_5_7.root");
    t = (TTree*)f->Get("ntBptoD0pi");
	t->AddFriend("MLPStage5");
	exp = "Dgen==23333";
	mva1 = new TH1D("mvag1",Form("MLP %s",exp.c_str()),100,0,1);
	t->Project("mvag1 ", "MLPStage5",Form("%s&&%s",ptcut.c_str(),exp.c_str()));
	mva1->Draw();
	c->SaveAs("MVAValG1.png");
	
}
