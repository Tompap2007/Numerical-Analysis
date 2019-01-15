#include <math.h>
#include <stdio.h>

#define N 10.

double s1(double x1,double x2,int k){
	return pow(x1,3)+2*x2-21*(1-k/N);
}

double s2(double x1,double x2,int k){
	return 7*x1+pow(x2,2)-30;
}

double det(double a, double b, double c, double d){
	return a*d-b*c;
}

main(){
	
	double x1=3,x2=-3; 
	double dx1,dx2; 
	const double acc=0.5*pow(10,-5); 
	int k;
	printf("i	x1	x2		dx1	dx2		s01	s02\n");
	
	for(k=1; k<=N; k++){
		printf("\nk = %d\n\n",k);
		int i=0; 
		
		do{
			i++;
			double s01 = s1(x1,x2,k);
			double s02 = s2(x1,x2,k);
			
			double detA = det(3*pow(x1,2),2,7,2*x2);
			
			dx1=det(-s01,2,-s02,2*x2)/detA;
			dx2=det(3*pow(x1,2),-s01,7,-s02) / detA;
			
			printf("%d. %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f\n",i,x1,x2,dx1,dx2,s01,s02);
			
			x1=x1+dx1;
			x2=x2+dx2;
		}while(fabs(dx1) >= acc || fabs(dx2) >= acc);
	}
	
	return 0;
}
