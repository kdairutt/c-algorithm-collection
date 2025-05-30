/*
    Bu program, bir apartmanda 10 dairenin yakıt giderlerini karşılaştırır.
    En yüksek yakıt giderine sahip daireyi bulur ve komşusu ile arasındaki farkı hesaplar.
*/

#include <stdio.h>
#include <math.h>
#define N 10

void enCokYakitveKomsuBul(float [], float *, int *);

int main()
{
    float yakitGiderleri[N] = {350.04, 351, 450.50, 90.2, 180, 162, 382, 349, 761.50, 452.50};
    int daireNo, i;
    float fark;
    printf("Dairelerin yakıt giderleri: ");
    for(i = 0; i < N; i++)
    {
        printf("%d. daire: %.2f\n", i + 1, yakitGiderleri[i]);
    }
    printf("\n");
    enCokYakitveKomsuBul(yakitGiderleri, &fark, &daireNo);
    printf("En çok yakıt gideri %d numara\n", daireNo);
    printf("Komşusu ile arasındaki fark: %.2f", fark);
    return 0;
}

void enCokYakitveKomsuBul(float yakitGiderleri[], float *fark, int *daireNo)
{
    int i;
    float enb = yakitGiderleri[0];
    for(i = 0; i < N; i++)
        if(yakitGiderleri[i] > enb)
        {
            enb = yakitGiderleri[i];
            *daireNo = i + 1;
            if(i % 2 == 1)
                *fark = fabs(yakitGiderleri[i] - yakitGiderleri[i - 1]);

            if(i % 2 == 0)
                *fark = fabs(yakitGiderleri[i] - yakitGiderleri[i + 1]);
        }
}
