#include <stdio.h>
#include <math.h>
double minifuncao(double x) {
	double c;

	c = pow(x,3);
	c = sin((c/10));
	c = x*c;

	return c;
}
double trapezio(double a,double b, int n) {
    double res, h=((b-a)/n),pa=0,som=0;
	for(int i=0;i<=n;i++){
        if (i==0||i==n){
            som = som + minifuncao(a + (h*i));
        }else {
        	pa = pa + minifuncao(a + (h*i));
     
        }
    }

    res = (h/2)*(som+2*pa);
	printf("%0.12lf",res);
	return 0;
}

int main() {
    double  a, b, n;
	scanf("%lf %lf %lf",&a, &b, &n);
	trapezio(a, b, n);
    
    return 0;
}