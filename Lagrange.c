#include <stdio.h>
#include <math.h>

double L(double *X, int k, int n, double val){
	int i;
	double l = 1;
	for (i = 0; i <= n; i++){
		if(i!=k){
			l *= (val-X[i])/(X[k]-X[i]);
		}
		
	}
	return l;
}

double factorial(double k){
	
	double num = 1;	
	int i;
	for(i = 1; i <= k; i++){
		
		num *= i;
	}
	return num;	
}

double E(double *X, int k, int n, double val){
	int i = 0;
	double P = cos(X[k] + (n+1)*M_PI/2.)/factorial(n+1);
	for (i = 0; i <= n; i++)
		P *= (val - X[i]);
	return P;
}

main(){
	
	double sum = 0, fE, b = 0;
	int i = 0;
	double X[4] = {0, M_PI/4, M_PI/3, M_PI/2};
	double Y[4] = {1, sqrt(2)/2., 1./2., 0};
	for (i = 0; i < 4; i++){
		
		sum += L(X, i, 3, M_PI/12)*Y[i];
		fE = fabs(E(X,i,3,M_PI/12));
		
		if (b < fE){
			b = fE;
		}
			
		
	}
	
	printf("y = %f\nerror = %f\n", sum, b);
	
	
	
	return 0;
}
