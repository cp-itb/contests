# Problems

- [A1 - Foto Wisuda (Mudah)](#a1---foto-wisuda-mudah)
- [A2 - Foto Wisuda (Sulit)](#a2---foto-wisuda-sulit)
- [B1 - Menggemaskan dan Cantik (Mudah)](#b1---menggemaskan-dan-cantik-mudah)
- [B2 - Menggemaskan dan Cantik (Sulit)](#b2---menggemaskan-dan-cantik-sulit)
- [C1 - Papan Selancar (Mudah)](#c1---papan-selancar-mudah)
- [C2 - Papan Selancar (Sulit)](#c2---papan-selancar-sulit)

# A1 - Foto Wisuda (Mudah)

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

UI baru saja melaksanakan wisuda di Balairung. Seperti biasa, mendadak halaman newsfeed Facebook dipenuhi oleh foto-foto para sarjana. Iseng-iseng, Anda ingin memperkirakan seberapa banyak orang yang hadir di Balairung pada wisuda tersebut.

Anda membuka-buka newsfeed Facebook Anda. Anda mengamati bahwa terdapat N buah foto. Untuk setiap foto, diketahui:

- Siapa saja orang yang terdapat pada foto tersebut (menggunakan fitur tag Facebook).
- Apakah foto tersebut merupakan selfie atau bukan (menggunakan aplikasi selfie detector dari salah satu lab riset di UI). Apabila foto tersebut bukan selfie, berarti ada tepat satu orang lain yang memotret orang-orang pada foto.

Dengan berasumsi tidak ada dua orang dengan nama yang sama, ada berapa maksimum orang yang Anda yakini hadir di Balairung pada wisuda yang lalu? Dengan kata lain, paling sedikit ada berapa orang yang dipotret atau memotret setidaknya sekali di Balairung pada wisuda yang lalu?

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji. Baris-baris berikutnya berisi T kasus uji, yang masing-masing diberikan dalam format berikut ini:

	N
	S[1] K[1] P[1][1] P[1][2] .. P[1][K[1]]
	S[2] K[2] P[2][1] P[2][2] .. P[2][K[2]]
	.
	.
	S[N] K[N] P[N][1] P[N][2] .. P[N][K[N]]
dengan:

- S[i] adalah selfie bila foto ke-i diambil secara selfie, dan dibantu bila foto ke-i diambil dengan bantuan tepat satu orang lain
- K[i] menyatakan banyak orang pada foto ke-i
- P[i][j] menyatakan nama orang ke-j pada foto ke-i

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah baris berisi banyaknya orang maksimum yang Anda yakini hadir di Balairung pada wisuda yang lalu.

## Contoh Masukan

	2
	1
	selfie 2 ani budi
	1
	dibantu 1 ani

## Contoh Keluaran

	2
	2

## Penjelasan

Untuk contoh masukan pertama, Anda yakin terdapat setidaknya 2 orang yang hadir: ani dan budi.

Untuk contoh masukan kedua, Anda yakin terdapat setidaknya 2 orang yang hadir: ani dan satu orang lain yang tidak diketahui namanya berdasarkan informasi yang ada.

## Batasan

- 1 ≤ T ≤ 5
- 1 ≤ K[i] ≤ 10
- S[i] adalah salah satu dari selfie dan dibantu
- Setiap nama orang (P[i][j]) terdiri atas 1 sampai dengan 8 karakter a - z
- Dalam masing-masing foto, dijamin tidak ada nama yang tertera lebih dari sekali

## Batasan Khusus Versi Mudah

Soal ini adalah soal versi mudah. Batasan di bawah ini juga berlaku, namun akan berbeda pada soal versi sulit:

N = 1





# A2 - Foto Wisuda (Sulit)

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

UI baru saja melaksanakan wisuda di Balairung. Seperti biasa, mendadak halaman newsfeed Facebook dipenuhi oleh foto-foto para sarjana. Iseng-iseng, Anda ingin memperkirakan seberapa banyak orang yang hadir di Balairung pada wisuda tersebut.

Anda membuka-buka newsfeed Facebook Anda. Anda mengamati bahwa terdapat N buah foto. Untuk setiap foto, diketahui:

- Siapa saja orang yang terdapat pada foto tersebut (menggunakan fitur tag Facebook).
- Apakah foto tersebut merupakan selfie atau bukan (menggunakan aplikasi selfie detector dari salah satu lab riset di UI). Apabila foto tersebut bukan selfie, berarti ada tepat satu orang lain yang memotret orang-orang pada foto.

Dengan berasumsi tidak ada dua orang dengan nama yang sama, ada berapa maksimum orang yang Anda yakini hadir di Balairung pada wisuda yang lalu? Dengan kata lain, paling sedikit ada berapa orang yang dipotret atau memotret setidaknya sekali di Balairung pada wisuda yang lalu?

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji. Baris-baris berikutnya berisi T kasus uji, yang masing-masing diberikan dalam format berikut ini:

	N
	S[1] K[1] P[1][1] P[1][2] .. P[1][K[1]]
	S[2] K[2] P[2][1] P[2][2] .. P[2][K[2]]
	.
	.
	S[N] K[N] P[N][1] P[N][2] .. P[N][K[N]]
dengan:

- S[i] adalah selfie bila foto ke-i diambil secara selfie, dan dibantu bila foto ke-i diambil dengan bantuan tepat satu orang lain
- K[i] menyatakan banyak orang pada foto ke-i
- P[i][j] menyatakan nama orang ke-j pada foto ke-i

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah baris berisi banyaknya orang maksimum yang Anda yakini hadir di Balairung pada wisuda yang lalu.

## Contoh Masukan

	2
	1
	selfie 2 ani budi
	1
	dibantu 1 ani

## Contoh Keluaran

	2
	2

## Penjelasan

Untuk contoh masukan pertama, Anda yakin terdapat setidaknya 2 orang yang hadir: ani dan budi.

Untuk contoh masukan kedua, Anda yakin terdapat setidaknya 2 orang yang hadir: ani dan satu orang lain yang tidak diketahui namanya berdasarkan informasi yang ada.

## Batasan

- 1 ≤ T ≤ 5
- 1 ≤ K[i] ≤ 10
- S[i] adalah salah satu dari selfie dan dibantu
- Setiap nama orang (P[i][j]) terdiri atas 1 sampai dengan 8 karakter a - z
- Dalam masing-masing foto, dijamin tidak ada nama yang tertera lebih dari sekali

## Batasan Khusus Versi Sulit

Soal ini adalah soal versi sulit. Batasan di bawah ini juga berlaku, namun akan berbeda pada soal versi mudah:

1 ≤ N ≤ 100





# B1 - Menggemaskan dan Cantik (Mudah)

| Time Limit   | 4s    |
|--------------|-------|
| Memory Limit | 256MB |

## Deskripsi

Sebentar lagi, kompetisi paling bergengsi se-Indonesia akan diadakan! Apa lagi kalau bukan Kompetisi Menggemaskan dan Cantik (geMasTIK). Seperti biasa, geMasTIK tahun ini terdiri atas dua kategori kompetisi: Kompetisi KegeMasan dan Kompetisi KecanTIKan.

Setiap perwakilan universitas berhak mengirimkan tepat satu tim untuk masing-masing kategori. Setiap tim harus terdiri atas tepat 3 orang. Selain itu, setiap orang tidak boleh ikut lebih dari satu kategori. Tahun ini, Anda ditugaskan oleh pihak kampus untuk mengatur pembagian tim sedemikian rupa agar universitas Anda dapat memenangkan geMasTIK.

Terdapat tepat N mahasiswa yang memenuhi syarat bertanding pada geMasTIK. Mahasiswa ke-i memiliki 2 nilai keahlian, yakni G[i] dan C[i]. G[i] menandakan seberapa menggemaskan mahasiswa tersebut, sedangkan C[i] menandakan seberapa cantik mahasiswa tersebut. Kekuatan suatu tim adalah hasil perkalian dari keahlian masing-masing anggotanya.

Anda berencana untuk mengirimkan tepat 2 tim. Tim pertama akan dikirim untuk mengikuti kontes KegeMasan, sementara kelompok kedua akan dikirim untuk mengikuti kontes KecanTIKan. Anda diminta mengatur pembagian tim sedemikian rupa sehingga kekuatan KegeMasan kelompok pertama ditambah kekuatan KecanTIKan kelompok kedua, sebesar mungkin. Dengan kata lain, misalkan indeks-indeks anggota kelompok pertama adalah a, b, c, sementara kelompok kedua adalah x, y, dan z. Carilah pembagian sedemikian sehingga nilai (G[a] × G[b] × G[c]) + (C[x] × C[y] × C[z]) maksimum.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi sebuah bilangan bulat N. N baris berikutnya masing-masing berisi string S[i] (menyatakan nama mahasiswa ke-i), dan dua buah bilangan bulat G[i] dan C[i].

## Format Keluaran

Untuk setiap kasus uji:

Keluaran terdiri atas 3 baris.

Baris pertama berisi sebuah integer yang menyatakan total kekuatan kedua kelompok.

Baris kedua berisi 3 string yang dipisahkan spasi yang merupakan nama-nama anggota kelompok 1 (kategori KegeMasan)

Baris ketiga terdiri dari 3 string yang dipisahkan spasi yang merupakan nama-nama anggota kelompok 2 (kategori KecanTIKan)

Jika ada lebih dari satu cara membagi kelompok yang menghasilkan total kekuatan terbesar, **keluarkan yang mana saja**.

## Contoh Masukan

    3
    6
    dana 10 9
    dini 10 9
    dani 10 9
    dono 9 10
    dona 9 10
    dina 9 10
    9
    abdul 3 3
    afaji 7 6
    alham 10 6
    alice 7 10
    budi 5 3
    jack 3 10
    kwak 10 10
    kwek 2 6
    kwok 5 8
    11
    charlie 11 60
    eko 70 32
    fauzan 101 101
    victor 99 103
    halim 103 10
    mona 16 100
    ridho 20 64
    sherly 54 85
    ahmad 100 3
    bambang 40 23
    wawan 74 19

## (Salah Satu Cara) Contoh Keluaran

    2000
    dana dini dani
    dono dona dina
    1500
    afaji alham kwak
    alice jack kwok
    1915800
    fauzan halim ahmad
    victor mona sherly

## Batasan

- 1 ≤ T ≤ 10
- S[i] terdiri atas 1 sampai dengan 8 karakter a - z
- Semua nama dijamin berbeda-beda
- 1 ≤ G[i], C[i] ≤ 100.000

## Batasan Khusus Versi Mudah

Soal ini adalah soal versi mudah. Batasan di bawah ini juga berlaku, namun akan berbeda pada soal versi sulit:

- 6 ≤ N ≤ 15



# B2 - Menggemaskan dan Cantik (Sulit)

| Time Limit   | 4s    |
|--------------|-------|
| Memory Limit | 256MB |

## Deskripsi

Sebentar lagi, kompetisi paling bergengsi se-Indonesia akan diadakan! Apa lagi kalau bukan Kompetisi Menggemaskan dan Cantik (geMasTIK). Seperti biasa, geMasTIK tahun ini terdiri atas dua kategori kompetisi: Kompetisi KegeMasan dan Kompetisi KecanTIKan.

Setiap perwakilan universitas berhak mengirimkan tepat satu tim untuk masing-masing kategori. Setiap tim harus terdiri atas tepat 3 orang. Selain itu, setiap orang tidak boleh ikut lebih dari satu kategori. Tahun ini, Anda ditugaskan oleh pihak kampus untuk mengatur pembagian tim sedemikian rupa agar universitas Anda dapat memenangkan geMasTIK.

Terdapat tepat N mahasiswa yang memenuhi syarat bertanding pada geMasTIK. Mahasiswa ke-i memiliki 2 nilai keahlian, yakni G[i] dan C[i]. G[i] menandakan seberapa menggemaskan mahasiswa tersebut, sedangkan C[i] menandakan seberapa cantik mahasiswa tersebut. Kekuatan suatu tim adalah hasil perkalian dari keahlian masing-masing anggotanya.

Anda berencana untuk mengirimkan tepat 2 tim. Tim pertama akan dikirim untuk mengikuti kontes KegeMasan, sementara kelompok kedua akan dikirim untuk mengikuti kontes KecanTIKan. Anda diminta mengatur pembagian tim sedemikian rupa sehingga kekuatan KegeMasan kelompok pertama ditambah kekuatan KecanTIKan kelompok kedua, sebesar mungkin. Dengan kata lain, misalkan indeks-indeks anggota kelompok pertama adalah a, b, c, sementara kelompok kedua adalah x, y, dan z. Carilah pembagian sedemikian sehingga nilai (G[a] × G[b] × G[c]) + (C[x] × C[y] × C[z]) maksimum.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi sebuah bilangan bulat N. N baris berikutnya masing-masing berisi string S[i] (menyatakan nama mahasiswa ke-i), dan dua buah bilangan bulat G[i] dan C[i].

## Format Keluaran

Untuk setiap kasus uji:

Keluaran terdiri atas 3 baris.

Baris pertama berisi sebuah integer yang menyatakan total kekuatan kedua kelompok.

Baris kedua berisi 3 string yang dipisahkan spasi yang merupakan nama-nama anggota kelompok 1 (kategori KegeMasan)

Baris ketiga terdiri dari 3 string yang dipisahkan spasi yang merupakan nama-nama anggota kelompok 2 (kategori KecanTIKan)

Jika ada lebih dari satu cara membagi kelompok yang menghasilkan total kekuatan terbesar, **keluarkan yang mana saja**.

## Contoh Masukan

    3
    6
    dana 10 9
    dini 10 9
    dani 10 9
    dono 9 10
    dona 9 10
    dina 9 10
    9
    abdul 3 3
    afaji 7 6
    alham 10 6
    alice 7 10
    budi 5 3
    jack 3 10
    kwak 10 10
    kwek 2 6
    kwok 5 8
    11
    charlie 11 60
    eko 70 32
    fauzan 101 101
    victor 99 103
    halim 103 10
    mona 16 100
    ridho 20 64
    sherly 54 85
    ahmad 100 3
    bambang 40 23
    wawan 74 19

## (Salah Satu Cara) Contoh Keluaran

    2000
    dana dini dani
    dono dona dina
    1500
    afaji alham kwak
    alice jack kwok
    1915800
    fauzan halim ahmad
    victor mona sherly

## Batasan

- 1 ≤ T ≤ 10
- S[i] terdiri atas 1 sampai dengan 8 karakter a - z
- Semua nama dijamin berbeda-beda
- 1 ≤ G[i], C[i] ≤ 100.000

## Batasan Khusus Versi Sulit

Soal ini adalah soal versi sulit. Batasan di bawah ini juga berlaku, namun akan berbeda pada soal versi mudah:

- 6 ≤ N ≤ 50.000




# C1 - Papan Selancar (Mudah)

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Setelah geMasTIK berakhir, Ani beserta peserta lainnya diajak pergi ke pantai oleh panitia sebagai salah satu rangkaian acara. Sebagian peserta langsung menceburkan diri ke laut untuk berenang. Amat disayangkan, karena Ani tidak bisa berenang, ia memutuskan untuk duduk-duduk saja di pinggir pantai. Kebetulan, ia melihat ada papan selancar di dekatnya. Ia lalu berinisiatif untuk bermain-main pasir dengan papan selancar tersebut.

Panjang papan selancar tersebut adalah N meter. Untuk kemudahan, papan selancar tersebut dibagi atas N buah posisi, yakni 1 sampai dengan N dari kiri ke kanan. Lalu, iseng-iseng, Ani menabur-naburkan pasir di atas papan tersebut. Ani melakukan tepat M buah taburan. Setiap taburan memiliki dua parameter: x, yakni posisi di mana Ani menaburkan pasir, dan k, yakni banyaknya pasir pada posisi tersebut.

Angin di pantai tersebut lumayan kencang. Oleh karena itu, setiap kali Ani menaburkan pasir sebanyak k pada posisi x, hal berikut akan terjadi:

- Tinggi pasir pada posisi x bertambah sebesar k.
- Tinggi pasir pada posisi x-1 bertambah sebesar k-1.
- Tinggi pasir pada posisi x+1 bertambah sebesar k-1.
- Tinggi pasir pada posisi x-2 bertambah sebesar k-2.
- Tinggi pasir pada posisi x+2 bertambah sebesar k-2.
- … dan seterusnya sampai pertambahan tinggi pasir menjadi 0 (k-k).

Setelah melakukan M taburan, mendadak ombak besar datang dan menghempaskan karya Ani. Ani pun menjadi sedih. Anda yang merupakan teman dekat Ani (dan baru selesai berenang), ingin membantu Ani membuat kembali "bangunan pasir" tersebut. Beruntung, Ani ingat persis setiap kegiatan taburan yang ia lakukan. Tentukan tinggi pasir pada setiap posisi agar Anda bisa membuat kembali bangunan pasir Ani!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji. Baris-baris berikutnya berisi T kasus uji, yang masing-masing diberikan dalam format berikut ini:

	N M
	x[1] k[1]
	x[2] k[2]
	.
	.
	x[M] k[M]

## Format Keluaran

Untuk setiap kasus uji, keluarkan jawaban dalam format berikut ini:

	H[1] H[2] .. H[N]

dengan H[i] menyatakan tinggi pasir pada posisi ke-i.

## Contoh Masukan

	2
	7 4
	4 3
	1 2
	5 1
	4 2
	2 2
	1 100
	2 100

## Contoh Keluaran

	2 2 3 5 4 1 0
	199 199

## Batasan

- 1 ≤ T ≤ 5
- 1 ≤ x[i] ≤ N
- 1 ≤ k[i] ≤ 50.000

## Batasan Khusus Versi Mudah

Soal ini adalah soal versi mudah. Batasan di bawah ini juga berlaku, namun akan berbeda pada soal versi sulit:

- 1 ≤ N, M ≤ 1.000




# C2 - Papan Selancar (Sulit)

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Setelah geMasTIK berakhir, Ani beserta peserta lainnya diajak pergi ke pantai oleh panitia sebagai salah satu rangkaian acara. Sebagian peserta langsung menceburkan diri ke laut untuk berenang. Amat disayangkan, karena Ani tidak bisa berenang, ia memutuskan untuk duduk-duduk saja di pinggir pantai. Kebetulan, ia melihat ada papan selancar di dekatnya. Ia lalu berinisiatif untuk bermain-main pasir dengan papan selancar tersebut.

Panjang papan selancar tersebut adalah N meter. Untuk kemudahan, papan selancar tersebut dibagi atas N buah posisi, yakni 1 sampai dengan N dari kiri ke kanan. Lalu, iseng-iseng, Ani menabur-naburkan pasir di atas papan tersebut. Ani melakukan tepat M buah taburan. Setiap taburan memiliki dua parameter: x, yakni posisi di mana Ani menaburkan pasir, dan k, yakni banyaknya pasir pada posisi tersebut.

Angin di pantai tersebut lumayan kencang. Oleh karena itu, setiap kali Ani menaburkan pasir sebanyak k pada posisi x, hal berikut akan terjadi:

- Tinggi pasir pada posisi x bertambah sebesar k.
- Tinggi pasir pada posisi x-1 bertambah sebesar k-1.
- Tinggi pasir pada posisi x+1 bertambah sebesar k-1.
- Tinggi pasir pada posisi x-2 bertambah sebesar k-2.
- Tinggi pasir pada posisi x+2 bertambah sebesar k-2.
- … dan seterusnya sampai pertambahan tinggi pasir menjadi 0 (k-k).

Setelah melakukan M taburan, mendadak ombak besar datang dan menghempaskan karya Ani. Ani pun menjadi sedih. Anda yang merupakan teman dekat Ani (dan baru selesai berenang), ingin membantu Ani membuat kembali "bangunan pasir" tersebut. Beruntung, Ani ingat persis setiap kegiatan taburan yang ia lakukan. Tentukan tinggi pasir pada setiap posisi agar Anda bisa membuat kembali bangunan pasir Ani!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji. Baris-baris berikutnya berisi T kasus uji, yang masing-masing diberikan dalam format berikut ini:

	N M
	x[1] k[1]
	x[2] k[2]
	.
	.
	x[M] k[M]

## Format Keluaran

Untuk setiap kasus uji, keluarkan jawaban dalam format berikut ini:

	H[1] H[2] .. H[N]

dengan H[i] menyatakan tinggi pasir pada posisi ke-i.

## Contoh Masukan

	2
	7 4
	4 3
	1 2
	5 1
	4 2
	2 2
	1 100
	2 100

## Contoh Keluaran

	2 2 3 5 4 1 0
	199 199

## Batasan

- 1 ≤ T ≤ 5
- 1 ≤ x[i] ≤ N
- 1 ≤ k[i] ≤ 50.000

## Batasan Khusus Versi Sulit

Soal ini adalah soal versi sulit. Batasan di bawah ini juga berlaku, namun akan berbeda pada soal versi mudah:

- 1 ≤ N, M ≤ 50.000

