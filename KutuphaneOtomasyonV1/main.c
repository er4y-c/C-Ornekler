#include <stdio.h>
#include <stdlib.h>
#include "kutuphane.h"

void menuYazdir();

int main(int argc, char** argv) {
    printf("--------------------------------------\n");
    printf("KUTUPHANE OTOMASYON SISTEMI\n");
    printf("--------------------------------------\n");
    
    int secim;
    menuYazdir();
    scanf("%d",&secim);
    
    while(1) {
    switch(secim) {
        case 0:
            printf("Cikis Yapiliyor...\n");
            exit(0);
            break;
        case 1:
            kitapEkle();
            break;
        case 2:
            kitapSil();
            break;
        case 3:
            uyeEkle();
            break;
        case 4:
            uyeSil();
            break;
        case 5:
            uyeListele();
            break;
        case 6:
            kitapListele();
            break;
        default:
            printf("Lutfen gecerli bir islem seciniz!\n");
            menuYazdir();
            scanf("%s",&secim);
            break;
    }
    
   }
    
    return (EXIT_SUCCESS);
}
void menuYazdir() {
    printf("\nYapmak Istediginiz Islemi Seciniz :\n");
    printf("1. Kitap Ekle\n");
    printf("2. Kitap Sil\n");
    printf("3. Uye Ekle\n");
    printf("4. Uye Sil\n");
    printf("5. Uyeleri Listele\n");
    printf("6. Kitaplari Listele\n");
    printf("0. Cikis Yap\n");
    printf("Seciminizi Giriniz : ");
}

