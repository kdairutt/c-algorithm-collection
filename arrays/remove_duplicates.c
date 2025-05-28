/*
    Dizideki tekrar eden elemanları bulan ve hem kendisini
    hem tekrar eden eşini -1 ile değiştiren program.
    Örnek: {1, 120, 4, 6, 6, 6, 120} → {1, -1, 4, -1, -1, -1, -1}
    Yazan: Kadir İpek
*/

#include <stdio.h>
#define N 9

void eleme(int []);

int main()
{
    int dizi[N] = {1,120,4,6,6,6,6,6,120};
    int i;

    printf("Dizinin ilk hali: ");
    for(i = 0; i < N; i++)
    {
        printf("%d ", dizi[i]);
    }

    eleme(dizi);

    printf("\n");

    printf("Dizinin yeni hali: ");
    for(i = 0; i < N; i++)
    {
        printf("%d ", dizi[i]);
    }

    return 0;
}

void eleme(int dizi[N])
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j <= N-1; j++)
        {
            if(i == j)
                j++;
            
            if(dizi[i] == dizi[j])
            {
                dizi[i] = -1;
                dizi[j] = -1;
            }
        }
    }

}