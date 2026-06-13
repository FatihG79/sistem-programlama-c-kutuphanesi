#include "../include/math_lib.h"

// Sayı asal ise 1, değilse 0 döndürür
int asal_mi(int sayi) {
    if (sayi <= 1) return 0;
    for (int i = 2; i * i <= sayi; i++) {
        if (sayi % i == 0) return 0;
    }
    return 1;
}
