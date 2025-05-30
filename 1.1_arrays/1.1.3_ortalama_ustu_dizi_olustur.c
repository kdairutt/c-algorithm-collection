#include <stdio.h>
#include <stdlib.h>

void olustur_ve_yaz(int [], int [], int *, int);
int buyukluk_bul(int, int, int, int [], int []);

int main()
{
    int n, i;
    printf("Dizilerin büyüklüğünü giriniz:");
    scanf("%d", &n);

    int dizi1[n], dizi2[n], *dizi3;

    printf("1. dizinin elemanlarını sırayla giriniz:");

    for(i = 0; i < n; i++)
        scanf("%d", &dizi1[i]);

    printf("2. dizinin elemanlarını sırayla giriniz:");

    for(i = 0; i < n; i++)
        scanf("%d", &dizi2[i]);

    olustur_ve_yaz(dizi1, dizi2, dizi3, n);

    return 0;
}

int buyukluk_bul(int m1, int m2, int n, int a[], int b[]) {
    int csayac = 0, i;
    for(i = 0; i < n; i++)
        if(a[i] >= m1 || b[i] >= m2)
            csayac++;
    return csayac;
}

void olustur_ve_yaz (int a[], int b[], int *c, int n)
{
    float top1 = 0, top2 = 0, ort1, ort2;
    int z = 0, i, csayac;

    for(i = 0; i < n; i++)
        top1 += a[i];
    ort1 = top1 / n;

    for(i = 0; i < n; i++)
        top2 += b[i];
    ort2 = top2 / n;

    csayac = buyukluk_bul(ort1, ort2, n, a, b);

    c = malloc(csayac * sizeof(int));

    for(i = 0; i < n; i++)
        if(a[i] >= ort1)
            c[z++] = a[i];

    for(i = 0; i < n; i++)
        if(b[i] >= ort2)
            c[z++] = b[i];

    printf("3. dizinin elemanları: ");
    for(i = 0; i < csayac; i++)
        printf("%d, ", c[i]);

    free(c);
}
