using namespace std;
#include "uti.h"
#include "Tools.h"
#include "../prefilter.h"

const int NmaxFonll = 401; //fonll data points number
float central[NmaxFonll],pt[NmaxFonll];
int Nsigma = 2;
float raa;

TString cuts;
TString cutb;
TString cutg;
TString evtweight="1";
//TString evtweight="pthatweight";
//TString hltPrescale="((DtktkRespt>8&&DtktkRespt<15)*1/(9.740888e+01)+(DtktkRespt>15&&DtktkRespt<20)*1/(2.594206e+01)+(DtktkRespt>20&&DtktkRespt<30)*1/(8.305474e+00)+(DtktkRespt>30&&DtktkRespt<50)*1/(4.070169e+00)+(DtktkRespt>50)*1/(1))";
TString hltPrescale="1";

void readxml_testcompare(TString inputSname="", TString inputBname="", TString inputMVAname="",
		Int_t pbpb=0, TString mva="BDT", int stage=1, Float_t ptMin=7., Float_t ptMax=10., Float_t RAA=1.)
{
//	inputSname = "../test/ntB_pp_MC.root";
//	inputBname = "../../TMVA_BtoD_BDT-5to7-2to5/test/ntB_pp_Data.root";
//	inputMVAname = "../myTMVA/ROOT/TMVA_pp_5_7_varStage2.root";
//	inputSname = "../../TMVA_BtoD_BDT-5to7-2to5-noweight/test/ntB_pp_MC.root";
//	inputBname = "../../TMVA_BtoD_BDT-5to7-2to5-noweight/test/ntB_pp_Data.root";
//	inputMVAname = "../../TMVA_BtoD_BDT-5to7-2to5-noweight/myTMVA/ROOT/TMVA_pp_5_7_varStage2.root";
	inputSname = "../../TMVA_BtoD_BDT-5to7-2to5-noweight-block/test/ntB_pp_MC.root";
	inputBname = "../../TMVA_BtoD_BDT-5to7-2to5-noweight-block/test/ntB_pp_Data.root";
	inputMVAname = "../../TMVA_BtoD_BDT-5to7-2to5-noweight-block/myTMVA/ROOT/TMVA_pp_5_7_varStage2.root";
	ptMin = 5;
	ptMax = 7;
	stage = 2;

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

	void calRatio(TTree* signal, TTree* background, TTree* generated, Float_t* results, Bool_t verbose=false);
	ptmin = ptMin;
	ptmax = ptMax;
	isPbPb = (bool)pbpb;
	MVAtype = (TString)mva;
	raa = isPbPb?RAA:1.;
	mycuts = isPbPb?mycuts_PP:mycuts_pp;
	mycutb = isPbPb?mycutb_PP:mycutb_pp;
	mycutg = isPbPb?mycutg_PP:mycutg_pp;
	colsyst = isPbPb?"PbPb":"pp";

	cuts = isPbPb?Form("(%s)&&Dpt>%f&&Dpt<%f&&hiBin>=0&&hiBin<=200",mycuts.Data(),ptmin,ptmax):Form("(%s)&&Dpt>%f&&Dpt<%f",mycuts.Data(),ptmin,ptmax);
	cutb = isPbPb?Form("(%s)&&Dpt>%f&&Dpt<%f&&hiBin>=0&&hiBin<=200",mycutb.Data(),ptmin,ptmax):Form("(%s)&&Dpt>%f&&Dpt<%f",mycutb.Data(),ptmin,ptmax);
	cutg = isPbPb?Form("(%s)&&Gpt>%f&&Gpt<%f&&hiBin>=0&&hiBin<=200",mycutg.Data(),ptmin,ptmax):Form("(%s)&&Gpt>%f&&Gpt<%f",mycutg.Data(),ptmin,ptmax);

	TLatex* texPar = new TLatex(0.18,0.93, Form("%s 5.02 TeV B^{+}",colsyst.Data()));
	texPar->SetNDC();
	texPar->SetTextAlign(12);
	texPar->SetTextSize(0.04);
	texPar->SetTextFont(42);
	TLatex* texPtY = new TLatex(0.96,0.93, Form("|y|<1.0, %.1f<p_{T}<%.1f GeV/c",ptmin,ptmax));
	texPtY->SetNDC();
	texPtY->SetTextAlign(32);
	texPtY->SetTextSize(0.04);
	texPtY->SetTextFont(42);

	TString ptstring = Form("(%.1f,%.1f)",ptmin,ptmax);
	cout<<endl;
	cout<<" ╒══════════════════════════════════════════════════╕"<<endl;
	cout<<" |               Cut Opt Configuration              |"<<endl;
	cout<<" ├────────────┬────────────────────────────┬────────┤"<<endl;
	cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"Pt"<<" | "<<setiosflags(ios::left)<<setw(26)<<ptstring<<" | "<<setiosflags(ios::left)<<setw(6)<<" "<<" |"<<endl;
	cout<<" ├────────────┼────────────────────────────┼────────┤"<<endl;
	cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"Raa"<<" | "<<setiosflags(ios::left)<<setw(26)<<raa<<" | "<<setiosflags(ios::left)<<setw(6)<<" "<<" |"<<endl;
	cout<<" ╘════════════╧════════════════════════════╧════════╛"<<endl;
	cout<<endl;

	TFile *inputS = new TFile(inputSname.Data());
	TFile *inputB = new TFile(inputBname.Data());
	string mvaTreeName = Form("%sStage2_pt%.0fto%.0f", MVAtype.Data(), ptmin, ptmax);

	TTree* background = (TTree*)inputB->Get("ntBptoD0pi");
	background->AddFriend("ntHlt");
	background->AddFriend("ntHi");
	background->AddFriend("ntSkim");
	background->AddFriend(mvaTreeName.c_str());

	TTree* signal = (TTree*)inputS->Get("ntBptoD0pi");
	signal->AddFriend("ntHlt");
	signal->AddFriend("ntHi");
	signal->AddFriend("ntSkim");
	signal->AddFriend(mvaTreeName.c_str());

	TTree* generated = (TTree*)inputS->Get("ntGen");
	generated->AddFriend("ntHlt");
	generated->AddFriend("ntHi");

	//read TMVA output
	TFile *inputMVA = new TFile(inputMVAname.Data());
	TH1D* th1_effBvsS = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_effBvsS", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
	TH1D* th1_effS = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_trainingEffS", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
	TH1D* th1_effB = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_trainingEffB", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
	TH1D* th1_S = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_Train_S", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
	TH1D* th1_B = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_Train_B", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));

//	const Int_t nBDT = 50+1;//
	const Int_t nBDT = 40+1;//
//	Float_t minBDT = -1;//
//	Float_t maxBDT = 1;//
    Float_t minBDT = th1_B->GetBinCenter(1)-(th1_B->GetBinWidth(1)/2);
    Float_t maxBDT = th1_B->GetBinCenter(40)+(th1_B->GetBinWidth(40)/2);
	if(MVAtype=="MLP"){minBDT = -0.8; maxBDT = 1.2;}
	Float_t widBDT = (maxBDT-minBDT)/(nBDT-1);
	//Float_t limBDTmin = -2;//
	//Float_t limBDTmax = 2;//
	Float_t limBDTmin = minBDT-1;//
	Float_t limBDTmax = maxBDT+1;//
	Float_t gbdtBins[nBDT+1];
	Float_t bdtBins[nBDT+3];
	bdtBins[0] = limBDTmin;
	for(int i=0;i<=nBDT;i++)
	{
		Float_t iBDT = minBDT+i*widBDT;
		gbdtBins[i] = iBDT;
		bdtBins[i+1] = iBDT;
	}
	bdtBins[nBDT+2] = limBDTmax;

	TH1F* hcountEffS = new TH1F("hcountEffS",Form(";%s;Signal counts",MVAtype.Data()),nBDT+2,bdtBins);
	TH1F* hcountEffB = new TH1F("hcountEffB",Form(";%s;Background counts",MVAtype.Data()),nBDT+2,bdtBins);
//	signal->Project("hcountEffS",mvaTreeName.c_str(),Form("%s*(%s)",evtweight.Data(),cuts.Data()));
//	background->Project("hcountEffB",mvaTreeName.c_str(),Form("%s",cutb.Data()));
	signal->Project("hcountEffS",mvaTreeName.c_str(),Form("%s*(%s)",evtweight.Data(),cuts.Data()),"",561290);
	background->Project("hcountEffB",mvaTreeName.c_str(),Form("%s",cutb.Data()),"",4161780);
	cout<<"Sig count: "<<hcountEffS->Integral()<<endl;
	cout<<"BG count: "<<hcountEffB->Integral()<<endl;
	TCanvas* chcountEffS = new TCanvas("chcountEffS","",600,600);
	hcountEffS->Scale(1/hcountEffS->Integral());
	hcountEffS->Draw("hist");
//    th1_S->SetLineColor(kRed);
    th1_S->SetLineColor(kBlack);
    th1_S->SetFillStyle(3004);
    th1_S->SetFillColor(kRed);
    th1_S->SetLineWidth(3);
	th1_S->Scale(hcountEffS->GetMaximum()/th1_S->GetMaximum());
	th1_S->Draw("same hist");
	chcountEffS->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_chcountEffS.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));
	TCanvas* chcountEffB = new TCanvas("chcountEffB","",600,600);
	hcountEffB->Scale(1/hcountEffB->Integral());
	hcountEffB->Draw("hist");
