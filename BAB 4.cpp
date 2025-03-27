#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Menambahkan data baru ke dalam linked list
void tambahNode(Node*& head, int angka) {
    Node* newNode = new Node;
    newNode->data = angka;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* bantu = head;
        while (bantu->next != nullptr) {
            bantu = bantu->next;
        }
        bantu->next = newNode;
    }
}

// Menampilkan isi linked list
void tampilkanList(Node* head) {
    Node* bantu = head;
    while (bantu != nullptr) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

// Membalikkan urutan linked list
void balikList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    Node* head = nullptr;

    // Menambahkan data ke linked list
    tambahNode(head, 1);
    tambahNode(head, 2);
    tambahNode(head, 3);
    tambahNode(head, 4);
    tambahNode(head, 5);

    cout << "Linked List Sebelum Dibalik: ";
    tampilkanList(head);

    balikList(head);

    cout << "Linked List Setelah Dibalik: ";
    tampilkanList(head);

    return 0;
}
