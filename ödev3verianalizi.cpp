#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Rastgele sayı üretmek için srand fonksiyonunu kullan
    srand(static_cast<unsigned>(time(0)));

    // 500 elemanlı bir vektör oluştur
    vector<int> numbers;
    int lower_limit = 10;
    int upper_limit = 35;
    double target_mean = 25;
    double tolerance = 5.0;

    // Ortalama 25±5 aralığında sayılar üret
    while (numbers.size() < 500) {
        int random_number = (rand() % (upper_limit - lower_limit + 1)) + lower_limit;
        numbers.push_back(random_number);

        // Ortalama kontrolü
        if (numbers.size() >= 500) {
            double current_mean = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
            if (current_mean < target_mean - tolerance || current_mean > target_mean + tolerance) {
                numbers.clear(); // Şart sağlanmazsa yeniden başla
            }
        }
    }

    // Diziyi ekrana yazdır
    cout << "Üretilen rastgele sayılar:" << endl;
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
        // Her 10 sayıda bir alt satıra geç
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }

    return 0;
}

