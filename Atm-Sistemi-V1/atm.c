#include <stdio.h>
#include <string.h>
#include "atm.h"

static int bakiyeOku();
static int bakiyeKaydet(int bakiye);

void paraYatir() {
    printf("\n[PARA YATIRMA EKRANI]\n");
    
    int bakiye = bakiyeOku();
    int tutar;
    printf("Yatirilacak tutari giriniz :");
    scanf("%d",&tutar);
    
    bakiye += tutar;
    
    int a;
    if((a = bakiyeKaydet(bakiye)) == 1) {
        printf("Paraniz yatirilmistir.\n");
    } else
        printf("Para yatirma islemi basarisiz. Tekrar deneyiniz.\n");
    
}
void paraCek() {
    printf("\n[PARA CEKME EKRANI]\n");
    int cekilecekTutar;
    int bakiye = bakiyeOku();
    
    printf("\nCekmek istediginiz tutari giriniz :");
    scanf("%d",&cekilecekTutar);
    
    if(cekilecekTutar>bakiye) {
        printf("Bakiyeniz yetersiz! Lutfen tekrar deneyiniz.\n");
        return;
    } else if(cekilecekTutar > 2000) {
        printf("Tek seferlik para cekme limiti 2000TL dir.Lutfen tekrar deneyiniz.");
        return;
    }
   
    bakiye -= cekilecekTutar;
 
    int a = bakiyeKaydet(bakiye);
    
    if(a!=1) {
        printf("\nPara cekme islemi basarisiz. Lutfen tekrar deneyiniz.\n");
    } else {
        printf("\nParanizi almayi unutmayiniz.\n");
    }    
   
}

void bakiyeGor() {
    int bakiye;
    bakiye = bakiyeOku();
    printf("\nBakiyeniz %d TL dir.\n",bakiye);
  
}

void sifreDegistir() {
    printf("\n[SIFRE DEGISTIRME EKRANI]\n");
        
        char eskiPass[UZUNLUK];
        char yeniPass[UZUNLUK];
        char passOku[UZUNLUK];
        
        printf("Eski kart sifrenizi giriniz : ");
        scanf("%s",eskiPass);
        
        FILE* passPtr = NULL;
        passPtr = fopen("pass.txt","r");
        fscanf(passPtr,"%s",passOku);
        fclose(passPtr);
        
        if(strcmp(passOku,eskiPass) == 0) {
        char yeniPass[UZUNLUK];
        
        printf("Giris basarili!\n");
        
        passPtr = fopen("pass.txt","r+");
        printf("Yeni sifrenizi giriniz :");
        scanf("%s",yeniPass);
        fprintf(passPtr,"%s",yeniPass);
        
        printf("Islem basarili!\n");
        printf("Yeni sifreniz : %s\n",yeniPass);
    } 
    else
        printf("Girdiginiz kullanici adi ya da sifre hatali.\n");       
}

static int bakiyeOku() {
    int bakiye;
    
    FILE* bakiyePtr = NULL;
    bakiyePtr = fopen("bakiye.txt","r");
    fscanf(bakiyePtr,"%d",&bakiye);
    fclose(bakiyePtr);
    
    return bakiye;
}

static int bakiyeKaydet(int bakiye) {
    FILE* bakiyePtr = NULL;
    bakiyePtr = fopen("bakiye.txt","r+");
    fprintf(bakiyePtr,"%d",bakiye);
    fclose(bakiyePtr);
    
    return 1;
}