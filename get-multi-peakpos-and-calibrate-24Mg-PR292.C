{
  Double_t pi=3.14159265359;
  // Use CUTbasic, CUTlimits as defined elsewhee 
  char name[128];
  char text2[128];

  int nrofpeaks=5; //9;
  Double_t startposition[nrofpeaks];
  Double_t low[nrofpeaks];
  Double_t high[nrofpeaks];
  Double_t Ex[nrofpeaks];
  Double_t ExErr[nrofpeaks];

//-------------------------------------------------------------
  startposition[0]=618.331;
  startposition[1]=602.627;
  startposition[2]=452.099;
  startposition[3]=362.714;
  startposition[4]=235.714;

  low[0]=startposition[0]-2;   high[0]=startposition[0]+2;
  low[1]=startposition[1]-2;   high[1]=startposition[1]+2;
  low[2]=startposition[2]-2;   high[2]=startposition[2]+2;
  low[3]=startposition[3]-1.5;   high[3]=startposition[3]+1.5;
  low[4]=startposition[4]-1.5; high[4]=startposition[4]+1.5;

  Ex[0]=4.23824;
  Ex[1]=4.43982;
  Ex[2]=6.43230;
  Ex[3]=7.61647;
  Ex[4]=9.28422;
//-----------------------------------------------------

    // for first pass fit: only gaussian
  Double_t par[nrofpeaks];
  Double_t peakposition[nrofpeaks];
  Double_t sigma[nrofpeaks];
  Double_t strength[nrofpeaks];

  // for fit with gaussian plus polynomial
  Double_t par2[nrofpeaks];
  Double_t peakposition2[nrofpeaks];
  Double_t sigma2[nrofpeaks];
  Double_t posErr[nrofpeaks];

  Double_t pol0=100,pol1=0;

  TF1 *fit = new TF1("fit","gaus(0) + pol2(3)",0,800);
 
  for(Int_t i=0;i<nrofpeaks;i++)	{
	  sprintf(text2,"-------- Fitting peak %1d:",i);
          cout << text2 << endl;
          hX1diff->SetAxisRange(startposition[i]-30.,startposition[i]+30.);

	  hX1diff->Fit("gaus","R","",low[i],high[i]);  
    	  	
		gaus->GetParameters(par);
		strength[i] = hX1diff->GetFunction("gaus")->GetParameter(0);
		peakposition[i] = hX1diff->GetFunction("gaus")->GetParameter(1);
		sigma[i] = hX1diff->GetFunction("gaus")->GetParameter(2);
	  
	  c1->Modified(); c1->Update();
	  c1->WaitPrimitive();

  // for fit with gaussian plus polynomial

	  fit->SetParameters(strength[i],peakposition[i],sigma[i],pol0,pol1);
          hX1diff->Fit("fit","R","",low[i],high[i]);

		peakposition2[i] = hX1diff->GetFunction("fit")->GetParameter(1);
		sigma2[i] = hX1diff->GetFunction("fit")->GetParameter(2);
		posErr[i] = hX1diff->GetFunction("fit")->GetParError(1);

	  c1->Modified(); c1->Update();
	  c1->WaitPrimitive(); 
  }

  cout << "Final fit: gaussian plus a polynomial: "<< endl;
  for(Int_t i=0;i<nrofpeaks;i++)	{
     cout <<"  Peak position: "<< peakposition2[i] <<"  Peak sigma: "<< sigma2[i] << endl;
  }
  cout << endl;

  cout <<"Ex (MeV)  Peak position (mm)   Peak Err "<< endl;
  for(Int_t i=0;i<nrofpeaks;i++)	{
     cout << Ex[i]  <<" "<< peakposition2[i] << " " << posErr[i]<< endl;
  }
  cout << endl;

}




