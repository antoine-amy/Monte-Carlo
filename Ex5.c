#include <math.h>
#include <stdio.h>
#include "unif.h"

//Compiler avec -lm; soit "gcc Ex5.c -lm -o Ex5"

int main(){
    const int Nsub=14, Nsim=10000;
    double xmi[Nsub], phi[Nsub], xmin=-0.2, xmax=1.2;
    int i,j;
    double x, dx=(xmax-xmin)/Nsub;
    for(j=0;j<Nsub;j++){
        phi[j]=0; //phi nbr de valeur random dans chaque intervalle
    }
    
    for(i=0;i<Nsim;i++){
        x=unif(); //nbr aléatoire avec le header
        j=floor((x-xmin)/dx); //j numéro de l'intervalle, sa renvoit la troncature du nombre de fois dx qu'on a dans x
        //printf(%f %d \n",x,j);
        if(j>=0 && j<Nsub){ //On rajoute 1 au poid de l'intervalle
            phi[j]+=1;
        }
    }
    for(j=0;j<Nsub;j++){
        xmi[j]=xmin+(j+0.5)*dx; //on prend le centre de l'intervalle
        phi[j]=phi[j]/dx/Nsim; //on normalise le poids
        printf("\t%f\t%f \n",xmi[j],phi[j]);
    }
}