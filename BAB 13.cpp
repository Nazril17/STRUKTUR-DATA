#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// ==== STRUCT DATA BUKU & ANGGOTA ====
struct Buku {
    int id;
    string judul;
    string pengarang;
    int rak;
    Buku* next;
};

struct Anggota {
    int id;
    string nama;
    queue<int> pinjaman; // ID buku yang dipinjam
    stack<int> historiPengembalian;
    Anggota* next;
};

Buku* headBuku = nullptr;
Anggota* headAnggota = nullptr;

// ==== GRAPH ADJACENCY MATRIX UNTUK RELASI RAK ====
const int MAX_RAK = 10;
int graph[MAX_RAK][MAX_RAK] = {0};

// ==== PETUNJUK PENGGUNA ====
void tampilkanPetunjuk() {
    cout << "\n===== PETUNJUK PENGGUNA APLIKASI PERPUSTAKAAN =====\n";
    cout << "1. Login sebagai Admin terlebih dahulu untuk menambahkan data.\n";
    cout << "   - Tambah Buku (wajib sebelum bisa dipinjam)\n";
    cout << "   - Tambah Anggota (wajib sebelum bisa meminjam)\n";
    cout << "   - Tambah Relasi Rak (opsional, digunakan untuk melihat hubungan antar rak)\n";
    cout << "2. Setelah data tersedia, Pembeli bisa:\n";
    cout << "   - Meminjam buku\n";
    cout << "   - Mengembalikan buku\n";
    cout << "   - Mencari buku berdasarkan ID\n";
    cout << "   - Melihat lokasi rak buku berdasarkan graph (jika sudah diisi oleh Admin)\n";
    cout << "=====================================================\n";
}

// ==== FUNGSI TAMBAH DATA ====
void tambahBuku() {
    Buku* baru = new Buku();
    cout << "ID Buku: "; cin >> baru->id;
    cin.ignore();
    cout << "Judul: "; getline(cin, baru->judul);
    cout << "Pengarang: "; getline(cin, baru->pengarang);
    cout << "Nomor Rak (0-" << MAX_RAK-1 << "): "; cin >> baru->rak;
    baru->next = headBuku;
    headBuku = baru;
    cout << "++Buku berhasil ditambahkan!\n";
}

void tambahAnggota() {
    Anggota* baru = new Anggota();
    cout << "ID Anggota: "; cin >> baru->id;
    cin.ignore();
    cout << "Nama: "; getline(cin, baru->nama);
    baru->next = headAnggota;
    headAnggota = baru;
    cout << "++Anggota berhasil ditambahkan!\n";
}

