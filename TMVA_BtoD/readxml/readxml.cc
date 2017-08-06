using namespace std;
#include "uti.h"
#include "readxml.h"
#include "Tools.h"
#include "../prefilter.h"

TString cutss;
TString cutsb;
TString cutsg;
//TString evtweight="1";
TString evtweight="pthatweight";
//TString hltPrescale="((DtktkRespt>8&&DtktkRespt<15)*1/(9.740888e+01)+(DtktkRespt>15&&DtktkRespt<20)*1/(2.594206e+01)+(DtktkRespt>20&&DtktkRespt<30)*1/(8.305474e+00)+(DtktkRespt>30&&DtktkRespt<50)*1/(4.070169e+00)+(DtktkRespt>50)*1/(1))";
TString hltPrescale="1";

//Raa=0.49,0.44,0.42,0.41,0.41
void readxml(Int_t pbpb=1, TString mva="CutsSA", Float_t ptMin=30., Float_t ptMax=50., Float_t RAA=1.)
{
  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);

  void calRatio(TTree* signal, TTree* background, TTree* generated, Float_t* results, Bool_t verbose=false);
  isPbPb = (bool)pbpb;
  MVAtype = (TString)mva;
  ptmin = ptMin;
  ptmax = ptMax;

  inputSname = isPbPb?inputSname_PP:inputSname_pp;
  inputBname = isPbPb?inputBname_PP:inputBname_pp;      
  raa = isPbPb?RAA:1.;
  mycuts = isPbPb?mycuts_PP:mycuts_pp;
  mycutb = isPbPb?mycutb_PP:mycutb_pp;
  mycutg = isPbPb?mycutg_PP:mycutg_pp;
  colsyst = isPbPb?"PbPb":"pp";

  cutss = isPbPb?Form("(%s)&&Dpt>%f&&Dpt<%f&&hiBin>=0&&hiBin<=200",mycuts.Data(),ptmin,ptmax):Form("(%s)&&Dpt>%f&&Dpt<%f",mycuts.Data(),ptmin,ptmax);
  cutsb = isPbPb?Form("(%s)&&Dpt>%f&&Dpt<%f&&hiBin>=0&&hiBin<=200",mycutb.Data(),ptmin,ptmax):Form("(%s)&&Dpt>%f&&Dpt<%f",mycutb.Data(),ptmin,ptmax);
  cutsg = isPbPb?Form("(%s)&&Gpt>%f&&Gpt<%f&&hiBin>=0&&hiBin<=200",mycutg.Data(),ptmin,ptmax):Form("(%s)&&Gpt>%f&&Gpt<%f",mycutg.Data(),ptmin,ptmax);

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

  TFile *inputS = new TFile(inputSname.Data());
  TFile *inputB = new TFile(inputBname.Data());

  TTree *background = (TTree*)inputB->Get("ntBptoD0pi");
  background->AddFriend("ntHlt");
  background->AddFriend("ntHi");
  background->AddFriend("ntSkim");

  TTree *generated = (TTree*)inputS->Get("ntGen");
  generated->AddFriend("ntHlt");
  generated->AddFriend("ntHi");

  TTree *signal = (TTree*)inputS->Get("ntBptoD0pi");
  signal->AddFriend("ntHlt");
  signal->AddFriend("ntHi");
  signal->AddFriend("ntSkim");

  //read weight file
  TString fileName = Form("../myTMVA/weights/TMVA_%s_%s_%.0f_%.0f.weights.xml",MVAtype.Data(),colsyst.Data(),ptmin,ptmax);
  const char* filename = fileName.Data();
  void *doc = TMVA::gTools().xmlengine().ParseFile(filename,TMVA::gTools().xmlenginebuffersize());
  void* rootnode = TMVA::gTools().xmlengine().DocGetRootElement(doc); // node "MethodSetup"
  TString fullMethodName(""); 
  TMVA::gTools().ReadAttr(rootnode, "Method", fullMethodName);

  cout<<" ╒══════════════════════════════════════════════════════════════════════════╕"<<endl;
  cout<<" |                              Cut Opt Configuration                       |"<<endl;
  cout<<" ├────────────┬───────────────────────────────────────────────┬─────────────┤"<<endl;
  cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"Method"<<" | "<<setiosflags(ios::left)<<setw(45)<<fullMethodName<<" | "<<setiosflags(ios::left)<<setw(11)<<" "<<" |"<<endl;

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
      cout<<" ├────────────┼───────────────────────────────────────────────┼─────────────┤"<<endl;
      cout<<" | "<<setiosflags(ios::left)<<setw(10)<<tem<<" | "<<setiosflags(ios::left)<<setw(45)<<varname<<" | "<<setiosflags(ios::left)<<setw(11)<<margins[k]<<" |"<<endl;
      var = TMVA::gTools().GetNextChild(var);
      varnames.push_back(varname);
    }
  cout<<" ╞════════════╪═══════════════════════════════════════════════╪═════════════╡"<<endl;
  cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"Pt"<<" | "<<setiosflags(ios::left)<<setw(45)<<ptstring<<" | "<<setiosflags(ios::left)<<setw(11)<<" "<<" |"<<endl;
  cout<<" ├────────────┼───────────────────────────────────────────────┼─────────────┤"<<endl;
  cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"Raa"<<" | "<<setiosflags(ios::left)<<setw(45)<<raa<<" | "<<setiosflags(ios::left)<<setw(11)<<" "<<" |"<<endl;
  cout<<" ╘════════════╧═══════════════════════════════════════════════╧═════════════╛"<<endl;

  void* weight = TMVA::gTools().GetChild(rootnode,"Weights");
  void* eff = TMVA::gTools().GetChild(weight,"Bin");
  int n=0;
  TString cut[NEff];
  while(eff)
    {
      TMVA::gTools().ReadAttr(eff, "effS", effS[n]);
      TMVA::gTools().ReadAttr(eff, "effB", effB[n]);
      void* cutsnode = TMVA::gTools().GetChild(eff,"Cuts");
      for(unsigned long l=0;l<varnames.size();l++)
	{
	  double min,max;
	  TMVA::gTools().ReadAttr(cutsnode, TString("cutMin_")+l, min);
	  TMVA::gTools().ReadAttr(cutsnode, TString("cutMax_")+l, max);
      cutvalMax[l].push_back(max);
      cutvalMin[l].push_back(min);
	  TString lessmax = "<"; lessmax+=max;
	  TString moremin = ">"; moremin+=min; 
      cut[l] = "";
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
  ceffSB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_EffvsSig.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));

  float wSignal=0;
  float wBackground=0;
  float* weights = new float[2];
  //
  calRatio(signal,background,generated,weights);//weight signal and background
  //

  wSignal = weights[1];
  wBackground = weights[0];

  cout<<endl;
  cout<<"Looking for max significance ..."<<endl;

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
	cout<<"mac. sig. cut expression: "<<endl;
    cout<<"CUTPP=$CUTPP\"";
    cout<<cut[maxindex]<<"\""<<endl;;

  cout<<endl;
  cout<<" ╒════════════════════════════════════════════════════════════════════╕"<<endl;
  cout<<" |                                Opt Result                          |"<<endl;
  cout<<" ├────────────┬────────────┬───────────────┬──────────────────────────┤"<<endl;
  cout<<" | "<<setiosflags(ios::left)<<setw(10)<<"Sig eff"<<" | "<<setiosflags(ios::left)<<setw(10)<<effS[maxindex]<<" | "<<setiosflags(ios::left)<<setw(13)<<"S/sqrt(S+B)"<<" | "<<setiosflags(ios::left)<<setw(24)<<maxsig<<" |"<<endl;
  cout<<" ├────────────┴────────────┴───────────────┴─────┬────────────────────┤"<<endl;

  for(unsigned int m=0;m<nVar;m++)
    {
      if(m) cout<<" ├───────────────────────────────────────────────┼────────────────────┤"<<endl;
	  if(margins[m]=="FMin" )
        cout<<" | "<<setiosflags(ios::left)<<setw(45)<<varval[m]<<" | "<<setiosflags(ios::left)<<setw(18)<<cutvalMax[m].at(maxindex)<<" |"<<endl;
	  if(margins[m]=="FMax")
        cout<<" | "<<setiosflags(ios::left)<<setw(45)<<varval[m]<<" | "<<setiosflags(ios::left)<<setw(18)<<cutvalMin[m].at(maxindex)<<" |"<<endl;
	  if(margins[m]=="NotEnforced"){
        cout<<" | "<<setiosflags(ios::left)<<setw(45)<<varval[m]<<" | "<<setiosflags(ios::left)<<setw(4)<<cutvalMax[m].at(maxindex)<<" , "<<setiosflags(ios::left)<<setw(11)<<cutvalMin[m].at(maxindex)<<" |"<<endl;
      }
    }
  cout<<" ╘═══════════════════════════════════════════════╧════════════════════╛"<<endl;
  cout<<endl;

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
  csig->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_Significance.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));

}

