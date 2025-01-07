{
// CUTbasic must be read in prior to running this script. 
char name[128];

// PR292 - 58Ni, 24Mg, 12C   
Int_t run_no[]={4034,4030,4032,4035,4036,4037,4039,4040,4041,4043,4044,4045,4047,4048,4049,4051};
  
  Int_t nrofruns=sizeof(run_no)/sizeof(run_no[0]);  
  cout<<" Total nr of runs to peakfit: "<< nrofruns<<endl;

  Double_t par[5];
  Float_t peakposition[100];
  Float_t sigma[100];

  for(Int_t i=0;i<nrofruns;i++)	{
          cout << " Run nr  " << run_no[i] << endl;
	  sprintf(name,"/home/lmdonaldson/K600/Data/PR292/ROOT/sorted0%4d.root",run_no[i]);
          //cout << name << endl;
	  TFile *_file0 = TFile::Open(name);
  	  TH1F *htof = new TH1F("htof","TOF",400,2000.,2400.);
          DATA->Draw("tof>>htof",CUTbasic,"");
          htof->Fit("gaus","QR","",2210.,2251.);

	  if(run_no[i]==4034) htof->Fit("gaus","QR","",2225.,2251.);
	  if(run_no[i]==4032) htof->Fit("gaus","QR","",2210.,2251.);
	  if(run_no[i]==4035) htof->Fit("gaus","QR","",2210.,2251.);
	  if(run_no[i]==4036) htof->Fit("gaus","QR","",2210.,2251.);
	  if(run_no[i]==4039) htof->Fit("gaus","QR","",2210.,2251.);
	  if(run_no[i]==4040) htof->Fit("gaus","QR","",2210.,2251.);
	  if(run_no[i]==4043) htof->Fit("gaus","QR","",2210.,2251.);
	  if(run_no[i]==4045) htof->Fit("gaus","QR","",2225.,2251.);
	  if(run_no[i]==4048) htof->Fit("gaus","QR","",2220.,2231.);
	  if(run_no[i]==4049) htof->Fit("gaus","QR","",2220.,2231.);
          if(run_no[i]==4051) htof->Fit("gaus","QR","",2220.,2231.);

    	  gaus->GetParameters(par);
          peakposition[i] = htof->GetFunction("gaus")->GetParameter(1);
          sigma[i] = htof->GetFunction("gaus")->GetParameter(2);

	  c1->Modified(); c1->Update();
	  c1->WaitPrimitive(); 
  }
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << " "<< run_no[i] <<" "<< peakposition[i] <<" "<< sigma[i] << endl;
  }
 
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << run_no[i] <<"  "<< int(peakposition[0]-peakposition[i]) << endl;
  }

}

 