//	th1_B->SetLineColor(kBlue+1);
	th1_B->SetLineColor(kBlack);
	th1_B->SetFillStyle(1001);
	th1_B->SetFillColor(kBlue-9);
	th1_B->SetLineWidth(3);
	th1_B->Scale(hcountEffB->GetMaximum()/th1_B->GetMaximum());
	th1_B->Draw("same hist");
	chcountEffB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_chcountEffB.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));

	TH1F* hdisEffS = (TH1F*)hcountEffS->Clone("hdisEffS");
	hdisEffS->Scale(1./hcountEffS->Integral());
	hdisEffS->SetLineColor(kRed);
	hdisEffS->SetFillStyle(3004);
	hdisEffS->SetFillColor(kRed);
	hdisEffS->SetLineWidth(3);
	hdisEffS->SetStats(0);
	TH1F* hdisEffB = (TH1F*)hcountEffB->Clone("hdisEffB");
	hdisEffB->Scale(1./hcountEffB->Integral());
	hdisEffB->SetLineColor(kBlue+1);
	hdisEffB->SetFillStyle(1001);
	hdisEffB->SetFillColor(kBlue-9);
	hdisEffB->SetLineWidth(3);
	hdisEffB->SetStats(0);

	TH2F* hemptydis = new TH2F("hemptydis","",50,minBDT-0.2,maxBDT+0.2,10,0.,max(hdisEffB->GetMaximum(),hdisEffS->GetMaximum())*1.2);
	hemptydis->GetXaxis()->CenterTitle();
	hemptydis->GetYaxis()->CenterTitle();
	hemptydis->GetXaxis()->SetTitle(MVAtype);
	hemptydis->GetYaxis()->SetTitle("Probability");
	hemptydis->GetXaxis()->SetTitleOffset(0.9);
	hemptydis->GetYaxis()->SetTitleOffset(1.2);
	hemptydis->GetXaxis()->SetTitleSize(0.05);
	hemptydis->GetYaxis()->SetTitleSize(0.05);
	hemptydis->GetXaxis()->SetTitleFont(42);
	hemptydis->GetYaxis()->SetTitleFont(42);
	hemptydis->GetXaxis()->SetLabelFont(42);
	hemptydis->GetYaxis()->SetLabelFont(42);
	hemptydis->GetXaxis()->SetLabelSize(0.035);
	hemptydis->GetYaxis()->SetLabelSize(0.035);
	TCanvas* cdisEffSB = new TCanvas("cdisEffSB","",600,600);
	hemptydis->Draw();
	hdisEffB->Draw("same hist");
	hdisEffS->Draw("same hist");
	th1_S->Draw("same hist");
	th1_B->Draw("same hist");
	TLegend* leg = new TLegend(0.60,0.75,0.95,0.86);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->AddEntry(hdisEffB,"Background","f");
	leg->AddEntry(hdisEffS,"Signal","f");
	leg->Draw("same");
	texPar->Draw();
	texPtY->Draw();
	cdisEffSB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_disEffSB.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));

	Float_t allS=0,allB=0;
	Float_t effS[nBDT],effB[nBDT],effSig[nBDT];
	for(int i=0;i<nBDT;i++)
	{
		effS[i] = 0;
		effB[i] = 0;
	}
	for(int i=0;i<(nBDT+2);i++)
	{
		allS+=hcountEffS->GetBinContent(i+1);
		allB+=hcountEffB->GetBinContent(i+1);
		if(i==0) continue;
		for(int j=0;j<i;j++)
		{
			if(j<nBDT)
			{
				effS[j]+=hcountEffS->GetBinContent(i+1);
				effB[j]+=hcountEffB->GetBinContent(i+1);
			}
		}
	}
	for(int i=0;i<nBDT;i++)
	{
		effS[i]/=allS;
		effB[i]/=allB;
	}

	TH2F* hemptyeff = new TH2F("hemptyeff","",50,minBDT-0.2,maxBDT+0.2,10,0.,1.2);
	hemptyeff->GetXaxis()->CenterTitle();
	hemptyeff->GetYaxis()->CenterTitle();
	hemptyeff->GetXaxis()->SetTitle(MVAtype);
	hemptyeff->GetYaxis()->SetTitle("Efficiency");
	hemptyeff->GetXaxis()->SetTitleOffset(0.9);
	hemptyeff->GetYaxis()->SetTitleOffset(1.0);
	hemptyeff->GetXaxis()->SetTitleSize(0.05);
	hemptyeff->GetYaxis()->SetTitleSize(0.05);
	hemptyeff->GetXaxis()->SetTitleFont(42);
	hemptyeff->GetYaxis()->SetTitleFont(42);
	hemptyeff->GetXaxis()->SetLabelFont(42);
	hemptyeff->GetYaxis()->SetLabelFont(42);
	hemptyeff->GetXaxis()->SetLabelSize(0.035);
	hemptyeff->GetYaxis()->SetLabelSize(0.035);

	TGraph* geffS = new TGraph(nBDT,gbdtBins,effS);
	geffS->SetMarkerSize(1.1);
	geffS->SetMarkerColor(kRed);
	geffS->SetLineWidth(2);
	geffS->SetLineColor(kRed);
	TGraph* geffB = new TGraph(nBDT,gbdtBins,effB);
	geffB->SetMarkerSize(1.1);
	geffB->SetMarkerColor(kBlue+1);
	geffB->SetLineWidth(2);
	geffB->SetLineColor(kBlue+1);
	TCanvas* ceffSB = new TCanvas("ceffSB","",600,600);
	hemptyeff->Draw();
	texPar->Draw();
	texPtY->Draw();
	geffS->Draw("samepl");
	geffB->Draw("samepl");

	th1_effS->SetMarkerSize(1.1);
	th1_effS->SetMarkerColor(kRed);
	th1_effS->SetLineWidth(2);
	th1_effS->SetLineColor(kRed);
	th1_effS->Draw("same");
	th1_effB->SetMarkerSize(1.1);
	th1_effB->SetMarkerColor(kBlue+1);
	th1_effB->SetLineWidth(2);
	th1_effB->SetLineColor(kBlue+1);
	th1_effB->Draw("same");
	TLegend* legeff = new TLegend(0.60,0.75,0.95,0.86);
	legeff->SetBorderSize(0);
	legeff->SetFillStyle(0);
	legeff->AddEntry(th1_effB,"Background","l");
	legeff->AddEntry(th1_effS,"Signal","l");
	legeff->Draw("same");
	ceffSB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_EffvsMVA.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));

	Float_t wSignal=0;
	Float_t wBackground=0;
	Float_t* weights = new Float_t[2];
	//
	calRatio(signal,background,generated,weights);//weight signal and background
	//

	wSignal = weights[1];
	wBackground = weights[0];

	cout<<endl;
	cout<<"Looking for max significance ..."<<endl;

	Double_t maxsig = wSignal*effS[0]/sqrt(wSignal*effS[0]+wBackground*effB[0]);
	int maxindex = 0;
	for(int i=0;i<nBDT;i++)
	{
		effSig[i] = wSignal*effS[i]/sqrt(wSignal*effS[i]+wBackground*effB[i]);
		if(effSig[i]>maxsig)
		{
			maxsig=effSig[i];
			maxindex=i;
		}
	}
	cout<<endl;
	cout<<" ╒══════════════════════════════════════════════════╕"<<endl;
	cout<<" |                     Opt Result                   |"<<endl;
	cout<<" ├────────────┬────────────┬───────────────┬────────┤"<<endl;
	cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"Sig eff"<<" | "<<setiosflags(ios::left)<<setw(10)<<effS[maxindex]<<" | "<<setiosflags(ios::left)<<setw(13)<<"S/sqrt(S+B)"<<" | "<<setiosflags(ios::left)<<setw(6)<<maxsig<<" |"<<endl;
	cout<<" ├────────────┴────────────┴───┬───────────┴────────┤"<<endl;
	cout<<" | "<<setiosflags(ios::left)<<setw(27)<<"MVA cut value"<<" | "<<setiosflags(ios::left)<<setw(18)<<(minBDT+maxindex*widBDT)<<" |"<<endl;
	cout<<" ╘═════════════════════════════╧════════════════════╛"<<endl;
	cout<<endl;
