# Problems

- [A - Angka Ajaib](#a---angka-ajaib)
- [B - Bersama Waifu](#b---bersama-waifu)
- [C - Kuota Maksimum](#c---kuota-maksimum)
- [D - Xor-or](#d---xor-or)
- [E - Menginap](#e---menginap)
- [F - Pasti Menang!](#f---pasti-menang)
- [G - Pertukaran Chanek](#g---pertukaran-chanek)
- [H - Perjalanan Aneh](#h---perjalanan-aneh)
- [I - Percobaan Median](#i---percobaan-median)


# A - Angka Ajaib

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Setelah mempelajari huruf ajaib dari Irwanto saat CompFest 8, Pak Chanek memutuskan untuk membuat angka ajaib. Pak Chanek mendefinisikan angka ajaib sebagai angka yang memenuhi syarat-syarat berikut:

- Terdiri dari tepat N digit
- Boleh diawali angka 0
- Terdapat suatu string terlarang S yang terdiri dari karakter '0' sampai '9' dengan panjang K. Dalam penulisannya, angka ajaib tidak boleh mengandung S sebagai substring. String S memiliki sifat unik, yaitu Si ≤ Si+1 untuk setiap 1 ≤ i < K

Sekarang, Pak Chanek menjadi penasaran, ada berapa banyaknya angka ajaib berbeda? Bantulah Pak Chanek menjawab pertanyaan tersebut!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi bilangan bulat N, yaitu banyak digit angka ajaib.

Baris kedua berisi bilangan bulat K, yaitu panjang string terlarang.

Beris ketiga berisi sebuah string S, yaitu string terlarang.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat, yaitu banyaknya angka ajaib. Karena bilangan ini bisa sangat besar, Anda cukup mengeluarkannya dalam modulo 109 + 7.

## Contoh Masukan

	2
	3
	2
	12
	5
	3
	122

## Contoh Keluaran

	980
	99700

## Penjelasan

Pada kasus uji pertama, terdapat 20 angka dengan N digit yang bukan merupakan angka ajaib, yaitu:

1. 012
2. 120
3. 112
4. 121
5. 212
6. 122
7. 312
8. 123
9. 412
10. 124
11. 512
12. 125
13. 612
14. 126
15. 712
16. 127
17. 812
18. 128
19. 912
20. 129

Maka, banyaknya angka ajaib adalah (banyak angka dengan N digit) - (banyak angka yang bukan angka ajaib) = 103- 20 = 980.

## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 100.000
- 1 ≤ K ≤ N
- String S hanya mengandung karakter '0' sampai '9'
- Si ≤ Si+1 untuk 1 ≤ i < K




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





# C - Kuota Maksimum

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 128MB  |

## Deskripsi

Pak Chanek adalah seorang otaku yang gemar sekali menonton dan download film anime secara online. Untuk menunjang hobinya ini, Pak Chanek baru saja membeli kartu perdana modem 4G dari sebuah operator baru bernama Thunder yang diklaim lebih cepat dan memiliki kuota lebih besar dari operator lainnya. Operator Thunder ini menyediakan N buah paket data, dengan besaran kuota dan harga paket yang berbeda-beda. Harga paket ke-i dinyatakan oleh Pi, dan besaran kuota paket ke-i dinyatakan oleh Si.

Operator Thunder bukanlah operator biasa. Operator ini menetapkan harga paket datanya dengan unik. Spesifiknya, untuk setiap pasang (i, j), 1 ≤ i, j ≤ N, berlaku:

1. Pi merupakan kelipatan Pj, atau
2. Pj merupakan kelipatan Pi

Saat ini, Pak Chanek memiliki uang sebesar M. Dengan jumlah uang yang terbatas, Pak Chanek ingin memaksimumkan jumlah kuota yang bisa didapatkan. Bantulah Pak Chanek untuk menghitung jumlah kuota maksimum yang bisa didapatkan dengan uang yang dimilikinya! (Dalam hal ini, satu paket data bisa dibeli lebih dari satu kali, dan tidak semua uang harus dihabiskan)

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi sebuah bilangan bulat N dan M, yang menyatakan banyak paket data dan uang yang dimiliki Pak Chanek.
Baris kedua berisi N buah bilangan bulat Pi, harga paket data ke-i.
Baris ketiga berisi N buah bilangan bulat Si, besaran kuota paket data ke-i.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat, jumlah kuota maksimum yang bisa dibeli Pak Chanek.

## Contoh Masukan

	1
	3 24
	2 6 18
	2 2 30

## Contoh Keluaran

	36

## Penjelasan

Pak Chanek dapat membeli 3 paket data ke-1 dan 1 paket data ke-3, sehingga jumlah kuota yang ia dapatkan adalah 3 * 2 + 1 * 30 = 36. Tidak ada pembelian dengan jumlah kuota melebihi 36.

## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 100
- 1 ≤ M ≤ 100.000
- 1 ≤ Pi ≤ 100.000
- 1 ≤ Si ≤ 100.000




# D - Xor-or

| Time Limit   | 4s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Chanekland adalah salah satu pusat hiburan keluarga terbesar yang pernah ada. Ribuan orang datang tiap harinya untuk menikmati berbagai wahana yang tersedia, termasuk wahana terbaru yang baru saja ditambahkan, yaitu Rumah Xor-or.

Rumah Xor-or adalah rumah hantu yang telah dirancang khusus oleh direktur utama Chanekland, Pak Chanek. Rumah Xor-or ini terdiri dari N ruangan dan M koridor. Di Rumah Xor-or, ruangan hanya berfungsi sebagai tempat istirahat, sedangkan hal-hal yang menakutkan akan dialami jika melewati koridor. Sebuah koridor menghubungkan dua ruangan yang mungkin saja sama, dan memiliki suatu nilai keseraman. Rumah Xor-or memiliki beberapa bagian berbeda, sehingga mungkin saja terdapat ruangan-ruangan yang tidak terhubung melalui koridor-koridor yang ada.

Karena Pak Chanek tidak ingin membuat pengunjungnya bosan, ia telah merancang Rumah Xor-or supaya berbeda dengan rumah hantu lainnya. Untuk membandingkan keunikan Rumah Xor-or dengan rumah hantu lainnya, Pak Chanek menggunakan suatu pengukuran nilai keunikan. Nilai keunikan Rumah Xor-or dapat dihitung sebagai berikut:

- Buat suatu himpunan S(i, j) untuk semua 1 ≤ i < j ≤ N, yang mana anggota dari S(i, j) memuat semua kemungkinan nilai keseraman rute yang mungkin dari ruangan ke-i ke ruangan ke-j. Nilai keseraman rute dihitung dengan melakukan operasi bitwise XOR kepada semua nilai keseraman koridor yang dilewati. Dalam satu rute, suatu ruangan atau koridor dapat dilewati lebih dari sekali.
- Tentukan suatu nilai F(i, j) untuk semua 1 ≤ i < j ≤ N, yang mana F(i, j) merupakan hasil dari operasi bitwise OR kepada semua anggota S(i, j). Apabila S(i, j) adalah himpunan kosong, maka F(i, j) = 0.
- Nilai keunikan Rumah Xor-or adalah total dari F(i, j) untuk semua 1 ≤ i < j ≤ N.

Karena rumitnya perhitungan ini, Pak Chanek tidak bisa menghitungnya sendiri. Anda, sebagai teman baik Pak Chanek, diminta untuk membantu Pak Chanek menghitung nilai keunikan Rumah Xor-or Chanekland.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi dua bilangan bulat N dan M, banyak ruangan dan banyak koridor.

M baris berikutnya masing-masing berisi Ui, Vi, dan Wi, yang menyatakan bahwa koridor ke-i menghubungkan Ui dan Vi dan memiliki nilai keseraman Wi.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi satu bilangan bulat, nilai keunikan dari Rumah Xor-or Chanekland.

## Contoh Masukan

	1
	4 3
	1 2 1
	2 3 2
	3 1 7

## Contoh Keluaran

	18

## Penjelasan

Pada contoh di atas, semua kemungkinan S(i, j) adalah sebagai berikut:

- S(1, 2) = {1, 5}
- S(1, 3) = {3, 7}
- S(1, 4) = {}
- S(2, 3) = {2, 6}
- S(2, 4) = {}
- S(3, 4) = {}

Semua kemungkinan F(i, j) adalah sebagai berikut:

- F(1, 2) = 5
- F(1, 3) = 7
- F(1, 4) = 0
- F(2, 3) = 6
- F(2, 4) = 0
- F(3, 4) = 0

Sehingga nilai keunikan Rumah Xor-or adalah 5 + 7 + 0 + 6 + 0 + 0 = 18.

## Batasan

- 1 ≤ T ≤ 8
- 2 ≤ N ≤ 30.000
- 1 ≤ M ≤ 50.000
- 1 ≤ Ui, Vi ≤ N
- 1 ≤ Wi ≤ 109

## Catatan

Operasi bitwise XOR dari dua buah bilangan bulat non-negatif P dan Q dihitung dengan cara berikut:

- Ubah P dan Q ke dalam biner
- Lakukan operasi XOR untuk setiap pasang bit yang bersesuaian, dimana:

0 XOR 0 = 0

0 XOR 1 = 1

1 XOR 0 = 1

1 XOR 1 = 0

- Ubah hasil XOR yang didapat kembali ke basis sepuluh.

Sebagai contoh, 5 XOR 6 = 3, karena 5 = 101 dalam biner dan 6 = 110 dalam biner. Sehingga didapat XOR nya adalah 011 = 3 dalam basis sepuluh.

Operasi bitwise OR dari dua buah bilangan bulat non-negatif P dan Q dihitung dengan cara berikut:

- Ubah P dan Q ke dalam biner
- Lakukan operasi OR untuk setiap pasang bit yang bersesuaian, dimana:

0 OR 0 = 0

0 OR 1 = 1

1 OR 0 = 1

1 OR 1 = 1

- Ubah hasil OR yang didapat kembali ke basis sepuluh.

Sebagai contoh, 5 OR 6 = 7, karena 5 = 101 dalam biner dan 6 = 110 dalam biner. Sehingga didapat OR nya adalah 111 = 7 dalam basis sepuluh.





# E - Menginap

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Keponakan Pak Chanek, Chaneka, sedang berkunjung ke rumah Pak Chanek. Karena saat itu sedang libur panjang, Chaneka memutuskan untuk menginap di rumah Pak Chanek. Kebetulan, ada kamar kosong di rumah Pak Chanek.

Setelah malam kedua Chaneka menginap, Pak Chanek menyadari bahwa Chaneka memiliki kebiasaan unik. Setiap malam, ia akan keluar kamarnya N kali, masing-masing dalam suatu interval tertentu. Pada kali ke-i, Chaneka pasti akan keluar kamar pada waktu Li, dan akan kembali pada waktu yang berada pada interval (Li, Ri) (eksklusif kiri dan kanan). Untuk setiap interval, peluang Chaneka kembali pada interval (Li, Ri) terdistribusi secara uniform. Waktu kembalinya Chaneka tidak harus berupa bilangan bulat.

Sekarang, Pak Chanek menjadi penasaran, berapa nilai harapan total lama waktu Chaneka keluar ruangan? Bantulah Pak Chanek menjawab pertanyaan tersebut!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.
Baris pertama berisi sebuah bilangan bulat N, yang menyatakan berapa kali Chaneka keluar kamar.
N baris berikutnya berisi dua buah bilangan bulat Li dan Ri, yang menyatakan pada kali ke-i, Chaneka keluar kamar pada waktu Li dan akan kembali pada interval (Li, Ri).

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan real yang menyatakan nilai harapan lama Chaneka keluar dari kamar. Keluarkan jawaban hingga tepat satu angka di belakang koma. Jawaban Anda harus sama persis dengan jawaban juri.

## Contoh Masukan

	1
	3
	1 2
	3 4
	5 7

## Contoh Keluaran

	2.0

## Batasan

- 1 ≤ T ≤ 100
- 1 ≤ N ≤ 1.000
- 1 ≤ Li < Ri ≤ 109
- Ri < Li+1 untuk setiap 1 ≤ i < N






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




# H - Perjalanan Aneh

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pada suatu pagi, seperti biasa Pak Chanek bangun di rumahnya yang berada di kota 1. Setelah mandi dan bersiap-siap, Pak Chanek lalu pergi ke kantornya yang berada di kota N. Namun, ternyata selama ia tidur terjadi hal aneh di jalan-jalan di negaranya, yakni Indopura.

Terdapat N kota dan M jalan dua arah di negara Indopura. Jalan ke-i menghubungkan kota Ui dan kota Vi. Dengan menggunakan jalan yang ada, dari setiap kota, seseorang dapat mengunjungi seluruh kota lainnya menggunakan satu atau lebih jalan.

Akibat hal aneh pada malam sebelumnya, setiap jalan menjadi memiliki nilai Bi dan Xi. Selanjutnya, waktu yang diperlukan untuk menempuh jalan ke-i menjadi cukup aneh. Waktu yang diperlukan untuk menempuh jalan ke-i menjadi max(1, Bi - t * Xi), dengan t menyatakan waktu ketika seseorang mulai menempuh jalan tersebut. Selain itu, terdapat aturan aneh lainnya. Seseorang boleh saja menunggu di suatu kota sebelum mulai menempuh suatu jalan, dengan syarat waktu menunggu tersebut harus berupa bilangan bulat.

Karena hampir terlambat, Pak Chanek ingin mencari waktu tercepat yang ia butuhkan untuk mencapai kantornya yang berada di kota N. Pak Chanek memulai perjalanan pada waktu 0. Bantulah Pak Chanek!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.
Baris pertama berisi dua buah bilangan bulat N dan M, masing-masing menyatakan banyak kota dan banyak jalan di Indopura.
M baris selanjutnya berisi Ui, Vi, Bi, dan Xi, yang menyatakan jalan ke-i menghubungkan kota ke-Ui dan kota ke-Vi, dan konstanta dalam menentukan waktu untuk menempuh jalan ke-i.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat yang menyatakan waktu tercepat yang dibutuhkan Pak Chanek untuk mencapai kota N.

## Contoh Masukan

	1
	4 4
	1 2 4 2
	1 3 9 3
	4 2 10 7
	3 4 9 6

## Contoh Keluaran

	4

## Penjelasan

Salah satu cara yang bisa dilakukan Pak Chanek adalah sebagai berikut:

- Menunggu di kota 1 hingga waktu 2, lalu menempuh jalan ke-1 dengan waktu menempuh max(1, 4 - 2 * 2) = 1, dan mencapai kota 2 pada waktu 3.
- Menempuh jalan ke-3 pada waktu 3 dengan waktu menempuh max(1, 10 - 3 * 7) = 1, dan mencapai kota 4 pada waktu 4.

## Batasan

- 1 ≤ T ≤ 8
- 1 ≤ N ≤ 50.000
- 1 ≤ M ≤ 100.000
- 1 ≤ Ui, Vi ≤ N
- 0 ≤ Bi ≤ 106
- 0 ≤ Xi ≤ 106



# I - Percobaan Median

| Time Limit   | 3500ms |
|--------------|--------|
| Memory Limit | 64MB   |

## Deskripsi

Pak Chanek sedang melakukan percobaan yang berhubungan dengan median dari suatu baris bilangan. Dalam menyiapkan bahan percobaannya, Pak Chanek meminta barisan bilangan dari 2 orang temannya, Bdawg dan Synd. Pak Chanek menerima barisan B dari Bdawg, dan barisan S dari Synd. Kedua barisan bilangan yang diterima Pak Chanek masing-masing terdiri dari N bilangan bulat.

Dalam percobaannya, Pak Chanek memiliki suatu konstanta yang bernilai K (bilangan bulat) yang dinamakan konstanta Chanek. Pak Chanek akan menggabungkan subbarisan dengan panjang K dari barisan bilangan milik Bdawg dan subbarisan dengan panjang K dari barisan bilangan milik Synd. Kemudian, Pak Chanek mengambil median (lihat catatan) dari hasil penggabungan kedua subbarisan tersebut. Pak Chanek akan melakukan hal tersebut untuk seluruh (N-K+1)2 kemungkinan pasangan subbarisan dengan panjang K, masing-masing tepat sekali, kemudian mengumpulkan semua nilai median hasil penggabungannya. Kemudian, Pak Chanek mengambil nilai median dari kumpulan nilai median yang didapat sebelumnya. Nilai median dari kumpulan nilai median tersebut dinamakan nilai median akhir dari dua barisan bilangan.

Pak Chanek mulai lelah dalam mencari nilai median akhir dari kedua barisan bilangan tersebut. Pak Chanek meminta bantuan Anda untuk membuat program untuk mencari nilai median akhir dari dua buah barisan B dan S. Bantulah Pak Chanek!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi dua buah bilangan bulat N dan K, yaitu banyaknya bilangan dari setiap barisan bilangan teman Pak Chanek dan konstanta Chanek.

Baris kedua berisi N buah bilangan bulat Bi yang menyatakan bilangan ke-i dari barisan bilangan B.

Baris ketiga berisi N buah bilangan bulat Si yang menyatakan bilangan ke-i dari barisan bilangan S.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi sebuah bilangan bulat yang menyatakan nilai median akhir dari barisan bilangan B dan S.

## Contoh Masukan

	1
	3 2
	7 4 1
	1 5 3

## Contoh Keluaran

	5

## Penjelasan

Pada kasus uji pertama, diketahui barisan B = [7, 4, 1] dan barisan S = [1, 5, 3], serta konstanta Chanek  bernilai 2.

Barisan B dan S masing-masing terdiri dari 3 bilangan. Terdapat (3-2+1)2 = 4 kemungkinan pasangan subbarisan B dan S:

1. Subbarisan [7, 4] dengan subbarisan [1, 5], nilai median dari hasil penggabungannya adalah 5.
2. Subbarisan [7, 4] dengan subbarisan [5, 3], nilai median dari hasil penggabungannya adalah 5.
3. Subbarisan [4, 1] dengan subbarisan [1, 5], nilai median dari hasil penggabungannya adalah 4.
4. Subbarisan [4, 1] dengan subbarisan [5, 3], nilai median dari hasil penggabungannya adalah 4.

Terlihat bahwa nilai median dari kumpulan nilai median diatas adalah 5. Maka, nilai median akhir dari B dan S adalah 5.

## Batasan

- 1 ≤ T ≤ 8
- 1 ≤ N ≤ 50.000
- 1 ≤ K ≤ N
- 1 ≤ Bi, Si ≤ 109

