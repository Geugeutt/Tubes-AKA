**Analisis Perbandingan Algoritma Backtracking Rekursif dan Iteratif**

Repository ini berisi implementasi dan analisis perbandingan algoritma
backtracking rekursif dan backtracking iteratif untuk menyelesaikan
permasalahan N-Queens. Analisis difokuskan pada perbandingan kompleksitas
waktu dan performa runtime kedua pendekatan.

Proyek ini merupakan bagian dari Tugas Besar mata kuliah
Analisis Kompleksitas Algoritma.
- Bahasa Pemrograman: C++
- Compiler: g++

## Struktur File
- `main.cpp`  
  Program utama untuk menjalankan algoritma dan mengukur runtime.
- `rekursif.cpp`, `rekursif.hpp`  
  Implementasi algoritma backtracking rekursif.
- `iteratif.cpp`, `iteratif.hpp`  
  Implementasi algoritma backtracking iteratif (menggunakan stack manual).
- `hasil_runtime.csv`  
  Data hasil pengukuran waktu eksekusi untuk analisis dan visualisasi.

## Cara Kompilasi dan Menjalankan
Gunakan perintah berikut pada terminal:
g++ main.cpp rekursif.cpp iteratif.cpp -o nqueens
./nqueens
