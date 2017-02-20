{

// This script must be run when you want ROOT to use a CUT that you have created previously. It looks for the CUT file in the directory in which you're running ROOT.

TFile * file20_1 = new TFile("CUTpad1tof_run01085.root","OLD");
TCutG *cut_1   = (TCutG*) file20_1 -> Get( "CUTpad1tof" );
cut_1->SetVarX("tof");
cut_1->SetVarY("pad1");

// NB! When running this script for individual root files (i.e. not chained files), you must use this command to get back to the file you were working:     _file0->cd()
// Otherwise ROOT stays in the CUT file and you can't look at any spectra since it won't know where your DATA tree is located.

}
