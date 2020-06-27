# B - Lonely Tutut

| Time Limit   | 500ms |
|--------------|-------|
| Memory Limit | 64MB  |

## Deskripsi

Tutut adalah seorang yang disebut “Jenius” dalam Matematika, semua permasalahan Matematika pasti bisa diselesaikannya. Tetapi, tutut merasa kesepian karena tidak ada yang bisa menyelesaikan permasalahannya. Anda sebagai programmer handal, ingin membantu tutut keluar dari rasa kesepian yang sedang dialaminya. Tutut kemudian memberi anda permasalahan sebagai berikut :

![](img/lonely_tutut.png)

Tutut memberi anda 1 persegi dengan panjang L. Setiap detik, setiap persegi dengan panjang L akan terpecah menjadi 4 persegi dengan panjang L/2.

Sekarang Tutut bertanya kepada anda, berapa jumlah panjang dari sisi-sisi persegi yang terbentuk setelah N detik ? Karena hasilnya bisa sangat besar, Tutut hanya menginginkan hasil dengan modulo (10^9+7).

Sebelum itu, Tutut juga sangat suka dengan bilangan Fibonacci, oleh karena itu jika N merupakan bilangan Fibonacci diatas 10, maka keluarkan "YEY" (tanpa tanda petik).

## Format Masukan

Baris pertama berisi bilangan T, yang menyatakan banyaknya kasus uji. T baris berikutnya merupakan bilangan N.

## Format Keluaran

Untuk setiap kasus uji, keluarkan jawaban yang dibutuhkan.

## Contoh Masukan

	3
    1
    5
    13

## Contoh Keluaran

	6
    66
    YEY

## Penjelasan

1 detik : jumlah panjang sisinya adalah 6

5 detik : jumlah panjang sisinya adalah 66

13 detik : karena 13 adalah fibonacci diatas 10, maka keluaran berupa YEY


## Batasan

- L = 1
- 1 ≤ T ≤ 10^5
- 1 ≤ N ≤ 10^8
