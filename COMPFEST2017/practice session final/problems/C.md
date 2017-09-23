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
