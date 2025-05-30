#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int n, i, tur, yedek, sayac1 = 0, sayac2 = 0, z;
    float ceyreklerArasiOrt, ceyreklerArasiAdet = 0, buyukler = 0, kucukler = 0, toplam = 0;
    printf("Eleman sayısını giriniz (1 - 500):");
    scanf("%d", &n);

    int dizi[n];

    for(i = 0; i < n; i++)
    {
        printf("Dizinin %d. elemanını giriniz:", i + 1);
        scanf("%d", &dizi[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(tur = 0; tur < n - 1; tur++)
        {
            if(dizi[tur] > dizi[tur + 1])
            {
                yedek = dizi[tur];
                dizi[tur] = dizi[tur + 1];
                dizi[tur + 1] = yedek;
            }
        }
    }
    printf("Dizinin sıralanmış hali: ");
    
    for(i = 0; i < n; i++)
    {
        printf("%d, ", dizi[i]);
    }
    printf("\n");
    for(i = 0; i < n / 4; i++)
    {
        kucukler += dizi[i];
        sayac1++;
    }
    i = n - 1;
    for(z = 0; z < n / 4; z++)
    {
        buyukler += dizi[i];
        sayac2++;
        i--;
    }

    for(i = 0; i < n; i++)
    {
        toplam += dizi[i];
    }
    ceyreklerArasiAdet = n - n / 2;
    ceyreklerArasiOrt = (toplam - (kucukler + buyukler)) / ceyreklerArasiAdet;
    printf("Dizinin çeyrekler arası ortalaması: %.1f", ceyreklerArasiOrt);

    return 0;
}


