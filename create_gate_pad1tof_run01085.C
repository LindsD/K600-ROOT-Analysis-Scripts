{
// This CUT should be done after you have done the CUTtofX1. After plotting pad1:tof with CUTtofX1 included (i.e. DATA->Draw("pad1:tof>>hpad1vstof","CUTtofX1","col")), select the region of interest using the scissor tool. Once the area is outlined, run this script. Remember to change the run number in the CUT name below. 

TCutG *cut1=new TCutG();
CUTpad1tof = (TCutG*) gPad -> WaitPrimitive("CUTG");

CUTpad1tof -> SetName("CUTpad1tof"); 
CUTpad1tof -> SetVarX("tof");
CUTpad1tof -> SetVarY("pad1");

// This section of the code writes the CUT to a file which is located in the directory in which you are running ROOT. This allows you to use the CUT again in a different ROOT session without having to redo the CUT. 

file20 = new TFile("CUTpad1tof_run01085.root","NEW");
CUTpad1tof -> Write();
file20 -> ls();
file20 -> Close();

// NB! When running this script for individual root files (i.e. not chained files), you must use this command to get back to the file you were working:     _file0->cd()
// Otherwise ROOT stays in the CUT file and you can't look at any spectra since it won't know where your DATA tree is located. 

// The next step is to use the rd_gate_pad1tof.C script. See that script for details. 

}
