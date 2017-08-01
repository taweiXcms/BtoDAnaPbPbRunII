#!/bin/bash

#BtoD MC
sed '1iconst int nBins=4; float pthatBin[nBins]={5,15,30,50}; float ptBin[nBins]={5,15,30,50}; float crosssec[nBins+1]={4.161e+07, 1.943e+06, 1.487e+05, 1.562e+04, 0}; int genSignal[2]={13,14};' weighPthat.C > weighPthat_tmp.C ##old MC
#sed '1iconst int nBins=7; float pthatBin[nBins]={0,2,5,10,15,30,50}; float ptBin[nBins]={0,0,0,0,0,0,0}; float crosssec[nBins+1]={1.054e+08, 1.017e+08, 7.899e+07, 2.248e+07, 7.427e+06, 7.863e+05, 1.161e+05, 0}; int genSignal[2]={13,14};' weighPthat.C > weighPthat_tmp.C ## new MC
INPUTFILE="test.root"
OUTPUTFILE="test_pthat.root"

###

cp "$INPUTFILE" "$OUTPUTFILE"
g++ weighPthat_tmp.C $(root-config --cflags --libs) -g -o weighPthat_tmp.exe 
./weighPthat_tmp.exe "$INPUTFILE" "$OUTPUTFILE"
rm weighPthat_tmp.exe

rm weighPthat_tmp.C
