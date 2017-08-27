#define MAX_XB       20000
// Declaration of leaf types
Int_t           RunNo;
Int_t           EvtNo;
Int_t           LumiNo;
Int_t           Dsize;
Float_t         PVx;
Float_t         PVy;
Float_t         PVz;
Float_t         PVnchi2;
Float_t         BSx;
Float_t         BSy;
Float_t         BSz;
Float_t         PVxE;
Float_t         PVyE;
Float_t         PVzE;
Float_t         BSxErr;
Float_t         BSyErr;
Float_t         BSzErr;
Float_t         BSdxdz;
Float_t         BSdydz;
Float_t         BSdxdzErr;
Float_t         BSdydzErr;
Float_t         BSWidthX;
Float_t         BSWidthXErr;
Float_t         BSWidthY;
Float_t         BSWidthYErr;
Int_t           Dindex[MAX_XB];   //[Dsize]
Int_t           Dtype[MAX_XB];   //[Dsize]
Float_t         Dmass[MAX_XB];   //[Dsize]
Float_t         D_unfitted_mass[MAX_XB];   //[Dsize]
Float_t         Dpt[MAX_XB];   //[Dsize]
Float_t         D_unfitted_pt[MAX_XB];   //[Dsize]
Float_t         Deta[MAX_XB];   //[Dsize]
Float_t         Dphi[MAX_XB];   //[Dsize]
Float_t         Dy[MAX_XB];   //[Dsize]
Float_t         DvtxX[MAX_XB];   //[Dsize]
Float_t         DvtxY[MAX_XB];   //[Dsize]
Float_t         DvtxZ[MAX_XB];   //[Dsize]
Float_t         Dd0[MAX_XB];   //[Dsize]
Float_t         Dd0Err[MAX_XB];   //[Dsize]
Float_t         Ddxyz[MAX_XB];   //[Dsize]
Float_t         DdxyzErr[MAX_XB];   //[Dsize]
Float_t         Dchi2ndf[MAX_XB];   //[Dsize]
Float_t         Dchi2cl[MAX_XB];   //[Dsize]
Float_t         Ddtheta[MAX_XB];   //[Dsize]
Float_t         Dlxy[MAX_XB];   //[Dsize]
Float_t         Dalpha[MAX_XB];   //[Dsize]
Float_t         DsvpvDistance[MAX_XB];   //[Dsize]
Float_t         DsvpvDisErr[MAX_XB];   //[Dsize]
Float_t         DsvpvDistance_2D[MAX_XB];   //[Dsize]
Float_t         DsvpvDisErr_2D[MAX_XB];   //[Dsize]
Float_t         Ddca[MAX_XB];   //[Dsize]
Float_t         DlxyBS[MAX_XB];   //[Dsize]
Float_t         DlxyBSErr[MAX_XB];   //[Dsize]
Float_t         DMaxDoca[MAX_XB];   //[Dsize]
Float_t         DMaxTkPt[MAX_XB];   //[Dsize]
Float_t         DMinTkPt[MAX_XB];   //[Dsize]
Float_t         Dtrk1Pt[MAX_XB];   //[Dsize]
Float_t         Dtrk2Pt[MAX_XB];   //[Dsize]
Float_t         Dtrk1PtErr[MAX_XB];   //[Dsize]
Float_t         Dtrk2PtErr[MAX_XB];   //[Dsize]
Float_t         Dtrk1Eta[MAX_XB];   //[Dsize]
Float_t         Dtrk2Eta[MAX_XB];   //[Dsize]
Float_t         Dtrk1Phi[MAX_XB];   //[Dsize]
Float_t         Dtrk2Phi[MAX_XB];   //[Dsize]
Float_t         Dtrk1P[MAX_XB];   //[Dsize]
Float_t         Dtrk2P[MAX_XB];   //[Dsize]
Float_t         Dtrk1Dz[MAX_XB];   //[Dsize]
Float_t         Dtrk2Dz[MAX_XB];   //[Dsize]
Float_t         Dtrk1Dxy[MAX_XB];   //[Dsize]
Float_t         Dtrk2Dxy[MAX_XB];   //[Dsize]
Float_t         Dtrk1MassHypo[MAX_XB];   //[Dsize]
Float_t         Dtrk2MassHypo[MAX_XB];   //[Dsize]
Int_t           Dtrk1originalAlgo[MAX_XB];   //[Dsize]
Int_t           Dtrk2originalAlgo[MAX_XB];   //[Dsize]
Bool_t          Dtrk1highPurity[MAX_XB];   //[Dsize]
Bool_t          Dtrk2highPurity[MAX_XB];   //[Dsize]
Float_t         Dtrk1dedx[MAX_XB];   //[Dsize]
Float_t         Dtrk2dedx[MAX_XB];   //[Dsize]
Float_t         Dtrk1thetastar[MAX_XB];   //[Dsize]
Float_t         Dtrk2thetastar[MAX_XB];   //[Dsize]
Float_t         Dtrk1thetastar_uf[MAX_XB];   //[Dsize]
Float_t         Dtrk2thetastar_uf[MAX_XB];   //[Dsize]
Float_t         Dtrk1PixelHit[MAX_XB];   //[Dsize]
Float_t         Dtrk2PixelHit[MAX_XB];   //[Dsize]
Float_t         Dtrk1StripHit[MAX_XB];   //[Dsize]
Float_t         Dtrk2StripHit[MAX_XB];   //[Dsize]
Float_t         Dtrk1nStripLayer[MAX_XB];   //[Dsize]
Float_t         Dtrk2nStripLayer[MAX_XB];   //[Dsize]
Float_t         Dtrk1nPixelLayer[MAX_XB];   //[Dsize]
Float_t         Dtrk2nPixelLayer[MAX_XB];   //[Dsize]
Float_t         Dtrk1Chi2ndf[MAX_XB];   //[Dsize]
Float_t         Dtrk2Chi2ndf[MAX_XB];   //[Dsize]
Int_t           Dtrk1Algo[MAX_XB];   //[Dsize]
Int_t           Dtrk2Algo[MAX_XB];   //[Dsize]
Float_t         Dtrk3Pt[MAX_XB];   //[Dsize]
Float_t         Dtrk4Pt[MAX_XB];   //[Dsize]
Float_t         Dtrk3PtErr[MAX_XB];   //[Dsize]
Float_t         Dtrk4PtErr[MAX_XB];   //[Dsize]
Float_t         Dtrk3Eta[MAX_XB];   //[Dsize]
Float_t         Dtrk4Eta[MAX_XB];   //[Dsize]
Float_t         Dtrk3Phi[MAX_XB];   //[Dsize]
Float_t         Dtrk4Phi[MAX_XB];   //[Dsize]
Float_t         Dtrk3P[MAX_XB];   //[Dsize]
Float_t         Dtrk4P[MAX_XB];   //[Dsize]
Float_t         Dtrk3MassHypo[MAX_XB];   //[Dsize]
Float_t         Dtrk4MassHypo[MAX_XB];   //[Dsize]
Float_t         Dtrk3Dz[MAX_XB];   //[Dsize]
Float_t         Dtrk4Dz[MAX_XB];   //[Dsize]
Float_t         Dtrk3Dxy[MAX_XB];   //[Dsize]
Float_t         Dtrk4Dxy[MAX_XB];   //[Dsize]
Int_t           Dtrk3originalAlgo[MAX_XB];   //[Dsize]
Int_t           Dtrk4originalAlgo[MAX_XB];   //[Dsize]
Bool_t          Dtrk3highPurity[MAX_XB];   //[Dsize]
Bool_t          Dtrk4highPurity[MAX_XB];   //[Dsize]
Float_t         Dtrk3dedx[MAX_XB];   //[Dsize]
Float_t         Dtrk4dedx[MAX_XB];   //[Dsize]
Float_t         Dtrk3thetastar[MAX_XB];   //[Dsize]
Float_t         Dtrk4thetastar[MAX_XB];   //[Dsize]
Float_t         Dtrk3thetastar_uf[MAX_XB];   //[Dsize]
Float_t         Dtrk4thetastar_uf[MAX_XB];   //[Dsize]
Float_t         Dtrk3PixelHit[MAX_XB];   //[Dsize]
Float_t         Dtrk4PixelHit[MAX_XB];   //[Dsize]
Float_t         Dtrk3StripHit[MAX_XB];   //[Dsize]
Float_t         Dtrk4StripHit[MAX_XB];   //[Dsize]
Float_t         Dtrk3nStripLayer[MAX_XB];   //[Dsize]
Float_t         Dtrk4nStripLayer[MAX_XB];   //[Dsize]
Float_t         Dtrk3nPixelLayer[MAX_XB];   //[Dsize]
Float_t         Dtrk4nPixelLayer[MAX_XB];   //[Dsize]
Float_t         Dtrk3Chi2ndf[MAX_XB];   //[Dsize]
Float_t         Dtrk4Chi2ndf[MAX_XB];   //[Dsize]
Int_t           Dtrk3Algo[MAX_XB];   //[Dsize]
Int_t           Dtrk4Algo[MAX_XB];   //[Dsize]
Float_t         Dtrk1Y[MAX_XB];   //[Dsize]
Float_t         Dtrk2Y[MAX_XB];   //[Dsize]
Float_t         Dtrk1D0[MAX_XB];   //[Dsize]
Float_t         Dtrk2D0[MAX_XB];   //[Dsize]
Float_t         Dtrk1D0Err[MAX_XB];   //[Dsize]
Float_t         Dtrk2D0Err[MAX_XB];   //[Dsize]
Int_t           Dtrk1Quality[MAX_XB];   //[Dsize]
Int_t           Dtrk2Quality[MAX_XB];   //[Dsize]
Int_t           Dtrk1Idx[MAX_XB];   //[Dsize]
Int_t           Dtrk2Idx[MAX_XB];   //[Dsize]
Float_t         Dtrk1EtaErr[MAX_XB];   //[Dsize]
Float_t         Dtrk2EtaErr[MAX_XB];   //[Dsize]
Float_t         Dtrk1PhiErr[MAX_XB];   //[Dsize]
Float_t         Dtrk2PhiErr[MAX_XB];   //[Dsize]
Float_t         Dtrk1MVAVal[MAX_XB];   //[Dsize]
Float_t         Dtrk2MVAVal[MAX_XB];   //[Dsize]
Float_t         Dtrk3Y[MAX_XB];   //[Dsize]
Float_t         Dtrk4Y[MAX_XB];   //[Dsize]
Float_t         Dtrk3D0[MAX_XB];   //[Dsize]
Float_t         Dtrk4D0[MAX_XB];   //[Dsize]
Float_t         Dtrk3D0Err[MAX_XB];   //[Dsize]
Float_t         Dtrk4D0Err[MAX_XB];   //[Dsize]
Int_t           Dtrk3Quality[MAX_XB];   //[Dsize]
Int_t           Dtrk4Quality[MAX_XB];   //[Dsize]
Int_t           Dtrk3Idx[MAX_XB];   //[Dsize]
Int_t           Dtrk4Idx[MAX_XB];   //[Dsize]
Float_t         Dtrk3EtaErr[MAX_XB];   //[Dsize]
Float_t         Dtrk4EtaErr[MAX_XB];   //[Dsize]
Float_t         Dtrk3PhiErr[MAX_XB];   //[Dsize]
Float_t         Dtrk4PhiErr[MAX_XB];   //[Dsize]
Float_t         Dtrk3MVAVal[MAX_XB];   //[Dsize]
Float_t         Dtrk4MVAVal[MAX_XB];   //[Dsize]
Float_t         DtktkResmass[MAX_XB];   //[Dsize]
Float_t         DtktkRes_unfitted_mass[MAX_XB];   //[Dsize]
Float_t         DtktkRespt[MAX_XB];   //[Dsize]
Float_t         DtktkRes_unfitted_pt[MAX_XB];   //[Dsize]
Float_t         DtktkReseta[MAX_XB];   //[Dsize]
Float_t         DtktkResphi[MAX_XB];   //[Dsize]
Float_t         DtktkRes_chi2ndf[MAX_XB];   //[Dsize]
Float_t         DtktkRes_chi2cl[MAX_XB];   //[Dsize]
Float_t         DtktkRes_alpha[MAX_XB];   //[Dsize]
Float_t         DtktkRes_alphaToSV[MAX_XB];   //[Dsize]
Float_t         DtktkRes_svpvDistance[MAX_XB];   //[Dsize]
Float_t         DtktkRes_svpvDisErr[MAX_XB];   //[Dsize]
Float_t         DtktkRes_svpvDistanceToSV[MAX_XB];   //[Dsize]
Float_t         DtktkRes_svpvDisErrToSV[MAX_XB];   //[Dsize]
Float_t         DtktkRes_dca[MAX_XB];   //[Dsize]
Float_t         DtktkRes_dcaToSV[MAX_XB];   //[Dsize]
Float_t         DtktkRes_lxyBS[MAX_XB];   //[Dsize]
Float_t         DtktkRes_lxyBSErr[MAX_XB];   //[Dsize]
Float_t         DtktkRes_angleToTrk1[MAX_XB];   //[Dsize]
Float_t         DtktkRes_unfitted_angleToTrk1[MAX_XB];   //[Dsize]
Float_t         DtktkRes_ptAsymToTrk1[MAX_XB];   //[Dsize]
Float_t         DtktkRes_unfitter_ptAsymToTrk1[MAX_XB];   //[Dsize]
Float_t         DRestrk1Pt[MAX_XB];   //[Dsize]
Float_t         DRestrk2Pt[MAX_XB];   //[Dsize]
Float_t         DRestrk3Pt[MAX_XB];   //[Dsize]
Float_t         DRestrk4Pt[MAX_XB];   //[Dsize]
Float_t         DRestrk1PtErr[MAX_XB];   //[Dsize]
Float_t         DRestrk2PtErr[MAX_XB];   //[Dsize]
Float_t         DRestrk3PtErr[MAX_XB];   //[Dsize]
Float_t         DRestrk4PtErr[MAX_XB];   //[Dsize]
Float_t         DRestrk1Eta[MAX_XB];   //[Dsize]
Float_t         DRestrk2Eta[MAX_XB];   //[Dsize]
Float_t         DRestrk3Eta[MAX_XB];   //[Dsize]
Float_t         DRestrk4Eta[MAX_XB];   //[Dsize]
Float_t         DRestrk1Phi[MAX_XB];   //[Dsize]
Float_t         DRestrk2Phi[MAX_XB];   //[Dsize]
Float_t         DRestrk3Phi[MAX_XB];   //[Dsize]
Float_t         DRestrk4Phi[MAX_XB];   //[Dsize]
Float_t         DRestrk1P[MAX_XB];   //[Dsize]
Float_t         DRestrk2P[MAX_XB];   //[Dsize]
Float_t         DRestrk3P[MAX_XB];   //[Dsize]
Float_t         DRestrk4P[MAX_XB];   //[Dsize]
Float_t         DRestrk1MassHypo[MAX_XB];   //[Dsize]
Float_t         DRestrk2MassHypo[MAX_XB];   //[Dsize]
Float_t         DRestrk3MassHypo[MAX_XB];   //[Dsize]
Float_t         DRestrk4MassHypo[MAX_XB];   //[Dsize]
Float_t         DRestrk1Dz[MAX_XB];   //[Dsize]
Float_t         DRestrk2Dz[MAX_XB];   //[Dsize]
Float_t         DRestrk3Dz[MAX_XB];   //[Dsize]
Float_t         DRestrk4Dz[MAX_XB];   //[Dsize]
Float_t         DRestrk1Dxy[MAX_XB];   //[Dsize]
Float_t         DRestrk2Dxy[MAX_XB];   //[Dsize]
Float_t         DRestrk3Dxy[MAX_XB];   //[Dsize]
Float_t         DRestrk4Dxy[MAX_XB];   //[Dsize]
Int_t           DRestrk1originalAlgo[MAX_XB];   //[Dsize]
Int_t           DRestrk2originalAlgo[MAX_XB];   //[Dsize]
Int_t           DRestrk3originalAlgo[MAX_XB];   //[Dsize]
Int_t           DRestrk4originalAlgo[MAX_XB];   //[Dsize]
Bool_t          DRestrk1highPurity[MAX_XB];   //[Dsize]
Bool_t          DRestrk2highPurity[MAX_XB];   //[Dsize]
Bool_t          DRestrk3highPurity[MAX_XB];   //[Dsize]
Bool_t          DRestrk4highPurity[MAX_XB];   //[Dsize]
Float_t         DRestrk1dedx[MAX_XB];   //[Dsize]
Float_t         DRestrk2dedx[MAX_XB];   //[Dsize]
Float_t         DRestrk3dedx[MAX_XB];   //[Dsize]
Float_t         DRestrk4dedx[MAX_XB];   //[Dsize]
Float_t         DRestrk1thetastar[MAX_XB];   //[Dsize]
Float_t         DRestrk2thetastar[MAX_XB];   //[Dsize]
Float_t         DRestrk3thetastar[MAX_XB];   //[Dsize]
Float_t         DRestrk4thetastar[MAX_XB];   //[Dsize]
Float_t         DRestrk1thetastar_uf[MAX_XB];   //[Dsize]
Float_t         DRestrk2thetastar_uf[MAX_XB];   //[Dsize]
Float_t         DRestrk3thetastar_uf[MAX_XB];   //[Dsize]
Float_t         DRestrk4thetastar_uf[MAX_XB];   //[Dsize]
Float_t         DRestrk1Y[MAX_XB];   //[Dsize]
Float_t         DRestrk2Y[MAX_XB];   //[Dsize]
Float_t         DRestrk3Y[MAX_XB];   //[Dsize]
Float_t         DRestrk4Y[MAX_XB];   //[Dsize]
Float_t         DRestrk1D0[MAX_XB];   //[Dsize]
Float_t         DRestrk2D0[MAX_XB];   //[Dsize]
Float_t         DRestrk3D0[MAX_XB];   //[Dsize]
Float_t         DRestrk4D0[MAX_XB];   //[Dsize]
Float_t         DRestrk1D0Err[MAX_XB];   //[Dsize]
Float_t         DRestrk2D0Err[MAX_XB];   //[Dsize]
Float_t         DRestrk3D0Err[MAX_XB];   //[Dsize]
Float_t         DRestrk4D0Err[MAX_XB];   //[Dsize]
Int_t           DRestrk1Quality[MAX_XB];   //[Dsize]
Int_t           DRestrk2Quality[MAX_XB];   //[Dsize]
Int_t           DRestrk3Quality[MAX_XB];   //[Dsize]
Int_t           DRestrk4Quality[MAX_XB];   //[Dsize]
Float_t         Dgen[MAX_XB];   //[Dsize]
Int_t           DgenIndex[MAX_XB];   //[Dsize]
Int_t           DgennDa[MAX_XB];   //[Dsize]
Float_t         Dgenpt[MAX_XB];   //[Dsize]
Float_t         Dgeneta[MAX_XB];   //[Dsize]
Float_t         Dgenphi[MAX_XB];   //[Dsize]
Float_t         Dgeny[MAX_XB];   //[Dsize]
Int_t           DgencollisionId[MAX_XB];   //[Dsize]
Float_t         DgenBAncestorpt[MAX_XB];   //[Dsize]
Int_t           DgenBAncestorpdgId[MAX_XB];   //[Dsize]
Float_t         DgenprodvtxX[MAX_XB];   //[Dsize]
Float_t         DgenprodvtxY[MAX_XB];   //[Dsize]
Float_t         DgenprodvtxZ[MAX_XB];   //[Dsize]
Float_t         DgendecayvtxX[MAX_XB];   //[Dsize]
Float_t         DgendecayvtxY[MAX_XB];   //[Dsize]
Float_t         DgendecayvtxZ[MAX_XB];   //[Dsize]
Int_t           DgenfromgenPV[MAX_XB];   //[Dsize]