// ==== CARI ====
Anggota* cariAnggota(int id) {
    Anggota* temp = headAnggota;
    while (temp != nullptr) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Buku* cariBuku(int id) {
    Buku* temp = headBuku;
    while (temp != nullptr) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

// ==== PINJAM & KEMBALIKAN ====
void pinjamBuku() {
    int idAnggota, idBuku;
    cout << "ID Anggota: "; cin >> idAnggota;
    Anggota* a = cariAnggota(idAnggota);
    if (!a) { cout << "!!Anggota tidak ditemukan!\n"; return; }
    cout << "ID Buku yang ingin dipinjam: "; cin >> idBuku;
    Buku* b = cariBuku(idBuku);
    if (!b) { cout << "!!Buku tidak ditemukan!\n"; return; }
    a->pinjaman.push(idBuku);
    cout << "!!Buku berhasil dipinjam oleh " << a->nama << ".\n";
}

void kembalikanBuku() {
    int idAnggota;
    cout << "ID Anggota: "; cin >> idAnggota;
    Anggota* a = cariAnggota(idAnggota);
    if (!a) { cout << "!!Anggota tidak ditemukan!\n"; return; }
    if (a->pinjaman.empty()) {
        cout << "!!Anda belum pernah meminjam buku!\n";
        return;
    }
    int idBuku = a->pinjaman.front();
    a->pinjaman.pop();
    a->historiPengembalian.push(idBuku);
    cout << "==Buku berhasil dikembalikan.\n";
}

// ==== CARI BUKU ====
void cariBukuMenu() {
    int id;
    cout << "ID Buku yang dicari: "; cin >> id;
    Buku* b = cariBuku(id);
    if (!b) cout << "!!Buku tidak ditemukan!\n";
    else {
        cout << "\nDetail Buku:\n";
        cout << "Judul     : " << b->judul << "\n";
        cout << "Pengarang : " << b->pengarang << "\n";
        cout << "Rak       : " << b->rak << "\n";
    }
}

// ==== TAMPILKAN DAFTAR BUKU ====
void tampilkanDaftarBuku() {
    if (headBuku == nullptr) {
        cout << "!!Belum ada data buku yang tersedia.\n";
        return;
    }

    cout << "\n DAFTAR BUKU TERSEDIA:\n";
    cout << "-----------------------------\n";
    Buku* temp = headBuku;
    while (temp != nullptr) {
        cout << "ID   : " << temp->id << " | Judul: " << temp->judul << "\n";
        temp = temp->next;
    }
    cout << "-----------------------------\n";
}


// ==== GRAPH RAK ====
void tambahRelasiRak() {
    int a, b;
    cout << "Masukkan Rak A: "; cin >> a;
    cout << "Terhubung ke Rak B: "; cin >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
    cout << "Relasi antara Rak " << a << " dan Rak " << b << " berhasil ditambahkan.\n";
}

void tampilkanGraphRak() {
    cout << "\n📌 Graph Adjacency Matrix Rak:\n";
    cout << "    ";
    for (int j = 0; j < MAX_RAK; j++) cout << j << " ";
    cout << "\n   -------------------------\n";
    for (int i = 0; i < MAX_RAK; i++) {
        cout << i << " | ";
        for (int j = 0; j < MAX_RAK; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

// ==== MENU ADMIN ====
void menuAdmin() {
    int pilih;
    do {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tambah Anggota\n";
        cout << "3. Tambah Relasi Rak\n";
        cout << "4. Lihat Graph Rak\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilih: "; cin >> pilih;
        switch (pilih) {
            case 1: tambahBuku(); break;
            case 2: tambahAnggota(); break;
            case 3: tambahRelasiRak(); break;
            case 4: tampilkanGraphRak(); break;
        }
    } while (pilih != 5);
}

// ==== MENU PEMBELI ====
void menuPembeli() {
    int pilih;
    do {
        cout << "1. Pinjam Buku\n";
        cout << "2. Kembalikan Buku\n";
        cout << "3. Cari Buku\n";
        cout << "4. Lihat Daftar Buku\n";
        cout << "5. Lihat Graph Rak\n";
        cout << "6. Kembali ke Menu Utama\n";
        cout << "Pilih: "; cin >> pilih;
        switch (pilih) {
            case 1: pinjamBuku(); break;
            case 2: kembalikanBuku(); break;
            case 3: cariBukuMenu(); break;
            case 4: tampilkanDaftarBuku(); break;
            case 5: tampilkanGraphRak(); break;
        }
    } while (pilih != 5);
}

// ==== MENU UTAMA ====
int main() {
    int pilihan;
    tampilkanPetunjuk(); // Tampilkan panduan dulu saat pertama jalan
    do {
        cout << "\n===== APLIKASI PERPUSTAKAAN =====\n";
        cout << "1. Login sebagai Admin\n";
        cout << "2. Login sebagai Pembeli\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: "; cin >> pilihan;
        switch (pilihan) {
            case 1: menuAdmin(); break;
            case 2: menuPembeli(); break;
            case 3: cout << "#Terima kasih telah menggunakan aplikasi ini#.\n"; break;
            default: cout << "!!Pilihan tidak valid.\n"; break;
        }
    } while (pilihan != 3);
    return 0;
}
