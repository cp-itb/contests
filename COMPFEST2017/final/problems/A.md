# A - Angka Ajaib

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Setelah mempelajari huruf ajaib dari Irwanto saat CompFest 8, Pak Chanek memutuskan untuk membuat angka ajaib. Pak Chanek mendefinisikan angka ajaib sebagai angka yang memenuhi syarat-syarat berikut:

- Terdiri dari tepat N digit
- Boleh diawali angka 0
- Terdapat suatu string terlarang S yang terdiri dari karakter '0' sampai '9' dengan panjang K. Dalam penulisannya, angka ajaib tidak boleh mengandung S sebagai substring. String S memiliki sifat unik, yaitu Si ≤ Si+1 untuk setiap 1 ≤ i < K

Sekarang, Pak Chanek menjadi penasaran, ada berapa banyaknya angka ajaib berbeda? Bantulah Pak Chanek menjawab pertanyaan tersebut!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi bilangan bulat N, yaitu banyak digit angka ajaib.

Baris kedua berisi bilangan bulat K, yaitu panjang string terlarang.

Beris ketiga berisi sebuah string S, yaitu string terlarang.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat, yaitu banyaknya angka ajaib. Karena bilangan ini bisa sangat besar, Anda cukup mengeluarkannya dalam modulo 109 + 7.

## Contoh Masukan

	2
	3
	2
	12
	5
	3
	122

## Contoh Keluaran

	980
	99700

## Penjelasan

Pada kasus uji pertama, terdapat 20 angka dengan N digit yang bukan merupakan angka ajaib, yaitu:

1. 012
2. 120
3. 112
4. 121
5. 212
6. 122
7. 312
8. 123
9. 412
10. 124
11. 512
12. 125
13. 612
14. 126
15. 712
16. 127
17. 812
18. 128
19. 912
20. 129

Maka, banyaknya angka ajaib adalah (banyak angka dengan N digit) - (banyak angka yang bukan angka ajaib) = 103- 20 = 980.

## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 100.000
- 1 ≤ K ≤ N
- String S hanya mengandung karakter '0' sampai '9'
- Si ≤ Si+1 untuk 1 ≤ i < K
