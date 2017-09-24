# A - ENCODING

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 512MB |

## Deskripsi

Pak Chandra sedang suka dengan encoding, kali ini dia menemukan suatu jenis encoding yang mengubah binary menjadi karakter. Jenis encoding ini mengambil 6 bit binary, kemudian mengubah nya menjadi bilangan desimal. Setelah itu bilangan desimal ini akan di ubah menjadi huruf dengan ketentuan sebagai berikut :

![a-1](https://user-images.githubusercontent.com/5902356/30779915-9fb599c2-a128-11e7-8fea-0b2ea8200dc5.png)

Gambar diatas menjelaskan bahwa angka 0 akan diubah menjadi 'A', angka 1 akan diubah menjadi 'B' dst. Pak Chandra meminta bantuan Anda sebagai programmer handal untuk membuat program yang menerima sekumpulan angka binary kemudian menampilkan hasil encodingnya.

## Format Masukan

Baris pertama berisi sebuah integer T, banyaknya kasus uji untuk soal ini. T baris berikutnya berisi sekumpulan binary S dengan banyak bit <= 150. Banyak bit dijamin habis dibagi 6.

## Format Keluaran

Untuk setiap kasus uji, keluarkan hasil encoding dari tiap input dengan format berikut.
Case #c: Y
dimana c adalah nomor urut kasus (dimulai dari 1), dan Y merupakan hasil encoding dari S.

## Contoh Masukan

	3
	010101000110100001100101
	011101000110100001100101001000000111
	000101110101011010010110001101101011

## Contoh Keluaran

	Case #1: VGhl
	Case #2: dGhlIH
	Case #3: F1aWNr

## Penjelasan

Kasus 1 :
S dipecah setiap 6 karakter menjadi 010101, 000110, 100001, 100101 Tiap pecahan diubah menjadi angka desimal, yaitu 21, 6, 33, dan 37 Kemudian ubah menjadi karakter sesuai pemetaan di deskripsi soal, 21 -> 'V', 6 -> 'G', 33 -> 'h', 37 -> 'l' Didapatkan hasil 'VGhl'.

## Batasan

- T <= 50
- Panjang 6 <= S <= 150
- S hanya akan terdiri dari karakter '0' dan '1
