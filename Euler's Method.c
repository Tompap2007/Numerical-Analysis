#include "stdio.h"
#include "math.h"

double df(double x, double y){
	return -100*y + 5*pow(x,3./2)*(1 + 40*x); //replace with your function
}

int main(){
	
	double h = 0.0227, y = 0, x = 0; //starting values
	int i = 1; // this is just a counter
	
	for (x = 0; x <= 1; x = x + h){
		y = y + df(x,y) * h;
		printf ("%d %f %f\n", i, x, y);
		i++;
	}
	printf("\n\n");
	h = 0.0227 / 2.0; //repeat with step h/2
	y = 0;
	x = 0;
	i = 1;
	
	for (x = 0; x <= 1; x = x + h){
		y = y + df(x,y) * h;
		printf ("%d %f %f\n", i, x, y);
		i++;
	}
	
 	return 0;	  
}
