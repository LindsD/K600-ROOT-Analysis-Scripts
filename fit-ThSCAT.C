
#include "TF1.h"
#include "TMath.h"

void fitThSCAT()
{
gROOT->Reset();

TF1 *p1=new TF1("p1","gaus",-2.2,-1.65);
TF1 *p2=new TF1("p2","gaus",-1.65,-0.98);
TF1 *p3=new TF1("p3","gaus",-0.98,-0.4);
TF1 *p4=new TF1("p4","gaus",-0.4,0.4);
TF1 *p5=new TF1("p5","gaus",0.4,0.98);
TF1 *p6=new TF1("p6","gaus",0.98,1.6);
TF1 *p7=new TF1("p7","gaus",1.6,2.2);

double par[21];

double minfit=-2.2;
double maxfit=2.2;

// Fit when all 7 peaks are there:
TF1 *total = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)",minfit,maxfit);

// Fit when first and last peak are not there
//TF1 *total = new TF1("total","gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)",minfit,maxfit);

// Fit when last 2 peaks are missing:
//TF1 *total = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)",minfit,maxfit);

hThSCAT->Fit(p1,"R");
hThSCAT->Fit(p2,"R");
hThSCAT->Fit(p3,"R");
hThSCAT->Fit(p4,"R");
hThSCAT->Fit(p5,"R");
hThSCAT->Fit(p6,"R");
hThSCAT->Fit(p7,"R");

p1->GetParameters(&par[0]);
p2->GetParameters(&par[3]);
p3->GetParameters(&par[6]);
p4->GetParameters(&par[9]);
p5->GetParameters(&par[12]);
p6->GetParameters(&par[15]);
p7->GetParameters(&par[18]);

total->SetParameters(par);

hThSCAT->Fit(total,"R+");

printf("   ThSCAT   \n");
printf("  %f (-1.84)  %f \n",par[1],par[2]);
printf("  %f (-1.30)  %f \n",par[4],par[5]);
printf("  %f (-0.65)  %f \n",par[7],par[8]);
printf("  %f (0.00)  %f \n",par[10],par[11]);
printf("  %f (0.65) %f \n",par[13],par[14]);
printf("  %f (1.30) %f \n",par[16],par[17]);
printf("  %f (1.84) %f \n",par[19],par[20]);


}
