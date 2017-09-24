# G - Strategi Tentara

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 512MB |

## Deskripsi

Jenderal Umon ingin menyiapkan strategi perang untuk memerangi negara tetangga. Oleh sebab itu beliau ingin menyiapkan perlengkapan untuk N orang tentaranya. Untuk dapat melakukan itu, Jenderal harus menentukan jumlah kapten dan serdadu. Di negara Pak Umon, tentara disebut kapten apabila ia memiliki tentara lain dibawahnya (baik itu serdadu maupun kapten yang lain), sedangkan serdadu tidak memiliki anak buah.

Seorang kapten dapat memiliki maksimal M bawahan langsung. Bawahan langsung adalah tentara yang berada persis satu tingkat di bawah atasannya. Maka, bawahan dari bawahan langsung bukanlah bawahan langsung. Seorang kapten dengan kurang dari M bawahan langsung tidak dapat bekerja dengan baik, sehingga Pak Umon hanya mentolerir maksimal terdapat 1 kapten dengan kurang dari M bawahan langsung.

Salah satu ujian untuk menjadi kapten adalah menghitung ada berapa maksimal kapten yang dapat diangkat oleh Pak Umon, berdasarkan ketentuan di atas.

## Format Masukan

Baris pertama berisi sebuah integer T, yaitu banyaknya kasus uji untuk soal ini. Setiap kasus uji berisi dua integer N M (banyaknya tentara, dan banyaknya bawahan langsung seorang kapten). 

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebaris string dengan format berikut.
	Case #x: y z
dimana x merepresentasikan nomor kasus, y adalah jumlah maksimal kapten dan z merupakan jumlah serdadu.

## Contoh Masukan

	3
	10 5
	3 2
	5 3

## Contoh Keluaran

	Case #1: 2 8
	Case #2: 1 2
	Case #3: 2 3

## Penjelasan

untuk kasus 1 :

![g-1](https://user-images.githubusercontent.com/5902356/30779916-9fb6b82a-a128-11e7-916d-c8f1c314c2a9.png)

## Batasan

- 1 <= T <= 1000
- 1 <= N,M <= 1000000