void readBR(TTree*treeIn){
	treeIn->SetBranchAddress("RunNo", &RunNo);
	treeIn->SetBranchAddress("EvtNo", &EvtNo);
	treeIn->SetBranchAddress("LumiNo", &LumiNo);
	treeIn->SetBranchAddress("Dsize", &Dsize);
	treeIn->SetBranchAddress("PVx", &PVx);
	treeIn->SetBranchAddress("PVy", &PVy);
	treeIn->SetBranchAddress("PVz", &PVz);
	treeIn->SetBranchAddress("PVnchi2", &PVnchi2);
	treeIn->SetBranchAddress("BSx", &BSx);
	treeIn->SetBranchAddress("BSy", &BSy);
	treeIn->SetBranchAddress("BSz", &BSz);
	treeIn->SetBranchAddress("PVxE", &PVxE);
	treeIn->SetBranchAddress("PVyE", &PVyE);
	treeIn->SetBranchAddress("PVzE", &PVzE);
	treeIn->SetBranchAddress("BSxErr", &BSxErr);
	treeIn->SetBranchAddress("BSyErr", &BSyErr);
	treeIn->SetBranchAddress("BSzErr", &BSzErr);
	treeIn->SetBranchAddress("BSdxdz", &BSdxdz);
	treeIn->SetBranchAddress("BSdydz", &BSdydz);
	treeIn->SetBranchAddress("BSdxdzErr", &BSdxdzErr);
	treeIn->SetBranchAddress("BSdydzErr", &BSdydzErr);
	treeIn->SetBranchAddress("BSWidthX", &BSWidthX);
	treeIn->SetBranchAddress("BSWidthXErr", &BSWidthXErr);
	treeIn->SetBranchAddress("BSWidthY", &BSWidthY);
	treeIn->SetBranchAddress("BSWidthYErr", &BSWidthYErr);
	treeIn->SetBranchAddress("Dindex", Dindex);
	treeIn->SetBranchAddress("Dtype", Dtype);
	treeIn->SetBranchAddress("Dmass", Dmass);
	treeIn->SetBranchAddress("D_unfitted_mass", D_unfitted_mass);
	treeIn->SetBranchAddress("Dpt", Dpt);
	treeIn->SetBranchAddress("D_unfitted_pt", D_unfitted_pt);
	treeIn->SetBranchAddress("Deta", Deta);
	treeIn->SetBranchAddress("Dphi", Dphi);
	treeIn->SetBranchAddress("Dy", Dy);
	treeIn->SetBranchAddress("DvtxX", DvtxX);
	treeIn->SetBranchAddress("DvtxY", DvtxY);
	treeIn->SetBranchAddress("DvtxZ", DvtxZ);
	treeIn->SetBranchAddress("Dd0", Dd0);
	treeIn->SetBranchAddress("Dd0Err", Dd0Err);
	treeIn->SetBranchAddress("Ddxyz", Ddxyz);
	treeIn->SetBranchAddress("DdxyzErr", DdxyzErr);
	treeIn->SetBranchAddress("Dchi2ndf", Dchi2ndf);
	treeIn->SetBranchAddress("Dchi2cl", Dchi2cl);
	treeIn->SetBranchAddress("Ddtheta", Ddtheta);
	treeIn->SetBranchAddress("Dlxy", Dlxy);
	treeIn->SetBranchAddress("Dalpha", Dalpha);
	treeIn->SetBranchAddress("DsvpvDistance", DsvpvDistance);
	treeIn->SetBranchAddress("DsvpvDisErr", DsvpvDisErr);
	treeIn->SetBranchAddress("DsvpvDistance_2D", DsvpvDistance_2D);
	treeIn->SetBranchAddress("DsvpvDisErr_2D", DsvpvDisErr_2D);
	treeIn->SetBranchAddress("Ddca", Ddca);
	treeIn->SetBranchAddress("DlxyBS", DlxyBS);
	treeIn->SetBranchAddress("DlxyBSErr", DlxyBSErr);
	treeIn->SetBranchAddress("DMaxDoca", DMaxDoca);
	treeIn->SetBranchAddress("DMaxTkPt", DMaxTkPt);
	treeIn->SetBranchAddress("DMinTkPt", DMinTkPt);
	treeIn->SetBranchAddress("Dtrk1Pt", Dtrk1Pt);
	treeIn->SetBranchAddress("Dtrk2Pt", Dtrk2Pt);
	treeIn->SetBranchAddress("Dtrk1PtErr", Dtrk1PtErr);
	treeIn->SetBranchAddress("Dtrk2PtErr", Dtrk2PtErr);
	treeIn->SetBranchAddress("Dtrk1Eta", Dtrk1Eta);
	treeIn->SetBranchAddress("Dtrk2Eta", Dtrk2Eta);
	treeIn->SetBranchAddress("Dtrk1Phi", Dtrk1Phi);
	treeIn->SetBranchAddress("Dtrk2Phi", Dtrk2Phi);
	treeIn->SetBranchAddress("Dtrk1P", Dtrk1P);
	treeIn->SetBranchAddress("Dtrk2P", Dtrk2P);
	treeIn->SetBranchAddress("Dtrk1Dz", Dtrk1Dz);
	treeIn->SetBranchAddress("Dtrk2Dz", Dtrk2Dz);
	treeIn->SetBranchAddress("Dtrk1Dxy", Dtrk1Dxy);
	treeIn->SetBranchAddress("Dtrk2Dxy", Dtrk2Dxy);
	treeIn->SetBranchAddress("Dtrk1MassHypo", Dtrk1MassHypo);
	treeIn->SetBranchAddress("Dtrk2MassHypo", Dtrk2MassHypo);
	treeIn->SetBranchAddress("Dtrk1originalAlgo", Dtrk1originalAlgo);
	treeIn->SetBranchAddress("Dtrk2originalAlgo", Dtrk2originalAlgo);
	treeIn->SetBranchAddress("Dtrk1highPurity", Dtrk1highPurity);
	treeIn->SetBranchAddress("Dtrk2highPurity", Dtrk2highPurity);
	treeIn->SetBranchAddress("Dtrk1dedx", Dtrk1dedx);
	treeIn->SetBranchAddress("Dtrk2dedx", Dtrk2dedx);
	treeIn->SetBranchAddress("Dtrk1thetastar", Dtrk1thetastar);
	treeIn->SetBranchAddress("Dtrk2thetastar", Dtrk2thetastar);
	treeIn->SetBranchAddress("Dtrk1thetastar_uf", Dtrk1thetastar_uf);
	treeIn->SetBranchAddress("Dtrk2thetastar_uf", Dtrk2thetastar_uf);
	treeIn->SetBranchAddress("Dtrk1PixelHit", Dtrk1PixelHit);
	treeIn->SetBranchAddress("Dtrk2PixelHit", Dtrk2PixelHit);
	treeIn->SetBranchAddress("Dtrk1StripHit", Dtrk1StripHit);
	treeIn->SetBranchAddress("Dtrk2StripHit", Dtrk2StripHit);
	treeIn->SetBranchAddress("Dtrk1nStripLayer", Dtrk1nStripLayer);
	treeIn->SetBranchAddress("Dtrk2nStripLayer", Dtrk2nStripLayer);
	treeIn->SetBranchAddress("Dtrk1nPixelLayer", Dtrk1nPixelLayer);
	treeIn->SetBranchAddress("Dtrk2nPixelLayer", Dtrk2nPixelLayer);
	treeIn->SetBranchAddress("Dtrk1Chi2ndf", Dtrk1Chi2ndf);
	treeIn->SetBranchAddress("Dtrk2Chi2ndf", Dtrk2Chi2ndf);
	treeIn->SetBranchAddress("Dtrk1Algo", Dtrk1Algo);
	treeIn->SetBranchAddress("Dtrk2Algo", Dtrk2Algo);
	treeIn->SetBranchAddress("Dtrk3Pt", Dtrk3Pt);
	treeIn->SetBranchAddress("Dtrk4Pt", Dtrk4Pt);
	treeIn->SetBranchAddress("Dtrk3PtErr", Dtrk3PtErr);
	treeIn->SetBranchAddress("Dtrk4PtErr", Dtrk4PtErr);
	treeIn->SetBranchAddress("Dtrk3Eta", Dtrk3Eta);
	treeIn->SetBranchAddress("Dtrk4Eta", Dtrk4Eta);
	treeIn->SetBranchAddress("Dtrk3Phi", Dtrk3Phi);
	treeIn->SetBranchAddress("Dtrk4Phi", Dtrk4Phi);
	treeIn->SetBranchAddress("Dtrk3P", Dtrk3P);
	treeIn->SetBranchAddress("Dtrk4P", Dtrk4P);
	treeIn->SetBranchAddress("Dtrk3MassHypo", Dtrk3MassHypo);
	treeIn->SetBranchAddress("Dtrk4MassHypo", Dtrk4MassHypo);
	treeIn->SetBranchAddress("Dtrk3Dz", Dtrk3Dz);
	treeIn->SetBranchAddress("Dtrk4Dz", Dtrk4Dz);
	treeIn->SetBranchAddress("Dtrk3Dxy", Dtrk3Dxy);
	treeIn->SetBranchAddress("Dtrk4Dxy", Dtrk4Dxy);
	treeIn->SetBranchAddress("Dtrk3originalAlgo", Dtrk3originalAlgo);
	treeIn->SetBranchAddress("Dtrk4originalAlgo", Dtrk4originalAlgo);
	treeIn->SetBranchAddress("Dtrk3highPurity", Dtrk3highPurity);
	treeIn->SetBranchAddress("Dtrk4highPurity", Dtrk4highPurity);
	treeIn->SetBranchAddress("Dtrk3dedx", Dtrk3dedx);
	treeIn->SetBranchAddress("Dtrk4dedx", Dtrk4dedx);
	treeIn->SetBranchAddress("Dtrk3thetastar", Dtrk3thetastar);
	treeIn->SetBranchAddress("Dtrk4thetastar", Dtrk4thetastar);
	treeIn->SetBranchAddress("Dtrk3thetastar_uf", Dtrk3thetastar_uf);
	treeIn->SetBranchAddress("Dtrk4thetastar_uf", Dtrk4thetastar_uf);
	treeIn->SetBranchAddress("Dtrk3PixelHit", Dtrk3PixelHit);
	treeIn->SetBranchAddress("Dtrk4PixelHit", Dtrk4PixelHit);
	treeIn->SetBranchAddress("Dtrk3StripHit", Dtrk3StripHit);
	treeIn->SetBranchAddress("Dtrk4StripHit", Dtrk4StripHit);
	treeIn->SetBranchAddress("Dtrk3nStripLayer", Dtrk3nStripLayer);
	treeIn->SetBranchAddress("Dtrk4nStripLayer", Dtrk4nStripLayer);
	treeIn->SetBranchAddress("Dtrk3nPixelLayer", Dtrk3nPixelLayer);
	treeIn->SetBranchAddress("Dtrk4nPixelLayer", Dtrk4nPixelLayer);
	treeIn->SetBranchAddress("Dtrk3Chi2ndf", Dtrk3Chi2ndf);
	treeIn->SetBranchAddress("Dtrk4Chi2ndf", Dtrk4Chi2ndf);
	treeIn->SetBranchAddress("Dtrk3Algo", Dtrk3Algo);
	treeIn->SetBranchAddress("Dtrk4Algo", Dtrk4Algo);
	treeIn->SetBranchAddress("Dtrk1Y", Dtrk1Y);
	treeIn->SetBranchAddress("Dtrk2Y", Dtrk2Y);
	treeIn->SetBranchAddress("Dtrk1D0", Dtrk1D0);
	treeIn->SetBranchAddress("Dtrk2D0", Dtrk2D0);
	treeIn->SetBranchAddress("Dtrk1D0Err", Dtrk1D0Err);
	treeIn->SetBranchAddress("Dtrk2D0Err", Dtrk2D0Err);
	treeIn->SetBranchAddress("Dtrk1Quality", Dtrk1Quality);
	treeIn->SetBranchAddress("Dtrk2Quality", Dtrk2Quality);
	treeIn->SetBranchAddress("Dtrk1Idx", Dtrk1Idx);
	treeIn->SetBranchAddress("Dtrk2Idx", Dtrk2Idx);
	treeIn->SetBranchAddress("Dtrk1EtaErr", Dtrk1EtaErr);
	treeIn->SetBranchAddress("Dtrk2EtaErr", Dtrk2EtaErr);
	treeIn->SetBranchAddress("Dtrk1PhiErr", Dtrk1PhiErr);
	treeIn->SetBranchAddress("Dtrk2PhiErr", Dtrk2PhiErr);
	treeIn->SetBranchAddress("Dtrk1MVAVal", Dtrk1MVAVal);
	treeIn->SetBranchAddress("Dtrk2MVAVal", Dtrk2MVAVal);
	treeIn->SetBranchAddress("Dtrk3Y", Dtrk3Y);
	treeIn->SetBranchAddress("Dtrk4Y", Dtrk4Y);
	treeIn->SetBranchAddress("Dtrk3D0", Dtrk3D0);
	treeIn->SetBranchAddress("Dtrk4D0", Dtrk4D0);
	treeIn->SetBranchAddress("Dtrk3D0Err", Dtrk3D0Err);
	treeIn->SetBranchAddress("Dtrk4D0Err", Dtrk4D0Err);
	treeIn->SetBranchAddress("Dtrk3Quality", Dtrk3Quality);
	treeIn->SetBranchAddress("Dtrk4Quality", Dtrk4Quality);
	treeIn->SetBranchAddress("Dtrk3Idx", Dtrk3Idx);
	treeIn->SetBranchAddress("Dtrk4Idx", Dtrk4Idx);
	treeIn->SetBranchAddress("Dtrk3EtaErr", Dtrk3EtaErr);
	treeIn->SetBranchAddress("Dtrk4EtaErr", Dtrk4EtaErr);
	treeIn->SetBranchAddress("Dtrk3PhiErr", Dtrk3PhiErr);
	treeIn->SetBranchAddress("Dtrk4PhiErr", Dtrk4PhiErr);
	treeIn->SetBranchAddress("Dtrk3MVAVal", Dtrk3MVAVal);
	treeIn->SetBranchAddress("Dtrk4MVAVal", Dtrk4MVAVal);
	treeIn->SetBranchAddress("DtktkResmass", DtktkResmass);
	treeIn->SetBranchAddress("DtktkRes_unfitted_mass", DtktkRes_unfitted_mass);
	treeIn->SetBranchAddress("DtktkRespt", DtktkRespt);
	treeIn->SetBranchAddress("DtktkRes_unfitted_pt", DtktkRes_unfitted_pt);
	treeIn->SetBranchAddress("DtktkReseta", DtktkReseta);
	treeIn->SetBranchAddress("DtktkResphi", DtktkResphi);
	treeIn->SetBranchAddress("DtktkRes_chi2ndf", DtktkRes_chi2ndf);
	treeIn->SetBranchAddress("DtktkRes_chi2cl", DtktkRes_chi2cl);
	treeIn->SetBranchAddress("DtktkRes_alpha", DtktkRes_alpha);
	treeIn->SetBranchAddress("DtktkRes_alphaToSV", DtktkRes_alphaToSV);
	treeIn->SetBranchAddress("DtktkRes_svpvDistance", DtktkRes_svpvDistance);
	treeIn->SetBranchAddress("DtktkRes_svpvDisErr", DtktkRes_svpvDisErr);
	treeIn->SetBranchAddress("DtktkRes_svpvDistanceToSV", DtktkRes_svpvDistanceToSV);
	treeIn->SetBranchAddress("DtktkRes_svpvDisErrToSV", DtktkRes_svpvDisErrToSV);
	treeIn->SetBranchAddress("DtktkRes_dca", DtktkRes_dca);
	treeIn->SetBranchAddress("DtktkRes_dcaToSV", DtktkRes_dcaToSV);
	treeIn->SetBranchAddress("DtktkRes_lxyBS", DtktkRes_lxyBS);
	treeIn->SetBranchAddress("DtktkRes_lxyBSErr", DtktkRes_lxyBSErr);
	treeIn->SetBranchAddress("DtktkRes_angleToTrk1", DtktkRes_angleToTrk1);
	treeIn->SetBranchAddress("DtktkRes_unfitted_angleToTrk1", DtktkRes_unfitted_angleToTrk1);
	treeIn->SetBranchAddress("DtktkRes_ptAsymToTrk1", DtktkRes_ptAsymToTrk1);
	treeIn->SetBranchAddress("DtktkRes_unfitter_ptAsymToTrk1", DtktkRes_unfitter_ptAsymToTrk1);
	treeIn->SetBranchAddress("DRestrk1Pt", DRestrk1Pt);
	treeIn->SetBranchAddress("DRestrk2Pt", DRestrk2Pt);
	treeIn->SetBranchAddress("DRestrk3Pt", DRestrk3Pt);
	treeIn->SetBranchAddress("DRestrk4Pt", DRestrk4Pt);
	treeIn->SetBranchAddress("DRestrk1PtErr", DRestrk1PtErr);
	treeIn->SetBranchAddress("DRestrk2PtErr", DRestrk2PtErr);
	treeIn->SetBranchAddress("DRestrk3PtErr", DRestrk3PtErr);
	treeIn->SetBranchAddress("DRestrk4PtErr", DRestrk4PtErr);
	treeIn->SetBranchAddress("DRestrk1Eta", DRestrk1Eta);
	treeIn->SetBranchAddress("DRestrk2Eta", DRestrk2Eta);
	treeIn->SetBranchAddress("DRestrk3Eta", DRestrk3Eta);
	treeIn->SetBranchAddress("DRestrk4Eta", DRestrk4Eta);
	treeIn->SetBranchAddress("DRestrk1Phi", DRestrk1Phi);
	treeIn->SetBranchAddress("DRestrk2Phi", DRestrk2Phi);
	treeIn->SetBranchAddress("DRestrk3Phi", DRestrk3Phi);
	treeIn->SetBranchAddress("DRestrk4Phi", DRestrk4Phi);
	treeIn->SetBranchAddress("DRestrk1P", DRestrk1P);
	treeIn->SetBranchAddress("DRestrk2P", DRestrk2P);
	treeIn->SetBranchAddress("DRestrk3P", DRestrk3P);
	treeIn->SetBranchAddress("DRestrk4P", DRestrk4P);
	treeIn->SetBranchAddress("DRestrk1MassHypo", DRestrk1MassHypo);
	treeIn->SetBranchAddress("DRestrk2MassHypo", DRestrk2MassHypo);
	treeIn->SetBranchAddress("DRestrk3MassHypo", DRestrk3MassHypo);
	treeIn->SetBranchAddress("DRestrk4MassHypo", DRestrk4MassHypo);
	treeIn->SetBranchAddress("DRestrk1Dz", DRestrk1Dz);
	treeIn->SetBranchAddress("DRestrk2Dz", DRestrk2Dz);
	treeIn->SetBranchAddress("DRestrk3Dz", DRestrk3Dz);
	treeIn->SetBranchAddress("DRestrk4Dz", DRestrk4Dz);
	treeIn->SetBranchAddress("DRestrk1Dxy", DRestrk1Dxy);
	treeIn->SetBranchAddress("DRestrk2Dxy", DRestrk2Dxy);
	treeIn->SetBranchAddress("DRestrk3Dxy", DRestrk3Dxy);
	treeIn->SetBranchAddress("DRestrk4Dxy", DRestrk4Dxy);
	treeIn->SetBranchAddress("DRestrk1originalAlgo", DRestrk1originalAlgo);
	treeIn->SetBranchAddress("DRestrk2originalAlgo", DRestrk2originalAlgo);
	treeIn->SetBranchAddress("DRestrk3originalAlgo", DRestrk3originalAlgo);
	treeIn->SetBranchAddress("DRestrk4originalAlgo", DRestrk4originalAlgo);
	treeIn->SetBranchAddress("DRestrk1highPurity", DRestrk1highPurity);
	treeIn->SetBranchAddress("DRestrk2highPurity", DRestrk2highPurity);
	treeIn->SetBranchAddress("DRestrk3highPurity", DRestrk3highPurity);
	treeIn->SetBranchAddress("DRestrk4highPurity", DRestrk4highPurity);
	treeIn->SetBranchAddress("DRestrk1dedx", DRestrk1dedx);
	treeIn->SetBranchAddress("DRestrk2dedx", DRestrk2dedx);
	treeIn->SetBranchAddress("DRestrk3dedx", DRestrk3dedx);
	treeIn->SetBranchAddress("DRestrk4dedx", DRestrk4dedx);
	treeIn->SetBranchAddress("DRestrk1thetastar", DRestrk1thetastar);
	treeIn->SetBranchAddress("DRestrk2thetastar", DRestrk2thetastar);
	treeIn->SetBranchAddress("DRestrk3thetastar", DRestrk3thetastar);
	treeIn->SetBranchAddress("DRestrk4thetastar", DRestrk4thetastar);
	treeIn->SetBranchAddress("DRestrk1thetastar_uf", DRestrk1thetastar_uf);
	treeIn->SetBranchAddress("DRestrk2thetastar_uf", DRestrk2thetastar_uf);
	treeIn->SetBranchAddress("DRestrk3thetastar_uf", DRestrk3thetastar_uf);
	treeIn->SetBranchAddress("DRestrk4thetastar_uf", DRestrk4thetastar_uf);
	treeIn->SetBranchAddress("DRestrk1Y", DRestrk1Y);
	treeIn->SetBranchAddress("DRestrk2Y", DRestrk2Y);
	treeIn->SetBranchAddress("DRestrk3Y", DRestrk3Y);
	treeIn->SetBranchAddress("DRestrk4Y", DRestrk4Y);
	treeIn->SetBranchAddress("DRestrk1D0", DRestrk1D0);
	treeIn->SetBranchAddress("DRestrk2D0", DRestrk2D0);
	treeIn->SetBranchAddress("DRestrk3D0", DRestrk3D0);
	treeIn->SetBranchAddress("DRestrk4D0", DRestrk4D0);
	treeIn->SetBranchAddress("DRestrk1D0Err", DRestrk1D0Err);
	treeIn->SetBranchAddress("DRestrk2D0Err", DRestrk2D0Err);
	treeIn->SetBranchAddress("DRestrk3D0Err", DRestrk3D0Err);
	treeIn->SetBranchAddress("DRestrk4D0Err", DRestrk4D0Err);
	treeIn->SetBranchAddress("DRestrk1Quality", DRestrk1Quality);
	treeIn->SetBranchAddress("DRestrk2Quality", DRestrk2Quality);
	treeIn->SetBranchAddress("DRestrk3Quality", DRestrk3Quality);
	treeIn->SetBranchAddress("DRestrk4Quality", DRestrk4Quality);
	treeIn->SetBranchAddress("Dgen", Dgen);
	treeIn->SetBranchAddress("DgenIndex", DgenIndex);
	treeIn->SetBranchAddress("DgennDa", DgennDa);
	treeIn->SetBranchAddress("Dgenpt", Dgenpt);
	treeIn->SetBranchAddress("Dgeneta", Dgeneta);
	treeIn->SetBranchAddress("Dgenphi", Dgenphi);
	treeIn->SetBranchAddress("Dgeny", Dgeny);
	treeIn->SetBranchAddress("DgencollisionId", DgencollisionId);
	treeIn->SetBranchAddress("DgenBAncestorpt", DgenBAncestorpt);
	treeIn->SetBranchAddress("DgenBAncestorpdgId", DgenBAncestorpdgId);
	treeIn->SetBranchAddress("DgenprodvtxX", DgenprodvtxX);
	treeIn->SetBranchAddress("DgenprodvtxY", DgenprodvtxY);
	treeIn->SetBranchAddress("DgenprodvtxZ", DgenprodvtxZ);
	treeIn->SetBranchAddress("DgendecayvtxX", DgendecayvtxX);
	treeIn->SetBranchAddress("DgendecayvtxY", DgendecayvtxY);
	treeIn->SetBranchAddress("DgendecayvtxZ", DgendecayvtxZ);
	treeIn->SetBranchAddress("DgenfromgenPV", DgenfromgenPV);
}

