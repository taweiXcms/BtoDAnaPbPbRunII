#!/bin/bash

DOANALYSISPP_FIT=1
DOANALYSISPP_MCSTUDY=0
DOANALYSISPbPb_FIT=0
DOANALYSISPbPb_MCSTUDY=0
DORAA=0

#LUMIPP=27.748 # paper 20170224, B analysis
#LUMIPP=25.8 # D analysis
LUMIPP=27.4 # D analysis
INPUTMCPP="../test/ntB_pp_MC_5_7.root"
INPUTDATAPP="../test/ntB_pp_Data_5_7.root"
#TRGPP="(HLT_DmesonPPTrackingGlobal_Dpt8_v1 || HLT_DmesonPPTrackingGlobal_Dpt15_v1 || HLT_DmesonPPTrackingGlobal_Dpt30_v1 || HLT_DmesonPPTrackingGlobal_Dpt50_v1)"
#TRGPP="(HLT_DmesonPPTrackingGlobal_Dpt8_v1 || HLT_DmesonPPTrackingGlobal_Dpt15_v1 || HLT_DmesonPPTrackingGlobal_Dpt20_v1 || HLT_DmesonPPTrackingGlobal_Dpt30_v1 || HLT_DmesonPPTrackingGlobal_Dpt50_v1)";
TRGPP="(HLT_L1MinimumBiasHF1OR_part1_v1||HLT_L1MinimumBiasHF1OR_part2_v1||HLT_L1MinimumBiasHF1OR_part3_v1||HLT_L1MinimumBiasHF1OR_part4_v1||HLT_L1MinimumBiasHF1OR_part5_v1||HLT_L1MinimumBiasHF1OR_part6_v1||HLT_L1MinimumBiasHF1OR_part7_v1||HLT_L1MinimumBiasHF1OR_part8_v1||HLT_L1MinimumBiasHF1OR_part9_v1||HLT_L1MinimumBiasHF1OR_part10_v1||HLT_L1MinimumBiasHF1OR_part11_v1||HLT_L1MinimumBiasHF1OR_part12_v1||HLT_L1MinimumBiasHF1OR_part13_v1||HLT_L1MinimumBiasHF1OR_part14_v1||HLT_L1MinimumBiasHF1OR_part15_v1||HLT_L1MinimumBiasHF1OR_part16_v1||HLT_L1MinimumBiasHF1OR_part17_v1||HLT_L1MinimumBiasHF1OR_part18_v1||HLT_L1MinimumBiasHF1OR_part19_v1)"
#TRGPP="1"
TRGPPMC="1"
CUTPP="abs(PVz)<15 && pBeamScrapingFilter && pPAprimaryVertexFilter && TMath::Abs(Dy)<1. && Dmass>5&&Dmass<6 && Dtrk1highPurity && DRestrk1highPurity && DRestrk2highPurity && Dtrk1PtErr/Dtrk1Pt<0.3 && DRestrk1PtErr/DRestrk1Pt<0.3 && DRestrk2PtErr/DRestrk2Pt<0.3 && abs(Dtrk1Eta)<1. && abs(DRestrk1Eta)<1. && abs(DRestrk2Eta)<1. && Dtrk1Pt>0.5 && DRestrk1Pt>0.5 && DRestrk2Pt>0.5 && DtktkRespt>0 && abs(DtktkResmass-1.87)<0.03 && Dchi2cl>0.05 && DtktkRes_chi2cl>0.05 && Dalpha<0.6 && DtktkRes_alpha<3.2 && (DsvpvDistance/DsvpvDisErr)>2.0 && (DtktkRes_svpvDistance/DtktkRes_svpvDisErr)>0.0"

