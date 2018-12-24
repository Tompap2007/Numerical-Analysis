#include "stdio.h"
#include "math.h"

double f(double x){
	return exp(-x/2) + cos(3.5*x) - 3/(x-4); //replace this with your function
}

int main(){
	
	double a = 1, b = 2, n = 50, sum1 = 0, sum2 = 0, res = 0; //replace a,b and n with your values
	double h = (b-a)/n;
	
	for (int x = 1; x < 50; x++){
		sum1 = sum1 + f(1+(double)x*h);
	}
 	
	sum2 = (f(0) + f(n))/2;
	res = (sum1 + sum2)*h;
	printf("%f", res);
	return 0;	  
}
