#include <stdio.h>
#include <math.h>
double Simpson(double a,double b, int n,double vnm,double dp);
double minifuncao(double x,double vnm, double dp);
int erro(double x, double vnm, double dp);
double Secante(double x0,double x1,double vnm,double dp,double conf ,double const1){
    double a=vnm,b0=(vnm+x0),b1=(vnm+x1),f0,f1,c=x1;
    int n0,n1;
    n0=erro(x0,vnm,dp);
    n1=erro(x1,vnm,dp);
	f0=const1*Simpson(a,b0,n0,vnm,dp)-conf;
	f1=const1*Simpson(a,b1,n1,vnm,dp)-conf;
	if (((f1-f0)==0)||((x1-x0)==0)) {
		return x1;
	}
    x1=(x0*f1-x1*f0)/(f1-f0);
	f1=const1*Simpson(a,b1,n1,vnm,dp)-conf;
	if (f1<0){
		f1=f1*(-1);
	}
	c=x1-c;
	c=sqrt((c*c));
	if (((f1)<0.0000001)||((c)<0.0000001)) {
		return x1;
	}
    return x1;
}
double Simpson(double a,double b, int n,double vnm,double dp) {
    double res,h=((b-a)/n),im=0,pa=0,som=0;
    int i;
    for(i=0;i<=n;i++){
        if (i==0||i==n){
            som = som+minifuncao(a+(h*i),vnm,dp);
        }else if (i%2==0){
            pa= pa+minifuncao(a+(h*i),vnm,dp);
        } else {
            im= im+minifuncao(a+(h*i),vnm,dp);      
        }
    }
    res = (h/3)*(som+4*im+2*pa);
    return res;
}
double minifuncao(double x,double vnm, double dp) {
    double res;
    res = pow(M_E,(-1*pow((x-vnm),2))/(2*pow(dp,2)));
    return res;
}

int erro(double x,double vnm, double dp){
    double err=0, a=vnm,b=vnm+x;
    int n=2, i;
    for (i=0;i<=5000;i++){
		if (i%2==0){
			err = Simpson(a,b,n+i,vnm,dp)-Simpson(a,b,(n+2+i),vnm,dp);
		}else {
			err = Simpson(a,b,n+i+1,vnm,dp)-Simpson(a,b,(n+3+i),vnm,dp);
		}
        err = sqrt((err*err));
        if (err<0.000000001) {
            n = n + i + 9999;
            return n;
        }
    }
    n=n+i;
    return 0;
}
int main() {
    double vnm, dp, conf,res,aux,mod;
    double const1, a, b,x0=0.00001,x1=0.00002,err;
    int n;
    scanf("%lf %lf %lf",&vnm,&dp,&conf);
	const1 = 2/(dp*sqrt(2*M_PI));
    for (int i = 0; i<60; i++) {
		aux=Secante(x0,x1,vnm,dp,conf,const1);
		mod = pow((aux-x1),2);
		mod = sqrt(mod);
		if ((mod)<0.000000000001) {
			printf("%0.12lf\n",(vnm-aux));
			printf("%0.12lf",(vnm+aux));
			return 0;
		}
    	x0=x1;
    	x1=aux;
	}
    return 1;
}