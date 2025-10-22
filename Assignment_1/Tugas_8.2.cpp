//
// Created by algorithm on 10/20/25.
//

#include <iostream>
#include <string>

using namespace std;

// === BAGIAN 1: DOUBLE LINKED LIST (MAHASISWA) ===

class DoublyLinkedList {
private:
    struct Node {
        string nama, nim;
        Node *next, *prev;
        Node(string n, string i) : nama(n), nim(i), next(nullptr), prev(nullptr) {}
    };
    Node *head, *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() { // Destruktor untuk membersihkan memori
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void tambahAwal(string nama, string nim) {
        Node *newNode = new Node(nama, nim);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void tambahAkhir(string nama, string nim) {
        Node *newNode = new Node(nama, nim);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void hapus(string nim) {
        Node *current = head;
        while (current && current->nim != nim) {
            current = current->next;
        }

        if (!current) {
            cout << ">> NIM '" << nim << "' tidak ditemukan." << endl;
            return;
        }

        if (current->prev) current->prev->next = current->next;
        else head = current->next;

        if (current->next) current->next->prev = current->prev;
        else tail = current->prev;

        cout << ">> Data '" << current->nama << "' dengan NIM '" << nim << "' berhasil dihapus." << endl;
        delete current;
    }

    void tampilMaju() {
        cout << "\n--- Traversal Maju (Head -> Tail) ---\n";
        Node *current = head;
        if (!current) { cout << "List kosong." << endl; return; }
        while (current) {
            cout << "Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
        }
    }

    void tampilMundur() {
        cout << "\n--- Traversal Mundur (Tail -> Head) ---\n";
        Node *current = tail;
        if (!current) { cout << "List kosong." << endl; return; }
        while (current) {
            cout << "Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->prev;
        }
    }
};

// === BAGIAN 2: CIRCULAR LINKED LIST (INTEGER) ===

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node *next;
        Node(int d) : data(d), next(nullptr) {}
    };
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    ~CircularLinkedList() { // Destruktor
        if (!head) return;
        Node *current = head->next;
        while (current != head) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }

    void tambah(int nilai) {
        Node *newNode = new Node(nilai);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void tampil() {
        cout << "\n--- Traversal Circular Linked List ---\n";
        if (!head) { cout << "List kosong." << endl; return; }
        Node *temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(kembali ke " << head->data << ")" << endl;
    }
};


// === FUNGSI UTAMA (MAIN) ===

int main() {
    cout << "===== PROGRAM DOUBLE LINKED LIST MAHASISWA =====\n";
    DoublyLinkedList daftarMhs;
    daftarMhs.tambahAkhir("Budi", "101");
    daftarMhs.tambahAkhir("Cindy", "102");
    daftarMhs.tambahAkhir("Dodi", "103");
    daftarMhs.tambahAwal("Ani", "100");
    daftarMhs.tambahAkhir("Eka", "104");

    daftarMhs.tampilMaju();
    daftarMhs.tampilMundur();

    cout << "\n--- Demo Hapus ---\n";
    daftarMhs.hapus("103"); // Hapus tengah
    daftarMhs.hapus("100"); // Hapus head
    daftarMhs.hapus("999"); // Tidak ditemukan
    daftarMhs.tampilMaju();

    cout << "\n\n===== PROGRAM CIRCULAR LINKED LIST INTEGER =====\n";
    CircularLinkedList daftarAngka;
    daftarAngka.tambah(10);
    daftarAngka.tambah(20);
    daftarAngka.tambah(30);
    daftarAngka.tambah(40);
    daftarAngka.tampil();

    return 0;
}