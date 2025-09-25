#include <iostream>
using namespace std;

struct Pasien {
    string nama;
    int umur;
    string keluhan;
};

int main() {
    Pasien daftar[3];  // array statis, fix 3 pasien

    for (int i = 0; i < 3; i++) {
        cout << "Pasien ke-" << i+1 << endl;
        cout << "Nama     : ";
        getline(cin, daftar[i].nama);

        cout << "Umur     : ";
        cin >> daftar[i].umur;
        cin.ignore(); // buang newline

        cout << "Keluhan  : ";
        getline(cin, daftar[i].keluhan);
        cout << endl;
    }

    cout << "=== Data Pasien ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i+1 << ". " << daftar[i].nama
             << " (" << daftar[i].umur << " tahun)"
             << " - Keluhan: " << daftar[i].keluhan << endl;
    }
}
