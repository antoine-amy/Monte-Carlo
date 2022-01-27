#include <math.h>
#include <stdio.h>
#include "unif.h"

//compile with gcc Ex2.c -lm -o Ex2

int main(){
    const int Nsub=12, Nsim=10000;
    double xmi[Nsub], phi[Nsub], fun[Nsub], xmin=0, xmax=1.;
    int i,j;
    double x, dx=(xmax-xmin)/Nsub;
    char *filename="out.txt";
    FILE *fp = fopen(filename, "w");

    for(j=0;j<Nsub;j++){
        phi[j]=0;
    }
    for(i=0;i<Nsim;i++){
        x=pow(unif(),1./8); //on met un point parce que sinon il considere que c'est un entier et ça bugue
        j=floor((x-xmin)/dx);
        if(j>=0 && j<Nsub){
            phi[j]+=1;
        }
    }

    for(j=0;j<Nsub;j++){
        xmi[j]=xmin+(j+0.5)*dx;
        phi[j]=phi[j]/dx/Nsim;
        fun[j]=8*pow(xmi[j],7);
        fprintf(fp,"\t%f\t%f\t%f \n",xmi[j],phi[j],fun[j]);
    }
    fclose(fp);
}