
#include "TF1.h"
#include "TMath.h"

void fitThFP()
{
gROOT->Reset();

double minfit=23.;
double maxfit=33.;

// These values come from hThFP

/*    //for run 110
TF1 *p1=new TF1("p1","gaus",23.7,24.4);
TF1 *p2=new TF1("p2","gaus",24.4,25.2);
TF1 *p3=new TF1("p3","gaus",25.2,26.0);
TF1 *p4=new TF1("p4","gaus",26.0,27.0);
TF1 *p5=new TF1("p5","gaus",27.0,27.8);
TF1 *p6=new TF1("p6","gaus",27.8,28.6);
TF1 *p7=new TF1("p7","gaus",28.6,29.6);
*/
  
/*  //for run 113
TF1 *p1=new TF1("p1","gaus",25.8,26.5);
TF1 *p2=new TF1("p2","gaus",26.5,27.5);
TF1 *p3=new TF1("p3","gaus",27.5,28.4);
TF1 *p4=new TF1("p4","gaus",28.4,29.4);
TF1 *p5=new TF1("p5","gaus",29.4,30.2);
TF1 *p6=new TF1("p6","gaus",30.2,31.1);
TF1 *p7=new TF1("p7","gaus",31.1,32.0);
*/

   //for run 114
TF1 *p1=new TF1("p1","gaus",24.6,25.3);
TF1 *p2=new TF1("p2","gaus",25.3,26.2);
TF1 *p3=new TF1("p3","gaus",26.2,27.0);
TF1 *p4=new TF1("p4","gaus",27.0,28.1);
TF1 *p5=new TF1("p5","gaus",28.1,28.8);


double par[21];

// For all 7 peaks there:
//TF1 *total = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)",minfit,maxfit);

// For first peak missing:
//TF1 *total = new TF1("total","gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)",minfit,maxfit);

// For first and last peak missing: 
//TF1 *total = new TF1("total","gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)",minfit,maxfit);

// For first 2 peaks missing:
//TF1 *total = new TF1("total","gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)",minfit,maxfit);

// For last 2 peaks missing:
TF1 *total = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)",minfit,maxfit);

hThFP->Fit(p1,"R");
hThFP->Fit(p2,"R");
hThFP->Fit(p3,"R");
hThFP->Fit(p4,"R");
hThFP->Fit(p5,"R");
//hThFP->Fit(p6,"R");
//hThFP->Fit(p7,"R");

p1->GetParameters(&par[0]);
p2->GetParameters(&par[3]);
p3->GetParameters(&par[6]);
p4->GetParameters(&par[9]);
p5->GetParameters(&par[12]);
//p6->GetParameters(&par[15]);
//p7->GetParameters(&par[18]);

total->SetParameters(par);

hThFP->Fit(total,"R+");

double theta[7];
theta[0]=1.84;
theta[1]=1.30;
theta[2]=0.65;
theta[3]=0.0;
theta[4]=-0.65;
//theta[5]=-1.30;
//theta[6]=-1.84;

double phi[7];
phi[0]=-1.84;
phi[1]=-1.30;
phi[2]=-0.65;
phi[3]=0.0;
phi[4]=0.65;
//phi[5]=1.30;
//phi[6]=1.84;

// Now we need to give the positions of the line in the ThSCATvsX1 spectrum

double X[7];
X[0]=635.5;  //Run 110
X[1]=185.1;  //Run 113
X[2]=432.8;  //Run 114

int xnr=2;	// determines which X value is to be printed
int phinr=3;	// determines which phi value is to be printed

printf("X           phi angle  ThSCAT    ThFP     sigma  \n");
printf("%f %f %f %f %f \n",X[xnr],phi[phinr],theta[0],par[1],par[2]);
printf("%f %f %f %f %f \n",X[xnr],phi[phinr],theta[1],par[4],par[5]);
printf("%f %f %f %f %f \n",X[xnr],phi[phinr],theta[2],par[7],par[8]);
printf("%f %f %f %f %f \n",X[xnr],phi[phinr],theta[3],par[10],par[11]);
printf("%f %f %f %f %f \n",X[xnr],phi[phinr],theta[4],par[13],par[14]);
printf("%f %f %f %f %f \n",X[xnr],phi[phinr],theta[5],par[16],par[17]);
printf("%f %f %f %f %f \n",X[xnr],phi[phinr],theta[6],par[19],par[20]);


}



