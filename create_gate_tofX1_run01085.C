{
// This is always the first CUT that you should make. It cuts out most of the background junk from your spectrum. After plotting the tof:X1pos spectrum in ROOT, use the scissors function from the toolbar in ROOT and draw around the area of interest. Once that area is outlined, run this script in the ROOT terminal. Remember to change the run number in the name of the CUT.  

TCutG *cut=new TCutG();
CUTtofX1 = (TCutG*) gPad -> WaitPrimitive("CUTG");

CUTtofX1 -> SetName("CUTtofX1"); 
CUTtofX1 -> SetVarX("X1pos");
CUTtofX1 -> SetVarY("tof");

// This section writes the CUT to a file that is saved in the directory in which you are running ROOT. This allows you to use this CUT again in a different ROOT session without having to redo it.

file20 = new TFile("CUTtofX1_run01085.root","NEW");
CUTtofX1 -> Write();
file20 -> ls();
file20 -> Close();

// NB! When running this script for individual root files (i.e. not chained files), you must use this command to get back to the file you were working:     _file0->cd()
// Otherwise ROOT stays in the CUT file and you can't look at any spectra since it won't know where your DATA tree is located. 

// The next step is to use the rd_gate_tofX1.C script. See that script for details. 

}
