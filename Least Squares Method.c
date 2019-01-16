#include <stdio.h>
#include <math.h>


double det(int a, int b, int c, int d, int e, int f, int g, int h, int i){
	return a*e*i + b*f*g + c*d*h - g*e*c - h*f*a - i*d*b;
}



int main(){
	
	int n = 5, i;
	int x[] = {0,1,2,3,4};
	int y[] = {1,2,2,4,5};
	double a0 = 0, a1 = 0, a2 = 0;
	int sumx = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0, sumy = 0, sumxy = 0, sumx2y = 0;
	
	for(i=0; i<n; i++){
		sumx += x[i];
		sumx2 += pow(x[i],2);
		sumx3 += pow(x[i],3);
		sumx4 += pow(x[i],4);
		sumy += y[i];
		sumxy += x[i] * y[i];
		sumx2y += pow(x[i],2) * y[i];
	}
	
	double detA = det(n, sumx, sumx2, sumx, sumx2, sumx3, sumx2, sumx3, sumx4);
	double detAa0 = det(sumy, sumx, sumx2, sumxy, sumx2, sumx3, sumx2y, sumx3, sumx4);
	double detAa1 = det(n, sumy, sumx2, sumx, sumxy, sumx3, sumx2, sumx2y, sumx4);
	double detAa2 = det(n, sumx, sumy, sumx, sumx2, sumxy, sumx2, sumx3, sumx2y);
	
	a0 = detAa0 / detA;
	a1 = detAa1 / detA;
	a2 = detAa2 / detA;
	
	printf("%f %f %f", a0, a1, a2);
	
	
	return 0;
}
