# A - Kafe Programmer

| Time Limit   | $1$s     |
|--------------|--------|
| Memory Limit | $1536$MB |

Arif adalah seorang mahasiswa yang membuka usaha kafe di kantin teknik UGM. Hari ini partner kerjanya sakit padahal pembeli yang datang justru sedang membludak. Karena hari ini dia bekerja seorang diri, dia juga tidak bisa melayani pembeli lainnya sebelum pesanan pembeli sebelumnya selesai dihidangkan. Arif pun memutar otak, dia ingin meminimalisir rata-rata waktu tunggu setiap pembeli. Setiap makanan dan minuman yang dibeli membutuhkan waktu yang berbeda untuk dihidangkan. Misalkan terdapat $3$ orang pembeli yang datang berturut-turut pada menit ke $0$, ke $1$, dan ke $2$, dan waktu yang dibutuhkan untuk menghidangkan pesanan tersebut berturut-turut adalah selama $3$, $9$, dan $6$ menit.

Jika Arif menggunakan prinsip yang pertama datang yang pertama dilayani, maka waktu tunggu pembeli tersebut berturut-turut adalah $3$, $11$, dan $16$ menit.

Rata-rata waktu tunggu ketiga pembeli tersebut adalah $\frac{3+11+16}{3} = 10$. Ini bukanlah waktu tunggu minimal.

Jika Arif melayani pembeli pertama kemudian pembeli ketiga terlebih dahulu baru terakhir pembeli kedua, maka waktu tunggu ketiganya berturut-turut adalah $3$, $7$, dan $17$ menit. Rata-rata waktu tunggu ketiganya menjadi $\frac{3 + 7 + 17}{3} = 9$.

Bantulah Arif menemukan rata-rata waktu tunggu minimum dari setiap pembeli yang datang.

## Input

Baris pertama berupa bilangan $N$ yang merupakan banyaknya pembeli yang datang.

Baris ke $N$selanjutnya, berisi nilai $T$ dan $L$ dipisahkan dengan spasi. $T$ adalah waktu ketika pembeli memesan makanan atau minuman. $L$ adalah lama waktu yang dibutuhkan untuk memasak makanan.

## Output

Menampilkan rata-rata waktu tunggu minimum dalam bentuk integer

## Batasan

- $1 \leq N \leq 10^5$
- $0 \leq T \leq 10^9$
- $1 \leq L \leq 10^9$

## Sample Input 1

	3
	0 3
	1 9
	2 5

## Sample Output 1

	8


<br>
<br>