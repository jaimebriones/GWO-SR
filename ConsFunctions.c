//Funciones Con restricciones
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ConsFunctions.h"
#include "GWO-C.h"
double function(int j, double pos[], int size){
	double sumF=0, sumF2=0, sumF3=0;
	int i=0;

	for (i = 0; i < 4; i++){
        sumF = sumF + pos[i];
        sumF2 = sumF2 + (pos[i] * pos[i]);
    }

    //int tam = sizeof(pos)/sizeof(pos[0]); //GTP: ojo te va a arrojar un error, el sizeof de pos sólo te da el tamanio de un double *, no del arreglo completo

    for (i = 0; i < size; ++i){
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

	if(g1<=0){phi += g1;} //gtp: you have =+ operator, but this does not exists in c, it is +=
	if(g2<=0){phi += g2;} //gtp: you have =+ operator, but this does not exists in c, it is +=
	if(g3<=0){phi += g3;} //gtp: you have =+ operator, but this does not exists in c, it is +=
	if(g4<=0){phi += g4;} //gtp: you have =+ operator, but this does not exists in c, it is +=
	if(g5<=0){phi += g5;} //gtp: you have =+ operator, but this does not exists in c, it is +=
	if(g6<=0){phi += g6;} //gtp: you have =+ operator, but this does not exists in c, it is +=
	if(g7<=0){phi += g7;} //gtp: you have =+ operator, but this does not exists in c, it is +=
	if(g8<=0){phi += g8;} //gtp: you have =+ operator, but this does not exists in c, it is +=
	if(g9<=0){phi += g9;} //gtp: you have =+ operator, but this does not exists in c, it is +=

	return phi;
}

int main(int argc, char const *argv[])
{
	srand(time(0));;

    double (*fObj)(int, double[], int);

    printf("Funcion 1\n");
    fObj=function;
    GWO(-100, 100, fObj);
    showPack();

	return 0;
}
