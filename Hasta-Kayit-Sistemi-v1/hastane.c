#include <stdio.h>
#include <string.h>
#include "hastane.h"

static void hastaOku(char[],char[],char[],char[],char[]);

void hastaKayit() {
    printf("\n\n\n");
    printf("-------[HASTA KAYIT EKRANI]-------\n");
    
    char ad[AD],soyad[AD],tcNo[12],dogumTarihi[12],doktor[AD];
    
    hastaOku(ad,soyad,tcNo,dogumTarihi,doktor);
    char dosyaAdi[AD];
    char uzanti[5] = ".txt";
    
    strcpy(dosyaAdi,tcNo);
    strcat(dosyaAdi,uzanti);
    
    FILE* filePtr = NULL;
    filePtr = fopen(dosyaAdi,"w");
    if(filePtr==NULL) {
        printf("Kayit Olusturulamadi!\n");
    }
    
    fprintf(filePtr,"%s\n%s\n%s\n%s\n%s\n",ad,soyad,tcNo,dogumTarihi,doktor);
    printf("Kayit Basariyla Olusturulmustur.\n");
    fclose(filePtr);
    
    return;
}

void hastaSil() {
    printf("\n\n\n");
    printf("-------[KAYIT SILME EKRANI]-------\n");
    
    char tc[20];
    char uzanti[5] = ".txt";
    printf("Kaydi silinecek hastanin Tc sini giriniz :");
    scanf("%s",tc);
    strcat(tc,uzanti);

    FILE* filePtr = NULL;
    filePtr = fopen(tc,"r");
    if(filePtr==NULL) {
        printf("Kayit Bulunamadi!\n");
        return;
    }
    
    fclose(filePtr);
    if(remove(tc)==0) {
        printf("Kayit Basariyla Silindi.\n");
        return;
    } else
        printf("Kayit Bulunamadi!\n");
    return;
}

void hastaGuncelle() {
    char yAd[AD],ySoyad[AD],yTcNo[12],yDogumTarihi[12],yDoktor[AD];
    char tc[12];
    char uzanti[5] = ".txt";
    printf("Kaydi guncellenecek hastanin Tc sini giriniz :");
    scanf("%s",tc);
    strcat(tc,uzanti);
    
    FILE* filePtr = NULL;
    filePtr = fopen(tc,"w");
    if(filePtr==NULL) {
        printf("Kayit Bulunamadi!\n");
        return;
    }
    hastaOku(yAd,ySoyad,yTcNo,yDogumTarihi,yDoktor);
    fprintf(filePtr,"%s\n%s\n%s\n%s\n%s\n",yAd,ySoyad,yTcNo,yDogumTarihi,yDoktor);
    printf("\nKayit basariyla guncellenmistir.\n");
 
    fclose(filePtr);
}

void hastaSorgu() {
    char ad[AD],soyad[AD],tcNo[12],dogumTarihi[12],doktor[AD];
    char tc[12];
    char uzanti[5] = ".txt";
    
    printf("Kaydi goruntulenecek hastanin Tc sini giriniz : ");
    scanf("%s",tc);
    strcat(tc,uzanti);
    
    FILE* filePtr = NULL;
    filePtr = fopen(tc,"r");
    if(filePtr==NULL) {
        printf("Kayit Bulunamadi!\n");
        return;
    }
    fscanf(filePtr,"%s\n%s\n%s\n%s\n%s\n",ad,soyad,tcNo,dogumTarihi,doktor);
    fclose(filePtr);
    
    printf("\n\n");
    printf("Hastanin Adi : %s\n",ad);
    printf("Hastanin Soyadi : %s\n",soyad);
    printf("Hasta TC : %s\n",tcNo);
    printf("Dogum Tarihi : %s\n",dogumTarihi);
    printf("Muayene Oldugu Doktor : %s\n",doktor);
    
}

static void hastaOku(char ad[AD],char soyad[AD],char tcNo[12],char dogumTarihi[12],char doktorAd[AD]) {
    char doktor1[AD] = "Eray Aynaci";
    char doktor2[AD] = "Cabbar Yanbasan";
    
    printf("Hastanin adini giriniz : ");
    scanf("%s",ad);
    printf("Hastanin soyadini giriniz : ");
    scanf("%s",soyad);
    printf("Hastanin TC sini giriniz : ");
    scanf("%s",tcNo);
    
    while(strlen(tcNo)!= 11) {
        printf("Hasta TC si 11 haneli olmalidir!\n");
        printf("Hastanin TC sini giriniz : ");
        scanf("%s",tcNo);
    }
    
    printf("Hastanin dogum tarihini giriniz (gg.aa.yyyy) :");
    scanf("%s",dogumTarihi);
    
    char secim2;
    printf("\n-----[DOKTOR LISTESI]-----\n");
    printf("--->(1) %s\n",doktor1);
    printf("--->(2) %s\n",doktor2);
    printf("Kayit yaptirilacak doktorun kodunu giriniz :");
    scanf("%s",&secim2);
 
    switch(secim2) {
        case '1':
            strcpy(doktorAd,doktor1);
            break;
        case '2':
            strcpy(doktorAd,doktor2);
            break;
        default:
            printf("Lutfen Gecerli Bir Kod Giriniz!");
            break;
    }
}
