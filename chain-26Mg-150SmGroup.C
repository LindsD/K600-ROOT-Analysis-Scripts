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

// DATAChain->Draw("(X1pos+0.9*ThSCAT-0.4*ThSCAT^2+0.1*ThSCAT^4)>>hX1pos","CUTtofX1 && CUTpad1tof && pad2<1000 && pad2>100 && X1flag==0 && X1pos>-100 && Y1>-25 && Y1<-5 && ThSCAT>-2.5","");
// DATAChain->Draw("ThSCAT:(X1pos+0.9*ThSCAT-0.4*ThSCAT^2+0.1*ThSCAT^4)>>hThSCATvsX1","CUTtofX1 && CUTpad1tof && pad2<1000 && pad2>100 && X1flag==0 && X1pos>-100 && Y1>-25 && Y1<-5 && ThSCAT>-2.5","col");
// DATAChain->Draw("Y1:(X1pos+0.9*ThSCAT-0.4*ThSCAT^2+0.1*ThSCAT^4)>>hY1vsX1","CUTtofX1 && CUTpad1tof && pad2<1000 && pad2>100 && X1flag==0 && X1pos>-100 &&  ThSCAT>-2.5","col");        
 

}

