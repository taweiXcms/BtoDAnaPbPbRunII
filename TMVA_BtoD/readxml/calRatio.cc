#include "uti.h"
#include "Tools.h"
#include "../prefilter.h"
const int NmaxFonll = 401; //fonll data points number
float central[NmaxFonll],pt[NmaxFonll];

TString cuts;
TString cutb;
TString cutg;
TString evtweight="1";
//TString evtweight="pthatweight";
//TString hltPrescale="((DtktkRespt>8&&DtktkRespt<15)*1/(9.740888e+01)+(DtktkRespt>15&&DtktkRespt<20)*1/(2.594206e+01)+(DtktkRespt>20&&DtktkRespt<30)*1/(8.305474e+00)+(DtktkRespt>30&&DtktkRespt<50)*1/(4.070169e+00)+(DtktkRespt>50)*1/(1))";
TString hltPrescale="1";

void calRatio(TString inputSname="", TString inputBname="", Int_t pbpb=0, TString mva="BDT", Float_t ptMin=5., Float_t ptMax=7., Float_t RAA=1., TString predfname="pp_pT_5_7.h")
{
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	gStyle->SetEndErrorSize(0);
	gStyle->SetMarkerStyle(20);
	gStyle->SetTextSize(0.05);
	gStyle->SetTextFont(42);
	gStyle->SetPadRightMargin(0.043);
	gStyle->SetPadLeftMargin(0.18);
	gStyle->SetPadTopMargin(0.1);
	gStyle->SetPadBottomMargin(0.145);
	gStyle->SetTitleX(.0f);

	ptmin = ptMin;
	ptmax = ptMax;
	isPbPb = (bool)pbpb;
	RAA = isPbPb?RAA:1.;
	colsyst = isPbPb?"PbPb":"pp";
	mycuts = isPbPb?mycuts_PP:mycuts_pp;
	mycutb = isPbPb?mycutb_PP:mycutb_pp;
	mycutg = isPbPb?mycutg_PP:mycutg_pp;
	cuts = isPbPb?Form("(%s)&&Dpt>%f&&Dpt<%f&&hiBin>=0&&hiBin<=200",mycuts.Data(),ptmin,ptmax):Form("(%s)&&Dpt>%f&&Dpt<%f",mycuts.Data(),ptmin,ptmax);
	cutb = isPbPb?Form("(%s)&&Dpt>%f&&Dpt<%f&&hiBin>=0&&hiBin<=200",mycutb.Data(),ptmin,ptmax):Form("(%s)&&Dpt>%f&&Dpt<%f",mycutb.Data(),ptmin,ptmax);
	cutg = isPbPb?Form("(%s)&&Gpt>%f&&Gpt<%f&&hiBin>=0&&hiBin<=200",mycutg.Data(),ptmin,ptmax):Form("(%s)&&Gpt>%f&&Gpt<%f",mycutg.Data(),ptmin,ptmax);

	//TString inputSname = Form("../test/ntB_pp_MC.root");
	//TString inputBname = Form("../test/ntB_pp_Data.root");
	TFile *inputS = new TFile(inputSname.Data());
	TFile *inputB = new TFile(inputBname.Data());
	TTree* background = (TTree*)inputB->Get("ntBptoD0pi");
	background->AddFriend("ntHlt");
	background->AddFriend("ntHi");
	background->AddFriend("ntSkim");
	TTree* signal = (TTree*)inputS->Get("ntBptoD0pi");
	signal->AddFriend("ntHlt");
	signal->AddFriend("ntHi");
	signal->AddFriend("ntSkim");
	TTree* generated = (TTree*)inputS->Get("ntGen");
	generated->AddFriend("ntHlt");
	generated->AddFriend("ntHi");
	//Background candidate number
	TH1D* hmassB = new TH1D("hmassB",";B mass (GeV/c^{2});Background Entries",50,5,6);
	background->Project("hmassB","Dmass",cutb);
	TCanvas* cmassB = new TCanvas("cmassB","",600,600);
	hmassB->Draw();
	cmassB->SaveAs(Form("plots/%s_pT_%.0f_%.0f_Background.pdf",colsyst.Data(),ptmin,ptmax));
	Int_t nentriesB = hmassB->Integral();

	//FONLL
	//
	//ifstream getdata("fonlls/fo_pp_Bplus_5p03TeV_y2p4.dat");
	ifstream getdata("fonlls/fo_pp_Bplus_5p03TeV_y1p0.dat");
	if(!getdata.is_open()) cout<<"Opening the file fails"<<endl;
	Float_t tem;
	Int_t nbin=0;
	while (!getdata.eof())
	{
		getdata>>pt[nbin]>>central[nbin]>>tem>>tem>>tem>>tem>>tem>>tem>>tem>>tem;
		if(pt[nbin]>=ptmin&&pt[nbin]<=ptmax) nbin++;
	}
	TH1D* hfonll = new TH1D("hfonll",";B p_{T} (GeV/c);FONLL differential xsection",nbin-1,pt);
	for(int i=0;i<nbin;i++)
	{
		hfonll->SetBinContent(i,central[i]);
	}
	TCanvas* cfonll = new TCanvas("cfonll","",600,600);
	hfonll->Draw();
	cfonll->SaveAs(Form("plots/%s_pT_%.0f_%.0f_Fonll.pdf",colsyst.Data(),ptmin,ptmax));

	TH1D* hrec = new TH1D("hrec",";B p_{T} (GeV/c);Signal reco entries",nbin-1,pt);
	TH1D* hgen = new TH1D("hgen",";B p_{T} (GeV/c);Generated entries",nbin-1,pt);
	TH1D* heff = new TH1D("heff",";B p_{T} (GeV/c);Prefilter efficiency",nbin-1,pt);
	if(isPbPb) signal->Project("hrec","Dpt",Form("%s*(%s&&hiBin>=0&&hiBin<=200)*(%s)",evtweight.Data(),mycuts.Data(),hltPrescale.Data()));
	else signal->Project("hrec","Dpt",Form("%s*(%s)*(%s)",evtweight.Data(),mycuts.Data(),hltPrescale.Data()));
	if(isPbPb) generated->Project("hgen","Gpt",Form("%s*(%s&&hiBin>=0&&hiBin<=200)",evtweight.Data(),mycutg.Data()));
	else generated->Project("hgen","Gpt",Form("%s*(%s)",evtweight.Data(),mycutg.Data()));

	heff->Divide(hrec,hgen,1.,1.,"B");
	TCanvas* ceff = new TCanvas("ceff","",600,600);
	heff->Draw();
	ceff->SaveAs(Form("plots/%s_pT_%.0f_%.0f_EffPrefilter.pdf",colsyst.Data(),ptmin,ptmax));

	TH1D* htheoryreco = new TH1D("htheoryreco","",nbin-1,pt);
	htheoryreco->Multiply(heff,hfonll,1,1,"B");

	//use lumi//
	Double_t lumi = isPbPb?lum_PP:lum_pp;
	Double_t BR = 1.8864e-4;//4.8e-3*3.93e-2
	Double_t deltapt = 0.25;
	//central[i] - in pb/GeV/c

	Double_t yieldDzero = htheoryreco->Integral();
	yieldDzero*=BR*deltapt*lumi*RAA*2*0.401;// need to consider HLT prescale

	Float_t* results = new Float_t[2];
	results[0] = nentriesB*0.08/0.3*2;// *2 since for BtoD sideband is only on 1 side
	results[1] = yieldDzero;
	cout<<"# of background in sideband: "<<nentriesB<<endl;
	cout<<"# of background in signal region: "<<results[0]<<endl;
	cout<<"# of predicted signal: "<<yieldDzero<<endl;
	ofstream myfile;
	myfile.open(Form("%s",predfname.Data()));
	myfile << Form("float pred_background = %f;\n",results[0]);
	myfile << Form("float pred_signal = %f;\n",results[1]);
	myfile.close();
}
