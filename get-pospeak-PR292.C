{
  // Use CUTbasic, CUTflags and CUTy as defined elsewhee 
  char name[128];
  char text[128];

  // 24Mg, PR292
  Int_t nrofruns=3;
  Int_t run_no[]={4034,4041,4044};

  //Int_t nrofruns=sizeof(run_no)/sizeof(run_no[0]); 

  Double_t fitgauslow=617;  // to define range where gauss fitting is done
  Double_t fitgaushi=621;   // to define range where gauss fitting is done
  Double_t fitcombinedlow=615;    // range over which fitting is performed
  Double_t fitcombinedhi=623;	  // range over which fitting is performed
  Double_t rangelow=fitcombinedlow;    // range of TF1 fit
  Double_t rangehi=fitcombinedhi;     // range of TF1 fit 
 
  // for first pass fit: only gaussian
  Double_t par[5];
  Double_t peakposition[3];
  Double_t sigma[3];
  Double_t strength[3];

  // for fit with gaussian plus polynomial
  Double_t peakposition2[3];
  Double_t sigma2[3];
  Double_t pol0=100,pol1=0;
  TF1 *fit = new TF1("fit","gaus(0) + pol2(3)",rangelow,rangehi);
  Double_t par2[5];

  for(Int_t i=0;i<nrofruns;i++)	{
	  sprintf(text,"-------- Fitting run nr %4d:",run_no[i]);
          cout << text << endl;
	  sprintf(name,"~/K600/Data/PR292/ROOT/sorted0%4d.root",run_no[i]);
	  TFile *_file0 = TFile::Open(name);     

	  cout<<"First fitting a single gaussian..."<<endl;
  	  TH1F *hX1pos = new TH1F("hX1pos","X1 Position",2000,300.,800.);
	  hX1pos->GetXaxis()->SetRangeUser(600.,650.);
          DATA->Draw("X1posCTOF>>hX1pos",CUTbasic && CUTflags && CUTy,"");
	  hX1pos->Fit("gaus","R","",fitgauslow,fitgaushi);


//	  	if(run_no[i]==3177)  hX1pos->Fit("gaus","QR","",fitgauslow-6.7,fitgaushi-7.8);
//	  	if(run_no[i]==3181)  hX1pos->Fit("gaus","QR","",fitgauslow-6.0,fitgaushi-7.5);
//	  	if(run_no[i]==3185)  hX1pos->Fit("gaus","QR","",fitgauslow-6.1,fitgaushi-7.1);
//	  	if(run_no[i]==3188)  hX1pos->Fit("gaus","QR","",fitgauslow-6.0,fitgaushi-6.9);
//	  	if(run_no[i]==3191)  hX1pos->Fit("gaus","QR","",fitgauslow-6.0,fitgaushi-6.8);
//	  	if(run_no[i]==3195)  hX1pos->Fit("gaus","QR","",fitgauslow-6.0,fitgaushi-6.8);
	  		  
	  	strength[i] = hX1pos->GetFunction("gaus")->GetParameter(0);
	  	peakposition[i] = hX1pos->GetFunction("gaus")->GetParameter(1);
	  	sigma[i] = hX1pos->GetFunction("gaus")->GetParameter(2);
	  	c1->Modified(); c1->Update();
	  	c1->WaitPrimitive();
 
	  cout<<"Now use the gaussian fit as a starting point for a fit of a gaussian and a polynomial"<<endl;
	  fit->SetParameters(strength[i],peakposition[i],sigma[i],pol0,pol1);
          hX1pos->Fit("fit","R","",fitcombinedlow,fitcombinedhi);
          	
//		if(run_no[i]==3177) hX1pos->Fit("fit","QR","",fitcombinedlow-6.8,fitcombinedhi-7.3);
//		if(run_no[i]==3181) hX1pos->Fit("fit","QR","",fitcombinedlow-5.9,fitcombinedhi-7.3);
//		if(run_no[i]==3185) hX1pos->Fit("fit","QR","",fitcombinedlow-5.9,fitcombinedhi-7.2);
//		if(run_no[i]==3188) hX1pos->Fit("fit","QR","",fitcombinedlow-6.3,fitcombinedhi-7.1);
//		if(run_no[i]==3191) hX1pos->Fit("fit","QR","",fitcombinedlow-4.9,fitcombinedhi-7.1);
//		if(run_no[i]==3195) hX1pos->Fit("fit","QR","",fitcombinedlow-4.9,fitcombinedhi-7.2);
          		
		peakposition2[i] = hX1pos->GetFunction("fit")->GetParameter(1);
	  	sigma2[i] = hX1pos->GetFunction("fit")->GetParameter(2);
	  	c1->Modified(); c1->Update();
	  	c1->WaitPrimitive(); 
  }
  cout << endl;
  cout << "First pass fit: extract estimates for gaussian position and width: "<< endl;
  for(Int_t i=0;i<nrofruns;i++)	{
    	 cout << "Run nr: "<< run_no[i] <<"  Peak position: "<< peakposition[i] <<"  Peak sigma:"<< sigma[i] << endl;
  }	  
  cout << endl;
  cout << "Final fit: gaussian plus a polynomial: "<< endl;
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << "Run nr: "<< run_no[i] <<"  Peak position: "<< peakposition2[i] <<"  Peak sigma:"<< sigma2[i] << endl;
  }
  cout << endl;
  cout << "Note the difference between fitting a single gaussian compared to a more complete fit... "<< endl;
  cout << "-----------------------------------------------------"<< endl; 
  cout << endl;
  cout << "Copy the following into your x1 position offset file: "<< endl;
  cout << endl;
  for(Int_t i=0;i<nrofruns;i++)	{
     cout <<  run_no[i] <<"  "<< peakposition2[0] - peakposition2[i]<< endl;
  }



}




