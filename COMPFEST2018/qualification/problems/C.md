# C - Mencari Tempat

| Time Limit   | 4s    |
|--------------|-------|
| Memory Limit | 256MB |

## Deskripsi

CFX merupakan negara yang makmur dan sejahtera. Mereka memiliki sistem transportasi yang sangat baik berupa rel kereta dan stasiun yang tersedia di setiap N kota. Berkat sistem ini, siapapun bisa pergi dari tiap kota ke kota lainnya. Uniknya, sistem transportasi tersebut tidak memiliki loops dan hanya ada tepat satu jalan antar dua buah kota.

Pak Chanek selaku pemimpin CFX telah meminta M walikota dari kota-kota yang berbeda untuk berkumpul membahas suatu proyek. Pak Chanek meminta mereka untuk berkumpul di satu kota tertentu. Akan tetapi, para walikota ini merupakan orang-orang yang sibuk sehingga mereka tidak mau pergi terlalu jauh dari kota asalnya. Lebih tepatnya, para walikota ini hanya mau pergi ke kota lain jika dan hanya jika mereka tidak melewati lebih dari K stasiun (tidak terhitung stasiun kota asal mereka). Pak Chanek menjadi bingung karena ia tidak tahu kota mana saja yang bisa dijadikan tempat berkumpul. Anda sebagai peserta CompFest X ditugaskan membantu Pak Chanek untuk menghitung berapa banyak kota yang dapat dijadikan tempat berkumpul sesuai syarat tersebut.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Setiap kasus uji diawali dengan 3 buah bilangan bulat N, M, K, yang menyatakan banyaknya kota, banyaknya walikota yang akan berkumpul, serta banyaknya stasiun maksimal yang dapat dilewati para walikota sesuai deskripsi soal.
N-1 baris berikutnya masing-masing berisi 2 buah bilangan bulat Ui dan Vi yang menyatakan bahwa terdapat rel kereta dua arah yang menghubungkan kota Ui dan kota Vi.
Baris terakhir di setiap kasus uji berisi M buah bilangan bulat Wi yang menyatakan kota asal dari para walikota yang akan berkumpul.

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah bilangan bulat berupa banyaknya kota yang dapat dijadikan tempat berkumpul sesuai deskripsi soal.

## Contoh Masukan

	1
	8 3 2
	1 2
	1 3
	1 6
	3 4
	3 5
	6 7
	7 8
	1 4 5

## Contoh Keluaran

	4

## Penjelasan

Walikota dari kota 1 bisa pergi ke semua kota kecuali kota 8. Walikota dari kota 4 dan 5 masing-masing dapat pergi ke kota 1, 3, 4, dan 5. Jadi, ketiga walikota tersebut dapat berkumpul di kota 1, 3, 4, dan 5.

## Batasan

- 1 ≤ T ≤ 12
- 1 ≤ M ≤ N ≤ 50.000
- 1 ≤ K ≤ 50.000
- 1 ≤ Ui, Vi ≤ N
- 1 ≤ Wi ≤ N
- Ui ≠ Vi untuk tiap 1 ≤ i ≤ N-1
- Untuk tiap i dan j dengan i ≠ j dan 1 ≤ i,j ≤ M, Wi ≠ Wj

