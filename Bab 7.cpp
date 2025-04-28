#include <iostream>
using namespace std;

// Stack A
int stackA[10];
int topA = -1;

// Stack B
int stackB[10];
int topB = -1;

// Stack C
int stackC[10];
int topC = -1;

// Push data ke Stack A
void pushA(int data) {
    topA++;
    stackA[topA] = data;
}

// Push data ke Stack B
void pushB(int data) {
    topB++;
    stackB[topB] = data;
}

// Push data ke Stack C
void pushC(int data) {
    topC++;
    stackC[topC] = data;
}

// Pop data dari Stack A
int popA() {
    int data = stackA[topA];
    topA--;
    return data;
}

// Pop data dari Stack B
int popB() {
    int data = stackB[topB];
    topB--;
    return data;
}

// Pop data dari Stack C
int popC() {
    int data = stackC[topC];
    topC--;
    return data;
}

// Fungsi untuk memindahkan batu
void moveBatu(char asal, char tujuan) {
    int batu;

    // Pop dari stack asal
    if (asal == 'A') batu = popA();
    else if (asal == 'B') batu = popB();
    else if (asal == 'C') batu = popC();

    // Push ke stack tujuan
    if (tujuan == 'A') pushA(batu);
    else if (tujuan == 'B') pushB(batu);
    else if (tujuan == 'C') pushC(batu);

    cout << "\nPindahkan batu " << batu << " dari " << asal << " ke " << tujuan << endl;
}

int main() {
    // Isi Stack A (besar ke kecil)
    pushA(30);
    pushA(20);
    pushA(10);

    cout << "\nBatu A: " << stackA[0] << " " << stackA[1] << " " << stackA[2] << endl;

    // Langkah-langkah Menara Hanoi
    moveBatu('A', 'C'); // Pindahkan batu 10 dari A ke C
    cout << "Batu A: " << stackA[0] << " " << stackA[1] << endl;
    cout << "Batu B: " << "-" << endl;
    cout << "Batu C: " << stackC[0] << endl;

    moveBatu('A', 'B'); // Pindahkan batu 20 dari A ke B
    cout << "Batu A: " << stackA[0] << endl;
    cout << "Batu B: " << stackB[0] << endl;
    cout << "Batu C: " << stackC[0] << endl;

    moveBatu('C', 'B'); // Pindahkan batu 10 dari C ke B
    cout << "Batu A: " << stackA[0] << endl;
    cout << "Batu B: " << stackB[0] << " " << stackB[1] << endl;
    cout << "Batu C: " << "-" << endl;

    moveBatu('A', 'C'); // Pindahkan batu 30 dari A ke C
    cout << "Batu A: " << "-" << endl;
    cout << "Batu B: " << stackB[0] << " " << stackB[1] << endl;
    cout << "Batu C: " << stackC[0] << " " << stackC[1] << endl;

    moveBatu('B', 'A'); // Pindahkan batu 10 dari B ke A
    cout << "Batu A: " << stackA[0] << endl;
    cout << "Batu B: " << stackB[0] << endl;
    cout << "Batu C: " << stackC[0] << " " << stackC[1] << endl;

    moveBatu('B', 'C'); // Pindahkan batu 20 dari B ke C
    cout << "Batu A: " << stackA[0] << endl;
    cout << "Batu B: " << "-" << endl;
    cout << "Batu C: " << stackC[0] << " " << stackC[1] << endl;
    
    moveBatu('A', 'C'); // Pindahkan batu 10 dari A ke C
    cout << "Batu A: " << "-" << endl;
    cout << "Batu B: " << "-" << endl;
    cout << "Batu C: " << stackC[0] << " " << stackC[1] << " " << stackC[2] << endl;

    cout << "\nHasil akhir setelah perpindahan dilakukan: " << endl;
    cout << "Batu A: " << "-" << endl;  
    cout << "Batu B: " << "-" << endl;
    cout << "Batu C: " << stackC[0] << " " << stackC[1] << " " << stackC[2] << endl;

    return 0;
}
