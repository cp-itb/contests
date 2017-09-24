# B - Bersama Waifu

| Time Limit   | 1s    |
|--------------|-------|
| Memory Limit | 64MB  |

## Deskripsi

Setelah perjuangan bertahun-tahun, Ayaze akhirnya berhasil masuk ke dunia dua dimensi guna menemui waifunya (baca: istrinya). Ayaze berada di koordinat (Xa, Ya), dan waifunya berada di koordinat (Xb, Yb). Sayangnya, ada sebuah organisasi yang tidak senang dengan keberhasilan Ayaze masuk ke dunia dua dimensi. Organisasi tersebut berencana memisahkan Ayaze dan waifunya, sehingga Ayaze tidak bisa mencapai waifunya.

Organisasi tersebut meletakkan N buah penanda di dunia dua dimensi. Penanda ke-i berada di koordinat (Xi, Yi). Setelah meletakkan penanda, organisasi tersebut akan mengirim sebuah senjata yang akan diletakkan di suatu koordinat dan menembakkan akan laser ke N penanda tersebut. Penembakan laser tersebut akan membagi dunia dua dimensi menjadi paling banyak N daerah terpisah (bisa saja ada dua penanda yang segaris dengan senjata tersebut). Untuk mempermudah, Ayaze, waifunya, penanda, dan senjata dapat dipandang sebagai suatu titik di bidang dua dimensi.

Untungnya, Ayaze berhasil mengetahui rencana jahat organisasi tersebut. Menggunakan kekuatan supernya, ia dapat melakukan dua hal berikut:

1. Menghancurkan penanda
2. Memindahkan senjata yang akan menembakkan laser. Senjata dapat dipindahkan ke koordinat manapun (tidak harus bilangan bulat) selama koordinat tersebut tidak ditempati Ayaze, waifunya, maupun penanda

Menghancurkan penanda merupakan tindakan yang sangat melelahkan, sehingga Ayaze ingin menghancurkan seminimum mungkin penanda. Ayaze ingin menghancurkan penanda, sehingga ia dapat meletakkan senjata yang menyebabkan ia dan waifunya berada di daerah yang sama. Selain itu, peletakan senjata tidak boleh menyebabkan senjata tersebut menembakkan laser yang mengenai dirinya atau waifunya, atau mereka akan mati.

Organisasi akan mengirim senjatanya beberapa saat lagi. Bantulah Ayaze mencari banyak penanda minimum yang perlu ia hancurkan, sehingga ia dapat menemui waifunya!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi dua buah bilangan bulat N, banyaknya penanda yang diletakkan organisasi.
N baris berikutnya berisi Xi dan Yi, koordinat posisi penanda ke-i.

Baris berikutnya berisi Xa, Ya, Xb, Yb, koordinat posisi Ayaze dan koordinat posisi waifu Ayaze.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi satu bilangan bulat, jawaban dari pertanyaan di atas.

## Contoh Masukan

	2
	2
	3 5
	2 1
	1 2 4 2
	4
	3 2
	3 5
	2 1
	5 2
	1 2 4 2

## Contoh Keluaran

	0
	1

## Penjelasan

Untuk kasus uji pertama, Ayaze dapat memindahkan senjata ke koordinat (2, 0), sehingga Ayaze dapat mencapai waifunya dengan bergerak memutari senjata.

![waifu-1-1](https://user-images.githubusercontent.com/8296835/30780792-70d42d66-a13d-11e7-925e-3c786d8e8897.png)

Untuk kasus uji kedua, berikut adalah posisi Ayaze, waifunya, dan penanda:

![waifu-2-1](https://user-images.githubusercontent.com/8296835/30780797-961c77e0-a13d-11e7-95cc-de8eb85d6c70.png)

Terdapat dua cara yang yang hanya perlu menghancurkan 1 penanda:

1. Menghancurkan penanda pertama, lalu meletakkan senjata, contohnya di (11.5, 2.1)

![waifu-2-2](https://user-images.githubusercontent.com/8296835/30780805-bee48d0c-a13d-11e7-8d36-d63968ddf1e3.png)

2. Menghancurkan penanda keempat, lalu meletakkan senjata, contohnya di (2, 0)

![waifu-2-3](https://user-images.githubusercontent.com/8296835/30780811-dcd0a4fe-a13d-11e7-860c-ca2a1e056340.png)

Tidak mungkin meletakkan senjata tanpa menghancurkan penanda manapun.

## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 200
- 1 ≤ Xi, Yi ≤ 10.000
- 1 ≤ Xa, Ya ≤ 10.000
- 1 ≤ Xb, Yb ≤ 10.000
- Tidak ada dua objek yang terletak pada koordinat yang sama

