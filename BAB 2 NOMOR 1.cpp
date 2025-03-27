#include <iostream>
using namespace std;

void memutarMatriks(int **matriks, int n) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int temp = matriks[i][j];

            matriks[i][j] = matriks[n - j - 1][i];
            matriks[n - j - 1][i] = matriks[n - i - 1][n - j - 1];
            matriks[n - i - 1][n - j - 1] = matriks[j][n - i - 1];
            matriks[j][n - i - 1] = temp;
        }
    }
}

void printMatriks(int **matriks, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan ukuran matriks (n x n): ";
    cin >> n;

    // Alokasi memori untuk matriks n x n secara dinamis
    int **matriks = new int*[n];
    for (int i = 0; i < n; i++) {
        matriks[i] = new int[n];
    }

    // Input matriks
    cout << "Masukkan elemen matriks:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriks[i][j];
        }
        cout << endl;
    }

    cout << "Matriks sebelum rotasi:" << endl;
    printMatriks(matriks, n);
    cout << endl;

    memutarMatriks(matriks, n);
    cout << endl;

    cout << "Matriks setelah rotasi 90 derajat:" << endl;
    printMatriks(matriks, n);

    // Dealokasi memori
    for (int i = 0; i < n; i++) {
        delete[] matriks[i];
    }
    delete[] matriks;

    return 0;
}
