#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 3x3 matrisin determinantını hesaplayan fonksiyon
double determinant(const vector<vector<double> > &matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

// Matris çarpımı yapan fonksiyon
vector<vector<double> > multiplyMatrices(const vector<vector<double> > &A, const vector<vector<double> > &B) {
    vector<vector<double> > C(3, vector<double>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Matris yazdırma fonksiyonu
void printMatrix(const vector<vector<double> > &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << setw(8) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<double> > A(3, vector<double>(3));
    vector<vector<double> > B(3, vector<double>(3));
    
    // Kullanıcıdan A ve B matrislerini alma
    cout << "3x3 boyutlu A matrisini giriniz:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "3x3 boyutlu B matrisini giriniz:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> B[i][j];
        }
    }

    // Matrislerin toplamı
    vector<vector<double> > C_sum(3, vector<double>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            C_sum[i][j] = A[i][j] + B[i][j];
        }
    }

    // Matrislerin çarpımı
    vector<vector<double> > C_product = multiplyMatrices(A, B);

    // A matrisinin determinantı
    double detA = determinant(A);

    // Sonuçların yazdırılması
    cout << "\nA Matrisi:" << endl;
    printMatrix(A);

    cout << "\nB Matrisi:" << endl;
    printMatrix(B);

    cout << "\nA + B Matrisi:" << endl;
    printMatrix(C_sum);

    cout << "\nA x B Matrisi:" << endl;
    printMatrix(C_product);

    cout << "\nA Matrisinin Determinantı: " << detA << endl;

    return 0;
}

