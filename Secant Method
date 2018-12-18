#include "stdio.h"
#include "math.h"

double f(const double x){

	return x + exp(-10.*pow(x,2))*cos(x); // change this with the function you study
}

int main(){

	double x1 = -0.7; // change this with your given starting value
	double x0 = -0.69;
	int i = 0;
	double en = 0;
	const double spec = 0.5 * pow(10,-10);
	

	printf("%s %s %s %s\n", "N", "Xn", "F(x)", "En");
	
	do{
		double x = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
		i++;
		en = fabs(x1 -x0);
		printf("%d %f %f %f\n", i, x1, f(x1), en);
		x0 = x1;
		x1 = x;
	
	
	}while(en >= spec);

	return 0;	  
}
