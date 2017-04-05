#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H
#include "Random.h"

#define MAX 250

struct RASTGELEKARAKTER
{
	Random super;
	char KarakterDizisi[52];
	char karakterler[MAX];
	char Dizi[MAX];
	char (*KarakterUret)(struct RASTGELEKARAKTER*);
	char* (*KarakterDizisiUret)(struct RASTGELEKARAKTER*,int);
	char* (*VerilenIkiKarakter)(struct RASTGELEKARAKTER*,char,char,int);
	char* (*BelirtilenKarakterler)(struct RASTGELEKARAKTER*,char*,int);
	void (*YoketRastgele)(struct RASTGELEKARAKTER*);
};
typedef struct RASTGELEKARAKTER* RastgeleKarakter;

RastgeleKarakter RastgeleOlustur();
char _KarakterUret(const RastgeleKarakter);
char* _KarakterDizisiUret(const RastgeleKarakter,int);
char* _VerilenIkiKarakter(const RastgeleKarakter,char,char,int);
char* _BelirtilenKarakterler(const RastgeleKarakter,char*,int);
void _YoketRastgele(RastgeleKarakter);

#endif
