#include "RastgeleKarakter.h"

void Ekrana_Yazdir(Random,char*);
void Yazi_Tipi(int*,int*);
void Ayarlar(int*,int*,int*);
void Yazi_Rengi(int*);

int main()
{
	
	RastgeleKarakter rnd =RastgeleOlustur();
	Random rastgeleSayi=RandomOlustur();

	int adet=0,secim;
	int nitelik1=0,nitelik2=0,nitelik3=34;

	char baslangic,bitis;
	char karakterler[100];
	
		

	while(1)
	{
		
		system("clear");
		
		printf("\033[%d;34m",nitelik1);
		printf("\033[%d;%dm",nitelik2,nitelik3);

		printf("\n 1-Rastgele Karakter Uret");
		printf("\n 2-Rastgele Karakter Dizisi Uret");
		printf("\n 3-Iki Karakter Arasinda Rastgele Uret");
		printf("\n 4-Belirtilen Karakterlerde Rastgele Uret");
		printf("\n 5-Ayarlar");
		printf("\n 6-Cikis");
		printf("\n\n Seciminiz :");
		scanf(" %d",&secim);

		switch(secim)
		{
			case 1:
				printf("\n Rastgele Karakter :");
				Ekrana_Yazdir(rastgeleSayi,rnd->KarakterDizisiUret(rnd,1));
				getchar();
				getchar();
				break;
			case 2:
				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");
				scanf(" %d",&adet);
			
				printf("\n Rastgele Karakter Dizisi :");
				Ekrana_Yazdir(rastgeleSayi,rnd->KarakterDizisiUret(rnd,adet));
				getchar();
				getchar();
				break;
			case 3:
				
				printf(" Baslangic Karakteri Giriniz : ");
				scanf(" %c",&baslangic);		

				printf(" Bitis Karakteri Giriniz : ");
				scanf(" %c",&bitis);

				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");
				scanf(" %d",&adet);

				printf("\n Verilen Iki Karakter Arasi :");
				Ekrana_Yazdir(rastgeleSayi,rnd->VerilenIkiKarakter(rnd,baslangic,bitis,adet));
				getchar();
				getchar();
				break;
			case 4:
				printf(" Lutfen Belirtilen Karakterleri Giriniz :");
				scanf(" %s",karakterler);		

				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");
				scanf(" %d",&adet);
	
				printf("\n Belirtilen Rastgele Karakterler :");
				Ekrana_Yazdir(rastgeleSayi,rnd->BelirtilenKarakterler(rnd,karakterler,adet));
				getchar();
				getchar();
				break;
			case 5:
				Ayarlar(&nitelik1,&nitelik2,&nitelik3);
				break;
			case 6:
				rnd->YoketRastgele(rnd);
				return 0;
				break;
			default:
				printf("\nHatali Giris!");
				getchar();
				getchar();
				break;
		}
	}

}

void Ekrana_Yazdir(Random rastgele,char* yazilacak)
{
	int boyut=0;

		
	for(int i=0;i<yazilacak[i]!=NULL;i++)
	boyut++;


	for(int i=0;i<boyut;i++)
	{
		printf("\033[1;%dm",rastgele->SayiUret(31,37));
		printf("%c",yazilacak[i]);
		
	}
	
	
	printf("\033[0;34m"); //Eski Renk...

	
}
void Yazi_Tipi(int* nitelik1,int* nitelik2)
{	
	int secim;	
	
	system("clear");

	printf("\n 1-Kalin");
	printf("\n 2-Italic");
	printf("\n 3 Kalin+Italic");
	printf("\n 4-Duz");
	
	printf("\n\n Seciminiz:");
	scanf(" %d",&secim);

	switch(secim)
	{
		case 1:
			*nitelik1=0;
			*nitelik2=1;
			break;
		case 2:
			*nitelik1=0;
			*nitelik2=3;
			break;
		case 3:
			*nitelik1=1;
			*nitelik2=3;
			break;
		case 4:
			*nitelik1=0;
			*nitelik2=0;
			break;
		default:
			return;
			break;
			
	}
	
}

void Ayarlar(int* nitelik1,int* nitelik2,int* nitelik3)
{
	int secim;	
	
	system("clear");

	printf("\n 1-Yazi Tipi");
	printf("\n 2-Yazi Rengi");
	printf("\n 3-Sifirla");
	
	printf("\n\n Seciminiz:");
	scanf(" %d",&secim);

	switch(secim)
	{
		case 1:
			Yazi_Tipi(nitelik1,nitelik2);
			break;
		case 2:
			Yazi_Rengi(nitelik3);
			break;
		case 3:
			*nitelik1=0;
			*nitelik2=0;
			*nitelik3=34;
			break;
	
		default:
			return;
			break;
			
	}
	
}

void Yazi_Rengi(int* nitelik)
{
	int secim;	
	
	system("clear");

	printf("\n 1-Kirmizi");
	printf("\n 2-Yesil");
	printf("\n 3-Kahverengi");
	printf("\n 4-Mavi");
	printf("\n 5-Magenda");
	printf("\n 6-Cyan");
	printf("\n 7-Acik Gri");
	
	printf("\n\n Seciminiz:");
	scanf(" %d",&secim);
	
	if(secim>=1 && secim<=7)
		*nitelik=30+secim;
}








