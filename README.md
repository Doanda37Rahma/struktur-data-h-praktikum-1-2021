
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
Untuk membantu visualisasi program, akan digunakan contoh input
```
1
5
5 4 7 2 1
```
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/nadut_1.png)
Output:
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```

## Malur Rajin
### Verdict
AC saat revisi
### Bukti
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/malur_bukti_ac.png)

### Penjelasan Soal
Diberikan informasi tumpukan buku dengan data relevan jumlah soal tersisa dan nama buku. Program diminta menentukan jumlah buku yang malur harus pisahkan dengan diikuti nama buku dengan soal tersisa paling sedikit tiap kali input memberikan perintah -1.
### Penjelasan Solusi
Program menggunakan 2 tipe data, yaitu stack dan priority queue. Stack `books` digunakan untuk menyimpan soal tersisa dan nama buku, sedangkan priority queue `pBooks` untuk mengurutkan soal tersisa tiap buku demi menentukan yang paling sedikit.
```
int main(int argc, char const *argv[])
{
    Stack books;
    stack_init(&books);

    PriorityQueue pBooks;
    pqueue_init(&pBooks);
...
```
Pertama, program mengambil input angka `num`. Ada 3 kemungkinan: jika `num` positif, maka itu adalah banyak soal tersisa dan bersama dengan nama buku ditumpuk ke `books`, sedangkan `num` dimasukkan ke `pBooks`, jika `num` nol maka tidak ada soal tersisa dan tidak dimasukkan ke stack.
Jika `num` adalah `-1` maka program mencari buku dengan soal paling sedikit dengan mengecek apakah top of stack sama dengan top of pqueue. Setiap kali tidak cocok, program menghilangkan satu persatu tumpukan stack dengan `stack_pop()` dan menghilangkan banyak soal tersisa milik stack yang dihapus dari pqueue menggunakan `pqueue_remove()`. Program juga menghitung tiap kali  tumpukan dihilangkan dengan `moveCount`. setelah menemukan yang dicari, program akan mengeluarkan output banyak buku yang dihilangkan dan nama buku yang dicari.
```
	int testc,
		num,
		moveCount;
	char buku[LEN];

	scanf("%d", &testc);
	
	moveCount = 0;
	int i = 0;
	for (; i<testc; i++)
	{
		scanf("%d", &num);
		if (num > 0) {
			scanf("%s", buku);
			stack_push(&books, num, buku);
			pqueue_push(&pBooks, num);
		} else if (num == 0) {
			scanf("%s", buku);
		} else if (num < 0) {
			if (!stack_isEmpty(&books)) {
				while (!stack_isEmpty(&books) && 
						pqueue_top(&pBooks) != stack_top(&books)) {
					moveCount++;
					pqueue_remove(&pBooks, stack_top(&books));
					stack_pop(&books);
				}
				if (stack_top(&books)) {
					printf("%d %s\n", moveCount, stack_topMapel(&books));
					stack_pop(&books);
					pqueue_pop(&pBooks);
				}
				moveCount = 0;
			}
		}
	}
```
### Visualisasi Solusi
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/malur_1.png)

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
Program diberikan tumpukan awal roti Ray sebanyak n (1-n dari atas) dan roti kakaknya kosong. Program diminta memindahkan satu-persatu roti dari satu tumpukan roti ke yang lainnya. Pada akhirnya, program diminta mengeluarkan output tumpukan roti Ray dan kakanya, serta output yang bervariasi tergantung tumpukan mana yang lebih banyak/tumpukan kosong/input salah. 
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
