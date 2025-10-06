//
// Created by algorithm on 10/5/25.
//

#include <iostream>
#include <vector>
#include <string>

struct Mahasiswa {
    std::string nama;
    std::string matkul;
    double      ipk{};
};

// Pakai aliases karena kepanjangan
using vec_str = std::vector<std::string>;
using vec_int = std::vector<int>;
using vec_mhs = std::vector<Mahasiswa>;

// Mencari data di dalam array → Binary Search.
int binary_search(const vec_int& array, int tujuan) {
    int kiri  = 0;
    int kanan = array.size() - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (array[tengah] == tujuan) { return tengah; }
        else if (array[tengah] < tujuan) { kiri = tengah + 1; }
        else { kanan = tengah - 1; }
    }

    return -1;
}

// Mengurutkan array → Bubble Sort
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

// Menambah Data
void tambah_data(vec_mhs& daftar) {
    Mahasiswa mhs;
    std::cout << "\n═════ Tambah Data Mahasiswa ═════\n";
    std::cin.ignore();

    std::cout << "Nama: ";        std::getline(std::cin, mhs.nama);
    std::cout << "Mata Kuliah: "; std::getline(std::cin, mhs.matkul);
    std::cout << "IPK: ";         std::cin >> mhs.ipk;

    daftar.push_back(mhs);
    std::cout << "Data berhasil ditambahkan.\n";
}

// Menampilkan Data
void tampil_data(const vec_mhs& daftar) {
    std::cout << "\n═════ Daftar Mahasiswa ═════\n";

    if (daftar.empty()) { std::cout << "Belum ada data.\n"; return; }

    for (size_t i = 0; i < daftar.size(); ++i) {
        std::cout << i + 1 << ". "
                  << "Nama: " << daftar[i].nama
                  << ", Mata Kuliah: " << daftar[i].matkul
                  << ", Nilai: " << daftar[i].ipk
                  << '\n';
    }
}

// Mengubah Data
void ubah_data(std::vector<Mahasiswa>& daftar) {
    std::cout << "\n═════ Ubah Data Mahasiswa ═════\n";

    if (daftar.empty()) { std::cout << "Data masih kosong.\n"; return; }

    for (size_t i = 0; i < daftar.size(); ++i) {
        std::cout << i + 1 << ". " << daftar[i].nama << "\n";
    }

    size_t indeks;
    std::cout << "Masukkan nomor untuk data yang ingin diubah: ";
    std::cin >> indeks;

    if (indeks < 1 || indeks > daftar.size()) {
        std::cout << "Nomor tidak valid.\n";
        return;
    }

    Mahasiswa& mhs = daftar[indeks - 1];
    std::cin.ignore();

    std::cout << "Nama baru (lama: " << mhs.nama << "): ";
    std::getline(std::cin, mhs.nama);

    std::cout << "Mata Kuliah baru (lama: " << mhs.matkul << "): ";
    std::getline(std::cin, mhs.matkul);

    std::cout << "Nilai baru (lama: " << mhs.ipk << "): ";
    std::cin >> mhs.ipk;

    std::cout << "Data berhasil diubah.\n";
}

// Menghapus Data
void hapus_data(vec_mhs& daftar) {
    std::cout << "\n═════ Hapus Data Mahasiswa ═════\n";

    if (daftar.empty()) {
        std::cout << "Data masih kosong, tidak ada yang bisa dihapus.\n";
        return;
    }

    for (size_t i = 0; i < daftar.size(); ++i) {
        std::cout << i + 1 << ". " << daftar[i].nama << "\n";
    }

    size_t indeks;
    std::cout << "Masukkan nomor data yang ingin dihapus: ";
    std::cin >> indeks;

    if (indeks < 1 || indeks > daftar.size()) {
        std::cout << "Nomor tidak valid.\n";
        return;
    }

    daftar.erase(daftar.begin() + (indeks - 1));

    std::cout << "Data berhasil dihapus.\n";
}

int main() {

    vec_mhs daftar;
    int pilihan;

    do {
        std::cout << "\n═════ PENGELOLA DATA MAHASISWA V.2 ═════\n"
                  << "  1. Tambah Data"  << "\n"
                  << "  2. Lihat Data"   << "\n"
                  << "  3. Ubah Data"    << "\n"
                  << "  4. Hapus Data"   << "\n"
                  << "  5. Urutkan Data" << "\n"
                  << "  6. Cari Data"    << "\n"
                  << "  7. Keluar"       << "\n"
                  << "Masukkan Pilihan (1-7): ";
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