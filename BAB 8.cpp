#include <iostream>
using namespace std;

// Queue manual
char queue[100];
int front, rear;

// Reset queue
void resetQueue() {
    front = -1;
    rear = -1;
}

// Enqueue huruf ke queue
void enqueue(char c) {
    if (rear == 99) {
        cout << "Queue penuh!" << endl;
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = c;
    }
}

// Dequeue huruf dari queue
char dequeue() {
    if (front == -1 || front > rear) {
        return '\0';
    } else {
        char c = queue[front];
        front++;
        return c;
    }
}

// Cek apakah kata palindrome
bool isPalindrome(string kata) {
    resetQueue(); // kosongkan queue

    // Isi queue
    for (int i = 0; i < kata.length(); i++) {
        enqueue(kata[i]);
    }

    // Bandingkan dari depan (queue) dan belakang (string)
    for (int i = kata.length() - 1; i >= 0; i--) {
        if (dequeue() != kata[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string kata1, kata2, kata3;
    cout << "Masukkan kata Pertama : ";
    cin >> kata1;
    cout << "Masukkan kata Kedua   : ";
    cin >> kata2;
    cout << "Masukkan kata Ketiga  : ";
    cin >> kata3;

    // Cek kata 1
    if (isPalindrome(kata1))
        cout << "\nKata Pertama : (" << kata1 << ") adalah palindrome" << endl;
    else
        cout << "\nKata Pertama : (" << kata1 << ") bukan palindrome" << endl;
    cout << "##########################" << endl;

    // Cek kata 2
    if (isPalindrome(kata2))
        cout << "Kata Kedua     : (" << kata2 << ") adalah palindrome" << endl;
    else
        cout << "Kata Kedua     : (" << kata2 << ") bukan palindrome" << endl;
    cout << "##########################" << endl;

    // Cek kata 3
    if (isPalindrome(kata3))
        cout << "Kata Ketiga    : (" << kata3 << ") adalah palindrome" << endl;
    else
        cout << "Kata Ketiga    : (" << kata3 << ") bukan palindrome" << endl;
    cout << "##########################" << endl;

    return 0;
}
