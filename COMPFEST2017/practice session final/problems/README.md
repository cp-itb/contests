# Problems

- [A - Restoran Chanek](#a---restoran-chanek)
- [B - Palindromisme](#b---palindromisme)
- [C - Iri Itu Tidak Baik](#c---iri-itu-tidak-baik)


# A - Restoran Chanek

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pak Chanek baru saja mendirikan restoran yang menyediakan M buah jenis makanan-makanan lezat. Untuk menyediakan makanan-makanan lezat tersebut, Pak Chanek berhasil merekrut N koki handal. Pak Chanek yang unik ingin semua koki terlibat dalam memasak setiap makanan yang akan disajikan. Hal ini dilakukan agar cita rasa dari makanan-makanan tersebut menjadi sangat nikmat, setidaknya menurut Pak Chanek.

Dikarenakan restoran Chanek baru didirikan dan kurangnya modal, Pak Chanek hanya sanggup membeli satu alat masak untuk dapur restorannya, sehingga hanya tepat satu koki yang bisa bekerja dalam satu waktu. Waktu yang koki ke-i butuhkan untuk menyelesaikan bagiannya dalam memasak makanan ke-j adalah Aij menit. Suatu pekerjaan koki dapat langsung dilaksanakan tepat setelah suatu pekerjaan koki lain selesai dilaksanakan.

Pak Chanek sedang memikirkan suatu kasus, yaitu ketika para koki tersebut harus menyiapkan tepat satu makanan untuk semua jenis makanan yang restorannya sediakan. Bantulah Pak Chanek menghitung waktu minimum yang para koki butuhkan dalam kasus tersebut!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi dua bilangan bulat N dan M, banyaknya koki dan banyaknya jenis makanan.
N baris berikutnya berisi M bilangan bulat A<sub>ij</sub>, waktu yang koki ke-i perlukan untuk melaksanakan bagiannya dalam memasak makanan ke-j dalam menit.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat, waktu minimum yang para koki butuhkan dalam menit.

## Contoh Masukan

	2
	1 3
	3 2 2
	2 2
	9 3
	4 7

## Contoh Keluaran

	7
	23

## Penjelasan

Pada kasus uji pertama, hanya terdapat 1 koki, waktu yang dibutuhkan adalah 3 + 2 + 2 = 7 menit.

Pada kasus uji kedua, urutan pengerjaan dapat dilakukan sebagai berikut:

1. Koki ke-1 memasak makanan ke-2
2. Koki ke-2 memasak makanan ke-1
3. Koki ke-2 memasak makanan ke-2
4. Koki ke-1 memasak makanan ke-1

Waktu yang dibutuhkan adalah 3 + 4 + 7 + 9 = 23 menit.

## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 250
- 1 ≤ M ≤ 250
- 1 ≤ A<sub>ij</sub> ≤ 50.000




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


# C - Iri Itu Tidak Baik

| Time Limit   | 1s    |
|--------------|-------|
| Memory Limit | 64MB  |

## Deskripsi

Pak Chanek adalah seorang pengusaha kaya. Ia mempekerjakan N karyawan di perusahaannya, dengan karyawan ke-i mendapat gaji sebesar Si per hari. Akhir-akhir ini, Pak Chanek sering mendapat surat dari karyawannya yang iri terhadap gaji karyawan lain. Sebagai orang yang baik, Pak Chanek tidak ingin banyak karyawannya yang merasa iri, sehingga ia memutuskan untuk memindahkan paling banyak K orang karyawan ke perusahaan temannya.

Tingkat iri hati di perusahaan Pak Chanek dapat didefinisikan sebagai selisih gaji tertinggi seorang karyawan dengan gaji terendah seorang karyawan di perusahaannya. Pak Chanek ingin meminimalkan tingkat iri hati dengan memindahkan paling banyak K orang dari perusahaannya. Bantulah Pak Chanek menentukan tingkat iri hati minimum yang dapat dicapai!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji. Setiap kasus uji dinyatakan sebagai berikut.
Baris pertama berisi 2 buah bilangan bulat N dan K, masing-masing menyatakan banyak karyawan di perusahaan Pak Chanek dan banyak karyawan yang paling banyak akan dipindahkan.
Baris kedua berisi N buah bilangan bulat S[i], yang menyatakan gaji yang diterima karyawan ke-i.

## Format Keluaran

Untuk setiap kasus uji, keluarkan 1 bilangan bulat yang menyatakan tingkat iri hati minimum.

## Contoh Masukan

	2
	4 2
	3 4 3 4
	6 1
	6 9 8 6 7 9

## Contoh Keluaran

	0
	3

## Batasan

- 1 ≤ T ≤ 10
- 2 ≤ N ≤ 100.000
- 0 ≤ K ≤ N - 2
- 1 ≤ S<sub>i</sub> ≤ 10<sup>9</sup>


