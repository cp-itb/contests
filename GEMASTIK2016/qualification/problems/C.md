# C - Menggemaskan dan Cantik

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
- 6 ≤ N ≤ 50.000
- S[i] terdiri atas 1 sampai dengan 8 karakter a - z
- Semua nama dijamin berbeda-beda
- 1 ≤ G[i], C[i] ≤ 100.000
