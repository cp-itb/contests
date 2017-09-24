# F - Pasti Menang!

| Time Limit   | 1500ms |
|--------------|--------|
| Memory Limit | 64MB   |

## Deskripsi

Turnamen K-Bidak 2017 akan segera berakhir! Pak Chanek yang menjadi juara bertahan selama 50 tahun akan melawan Ayaze dalam pertandingan final. Sebelumnya, aturan permainan K-Bidak dijelaskan sebagai berikut:

- Arena permainan terdiri dari N petak yang dinomori 1 sampai N, dengan M jalan satu arah yang menghubungkan satu petak ke satu petak yang lain.
- Permainan dimainkan oleh 2 orang pemain. Pemain bermain secara bergiliran.
- Terdapat K bidak yang dinomori 1 sampai K, dengan setiap bidak terletak di suatu petak.
- Suatu petak dapat ditempati oleh satu atau lebih bidak, atau tidak ditempati bidak sama sekali.
- Dalam gilirannya, seorang pemain dapat memindahkan salah satu bidak yang berada di petak X (1 ≤ X ≤ N) ke petak Y, apabila terdapat jalan satu arah yang berasal dari petak X dan berakhir di petak Y. Kemudian, gilirannya selesai.
- Pemain yang tidak bisa memindahkan bidak dinyatakan kalah.
Pada pertandingan final, Pak Chanek akan mendapatkan giliran pertama.

Bukannya berlatih untuk menghadapi Ayaze, Pak Chanek sekarang justru memikirkan hal berbeda. Ia sekarang berpikir, ada berapa konfigurasi awal peletakan K bidak tersebut, sehingga apabila Pak Chanek dan Ayaze bermain secara optimal (tidak akan melakukan gerakan yang akan menyebabkan mereka kalah, kecuali jika semua gerakan akan menyebabkan kekalahan) maka Pak Chanek pasti menang? Dua konfigurasi peletakan dikatakan berbeda apabila terdapat x, sehingga bidak ke-x diletakkan di petak yang berbeda pada kedua peletakan tersebut.

Pak Chanek ternyata kesulitan menjawab pertanyaan tersebut. Oleh karena itu, Pak Chanek meminta bantuan Anda untuk menjawab pertanyaannya. Karena banyak konfigurasi bisa sangat besar, Pak Chanek meminta Anda untuk menjawabnya dalam modulo 109 + 8 saja. Bantulah Pak Chanek!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi tiga buah bilangan N, M, dan K, yaitu banyaknya petak, banyaknya jalan satu arah, dan banyaknya bidak.

M baris berikutnya berisi dua buah bilangan Ui dan Vi, yang menandakan bahwa terdapat jalan satu arah dari petak bernomor Ui ke petak bernomor Vi.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat yang menyatakan banyak konfigurasi awal peletakan bidak sehingga Pak Chanek pasti menang dalam modulo 109 + 8.

## Contoh Masukan

	2
	10 4 1
	2 1
	5 1
	7 1
	3 1
	50000 4 2
	2 1
	5 1
	7 1
	3 1

## Contoh Keluaran

	4
	399968

## Penjelasan

Pada contoh kasus uji pertama, terdapat 1 bidak. Agar Pak Chanek pasti menang, bidak tersebut harus diletakkan di petak 2, 3, 5, atau 7. Sehingga, ada 4 konfigurasi awal berbeda yang dapat menyebabkan Pak Chanek menang.

Pada contoh kasus uji kedua, terdapat 2 bidak. Agar Pak Chanek pasti menang, salah satu bidak harus diletakkan di salah satu dari petak 2, 3, 5, atau 7, dan bidak lainnya harus diletakkan di salah satu dari 49996 petak lainnya. Maka, ada 4 * 49996 * 2 = 399968 konfigurasi.

## Batasan

- 1 ≤ T ≤ 8
- 2 ≤ N ≤ 50.000
- 1 ≤ M ≤ 100.000
- 1 ≤ K ≤ 109
- 1 ≤ Vi < Ui ≤ N