#CUTPP=$CUTPP" && Dtrk1Pt>0.81410207921796984 && DRestrk1Pt>0.91851796461340629 && DRestrk2Pt>0.45770396380096878 && DtktkRespt>2.3871345418641368 && Dchi2cl>0.13667649656962585 && DtktkRes_chi2cl>0.12167909605560623 && Dalpha<0.27121158916733801 && DtktkRes_alpha<2.3740247975997524 && DtktkRes_alphaToSV<3.0949164478099367 && DsvpvDistance/DsvpvDisErr>7.0428338151204457 && DtktkRes_svpvDistance/DtktkRes_svpvDisErr>-3.0300759265275587 && DtktkRes_ptAsymToTrk1<0.918139439686114 && DtktkRes_ptAsymToTrk1>-0.99139278206127024 && DtktkRes_angleToTrk1<2.5112713644187652"
#CUTPP=$CUTPP" && Dtrk1Pt>0.9450963731440748 && DRestrk1Pt>0.74607339206368972 && DRestrk2Pt>0.48253800050809303 && DtktkRespt>1.8926671060453399 && Dchi2cl>0.0498872211227867 && DtktkRes_chi2cl>0.1213970632035527 && Dalpha<0.22561935452824519 && DtktkRes_alpha<1.0485336378073216 && DtktkRes_alphaToSV<1.5138467160833029 && DsvpvDistance/DsvpvDisErr>4.7494885579476733 && DtktkRes_svpvDistance/DtktkRes_svpvDisErr>-18.056276289334427 && DtktkRes_ptAsymToTrk1<1.2806039474101358 && DtktkRes_ptAsymToTrk1>-0.33261359369210447 && DtktkRes_angleToTrk1<2.5005532246289088"
#CUTPP=$CUTPP"&&LD>0.08"
#CUTPP=$CUTPP"&&MLP>0.92"
#CUTPP=$CUTPP"&&BDT>0.24"
#CUTPP=$CUTPP"&&BDTB>1."

CUTPP=$CUTPP"&&BDT>0.20"
#CUTPP=$CUTPP"&&BDT>0.15"
#CUTPP=$CUTPP"&&BDT>0.13"
#CUTPP=$CUTPP"&&BDT>0.1"

SELGENPP="TMath::Abs(Gy)<2.4 && abs(GpdgId)==521 && (GisSignal==13 || GisSignal==14)"
SELGENPPACCPP="TMath::Abs(Gy)<2.4 && abs(GpdgId)==521 && (GisSignal==13 || GisSignal==14) && Gtk1pt>1.0 && TMath::Abs(Gtk1eta)<2.4"
RECOONLYPP=$CUTPP
ISMCPP=0
ISDOWEIGHTPP=0
LABELPP="pp"
OUTPUTFILEPP="ROOTfiles/hPtSpectrumBplusPP.root"
OUTPUTFILEMCSTUDYPP="ROOTfiles/MCstudiesPP.root"
NPFIT_PP="3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2) + 2.11124e2"

if [ $DOANALYSISPP_FIT -eq 1 ]; then
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe
./fitB.exe 0 "$INPUTDATAPP"  "$INPUTMCPP"  "$TRGPP" "$CUTPP"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPP" "$NPFIT_PP" 0
rm fitB.exe
fi

if [ $DOANALYSISPP_MCSTUDY -eq 1 ]; then
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe
./MCefficiency.exe  0 "$INPUTMCPP"  "$SELGENPP" "$SELGENPPACCPP"  "$RECOONLYPP" "$CUTPP&&$TRGPPMC"  "$LABELPP" "$OUTPUTFILEMCSTUDYPP" "$ISDOWEIGHTPP"
rm MCefficiency.exe
fi

