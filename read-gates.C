{
// This script allows you to read in all of your CUTs in one step instead of having to do them individually. 

// Note that the below script is for a (p,p') experiment. If you are analysing an (a,a') experiment, you wont have CUTpad2tof and CUTpad1pad2. Comment out the lines that relate to those CUTs. 

gStyle->SetPalette(1,0);


Char_t name1[30];
     
sprintf(name1,".x rd_gate_tofX1_run01085.C");
gROOT->ProcessLine(name1);
sprintf(name1,".x rd_gate_pad1tof_run01085.C");
gROOT->ProcessLine(name1);
sprintf(name1,".x rd_gate_pad2tof_run01085.C");
gROOT->ProcessLine(name1);
sprintf(name1,".x rd_gate_pad1pad2_run01085.C");
gROOT->ProcessLine(name1);


sprintf(name1,".x histos.C");
gROOT->ProcessLine(name1);

// The lines below create a new TCut that is a combination of all of the above graphical cuts. Since you are now using a TCut (as opposed to a TCutG), do not use "" when making use of the CUT names. 
// i.e. DATA->Draw("X1pos>>hX1pos","CUTtofX1 && CUTpad1tof && CUTpad2tof && CUTpad1pad2 && X1flag==0 && U1flag==0 && U2flag==0 && Y1>-5 && Y1<20","") becomes
// DATA->Draw("X1pos>>hX1pos",CUTbasic && CUTflags && CUTy,"")

// For (a,a') experiments, remember to remove the CUTpad2tof and CUTpad1pad2

TCut CUTbasic = "CUTtofX1 && CUTpad1tof && CUTpad2tof && CUTpad1pad2";
TCut CUTflags = "X1flag==0 && U1flag==0 && U2flag==0";
TCut CUTy = "Y1>-5 && Y1<20";

}
