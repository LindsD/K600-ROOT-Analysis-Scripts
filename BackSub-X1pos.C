{
gStyle->SetPalette(1,0);

c1 = new TCanvas("c1","c1",800,10,1000,600);
c1->SetFillColor(0);
c1->SetGridy(0);
c1->SetFillColor(0);

// Create 1 dimensional histograms

TH1F *hX1posCTOF = new TH1F("hX1posCTOF","Corrected Position",4000,0.,800.);
TH1F *hX1posCTOFback1 = new TH1F("hX1posCTOFback1","Corrected Position",4000,0.,800.);
TH1F *hX1posCTOFback2 = new TH1F("hX1posCTOFback2","Corrected Position",4000,0.,800.);
TH1F *hX1posCTOFbacktot = new TH1F("hX1posCTOFbacktot","Corrected Position",4000,0.,800.);
TH1F *hX1posCTOFdiff = new TH1F("hX1posCTOFdiff","Corrected and Subtracted Position",4000,0.,800.);

//Note that we use X1posCTOF since we corrected the lineshape with TOF

DATA->Draw("X1posCTOF>>hX1posCTOF",CUTbasic && CUTflags && CUTy,"");
DATA->Draw("X1posCTOF>>hX1posCTOFback2",CUTbasic && CUTflags && CUTyback2,"");
DATA->Draw("X1posCTOF>>hX1posCTOFback1",CUTbasic && CUTflags && CUTyback1,"");

hX1posCTOFdiff->SetStats(0);
hX1posCTOFdiff->GetXaxis()->SetTitle("Position (mm)");
hX1posCTOFdiff->GetXaxis()->CenterTitle(true);
hX1posCTOFdiff->GetYaxis()->SetTitle("Counts/10 keV");
hX1posCTOFdiff->GetYaxis()->CenterTitle(true);

hX1posCTOFdiff->Add(hX1posCTOF);
hX1posCTOFdiff->Add(hX1posCTOFback1,-1.);
hX1posCTOFdiff->Add(hX1posCTOFback2,-1.);
hX1posCTOFbacktot->Add(hX1posCTOFback1,1.);
hX1posCTOFbacktot->Add(hX1posCTOFback2,1.);

hX1posCTOF->SetLineColor(4);
hX1posCTOFback1->SetLineColor(2);
hX1posCTOFback2->SetLineColor(3);
hX1posCTOFdiff->SetLineColor(1);
hX1posCTOFbacktot->SetLineColor(6);

hX1posCTOF->Draw();
hX1posCTOFdiff->Draw("same");
hX1posCTOFback1->Draw("same");
hX1posCTOFback2->Draw("same");
hX1posCTOFbacktot->Draw("same");

}


