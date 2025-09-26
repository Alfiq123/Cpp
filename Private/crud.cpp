#include <iostream>
using namespace std;

int main() {
    string mahasiswa[100];
    int jumlah = 0, pilih, idx;
    string nama;

    do {
        cout << "\nMenu: \n1. Create\n2. Read\n3. Update\n4. Delete\n5. Exit\n";
        cout << "Pilih: "; 
        cin >> pilih;

        if (pilih == 1) {
            cout << "Nama: "; 
            cin >> nama;
            mahasiswa[jumlah++] = nama;
            cout << "Data berhasil ditambahkan!\n";
        }
        else if (pilih == 2) {
            cout << "\nData Mahasiswa:\n";
            for (int i = 0; i < jumlah; i++) {
                cout << i+1 << ". " << mahasiswa[i] << endl;
            }
        }
        else if (pilih == 3) {
            cout << "Index data: "; 
            cin >> idx;
            if (idx >= 1 && idx <= jumlah) {
                cout << "Nama baru: "; 
                cin >> nama;
                mahasiswa[idx-1] = nama;
                cout << "Data berhasil diupdate!\n";
            } else {
                cout << "Index tidak valid!\n";
            }
        }
        else if (pilih == 4) {
            cout << "Index data: "; 
            cin >> idx;
            if (idx >= 1 && idx <= jumlah) {
                for (int i = idx-1; i < jumlah-1; i++) {
                    mahasiswa[i] = mahasiswa[i+1];
                }
                jumlah--;
                cout << "Data berhasil dihapus!\n";
            } else {
                cout << "Index tidak valid!\n";
            }
        }
        else if (pilih == 5) {
            cout << "Program selesai.\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);

    return 0;
}
