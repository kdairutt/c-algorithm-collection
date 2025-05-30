/*
Girilen string'i yerinde tersine çeviren C programı.
Örnek: "ridak" → "kadir"
Yazan: Kadir İpek
*/

#include <stdio.h>
#include <string.h>
void tersCevir(char *dizgi) {
    char *bas, *son, temp;
    int uzunluk;
    uzunluk = strlen(dizgi);
    bas = dizgi;
    son = bas + uzunluk - 1;
    while (bas < son) {
        temp = *bas;
        *bas = *son;
        *son = temp;
        bas++;
        son--;
    }
}

int main()
{
    char metin[] = "ridak";
    tersCevir(metin);
    printf("Dizginin çevirilmiş hali: %s\n", metin);
    return 0;
}
