# C - Kuota Maksimum

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 128MB  |

## Deskripsi

Pak Chanek adalah seorang otaku yang gemar sekali menonton dan download film anime secara online. Untuk menunjang hobinya ini, Pak Chanek baru saja membeli kartu perdana modem 4G dari sebuah operator baru bernama Thunder yang diklaim lebih cepat dan memiliki kuota lebih besar dari operator lainnya. Operator Thunder ini menyediakan N buah paket data, dengan besaran kuota dan harga paket yang berbeda-beda. Harga paket ke-i dinyatakan oleh Pi, dan besaran kuota paket ke-i dinyatakan oleh Si.

Operator Thunder bukanlah operator biasa. Operator ini menetapkan harga paket datanya dengan unik. Spesifiknya, untuk setiap pasang (i, j), 1 ≤ i, j ≤ N, berlaku:

1. Pi merupakan kelipatan Pj, atau
2. Pj merupakan kelipatan Pi

Saat ini, Pak Chanek memiliki uang sebesar M. Dengan jumlah uang yang terbatas, Pak Chanek ingin memaksimumkan jumlah kuota yang bisa didapatkan. Bantulah Pak Chanek untuk menghitung jumlah kuota maksimum yang bisa didapatkan dengan uang yang dimilikinya! (Dalam hal ini, satu paket data bisa dibeli lebih dari satu kali, dan tidak semua uang harus dihabiskan)

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi sebuah bilangan bulat N dan M, yang menyatakan banyak paket data dan uang yang dimiliki Pak Chanek.
Baris kedua berisi N buah bilangan bulat Pi, harga paket data ke-i.
Baris ketiga berisi N buah bilangan bulat Si, besaran kuota paket data ke-i.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat, jumlah kuota maksimum yang bisa dibeli Pak Chanek.

## Contoh Masukan

	1
	3 24
	2 6 18
	2 2 30

## Contoh Keluaran

	36

## Penjelasan

Pak Chanek dapat membeli 3 paket data ke-1 dan 1 paket data ke-3, sehingga jumlah kuota yang ia dapatkan adalah 3 * 2 + 1 * 30 = 36. Tidak ada pembelian dengan jumlah kuota melebihi 36.

## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 100
- 1 ≤ M ≤ 100.000
- 1 ≤ Pi ≤ 100.000
- 1 ≤ Si ≤ 100.000

