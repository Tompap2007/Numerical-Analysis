#include <stdio.h>
#include <math.h>

double f(double x){
	return exp(-x/2)+cos(3.5*x)-3/(x-4);
}


int main(){
	
	double result = (0.888888888888889*f((0.000000000000000 + 3) / 2) + 0.555555555555556 * f((-0.774596669241483+3) / 2) 
	+ 0.555555555555556 * f((0.774596669241483 + 3) / 2))/2;
	
	printf("%.15f", result);
	
	return 0;
}