Int_t           new_RunNo;
Int_t           new_EvtNo;
Int_t           new_LumiNo;
Int_t           new_Dsize;
Float_t         new_PVx;
Float_t         new_PVy;
Float_t         new_PVz;
Float_t         new_PVnchi2;
Float_t         new_BSx;
Float_t         new_BSy;
Float_t         new_BSz;
Float_t         new_PVxE;
Float_t         new_PVyE;
Float_t         new_PVzE;
Float_t         new_BSxErr;
Float_t         new_BSyErr;
Float_t         new_BSzErr;
Float_t         new_BSdxdz;
Float_t         new_BSdydz;
Float_t         new_BSdxdzErr;
Float_t         new_BSdydzErr;
Float_t         new_BSWidthX;
Float_t         new_BSWidthXErr;
Float_t         new_BSWidthY;
Float_t         new_BSWidthYErr;
Int_t           new_Dindex[MAX_XB];   //[Dsize]
Int_t           new_Dtype[MAX_XB];   //[Dsize]
Float_t         new_Dmass[MAX_XB];   //[Dsize]
Float_t         new_D_unfitted_mass[MAX_XB];   //[Dsize]
Float_t         new_Dpt[MAX_XB];   //[Dsize]
Float_t         new_D_unfitted_pt[MAX_XB];   //[Dsize]
Float_t         new_Deta[MAX_XB];   //[Dsize]
Float_t         new_Dphi[MAX_XB];   //[Dsize]
Float_t         new_Dy[MAX_XB];   //[Dsize]
Float_t         new_DvtxX[MAX_XB];   //[Dsize]
Float_t         new_DvtxY[MAX_XB];   //[Dsize]
Float_t         new_DvtxZ[MAX_XB];   //[Dsize]
Float_t         new_Dd0[MAX_XB];   //[Dsize]
Float_t         new_Dd0Err[MAX_XB];   //[Dsize]
Float_t         new_Ddxyz[MAX_XB];   //[Dsize]
Float_t         new_DdxyzErr[MAX_XB];   //[Dsize]
Float_t         new_Dchi2ndf[MAX_XB];   //[Dsize]
Float_t         new_Dchi2cl[MAX_XB];   //[Dsize]
Float_t         new_Ddtheta[MAX_XB];   //[Dsize]
Float_t         new_Dlxy[MAX_XB];   //[Dsize]
Float_t         new_Dalpha[MAX_XB];   //[Dsize]
Float_t         new_DsvpvDistance[MAX_XB];   //[Dsize]
Float_t         new_DsvpvDisErr[MAX_XB];   //[Dsize]
Float_t         new_DsvpvDistance_2D[MAX_XB];   //[Dsize]
Float_t         new_DsvpvDisErr_2D[MAX_XB];   //[Dsize]
Float_t         new_Ddca[MAX_XB];   //[Dsize]
Float_t         new_DlxyBS[MAX_XB];   //[Dsize]
Float_t         new_DlxyBSErr[MAX_XB];   //[Dsize]
Float_t         new_DMaxDoca[MAX_XB];   //[Dsize]
Float_t         new_DMaxTkPt[MAX_XB];   //[Dsize]
Float_t         new_DMinTkPt[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1Pt[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2Pt[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1PtErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2PtErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1Eta[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2Eta[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1Phi[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2Phi[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1P[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2P[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1Dz[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2Dz[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1Dxy[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2Dxy[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1MassHypo[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2MassHypo[MAX_XB];   //[Dsize]
Int_t           new_Dtrk1originalAlgo[MAX_XB];   //[Dsize]
Int_t           new_Dtrk2originalAlgo[MAX_XB];   //[Dsize]
Bool_t          new_Dtrk1highPurity[MAX_XB];   //[Dsize]
Bool_t          new_Dtrk2highPurity[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1dedx[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2dedx[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1thetastar[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2thetastar[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1thetastar_uf[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2thetastar_uf[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1PixelHit[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2PixelHit[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1StripHit[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2StripHit[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1nStripLayer[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2nStripLayer[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1nPixelLayer[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2nPixelLayer[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1Chi2ndf[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2Chi2ndf[MAX_XB];   //[Dsize]
Int_t           new_Dtrk1Algo[MAX_XB];   //[Dsize]
Int_t           new_Dtrk2Algo[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3Pt[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4Pt[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3PtErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4PtErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3Eta[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4Eta[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3Phi[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4Phi[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3P[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4P[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3MassHypo[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4MassHypo[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3Dz[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4Dz[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3Dxy[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4Dxy[MAX_XB];   //[Dsize]
Int_t           new_Dtrk3originalAlgo[MAX_XB];   //[Dsize]
Int_t           new_Dtrk4originalAlgo[MAX_XB];   //[Dsize]
Bool_t          new_Dtrk3highPurity[MAX_XB];   //[Dsize]
Bool_t          new_Dtrk4highPurity[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3dedx[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4dedx[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3thetastar[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4thetastar[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3thetastar_uf[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4thetastar_uf[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3PixelHit[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4PixelHit[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3StripHit[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4StripHit[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3nStripLayer[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4nStripLayer[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3nPixelLayer[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4nPixelLayer[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3Chi2ndf[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4Chi2ndf[MAX_XB];   //[Dsize]
Int_t           new_Dtrk3Algo[MAX_XB];   //[Dsize]
Int_t           new_Dtrk4Algo[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1Y[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2Y[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1D0[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2D0[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1D0Err[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2D0Err[MAX_XB];   //[Dsize]
Int_t           new_Dtrk1Quality[MAX_XB];   //[Dsize]
Int_t           new_Dtrk2Quality[MAX_XB];   //[Dsize]
Int_t           new_Dtrk1Idx[MAX_XB];   //[Dsize]
Int_t           new_Dtrk2Idx[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1EtaErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2EtaErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1PhiErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2PhiErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk1MVAVal[MAX_XB];   //[Dsize]
Float_t         new_Dtrk2MVAVal[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3Y[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4Y[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3D0[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4D0[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3D0Err[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4D0Err[MAX_XB];   //[Dsize]
Int_t           new_Dtrk3Quality[MAX_XB];   //[Dsize]
Int_t           new_Dtrk4Quality[MAX_XB];   //[Dsize]
Int_t           new_Dtrk3Idx[MAX_XB];   //[Dsize]
Int_t           new_Dtrk4Idx[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3EtaErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4EtaErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3PhiErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4PhiErr[MAX_XB];   //[Dsize]
Float_t         new_Dtrk3MVAVal[MAX_XB];   //[Dsize]
Float_t         new_Dtrk4MVAVal[MAX_XB];   //[Dsize]
Float_t         new_DtktkResmass[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_unfitted_mass[MAX_XB];   //[Dsize]
Float_t         new_DtktkRespt[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_unfitted_pt[MAX_XB];   //[Dsize]
Float_t         new_DtktkReseta[MAX_XB];   //[Dsize]
Float_t         new_DtktkResphi[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_chi2ndf[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_chi2cl[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_alpha[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_alphaToSV[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_svpvDistance[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_svpvDisErr[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_svpvDistanceToSV[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_svpvDisErrToSV[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_dca[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_dcaToSV[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_lxyBS[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_lxyBSErr[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_angleToTrk1[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_unfitted_angleToTrk1[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_ptAsymToTrk1[MAX_XB];   //[Dsize]
Float_t         new_DtktkRes_unfitter_ptAsymToTrk1[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1Pt[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2Pt[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3Pt[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4Pt[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1PtErr[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2PtErr[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3PtErr[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4PtErr[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1Eta[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2Eta[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3Eta[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4Eta[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1Phi[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2Phi[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3Phi[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4Phi[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1P[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2P[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3P[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4P[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1MassHypo[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2MassHypo[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3MassHypo[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4MassHypo[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1Dz[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2Dz[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3Dz[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4Dz[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1Dxy[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2Dxy[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3Dxy[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4Dxy[MAX_XB];   //[Dsize]
Int_t           new_DRestrk1originalAlgo[MAX_XB];   //[Dsize]
Int_t           new_DRestrk2originalAlgo[MAX_XB];   //[Dsize]
Int_t           new_DRestrk3originalAlgo[MAX_XB];   //[Dsize]
Int_t           new_DRestrk4originalAlgo[MAX_XB];   //[Dsize]
Bool_t          new_DRestrk1highPurity[MAX_XB];   //[Dsize]
Bool_t          new_DRestrk2highPurity[MAX_XB];   //[Dsize]
Bool_t          new_DRestrk3highPurity[MAX_XB];   //[Dsize]
Bool_t          new_DRestrk4highPurity[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1dedx[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2dedx[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3dedx[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4dedx[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1thetastar[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2thetastar[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3thetastar[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4thetastar[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1thetastar_uf[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2thetastar_uf[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3thetastar_uf[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4thetastar_uf[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1Y[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2Y[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3Y[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4Y[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1D0[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2D0[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3D0[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4D0[MAX_XB];   //[Dsize]
Float_t         new_DRestrk1D0Err[MAX_XB];   //[Dsize]
Float_t         new_DRestrk2D0Err[MAX_XB];   //[Dsize]
Float_t         new_DRestrk3D0Err[MAX_XB];   //[Dsize]
Float_t         new_DRestrk4D0Err[MAX_XB];   //[Dsize]
Int_t           new_DRestrk1Quality[MAX_XB];   //[Dsize]
Int_t           new_DRestrk2Quality[MAX_XB];   //[Dsize]
Int_t           new_DRestrk3Quality[MAX_XB];   //[Dsize]
Int_t           new_DRestrk4Quality[MAX_XB];   //[Dsize]
Float_t         new_Dgen[MAX_XB];   //[Dsize]
Int_t           new_DgenIndex[MAX_XB];   //[Dsize]
Int_t           new_DgennDa[MAX_XB];   //[Dsize]
Float_t         new_Dgenpt[MAX_XB];   //[Dsize]
Float_t         new_Dgeneta[MAX_XB];   //[Dsize]
Float_t         new_Dgenphi[MAX_XB];   //[Dsize]
Float_t         new_Dgeny[MAX_XB];   //[Dsize]
Int_t           new_DgencollisionId[MAX_XB];   //[Dsize]
Float_t         new_DgenBAncestorpt[MAX_XB];   //[Dsize]
Int_t           new_DgenBAncestorpdgId[MAX_XB];   //[Dsize]
Float_t         new_DgenprodvtxX[MAX_XB];   //[Dsize]
Float_t         new_DgenprodvtxY[MAX_XB];   //[Dsize]
Float_t         new_DgenprodvtxZ[MAX_XB];   //[Dsize]
Float_t         new_DgendecayvtxX[MAX_XB];   //[Dsize]
Float_t         new_DgendecayvtxY[MAX_XB];   //[Dsize]
Float_t         new_DgendecayvtxZ[MAX_XB];   //[Dsize]
Int_t           new_DgenfromgenPV[MAX_XB];   //[Dsize]

void buildBR(TTree* treeOut){
	treeOut->Branch("RunNo",&RunNo);
	treeOut->Branch("EvtNo",&EvtNo);
	treeOut->Branch("LumiNo",&LumiNo);
	treeOut->Branch("Dsize",&new_Dsize);
	treeOut->Branch("PVx",&PVx);
	treeOut->Branch("PVy",&PVy);
	treeOut->Branch("PVz",&PVz);
	treeOut->Branch("PVnchi2",&PVnchi2);
	treeOut->Branch("BSx",&BSx);
	treeOut->Branch("BSy",&BSy);
	treeOut->Branch("BSz",&BSz);
	treeOut->Branch("PVxE",&PVxE);
	treeOut->Branch("PVyE",&PVyE);
	treeOut->Branch("PVzE",&PVzE);
	treeOut->Branch("BSxErr",&BSxErr);
	treeOut->Branch("BSyErr",&BSyErr);
	treeOut->Branch("BSzErr",&BSzErr);
	treeOut->Branch("BSdxdz",&BSdxdz);
	treeOut->Branch("BSdydz",&BSdydz);
	treeOut->Branch("BSdxdzErr",&BSdxdzErr);
	treeOut->Branch("BSdydzErr",&BSdydzErr);
	treeOut->Branch("BSWidthX",&BSWidthX);
	treeOut->Branch("BSWidthXErr",&BSWidthXErr);
	treeOut->Branch("BSWidthY",&BSWidthY);
	treeOut->Branch("BSWidthYErr",&BSWidthYErr);        
	treeOut->Branch("Dindex",new_Dindex,"Dindex[Dsize]/I");
	treeOut->Branch("Dtype",new_Dtype,"Dtype[Dsize]/I");
	treeOut->Branch("Dmass",new_Dmass,"Dmass[Dsize]/F");
	treeOut->Branch("D_unfitted_mass",new_D_unfitted_mass,"D_unfitted_mass[Dsize]/F");
	treeOut->Branch("Dpt",new_Dpt,"Dpt[Dsize]/F");
	treeOut->Branch("D_unfitted_pt",new_D_unfitted_pt,"D_unfitted_pt[Dsize]/F");
	treeOut->Branch("Deta",new_Deta,"Deta[Dsize]/F");
	treeOut->Branch("Dphi",new_Dphi,"Dphi[Dsize]/F");
	treeOut->Branch("Dy",new_Dy,"Dy[Dsize]/F");
	treeOut->Branch("DvtxX",new_DvtxX,"DvtxX[Dsize]/F");
	treeOut->Branch("DvtxY",new_DvtxY,"DvtxY[Dsize]/F");
	treeOut->Branch("DvtxZ",new_DvtxZ,"DvtxZ[Dsize]/F");
	treeOut->Branch("Dd0",new_Dd0,"Dd0[Dsize]/F");
	treeOut->Branch("Dd0Err",new_Dd0Err,"Dd0Err[Dsize]/F");
	treeOut->Branch("Ddxyz",new_Ddxyz,"Ddxyz[Dsize]/F");
	treeOut->Branch("DdxyzErr",new_DdxyzErr,"DdxyzErr[Dsize]/F");
	treeOut->Branch("Dchi2ndf",new_Dchi2ndf,"Dchi2ndf[Dsize]/F");
	treeOut->Branch("Dchi2cl",new_Dchi2cl,"Dchi2cl[Dsize]/F");
	treeOut->Branch("Ddtheta",new_Ddtheta,"Ddtheta[Dsize]/F");
	treeOut->Branch("Dlxy",new_Dlxy,"Dlxy[Dsize]/F");
	treeOut->Branch("Dalpha",new_Dalpha,"Dalpha[Dsize]/F");
	treeOut->Branch("DsvpvDistance",new_DsvpvDistance,"DsvpvDistance[Dsize]/F");
	treeOut->Branch("DsvpvDisErr",new_DsvpvDisErr,"DsvpvDisErr[Dsize]/F");
	treeOut->Branch("DsvpvDistance_2D",new_DsvpvDistance_2D,"DsvpvDistance_2D[Dsize]/F");
	treeOut->Branch("DsvpvDisErr_2D",new_DsvpvDisErr_2D,"DsvpvDisErr_2D[Dsize]/F");
	treeOut->Branch("Ddca",new_Ddca,"Ddca[Dsize]/F");
	treeOut->Branch("DlxyBS",new_DlxyBS,"DlxyBS[Dsize]/F");
	treeOut->Branch("DlxyBSErr",new_DlxyBSErr,"DlxyBSErr[Dsize]/F");
	treeOut->Branch("DMaxDoca",new_DMaxDoca,"DMaxDoca[Dsize]/F");
	treeOut->Branch("DMaxTkPt",new_DMaxTkPt,"DMaxTkPt[Dsize]/F");
	treeOut->Branch("DMinTkPt",new_DMinTkPt,"DMinTkPt[Dsize]/F");
	treeOut->Branch("Dtrk1Pt",new_Dtrk1Pt,"Dtrk1Pt[Dsize]/F");
//	treeOut->Branch("Dtrk2Pt",new_Dtrk2Pt,"Dtrk2Pt[Dsize]/F");
	treeOut->Branch("Dtrk1PtErr",new_Dtrk1PtErr,"Dtrk1PtErr[Dsize]/F");
//	treeOut->Branch("Dtrk2PtErr",new_Dtrk2PtErr,"Dtrk2PtErr[Dsize]/F");
	treeOut->Branch("Dtrk1Eta",new_Dtrk1Eta,"Dtrk1Eta[Dsize]/F");
//	treeOut->Branch("Dtrk2Eta",new_Dtrk2Eta,"Dtrk2Eta[Dsize]/F");
	treeOut->Branch("Dtrk1Phi",new_Dtrk1Phi,"Dtrk1Phi[Dsize]/F");
//	treeOut->Branch("Dtrk2Phi",new_Dtrk2Phi,"Dtrk2Phi[Dsize]/F");
	treeOut->Branch("Dtrk1P",new_Dtrk1P,"Dtrk1P[Dsize]/F");
//	treeOut->Branch("Dtrk2P",new_Dtrk2P,"Dtrk2P[Dsize]/F");
	treeOut->Branch("Dtrk1Dz",new_Dtrk1Dz,"Dtrk1Dz[Dsize]/F");
//	treeOut->Branch("Dtrk2Dz",new_Dtrk2Dz,"Dtrk2Dz[Dsize]/F");
	treeOut->Branch("Dtrk1Dxy",new_Dtrk1Dxy,"Dtrk1Dxy[Dsize]/F");
//	treeOut->Branch("Dtrk2Dxy",new_Dtrk2Dxy,"Dtrk2Dxy[Dsize]/F");
	treeOut->Branch("Dtrk1MassHypo",new_Dtrk1MassHypo,"Dtrk1MassHypo[Dsize]/F");
//	treeOut->Branch("Dtrk2MassHypo",new_Dtrk2MassHypo,"Dtrk2MassHypo[Dsize]/F");
	treeOut->Branch("Dtrk1originalAlgo",new_Dtrk1originalAlgo,"Dtrk1originalAlgo[Dsize]/I");
//	treeOut->Branch("Dtrk2originalAlgo",new_Dtrk2originalAlgo,"Dtrk2originalAlgo[Dsize]/I");
	treeOut->Branch("Dtrk1highPurity",new_Dtrk1highPurity,"Dtrk1highPurity[Dsize]/O");
//	treeOut->Branch("Dtrk2highPurity",new_Dtrk2highPurity,"Dtrk2highPurity[Dsize]/O");
	treeOut->Branch("Dtrk1dedx",new_Dtrk1dedx,"Dtrk1dedx[Dsize]/F");
//	treeOut->Branch("Dtrk2dedx",new_Dtrk2dedx,"Dtrk2dedx[Dsize]/F");
	treeOut->Branch("Dtrk1thetastar",new_Dtrk1thetastar,"Dtrk1thetastar[Dsize]/F");
//	treeOut->Branch("Dtrk2thetastar",new_Dtrk2thetastar,"Dtrk2thetastar[Dsize]/F");
	treeOut->Branch("Dtrk1thetastar_uf",new_Dtrk1thetastar_uf,"Dtrk1thetastar_uf[Dsize]/F");
//	treeOut->Branch("Dtrk2thetastar_uf",new_Dtrk2thetastar_uf,"Dtrk2thetastar_uf[Dsize]/F");
	treeOut->Branch("Dtrk1PixelHit",new_Dtrk1PixelHit,"Dtrk1PixelHit[Dsize]/F");
//	treeOut->Branch("Dtrk2PixelHit",new_Dtrk2PixelHit,"Dtrk2PixelHit[Dsize]/F");
	treeOut->Branch("Dtrk1StripHit",new_Dtrk1StripHit,"Dtrk1StripHit[Dsize]/F");
//	treeOut->Branch("Dtrk2StripHit",new_Dtrk2StripHit,"Dtrk2StripHit[Dsize]/F");
	treeOut->Branch("Dtrk1nStripLayer",new_Dtrk1nStripLayer,"Dtrk1nStripLayer[Dsize]/F");
//	treeOut->Branch("Dtrk2nStripLayer",new_Dtrk2nStripLayer,"Dtrk2nStripLayer[Dsize]/F");
	treeOut->Branch("Dtrk1nPixelLayer",new_Dtrk1nPixelLayer,"Dtrk1nPixelLayer[Dsize]/F");
//	treeOut->Branch("Dtrk2nPixelLayer",new_Dtrk2nPixelLayer,"Dtrk2nPixelLayer[Dsize]/F");
	treeOut->Branch("Dtrk1Chi2ndf",new_Dtrk1Chi2ndf,"Dtrk1Chi2ndf[Dsize]/F");
//	treeOut->Branch("Dtrk2Chi2ndf",new_Dtrk2Chi2ndf,"Dtrk2Chi2ndf[Dsize]/F");
	treeOut->Branch("Dtrk1Algo",new_Dtrk1Algo,"Dtrk1Algo[Dsize]/I");
//	treeOut->Branch("Dtrk2Algo",new_Dtrk2Algo,"Dtrk2Algo[Dsize]/I");
//	treeOut->Branch("Dtrk3Pt",new_Dtrk3Pt,"Dtrk3Pt[Dsize]/F");
//	treeOut->Branch("Dtrk4Pt",new_Dtrk4Pt,"Dtrk4Pt[Dsize]/F");
//	treeOut->Branch("Dtrk3PtErr",new_Dtrk3PtErr,"Dtrk3PtErr[Dsize]/F");
//	treeOut->Branch("Dtrk4PtErr",new_Dtrk4PtErr,"Dtrk4PtErr[Dsize]/F");
//	treeOut->Branch("Dtrk3Eta",new_Dtrk3Eta,"Dtrk3Eta[Dsize]/F");
//	treeOut->Branch("Dtrk4Eta",new_Dtrk4Eta,"Dtrk4Eta[Dsize]/F");
//	treeOut->Branch("Dtrk3Phi",new_Dtrk3Phi,"Dtrk3Phi[Dsize]/F");
//	treeOut->Branch("Dtrk4Phi",new_Dtrk4Phi,"Dtrk4Phi[Dsize]/F");
//	treeOut->Branch("Dtrk3P",new_Dtrk3P,"Dtrk3P[Dsize]/F");
//	treeOut->Branch("Dtrk4P",new_Dtrk4P,"Dtrk4P[Dsize]/F");
//	treeOut->Branch("Dtrk3MassHypo",new_Dtrk3MassHypo,"Dtrk3MassHypo[Dsize]/F");
//	treeOut->Branch("Dtrk4MassHypo",new_Dtrk4MassHypo,"Dtrk4MassHypo[Dsize]/F");
//	treeOut->Branch("Dtrk3Dz",new_Dtrk3Dz,"Dtrk3Dz[Dsize]/F");
//	treeOut->Branch("Dtrk4Dz",new_Dtrk4Dz,"Dtrk4Dz[Dsize]/F");
//	treeOut->Branch("Dtrk3Dxy",new_Dtrk3Dxy,"Dtrk3Dxy[Dsize]/F");
//	treeOut->Branch("Dtrk4Dxy",new_Dtrk4Dxy,"Dtrk4Dxy[Dsize]/F");
//	treeOut->Branch("Dtrk3originalAlgo",new_Dtrk3originalAlgo,"Dtrk3originalAlgo[Dsize]/I");
//	treeOut->Branch("Dtrk4originalAlgo",new_Dtrk4originalAlgo,"Dtrk4originalAlgo[Dsize]/I");
//	treeOut->Branch("Dtrk3highPurity",new_Dtrk3highPurity,"Dtrk3highPurity[Dsize]/O");
//	treeOut->Branch("Dtrk4highPurity",new_Dtrk4highPurity,"Dtrk4highPurity[Dsize]/O");
//	treeOut->Branch("Dtrk3dedx",new_Dtrk3dedx,"Dtrk3dedx[Dsize]/F");
//	treeOut->Branch("Dtrk4dedx",new_Dtrk4dedx,"Dtrk4dedx[Dsize]/F");
//	treeOut->Branch("Dtrk3thetastar",new_Dtrk3thetastar,"Dtrk3thetastar[Dsize]/F");
//	treeOut->Branch("Dtrk4thetastar",new_Dtrk4thetastar,"Dtrk4thetastar[Dsize]/F");
//	treeOut->Branch("Dtrk3thetastar_uf",new_Dtrk3thetastar_uf,"Dtrk3thetastar_uf[Dsize]/F");
//	treeOut->Branch("Dtrk4thetastar_uf",new_Dtrk4thetastar_uf,"Dtrk4thetastar_uf[Dsize]/F");
//	treeOut->Branch("Dtrk3PixelHit",new_Dtrk3PixelHit,"Dtrk3PixelHit[Dsize]/F");
//	treeOut->Branch("Dtrk4PixelHit",new_Dtrk4PixelHit,"Dtrk4PixelHit[Dsize]/F");
//	treeOut->Branch("Dtrk3StripHit",new_Dtrk3StripHit,"Dtrk3StripHit[Dsize]/F");
//	treeOut->Branch("Dtrk4StripHit",new_Dtrk4StripHit,"Dtrk4StripHit[Dsize]/F");
//	treeOut->Branch("Dtrk3nStripLayer",new_Dtrk3nStripLayer,"Dtrk3nStripLayer[Dsize]/F");
//	treeOut->Branch("Dtrk4nStripLayer",new_Dtrk4nStripLayer,"Dtrk4nStripLayer[Dsize]/F");
//	treeOut->Branch("Dtrk3nPixelLayer",new_Dtrk3nPixelLayer,"Dtrk3nPixelLayer[Dsize]/F");
//	treeOut->Branch("Dtrk4nPixelLayer",new_Dtrk4nPixelLayer,"Dtrk4nPixelLayer[Dsize]/F");
//	treeOut->Branch("Dtrk3Chi2ndf",new_Dtrk3Chi2ndf,"Dtrk3Chi2ndf[Dsize]/F");
//	treeOut->Branch("Dtrk4Chi2ndf",new_Dtrk4Chi2ndf,"Dtrk4Chi2ndf[Dsize]/F");
//	treeOut->Branch("Dtrk3Algo",new_Dtrk3Algo,"Dtrk3Algo[Dsize]/I");
//	treeOut->Branch("Dtrk4Algo",new_Dtrk4Algo,"Dtrk4Algo[Dsize]/I");
	treeOut->Branch("Dtrk1Y",new_Dtrk1Y,"Dtrk1Y[Dsize]/F");
//	treeOut->Branch("Dtrk2Y",new_Dtrk2Y,"Dtrk2Y[Dsize]/F");
	treeOut->Branch("Dtrk1D0",new_Dtrk1D0,"Dtrk1D0[Dsize]/F");
//	treeOut->Branch("Dtrk2D0",new_Dtrk2D0,"Dtrk2D0[Dsize]/F"); 
	treeOut->Branch("Dtrk1D0Err",new_Dtrk1D0Err,"Dtrk1D0Err[Dsize]/F");
//	treeOut->Branch("Dtrk2D0Err",new_Dtrk2D0Err,"Dtrk2D0Err[Dsize]/F"); 
	treeOut->Branch("Dtrk1Quality",new_Dtrk1Quality,"Dtrk1Quality[Dsize]/I");
//	treeOut->Branch("Dtrk2Quality",new_Dtrk2Quality,"Dtrk2Quality[Dsize]/I");
	treeOut->Branch("Dtrk1Idx",new_Dtrk1Idx,"Dtrk1Idx[Dsize]/I");
//	treeOut->Branch("Dtrk2Idx",new_Dtrk2Idx,"Dtrk2Idx[Dsize]/I");
	treeOut->Branch("Dtrk1EtaErr",new_Dtrk1EtaErr,"Dtrk1EtaErr[Dsize]/F");
//	treeOut->Branch("Dtrk2EtaErr",new_Dtrk2EtaErr,"Dtrk2EtaErr[Dsize]/F");
	treeOut->Branch("Dtrk1PhiErr",new_Dtrk1PhiErr,"Dtrk1PhiErr[Dsize]/F");
//	treeOut->Branch("Dtrk2PhiErr",new_Dtrk2PhiErr,"Dtrk2PhiErr[Dsize]/F");
	treeOut->Branch("Dtrk1MVAVal",new_Dtrk1MVAVal,"Dtrk1MVAVal[Dsize]/F");
//	treeOut->Branch("Dtrk2MVAVal",new_Dtrk2MVAVal,"Dtrk2MVAVal[Dsize]/F");
	treeOut->Branch("Dtrk3Y",new_Dtrk3Y,"Dtrk3Y[Dsize]/F");
	treeOut->Branch("Dtrk4Y",new_Dtrk4Y,"Dtrk4Y[Dsize]/F");
	treeOut->Branch("Dtrk3D0",new_Dtrk3D0,"Dtrk3D0[Dsize]/F");
	treeOut->Branch("Dtrk4D0",new_Dtrk4D0,"Dtrk4D0[Dsize]/F");
	treeOut->Branch("Dtrk3D0Err",new_Dtrk3D0Err,"Dtrk3D0Err[Dsize]/F");
	treeOut->Branch("Dtrk4D0Err",new_Dtrk4D0Err,"Dtrk4D0Err[Dsize]/F");
	treeOut->Branch("Dtrk3Quality",new_Dtrk3Quality,"Dtrk3Quality[Dsize]/I");
	treeOut->Branch("Dtrk4Quality",new_Dtrk4Quality,"Dtrk4Quality[Dsize]/I");
	treeOut->Branch("Dtrk3Idx",new_Dtrk3Idx,"Dtrk3Idx[Dsize]/I");
	treeOut->Branch("Dtrk4Idx",new_Dtrk4Idx,"Dtrk4Idx[Dsize]/I");
	treeOut->Branch("Dtrk3EtaErr",new_Dtrk3EtaErr,"Dtrk3EtaErr[Dsize]/F");
	treeOut->Branch("Dtrk4EtaErr",new_Dtrk4EtaErr,"Dtrk4EtaErr[Dsize]/F");
	treeOut->Branch("Dtrk3PhiErr",new_Dtrk3PhiErr,"Dtrk3PhiErr[Dsize]/F");
	treeOut->Branch("Dtrk4PhiErr",new_Dtrk4PhiErr,"Dtrk4PhiErr[Dsize]/F");
	treeOut->Branch("Dtrk3MVAVal",new_Dtrk3MVAVal,"Dtrk3MVAVal[Dsize]/F");
	treeOut->Branch("Dtrk4MVAVal",new_Dtrk4MVAVal,"Dtrk4MVAVal[Dsize]/F");
	treeOut->Branch("DtktkResmass",new_DtktkResmass,"DtktkResmass[Dsize]/F");
	treeOut->Branch("DtktkRes_unfitted_mass",new_DtktkRes_unfitted_mass,"DtktkRes_unfitted_mass[Dsize]/F");
	treeOut->Branch("DtktkRespt",new_DtktkRespt,"DtktkRespt[Dsize]/F");
	treeOut->Branch("DtktkRes_unfitted_pt",new_DtktkRes_unfitted_pt,"DtktkRes_unfitted_pt[Dsize]/F");
	treeOut->Branch("DtktkReseta",new_DtktkReseta,"DtktkReseta[Dsize]/F");
	treeOut->Branch("DtktkResphi",new_DtktkResphi,"DtktkResphi[Dsize]/F");
	treeOut->Branch("DtktkRes_chi2ndf",new_DtktkRes_chi2ndf,"DtktkRes_chi2ndf[Dsize]/F");
	treeOut->Branch("DtktkRes_chi2cl",new_DtktkRes_chi2cl,"DtktkRes_chi2cl[Dsize]/F");
	treeOut->Branch("DtktkRes_alpha",new_DtktkRes_alpha,"DtktkRes_alpha[Dsize]/F");
	treeOut->Branch("DtktkRes_alphaToSV",new_DtktkRes_alphaToSV,"DtktkRes_alphaToSV[Dsize]/F");
	treeOut->Branch("DtktkRes_svpvDistance",new_DtktkRes_svpvDistance,"DtktkRes_svpvDistance[Dsize]/F");
	treeOut->Branch("DtktkRes_svpvDisErr",new_DtktkRes_svpvDisErr,"DtktkRes_svpvDisErr[Dsize]/F");
	treeOut->Branch("DtktkRes_svpvDistanceToSV",new_DtktkRes_svpvDistanceToSV,"DtktkRes_svpvDistanceToSV[Dsize]/F");
	treeOut->Branch("DtktkRes_svpvDisErrToSV",new_DtktkRes_svpvDisErrToSV,"DtktkRes_svpvDisErrToSV[Dsize]/F");
	treeOut->Branch("DtktkRes_dca",new_DtktkRes_dca,"DtktkRes_dca[Dsize]/F");
	treeOut->Branch("DtktkRes_dcaToSV",new_DtktkRes_dcaToSV,"DtktkRes_dcaToSV[Dsize]/F");
	treeOut->Branch("DtktkRes_lxyBS",new_DtktkRes_lxyBS,"DtktkRes_lxyBS[Dsize]/F");
	treeOut->Branch("DtktkRes_lxyBSErr",new_DtktkRes_lxyBSErr,"DtktkRes_lxyBSErr[Dsize]/F");
	treeOut->Branch("DtktkRes_angleToTrk1",new_DtktkRes_angleToTrk1,"DtktkRes_angleToTrk1[Dsize]/F");
	treeOut->Branch("DtktkRes_unfitted_angleToTrk1",new_DtktkRes_unfitted_angleToTrk1,"DtktkRes_unfitted_angleToTrk1[Dsize]/F");
	treeOut->Branch("DtktkRes_ptAsymToTrk1",new_DtktkRes_ptAsymToTrk1,"DtktkRes_ptAsymToTrk1[Dsize]/F");
	treeOut->Branch("DtktkRes_unfitter_ptAsymToTrk1",new_DtktkRes_unfitter_ptAsymToTrk1,"DtktkRes_unfitter_ptAsymToTrk1[Dsize]/F");
	treeOut->Branch("DRestrk1Pt",new_DRestrk1Pt,"DRestrk1Pt[Dsize]/F");
	treeOut->Branch("DRestrk2Pt",new_DRestrk2Pt,"DRestrk2Pt[Dsize]/F");
//	treeOut->Branch("DRestrk3Pt",new_DRestrk3Pt,"DRestrk3Pt[Dsize]/F");
//	treeOut->Branch("DRestrk4Pt",new_DRestrk4Pt,"DRestrk4Pt[Dsize]/F");
	treeOut->Branch("DRestrk1PtErr",new_DRestrk1PtErr,"DRestrk1PtErr[Dsize]/F");
	treeOut->Branch("DRestrk2PtErr",new_DRestrk2PtErr,"DRestrk2PtErr[Dsize]/F");
//	treeOut->Branch("DRestrk3PtErr",new_DRestrk3PtErr,"DRestrk3PtErr[Dsize]/F");
//	treeOut->Branch("DRestrk4PtErr",new_DRestrk4PtErr,"DRestrk4PtErr[Dsize]/F");
	treeOut->Branch("DRestrk1Eta",new_DRestrk1Eta,"DRestrk1Eta[Dsize]/F");
	treeOut->Branch("DRestrk2Eta",new_DRestrk2Eta,"DRestrk2Eta[Dsize]/F");
//	treeOut->Branch("DRestrk3Eta",new_DRestrk3Eta,"DRestrk3Eta[Dsize]/F");
//	treeOut->Branch("DRestrk4Eta",new_DRestrk4Eta,"DRestrk4Eta[Dsize]/F");
	treeOut->Branch("DRestrk1Phi",new_DRestrk1Phi,"DRestrk1Phi[Dsize]/F");
	treeOut->Branch("DRestrk2Phi",new_DRestrk2Phi,"DRestrk2Phi[Dsize]/F");
//	treeOut->Branch("DRestrk3Phi",new_DRestrk3Phi,"DRestrk3Phi[Dsize]/F");
//	treeOut->Branch("DRestrk4Phi",new_DRestrk4Phi,"DRestrk4Phi[Dsize]/F");
	treeOut->Branch("DRestrk1P",new_DRestrk1P,"DRestrk1P[Dsize]/F");
	treeOut->Branch("DRestrk2P",new_DRestrk2P,"DRestrk2P[Dsize]/F");
//	treeOut->Branch("DRestrk3P",new_DRestrk3P,"DRestrk3P[Dsize]/F");
//	treeOut->Branch("DRestrk4P",new_DRestrk4P,"DRestrk4P[Dsize]/F");
	treeOut->Branch("DRestrk1MassHypo",new_DRestrk1MassHypo,"DRestrk1MassHypo[Dsize]/F");
	treeOut->Branch("DRestrk2MassHypo",new_DRestrk2MassHypo,"DRestrk2MassHypo[Dsize]/F");
//	treeOut->Branch("DRestrk3MassHypo",new_DRestrk3MassHypo,"DRestrk3MassHypo[Dsize]/F");
//	treeOut->Branch("DRestrk4MassHypo",new_DRestrk4MassHypo,"DRestrk4MassHypo[Dsize]/F");
	treeOut->Branch("DRestrk1Dz",new_DRestrk1Dz,"DRestrk1Dz[Dsize]/F");
	treeOut->Branch("DRestrk2Dz",new_DRestrk2Dz,"DRestrk2Dz[Dsize]/F");
//	treeOut->Branch("DRestrk3Dz",new_DRestrk3Dz,"DRestrk3Dz[Dsize]/F");
//	treeOut->Branch("DRestrk4Dz",new_DRestrk4Dz,"DRestrk4Dz[Dsize]/F");
	treeOut->Branch("DRestrk1Dxy",new_DRestrk1Dxy,"DRestrk1Dxy[Dsize]/F");
	treeOut->Branch("DRestrk2Dxy",new_DRestrk2Dxy,"DRestrk2Dxy[Dsize]/F");
//	treeOut->Branch("DRestrk3Dxy",new_DRestrk3Dxy,"DRestrk3Dxy[Dsize]/F");
//	treeOut->Branch("DRestrk4Dxy",new_DRestrk4Dxy,"DRestrk4Dxy[Dsize]/F");
	treeOut->Branch("DRestrk1originalAlgo",new_DRestrk1originalAlgo,"DRestrk1originalAlgo[Dsize]/I");
	treeOut->Branch("DRestrk2originalAlgo",new_DRestrk2originalAlgo,"DRestrk2originalAlgo[Dsize]/I");
//	treeOut->Branch("DRestrk3originalAlgo",new_DRestrk3originalAlgo,"DRestrk3originalAlgo[Dsize]/I");
//	treeOut->Branch("DRestrk4originalAlgo",new_DRestrk4originalAlgo,"DRestrk4originalAlgo[Dsize]/I");
	treeOut->Branch("DRestrk1highPurity",new_DRestrk1highPurity,"DRestrk1highPurity[Dsize]/O");
	treeOut->Branch("DRestrk2highPurity",new_DRestrk2highPurity,"DRestrk2highPurity[Dsize]/O");
//	treeOut->Branch("DRestrk3highPurity",new_DRestrk3highPurity,"DRestrk3highPurity[Dsize]/O");
//	treeOut->Branch("DRestrk4highPurity",new_DRestrk4highPurity,"DRestrk4highPurity[Dsize]/O");
	treeOut->Branch("DRestrk1dedx",new_DRestrk1dedx,"DRestrk1dedx[Dsize]/F");
	treeOut->Branch("DRestrk2dedx",new_DRestrk2dedx,"DRestrk2dedx[Dsize]/F");
//	treeOut->Branch("DRestrk3dedx",new_DRestrk3dedx,"DRestrk3dedx[Dsize]/F");
//	treeOut->Branch("DRestrk4dedx",new_DRestrk4dedx,"DRestrk4dedx[Dsize]/F");
	treeOut->Branch("DRestrk1thetastar",new_DRestrk1thetastar,"DRestrk1thetastar[Dsize]/F");
	treeOut->Branch("DRestrk2thetastar",new_DRestrk2thetastar,"DRestrk2thetastar[Dsize]/F");
//	treeOut->Branch("DRestrk3thetastar",new_DRestrk3thetastar,"DRestrk3thetastar[Dsize]/F");
//	treeOut->Branch("DRestrk4thetastar",new_DRestrk4thetastar,"DRestrk4thetastar[Dsize]/F");
	treeOut->Branch("DRestrk1thetastar_uf",new_DRestrk1thetastar_uf,"DRestrk1thetastar_uf[Dsize]/F");
	treeOut->Branch("DRestrk2thetastar_uf",new_DRestrk2thetastar_uf,"DRestrk2thetastar_uf[Dsize]/F");
//	treeOut->Branch("DRestrk3thetastar_uf",new_DRestrk3thetastar_uf,"DRestrk3thetastar_uf[Dsize]/F");
//	treeOut->Branch("DRestrk4thetastar_uf",new_DRestrk4thetastar_uf,"DRestrk4thetastar_uf[Dsize]/F");
	treeOut->Branch("DRestrk1Y",new_DRestrk1Y,"DRestrk1Y[Dsize]/F");
	treeOut->Branch("DRestrk2Y",new_DRestrk2Y,"DRestrk2Y[Dsize]/F");
//	treeOut->Branch("DRestrk3Y",new_DRestrk3Y,"DRestrk3Y[Dsize]/F");
//	treeOut->Branch("DRestrk4Y",new_DRestrk4Y,"DRestrk4Y[Dsize]/F");
	treeOut->Branch("DRestrk1D0",new_DRestrk1D0,"DRestrk1D0[Dsize]/F");
	treeOut->Branch("DRestrk2D0",new_DRestrk2D0,"DRestrk2D0[Dsize]/F");
//	treeOut->Branch("DRestrk3D0",new_DRestrk3D0,"DRestrk3D0[Dsize]/F");
//	treeOut->Branch("DRestrk4D0",new_DRestrk4D0,"DRestrk4D0[Dsize]/F");
	treeOut->Branch("DRestrk1D0Err",new_DRestrk1D0Err,"DRestrk1D0Err[Dsize]/F");
	treeOut->Branch("DRestrk2D0Err",new_DRestrk2D0Err,"DRestrk2D0Err[Dsize]/F");
//	treeOut->Branch("DRestrk3D0Err",new_DRestrk3D0Err,"DRestrk3D0Err[Dsize]/F");
//	treeOut->Branch("DRestrk4D0Err",new_DRestrk4D0Err,"DRestrk4D0Err[Dsize]/F");
	treeOut->Branch("DRestrk1Quality",new_DRestrk1Quality,"DRestrk1Quality[Dsize]/I");
	treeOut->Branch("DRestrk2Quality",new_DRestrk2Quality,"DRestrk2Quality[Dsize]/I");
//	treeOut->Branch("DRestrk3Quality",new_DRestrk3Quality,"DRestrk3Quality[Dsize]/I");
//	treeOut->Branch("DRestrk4Quality",new_DRestrk4Quality,"DRestrk4Quality[Dsize]/I");
	treeOut->Branch("Dgen",new_Dgen,"Dgen[Dsize]/F");
	treeOut->Branch("DgenIndex",new_DgenIndex,"DgenIndex[Dsize]/I");
	treeOut->Branch("DgennDa",new_DgennDa,"DgennDa[Dsize]/I");
	treeOut->Branch("Dgenpt",new_Dgenpt,"Dgenpt[Dsize]/F");
	treeOut->Branch("Dgeneta",new_Dgeneta,"Dgeneta[Dsize]/F");
	treeOut->Branch("Dgenphi",new_Dgenphi,"Dgenphi[Dsize]/F");
	treeOut->Branch("Dgeny",new_Dgeny,"Dgeny[Dsize]/F");
	treeOut->Branch("DgencollisionId",new_DgencollisionId,"DgencollisionId[Dsize]/I");
	treeOut->Branch("DgenBAncestorpt",new_DgenBAncestorpt,"DgenBAncestorpt[Dsize]/F");
	treeOut->Branch("DgenBAncestorpdgId",new_DgenBAncestorpdgId,"DgenBAncestorpdgId[Dsize]/I");
	treeOut->Branch("DgenprodvtxX",new_DgenprodvtxX,"DgenprodvtxX[Dsize]/F");
	treeOut->Branch("DgenprodvtxY",new_DgenprodvtxY,"DgenprodvtxY[Dsize]/F");
	treeOut->Branch("DgenprodvtxZ",new_DgenprodvtxZ,"DgenprodvtxZ[Dsize]/F");
	treeOut->Branch("DgendecayvtxX",new_DgendecayvtxX,"DgendecayvtxX[Dsize]/F");
	treeOut->Branch("DgendecayvtxY",new_DgendecayvtxY,"DgendecayvtxY[Dsize]/F");
	treeOut->Branch("DgendecayvtxZ",new_DgendecayvtxZ,"DgendecayvtxZ[Dsize]/F");
	treeOut->Branch("DgenfromgenPV",new_DgenfromgenPV,"DgenfromgenPV[Dsize]/I");
}

void copyBR(int i, int j){
	new_Dindex[i] = Dindex[j];
	new_Dtype[i] = Dtype[j];
	new_Dmass[i] = Dmass[j];
	new_D_unfitted_mass[i] = D_unfitted_mass[j];
	new_Dpt[i] = Dpt[j];
	new_D_unfitted_pt[i] = D_unfitted_pt[j];
	new_Deta[i] = Deta[j];
	new_Dphi[i] = Dphi[j];
	new_Dy[i] = Dy[j];
	new_DvtxX[i] = DvtxX[j];
	new_DvtxY[i] = DvtxY[j];
	new_DvtxZ[i] = DvtxZ[j];
	new_Dd0[i] = Dd0[j];
	new_Dd0Err[i] = Dd0Err[j];
	new_Ddxyz[i] = Ddxyz[j];
	new_DdxyzErr[i] = DdxyzErr[j];
	new_Dchi2ndf[i] = Dchi2ndf[j];
	new_Dchi2cl[i] = Dchi2cl[j];
	new_Ddtheta[i] = Ddtheta[j];
	new_Dlxy[i] = Dlxy[j];
	new_Dalpha[i] = Dalpha[j];
	new_DsvpvDistance[i] = DsvpvDistance[j];
	new_DsvpvDisErr[i] = DsvpvDisErr[j];
	new_DsvpvDistance_2D[i] = DsvpvDistance_2D[j];
	new_DsvpvDisErr_2D[i] = DsvpvDisErr_2D[j];
	new_Ddca[i] = Ddca[j];
	new_DlxyBS[i] = DlxyBS[j];
	new_DlxyBSErr[i] = DlxyBSErr[j];
	new_DMaxDoca[i] = DMaxDoca[j];
	new_DMaxTkPt[i] = DMaxTkPt[j];
	new_DMinTkPt[i] = DMinTkPt[j];
	new_Dtrk1Pt[i] = Dtrk1Pt[j];
	new_Dtrk2Pt[i] = Dtrk2Pt[j];
	new_Dtrk1PtErr[i] = Dtrk1PtErr[j];
	new_Dtrk2PtErr[i] = Dtrk2PtErr[j];
	new_Dtrk1Eta[i] = Dtrk1Eta[j];
	new_Dtrk2Eta[i] = Dtrk2Eta[j];
	new_Dtrk1Phi[i] = Dtrk1Phi[j];
	new_Dtrk2Phi[i] = Dtrk2Phi[j];
	new_Dtrk1P[i] = Dtrk1P[j];
	new_Dtrk2P[i] = Dtrk2P[j];
	new_Dtrk1Dz[i] = Dtrk1Dz[j];
	new_Dtrk2Dz[i] = Dtrk2Dz[j];
	new_Dtrk1Dxy[i] = Dtrk1Dxy[j];
	new_Dtrk2Dxy[i] = Dtrk2Dxy[j];
	new_Dtrk1MassHypo[i] = Dtrk1MassHypo[j];
	new_Dtrk2MassHypo[i] = Dtrk2MassHypo[j];
	new_Dtrk1originalAlgo[i] = Dtrk1originalAlgo[j];
	new_Dtrk2originalAlgo[i] = Dtrk2originalAlgo[j];
	new_Dtrk1highPurity[i] = Dtrk1highPurity[j];
	new_Dtrk2highPurity[i] = Dtrk2highPurity[j];
	new_Dtrk1dedx[i] = Dtrk1dedx[j];
	new_Dtrk2dedx[i] = Dtrk2dedx[j];
	new_Dtrk1thetastar[i] = Dtrk1thetastar[j];
	new_Dtrk2thetastar[i] = Dtrk2thetastar[j];
	new_Dtrk1thetastar_uf[i] = Dtrk1thetastar_uf[j];
	new_Dtrk2thetastar_uf[i] = Dtrk2thetastar_uf[j];
	new_Dtrk1PixelHit[i] = Dtrk1PixelHit[j];
	new_Dtrk2PixelHit[i] = Dtrk2PixelHit[j];
	new_Dtrk1StripHit[i] = Dtrk1StripHit[j];
	new_Dtrk2StripHit[i] = Dtrk2StripHit[j];
	new_Dtrk1nStripLayer[i] = Dtrk1nStripLayer[j];
	new_Dtrk2nStripLayer[i] = Dtrk2nStripLayer[j];
	new_Dtrk1nPixelLayer[i] = Dtrk1nPixelLayer[j];
	new_Dtrk2nPixelLayer[i] = Dtrk2nPixelLayer[j];
	new_Dtrk1Chi2ndf[i] = Dtrk1Chi2ndf[j];
	new_Dtrk2Chi2ndf[i] = Dtrk2Chi2ndf[j];
	new_Dtrk1Algo[i] = Dtrk1Algo[j];
	new_Dtrk2Algo[i] = Dtrk2Algo[j];
	new_Dtrk3Pt[i] = Dtrk3Pt[j];
	new_Dtrk4Pt[i] = Dtrk4Pt[j];
	new_Dtrk3PtErr[i] = Dtrk3PtErr[j];
	new_Dtrk4PtErr[i] = Dtrk4PtErr[j];
	new_Dtrk3Eta[i] = Dtrk3Eta[j];
	new_Dtrk4Eta[i] = Dtrk4Eta[j];
	new_Dtrk3Phi[i] = Dtrk3Phi[j];
	new_Dtrk4Phi[i] = Dtrk4Phi[j];
	new_Dtrk3P[i] = Dtrk3P[j];
	new_Dtrk4P[i] = Dtrk4P[j];
	new_Dtrk3MassHypo[i] = Dtrk3MassHypo[j];
	new_Dtrk4MassHypo[i] = Dtrk4MassHypo[j];
	new_Dtrk3Dz[i] = Dtrk3Dz[j];
	new_Dtrk4Dz[i] = Dtrk4Dz[j];
	new_Dtrk3Dxy[i] = Dtrk3Dxy[j];
	new_Dtrk4Dxy[i] = Dtrk4Dxy[j];
	new_Dtrk3originalAlgo[i] = Dtrk3originalAlgo[j];
	new_Dtrk4originalAlgo[i] = Dtrk4originalAlgo[j];
	new_Dtrk3highPurity[i] = Dtrk3highPurity[j];
	new_Dtrk4highPurity[i] = Dtrk4highPurity[j];
	new_Dtrk3dedx[i] = Dtrk3dedx[j];
	new_Dtrk4dedx[i] = Dtrk4dedx[j];
	new_Dtrk3thetastar[i] = Dtrk3thetastar[j];
	new_Dtrk4thetastar[i] = Dtrk4thetastar[j];
	new_Dtrk3thetastar_uf[i] = Dtrk3thetastar_uf[j];
	new_Dtrk4thetastar_uf[i] = Dtrk4thetastar_uf[j];
	new_Dtrk3PixelHit[i] = Dtrk3PixelHit[j];
	new_Dtrk4PixelHit[i] = Dtrk4PixelHit[j];
	new_Dtrk3StripHit[i] = Dtrk3StripHit[j];
	new_Dtrk4StripHit[i] = Dtrk4StripHit[j];
	new_Dtrk3nStripLayer[i] = Dtrk3nStripLayer[j];
	new_Dtrk4nStripLayer[i] = Dtrk4nStripLayer[j];
	new_Dtrk3nPixelLayer[i] = Dtrk3nPixelLayer[j];
	new_Dtrk4nPixelLayer[i] = Dtrk4nPixelLayer[j];
	new_Dtrk3Chi2ndf[i] = Dtrk3Chi2ndf[j];
	new_Dtrk4Chi2ndf[i] = Dtrk4Chi2ndf[j];
	new_Dtrk3Algo[i] = Dtrk3Algo[j];
	new_Dtrk4Algo[i] = Dtrk4Algo[j];
	new_Dtrk1Y[i] = Dtrk1Y[j];
	new_Dtrk2Y[i] = Dtrk2Y[j];
	new_Dtrk1D0[i] = Dtrk1D0[j];
	new_Dtrk2D0[i] = Dtrk2D0[j];
	new_Dtrk1D0Err[i] = Dtrk1D0Err[j];
	new_Dtrk2D0Err[i] = Dtrk2D0Err[j];
	new_Dtrk1Quality[i] = Dtrk1Quality[j];
	new_Dtrk2Quality[i] = Dtrk2Quality[j];
	new_Dtrk1Idx[i] = Dtrk1Idx[j];
	new_Dtrk2Idx[i] = Dtrk2Idx[j];
	new_Dtrk1EtaErr[i] = Dtrk1EtaErr[j];
	new_Dtrk2EtaErr[i] = Dtrk2EtaErr[j];
	new_Dtrk1PhiErr[i] = Dtrk1PhiErr[j];
	new_Dtrk2PhiErr[i] = Dtrk2PhiErr[j];
	new_Dtrk1MVAVal[i] = Dtrk1MVAVal[j];
	new_Dtrk2MVAVal[i] = Dtrk2MVAVal[j];
	new_Dtrk3Y[i] = Dtrk3Y[j];
	new_Dtrk4Y[i] = Dtrk4Y[j];
	new_Dtrk3D0[i] = Dtrk3D0[j];
	new_Dtrk4D0[i] = Dtrk4D0[j];
	new_Dtrk3D0Err[i] = Dtrk3D0Err[j];
	new_Dtrk4D0Err[i] = Dtrk4D0Err[j];
	new_Dtrk3Quality[i] = Dtrk3Quality[j];
	new_Dtrk4Quality[i] = Dtrk4Quality[j];
	new_Dtrk3Idx[i] = Dtrk3Idx[j];
	new_Dtrk4Idx[i] = Dtrk4Idx[j];
	new_Dtrk3EtaErr[i] = Dtrk3EtaErr[j];
	new_Dtrk4EtaErr[i] = Dtrk4EtaErr[j];
	new_Dtrk3PhiErr[i] = Dtrk3PhiErr[j];
	new_Dtrk4PhiErr[i] = Dtrk4PhiErr[j];
	new_Dtrk3MVAVal[i] = Dtrk3MVAVal[j];
	new_Dtrk4MVAVal[i] = Dtrk4MVAVal[j];
	new_DtktkResmass[i] = DtktkResmass[j];
	new_DtktkRes_unfitted_mass[i] = DtktkRes_unfitted_mass[j];
	new_DtktkRespt[i] = DtktkRespt[j];
	new_DtktkRes_unfitted_pt[i] = DtktkRes_unfitted_pt[j];
	new_DtktkReseta[i] = DtktkReseta[j];
	new_DtktkResphi[i] = DtktkResphi[j];
	new_DtktkRes_chi2ndf[i] = DtktkRes_chi2ndf[j];
	new_DtktkRes_chi2cl[i] = DtktkRes_chi2cl[j];
	new_DtktkRes_alpha[i] = DtktkRes_alpha[j];
	new_DtktkRes_alphaToSV[i] = DtktkRes_alphaToSV[j];
	new_DtktkRes_svpvDistance[i] = DtktkRes_svpvDistance[j];
	new_DtktkRes_svpvDisErr[i] = DtktkRes_svpvDisErr[j];
	new_DtktkRes_svpvDistanceToSV[i] = DtktkRes_svpvDistanceToSV[j];
	new_DtktkRes_svpvDisErrToSV[i] = DtktkRes_svpvDisErrToSV[j];
	new_DtktkRes_dca[i] = DtktkRes_dca[j];
	new_DtktkRes_dcaToSV[i] = DtktkRes_dcaToSV[j];
	new_DtktkRes_lxyBS[i] = DtktkRes_lxyBS[j];
	new_DtktkRes_lxyBSErr[i] = DtktkRes_lxyBSErr[j];
	new_DtktkRes_angleToTrk1[i] = DtktkRes_angleToTrk1[j];
	new_DtktkRes_unfitted_angleToTrk1[i] = DtktkRes_unfitted_angleToTrk1[j];
	new_DtktkRes_ptAsymToTrk1[i] = DtktkRes_ptAsymToTrk1[j];
	new_DtktkRes_unfitter_ptAsymToTrk1[i] = DtktkRes_unfitter_ptAsymToTrk1[j];
	new_DRestrk1Pt[i] = DRestrk1Pt[j];
	new_DRestrk2Pt[i] = DRestrk2Pt[j];
	new_DRestrk3Pt[i] = DRestrk3Pt[j];
	new_DRestrk4Pt[i] = DRestrk4Pt[j];
	new_DRestrk1PtErr[i] = DRestrk1PtErr[j];
	new_DRestrk2PtErr[i] = DRestrk2PtErr[j];
	new_DRestrk3PtErr[i] = DRestrk3PtErr[j];
	new_DRestrk4PtErr[i] = DRestrk4PtErr[j];
	new_DRestrk1Eta[i] = DRestrk1Eta[j];
	new_DRestrk2Eta[i] = DRestrk2Eta[j];
	new_DRestrk3Eta[i] = DRestrk3Eta[j];
	new_DRestrk4Eta[i] = DRestrk4Eta[j];
	new_DRestrk1Phi[i] = DRestrk1Phi[j];
	new_DRestrk2Phi[i] = DRestrk2Phi[j];
	new_DRestrk3Phi[i] = DRestrk3Phi[j];
	new_DRestrk4Phi[i] = DRestrk4Phi[j];
	new_DRestrk1P[i] = DRestrk1P[j];
	new_DRestrk2P[i] = DRestrk2P[j];
	new_DRestrk3P[i] = DRestrk3P[j];
	new_DRestrk4P[i] = DRestrk4P[j];
	new_DRestrk1MassHypo[i] = DRestrk1MassHypo[j];
	new_DRestrk2MassHypo[i] = DRestrk2MassHypo[j];
	new_DRestrk3MassHypo[i] = DRestrk3MassHypo[j];
	new_DRestrk4MassHypo[i] = DRestrk4MassHypo[j];
	new_DRestrk1Dz[i] = DRestrk1Dz[j];
	new_DRestrk2Dz[i] = DRestrk2Dz[j];
	new_DRestrk3Dz[i] = DRestrk3Dz[j];
	new_DRestrk4Dz[i] = DRestrk4Dz[j];
	new_DRestrk1Dxy[i] = DRestrk1Dxy[j];
	new_DRestrk2Dxy[i] = DRestrk2Dxy[j];
	new_DRestrk3Dxy[i] = DRestrk3Dxy[j];
	new_DRestrk4Dxy[i] = DRestrk4Dxy[j];
	new_DRestrk1originalAlgo[i] = DRestrk1originalAlgo[j];
	new_DRestrk2originalAlgo[i] = DRestrk2originalAlgo[j];
	new_DRestrk3originalAlgo[i] = DRestrk3originalAlgo[j];
	new_DRestrk4originalAlgo[i] = DRestrk4originalAlgo[j];
	new_DRestrk1highPurity[i] = DRestrk1highPurity[j];
	new_DRestrk2highPurity[i] = DRestrk2highPurity[j];
	new_DRestrk3highPurity[i] = DRestrk3highPurity[j];
	new_DRestrk4highPurity[i] = DRestrk4highPurity[j];
	new_DRestrk1dedx[i] = DRestrk1dedx[j];
	new_DRestrk2dedx[i] = DRestrk2dedx[j];
	new_DRestrk3dedx[i] = DRestrk3dedx[j];
	new_DRestrk4dedx[i] = DRestrk4dedx[j];
	new_DRestrk1thetastar[i] = DRestrk1thetastar[j];
	new_DRestrk2thetastar[i] = DRestrk2thetastar[j];
	new_DRestrk3thetastar[i] = DRestrk3thetastar[j];
	new_DRestrk4thetastar[i] = DRestrk4thetastar[j];
	new_DRestrk1thetastar_uf[i] = DRestrk1thetastar_uf[j];
	new_DRestrk2thetastar_uf[i] = DRestrk2thetastar_uf[j];
	new_DRestrk3thetastar_uf[i] = DRestrk3thetastar_uf[j];
	new_DRestrk4thetastar_uf[i] = DRestrk4thetastar_uf[j];
	new_DRestrk1Y[i] = DRestrk1Y[j];
	new_DRestrk2Y[i] = DRestrk2Y[j];
	new_DRestrk3Y[i] = DRestrk3Y[j];
	new_DRestrk4Y[i] = DRestrk4Y[j];
	new_DRestrk1D0[i] = DRestrk1D0[j];
	new_DRestrk2D0[i] = DRestrk2D0[j];
	new_DRestrk3D0[i] = DRestrk3D0[j];
	new_DRestrk4D0[i] = DRestrk4D0[j];
	new_DRestrk1D0Err[i] = DRestrk1D0Err[j];
	new_DRestrk2D0Err[i] = DRestrk2D0Err[j];
	new_DRestrk3D0Err[i] = DRestrk3D0Err[j];
	new_DRestrk4D0Err[i] = DRestrk4D0Err[j];
	new_DRestrk1Quality[i] = DRestrk1Quality[j];
	new_DRestrk2Quality[i] = DRestrk2Quality[j];
	new_DRestrk3Quality[i] = DRestrk3Quality[j];
	new_DRestrk4Quality[i] = DRestrk4Quality[j];
	new_Dgen[i] = Dgen[j];
	new_DgenIndex[i] = DgenIndex[j];
	new_DgennDa[i] = DgennDa[j];
	new_Dgenpt[i] = Dgenpt[j];
	new_Dgeneta[i] = Dgeneta[j];
	new_Dgenphi[i] = Dgenphi[j];
	new_Dgeny[i] = Dgeny[j];
	new_DgencollisionId[i] = DgencollisionId[j];
	new_DgenBAncestorpt[i] = DgenBAncestorpt[j];
	new_DgenBAncestorpdgId[i] = DgenBAncestorpdgId[j];
	new_DgenprodvtxX[i] = DgenprodvtxX[j];
	new_DgenprodvtxY[i] = DgenprodvtxY[j];
	new_DgenprodvtxZ[i] = DgenprodvtxZ[j];
	new_DgendecayvtxX[i] = DgendecayvtxX[j];
	new_DgendecayvtxY[i] = DgendecayvtxY[j];
	new_DgendecayvtxZ[i] = DgendecayvtxZ[j];
	new_DgenfromgenPV[i] = DgenfromgenPV[j];
}
