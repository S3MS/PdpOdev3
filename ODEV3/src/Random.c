#include "Random.h"

Random RandomOlustur()
{
	Random this;
	this = (Random)malloc(sizeof(struct RANDOM));
	this->SayiUret=&_SayiUret;
	this->Yoket=&_Yoket;

	return this;
}
int _SayiUret(int baslangic,int son)
{
	
	struct timespec spec;

  	clock_gettime(CLOCK_REALTIME,&spec);

    return (int)(spec.tv_nsec%(son-baslangic)+baslangic);
}
void _Yoket(Random rnd)
{
	if(rnd==NULL)return;
	free(rnd);
	rnd=NULL;
}



