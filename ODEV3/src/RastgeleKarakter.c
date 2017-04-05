#include "RastgeleKarakter.h"

RastgeleKarakter RastgeleOlustur()
{
	RastgeleKarakter this;
	this=(RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));
	this->super=RandomOlustur();
	this->KarakterUret=&_KarakterUret;
	this->KarakterDizisiUret=&_KarakterDizisiUret;
	this->VerilenIkiKarakter=&_VerilenIkiKarakter;
	this->BelirtilenKarakterler=&_BelirtilenKarakterler;
	this->YoketRastgele=&_YoketRastgele;
	
	int indis = 0;
        //a-z arasi harfler diziye ataniyor..
        for (char krt = 'a'; krt <= 'z'; krt++) {
            this->KarakterDizisi[indis++] = krt;
        }

        //A-Z arasi harfler diziye ataniyor..
        for (char krt = 'A'; krt <= 'Z'; krt++) {
            this->KarakterDizisi[indis++] = krt;
        }
	
	return this;
}
char _KarakterUret(const RastgeleKarakter rastgele)
{
	int rastgeleindis=rastgele->super->SayiUret(0,52);
	
	return 	rastgele->KarakterDizisi[rastgeleindis];
}

char* _KarakterDizisiUret(const RastgeleKarakter rastgele,int adet)
{	
	if(adet>MAX)
	adet=MAX-2;

	for(int i=0;i<adet;i++)
	{
		rastgele->karakterler[i]=rastgele->KarakterUret(rastgele);
		rastgele->karakterler[i+1]='\0';
	}
	return rastgele->karakterler;
	
}
char* _VerilenIkiKarakter(const RastgeleKarakter rastgele,char karakter1,char karakter2,int adet)
{
	char temp;
	int rastgeleindis;
	int indis=0;

	if(karakter2<karakter1)
	{
		temp=karakter1;
		karakter1=karakter2;
		karakter2=temp;
	}
	

	for(char krt=karakter1;krt<=karakter2;krt++)
	rastgele->Dizi[indis++]=krt;

	for(int i=0;i<adet;i++)
	{
		rastgeleindis=rastgele->super->SayiUret(0,indis);
		rastgele->karakterler[i]=rastgele->Dizi[rastgeleindis];
		rastgele->karakterler[i+1]='\0';
	}
	
	return rastgele->karakterler;

}

char* _BelirtilenKarakterler(const RastgeleKarakter rastgele,char* gonderilen,int adet)
{
	int rastgeleindis=0;
	int boyut=0;

	for(int i=0;i<gonderilen[i]!='\0';i++)
	boyut++;	

	for(int i=0;i<adet;i++)
	{
		rastgeleindis=rastgele->super->SayiUret(0,boyut);
		rastgele->karakterler[i]=gonderilen[rastgeleindis];
		rastgele->karakterler[i+1]='\0';
	}

	return rastgele->karakterler;
}

void _YoketRastgele(RastgeleKarakter rastgele)
{
	if(rastgele==NULL) return;
	if(rastgele->super!=NULL)
	rastgele->super->Yoket(rastgele->super); 
	free(rastgele);
	rastgele=NULL;
}







