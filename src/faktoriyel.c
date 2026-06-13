#include "../include/math_lib.h"

int faktoriyel_hesapla(int sayi) {
    if (sayi <= 1) return 1;
    int sonuc = 1;
    for (int i = 2; i <= sayi; i++) {
        sonuc *= i;
    }
    return sonuc;
}
