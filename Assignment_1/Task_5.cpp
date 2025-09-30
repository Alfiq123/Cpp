#include <iostream>
#include <string>

// ## Tugas Individu

// - Buat program CRUD sederhana untuk data nilai mata kuliah

// (Nama Matkul + nilai)
// batasi jika nama matkul hanya boleh huruf saja, jika nilai hanya boleh angka saja

std::string nama_matkul[100];
std::string nilai_matkul[100];

// Fungsi → Menampilkan Semua Pilihan
void tampilkan_menu() {
    std::cout << "───── PROGRAM DATA NILAI MATA KULIAH ───── \n\n"
         << "  1. Create  \n"
         << "  2. Read    \n"
         << "  3. Update  \n"
         << "  4. Delete  \n"
         << "  5. Exit    \n\n";
}

// Fungsi → Membuat Data Baru → CREATE
void create_data() {
    std::cout << "\n───── TAMBAH DATA BARU ───── \n\n";

    std::cout << "Masukkan Nama Mata Kuliah: ";

}

// Fungsi → Membaca Data → READ
void read_data() {
    std::cout << "\n───── DAFTAR NILAI MATA KULIAH ─────\n";
}

// Fungsi → Memperbarui Data → UPDATE
void update_data() {
    std::cout << "\n───── MEMPERBARUI DATA ─────\n";
}

// Fungsi → Menghapus Data → DELETE
void delete_data() {
    std::cout << "\n───── MENGHAPUS DATA ─────\n";
}

int main() {
    struct DataMahasiswa {
        std::string nama_matkul;
        int nilai;
    };

    std::string data_mahasiswa[100];
    tampilkan_menu();
    int userInput;
    std::cout << "Masukkan Pilihan Kamu: ";
    std::cin  >> userInput;

    // Validasi Inputan User
    if      (userInput == 1) { create_data(); }
    else if (userInput == 2) { read_data(); }
    else if (userInput == 2) { update_data(); }
    else if (userInput == 4) { delete_data(); }
    else (exit);

    return 0;
}
