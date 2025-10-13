#include <iostream>
#include <string>

const int MAX_MAHASISWA = 100;

struct Mahasiswa {
    std::string nama;
    int nilai{};
};

void tampilkanMenu();
void traversal(const Mahasiswa arr[], int jumlahData);
void searching(const Mahasiswa arr[], int jumlahData);
void sorting(Mahasiswa arr[], int jumlahData);
void insertion(Mahasiswa arr[], int &jumlahData);
void deletion(Mahasiswa arr[], int &jumlahData);


int main() {
    Mahasiswa daftarMahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa = 0;

    daftarMahasiswa[0] = {"Budi", 85};
    daftarMahasiswa[1] = {"Ani", 92};
    daftarMahasiswa[2] = {"Candra", 78};
    daftarMahasiswa[3] = {"Dewi", 88};
    jumlahMahasiswa = 4;

    int pilihan;
    do {
        tampilkanMenu();
        std::cout << "Masukkan pilihan Anda: ";
        std::cin >> pilihan;
        std::cin.ignore();

        switch (pilihan) {
            case 1: traversal(daftarMahasiswa, jumlahMahasiswa); break;
            case 2: searching(daftarMahasiswa, jumlahMahasiswa); break;
            case 3: sorting(daftarMahasiswa, jumlahMahasiswa); break;
            case 4: insertion(daftarMahasiswa, jumlahMahasiswa); break;
            case 5: deletion(daftarMahasiswa, jumlahMahasiswa); break;
            case 0: std::cout << "Terima kasih! Program selesai." << "\n"; break;
            default: std::cout << "Pilihan tidak valid. Silakan coba lagi." << "\n";
        }

        std::cout << "\n";
    } while (pilihan != 0);

    return 0;
}


void tampilkanMenu() {
    std::cout << "════════════════════════════════════════" << "\n"
              << "      PROGRAM DATA NILAI MAHASISWA      " << "\n"
              << "════════════════════════════════════════" << "\n"
              << "1. Tampilkan Semua Data (Traversal)"      << "\n"
              << "2. Cari Data Mahasiswa (Searching)"       << "\n"
              << "3. Urutkan Data Mahasiswa (Sorting)"      << "\n"
              << "4. Tambah Data (Insertion)"               << "\n"
              << "5. Hapus Data (Deletion)"                 << "\n"
              << "0. Keluar"                                << "\n"
              << "────────────────────────────────────────" << "\n";
}

void traversal(const Mahasiswa arr[], int jumlahData) {
    std::cout << "\n─── Menampilkan Semua Data Mahasiswa ───" << "\n";
    if (jumlahData == 0) {
        std::cout << "Data masih kosong." << "\n";
        return;
    }
    for (int i = 0; i < jumlahData; ++i) {
        std::cout << i + 1 << ". Nama: " << arr[i].nama << ", Nilai: " << arr[i].nilai << "\n";
    }
}

void searching(const Mahasiswa arr[], int jumlahData) {
    std::string namaCari;
    std::cout << "\n─── Mencari Data Mahasiswa ───" << "\n";
    std::cout << "Masukkan nama yang ingin dicari: ";
    getline(std::cin, namaCari);

    bool ditemukan = false;
    for (int i = 0; i < jumlahData; ++i) {
        if (arr[i].nama == namaCari) {
            std::cout << "Data ditemukan pada posisi " << i + 1 << "!"          << "\n";
            std::cout << "Nama: " << arr[i].nama << ", Nilai: " << arr[i].nilai << "\n";
            ditemukan = true;
            break; // Hentikan pencarian setelah data pertama ditemukan
        }
    }

    if (!ditemukan) {
        std::cout << "Data dengan nama '" << namaCari << "' tidak ditemukan." << "\n";
    }
}

void sorting(Mahasiswa arr[], int jumlahData) {
    int pilihanUrut;
    std::cout << "\n─── Mengurutkan Data Mahasiswa ───"  << "\n"
              << "Pilih metode pengurutan:"              << "\n"
              << "  1. Dari kecil ke besar (Ascending)"  << "\n"
              << "  2. Dari besar ke kecil (Descending)" << "\n"
              << "Pilihan: ";
    std::cin >> pilihanUrut;

    for (int i = 0; i < jumlahData - 1; ++i) {
        for (int j = 0; j < jumlahData - i - 1; ++j) {
            bool harusTukar = false;
            // Ascending
            if (pilihanUrut == 1 && arr[j].nilai > arr[j + 1].nilai) { harusTukar = true; }
            // Descending
            else if (pilihanUrut == 2 && arr[j].nilai < arr[j + 1].nilai) { harusTukar = true; }

            if (harusTukar) {
                Mahasiswa temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    std::cout << "Data berhasil diurutkan!" << "\n";
    traversal(arr, jumlahData);
}


void insertion(Mahasiswa arr[], int &jumlahData) {
    if (jumlahData >= MAX_MAHASISWA) {
        std::cout << "Array sudah penuh. Tidak bisa menambah data." << "\n";
        return;
    }

    std::cout << "\n─── Menambahkan Data Mahasiswa Baru ───" << "\n";

    Mahasiswa mhsBaru;
    int posisi;

    std::cout << "Masukkan nama mahasiswa baru: "; getline(std::cin, mhsBaru.nama);
    std::cout << "Masukkan nilai mahasiswa baru: "; std::cin >> mhsBaru.nilai;

    std::cout << "Sisipkan pada posisi (1 - " << jumlahData + 1 << "): ";
    std::cin >> posisi;

    int index = posisi - 1;

    if (index < 0 || index > jumlahData) {
        std::cout << "Posisi tidak valid." << "\n";
        return;
    }

    for (int i = jumlahData; i > index; --i) {
        arr[i] = arr[i - 1];
    }

    arr[index] = mhsBaru;
    jumlahData++;

    std::cout << "Data berhasil ditambahkan!" << "\n";
    traversal(arr, jumlahData);
}


void deletion(Mahasiswa arr[], int &jumlahData) {
    if (jumlahData == 0) {
        std::cout << "Data masih kosong. Tidak ada yang bisa dihapus." << "\n";
        return;
    }

    std::string namaHapus;
    std::cout << "\n─── Menghapus Data Mahasiswa ───" << "\n";
    std::cout << "Masukkan nama yang ingin dihapus: ";
    getline(std::cin, namaHapus);

    int indexHapus = -1;
    for (int i = 0; i < jumlahData; ++i) {
        if (arr[i].nama == namaHapus) {
            indexHapus = i;
            break;
        }
    }

    if (indexHapus == -1) {
        std::cout << "Data dengan nama '" << namaHapus << "' tidak ditemukan." << "\n";
    } else {
        for (int i = indexHapus; i < jumlahData - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        jumlahData--;
        std::cout << "Data berhasil dihapus!" << "\n";
        traversal(arr, jumlahData);
    }
}