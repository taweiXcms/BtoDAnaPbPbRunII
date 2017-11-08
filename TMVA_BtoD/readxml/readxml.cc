using namespace std;
#include "uti.h"
#include "Tools.h"
#include "../prefilter.h"
#include "pred_temp.h"
int stage;
Float_t wSignal=pred_signal;
Float_t wBackground=pred_background;

void readxml(Int_t pbpb=0, TString mva="BDT", int _stage=1, Float_t ptMin=7., Float_t ptMax=10., Float_t RAA=1.)
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

	stage=_stage;
	ptmin = ptMin;
	ptmax = ptMax;
	isPbPb = (bool)pbpb;
	MVAtype = (TString)mva;
	RAA = isPbPb?RAA:1.;
	colsyst = isPbPb?"PbPb":"pp";

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

	printf("=======================================================================================================\n");
	printf("MVA type:                          %s\n",MVAtype.Data());
	printf("Pt:                                %.0f %0.f\n",ptmin,ptmax);
    printf("Stage:                             %d\n",stage);
	printf("Raa:                               %f\n", RAA);

	std::string str = MVAtype.Data();
	std::size_t found = str.find("Cuts");
	if (found!=std::string::npos){
		const int NmaxVar = 30;
		TString varval[NmaxVar];
		//read weight file
		TString fileName = Form("../myTMVA/dataset/weights/TMVA_%s_%s_%.0f_%.0f_varStage%d.weights.xml",MVAtype.Data(),colsyst.Data(),ptmin,ptmax,stage);
		const char* filename = fileName.Data();
		void *doc = TMVA::gTools().xmlengine().ParseFile(filename,TMVA::gTools().xmlenginebuffersize());
		void* rootnode = TMVA::gTools().xmlengine().DocGetRootElement(doc); // node "MethodSetup"
		TString fullMethodName(""); 
		TMVA::gTools().ReadAttr(rootnode, "Method", fullMethodName);

		void *opts = TMVA::gTools().GetChild(rootnode,"Options");
		void* opt = TMVA::gTools().GetChild(opts,"Option");

		TString varProp("");
		while (opt)
		{
			TString optname("");
			TMVA::gTools().ReadAttr(opt, "name", optname);
			if (optname=="VarProp") varProp = TMVA::gTools().GetContent(opt);
			opt = TMVA::gTools().GetNextChild(opt);
		}

		TObjArray *marginclass = varProp.Tokenize(" ");
		std::vector<TString> margins;//avoid objarrays
		for(int i=0;i<marginclass->GetEntries();i++)
		{
			margins.push_back(((TObjString *)(marginclass->At(i)))->String());
		}
		void* variables = TMVA::gTools().GetChild(rootnode,"Variables");
		unsigned int nVar=0;
		std::vector<TString> varnames;
		TMVA::gTools().ReadAttr(variables, "NVar", nVar);

		void* var = TMVA::gTools().GetChild(variables,"Variable");
		for(unsigned int k=0;k<nVar;k++)
		{
			TString varname("");
			TMVA::gTools().ReadAttr(var, "Expression", varname);
			TString tem = Form("Variable%i",k);
			varval[k] = varname;
			cout<<setiosflags(ios::left)<<setw(35)<<varname<<margins[k]<<endl;
			var = TMVA::gTools().GetNextChild(var);
			varnames.push_back(varname);
		}

		void* weight = TMVA::gTools().GetChild(rootnode,"Weights");
		void* eff = TMVA::gTools().GetChild(weight,"Bin");
		int n=0;
		const int NEff = 100;
		TString cut[NEff];
		double effS[NEff], effB[NEff],effSig[NEff],effBac[NEff];
		std::vector<Double_t> cutvalMin[NmaxVar];
		std::vector<Double_t> cutvalMax[NmaxVar];
		while(eff)
		{
			TMVA::gTools().ReadAttr(eff, "effS", effS[n]);
			TMVA::gTools().ReadAttr(eff, "effB", effB[n]);
			void* cutsnode = TMVA::gTools().GetChild(eff,"Cuts");
			cut[n] = "";
			for(unsigned long l=0;l<varnames.size();l++)
			{
				double min,max;
				TMVA::gTools().ReadAttr(cutsnode, TString("cutMin_")+l, min);
				TMVA::gTools().ReadAttr(cutsnode, TString("cutMax_")+l, max);
				cutvalMax[l].push_back(max);
				cutvalMin[l].push_back(min);
				TString lessmax = "<"; lessmax+=max;
				TString moremin = ">"; moremin+=min; 
				if(margins[l]=="FMin" || margins[l]=="NotEnforced")
				{
					cut[n]+=" && "+varnames[l]+lessmax;
				}
				if(margins[l]=="FMax" || margins[l]=="NotEnforced")
				{
					cut[n]+=" && "+varnames[l]+moremin;
				}
			}
			eff = TMVA::gTools().GetNextChild(eff);
			n++;
		}
		TMVA::gTools().xmlengine().FreeDoc(doc);

		TH2F* hemptyeff = new TH2F("hemptyeff","",100,0,1,140,-0.2,1.2);
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
		TGraph* geffS = new TGraph(100,effS,effS);
		geffS->SetMarkerSize(1.1);
		geffS->SetMarkerColor(kRed);
		geffS->SetLineWidth(2);
		geffS->SetLineColor(kRed);
		TGraph* geffB = new TGraph(100,effS,effB);
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
		TLegend* legeff = new TLegend(0.60,0.75,0.95,0.86);
		legeff->SetBorderSize(0);
		legeff->SetFillStyle(0);
		legeff->AddEntry(geffB,"Background","pl");
		legeff->AddEntry(geffS,"Signal","pl");
		legeff->Draw("same");

		double maxsig = wSignal*effS[1]/sqrt(wSignal*effS[1]+wBackground*effB[1]);
		int maxindex = 1;
		effS[0]=0;
		for(int i=1;i<100;i++)
		{
			effSig[i] = wSignal*effS[i]/sqrt(wSignal*effS[i]+wBackground*effB[i]);
			if(effB[i]<0){
				cout<<"Negative BG efficiency, set it to -1"<<endl;
				printf("effB: %f,  nBG*effB: %f, Significane: %f\n",effB[i], wBackground*effB[i], effSig[i]);
				effSig[i] = -1;
			}

			if(effSig[i]>maxsig)
			{
				maxsig=effSig[i];
				maxindex=i;
			}
		}
		printf("significance:                      %f\n",maxsig);
		printf("effb                               %.10f\n",effB[maxindex]);
		printf("effs                               %.10f\n",effS[maxindex]);
        printf("effb*nbackground                   %.10f\n",effB[maxindex]*wBackground);
        printf("effs*nsignal                       %.10f\n",effS[maxindex]*wSignal);

		for(unsigned int m=0;m<nVar;m++)
		{
			if(margins[m]=="FMin" )
				cout<<setiosflags(ios::left)<<setw(35)<<varval[m]<<cutvalMax[m].at(maxindex)<<endl;
			if(margins[m]=="FMax")
				cout<<setiosflags(ios::left)<<setw(35)<<varval[m]<<cutvalMin[m].at(maxindex)<<endl;
			if(margins[m]=="NotEnforced"){
				cout<<setiosflags(ios::left)<<setw(35)<<varval[m]<<cutvalMax[m].at(maxindex)<<" , "<<setiosflags(ios::left)<<setw(11)<<cutvalMin[m].at(maxindex)<<endl;
			}
		}

		cout<<"mac. sig. cut expression: "<<endl;
		cout<<"CUTPP=$CUTPP\"";
		cout<<cut[maxindex]<<"\""<<endl;;

		TH2F* hempty = new TH2F("hempty","",50,0,1.,10,0.,maxsig*1.2);  
		hempty->GetXaxis()->CenterTitle();
		hempty->GetYaxis()->CenterTitle();
		hempty->GetXaxis()->SetTitle("Signal efficiency");
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

		TGraph* gsig = new TGraph(100,effS,effSig);
		TCanvas* csig = new TCanvas("csig","",600,600);
		hempty->Draw();
		texPar->Draw();
		texPtY->Draw();
		gsig->Draw("same*");

		ceffSB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_EffvsSig.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));
		csig->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_Significance.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));
	}
	else{
		//read TMVA output
        TString inputMVAname = Form("../myTMVA/ROOT/TMVA_%s_%.0f_%.0f_varStage%d.root",colsyst.Data(),ptMin,ptMax,stage);
		TFile *inputMVA = new TFile(inputMVAname.Data());

		TH1D* th1_S = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_S", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
		TH1D* th1_B = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_B", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
		Float_t minBDT = th1_B->GetBinCenter(1)-(th1_B->GetBinWidth(1)/2);
		Float_t maxBDT = th1_B->GetBinCenter(40)+(th1_B->GetBinWidth(40)/2);

		TCanvas* chcountEffS = new TCanvas("chcountEffS","",600,600);
		th1_S->SetLineColor(kRed);
		th1_S->SetFillStyle(3004);
		th1_S->SetFillColor(kRed);
		th1_S->SetLineWidth(3);
		th1_S->Scale(1/th1_S->Integral());
		th1_S->Draw("hist");
		TCanvas* chcountEffB = new TCanvas("chcountEffB","",600,600);
		th1_B->SetLineColor(kBlue+1);
		th1_B->SetFillStyle(1001);
		th1_B->SetFillColor(kBlue-9);
		th1_B->SetLineWidth(3);
		th1_B->Scale(1/th1_B->Integral());
		th1_B->Draw("hist");

		TH2F* hemptydis = new TH2F("hemptydis","",50,minBDT-0.2,maxBDT+0.2,10,0.,max(th1_S->GetMaximum(),th1_B->GetMaximum())*1.2);
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
		th1_S->Draw("same hist");
		th1_B->Draw("same hist");
		TLegend* leg = new TLegend(0.60,0.75,0.95,0.86);
		leg->SetBorderSize(0);
		leg->SetFillStyle(0);
		leg->AddEntry(th1_B,"Background","f");
		leg->AddEntry(th1_S,"Signal","f");
		leg->Draw("same");
		texPar->Draw();
		texPtY->Draw();

		TH1D* th1_effBvsS = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_effBvsS", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
		TH1D* th1_effS = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_effS", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
		TH1D* th1_effB = (TH1D*)inputMVA->Get(Form("dataset/Method_%s/%s/MVA_%s_effB", MVAtype.Data(), MVAtype.Data(), MVAtype.Data()));
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
				_cutval=_cutval_arr[e-1];
			}
		}	
		_effs = th1_effS->GetBinContent(_maxsigbin);
		_effb = th1_effB->GetBinContent(_maxsigbin);
		printf("significance:                      %f\n",_maxsigval);
		printf("effb                               %.10f\n",_effb);
		printf("effs                               %.10f\n",_effs);
        printf("effb*nbackground                   %.10f\n",_effb*wBackground);
        printf("effs*nsignal                       %.10f\n",_effs*wSignal);
		cout<<setiosflags(ios::left)<<setw(35)<<"cutval: "<<_cutval<<endl;
		TCanvas* csig = new TCanvas("csig","",600,600);
		TH2F* hempty = new TH2F("hempty","",50,_cutval_arr[0]-0.2,_cutval_arr[_bins-1]+0.2,10,0.,_maxsigval*1.2);  
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
		hempty->Draw();
		texPar->Draw();
		texPtY->Draw();
		TGraph* _gsig = new TGraph(th1_effS->GetNbinsX(),_cutval_arr,_sigval_arr);
		_gsig->Draw("same *");

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

		TCanvas* ceffSB = new TCanvas("ceffSB","",600,600);
		hemptyeff->Draw();
		texPar->Draw();
		texPtY->Draw();
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

		chcountEffS->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_varStage%d_chcountEffS.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax,stage));
		chcountEffB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_varStage%d_chcountEffB.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax,stage));
		cdisEffSB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_varStage%d_disEffSB.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax,stage));
		csig->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_varStage%d_Significance.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax,stage));
		ceffSB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_varStage%d_EffvsMVA.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax,stage));
	}

}
