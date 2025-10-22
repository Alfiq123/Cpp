//
// Created by algorithm on 10/20/25.
//

#include <iostream>
#include <string>
using namespace std;

// Struktur node mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* prev;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;
Mahasiswa* tail = nullptr;

// Tambah di awal
void tambahAwal(string nama, string nim) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->prev = nullptr;
    baru->next = head;

    if (head != nullptr) {
        head->prev = baru;
    } else {
        tail = baru;
    }
    head = baru;
}

// Tambah di akhir
void tambahAkhir(string nama, string nim) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = nullptr;
    baru->prev = tail;

    if (tail != nullptr) {
        tail->next = baru;
    } else {
        head = baru;
    }
    tail = baru;
}

// Hapus berdasarkan NIM
void hapusBerdasarkanNIM(string nim) {
    Mahasiswa* temp = head;

    while (temp != nullptr && temp->nim != nim) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Jika node yang dihapus adalah head
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // Jika node yang dihapus adalah tail
    }

    delete temp;
    cout << "Data dengan NIM " << nim << " berhasil dihapus.\n";
}

// Traversal maju
void travelMaju() {
    cout << "Traversal Maju:\n";
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        cout << temp->nama << " (" << temp->nim << ")\n";
        temp = temp->next;
    }
}

// Traversal mundur
void travelMundur() {
    cout << "Traversal Mundur:\n";
    Mahasiswa* temp = tail;
    while (temp != nullptr) {
        cout << temp->nama << " (" << temp->nim << ")\n";
        temp = temp->prev;
    }
}

int main() {
    // Tambah 5 data mahasiswa
    tambahAkhir("Andi", "231001");
    tambahAkhir("Budi", "231002");
    tambahAkhir("Citra", "231003");
    tambahAwal("Dewi", "231004");
    tambahAkhir("Eka", "231005");

    travelMaju();
    cout << endl;
    travelMundur();

    cout << "\nMenghapus data dengan NIM 231003...\n";
    hapusBerdasarkanNIM("231003");
    cout << endl;

    travelMaju();
}
