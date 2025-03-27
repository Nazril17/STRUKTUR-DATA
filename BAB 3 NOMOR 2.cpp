#include <iostream>

using namespace std;

// Fungsi untuk menghitung biaya rental warnet
int hitungBiayaRental(int jam, int menit, int detik) {
    int totalDetik = (jam * 3600) + (menit * 60) + detik;
    int biaya = (totalDetik / 30) * 130;
    return biaya;
}

int main() {
    int jam, menit, detik;

    cout << "Masukkan Durasi Rental Anda";
    cout << endl;
    cout << "Berapa Jam (1-24): ";
    cin >> jam;
    cout << "Berapa Menit (1-59): ";
    cin >> menit;
    cout << "Berapa Detik (1-59): ";
    cin >> detik ;
    cout << endl;

    int biaya = hitungBiayaRental (jam, menit, detik);

    cout << "Total Biaya Yang Harus Anda Bayar: Rp. " << biaya << endl;

    return 0;
}
