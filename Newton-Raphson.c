#include <stdio.h>
#include <math.h>


double f(double x){
	
	return x + exp(-10.*pow(x,2)) * cos(x);
}

double df(double x){
	
	return 1 - 20.*exp(-10.*pow(x,2))*x*cos(x) - exp(-10.*pow(x,2)) * sin(x);
}

int main(){
	
	const double acc = 5 * pow(10,-10);
	printf("Newton-Raphson Table\nN	x0	x1	F(x1)	ERROR\n");
	int n = 1;
	double x0 = -0.7, x1, err = 1;
	
	while (err >= acc){
		x1 = x0 - f(x0)/df(x0);
		err = fabs(x1 - x0);
		
		printf("%d %f %f %f %f\n", n, x0, x1, f(x1), err);
		
		x0 = x1;
		n++;
		
	}
	return 0;
}
