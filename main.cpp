#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define OgrenciSayisi 20

/**KAC OGRENCI ICIN DONECEGINI YUKARIDAN AYARLAYABILIYORUZ*/

/**STRUCT YAPIMIZ*/
struct Ogrenci
{
    int sinavNotu;
    char ad[20];
    char soyad[20];
};
/**STRUCT OGRENCI TIPIMIZDE OGRENCILER ADLI DIZI OLUSTURDUK*/
struct Ogrenci ogrenciler[OgrenciSayisi];

/**EN AZ OLAN KISININ NOTUNU BULMAK ICIN*/
void minimumuBul()
{
    int i = 0;
    struct Ogrenci minimum;

    /**EN KUCUK SINAV NOTUNU BULMAK ICIN
       KULLANDIGIM ALGORITMA*/
    minimum = ogrenciler[0];

    for(i = 1 ; i < OgrenciSayisi ; i++)
    {
        if(minimum.sinavNotu < ogrenciler[i].sinavNotu)
        {
            continue;
        }
        else
        {
            minimum = ogrenciler[i];
        }
    }

    /**EKRANA YAZDIRMA KISMI*/
    printf("\nEn az notu alan ogrenci : %s %s",minimum.ad,minimum.soyad);
    printf("\nNotu                    : %d",minimum.sinavNotu);
    printf("\n\n");
}

void ogrencileriGir()
{
    int i = 0;

    /**OGRENCILERIMIZI EKLIYORUZ*/
    for( i = 0; i < OgrenciSayisi ; i++)
    {
        printf("%d. Ogrencinin adini soyadini giriniz : ",i+1);
        scanf("%s %s",ogrenciler[i].ad,ogrenciler[i].soyad);
        printf("%d. Ogrencinin Notunu giriniz : ",i+1);
        scanf("%d",&ogrenciler[i].sinavNotu);
        printf("\n\n");
    }

    /**PROGRAMIN OKUNABILIR OLMASI ACISINDAN EKRANI SILDIM*/
    system("CLS");
}

void ogrencileriListele()
{
    int i = 0;

    /**OGRENCILERIN LISTESINI YAZDIRIYORUZ*/
    for( i = 0; i < OgrenciSayisi ; i++)
    {
        printf("%d. Ogrencinin "
               "\tAdi : %s "
               "\tSoyadi : %s  "
               "\tSinav Notu : %d "
               ,i+1,ogrenciler[i].ad,ogrenciler[i].soyad,ogrenciler[i].sinavNotu);
        printf("\n");
    }
}


int main()
{
    ogrencileriGir();
    ogrencileriListele();
    minimumuBul();

    return 0;
}