void calRatio(TTree* signal, TTree* background, TTree* generated, Float_t* results, Bool_t verbose=false)
{
  TString sels = cutss;
  TString selb = cutsb;
  TString selg = cutsg;

  //Background candidate number
  TH1D* hmassB = new TH1D("hmassB",";B mass (GeV/c^{2});Background Entries",50,5,6);
  background->Project("hmassB","Dmass",selb);
  TCanvas* cmassB = new TCanvas("cmassB","",600,600);
  hmassB->Draw();
  cmassB->SaveAs(Form("plots/%s_%s_pT_%.0f_%.0f_Background.pdf",MVAtype.Data(),colsyst.Data(),ptmin,ptmax));
  int nentriesB = hmassB->Integral();

  //FONLL
  //ifstream getdata("fonlls/fo_pp_Bplus_5p03TeV_y2p4.dat");
  ifstream getdata("fonlls/fo_pp_Bplus_5p03TeV_y1p0.dat");
  if(!getdata.is_open()) cout<<"Opening the file fails"<<endl;
  float tem;
  int nbin=0;
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
  double deltapt = 0.25;
  //central[i] - in pb/GeV/c

  double yieldDzero = htheoryreco->Integral();
  yieldDzero*=BR*deltapt*lumi*raa*2*0.401;// need to consider HLT prescale

  //results[0] = nentriesB*Nsigma*sigma/0.05;//0.05: half of sideband width
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
