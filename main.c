#include <stdio.h>
#include "include/math_lib.h"

int main() {
    int sayi1 = 5;
    int sayi2 = 17;
    int sayi3 = 4;

    printf("=== Matematik Kutuphanesi Test Sonuclari ===\n");
    
    // Fonksiyon cagrilarinin yapilmasi ve sonuclarin ekrana yazdirilmasi [cite: 36]
    printf("%d sayisinin karesi: %d\n", sayi1, karesini_al(sayi1));
    printf("%d sayisinin kupu: %d\n", sayi3, kupunu_al(sayi3));
    printf("%d sayisinin faktoriyeli: %d\n", sayi1, faktoriyel_hesapla(sayi1));

    if (asal_mi(sayi2)) {
        printf("%d sayisi bir asal sayidir.\n", sayi2);
    } else {
        printf("%d sayisi bir asal sayi degildir.\n", sayi2);
    }

    return 0;
}
