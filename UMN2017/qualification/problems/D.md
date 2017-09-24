# D - Lift Menyebalkan

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 512MB |

## Deskripsi

Pada suatu hari, Anda sedang berada disebuah gedung untuk meeting dengan client Anda. Anda berada di lantai X, pada gedung yang memiliki N lantai, dan client Anda berada pada lantai Y.
Terdapat sebuah lift pada gedung tersebut, namun lift tersebut hanya bisa menuju A lantai di atasnya dan B lantai dibawahnya. Jika lantai tersebut tidak ada, maka lift itu tidak akan bekerja.
Cari tahu berapa kali minimal Anda harus menggunakan lift untuk sampai ke lantai Y, namun jika lantai Y tidak dapat dicapai dengan lift, tuliskan "Pakai tangga saja".

## Format Masukan

Baris pertama berisi sebuah integer T, banyaknya kasus uji untuk soal ini.

T baris berikutnya berisi lima buah bilangan N, X, Y, A, B.

## Format Keluaran

Untuk setiap kasus uji, keluarkan berapa kali minimal Anda harus menggunakan lift untuk sampai
ke lantai Y, dengan format berikut.
	Case #c: Z
dimana c adalah nomor urut kasus (dimulai dari 1), dan Z merupakan minimal penggunaan lift,
atau tulisan "Pakai tangga saja" tanpa tanda petik, jika lantai Y tidak bisa dicapai dengan lift.

## Contoh Masukan

	3
	10 1 10 3 1
	20 3 17 5 2
	30 6 27 4 2

## Contoh Keluaran

	Case #1: 3
	Case #2: 7
	Case #3: Pakai tangga saja

## Penjelasan

Kasus 1:
Gedung terdiri dari 10 lantai, Anda sedang berada di lantai 1 dan ingin ke lantai 10. Lift hanya
bisa naik 3 lantai, atau turun 1 lantai.
Untuk kasus ini minimal penggunaan lift adalah 3 kali yaitu:
dari lantai 1 ke 4
dari lantai 4 ke 7
dari lantai 7 ke 10

## Batasan

- T <= 500
- 1 <= X, Y <= N <= 10<sup>6</sup>, X != Y
- 1 <= A, B <= 10<sup>6</sup>
