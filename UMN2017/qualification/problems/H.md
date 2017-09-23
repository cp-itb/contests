# H - Traktiran Perpisahan

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 512MB |

## Deskripsi

Pak Emon sedang sedih, pasalnya beliau sebentar lagi harus pergi meninggalkan murid muridnya. Pak Emon ingin mentraktir anak-anak muridnya, beliau sudah tahu bahwa biaya yang dibutuhkan adalah p. Sekarang beliau hanya memiliki deposit senilai d dengan bunga per
bulannya sebesar i persen.

Pak Emon meminta bantuan anda untuk menghitung berapa bulan yang dibutuhkan agar nominal depositnya lebih besar sama dengan dana yang dibutuhkan untuk mentraktir anak-anaknya. Ayo bantulah Pak Emon mempersiapkan pesta perpisahannya

## Format Masukan

Program akan menerima sebuah bilangan bulat t yang mendefinisikan banyaknya kasus yang akan diberikan kepada program.
Untuk T baris berikutnya akan terdapat 3 bilangan bulat d p i untuk setiap barisnya.

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebaris string dengan format berikut.
	Case #x: y
dimana x merepresentasikan nomor kasus, y adalah jumlah bulan yang dibutuhkan.

## Contoh Masukan

	4
	1000 2000 20
	1000 2000 10
	1000 2000 50
	3000 1000 40

## Contoh Keluaran

	Case #1: 4
	Case #2: 8
	Case #3: 2
	Case #4: 0

## Penjelasan

untuk kasus 1 :

(bulan 1)
deposito = 1000
bunga = 200
total = 1200

(bulan 2)
deposito = 1200
bunga = 240
total = 1440

(bulan 3)
deposito = 1440
bunga = 288
total = 1728

(bulan 4)
deposito = 1728
bunga = 346.5
total = 2074.5

total melebihi target profit maka jawabnya 4.

untuk kasus 4 :

Pak Emon tidak perlu melakukan deposit karena nilai uang yang dimilikinya sudah mampu menutupi acara makan makan yang akan diadakan beliau.

## Batasan

1 <= t <= 10<sup>5</sup>
1 <= p <= 10<sup>8</sup>
1 <= d <= 10<sup>8</sup>
1 <= i <= 100
