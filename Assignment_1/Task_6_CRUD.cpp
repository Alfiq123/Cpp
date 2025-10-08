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

// Deklarasi fungsi agar bisa dipanggil sebelum definisinya
void tampil_data(const vec_mhs& daftar);

// Mengurutkan array Mahasiswa berdasarkan nama → Bubble Sort
void bubble_sort_mhs(vec_mhs& daftar) {
    int ukuran = daftar.size();

    for (int langkah = 0; langkah < ukuran - 1; ++langkah) {
        for (int i = 0; i < ukuran - langkah - 1; ++i) {
            // Bandingkan berdasarkan nama mahasiswa
            if (daftar[i].nama > daftar[i + 1].nama) {
                // Tukar posisi jika urutannya salah
                Mahasiswa temp = daftar[i];
                daftar[i] = daftar[i + 1];
                daftar[i + 1] = temp;
            }
        }
    }
}

// Mencari data di dalam vector Mahasiswa berdasarkan nama → Binary Search.
// Mengembalikan indeks jika ditemukan, dan -1 jika tidak ditemukan.
int binary_search_mhs(const vec_mhs& daftar, const std::string& nama_dicari) {
    int kiri  = 0;
    int kanan = daftar.size() - 1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2; // Cara ini lebih aman dari overflow

        // Bandingkan nama mahasiswa di posisi tengah dengan nama yang dicari
        if (daftar[tengah].nama == nama_dicari) {
            return tengah; // Data ditemukan, kembalikan indeksnya
        }
        else if (daftar[tengah].nama < nama_dicari) {
            kiri = tengah + 1; // Cari di sisi kanan
        }
        else {
            kanan = tengah - 1; // Cari di sisi kiri
        }
    }

    return -1; // Data tidak ditemukan
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

    tampil_data(daftar); // Tampilkan data agar user tahu nomornya

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

    tampil_data(daftar); // Tampilkan data agar user tahu nomornya

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

// Fungsi untuk menu Urutkan Data
void urutkan_data(vec_mhs& daftar) {
    if (daftar.empty()) {
        std::cout << "\nData masih kosong, tidak ada yang bisa diurutkan.\n";
        return;
    }

    bubble_sort_mhs(daftar);
    std::cout << "\nData berhasil diurutkan berdasarkan nama.\n";
    tampil_data(daftar); // Tampilkan data setelah diurutkan
}

// Fungsi untuk menu Cari Data
void cari_data(const vec_mhs& daftar) {
    if (daftar.empty()) {
        std::cout << "\nData masih kosong, tidak ada yang bisa dicari.\n";
        return;
    }

    std::cout << "\n═════ Cari Data Mahasiswa ═════\n";
    std::cin.ignore();
    std::string nama_dicari;
    std::cout << "Masukkan nama mahasiswa yang ingin dicari: ";
    std::getline(std::cin, nama_dicari);

    // PENTING: Beri peringatan bahwa binary search butuh data terurut
    std::cout << "(Peringatan: Pencarian paling akurat jika data sudah diurutkan!)\n";

    int indeks = binary_search_mhs(daftar, nama_dicari);

    if (indeks != -1) {
        std::cout << "Data ditemukan pada nomor " << indeks + 1 << ":\n";
        std::cout << "Nama: " << daftar[indeks].nama
                  << ", Mata Kuliah: " << daftar[indeks].matkul
                  << ", Nilai: " << daftar[indeks].ipk
                  << '\n';
    } else {
        std::cout << "Data dengan nama \"" << nama_dicari << "\" tidak ditemukan.\n";
    }
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
                  << "  5. Urutkan Data (Berdasarkan Nama)" << "\n"
                  << "  6. Cari Data (Berdasarkan Nama)"    << "\n"
                  << "  7. Keluar"       << "\n"
                  << "Masukkan Pilihan (1-7): ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1: tambah_data(daftar); break;
            case 2: tampil_data(daftar); break;
            case 3: ubah_data(daftar); break;
            case 4: hapus_data(daftar); break;
            case 5: urutkan_data(daftar); break;
            case 6: cari_data(daftar); break;
            case 7: std::cout << "Keluar...\n"; break;
            default: std::cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);

    return 0;
}