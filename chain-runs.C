{
  TChain *DATAChain = new TChain("DATA","MEGA Tree");
  char name[128];

  // 26Mg, November/December 2014
  Int_t nrofruns=7;
  Int_t run_no[128]={1069,1072,1078,1085,1090,1091,1098};


  for(Int_t i=0;i<nrofruns;i++)	{
	  sprintf(name,"/home/lmdonaldson/K600/DATA/PR217/sorted0%4d.root",run_no[i]);
          cout<< name<<endl;
	  DATAChain->Add(name);
  }
         

}

