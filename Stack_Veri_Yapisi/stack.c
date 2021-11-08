#include <stdio.h>
#include <stdlib.h>
#define boyut 50

void push(int i);
int pop(void );
void yazdir();
void menu();

int *enAlt, *enUst, *yigin;

int main() {
    yigin = (int*) malloc(sizeof(int));
    int secim;
    enAlt = yigin;
    enUst = yigin;

    while (1)
    {
        menu();
        printf("\nBir secim giriniz :");
        scanf("%d", &secim);
        int deger;
        switch (secim)
        {
        case 0:
            printf("Cikis yapiliyor...");
            exit(0);
            free(yigin);
            break;
        case 1:
            printf("\nYigina eklenecek degeri giriniz : ");
            scanf("%d", &deger);
            push(deger);
            break;
        case 2:
            deger = pop();
            printf("Yigindan alinan deger : %d",deger);
            break;
        case 3:
            yazdir();
            break;        
        default:
            printf("Gecersiz secim.");
            break;
        }
    }
    
    return 0;
}
void push(int i) {
    if(enUst+1 == (enAlt + boyut)) {
        printf("Yigin dolu.\n");
        exit(0);
    }
    yigin = realloc(yigin,1 * sizeof(int));
    *enUst = i;
    enUst++;
}
int pop(void) {
    if(enUst == enAlt) {
        printf("Yigin bos.\n");
        exit(0);
    }
    enUst--;
    int deger = *enUst;
    return deger;
}
void yazdir() {
    printf("\n[EN ALT]\n");
    int *temp = yigin;
    while(temp<enUst) {
        printf("%d\n", *temp);
        temp++;
    }
    printf("[EN UST]");
}
void menu() {
    printf("\n=============\nMENU\n=============\n");
    printf("1. Ekle \n 2.Cikar \n 3.Yazdir \n 0.Cikis");
}