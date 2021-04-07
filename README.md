
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

INPUT
```
5
1012
222
1001
1002
6969
```
OUTPUT
```
Urutan Mobil Roy : 1002 222 1012 1001 6969
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
Kemudian stack `blocks` dipindah ke `revB` agar urutan output tepat. Setiap akhir testcase program mengeluarkan output lalu kedua stack dikosongkan.
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
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/nadut_2.png)

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
Program diberikan garasi mobil dengan informasi banyak mobil, kapasitas, dan waktu masuk/keluar mobil.
Program diminta menentukan apakah mobil pertama dapat keluar, tanpa dihalangi oleh mobil lain/mobil masuk tidak memenuhi garasi melebihi kapasitas.
Garasi Saha tidak memungkinkan sebuah mobil atau lebih masuk pada waktu yang sama atau keluar pada waktu yang sama tapi memungkinkan lebih dari 1 mobil masuk dan keluar pada waktu yang sama. 
### Penjelasan Solusi
Program menggunakan priority queue yang berisi `masuk` dan `keluar` sebagai waktu mobil masuk dan keluar, untuk mengurutkan waktu masuk mobil.
Pertama, program menginisialisasi pqueue `cars`, lalu mengambil input `testc` (banyak testcase). 
```
int main(int argc, char const *argv[])
{
   PriorityQueue cars;
   pqueue_init(&cars);
   int testc;
   int carCount,
   cap,
   timeIn,
   timeOut,
   renov;
    
   scanf("%d", &testc);

```
Untuk setiap testcase:
1. Program mengambil input `timeIn` dan `timeOut` lalu memasukkan ke pqueue. 
```
    int i=0;
    for (; i<testc; i++)
    {
		scanf("%d%d", &carCount ,&cap);
    	int j=0;
    	for (; j<carCount; j++) {
    		scanf("%d%d", &timeIn,&timeOut);
    		pqueue_push(&cars, timeIn, timeOut);
		}

```
2. Kemudian, program mengurutkan waktu keluar mobil dalam pqueue untuk mobil-mobil dengan waktu masuk sama (karena 2 mobil boleh masuk dan keluar bersamaan) melalui fungsi `pqueue_sortCars()` (sebagai 'just in case').
3. Selanjutnya, program menentukan apakah garasi butuh renovasi melalui fungsi `pqueue_needRenov()` dan mengeluarkan `Hmm harus renovasi garasi nich` jika TRUE dan `Hore gausah renov garasi` jika FALSE.
```
		if (pqueue_needRenov(&cars))
			printf("Hmm harus renovasi garasi nich\n");
		else
			printf("Hore gausah renov garasi\n");

```
4. Program mengosongkan pqueue.
```
	    while (!pqueue_isEmpty(&cars)) {
	        pqueue_pop(&cars);
	    }
	}
    return 0;
}
```
#### Fungsi pqueue_sortCars()
Fungsi ini melakukan traverse melalui setiap node dalam pqueue dan setiap kali `masuk` dalam node sama dengan node selanjutnya, fungsi akan meng-swap `keluar` dari kedua node jika `keluar` dari node lebih dari node berikutnya.
```
void pqueue_sortCars(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp;
        temp = pqueue->_top;
		
	int tempval;
        while (temp->next != NULL) {
		if (temp->masuk == temp->next->masuk) {
			if (temp->keluar > temp->next->keluar) {
				tempval = temp->keluar;
				temp->keluar = temp->next->keluar;
				temp->next->keluar = tempval;
			}
		}
		temp = temp->next;
        }
    }
}
```
#### Fungsi pqueue_needRenov()
Fungsi ini sebagai fungsi bool utama untuk menentukan output program, mengembalikan 1 jika garasi perlu renovasi, 0 jika tidak. Fungsi akan menemukan salah satu dari case-case berikut:
1. Jika waktu keluar mobil pertama lebih kecil atau sama dengan waktu masuk mobil kedua, maka keluar 0.
2. Jika saat traverse waktu masuk dan keluar sebuah mobil sama, maka keluar 1.
3. Jika saat traverse menemukan mobil setelah mobil pertama yang masuk sebelum mobil pertama keluar DAN keluar setelah mobil pertama (yang berarti mobil pertama tidak bisa keluar), maka keluar 1.
4. Jika traverse selesai (berarti mobil pertama bisa keluar), maka keluar 0.
```
int  pqueue_needRenov(PriorityQueue *pqueue) {
    PQueueNode *temp = pqueue->_top;
    if (temp->masuk == temp->keluar) return 1;
    if (temp->keluar <= temp->next->masuk) return 0;
    while ( temp->next != NULL ) {
		if (temp->next->masuk == temp->next->keluar) return 1;

		temp = temp->next;
        if ((temp->masuk >= pqueue->_top->masuk && 
			 temp->masuk < pqueue->_top->keluar) &&
			 temp->keluar > pqueue->_top->keluar)
			return 1;
	}
	return 0;
}
```
### Visualisasi Solusi
INPUT 1:
```
1
2 1
1 5
3 8
```
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/garasi1.png)

OUTPUT 1:
```
Hmm harus renovasi garasi nich
```
Disini mobil pertama tidak bisa keluar karena saat mobil pertama ingin keluar, mobil kedua masih belum keluar, maka harus renovasi garasi (lihat kemungkinan 3 `Fungsi pqueue_sortCars()` di atas).

INPUT 2:
```
2
6 6
1 11
2 10
3 9
4 8
5 7
6 6
3 2
1 2
4 5
3 6
```
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/garasi2.png)

OUTPUT 2:
```
Hmm harus renovasi garasi nich
Hore gausah renov garasi
```
Dalam case 1, mobil 6 masuk dan keluar bersamaan, yang tidak diperbolehkan. maka harus renovasi. (kemungkinan 2)
Dalam case 2, mobil 1 masuk dan bisa keluar terlebih dahulu, maka tidak harus renovasi (kemungkinan 1).

## Bread Problemo
### Verdict
AC saat revisi
### Bukti
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bread_bukti_ac.png)

### Penjelasan Soal
Program diberikan tumpukan awal roti Ray sebanyak n (1-n dari atas) dan roti kakaknya kosong. Program diminta memindahkan satu-persatu roti dari satu tumpukan roti ke yang lainnya. Pada akhirnya, program diminta mengeluarkan output tumpukan roti Ray dan kakanya, serta output yang bervariasi tergantung tumpukan mana yang lebih banyak/tumpukan kosong/input salah. 
### Penjelasan Solusi
Program menggunakan struktur data stack. Terdapat 2 stack, yaitu tumpukan roti Ray dan kakaknya. Pertama, program menginisialisasi kedua stack, lalu mengambil input `N`, banyaknya roti si awal tumpukan Ray, dan `T` banyaknya testcase. Apabila `N` kurang dari 1, maka mengeluarkan `Ray SangaT MaraH!`. Kemudian, program memasukkan angka `N` sampai `1` ke dalam stack `ray` Tiap testcase, program mengambil input `a` dan `b` dimana `a=1` berarti memindahkan roti sebanyak `b` (satu-persatu) dari stack `ray` ke stack `kakak` . Jika `a=2`, artinya memindahkan roti dari stack `kakak` ke stack `ray`. Jika `a` bukan 1 atau 2, maka program mengeluarkan `TumpukAnnya saLah! :(`.
```
int main(int argc, char const *argv[])
{
    Stack ray;
    Stack kakak;
 
    stack_init(&ray);
    stack_init(&kakak);
    
    int N, T, a, b;
    
    scanf("%d", &N);
    scanf("%d", &T);
    
    if (N<1) {
    	printf("Ray SangaT MaraH!\n");
    	return 0;
	}
	
    int i, j;
    for (i=N; i>0; i--) {
    	stack_push(&ray, i);
	}
    for (i=0; i<T; i++)
    {
    	scanf("%d%d", &a, &b );
    	if (a==1) {
    		for (j=0; j<b && !stack_isEmpty(&ray); j++) {
				stack_push(&kakak, stack_top(&ray));
				stack_pop(&ray);	    		
			}
		} else if (a==2) {
    		for (j=0; j<b && !stack_isEmpty(&kakak); j++) {
				stack_push(&ray, stack_top(&kakak));
				stack_pop(&kakak);	    					
			}
		} else {
			printf("TumpukAnnya saLah! :(\n");
			return 0;
		}
	}

```
Setelah itu, program mengeluarkan tumpukan teratas dari stack `ray` dan `kakak` (dipisah dengan spasi) sampai kedua stack kosong. Jika `ray` kosong terlebih dahulu, maka program mengeluarkan `-` (hanya sekali). Sebaliknya, jika `kakak` kosong terlebih dahulu, mengeluarkan `:(`.
```
	int rayE=0, kakakE=0; 
	
	while (!stack_isEmpty(&ray) || !stack_isEmpty(&kakak)) {
		if (!stack_isEmpty(&ray)) {
			printf("%d ", stack_top(&ray));
			stack_pop(&ray);
		} else {
			rayE+=1;
		}
		if (rayE>0) {
			printf("- ");
			rayE=-10000;
		} else if (rayE < 0) {
			printf(" ");
		}
		if (!stack_isEmpty(&kakak)) {
			printf("%d", stack_top(&kakak));
			stack_pop(&kakak);
		} else {
			kakakE+=1;
		}
		if (kakakE>0) {
			printf(":(");
			kakakE=-10000;
		}
		putchar('\n');
	}
	
    return 0;
}

```
### Visualisasi Solusi
Contoh INPUT:

```
5
5
1 1
1 2
1 1
2 1
2 2
```
OUTPUT

```
2 1
3 :(
4
5
```
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/bread1.png)

## Cari Tanah
### Verdict
AC saat revisi
### Bukti
![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/ct_bukti_ac.png)

### Penjelasan Soal
Program diberikan suatu 2d array dengan value 1 atau 0.
Program diminta menentukan apakah terdapat luas yang terbentuk dari 0 minimal sebesar `x`.
### Penjelasan Solusi
Program menggunakan konsep histogram untuk mencari luas. Untuk setiap baris dari 2d array, ada baris histogram yang berisi tinggi (banyaknya 0 untuk tiap kolom, dihitung sejak baris pertama atau baris setelah baris bervalue 1 jika menemukan) tiap kolom. Implementasinya seperti berikut:
Misal input 2d array berukuran 5x5 dan misal minimal area adalah `5`. Pertama, program mengambil tiap input sebagai char dan mengubahnya menjadi int:
```
		scanf("%d%d\n", &p, &l);
		for (j=0; j<p; j++) {
			
			for (k=0; k<l; k++){
				c = getchar();
				if (k==l-1 && j!= p-1) scanf("\n");
				arr[j][k] = (int)c - '0';
			}
		}

```

INPUT:

```
1 5
5 5
11100
00100
00001
00011
11100
```
Kemudian mengubah setiap 0 menjadi 1 dan sebaliknya (karena lebih baik melakukan increment untuk tiap value 1 untuk mencari nilai data pada histogram).

```
		for (j=0; j<p; j++) {
			for (k=0; k<l; k++) {
				if (arr[j][k]) arr[j][k] = 0;
				else arr[j][k] = 1; 
			}
		}

```
```
00011
11011
11110
11100
00011
```
Kemudian hasil histogram:
```
		for (j=0; j<p; j++) {
			if (j) {
				for (k=0; k<l; k++) {
					if (arr[j][k]) arr[j][k] += arr[j-1][k];
				}
			}
		}

```
```
00011
11022
22130
33200
00011
```
Setelah mendapat kelima baris histogram, program menggunakan fungsi `maxHist()` (https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/) untuk menghitung luas maksimum yang ditemukan pada tiap baris histogram. Setelah itu, maka akan ditemukan:
```
		int ada = 0;
		for (j=0; j<p; j++) {
			if (maxHist(arr[j], l) > min) ada =1; 
		}
	
		if (ada) printf("IYA\n");
		else printf("TIDAK\n");	

```
```
Area max baris 1: 2
Area max baris 2: 4
Area max baris 3: 4
Area max baris 4: 6
Area max baris 5: 2
```
Maka ditemukan pada histogram ke-4, max areanya (6) melebihi minimal area (5) sehingga `maxHist()` mengembalikan TRUE dan program mengeluarkan output `IYA`. Jika terjadi sebaliknya, maka program mengeluarkan output `TIDAK` 
### Visualisasi Solusi
Dilihat pada histogram ke-4: 

![nc](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-1-2021/blob/main/img/caritanah1.png)

Ditemukan luas maksimal 6
