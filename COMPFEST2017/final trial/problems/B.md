# B - Palindromisme

| Time Limit   | 1s    |
|--------------|-------|
| Memory Limit | 64MB  |

## Deskripsi

Pak Chanek sedang berulang tahun! Sebagai teman baik Pak Chanek, Irwanto pun memberikan hadiah pada Pak Chanek. Hadiah tersebut berupa string dengan panjang N yang dibungkus dengan kado yang sangat indah. Sayangnya, Irwanto memberikan hadiah tanpa mengetahui bahwa Pak Chanek merupakan pengikut ajaran Palindromisme.

Setiap pengikut ajaran Palindromisme diwajibkan untuk mengubah string apapun yang mereka lihat hingga setiap substring dari string tersebut merupakan palindrom. Pengubahan ini dilakukan dalam beberapa langkah, yang mana dalam satu langkah terdapat satu indeks sehingga karakter pada indeks tersebut diubah menjadi karakter lain. Misal string hasil pengubahan adalah X. Maka, untuk setiap pasang (i, j) (1 ≤ i ≤ j ≤ |X|), substring Xi..j harus merupakan palindrom.

Pak Chanek yang telah membuka kado dari Irwanto lalu mencoba mengubah string dari Irwanto sesuai ajaran Palindromisme. Sekarang, Pak Chanek justru penasaran, berapa langkah minimum yang ia perlukan dalam mengubah string tersebut?

Suatu string dikatakan palindrom jika dan hanya jika string tersebut dapat dibaca dengan sama baik dari depan maupun belakang.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.
Baris pertama berisi sebuah bilangan N, panjang string yang diberikan Irwanto.
Baris kedua berisi sebuah string S, string yang diberikan Irwanto.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat, banyak langkah minimum yang diperlukan Pak Chanek.

## Contoh Masukan

	2
	1
	c
	2
	pc

## Contoh Keluaran

	0
	1

## Batasan

- 1 ≤ T ≤ 100
- 1 ≤ N ≤ 1.000
- S hanya terdiri dari huruf kecil alfabet ('a' - 'z')
