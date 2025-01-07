{
// CUTbasic and CUTflags must be read in prior to running this script
  char name[128];

// PR292 - 58Ni, 24Mg, 12C
Int_t run_no[]={4034,4030,4032,4035,4036,4037,4039,4040,4041,4043,4044,4045,4047,4048,4049,4051};

  Int_t nrofruns=sizeof(run_no)/sizeof(run_no[0]);  
  cout<<" Total nr of runs to peakfit: "<< nrofruns<<endl;

  Double_t par[5];
  Float_t peakposition[20];
  Float_t sigma[20];

  for(Int_t i=0;i<nrofruns;i++)	{
          cout << " Run nr  "<< run_no[i] <<endl;
	  sprintf(name,"~/K600/Data/PR292/ROOT/sorted0%4d.root",run_no[i]);
          //cout << name << endl;
	  TFile *_file0 = TFile::Open(name);
  	  TH1F *hY1 = new TH1F("hY1","Y1",420,-60.,80.);
	  DATA->Draw("Y1>>hY1",CUTbasic,"");
	  hY1->Fit("gaus","QR","",0.,11.);
	  
 	  //if(run_no[i]==3079) hY1->Fit("gaus","QR","",-5.,14.);
	  //if(run_no[i]==3080) hY1->Fit("gaus","QR","",-5.,14.);
	  //if(run_no[i]==3085) hY1->Fit("gaus","QR","",-6.,13.);
	  //if(run_no[i]==3088) hY1->Fit("gaus","QR","",-6.,13.);
	  //if(run_no[i]==3089) hY1->Fit("gaus","QR","",-6.,13.);
	  //if(run_no[i]==3093) hY1->Fit("gaus","QR","",-6.,13.);
	  //if(run_no[i]==3096) hY1->Fit("gaus","QR","",-6.,13.);
	  //if(run_no[i]==3097) hY1->Fit("gaus","QR","",-6.,13.);
	  //if(run_no[i]==3101) hY1->Fit("gaus","QR","",-5.,13.);
	  //if(run_no[i]==3104) hY1->Fit("gaus","QR","",-5.,13.);
	  //if(run_no[i]==3105) hY1->Fit("gaus","QR","",-5.,13.);
	  //if(run_no[i]==3115) hY1->Fit("gaus","QR","",-3.,16.);
	  //if(run_no[i]==3117) hY1->Fit("gaus","QR","",-3.,16.);
	  //if(run_no[i]==3121) hY1->Fit("gaus","QR","",-3.,16.);
	  //if(run_no[i]==3127) hY1->Fit("gaus","QR","",-3.,16.);
	  //if(run_no[i]==3131) hY1->Fit("gaus","QR","",-3.,16.);
	  //if(run_no[i]==3136) hY1->Fit("gaus","QR","",-1.,18.);
	  //if(run_no[i]==3140) hY1->Fit("gaus","QR","",-1.,18.);
	  //if(run_no[i]==3144) hY1->Fit("gaus","QR","",0.,18.);
	  //if(run_no[i]==3178) hY1->Fit("gaus","QR","",-11.,10.);
	  //if(run_no[i]==3182) hY1->Fit("gaus","QR","",-11.,10.);
	  //if(run_no[i]==3186) hY1->Fit("gaus","QR","",-11.,8.);
	  //if(run_no[i]==3190) hY1->Fit("gaus","QR","",-11.,8.);
	  //if(run_no[i]==3193) hY1->Fit("gaus","QR","",-11.,9.);
	  //if(run_no[i]==3194) hY1->Fit("gaus","QR","",-11.,9.);
	  //if(run_no[i]==3196) hY1->Fit("gaus","QR","",-11.,10.);

	  gaus->GetParameters(par);
          peakposition[i] = hY1->GetFunction("gaus")->GetParameter(1);
          sigma[i] = hY1->GetFunction("gaus")->GetParameter(2);

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




