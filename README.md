
# struktur-data-h-praktikum-1-2021

## Genjil Ganap
### Verdict
AC saat praktikum

### Bukti
![acD](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/gg_bukti_ax.png)

**Mengerjakan saat praktikum dan AC saat revisi karena kesalahan testcase**

### Penjelasan Soal
Diminta mengurutkan mobil-mobil Roy dengan mobil plat genap di depan sedangkan plat ganjil di belakang untuk menghindari tilang.

### Penjelasan Solusi
Program menggunakan 4 stack yaitu `gjl`,`gnp`,`rev`, dan `urut`. Pertama program menginisialisasi keempat dengan fungsi `stack_init()` kemudian mengambil sebuah value `n` sebagai jumlah mobil. Sebanyak `n` kali program akan mengambil nomor plat mobil `plat` dan menumpukkan menggunakan `stack_pushBack()` pada salah satu dari stack `gjl` atau `gnp` tergantung apakah ganjil atau genap. 
Setelah itu, program memindahkan isi stack `gjl` satu-persatu ke stack `urut`. Setelah itu memindahkan isi stack `gnp` ke `rev` kemudian ke `urut`.
Setelah langkah ini selesai, stack `urut` mengandung urutan mobil yang urut dari atas stack ke bawah. Langkah terakhir mengeluarkan output stack `urut` dari atas.

### Visualisasi Solusi

Untuk mempermudah visualisasi solusi, digunakan sample input berikut:

```
5
1012
222
1001
1002
6969
```
![GGvisual](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/gg_visual1.png)

## Nadut & Cayo
### Verdict
AC saat praktikum
### Bukti
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/nadut_bukti_ac.png)

### Penjelasan Soal

### Penjelasan Solusi

### Visualisasi Solusi

## Malur Rajin
### Verdict
AC saat revisi
### Bukti
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/malur_bukti_ac.png)

### Penjelasan Soal

### Penjelasan Solusi

### Visualisasi Solusi

## Garasi Mobil Saha
### Verdict
AC saat revisi
### Bukti
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/garasi_bukti_ac.png)

### Penjelasan Soal

### Penjelasan Solusi

### Visualisasi Solusi

## Bread Problemo
### Verdict
AC saat revisi
### Bukti
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bread_bukti_ac.png)

### Penjelasan Soal

### Penjelasan Solusi

### Visualisasi Solusi

## Cari Tanah
### Verdict
AC saat revisi
### Bukti
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/ct_bukti_ac.png)

### Penjelasan Soal

### Penjelasan Solusi

### Visualisasi Solusi
