bool isPbPb;
float ptmin;
float ptmax;
double luminosity;

TString inputSname;
TString inputBname;
TString mycut;
TString mycuts;
TString mycutb;
TString mycutg;
TString colsyst;
TString MVAtype;
TString npfile;
TString selgen = "TMath::Abs(Gy)<1.0 && abs(GpdgId)==521 && (GisSignal==13 || GisSignal==14)";
TString kinematic_cuts = "TMath::Abs(Dy)<1.0 && Dmass>5&&Dmass<6";
//TString prefilter = "Dtrk1highPurity && DRestrk1highPurity && DRestrk2highPurity && Dtrk1PtErr/Dtrk1Pt<0.3 && DRestrk1PtErr/DRestrk1Pt<0.3 && DRestrk2PtErr/DRestrk2Pt<0.3 && abs(Dtrk1Eta)<1.0 && abs(DRestrk1Eta)<1.0 && abs(DRestrk2Eta)<1.0 && Dtrk1Pt>0.5 && DRestrk1Pt>0.5 && DRestrk2Pt>0.5 && DtktkRespt>0 && abs(DtktkResmass-1.87)<0.03 && Dchi2cl>0.05 && DtktkRes_chi2cl>0.05 && Dalpha<3.2 && DtktkRes_alpha<3.2 && DtktkRes_alphaToSV<3.2 && (DsvpvDistance/DsvpvDisErr)>0.0 && (DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>0.0";
TString prefilter = "Dtrk1highPurity && DRestrk1highPurity && DRestrk2highPurity && Dtrk1PtErr/Dtrk1Pt<0.3 && DRestrk1PtErr/DRestrk1Pt<0.3 && DRestrk2PtErr/DRestrk2Pt<0.3 && abs(Dtrk1Eta)<999.0 && abs(DRestrk1Eta)<999.0 && abs(DRestrk2Eta)<999.0 && Dtrk1Pt>0.5 && DRestrk1Pt>0.5 && DRestrk2Pt>0.5 && DtktkRespt>0 && abs(DtktkResmass-1.87)<0.03 && Dchi2cl>0.05 && DtktkRes_chi2cl>0.05 && Dalpha<3.2 && DtktkRes_alpha<3.2 && DtktkRes_alphaToSV<3.2 && (DsvpvDistance/DsvpvDisErr)>0.0 && (DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>0.0";

//////////pp section
double lum_pp=0.0381639;//MB
//double lum_pp=27.4;//HF
TString inputSname_pp = "/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170731_pp_BuToD0Pi_DfinderMC_pp_20170729_BtoD0Pi_pthatweight.root";
TString inputBname_pp = "/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170731_MinimumBias_DfinderData_pp_20170729_BtoD0Pi_Dpt5EvtSkim/Dntuple_20170731_MinimumBias2to5_DfinderData_pp_20170729_BtoD0Pi_Dpt5EvtSkim.root";
//TString myTrg_pp ="((HLT_DmesonPPTrackingGlobal_Dpt8_v1&&DtktkRespt>10&&DtktkRespt<20)||(HLT_DmesonPPTrackingGlobal_Dpt15_v1&&DtktkRespt>20&&DtktkRespt<40)||(HLT_DmesonPPTrackingGlobal_Dpt30_v1&&DtktkRespt>40&&DtktkRespt<60)||(HLT_DmesonPPTrackingGlobal_Dpt50_v1&&DtktkRespt>60))";
//TString myTrg_pp = "(HLT_DmesonPPTrackingGlobal_Dpt8_v1||HLT_DmesonPPTrackingGlobal_Dpt15_v1||HLT_DmesonPPTrackingGlobal_Dpt30_v1||HLT_DmesonPPTrackingGlobal_Dpt50_v1)";// HF
//TString myTrg_pp = "(HLT_DmesonPPTrackingGlobal_Dpt8_v1||HLT_DmesonPPTrackingGlobal_Dpt15_v1||HLT_DmesonPPTrackingGlobal_Dpt20_v1||HLT_DmesonPPTrackingGlobal_Dpt30_v1||HLT_DmesonPPTrackingGlobal_Dpt50_v1)";// HF
TString myTrg_pp = "(HLT_L1MinimumBiasHF1OR_part1_v1||HLT_L1MinimumBiasHF1OR_part2_v1||HLT_L1MinimumBiasHF1OR_part3_v1||HLT_L1MinimumBiasHF1OR_part4_v1||HLT_L1MinimumBiasHF1OR_part5_v1||HLT_L1MinimumBiasHF1OR_part6_v1||HLT_L1MinimumBiasHF1OR_part7_v1||HLT_L1MinimumBiasHF1OR_part8_v1||HLT_L1MinimumBiasHF1OR_part9_v1||HLT_L1MinimumBiasHF1OR_part10_v1||HLT_L1MinimumBiasHF1OR_part11_v1||HLT_L1MinimumBiasHF1OR_part12_v1||HLT_L1MinimumBiasHF1OR_part13_v1||HLT_L1MinimumBiasHF1OR_part14_v1||HLT_L1MinimumBiasHF1OR_part15_v1||HLT_L1MinimumBiasHF1OR_part16_v1||HLT_L1MinimumBiasHF1OR_part17_v1||HLT_L1MinimumBiasHF1OR_part18_v1||HLT_L1MinimumBiasHF1OR_part19_v1)";// MB
TString evtfilter_pp = "abs(PVz)<15 && pBeamScrapingFilter && pPAprimaryVertexFilter";
TString mycut_pp = evtfilter_pp + "&&" + kinematic_cuts + "&&" + prefilter;
TString mycuts_pp = Form("%s &&Dgen==23333",mycut_pp.Data());
//TString mycutb_pp = Form("%s &&abs(Dmass-5.279)>0.2&&abs(Dmass-5.279)<0.3",mycut_pp.Data()); //sideband 0.1
TString mycutb_pp = Form("%s &&(Dmass-5.279)>0.2&&(Dmass-5.279)<0.5&& %s",mycut_pp.Data(), myTrg_pp.Data()); //sideband 0.3
TString mycutg_pp = selgen;

