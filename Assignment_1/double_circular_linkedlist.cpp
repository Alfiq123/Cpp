#include <iostream>
#include <string>
using namespace std;

// ========== DOUBLE LINKED LIST ==========
struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* prev;
    Mahasiswa* next;
};

class DoubleLinkedList {
private:
    Mahasiswa* head;
    Mahasiswa* tail;

public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Tambah data di awal
    void tambahAwal(string nama, string nim) {
        Mahasiswa* baru = new Mahasiswa();
        baru->nama = nama;
        baru->nim = nim;
        baru->prev = NULL;
        baru->next = head;

        if (head != NULL) {
            head->prev = baru;
        } else {
            tail = baru;
        }
        head = baru;
        cout << "Data " << nama << " berhasil ditambahkan di awal!\n";
    }

    // Tambah data di akhir
    void tambahAkhir(string nama, string nim) {
        Mahasiswa* baru = new Mahasiswa();
        baru->nama = nama;
        baru->nim = nim;
        baru->next = NULL;
        baru->prev = tail;

        if (tail != NULL) {
            tail->next = baru;
        } else {
            head = baru;
        }
        tail = baru;
        cout << "Data " << nama << " berhasil ditambahkan di akhir!\n";
    }

    // Hapus berdasarkan NIM
    void hapusByNIM(string nim) {
        Mahasiswa* temp = head;
        
        while (temp != NULL) {
            if (temp->nim == nim) {
                // Jika node yang dihapus adalah head
                if (temp == head) {
                    head = temp->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    } else {
                        tail = NULL;
                    }
                }
                // Jika node yang dihapus adalah tail
                else if (temp == tail) {
                    tail = temp->prev;
                    tail->next = NULL;
                }
                // Jika node di tengah
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                
                cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus!\n";
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Data dengan NIM " << nim << " tidak ditemukan!\n";
    }

    // Traversal maju (dari awal ke akhir)
    void traversalMaju() {
        if (head == NULL) {
            cout << "List kosong!\n";
            return;
        }
        
        Mahasiswa* temp = head;
        cout << "\n=== Traversal Maju ===\n";
        while (temp != NULL) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }

    // Traversal mundur (dari akhir ke awal)
    void traversalMundur() {
        if (tail == NULL) {
            cout << "List kosong!\n";
            return;
        }
        
        Mahasiswa* temp = tail;
        cout << "\n=== Traversal Mundur ===\n";
        while (temp != NULL) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->prev;
        }
    }
};

// ========== CIRCULAR LINKED LIST ==========
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Tambah data
    void tambah(int nilai) {
        Node* baru = new Node();
        baru->data = nilai;

        if (head == NULL) {
            head = baru;
            baru->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = baru;
            baru->next = head;
        }
    }

    // Traversal circular
    void traversal() {
        if (head == NULL) {
            cout << "List kosong!\n";
            return;
        }

        Node* temp = head;
        cout << "\n=== Traversal Circular Linked List ===\n";
        cout << "Data: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(kembali ke awal)\n";
    }
};

// ========== MAIN PROGRAM ==========
int main() {
    // DOUBLE LINKED LIST
    cout << "======================================\n";
    cout << "    DOUBLE LINKED LIST MAHASISWA\n";
    cout << "======================================\n\n";

    DoubleLinkedList dll;

    // Inisialisasi 5 data mahasiswa
    dll.tambahAkhir("Budi Santoso", "2201001");
    dll.tambahAkhir("Siti Nurhaliza", "2201002");
    dll.tambahAkhir("Ahmad Zaki", "2201003");
    dll.tambahAkhir("Dewi Lestari", "2201004");
    dll.tambahAkhir("Eko Prasetyo", "2201005");

    // Tampilkan traversal maju dan mundur
    dll.traversalMaju();
    dll.traversalMundur();

    // Tambah di awal
    cout << "\n--- Menambah data di awal ---\n";
    dll.tambahAwal("Rina Wijaya", "2201000");
    dll.traversalMaju();

    // Hapus berdasarkan NIM
    cout << "\n--- Menghapus data dengan NIM 2201003 ---\n";
    dll.hapusByNIM("2201003");
    dll.traversalMaju();

    // CIRCULAR LINKED LIST
    cout << "\n\n======================================\n";
    cout << "      CIRCULAR LINKED LIST\n";
    cout << "======================================\n";

    CircularLinkedList cll;
    
    // Inisialisasi 4 nilai integer
    cll.tambah(10);
    cll.tambah(20);
    cll.tambah(30);
    cll.tambah(40);

    // Tampilkan traversal
    cll.traversal();

    cout << "\n======================================\n";
    cout << "         PROGRAM SELESAI\n";
    cout << "======================================\n";

    return 0;
}
