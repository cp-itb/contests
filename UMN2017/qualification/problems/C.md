# C - Ledakan Terbesar

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 512MB |

## Deskripsi

Sedang terjadi perang antara Negara Api dan Negara Bumi, Negara Api menyerang Negara Bumi dengan bola-bola api sehingga Negara Bumi mengalami kerusakan dimana-mana. Serangan bola api tersebut menyebabkan bekas ledakan di tanah Negara Bumi. Jendral dari Negara Bumi ingin mengetahui kerusakan terbesar yang disebabkan oleh bola-bola api tersebut. Anda diberikan peta kerusakan Negara Bumi, dengan format sebagai berikut.

- Karakter '*' menunjukkan daerah yang rusak
- Karakter '.' menunjukkan daerah yang tidak rusak

Daerah yang dihitung termasuk dalam 1 kerusakan yaitu daerah yang bersebelahan (atas, kiri, kanan, bawah). Peta yang diberikan memiliki ukuran R * C. Tentukan kerusakan terbesar yang
dialami oleh Negara Bumi.

## Format Masukan

Baris pertama berisi sebuah integer T, banyaknya kasus uji untuk soal ini.
Untuk tiap kasus uji akan diawali dengan 2 bilangan R dan C.
Kemudian di ikuti R baris input, yang masing-masing terdiri dari C karakter

## Format Keluaran

Untuk setiap kasus uji, keluarkan kerusakan terbesar dengan format berikut.
Case #c: Y
dimana c adalah nomor urut kasus (dimulai dari 1), dan Y merupakan kerusakaan terbesar yang
terjadi di Negara Bumi.

## Contoh Masukan

	2
	5 4
	.*..
	.**.
	....
	..*.
	*...
	4 7
	.*..*..
	***..*.
	*.*..*.
	....*.*

## (Salah Satu Cara) Contoh Keluaran

	Case #1: 3
	Case #2: 6

## Penjelasan

Kasus 1: Ledakan terbesar yang ada terdapat pada baris pertama dan kedua
	.*..
	.**.
dimana terdapat 3 daerah rusak yang saling terhubung.

## Batasan

- T <= 50
- 1 <= R, C <= 50
- Hanya terdapat karakter '*' dan '.' pada peta.
