#include <stdio.h>
#include <stdlib.h>

#ifndef _COMMON_H
#define _COMMON_H

typedef struct {
    double fitness;
    double pos[13]; //gtp: ojo, esto lo deja fijo, por favor ocupa un *pos
} Wolf;

#endif
