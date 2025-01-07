{
// For (a,a') experiments, no CUTS using pad2 should be made. Turn back now.   

// For a (p,p') experiment, this CUT should be done after you have done CUTtofX1 and CUTpad1tof. After plotting pad2:tof with CUTtofX1 and CUTpad1tof included (i.e. DATA->Draw("pad2:tof>>hpad2vstof","CUTtofX1 && CUTpad1tof","col")), select the region of interest using the scissors tool. Once the area is outlined, run this script. Remember to change the run number in the CUT name below.

TCutG *cut2=new TCutG();
CUTpad2tof = (TCutG*) gPad -> WaitPrimitive("CUTG");

CUTpad2tof -> SetName("CUTpad2tof"); 
CUTpad2tof -> SetVarX("tof");
CUTpad2tof -> SetVarY("pad2");

// This section of the code writes the CUT to a file which is located in the directory in which you are running ROOT. This allows you to use the CUT again in a different ROOT session without having to redo the CUT.

file20 = new TFile("CUTpad2tof_run01085.root","NEW");
CUTpad2tof -> Write();
file20 -> ls();
file20 -> Close();

// NB! When running this script for individual root files (i.e. not chained files), you must use this command to get back to the file you were working:     _file0->cd()
// Otherwise ROOT stays in the CUT file and you can't look at any spectra since it won't know where your DATA tree is located. 

// The next step is to use the rd_gate_pad2tof.C script. See that script for details. 


}
