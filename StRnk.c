#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StRnk.h"
#include "RngStream.h"
#include "ConsFunctions.h"
#include "common.h"


void stRank(Wolf *pack, int SA, RngStream g1){

	double Pf = 0.45;

	int i = 0;
	for (i = 0; i < SA; ++i){
		int band = 0;
		int j = 0;

		int tam = sizeof(pack[i].pos)/sizeof(pack[i].pos[0]);
		double hlp[tam];

		for (j = 0; j < SA; ++j){
			double u = RngStream_RandU01(g1);

			if (getPhi(pack[j].pos)==getPhi(pack[j+1].pos) || u < Pf){

				if (pack[j].fitness > pack[j+1].fitness){
					memcpy(hlp, pack[j].pos, sizeof(hlp));
					memcpy(pack[j].pos, pack[j+1].pos, sizeof(pack[j].pos));
					memcpy(pack[j+1].pos, hlp, sizeof(pack[j+1].pos));
					band = 1;
				}

			}
			else{
				if (pack[j].fitness > pack[j+1].fitness){
					memcpy(hlp, pack[j].pos, sizeof(hlp));
					memcpy(pack[j].pos, pack[j+1].pos, sizeof(pack[j].pos));
					memcpy(pack[j+1].pos, hlp, sizeof(pack[j+1].pos));
					band = 1;
				}

			}
		}
		if (band == 1){
			break;
		}
	}
}
