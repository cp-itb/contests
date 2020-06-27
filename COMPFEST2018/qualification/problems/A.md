# A - Origami Tempel

| Time Limit   | 4s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pak Chanek memiliki banyak kertas origami berbentuk persegi panjang. Di kala senggang, dia suka melipat kertas-kertas tersebut dan menghasilkan bentuk hewan-hewan unik. Bosan dengan karya origami biasa, Pak Chanek memiliki ide lain terhadap origaminya.

![origami-tempel-illustration](https://user-images.githubusercontent.com/8296835/45300392-69a4bc80-b538-11e8-95f6-0251043c37e6.png)

Pak Chanek ingin membuat N kertas origaminya menjadi sebuah kesatuan dengan cara menempelkan sisi-sisinya. Dua atau lebih origami dapat disatukan hanya jika sisi yang ditempelkan memiliki panjang yang sama. Agar memiliki bentuk yang unik, dia dapat menempelkan beberapa kertas sekaligus. Setelah dilihat-lihat, Pak Chanek ternyata tidak terlalu suka dengan tempelan-tempelan tersebut. Baginya, tempelan-tempelan tersebut membuat kerumitan apalagi jika sisi yang ditempelkan cukup panjang. Lebih lanjut, Pak Chanek mendefinisikan nilai kerumitan dari sebuah tempelan dengan (X - 1) * S dengan X adalah banyak kertas yang menempel dan S adalah panjang sisi yang ditempelkan. Sekarang Pak Chanek bertanya-tanya, berapakah total nilai kerumitan minimum yang dapat diperoleh?

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi sebuah bilangan bulat N, yaitu banyak kertas origami milik Pak Chanek.
N baris berikutnya berisi dua buah bilangan Pi dan Li, panjang dan lebar origami ke-i.
Dijamin N origami tersebut dapat ditempel menjadi satu.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat, yaitu jawaban pertanyaan Pak Chanek.

## Contoh Masukan

	2
	4
	1 2
	4 2
	4 5
	6 1
	4
	4 6
	6 8
	6 8
	8 9

## Contoh Keluaran

	7
	20

## Penjelasan

Pada kasus uji pertama, Pak Chanek dapat menempelkan origami kedua dengan origami ketiga pada sisi dengan panjang 4, origami pertama dengan origami keempat pada sisi dengan panjang 1, dan origami pertama dengan origami kedua pada sisi dengan panjang 2 sehingga semua origami menjadi satu. Total nilai kerumitan yang dihasilkan adalah 1x4 + 1x1 + 1x2 = 7. Perhatikan tidak ada cara yang menghasilkan total nilai kerumitan kurang dari 7.

Pada kasus uji kedua, Pak Chanek dapat menempelkan origami kedua dengan origami keempat pada sisi dengan panjang 8 dan menempelkan origami pertama, kedua, dan ketiga pada sisi dengan panjang 6 sehingga total nilai kerumitan yang dihasilkan adalah 1x8 + 2x6 = 20.

## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 100.000
- 1 ≤ Pi, Li ≤ 1.000.000.000
