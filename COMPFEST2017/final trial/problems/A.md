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
