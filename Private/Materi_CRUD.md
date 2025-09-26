# Tujuan Pembelajaran

- Mahasiswa memahami konsep dasar CRUD
- Mahasiswa dapat menuliskan kode C++ untuk setiap operasi CRUD
- Nahasiswa dapat mengembangkan program kecil berbasis array

## CRUD

- C: Create → Menambahkan data baru
- R: Read → Menampilkan data
- U: Update → Mengubah Data
- D: Delete → Menghapus data

## Contoh

- Create → Tambah kontak
- Read → Lihat Daftar Kontak
- Update → Edit nomor HP teman
- Delete → Hapus kontak yang sudah tidak dipakai

---

## Representasi dengan Array

```cpp
string mahasiswa[100]; // Simpan Data mahasiswa
int jumlah = 0;        // Hitung jumlah Data
```

## Operasi Create

```cpp
mahasiswa[jumlah] = "Ani";
jumlah++;
```

## Operasi Read

```cpp
for (int i = 0; i < jumlah; i++) {
    cout << i+1 << ". " << mahasiswa[i] << endl;
}
```
## Operasi Update

```cpp
int idx;
cout << "Data ke berapa yang mau diubah?";
cin >> idx;
mahasiswa[idx-1] = "NamaBaru";
```

## Operasi Delete

```cpp
int idx;
cout << "Data ke berapa yang mau dihapus?";
cin >> idx;
for (int i = idx-1; i < jumlah-1; i++) {
    mahasiswa[i] = mahasiswa[i+1];
}
jumlah--;
```

## Error yang sering terjadi

- Indeks keluar dari batas array
- Tidak menggeser data saat delete
- Tidak menambah variabel jumlah saat create

## Studi Kasus Tambahan

- CRUD daftar menu makanan di kantin
- CRUD jadwal kuliah
- CRUD daftar buku di perpustakaan

## Tugas Individu

- Buat program CRUD sederhana untuk data nilai mata kuliah

(Nama Matkul + nilai)
batasi jika nama matkul hanya boleh huruf saja, jika nilai hanya boleh angka saja