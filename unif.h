#include <math.h>
#include <stdio.h>
unsigned int iran1=115431, iran2=432751;

double unif(){
    unsigned int a=90696, b=0;
    iran1=(a*iran1+b);
    iran2=iran2^(iran2<<17);
    iran2=iran2^(iran2>>15);
    return (double) (iran1^iran2) / 2. /pow(2,31);
}