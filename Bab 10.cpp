#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Variabel global
int jumlahDesa;
vector<vector<int>> biaya;      // Matriks biaya antar desa
vector<bool> dikunjungi;        // Status kunjungan desa
int biayaMinimum = INT_MAX;     // Biaya minimum hasil akhir

// Fungsi rekursif untuk mengecek semua rute yang mungkin
void cariRute(int desaSekarang, int jumlahKunjungan, int totalBiaya, int desaAwal) {
    // Jika semua desa sudah dikunjungi dan bisa kembali ke awal
    if (jumlahKunjungan == jumlahDesa && biaya[desaSekarang][desaAwal] != 0) {
        totalBiaya += biaya[desaSekarang][desaAwal]; // Tambah biaya pulang
        if (totalBiaya < biayaMinimum) {
            biayaMinimum = totalBiaya;
        }
        return;
    }

    // Mencoba kunjungi desa yang belum dikunjungi
    for (int i = 0; i < jumlahDesa; i++) {
        if (!dikunjungi[i] && biaya[desaSekarang][i] != 0) {
            dikunjungi[i] = true; // Menandai desa sudah dikunjungi
            cariRute(i, jumlahKunjungan + 1, totalBiaya + biaya[desaSekarang][i], desaAwal);
            dikunjungi[i] = false; // Kembalikan status untuk backtrack
        }
    }
}

int main() {
    cout << "=== Program Tukang Pos Keliling Desa Makmur===\n";
    cout << "Masukkan jumlah desa: ";
    cin >> jumlahDesa;

    // Inisialisasi matriks dan kunjungan
    biaya = vector<vector<int>>(jumlahDesa, vector<int>(jumlahDesa));
    dikunjungi = vector<bool>(jumlahDesa, false);

    // Input matriks biaya
    cout << "\nMasukkan matriks biaya antar desa:\n";
    for (int i = 0; i < jumlahDesa; i++) {
        for (int j = 0; j < jumlahDesa; j++) {
            cin >> biaya[i][j];
        }
    }

    int desaAwal;
    cout << "\nMasukkan nomor desa awal (0 sampai " << jumlahDesa - 1 << "): ";
    cin >> desaAwal;

    // Tandai desa awal sudah dikunjungi
    dikunjungi[desaAwal] = true;

    // Jalankan pencarian rute terbaik
    cariRute(desaAwal, 1, 0, desaAwal);

    // Tampilkan hasil
    cout << "\nBiaya minimum keliling semua desa dan kembali ke awal: " << biayaMinimum << endl;

    return 0;
}
