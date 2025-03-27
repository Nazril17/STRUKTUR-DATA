#include <iostream>
using namespace std;

void memutarMatriks(int *matriks) {
    for (int i = 0; i < 4 / 2; i++) {
        for (int j = i; j < 4 - i - 1; j++) {
            int temp = *(matriks + i * 4 + j);

            *(matriks + i * 4 + j) = *(matriks + (4 - j - 1) * 4 + i);
            *(matriks + (4 - j - 1) * 4 + i) = *(matriks + (4 - i - 1) * 4 + (4 - j - 1));
            *(matriks + (4 - i - 1) * 4 + (4 - j - 1)) = *(matriks + j * 4 + (4 - i - 1));
            *(matriks + j * 4 + (4 - i - 1)) = temp;
        }
    }
}

void printMatriks(int *matriks) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << *(matriks + i * 4 + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int matriks[4][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Matriks sebelum dirotasi:" << endl;
    printMatriks((int *)matriks);
    cout << endl;

    memutarMatriks((int *)matriks);
    cout << endl;

    cout << "Matriks setelah dirotasi 90 derajat:" << endl;
    printMatriks((int *)matriks);
    cout << endl;

    return 0;
}
