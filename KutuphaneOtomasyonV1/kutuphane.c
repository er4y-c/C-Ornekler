#include <stdio.h>
#include "kutuphane.h"

static void kullanicidanKitapOku(Kitap* kitapPtr);
static void kitapYazdir(Kitap* kitapPtr);
static void kullanicidanUyeOku(Uye* uyePtr);
static void uyeYazdir(Uye* uyePtr); 

int kitapSayisi = 0;
int uyeSayisi = 0;

void kitapEkle() {
    Kitap* kitapPtr;
    kullanicidanKitapOku(kitapPtr);
    kitapSayisi++;
}

void kitapSil() {
    Kitap* kitapPtr;
    
    if(kitapSayisi == 0) {
        printf("Silinecek kitap bulunmamaktadir!\n");
        return;
    }
    
    int silinecekID;
    kitapListele();    
    
    printf("Silinecek kitabin ID'sini giriniz : ");
    scanf("%d",&silinecekID);
    
    while(silinecekID < 1 || silinecekID > kitapSayisi) {
        printf("\nGirdiginiz ID gecersizdir!\n");
        printf("Silenecek kitabin ID'sini giriniz :");
        scanf("%d", &silinecekID);
    }
    
    kitapPtr = &kitapList[silinecekID - 1];
    *kitapPtr = kitapList[kitapSayisi - 1];
    kitapSayisi--;
    
    printf("\nKitap kaydi basariyla silinmistir!\n");
}

void uyeEkle() {
    Uye* uyePtr;
    kullanicidanUyeOku(uyePtr);
    uyeSayisi++;
}

void uyeSil() {
    Uye* uyePtr;
    if(uyeSayisi == 0) {
        printf("Silinecek uye bulunmamaktadir!\n");
        return;
    }
    
    int silinecekId;
    uyeListele();
  
    printf("Silmek istediginiz uyenin ID'sini giriniz : ");
    scanf("%d",&silinecekId);
    
    while(silinecekId < 0 || silinecekId > uyeSayisi) {
        printf("Girdiginiz ID gecersizdir!\n");
        printf("Silmek istediginiz uyenin ID'sini giriniz : ");
        scanf("%d",&silinecekId);
    }
    uyePtr = &uyeList[silinecekId - 1];
    *uyePtr = uyeList[uyeSayisi - 1];
    uyeSayisi--;
    
    printf("Uye kaydi basariyla silinmistir.\n");
}

void uyeListele() {
    Uye* uyePtr;
    uyePtr = uyeList;
    
    int i = 0;
    while(i<uyeSayisi) {
        uyeYazdir(uyePtr);
        uyePtr++;
        i++;
    }
    printf("\n");
}

void kitapListele() {
    Kitap* kitapPtr;
    kitapPtr = kitapList;
    
    int i = 0;
    while(i<kitapSayisi) {
        kitapYazdir(kitapPtr);
        kitapPtr++;
        i++;
    }
    printf("\n");
}

static void kullanicidanKitapOku(Kitap* kitapPtr) {
    printf("\n[KITAP EKLEME]\n");
    
    printf("\nKitabin adini giriniz : ");
    gets(kitapPtr->kitapAdi);
    
    printf("Yazarin adini soyadini giriniz : ");
    gets(kitapPtr->yazarAdi);
    
    printf("Yayin evinin adini giriniz : ");
    gets(kitapPtr->yayinAdi);
    
    printf("Kitabin basim yilini giriniz : ");
    scanf("%d",(kitapPtr->basimYili));
    
}

static void kitapYazdir(Kitap* kitapPtr) {
    int kitapId = (kitapPtr - kitapList) + 1;
    
    printf("\nKitap ID : %d\n",kitapId);
    printf("Kitabin Adi : %s\n",kitapPtr->kitapAdi);
    printf("Kitabin Yazari : %s\n",kitapPtr->yazarAdi);
    printf("Yayinevi : %s\n",kitapPtr->yayinAdi);
    printf("Basim Yili : %d\n",kitapPtr->basimYili);
    printf("\n");
}

static void kullanicidanUyeOku(Uye* uyePtr) {
    printf("\n[UYE EKLEME]\n");
    
    printf("Uyenin adini soyadini giriniz : ");
    gets(uyePtr->uyeAdi);
    
    printf("TC kimlik numarasini giriniz : ");
    scanf("%s",uyePtr->tc);
    
    printf("Kayit tarihini giriniz (gg.aa.yyyy) :");
    scanf("%s",uyePtr->kayitTarih); 
    
}

static void uyeYazdir(Uye* uyePtr) {
    int uyeId = (uyePtr - uyeList) + 1;
    
    printf("\nUye ID : %d\n",uyeId);
    printf("Uye Adi : %s\n",uyePtr->uyeAdi);
    printf("Uye TC Numarasi : %s\n",uyePtr->tc);
    printf("Uyelik tarihi :% s\n",uyePtr->kayitTarih);
    
}