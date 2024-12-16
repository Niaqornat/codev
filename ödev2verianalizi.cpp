#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Rastgele sayı üretmek için srand fonksiyonunu kullan
    srand(static_cast<unsigned>(time(0)));

    // 500 elemanlı bir dizi oluştur
    int numbers[500];

    // 25-35 arasında rastgele tamsayılar üret ve diziye ata
    for (int i = 0; i < 500; ++i) {
        numbers[i] = (rand() % 11) + 25; // 25-35 arasında sayı üret
    }

    // Diziyi ekrana yazdır
    cout << "Üretilen rastgele sayılar:" << endl;
    for (int i = 0; i < 500; ++i) {
        cout << numbers[i] << " ";
        // Her 10 sayıda bir alt satıra geç
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }

    return 0;
}