cout<<"B eff: "<<effB[maxindex]<<endl;
	TH2F* hempty = new TH2F("hempty","",50,minBDT-0.2,maxBDT+0.2,10,0.,maxsig*1.2);  
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetXaxis()->SetTitle(MVAtype);
	hempty->GetYaxis()->SetTitle("S/sqrt(S+B)");
	hempty->GetXaxis()->SetTitleOffset(0.9);
	hempty->GetYaxis()->SetTitleOffset(1.0);
	hempty->GetXaxis()->SetTitleSize(0.05);
	hempty->GetYaxis()->SetTitleSize(0.05);
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.035);
	hempty->GetYaxis()->SetLabelSize(0.035);

	int _maxsigbin = 0;
	float _maxsigval = 0;
	float _sigval = 0;
	float _effb = 0;
	float _effs = 0;
	float _cutval = -999;
	const int _bins = 10000;
	float _sigval_arr[_bins];
	float _cutval_arr[_bins];
	if(_bins<th1_effS->GetNbinsX()) cout<<"Warning: efficiency bins not enough"<<endl;
	for(int e=1; e<=min(th1_effS->GetNbinsX(),_bins); e++){
		_effs = th1_effS->GetBinContent(e);
		_effb = th1_effB->GetBinContent(e);
		_sigval = wSignal*_effs/sqrt(wSignal*_effs+wBackground*_effb);
		_sigval_arr[e-1] = _sigval;
		_cutval_arr[e-1] = th1_effS->GetBinCenter(e);
        if(_sigval>_maxsigval)
        {
			_maxsigval=_sigval;
			_maxsigbin=e;
			_cutval=_cutval_arr[e];
        }
	}	
	_effs = th1_effS->GetBinContent(_maxsigbin);
	_effb = th1_effB->GetBinContent(_maxsigbin);
	cout<<"significance: "<<_maxsigval<<endl;
	cout<<"effb: "<<_effb<<endl;
	cout<<"effs: "<<_effs<<endl;
	cout<<"cutval: "<<_cutval<<endl;

	TGraph* gsig = new TGraph(nBDT,gbdtBins,effSig);
	TCanvas* csig = new TCanvas("csig","",600,600);
	hempty->Draw();
	texPar->Draw();
	texPtY->Draw();
	gsig->Draw("same*");
	TGraph* _gsig = new TGraph(th1_effS->GetNbinsX(),_cutval_arr,_sigval_arr);
	_gsig->Draw("same");
	csig->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_Significance.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));
}

