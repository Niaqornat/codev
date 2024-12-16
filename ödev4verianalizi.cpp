#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
#include <map>
#include <algorithm>

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
    cout << "\nÜretilen rastgele sayılar:" << endl;
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }

    // Aritmetik ortalamayı hesapla
    double mean = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    cout << "\n\nAritmetik Ortalama: " << mean << endl;

    // En küçük ve en büyük değerleri bul
    int min_value = numbers[0];
    int max_value = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < min_value) min_value = numbers[i];
        if (numbers[i] > max_value) max_value = numbers[i];
    }
    cout << "En Küçük Değer: " << min_value << endl;
    cout << "En Büyük Değer: " << max_value << endl;

    // Frekansları hesapla
    map<int, int> frequency;
    for (size_t i = 0; i < numbers.size(); ++i) {
        frequency[numbers[i]]++;
    }

    cout << "\nFrekanslar:" << endl;
    for (map<int, int>::iterator it = frequency.begin(); it != frequency.end(); ++it) {
        cout << it->first << "'den " << it->second << " adet" << endl;
    }

    // Tek ve çift sayıları ayrı dizilere ata
    vector<int> odd_numbers;
    vector<int> even_numbers;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0) {
            even_numbers.push_back(numbers[i]);
        } else {
            odd_numbers.push_back(numbers[i]);
        }
    }

    cout << "\nTek Sayılar:" << endl;
    for (size_t i = 0; i < odd_numbers.size(); ++i) {
        cout << odd_numbers[i] << " ";
    }

    cout << "\n\nÇift Sayılar:" << endl;
    for (size_t i = 0; i < even_numbers.size(); ++i) {
        cout << even_numbers[i] << " ";
    }

    // Ortalamadan küçük ve büyük olanları ayrı dizilere ata
    vector<int> below_mean;
    vector<int> above_mean;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] < mean) {
            below_mean.push_back(numbers[i]);
        } else {
            above_mean.push_back(numbers[i]);
        }
    }

    cout << "\n\nOrtalamadan Küçük Olan Sayılar:" << endl;
    for (size_t i = 0; i < below_mean.size(); ++i) {
        cout << below_mean[i] << " ";
    }

    cout << "\n\nOrtalamadan Büyük veya Eşit Olan Sayılar:" << endl;
    for (size_t i = 0; i < above_mean.size(); ++i) {
        cout << above_mean[i] << " ";
    }

    return 0;
}

