#include <stdio.h>
#include <math.h>

int main() {
    float a,b,c,d;
    scanf("%f %f %f", &a, &b, &c);
    d = (b*b)+(-4*a*c);
    if (d<0) {
        printf("nao ha raiz real\n");
        return 0;
    } else if (d>0) {
            d = pow(d,0.5);
            printf("%.4f %.4f\n", ((b*-1)+d)/(2*a), ((b*-1)-d)/(2*a));
    } else {
        d = pow(d,0.5);
        printf("%.4f\n", ((b*-1)+d)/(2*a)); 
    }
    return 0;
}