//
// Created by algorithm on 10/5/25.
//

#include <iostream>
#include <vector>
#include <string>

struct Mahasiswa {
    std::string nama;
    std::string mata_kuliah;
    int         nilai{};
};

// Pakai aliases karena kepanjangan
using vec_str = std::vector<std::string>;
using vec_int = std::vector<int>;
using vec_mhs = std::vector<Mahasiswa>;

// Fungsi untuk mencari data di dalam array → Binary Search.
int binary_search(const vec_int& array, int tujuan) {
    int kiri  = 0;
    int kanan = array.size() - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (array[tengah] == tujuan) {
            return tengah;
        } if (array[tengah] < tujuan) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return -1;
}

// Fungsi untuk mengurutkan array → Bubble Sort
void bubble_sort(vec_int& array) {
    int ukuran = array.size();

    for (int langkah = 0; langkah < ukuran - 1; ++langkah) {
        for (int i = 0; i < ukuran - langkah - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void tambah_data(vec_mhs& daftar) {
    Mahasiswa mhs;
    std::cout << "\n=== Tambah Data Mahasiswa ===\n";
    std::cin.ignore();

    std::cout << "Nama: ";
    std::getline(std::cin, mhs.nama);

    std::cout << "Mata Kuliah: ";
    std::getline(std::cin, mhs.mata_kuliah);

    std::cout << "Nilai: ";
    std::cin >> mhs.nilai;

    daftar.push_back(mhs);
    std::cout << "Data berhasil ditambahkan.\n";
}
void tampil_data(vec_mhs& daftar) {}
void ubah_data(vec_mhs& daftar) {}
void hapus_data(vec_mhs& daftar) {}

int main() {

    vec_mhs daftar;
    int pilihan;

    do {
        std::cout << "\n═════ MENU CRUD MAHASISWA ═════\n"
                  << "  1. Tambah data\n"
                  << "  2. Lihat data\n"
                  << "  3. Ubah data\n"
                  << "  4. Hapus data\n"
                  << "  5. Keluar\n"
                  << "Pilih: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1: tambah_data(daftar); break;
            case 2: tampil_data(daftar); break;
            case 3: ubah_data(daftar); break;
            case 4: hapus_data(daftar); break;
            case 5: std::cout << "Keluar...\n"; break;
            default: std::cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}