/*
    Bu program bir tam sayı dizisinde ortalamayı hesaplar
    ve ortalamaya en yakın olan elemanı ve indeksini bulur.
*/

#include <stdio.h>
#include <math.h>
#define N 9
void ortalamayaYakiniBul(int [], int*, int *, float*);
int main()
{
    int dizi[N] = {9,7,3,4,11,67,25,56,34};
    int indis, eleman;
    float ortalama;
    ortalamayaYakiniBul(dizi, &eleman, &indis, &ortalama);

    printf("-------------------------\n");
    printf("Ortalama: %.2f, ortalamaya en yakın eleman: %d, indisi: %d", ortalama, eleman, indis);
    return 0;
}
void ortalamayaYakiniBul(int dizi[], int *eleman, int *indis, float *ortalama)
{
    int i;
    float enk, toplam = 0, farklar[N];
    for(i = 0; i < N; i++)
        toplam += dizi[i];
    *ortalama = toplam / N;
    for(i = 0; i < N; i++)
        farklar[i] = fabs(dizi[i] - *ortalama);
    enk = farklar[0];
    for(i = 0; i < N; i++)
        if(farklar[i] < enk)
        {
            enk = farklar[i];
            *indis = i;
            *eleman = dizi[i];
        }
}
