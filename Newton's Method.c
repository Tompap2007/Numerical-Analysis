#include <stdio.h>
#include <math.h>


double f1(double x1, double x2, double x3){
	
	return 3.*pow(x1,3) - 12.*pow(x2,5) + 13.*pow(x3,2) - 4;
}
double f2(double x1, double x2, double x3){
	
	return pow(x1,4) + 2.*pow(x2,2) - 12.*pow(x3,5) + 9;
}
double f3(double x1, double x2, double x3){
	
	return pow(x1,2) - 2.*pow(x2,2) + 2.*pow(x3,3) - 1;
}
double df1x1(double x1){	
	return 9.*pow(x1,2);
}
double df1x2(double x2){	
	return -60.*pow(x2,4);
}
double df1x3(double x3){	
	return 26.*x3;
}

double df2x1(double x1){
	return 4.*pow(x1,3);
}
double df2x2(double x2){
	return 4.*x2;
}
double df2x3(double x3){
	return -60.*pow(x3,4);
}

double df3x1(double x1){
	return 2.*x1;
}
double df3x2(double x2){
	return -4.*x2;
}
double df3x3(double x3){
	return 6.*pow(x3,2);
}

double det(double a,double b,double c,
			double d,double e,double f,
			double g, double h, double i){
				
				return a*e*i + b*f*g + c*d*h - g*e*c - h*f*a - i*d*b;
			}

int main(){
	
	const double acc = 5 * pow(10,-10);
	printf("Pinakas Newton\nN	dx1	dx2	dx3	x1	x2		x3  f1(x1,x2,x3) f2(x1,x2,x3) f3(x1,x2,x3)\n");
	int n = 1;
	double dx1 = 1, dx2 = 1, dx3 = 1, x1 = 1.5, x2 = 1.5, x3 = 1.5, detA, detA1, detA2, detA3, f01, f02, f03;
	
	while (fabs(dx1) >= acc || fabs(dx2) >= acc || fabs(dx3) >= acc){
		
		detA = det(df1x1(x1), df1x2(x2), df1x3(x3), df2x1(x1), df2x2(x2), df2x3(x3), df3x1(x1), df3x2(x2), df3x3(x3));
		f01 = f1(x1,x2,x3);
		f02 = f2(x1,x2,x3);
		f03 = f3(x1,x2,x3);
		
		detA1 = det(-f01, df1x2(x2), df1x3(x3), -f02, df2x2(x2), df2x3(x3), -f03, df3x2(x2), df3x3(x3));
		detA2 = det(df1x1(x1), -f01, df1x3(x3), df2x1(x1), -f02, df2x3(x3), df3x1(x1), -f03, df3x3(x3));
		detA3 = det(df1x1(x1), df1x2(x2), -f01, df2x1(x1), df2x2(x2), -f02, df3x1(x1), df3x2(x2), -f03);
		
		dx1 = detA1 / detA;
		dx2 = detA2 / detA;
		dx3 = detA3 / detA;
		
		x1 = x1 + dx1;
		x2 = x2 + dx2;
		x3 = x3 + dx3;
		
		printf("%d %f %f %f %f %f %f %f %f %f\n", n, dx1, dx2, dx3, x1, x2, x3, f1(x1,x2,x3), f2(x1,x2,x3), f3(x1,x2,x3));
		
		
		n++;
		
	}
	return 0;
}