#LUMIPbPb=13.1983052423 #paper 20170227, B analysis
#LUMIPbPb=15.5665   # from brilcalc, D analysis
LUMIPbPb=15.5020   # from brilcalc, D analysis
INPUTDATAPbPb="../Skim/Skim_ntD_EvtBase_20170323_DfinderData_PbPb_20170123_BtoD0Pi_Dpt10Dsvpv3Dalpha0p14Dchi20p05Dmass56Tkpt1Ressvpv3.root"
INPUTMCPbPb="../Skim/Skim_ntD_EvtBase_20170130_DfinderMC_PbPb_20170123_BtoD0Pi_dPt0tkPt2p5_Pythia8_nonprompt_Hydjet_MB_Dpt5tkPt2p5Decay3tktkResDecay3Skim_pthatweight.root"
#TRGPbPb="(HLT_HIDmesonHITrackingGlobal_Dpt20_v1 || HLT_HIDmesonHITrackingGlobal_Dpt40_v1 || HLT_HIDmesonHITrackingGlobal_Dpt60_v1)"
TRGPbPb="1"
TRGPbPbMC="1"
CUTPbPb="abs(PVz)<15 && pclusterCompatibilityFilter && pprimaryVertexFilter && phfCoincFilter3 && TMath::Abs(Dy)<2.4 && Dmass>5&&Dmass<6 && abs(Dtrk1Eta)<1.0 && Dtrk1Pt>0.5 && Dchi2cl>0.05 && DtktkRes_chi2cl>0.05 && Dalpha < 0.14 && (Dpt>10 && (DsvpvDistance/DsvpvDisErr)>3) && Dtrk1Pt > 2.5 && DRestrk1Pt > 2.5 && DRestrk2Pt > 2.5 && fabs(DtktkResmass-1.87) < 0.03 && DtktkRes_alpha < 0.1 && Dalpha < 0.14 && ((Dpt < 30 && Dalpha < 0.08 && DsvpvDistance/DsvpvDisErr > 5.) || (Dpt > 30))"
SELGENPbPb="TMath::Abs(Gy)<2.4 && abs(GpdgId)==521 && (GisSignal==13 || GisSignal==14)"
SELGENPbPbACCPbPb="TMath::Abs(Gy)<2.4 && abs(GpdgId)==521 && (GisSignal==13 || GisSignal==14) && Gtk1pt>2.5 && TMath::Abs(Gtk1eta)<2.4"
RECOONLYPbPb=$CUTPbPb
ISMCPbPb=0
ISDOWEIGHTPbPb=1
LABELPbPb="PbPb"
OUTPUTFILEPbPb="ROOTfiles/hPtSpectrumBplusPbPb.root"
OUTPUTFILEMCSTUDYPbPb="ROOTfiles/MCstudiesPbPb.root"
NPFIT_PbPb="3.39711e1*Gaus(x,5.35002e0,3.87952e-2)*(x<5.35002e0)+(x>=5.35002e0)*3.39711e1*Gaus(x,5.35002e0,1.14232e-1)+2.16376e2*TMath::Erf(-(x-5.14189)/8.66243e-2) + 2.16376e2"
CENTPbPbMIN=0
CENTPbPbMAX=100

if [ $DOANALYSISPbPb_FIT -eq 1 ]; then
g++ fitB.C $(root-config --cflags --libs) -g -o fitB.exe
./fitB.exe 1 "$INPUTDATAPbPb"  "$INPUTMCPbPb"  "$TRGPbPb" "$CUTPbPb"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPb" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitB.exe
fi

if [ $DOANALYSISPbPb_MCSTUDY -eq 1 ]; then
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe
./MCefficiency.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb" "$SELGENPbPbACCPbPb"  "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPbMC"  "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi


OUTPUTFILERAA="ROOTfiles/outputRAA.root"
if [ $DORAA -eq 1 ]; then
g++ NuclearModificationFactor.C $(root-config --cflags --libs) -g -o NuclearModificationFactor.exe
./NuclearModificationFactor.exe "$OUTPUTFILEPP" "$OUTPUTFILEPbPb" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEMCSTUDYPbPb" "$LABELPbPb" "$OUTPUTFILERAA" 0 "$LUMIPP" "$LUMIPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactor.exe
fi
