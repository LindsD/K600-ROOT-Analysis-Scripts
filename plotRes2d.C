{

// This script is used to assess whether LUT offsets are necessary and gives an idea of how much the LUT offsets should be. Run the histos.C script and then this script compare with the K600 user manual to see whether offsets are necessary.

// NB! Please ensure that your histos.C file is set to look at the correct TOF region ssince this can change depending on the experiment!! More recent experiments have TOF ranges that are much lower than the older experiments. You should know that you are not looking at the right region if you try to plot pad1:tof and see no data in the histogram that's created. 

  //gROOT->Reset();

  c2 = new TCanvas("c2","The evolution of the Res2D plot with offset",10,10,900,600);
  c2->SetFillColor(9);
  c2->SetGridy(0);

  TPad* pad2 = new TPad("pad2","Spectra",0.01,0.01,0.99,0.99);
  pad2->Draw();
  pad2->cd();
  pad2->Divide(2,2);

// The below limits are rough estimates and are obtained by looking at the pad1:tof spectrum and limiting the region to your region of interest. It is important that the LUT offsets are determined for the particles of interest only so you must check that these values match the data you have. If not, change them for your specific case. 

// PR373 - 58Ni(p,d), E_p = 66 MeV

TCut CUTbasic = "tof>-390 && tof<-295 && pad1>1300 && pad1<1950";

pad2->cd(1);
DATA->Draw("X1res1:X1res0>>hX1Res2d",CUTbasic,"col");
//DATA->Draw("X1res1:X1res0>>hX1Res2d","CUTpad1tof","col");

pad2->cd(2);
DATA->Draw("U1res1:U1res0>>hU1Res2d",CUTbasic,"col");
//DATA->Draw("U1res1:U1res0>>hU1Res2d","CUTpad1tof","col");

pad2->cd(3);
DATA->Draw("X2res1:X2res0>>hX2Res2d",CUTbasic,"col");
//DATA->Draw("X2res1:X2res0>>hX2Res2d","CUTpad1tof","col");

pad2->cd(4);
DATA->Draw("U2res1:U2res0>>hU2Res2d",CUTbasic,"col");
//DATA->Draw("U2res1:U2res0>>hU2Res2d","CUTpad1tof","col");

}
