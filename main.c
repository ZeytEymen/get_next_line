#include <stdio.h>

void sayaciArttir() {
    // static değişken tanımlanır ve sadece bu fonksiyon içinde görünür.
    int sayac = 0;

    // Sayaç her çağrıldığında arttırılır.
    sayac++;

    // Son değeri ekrana yazdırılır.
    printf("Sayaç Değeri: %d\n", sayac);
}

int main() {
    // Fonksiyon birkaç kez çağrılır.
    sayaciArttir();
    sayaciArttir();
    sayaciArttir();

    return 0;
}