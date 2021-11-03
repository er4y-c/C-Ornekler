#ifndef KUTUPHANE_H
#define KUTUPHANE_H

#define AD_UZUNLUK 50
#define UZUNLUK 12

typedef struct kitaplar {
    char kitapAdi[AD_UZUNLUK];
    char yazarAdi[AD_UZUNLUK];
    char yayinAdi[AD_UZUNLUK];
    int basimYili;
}Kitap;

typedef struct uyeler {
    char uyeAdi[AD_UZUNLUK];
    char tc[UZUNLUK];
    char kayitTarih[UZUNLUK];
}Uye;


extern Kitap kitapList[];
extern int kitapSayisi;

extern Uye uyeList[];
extern int uyeSayisi;


void kitapEkle();
void kitapSil();
void uyeEkle();
void uyeSil();
void uyeListele();
void kitapListele();

#endif

