#include <stdio.h>
#include <math.h>
double minifuncao(double x,double k) {
	double c;
	c = x*pow(M_E,x)-k;
	return c;
}
double bi(double a,double b, int n) {
    double res, x=(a+b)/2,c;
	for(int i=1;i<=10;i++){
		c=minifuncao(x,n);
		if((c*minifuncao(b,n))<0){
			a=x;
		}else{
			b=x;
		}
		if(i!=10){
			x=(a+b)/2;
		}
    }
	return x;
}
int main() {
    double  a, b, k,c;
	scanf("%lf %lf %lf",&k, &a, &b);
	c = bi(a, b, k);
    printf("%lf",c);
    return 0;
}