void calRatio(TTree* signal, TTree* background, TTree* generated, Float_t* results, Bool_t verbose=false)
{
	TString sels = cuts;
	TString selb = cutb;
	TString selg = cutg;

	//Background candidate number
	TH1D* hmassB = new TH1D("hmassB",";B mass (GeV/c^{2});Background Entries",50,5,6);
	background->Project("hmassB","Dmass",selb);
	TCanvas* cmassB = new TCanvas("cmassB","",600,600);
	hmassB->Draw();
	cmassB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_Background.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));
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
	cfonll->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_Fonll.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));

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
	ceff->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_EffPrefilter.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));

	TH1D* htheoryreco = new TH1D("htheoryreco","",nbin-1,pt);
	htheoryreco->Multiply(heff,hfonll,1,1,"B");

	//use lumi//
	Double_t lumi = isPbPb?lum_PP:lum_pp;
	Double_t BR = 1.8864e-4;//4.8e-3*3.93e-2
	Double_t deltapt = 0.25;
	//central[i] - in pb/GeV/c

	Double_t yieldDzero = htheoryreco->Integral();
	yieldDzero*=BR*deltapt*lumi*raa*2*0.401;// need to consider HLT prescale


	results[0] = nentriesB*0.08/0.3*2;// *2 since for BtoD sideband is only on 1 side
	results[1] = yieldDzero;
	cout<<endl;
	cout<<" ╒══════════════════════════════════════════════════╕"<<endl;
	cout<<" |                   Weight Result                  |"<<endl;
	cout<<" ├────────────┬────────────┬────────────┬───────────┤"<<endl;
	cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"Bkg #"<<" | "<<setiosflags(ios::left)<<setw(10)<<nentriesB<<" | "<<setiosflags(ios::left)<<setw(10)<<"Sig reg"<<" | "<<setiosflags(ios::left)<<setw(9)<<setprecision(3)<<0.16<<" |"<<endl;
	cout<<" ├────────────┼────────────┼────────────┼───────────┤"<<endl;
	cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"SigWeight"<<" | "<<setiosflags(ios::left)<<setw(10)<<yieldDzero<<" | "<<setiosflags(ios::left)<<setw(10)<<"BkgWeight"<<" | "<<setiosflags(ios::left)<<setw(9)<<results[0]<<" |"<<endl;
	cout<<" ╘════════════╧════════════╧════════════╧═══════════╛"<<endl;
}
