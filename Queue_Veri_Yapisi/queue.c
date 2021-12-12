#include <stdio.h>
#include <stdlib.h>
#define boyut 50

void insert(int );
int _remove();
void list();
void menu();

int *bas,*son,*kuyruk;

int main() {
    kuyruk = (int*) malloc(sizeof(int));
    bas = kuyruk;
    son = kuyruk;
    while (1)
    {
        int secim;
        menu();
        printf("\nYapmak istediginiz islemi seciniz :");
        scanf("%d", &secim);
        int deger;
        switch (secim)
        {
        case 1:
            printf("Kuyruga eklenecek degeri giriniz :");
            scanf("%d",&deger);
            insert(deger);
            break;
        case 2:
            deger = _remove();
            printf("Cikarilan deger %d",deger);
            break;
        case 3:
            list();
            break;
        case 0:
            printf("\nCikis yapiliyor...");
            free(kuyruk);
            exit(0);       
        default:
            printf("Gecerli bir deger giriniz!");
            break;
        }
    }
    return 0;
}
void insert(int deger) {
    if(son == (bas + boyut)) {
        printf("\nYigin dolu, ekleme yapilamaz.\n");
        exit(0);
    }
    kuyruk = realloc(kuyruk,sizeof(int));
    *son = deger;
    son++;
}
int _remove(){
    if(son == bas) {
        printf("\nYigin bos, cikarma yapilamaz.\n");
        exit(0);
    }
    int deger = *bas;
    bas++;
    return deger;
}
void list(){
    int *temp = bas;
    while(temp<son) {
        printf("%d\n", *temp);
        temp++;
    }
}
void menu() {
    printf("\n=============\nMENU\n=============\n");
    printf("1. Ekle \n 2.Cikar \n 3.Yazdir \n 0.Cikis");
}