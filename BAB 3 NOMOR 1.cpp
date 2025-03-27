#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Struct Nilai
struct Nilai {
    float absen, tugas, UTS, UAS, akhir;
    char huruf;
};

// Struct Mahasiswa
struct Mahasiswa {
    string NPM, nama;
    Nilai nilai;
};

vector<Mahasiswa> daftarMahasiswa;

// Fungsi untuk menghitung nilai akhir dan huruf
void hitungNilai(Nilai &mhs) {
    mhs.akhir = (0.1 * mhs.absen) + (0.2 * mhs.tugas) + (0.3 * mhs.UTS) + (0.4 * mhs.UAS);
    if (mhs.akhir > 80) mhs.huruf = 'A';
    else if (mhs.akhir > 70) mhs.huruf = 'B';
    else if (mhs.akhir > 60) mhs.huruf = 'C';
    else mhs.huruf = 'D';
}

// Fungsi untuk menambah data mahasiswa
void tambahMahasiswa() {
    Mahasiswa mhs;
    cout << "\nMasukkan NPM (Bilangan Cacah): "; cin >> mhs.NPM;
    cout << "Masukkan Nama (Huruf): "; cin.ignore(); getline(cin, mhs.nama);
    cout << "Masukkan Nilai Absen (0-100): "; cin >> mhs.nilai.absen;
    cout << "Masukkan Nilai Tugas (0-100): "; cin >> mhs.nilai.tugas;
    cout << "Masukkan Nilai UTS (0-100): "; cin >> mhs.nilai.UTS;
    cout << "Masukkan Nilai UAS (0-100): "; cin >> mhs.nilai.UAS;

    hitungNilai(mhs.nilai);
    daftarMahasiswa.push_back(mhs);
    cout << "\nData Anda Berhasil Ditambahkan!!!\n";
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa() {
    cout << "\nData Mahasiswa:\n";
    cout << "------------------------------------------------------\n";
    cout << "NPM\tNama\tAbsen\tTugas\tUTS\tUAS\tAkhir\tHuruf\n";
    cout << "------------------------------------------------------\n";
    for (const auto &mhs : daftarMahasiswa) {
        cout << mhs.NPM << "\t" << mhs.nama << "\t" << mhs.nilai.absen << "\t" << mhs.nilai.tugas
             << "\t" << mhs.nilai.UTS << "\t" << mhs.nilai.UAS << "\t" << mhs.nilai.akhir
             << "\t" << mhs.nilai.huruf << "\n";
    }
}

// Fungsi untuk mengedit data mahasiswa
void editMahasiswa() {
    string npm;
    cout << "\nMasukkan NPM Mahasiswa yang Ingin Diedit: "; cin >> npm;
    for (auto &mhs : daftarMahasiswa) {
        if (mhs.NPM == npm) {
            cout << "\nMasukkan NPM (Bilangan Cacah): "; cin >> mhs.NPM;
            cout << "Masukkan Nama baru (Huruf): "; cin.ignore(); getline(cin, mhs.nama);
            cout << "Masukkan Nilai Absen (0-100): "; cin >> mhs.nilai.absen;
            cout << "Masukkan Nilai Tugas (0-100): "; cin >> mhs.nilai.tugas;
            cout << "Masukkan Nilai UTS (0-100): "; cin >> mhs.nilai.UTS;
            cout << "Masukkan Nilai UAS (0-100): "; cin >> mhs.nilai.UAS;
            hitungNilai(mhs.nilai);
            cout << "\nData berhasil diperbarui!!!\n";
            return;
        }
    }
    cout << "\nMahasiswa dengan NPM " << npm << " Tidak Ditemukan.\n";
}

// Fungsi untuk menghapus data mahasiswa
void hapusMahasiswa() {
    string npm;
    cout << "\nMasukkan NPM Mahasiswa yang Ingin Dihapus: "; cin >> npm;
    for (auto it = daftarMahasiswa.begin(); it != daftarMahasiswa.end(); ++it) {
        if (it->NPM == npm) {
            daftarMahasiswa.erase(it);
            cout << "\nData Berhasil Dihapus!!!\n";
            return;
        }
    }
    cout << "\nMahasiswa dengan NPM " << npm << " Tidak Ditemukan.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\nMENU:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Edit Data Mahasiswa\n";
        cout << "4. Hapus Data Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: tambahMahasiswa(); break;
            case 2: tampilkanMahasiswa(); break;
            case 3: editMahasiswa(); break;
            case 4: hapusMahasiswa(); break;
            case 5: cout << "\nTerima kasih!\n"; break;
            default: cout << "\nPilihan Tidak Valid!\n";
        }
    } while (pilihan != 5);
    return 0;
}
