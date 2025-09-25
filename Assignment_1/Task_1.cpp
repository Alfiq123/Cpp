#include <iostream>
#include <string>
using namespace std;

// "Struktur" untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
};

int main() {
    const int JUMLAH = 5;       // jumlah mahasiswa
    Mahasiswa daftar[JUMLAH];   // `array` untuk simpan data

    // Input data mahasiswa
    for (int i = 0; i < JUMLAH; i++) {
        cout << "Mahasiswa ke-" << i+1 << ":\n";
        cout << "Nama: ";
        cin >> daftar[i].nama;
        cout << "Umur: ";
        cin >> daftar[i].umur;
        cout << "IPK: ";
        cin >> daftar[i].ipk;
    }

    // Hitung rata-rata IPK
    float total = 0;
    for (int i = 0; i < JUMLAH; i++) {
        total += daftar[i].ipk;
    }
    float rata = total / JUMLAH;

    // Mencari mahasiswa dengan IPK tertinggi
    int indeksMaks = 0;
    for (int i = 1; i < JUMLAH; i++) {
        if (daftar[i].ipk > daftar[indeksMaks].ipk) {
            indeksMaks = i;
        }
    }

    // Output hasil
    cout << "\nRata-rata IPK: " << rata << endl;
    cout << "Mahasiswa dengan IPK tertinggi:\n";
    cout << "Nama: " << daftar[indeksMaks].nama << endl;
    cout << "Umur: " << daftar[indeksMaks].umur << endl;
    cout << "IPK: " << daftar[indeksMaks].ipk << endl;

    return 0;
}
