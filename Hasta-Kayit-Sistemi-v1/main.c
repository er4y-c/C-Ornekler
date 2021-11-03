#include <stdio.h>
#include <stdlib.h>
#include "hastane.h"

void menuYazdir();

int main(int argc, char** argv) {
    printf("-----------------------------\n");
    printf("-----[HASTA KAYIT SISTEMI]-----\n");
    printf("-----------------------------\n");
    printf("\n\n\n");
    
    char secim;
    while(1) {
    menuYazdir();
    scanf("%c",&secim);
    
    switch(secim) {
        case '1':
            hastaKayit();
            break;
        case '2':
            hastaSil();
            break;
        case '3':
            hastaGuncelle();
            break;
        case '4':
            hastaSorgu();
            break;
        case '0':
            printf("Cikis Yapiliyor...\n");
            exit(0);
          default:
            printf("\nLutfen Gecerli Bir Islem Seciniz...\n");
            break;
        
    }
  }
    return (EXIT_SUCCESS);
}
void menuYazdir() {
    printf("\n------[ANA MENU]-------\n");
    printf("1. Hasta Kayit\n");
    printf("2. Hasta Silme\n");
    printf("3. Hasta Guncelleme\n");
    printf("4. Hasta Sorgulama\n");
    printf("0. Cikis\n");
    printf("\nYapmak Istediginiz Islemi Seciniz :");
}
