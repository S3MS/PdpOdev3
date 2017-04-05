#ifndef RANDOM_H
#define RANDOM_H

#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include <inttypes.h>
#include <math.h>


struct RANDOM{
	int (*SayiUret)(int,int);
	void (*Yoket)(struct RANDOM*);	
};
typedef struct RANDOM* Random;  

Random RandomOlustur();
int _SayiUret(int,int);
void _Yoket(Random);

#endif
