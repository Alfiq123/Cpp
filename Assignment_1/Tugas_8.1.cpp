//
// Created by algorithm on 10/20/25.
//

#include <iostream>
#include <string>

using namespace std;

// === BAGIAN DOUBLE LINKED LIST (MAHASISWA) ===

// 1. Struktur Node untuk Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa *next;
    Mahasiswa *prev;
};

// Pointer global untuk menunjuk ke node pertama (head) dan terakhir (tail)
Mahasiswa *head = nullptr;
Mahasiswa *tail = nullptr;

// 2. Fungsi untuk Menambah Node di Awal (Head)
void tambah_di_awal(string nama, string nim) {
    Mahasiswa *newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        // Jika list masih kosong
        head = tail = newNode;
    } else {
        // Jika list sudah ada isinya
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << ">> Data '" << nama << "' berhasil ditambahkan di awal." << endl;
}

// 3. Fungsi untuk Menambah Node di Akhir (Tail)
void tambahAkhir(string nama, string nim) {
    Mahasiswa *newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        // Jika list masih kosong
        head = tail = newNode;
    } else {
        // Jika list sudah ada isinya
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << ">> Data '" << nama << "' berhasil ditambahkan di akhir." << endl;
}

// 4. Fungsi untuk Menghapus Node berdasarkan NIM
void hapusBerdasarkanNim(string nim) {
    if (head == nullptr) {
        cout << "List kosong, tidak ada data yang bisa dihapus." << endl;
        return;
    }

    Mahasiswa *current = head;
    // Cari node yang akan dihapus
    while (current != nullptr && current->nim != nim) {
        current = current->next;
    }

    // Jika NIM tidak ditemukan
    if (current == nullptr) {
        cout << ">> NIM '" << nim << "' tidak ditemukan." << endl;
        return;
    }

    cout << ">> Menghapus data dengan NIM '" << nim << "'..." << endl;

    // Jika node yang dihapus adalah head
    if (current == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            // Jika hanya ada satu node di list
            tail = nullptr;
        }
    }
    // Jika node yang dihapus adalah tail
    else if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    // Jika node yang dihapus di tengah
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current; // Hapus node dari memori
    cout << ">> Data berhasil dihapus." << endl;
}

// 5. Fungsi Traversal Maju (dari Head ke Tail)
void traversalMaju() {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }
    cout << "\n--- Traversal Maju (Head -> Tail) ---\n";
    Mahasiswa *current = head;
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
    }
    cout << "-------------------------------------\n";
}

// 6. Fungsi Traversal Mundur (dari Tail ke Head)
void traversalMundur() {
    if (tail == nullptr) {
        cout << "List kosong." << endl;
        return;
    }
    cout << "\n--- Traversal Mundur (Tail -> Head) ---\n";
    Mahasiswa *current = tail;
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->prev;
    }
    cout << "-------------------------------------\n";
}


// === BAGIAN CIRCULAR LINKED LIST (INTEGER) ===

// 1. Struktur Node untuk Integer
struct Node {
    int data;
    Node *next;
};

// Pointer global untuk menunjuk ke node pertama (head) dari Circular List
Node *headCLL = nullptr;

// 2. Fungsi untuk menambah node di akhir Circular List
void tambahCircular(int nilai) {
    Node *newNode = new Node;
    newNode->data = nilai;

    if (headCLL == nullptr) {
        // Jika list kosong, node baru menunjuk ke dirinya sendiri
        headCLL = newNode;
        newNode->next = headCLL;
    } else {
        // Cari node terakhir
        Node *temp = headCLL;
        while (temp->next != headCLL) {
            temp = temp->next;
        }
        // Sambungkan node terakhir ke node baru, dan node baru ke head
        temp->next = newNode;
        newNode->next = headCLL;
    }
}

// 3. Fungsi untuk menampilkan Circular List
void tampilkanCircular() {
    if (headCLL == nullptr) {
        cout << "Circular List kosong." << endl;
        return;
    }

    cout << "\n--- Traversal Circular Linked List ---\n";
    Node *temp = headCLL;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != headCLL);
    cout << "(kembali ke " << headCLL->data << ")" << endl;
    cout << "--------------------------------------\n";
}


// === FUNGSI UTAMA (MAIN) ===

int main() {
    cout << "===== PROGRAM DOUBLE LINKED LIST MAHASISWA =====\n" << endl;

    // Menambahkan 5 data awal
    tambahAkhir("Budi", "101");
    tambahAkhir("Cindy", "102");
    tambahAkhir("Dodi", "103");
    tambahAkhir("Eka", "104");
    tambahAkhir("Fahri", "105");

    // Menampilkan data awal
    traversalMaju();

    // Demo fitur-fitur
    cout << "\n=== DEMO FITUR ===\n";
    tambah_di_awal("Ani", "100");
    tambahAkhir("Gilang", "106");
    traversalMaju();
    traversalMundur();

    cout << "\n=== DEMO HAPUS DATA ===\n";
    hapusBerdasarkanNim("103"); // Menghapus data di tengah
    hapusBerdasarkanNim("100"); // Menghapus data di awal (head)
    hapusBerdasarkanNim("106"); // Menghapus data di akhir (tail)
    hapusBerdasarkanNim("999"); // Mencoba menghapus data yang tidak ada
    traversalMaju();


    cout << "\n\n===== PROGRAM CIRCULAR LINKED LIST INTEGER =====\n";

    // Menambahkan 4 data integer
    tambahCircular(10);
    tambahCircular(20);
    tambahCircular(30);
    tambahCircular(40);

    // Menampilkan hasil traversal
    tampilkanCircular();

    return 0;
}