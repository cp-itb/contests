# G - Pertukaran Chanek

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 128MB |

## Deskripsi

Pak Chanek adalah orang yang sangat kreatif. Ia disenangi oleh anak-anak maupun orang dewasa karena permainan buatannya yang sangat adiktif dan menantang. Sekarang, Pak Chanek mempunyai permainan baru untuk para finalis SCPC Compfest 9 mainkan.

Permainan baru buatan Pak Chanek kali ini bernama "Pertukaran Chanek". Aturan permainannya adalah sebagai berikut:

- Permainan dimainkan oleh satu pemain.
- Pada awal permainan, pemain diberikan sebuah array A yang berisi N bilangan bulat (indeks pertama adalah indeks ke-1). Permainan terdiri dari Q level.
- Untuk setiap level, pemain diberikan sebuah array yang merupakan subarray A yang bermula di indeks L dan berakhir di indeks R. Subarray tersebut dinamakan B.
- Pemain dapat melakukan langkah penukaran. Langkah penukaran didefinisikan sebagai mengambil suatu indeks i, 1 ≤ i < R - L + 1, lalu menukar nilai B[i] dan nilai B[i+1]. Dengan kata lain, apabila C menyatakan array setelah penukaran, maka C[i] = B[i+1] dan C[i+1] = B[i]. Poin yang didapat dari penukaran ini adalah B[i] + B[i+1].
- Setelah melakukan tepat K kali penukaran, permainan pada level tersebut selesai.
- Segala penukaran yang dilakukan pada array B tidak akan mempengaruhi array A.
- Skor pemain pada suatu level adalah total poin yang didapat setelah melakukan tepat K kali penukaran pada level tersebut.

Pak Chanek penasaran, berapa skor maksimum yang bisa didapat seorang pemain pada setiap levelnya? Pak Chanek kemudian meminta tolong kepada Anda dan teman-teman Anda, yang berambisi untuk menjadi juara 1 dalam kompetisi SCPC Compfest 9 untuk membuat program yang bisa menjawab pertanyaan Pak Chanek. Bantulah Pak Chanek!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi tiga buah bilangan bulat N, K, dan Q yang menandakan ukuran dari array, banyaknya langkah penukaran, dan banyaknya level permainan.

Baris kedua berisi N buah bilangan bulat A[i].

Q baris berikutnya berisi dua buah bilangan Li dan Ri, rentang subarray A yang diberikan pada level ke-i.

## Format Keluaran

Untuk setiap kasus uji, keluarkan Q baris berisi sebuah bilangan bulat, yaitu skor tertinggi yang didapat pada level ke-i.

## Contoh Masukan

	1
	5 2 2
	3 5 1 1 7
	2 3
	1 5

## Contoh Keluaran

	12
	16

## Penjelasan

Terdapat satu kasus uji.
Array A yang diberikan Pak Chanek adalah [3, 5, 1, 1, 7].

Untuk level pertama:

- Array B yang diberikan pada level ini: [5, 1]
- Langkah penukaran:
1. Pilih i = 1. poin yang didapat adalah B[1] + B[2] = 5 + 1 = 6. Kondisi array B sekarang: [1, 5]
2. Pilih i = 1. poin yang didapat adalah B[1] + B[2] = 1 + 5 = 6. Kondisi array B sekarang: [5, 1]
- Total poin yang didapat = 6 + 6 = 12
- Skor yang didapat pada level pertama adalah 12. Tidak ada cara lain untuk mendapatkan skor lebih dari 12.

Untuk level kedua:

- Array B yang diberikan pada level ini: [3, 5, 1, 1, 7]
- Salah satu langkah penukaran:
1. Pilih i = 1. poin yang didapat adalah B[1] + B[2] = 3 + 5 = 8. Kondisi array B sekarang: [5, 3, 1, 1, 7]
2. Pilih i = 4. poin yang didapat adalah B[4] + B[5] = 7 + 1 = 8. Kondisi array B sekarang: [5, 3, 1, 7, 1]
- Total poin yang didapat = 8 + 8 = 16
- Skor yang didapat pada level kedua adalah 16. Tidak ada cara lain untuk mendapatkan skor lebih dari 16.

## Batasan

- 1 ≤ T ≤ 8
- 2 ≤ N ≤ 100.000
- 1 ≤ K ≤ 106
- 1 ≤ Q ≤ 100.000
- 1 ≤ A[i] ≤ 109 untuk 1 ≤ i ≤ N
- 1 ≤ Li < Ri ≤ N

