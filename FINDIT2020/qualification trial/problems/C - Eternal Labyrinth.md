# C - Eternal Labyrinth

| Time Limit   | $1$s     |
|--------------|--------|
| Memory Limit | $1536$MB |

Diky adalah seorang mahasiswa yang suka menjelajah. Suatu hari dia menemukan suatu labirin yang unik. Labirin itu memiliki dimensi $R \times C$. Dalam labirin terdapat jalan yang dapat dilewati dan jalan yang diblok. Untuk setiap jalan yang dapat dilewati disimbolkan dengan angka $0$ dan untuk jalan yang diblok di simbolkan dengan angka $-1$. Bantulah Diky mencari semua kombinasi jalan keluar labirin tanpa melewati jalan yang diblok!

## Keterangan

- Titik awal terdapat dibaris $1$ kolom $1$ dari matriks labirin. Tujuan akhir terdapat dibagian paling kanan-bawah dari labirin. Diky hanya bisa bergerak ke kanan dan kebawah!
- Apabila titik awal dan tujuan akhir bernilai $-1$ maka tidak ada jalan keluar yang tersedia

## Input

- Baris pertama berisi $R$ dan $C$, yaitu jumlah baris dan kolom dari matriks labirin 
- $R$ baris selanjutnya adalah matriks labirin dengan kolom sebanyak $C$.

## Output

Sebuah integer yang menunjukkan banyak kombinasi jalan dari titik awal ke titik tujuan.

## Sample Input 1

	3 3
	0 0 0
	0 -1 0
	0 0 0

## Sample Output 1

	2

## Penjelasan

Terdapat matriks $3 \times 3$ yang berisi $-1$ di entry $2,2$ dan $0$ di entry lainnya. Hanya ada $2$ kombinasi jalan dari kiri atas ke kanan bawah yaitu kanan-kanan-bawah-bawah dan bawah-bawah-kanan-kanan


<br>
<br>