// bu program, basit bir stack yapısı oluşturan kodları içerir.

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int veri) {
    if (top == MAX - 1) {
        printf("Stack dolu! Eleman eklenemedi.\n");
        return;
    }
    top++;
    stack[top] = veri;
    printf("%d stack'e eklendi.\n", veri);
}

int pop() {
    if (top == -1) {
        printf("Stack boş! Eleman çıkarılamaz.\n");
        return -1;
    }
    int silinen = stack[top];
    top--;
    printf("%d stack'ten çıkarıldı.\n", silinen);
    return silinen;
}


int peek() {
    if (top == -1) {
        printf("Stack boş!\n");
        return -1;
    }
    return stack[top];
}

void yazdir() {
    if (top == -1) {
        printf("Stack boş, gösterilecek eleman yok.\n");
        return;
    }
    printf("Stack içeriği (top -> bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}


int main() {
    int secim, deger;

    while (1) {
        printf("1 - Stack'e eleman girin (push): \n");
        printf("2 - Stack'ten eleman çıkarın (pop): \n");
        printf("3 - Stack'in en tepesindeki elemanı gösterin (peek): \n");
        printf("4 - Stack'i ekrana yazdırın (show): \n");
        printf("5 - Çıkış yapın (exit) \n");
        printf("Seçiminizi giriniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklenecek değeri girin: ");
                scanf("%d", &deger);
                push(deger);
                break;
            case 2:
                pop();
                break;
            case 3:
                deger = peek();
                if (deger != -1)
                    printf("En üstteki eleman: %d\n", deger);
                break;
            case 4:
                yazdir();
                break;
            case 5:
                printf("Programdan çıkılıyor.\n");
                return 0;

            default:
                printf("Geçersiz bir seçim yaptınız.\n");
        }
    }
}