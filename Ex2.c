#include <math.h>
#include <stdio.h>
unsigned int iran2=432751;

double unif2(){
    iran2=iran2^(iran2<<17);
    iran2^(iran2>>15);
    return (double) iran2 / 2. /pow(2,31);
}

int main(){
    int i; double x;
    for(i=0;i<10;i++){
        x=unif2();
        printf("x=%f\n",x);
    }
}