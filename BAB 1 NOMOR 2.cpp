#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int* ptr = arr;

    cout << "Masukkkan 5 angka: ";
        for(int i = 0; i < 5; i++) {
            cin >> arr[i];
        }
        cout << "Alamat dan nilai dari setiap elemen array:\n";
        for(int i = 0; i < 5; i++) {
            cout << "Alamat: " << (ptr + i) << " | Nilai: " << *(ptr + i) << endl;
        }
        return 0;
}
