/*
Bu program, kullanıcıdan alınan iki tam sayının EBOB (en büyük ortak bölen) ve
    EKOK (en küçük ortak kat) değerlerini bulur. Negatif girişleri mutlak değere
    çevirir ve aralarında asal olup olmadığını kontrol eder.
*/

#include <stdio.h>
#include <stdlib.h>

struct Sayilar {
    int sayi1;
    int sayi2;
    int ebob;
    int ekok;
};
typedef struct Sayilar sayi;

int ebob_bul(int, int);
int ekok_bul(int, int);
void yer_degistir(int *, int *);

int main () 
{
    sayi a;
    while (1) {
        printf("Sayılarınızı sırasıyla giriniz (Çıkmak için iki sayıyı da 0 giriniz): ");
        scanf("%d%d", &a.sayi1, &a.sayi2);
        if (!a.sayi1 || !a.sayi2) {
            printf("Program başarıyla sonlandırıldı.");
            return 0;
        }
        a.ebob = ebob_bul(abs(a.sayi1), abs(a.sayi2));
        a.ekok = ekok_bul(abs(a.sayi1), abs(a.sayi2));
        if (a.ebob == 1)
            printf("%d ve %d tam sayıları, aralarında asal sayılardır.\n", abs(a.sayi1), abs(a.sayi2));
        printf("EBOB(%d, %d): %d\n", abs(a.sayi1), abs(a.sayi2), a.ebob);
        printf("EKOK(%d, %d): %d\n", abs(a.sayi1), abs(a.sayi2), a.ekok);
    }
}

void yer_degistir(int *x, int *y) { // ilk girilen sayının büyük olmadığı durumlar için
    if (*x < *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}

int ebob_bul(int x, int y) {
    yer_degistir(&x, &y);
    int i = 1, z, ebob = 1;
    while(i < x) {
        for(z = i; z >= 1; z--) {
            if(x % i == 0 && y % i == 0) {
                ebob *= i;
                x /= i;
                y /= i;
            }
        }
        i++;
    }
    return ebob;
}

int ekok_bul(int x, int y) {
    return x / ebob_bul(x, y) * y;
}
