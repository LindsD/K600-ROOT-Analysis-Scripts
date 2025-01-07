{

// This script must be run when you want ROOT to use a CUT that you have created previously. It looks for the CUT file in the directory in which you're running ROOT.

TFile * file20_12 = new TFile("CUTpad1pad2_run01085.root","OLD");
TCutG *cut_12   = (TCutG*) file20_12 -> Get( "CUTpad1pad2" );
cut_12->SetVarX("pad2");
cut_12->SetVarY("pad1");

// NB! When running this script for individual root files (i.e. not chained files), you must use this command to get back to the file you were working:     _file0->cd()
// Otherwise ROOT stays in the CUT file and you can't look at any spectra since it won't know where your DATA tree is located.

}
