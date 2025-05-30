/*
Bu program klasik "lamba problemi"ni çözer.
    1'den 50'ye kadar numaralanmış lambalar başlangıçta kapalıdır.
    10 araba sırayla geçer, her araba numarasıyla tam bölünebilen lambaların durumunu değiştirir.
    Sonuçta hangi lambaların yanık ve sönük olduğunu listeler.
*/
#include <stdio.h>
int main()
{
    int lambalar[51] = {0};
    int i, arabalar;
    for(arabalar = 1; arabalar <= 10; arabalar++)
    {
        for(i = 1; i < 51; i++)
        {
            if(i % arabalar == 0)
            {
                if(lambalar[i] == 0)
                    lambalar[i] = 1;
                else
                    lambalar[i] = 0;
            }
        }
    }

    printf("Yanık lambalar: ");
    for(i = 1; i < 51; i++)
        if(lambalar[i] == 1)
            printf("%d ", i);

    printf("\nSönük lambalar: ");
    for(i = 1; i < 51; i++)
        if(lambalar[i] == 0)
            printf("%d ", i);

    return 0;
}
