
```markdown
# Perbandingan Efisiensi Algoritma Iteratif dan Rekursif

## Deskripsi
Program ini membandingkan efisiensi dua algoritma, yaitu **iteratif** dan **rekursif**, dalam menghitung total pengeluaran dari sebuah dataset besar. Program ini mengukur waktu eksekusi rata-rata untuk kedua metode menggunakan dataset statis dan mencetak hasilnya.

## Fitur
- **Iteratif**: Menggunakan perulangan (`for loop`) untuk menghitung total pengeluaran.
- **Rekursif**: Menggunakan pemanggilan fungsi rekursif dengan optimasi tail recursion.
- Mengukur waktu eksekusi untuk setiap metode menggunakan library `<chrono>`.
- Menghasilkan rata-rata waktu eksekusi per metode dalam satuan detik.

## Prasyarat
- **Compiler C++**: Pastikan Anda memiliki compiler modern seperti GCC atau Clang dengan dukungan C++11 atau lebih tinggi.
- **Library Standar C++**: Program ini menggunakan `<iostream>`, `<iomanip>`, dan `<chrono>`.

## Cara Menjalankan
1. **Kompilasi Program**:
   Gunakan perintah berikut di terminal:
   ```bash
   g++ -o perbandingan_algoritma perbandingan_algoritma.cpp -std=c++11
   ```
2. **Jalankan Program**:
   Jalankan file yang telah dikompilasi:
   ```bash
   ./perbandingan_algoritma
   ```

## Penjelasan Kode
### **1. Fungsi Utama**
- **hitungTotalIteratif**: Fungsi iteratif yang menggunakan perulangan `for` untuk menghitung total elemen array.
- **hitungTotalRekursif**: Fungsi rekursif dengan tail recursion yang menggunakan parameter tambahan `total` untuk menyimpan hasil perhitungan.

### **2. Proses Utama**
1. **Inisialisasi Dataset**: Membuat array statis `pengeluaran` berisi elemen dengan nilai tetap (1000).
2. **Pengukuran Waktu**:
   - **Iteratif**: Menghitung total menggunakan fungsi iteratif sebanyak `jumlahUlang` kali.
   - **Rekursif**: Menghitung total menggunakan fungsi rekursif sebanyak `jumlahUlang` kali.
3. **Hasil**:
   Program mencetak rata-rata waktu eksekusi untuk setiap metode dengan presisi hingga 9 digit desimal.

## Output
Program akan menghasilkan output seperti berikut:
```
Inisialisasi dataset...
Dataset selesai.
Mulai iteratif...
Iteratif selesai.
Mulai rekursif...
Rekursif selesai.
Waktu Eksekusi Iteratif: 0.000070003 detik per eksekusi
Waktu Eksekusi Rekursif: 0.000129959 detik per eksekusi
```

## Pengaturan
- **Ukuran Dataset**: Anda dapat mengubah ukuran dataset dengan mengubah nilai konstanta `ukuran` di kode:
  ```cpp
  const int ukuran = 40000;
  ```
- **Jumlah Pengulangan**: Anda dapat mengubah jumlah pengulangan untuk akurasi pengukuran waktu dengan mengubah nilai `jumlahUlang`:
  ```cpp
  const int jumlahUlang = 100;
  ```

## Kesimpulan
- **Iteratif** lebih efisien pada dataset besar karena tidak memiliki overhead pemanggilan stack.
- **Rekursif** lebih intuitif dan cocok untuk dataset kecil, tetapi rentan terhadap stack overflow pada dataset besar.

## Catatan
- Pastikan perangkat Anda memiliki memori yang cukup untuk menjalankan dataset besar.
- Gunakan dataset yang lebih kecil jika terjadi stack overflow pada metode rekursif.
``` 
