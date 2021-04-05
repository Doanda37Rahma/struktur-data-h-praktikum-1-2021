
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
Program menggunakan algoritma pemrograman berbasis stack. Program menggunakan 4 stack yaitu `gjl`,`gnp`,`rev`, dan `urut`. Pertama program menginisialisasi keempat dengan fungsi `stack_init()` kemudian mengambil sebuah value `n` sebagai jumlah mobil. Sebanyak `n` kali program akan mengambil nomor plat mobil `plat` dan menumpukkan menggunakan `stack_pushBack()` pada salah satu dari stack `gjl` atau `gnp` tergantung apakah ganjil atau genap. 
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
Diminta menentukan susunan blok angka tertinggi dengan syarat jika ada blok angka yang lebih besar dibanding blok sebelumnya maka blok angka sebelumnya harus dikeluarkan dari tumpukan.
### Penjelasan Solusi
Program menggunakan algoritma berbasis stack. Untuk setiap testcase, program pertama mengambil input `blockCount` setiap input dimasukkan ke dalam variabel `block` yang akan dimasukkan ke stack `blocks`. Jika `block` lebih besar daripada elemen paling atas stack (mengecek menggunakan `stack_top()`), maka elemen stack dihilangkan dengan `stack_pop` sampai tidak lebih besar atau stack kosong, setelah itu ditumpuk di stack dengan `stack_pushBack()`. 
```
int main(int argc, char const *argv[])
{
    Stack blocks;
    Stack revB;

    stack_init(&blocks);
    stack_init(&revB);

	int testc,
		blockCount, 
		block;
	int i=0;
	scanf("%d", &testc);
	for (; i<testc; i++)
	{
		int j=0;
		scanf("%d", &blockCount);
		for (; j<blockCount; j++)
		{
			scanf("%d", &block);
			while (!stack_isEmpty(&blocks) && stack_top(&blocks) < block) {
				stack_pop(&blocks);
			}
			stack_push(&blocks, block);
		}

```
Kemudian stack `blocks` dipindah ke `revB` agar urutan output tepat. Setiap akhir testcase program mengeluarkan output kedua stack dikosongkan.
```
		while (!stack_isEmpty(&blocks)) {
			stack_push(&revB, stack_top(&blocks));
			stack_pop(&blocks);
		}
		printf("Susunan blok yang disusun Nadut dan Cayo adalah : ");
	    while (!stack_isEmpty(&revB)) {
	        printf("%d ", stack_top(&revB));
	        stack_pop(&revB);
	    }
		puts("");

		while (!stack_isEmpty(&blocks)) {
			stack_pop(&blocks);
		}
	    while (!stack_isEmpty(&revB)) {
	        stack_pop(&revB);
	    }		
	}
		
    return 0;
}
```

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
