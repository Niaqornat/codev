#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    const int YEARS = 5;
    const int MONTHS = 12;
    int ciro[YEARS][MONTHS];
    double ortciro[YEARS] = {0};

    // Rastgele ciro verisi üretimi
    srand(time(0)); // Rastgelelik için zaman tohumlama
    for (int year = 0; year < YEARS; ++year) {
        for (int month = 0; month < MONTHS; ++month) {
            ciro[year][month] = 100 + rand() % 4901; // 100-5000 arası rastgele değer
        }
    }

    // Yıllık ortalama ciro hesaplama
    for (int year = 0; year < YEARS; ++year) {
        int toplam = 0;
        for (int month = 0; month < MONTHS; ++month) {
            toplam += ciro[year][month];
        }
        ortciro[year] = static_cast<double>(toplam) / MONTHS;
    }

    // Kullanıcıdan yıl bilgisi alma
    int secilenYil;
    cout << "Bir yıl seçin (1-" << YEARS << "): ";
    cin >> secilenYil;

    if (secilenYil < 1 || secilenYil > YEARS) {
        cout << "Geçersiz yıl!" << endl;
        return 1;
    }

    // Seçilen yılın sıfır tabanlı indeksi
    int yilIndex = secilenYil - 1;

    // Seçilen yılın ortalamasından yüksek olan aylar
    cout << "\n" << secilenYil << ". yılın ortalamasından yüksek olan aylar:\n";
    cout << "Ay\tCiro\n";
    for (int month = 0; month < MONTHS; ++month) {
        if (ciro[yilIndex][month] > ortciro[yilIndex]) {
            cout << month + 1 << "\t" << ciro[yilIndex][month] << endl;
        }
    }

    // Çeyrek ortalamalarını hesaplama ve ekrana yazdırma
    cout << "\n" << secilenYil << ". yılın çeyrek ortalamaları:\n";
    for (int quarter = 0; quarter < 4; ++quarter) {
        int baslangicAy = quarter * 3;
        double toplam = 0;
        for (int i = 0; i < 3; ++i) {
            toplam += ciro[yilIndex][baslangicAy + i];
        }
        double ortalama = toplam / 3;
        cout << quarter + 1 << ". Çeyrek: " << fixed << setprecision(2) << ortalama << endl;
    }

    return 0;
}

