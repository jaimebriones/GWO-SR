//Funciones Con restricciones
#include <stdio.h>
#include "GWO-C.h"
#include "RngStream.h"

double function(int j, double pos[]){
	double sumF=0, sumF2=0, sumF3=0;
	int i=0;

	for (i = 0; i < 4; i++){
        sumF = sumF + pos[i];
        sumF2 = sumF2 + (pos[i] * pos[i]);
    }

    int tam = sizeof(pos)/sizeof(pos[0]);

    for (i = 0; i < tam; ++i){
    	sumF3 = sumF3 + pos[i];
    }

    return (5*sumF) - (5*sumF2) - sumF3;
}

double getPhi(double x[]){
	double phi=0;

	double g1 = ( (2*x[0]) + (2*x[1]) + (x[9]) + (x[10]) - 10 );
	double g2 = ( (2*x[0]) + (2*x[2]) + (x[9]) + (x[11]) - 10 );
	double g3 = ( (2*x[1]) + (2*x[2]) + (x[10])+ (x[11]) - 10 );
	double g4 = ( -(8*x[0]) + (x[9]) );
	double g5 = ( -(8*x[1]) + (x[10]) );
	double g6 = ( -(8*x[2]) + (x[11]) );
	double g7 = ( -(2*x[3]) - (x[4]) + (x[9]) );
	double g8 = ( -(2*x[5]) + (x[6]) + (x[10]) );
	double g9 = ( -(2*x[7]) + (x[8]) + (x[11]) );

	if(g1<=0){phi =+ g1;}
	if(g2<=0){phi =+ g2;}
	if(g3<=0){phi =+ g3;}
	if(g4<=0){phi =+ g4;}
	if(g5<=0){phi =+ g5;}
	if(g6<=0){phi =+ g6;}
	if(g7<=0){phi =+ g7;}
	if(g8<=0){phi =+ g8;}
	if(g9<=0){phi =+ g9;}

	return phi;
}

int main(int argc, char const *argv[])
{
	srand(time(0));;

    double (*fObj)(int, double[]);

    printf("Funcion 1\n");
    fObj=function;
    GWO(-100, 100, fObj);
    showPack();

	return 0;
}