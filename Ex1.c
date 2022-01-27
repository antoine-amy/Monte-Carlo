#include <math.h>
#include <stdio.h>
unsigned int iran1=115431;

double unif1(){
    unsigned int a=90696, b=0;
    iran1=(a*iran1+b);
    return (double) iran1 / 2. /pow(2,31);
}

int main(){
    int i; double x;
    for(i=0;i<10;i++){
        x=unif1();
        printf("x=%f\n",x);
    }
}