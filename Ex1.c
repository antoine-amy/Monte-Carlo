#include <math.h>
#include <stdio.h>
#include "unif.h"

//compile with gcc Ex1.c -lm -o Ex1

int main(){
    const int Nsub=15, Nsim=10000;
    double xmi[Nsub], phi[Nsub], fun[Nsub], xmin=0, xmax=3;
    int i,j;
    double x, dx=(xmax-xmin)/Nsub;
    char *filename="out.txt";
    FILE *fp = fopen(filename, "w");

    for(j=0;j<Nsub;j++){
        phi[j]=0;
    }
    for(i=0;i<Nsim;i++){
        x=-log(1-unif());  //permet de suivre une loi exp
        j=floor((x-xmin)/dx);
        if(j>=0 && j<Nsub){
            phi[j]+=1;
        }
    }

    for(j=0;j<Nsub;j++){
        xmi[j]=xmin+(j+0.5)*dx;
        phi[j]=phi[j]/dx/Nsim;
        fun[j]=exp(-xmi[j]);
        fprintf(fp,"\t%f\t%f\t%f \n",xmi[j],phi[j],fun[j]);
    }
    fclose(fp);
}