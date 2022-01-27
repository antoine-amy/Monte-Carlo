#include <math.h>
#include <stdio.h>
#include "unif.h"

int main(){
    int i; double x;
    for(i=0;i<20;i++){
        x=unif();
        printf("x=%f\n",x);
    }
}