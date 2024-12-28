#include <iostream>    // Untuk input-output standar
#include <iomanip>     // Untuk format output (fixed, setprecision)
#include <chrono>      // Untuk mengukur waktu eksekusi

using namespace std;       // Menghindari penulisan std:: di setiap objek/kelas dari namespace std
using namespace chrono;    // Menghindari penulisan chrono:: di objek terkait pengukuran waktu

// Fungsi Iteratif untuk menghitung total pengeluaran
int hitungTotalIteratif(const int pengeluaran[], int ukuran) {
    int total = 0;                              // Inisialisasi total menjadi 0
    for (int i = 0; i < ukuran; i++) {          // Iterasi melalui setiap elemen array
        total += pengeluaran[i];                // Menambahkan nilai pengeluaran[i] ke total
    }
    return total;                               // Mengembalikan hasil total
}

// Fungsi Rekursif (dengan optimasi Tail Recursion) untuk menghitung total pengeluaran
int hitungTotalRekursif(const int pengeluaran[], int index, int total = 0) {
    if (index < 0) {                            // Basis rekursi: jika indeks negatif, kembalikan total yang sudah dihitung
        return total;
    }
                                                // Rekursi: tambahkan pengeluaran[index] ke total dan panggil fungsi dengan index - 1
    return hitungTotalRekursif(pengeluaran, index - 1, total + pengeluaran[index]);
}

int main() {
    const int ukuran = 40000;                           // Ukuran dataset (array pengeluaran) sebesar 10.000 elemen
    const int jumlahUlang = 100;                        // Jumlah pengulangan untuk pengukuran waktu (100 kali)

    int pengeluaran[ukuran];                            // Deklarasi array statis untuk menyimpan data pengeluaran
    cout << "Inisialisasi dataset...\n";                // Informasi awal untuk debugging
    for (int i = 0; i < ukuran; i++) {                  // Inisialisasi dataset
        pengeluaran[i] = 1000;                          // Setiap elemen diisi dengan nilai 1000
    }
    cout << "Dataset selesai.\n";                        // Konfirmasi bahwa dataset selesai dibuat

    // Mengukur waktu untuk algoritma iteratif
    cout << "Mulai iteratif...\n";                       // Informasi awal untuk iterasi
    auto startIteratif = high_resolution_clock::now();   // Mulai pencatatan waktu
    for (int i = 0; i < jumlahUlang; i++) {              // Ulangi penghitungan iteratif sebanyak jumlahUlang
        hitungTotalIteratif(pengeluaran, ukuran);        // Panggil fungsi iteratif
    }
    auto endIteratif = high_resolution_clock::now();     // Akhiri pencatatan waktu
    cout << "Iteratif selesai.\n";                       // Konfirmasi bahwa iterasi selesai

    // Mengukur waktu untuk algoritma rekursif
    cout << "Mulai rekursif...\n";                       // Informasi awal untuk rekursi
    auto startRekursif = high_resolution_clock::now();   // Mulai pencatatan waktu
    for (int i = 0; i < jumlahUlang; i++) {              // Ulangi penghitungan rekursif sebanyak jumlahUlang
        hitungTotalRekursif(pengeluaran, ukuran - 1);    // Panggil fungsi rekursif dengan indeks terakhir
    }
    auto endRekursif = high_resolution_clock::now();     // Akhiri pencatatan waktu
    cout << "Rekursif selesai.\n";                       // Konfirmasi bahwa rekursi selesai

    // Menghitung durasi eksekusi
    duration<double> durasiIteratif = endIteratif - startIteratif; // Durasi iteratif
    duration<double> durasiRekursif = endRekursif - startRekursif; // Durasi rekursif

    // Menampilkan hasil
    cout << fixed << setprecision(9);                    // Format output menjadi angka desimal dengan 9 digit presisi
    cout << "Waktu Eksekusi Iteratif: " << durasiIteratif.count() / jumlahUlang << " detik per eksekusi\n";
    // Menampilkan rata-rata waktu iteratif
    cout << "Waktu Eksekusi Rekursif: " << durasiRekursif.count() / jumlahUlang << " detik per eksekusi\n";
    // Menampilkan rata-rata waktu rekursif

    return 0;                                            // Mengakhiri program
}