///////PbPb section
double lum_PP=1.6419125;//MB
//double lum_PP=15.5020+4.63386;//HP
TString inputSname_PP = "/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170717_PbPb_BuToD0Pi_20151212_DfinderMC_PbPb_20170720_BtoD0Pi_40FilesEach_pthatweight.root";
TString inputBname_PP = "/net/hisrv0001/home/tawei/scratch/HeavyFlavor/Run2Ana/BtoDAna/samples/Dntuple_20170717_HIMinimumBias2_DfinderData_PbPb_20170717_Golden_BtoD0Pi_Dpt5EvtSkim_10Files.root";
//TString myTrg_PP = "((HLT_HIDmesonHITrackingGlobal_Dpt20_v1&&DtktkRespt>20&&DtktkRespt<40)||(HLT_HIDmesonHITrackingGlobal_Dpt40_v1&&DtktkRespt>40&&DtktkRespt<60)||(HLT_HIDmesonHITrackingGlobal_Dpt60_v1&&DtktkRespt>60))";// HP
//TString myTrg_PP = "(HLT_HIDmesonHITrackingGlobal_Dpt20_v1 || HLT_HIDmesonHITrackingGlobal_Dpt40_v1 || HLT_HIDmesonHITrackingGlobal_Dpt60_v1)";// HP
//TString myTrg_PP = ="(HLT_HIL1MinimumBiasHF2AND_part1_v1||HLT_HIL1MinimumBiasHF2AND_part2_v1||HLT_HIL1MinimumBiasHF2AND_part3_v1)"// MB
TString myTrg_PP = "(1)"; // events of MB dataset will all pass the MB HLT
TString evtfilter_PP = "abs(PVz)<15 && pclusterCompatibilityFilter && pprimaryVertexFilter && phfCoincFilter3"; 
TString mycut_PP = evtfilter_PP + "&&" + kinematic_cuts + "&&" + prefilter;
TString mycuts_PP = Form("%s &&Dgen==23333",mycut_PP.Data());
TString mycutb_PP = Form("%s &&(Dmass-5.279)>0.2&&(Dmass-5.279)<0.5&& %s",mycut_PP.Data(), myTrg_PP.Data()); //sideband 0.3
TString mycutg_PP = selgen; 

// the cuts used by the D RAA analysis, too tight for B to D analysis
TString DAnacut_pp = "((DtktkRes_lxyBS/DtktkRes_lxyBSErr)>2.5&&DtktkRes_alpha<0.12&&((DtktkRespt>2&&DtktkRespt<4&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>5.86&&DtktkRes_alpha>0.224)||(DtktkRespt>4&&DtktkRespt<5&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>5.46&&DtktkRes_alpha>0.196)||(DtktkRespt>5&&DtktkRespt<6&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>4.86&&DtktkRes_alpha>0.170)||(DtktkRespt>6&&DtktkRespt<8&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>4.54&&DtktkRes_alpha>0.125)||(DtktkRespt>8&&DtktkRespt<10&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>4.42&&DtktkRes_alpha>0.091)||(DtktkRespt>10&&DtktkRespt<15&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>4.06&&DtktkRes_alpha>0.069)||(DtktkRespt>15&&DtktkRespt<20&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>3.71&&DtktkRes_alpha>0.056)||(DtktkRespt>20&&DtktkRespt<25&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>3.25&&DtktkRes_alpha>0.054)||(DtktkRespt>25&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>2.97&&DtktkRes_alpha>0.050)))";
TString DAnacut_PP = "((DtktkRes_lxyBS/DtktkRes_lxyBSErr)>2.5&&DtktkRes_alpha<0.12&&((DtktkRespt>1&&DtktkRespt<2&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>6.0&&Dchi2cl>0.25)||(DtktkRespt>2&&DtktkRespt<3&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>4.62&&Dchi2cl>0.161)||(DtktkRespt>3&&DtktkRespt<4&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>4.80&&Dchi2cl>0.197)||(DtktkRespt>4&&DtktkRespt<5&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>4.63&&Dchi2cl>0.141)||(DtktkRespt>5&&DtktkRespt<6&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>4.53&&Dchi2cl>0.172)||(DtktkRespt>6&&DtktkRespt<8&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>4.09&&Dchi2cl>0.120)||(DtktkRespt>8&&DtktkRespt<10&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>4.02&&Dchi2cl>0.098)||(DtktkRespt>10&&DtktkRespt<12.5&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>3.66&&Dchi2cl>0.099)||(DtktkRespt>12.5&&DtktkRespt<15&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>3.70&&Dchi2cl>0.084)||(DtktkRespt>15&&DtktkRespt<20&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>3.53&&Dchi2cl>0.047)||(DtktkRespt>20&&DtktkRespt<25&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>3.25&&Dchi2cl>0.054)||(DtktkRespt>25&&(DtktkRes_svpvDistance/DtktkRes_svpvDisErrr)>2.97&&Dchi2cl>0.050)))";
