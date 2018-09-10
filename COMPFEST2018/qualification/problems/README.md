# Problems

- [A - Origami Tempel](#a---origami-tempel)
- [B - Drone Pak Chanek](#b---drone-pak-chanek)
- [C - Mencari Tempat](#c---mencari-tempat)
- [D - Memperpanjang Barisan](#d---memperpanjang-barisan)
- [E - Mari Membaca](#e---mari-membaca)
- [F - Jelajah Kota](#f---jelajah-kota)
- [G - FPB Terbesar](#g---fpb-terbesar)

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





# B - Drone Pak Chanek

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pak Chanek baru saja membeli sebuah drone yang telah lama diidamkannya. Karena begitu semangat, ia langsung pergi ke lapangan untuk menerbangkan drone tersebut.

Ternyata drone yang dibeli Pak Chanek berbeda dibanding drone pada umumnya. Drone baru Pak Chanek tidak memiliki analog yang dapat digunakan sebagai controller. Oleh karena itu, Pak Chanek harus mengetikkan beberapa baris perintah ke dalam controller drone tersebut. Setiap baris perintah yang dimasukkan Pak Chanek berisi arah drone tersebut akan terbang dan jarak yang akan ditempuh oleh drone tersebut. Arah terbang drone tersebut dapat dibayangkan sebagai sudut yang dihitung dari garis yang sejajar dengan sumbu x dan melewati titik awal drone sebelum terbang kemudian diputar berlawanan arah dengan jarum jam. Pak Chanek menghadap arah sumbu y positif dan Pak Chanek tidak mengubah arah hadapnya selama drone terbang. Pak Chanek serta drone-nya berada pada koordinat (0, 0) pada awal sebelum eksekusi perintah pertama.

Pak Chanek pun mulai mengetikkan beberapa baris perintah. Setelah semua perintah selesai dimasukkan, Pak Chanek menekan tombol "Jalan" yang kemudian memulai eksekusi perintah pada drone tersebut satu per satu. Sayangnya, program yang dibuat untuk menjalankan drone tersebut ternyata memiliki bug yang membuat pergerakan drone tersebut terbatasi oleh sebuah persegi khayalan dengan Pak Chanek sebagai pusatnya. Persegi yang terbentuk dibatasi oleh garis x = R, x = -R, y = R, dan y = -R, dengan R merupakan suatu konstanta bilangan bulat dalam satuan meter. Akibatnya, apabila drone tersebut sampai di batas persegi, drone tersebut akan memantul secara sempurna sehingga arah geraknya berubah, namun jarak total yang ditempuh tetap disesuaikan dengan perintah yang dimasukkan. Pantulan sempurna yang dimaksud merupakan pantulan sedemikian sehingga sudut datang dari drone tersebut terhadap sisi persegi sama dengan sudut pantulnya. Akibatnya juga, jika drone tersebut menabrak titik sudut persegi, drone tersebut akan terpantul tepat berlawanan arah dengan arah datangnya.

Hal ini tentu saja membuat Pak Chanek bingung. Kini ia tidak dapat memprediksi dimana letak drone tersebut saat semua perintah selesai tereksekusi. Oleh karena itu, bantulah Pak Chanek menemukan titik akhir drone tersebut.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji yang diberikan. Setiap kasus uji dinyatakan sebagai berikut.

Baris pertama berisi 2 buah bilangan bulat N dan R yang menyatakan banyak baris perintah yang dimasukkan dan konstanta persegi yang dijelaskan dalam soal.
Baris ke-2 sampai N+1 masing-masing berisi dua buah bilangan bulat D dan J yang menyatakan arah terbang drone Pak Chanek dalam derajat dan jarak tempuh drone Pak Chanek pada arah tersebut dalam satuan meter.

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah baris yang berisi dua buah bilangan desimal X dan Y yang menyatakan koordinat akhir (X, Y) drone tersebut saat semua perintah selesai dieksekusi.

Jawaban akan dianggap benar apabila relative error antara solusi peserta dan solusi juri tidak lebih dari 10-2. Dengan kata lain, misalkan jawaban anda adalah (Xpes, Ypes) dan jawaban juri adalah (Xjuri, Yjuri), jawaban anda dianggap benar apabila |Xpes−Xjuri|/max(1,|Xjuri|) ≤ 10−2 dan |Ypes−Yjuri|/max(1,|Yjuri|) ≤ 10−2.

## Contoh Masukan

	2
	2 12
	0 5
	90 5
	2 5
	45 14
	330 10

## Contoh Keluaran

	5.000000000 5.000000000
	1.239240899 -4.899494937

## Penjelasan Contoh

Pada kasus uji kedua, drone Pak Chanek terkurung dalam persegi yang dibentuk oleh garis x = 5, x = -5, y = 5, dan y = -5.

Pada saat drone mengeksekusi perintah pertama, gerakan drone dijelaskan oleh gambar berikut.

![drone-pak-chanek-step-1](https://user-images.githubusercontent.com/8296835/45300391-690c2600-b538-11e8-88da-16a68898343f.png)

Terlihat sudut datang = sudut pantul, maka drone terpantul ke arah sebaliknya.

![drone-pak-chanek-step-2](https://user-images.githubusercontent.com/8296835/45300390-690c2600-b538-11e8-9a34-f520a347320d.png)

Setelah drone mengeksekusi perintah pertama, titik akhir drone berada pada (0.10051, 0.10051).

Pada saat drone mengeksekusi perintah kedua, gerakan drone dijelaskan oleh gambar berikut.

![drone-pak-chanek-step-3](https://user-images.githubusercontent.com/8296835/45300388-690c2600-b538-11e8-9f69-1cf29b344a40.png)

Setelah drone mengeksekusi perintah kedua, titik akhir drone berada pada (1.239240899 -4.899494937).

## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 100.000
- 1 ≤ R ≤ 100.000
- 0 ≤ D ≤ 360
- 0 ≤ J ≤ 10.000.000

