# Problems

- [A - Membangun Menara](#a---membangun-menara)
- [B - Kode Keras](#b---kode-keras)
- [C - Menggemaskan dan Cantik](#c---menggemaskan-dan-cantik)
- [D - Saklar Lhompat](#d---saklar-lhompat)
- [E - Libur Tahun Baru](#e---libur-tahun-baru)
- [F - Kartu Truf](#f---kartu-truf)

# A - Membangun Menara

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Untuk mempersiapkan geMasTIK, William selaku kepala divisi dekorasi berniat untuk membangun sebuah menara yang akan digunakan sebagai hiasan gapura. Menara ini dibangun menggunakan balok-balok dengan berbagai ukuran. William memiliki N buah balok. Balok ke-i memiliki dimensi A[i] × B[i] × C[i]. Balok-balok tersebut akan ditumpuk-tumpuk hingga membentuk menara.

William ingin tahu, berapa tinggi menara paling tinggi yang mungkin dibentuk, serta tinggi menara paling rendah yang mungkin dibentuk jika semua balok dipakai dalam penyusunan menara. Dalam penyusunannya, balok-balok tersebut boleh diputar sesuai keinginan. William memberikan tugas kepada Anda (sebagai wakil kepala divisi) untuk mencari tahu hal tersebut.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi sebuah bilangan bulat N. N baris berikutnya masing-masing berisi tiga buah bilangan bulat A[i], B[i], dan C[i].

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah baris berisi dua buah bilangan bulat L dan H. L menyatakan tinggi menara minimum, dan H menyatakan tinggi menara maksimum.

## Contoh Masukan

    3
    3
    1 2 3
    5 4 6
    9 8 7
    1
    6 6 6
    2
    1 1 1
    10 20 30

## Contoh Keluaran

    12 18
    6 6
    11 31

## Batasan

- 1 ≤ T ≤ 20
- 1 ≤ N ≤ 100
- 1 ≤ A[i], B[i], C[i] ≤ 1.000



# B - Kode Keras

| Time Limit   | 1s    |
|--------------|-------|
| Memory Limit | 256MB |

## Deskripsi

Niken adalah seorang gadis yang sedang amat mendambakan pasangan hidup. Niken sebenarnya punya banyak teman yang ia harapkan bisa menjadi pasangan hidupnya. Namun, Niken adalah tipe orang yang tidak berkata langsung, melainkan melalui kode-kode.

Niken melakukan kode dengan cara menulis status-status bertemakan cinta pada sosial media (misalnya Facebook), dan berharap sang pujaan hati melihat postingan tersebut dan tergerak hatinya. Jika Niken menulis status pada suatu waktu tertentu, maka semua teman Niken yang online pada waktu tersebut akan melihat status tersebut. Tentu Niken tidak mau kode ini salah sasaran. Oleh karena itu, ia berniat menulis status berkali-kali, dengan tujuan sang pujaan hati melihat kode Niken lebih banyak dibandingkan teman-teman Niken yang lain. Tetapi Niken juga tidak mau menulis status terlalu banyak, karena khawatir dinilai terlalu galau oleh teman- temannya.

Anda diberikan N yang menyatakan banyaknya teman Niken, serta rentang waktu kapan teman ke-i tersebut online dalam S[i] dan E[i]. Suatu status akan dibaca oleh teman ke-i apabila status tersebut ditulis pada waktu X yang memenuhi

S[i] ≤ X < E[i]

Karena Niken merahasiakan kepada Anda siapa pujaan hatinya, Anda harus mencari tahu untuk setiap i, berapa status minimum yang harus ditulis jika Niken ingin melakukan kode terhadap teman ke-i. Dengan kata lain, Anda ingin mencari tahu untuk setiap i, berapa status minimum yang harus ditulis agar teman ke-i melihat status Niken **lebih banyak** daripada setiap teman lainnya.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi sebuah bilangan bulat N. N baris berikutnya masing-masing berisi dua buah string S[i] dan E[i], yang ditulis dalam format waktu `hh:mm:ss`. Waktu paling awal adalah 00:00:00 dan waktu paling akhir adalah 23:59:59.

## Format Keluaran

Untuk setiap kasus uji:

Keluarkan sebuah baris berisi banyaknya status minimum yang harus ditulis untuk melakukan kode kepada teman ke-i, atau -1 apabila hal tersebut tidak mungkin.

## Contoh Masukan

    2
    4
    08:00:00 09:00:00
    08:20:00 08:45:00
    08:05:00 09:40:00
    08:15:00 10:00:00
    3
    00:00:00 00:00:01
    00:00:01 00:00:10
    00:00:02 00:00:10

## Contoh Keluaran

    1
    -1
    2
    1
    1
    1
    -1

## Penjelasan

Untuk contoh masukan pertama:

1. Untuk memberi kode pada teman 1, Niken dapat menulis status pada 08:00:00:
    - Teman 1 melihat status Niken 1 kali.
    - Teman 2, 3, dan 4 tidak pernah melihat status Niken.
2. Niken tidak mungkin memberi kode pada teman 2 karena setiap kali teman 2 melihat status Niken, teman 1 dan 3 pasti juga melihatnya. Tidak mungkin membuat teman 2 melihat status Niken lebih banyak daripada teman 1 dan 3.
3. Untuk memberi kode pada teman 3, Niken dapat menulis status pada 08:10:00 dan 09:20:00:
    - Teman 1 dan 4 melihat status Niken 1 kali.
    - Teman 2 tidak pernah melihat status Niken.
    - Teman 3 melihat status Niken 2 kali.
4. Untuk memberi kode pada teman 4, Niken dapat menulis status pada 09:59:59:
    - Teman 1, 2, dan 3 tidak pernah melihat status Niken.
    - Teman 4 melihat status Niken 1 kali.

Untuk contoh masukan kedua:

1. Untuk memberi kode pada teman 1, Niken dapat menulis status pada suatu waktu sebelum 00:00:01 (tidak harus bulat).
2. Untuk memberi kode pada teman 2, Niken dapat menulis status pada 00:00:01.
3. Niken tidak mungkin memberi kode pada teman 3.


## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 50.000
- Waktu yang direpresentasikan oleh S[i] < waktu yang direpresentasikan oleh E[i]



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



# D - Saklar Lhompat

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pak Fuad adalah dosen yang ditunjuk oleh Universitas XYZ untuk mengoordinasikan jalannya penyisihan geMasTIK kategori pemrograman untuk tim-tim pada universitas tersebut. Agar para mahasiswanya lebih berkonsentrasi untuk mengerjakan soal-soal penyisihan yang akan dimulai seminggu lagi, Pak Fuad memiliki sebuah ide: kerjakan babak penyisihan di sebuah vila!

Terdapat banyak mahasiswa yang akan mengikuti babak penyisihan. Setiap mahasiswa akan membawa tepat satu buah laptop, termasuk satu buah charger-nya. Pak Fuad ingin mempersiapkan stop kontak yang cukup agar semua mahasiswa bisa men-charge laptop pada saat yang bersamaan.

Terdapat dua jenis steker charger laptop para mahasiswa:

- Steker lurus: bisa dipasang pada lubang stop kontak mana saja.

![](https://judgels-competition.gemastik.ui.ac.id/contests/3/problems/8/render/saklar_steker_lurus.png)

Steker bengkok: bisa dipasang pada lubang pada kedua ujung stop kontak dengan normal, atau pada lubang yang bukan ujung, __namun akan selalu memakan tempat sebanyak dua lubang__.

![](https://judgels-competition.gemastik.ui.ac.id/contests/3/problems/8/render/saklar_steker_bengkok.png)​

Di toko listrik langganan Pak Fuad, hanya tersedia stop kontak dengan 4 lubang:

![](https://judgels-competition.gemastik.ui.ac.id/contests/3/problems/8/render/saklar_colokan4.png)

Setiap stop kontak memiliki kabel colokan bertipe lurus.

Diketahui bahwa terdapat L mahasiswa yang memiliki laptop dengan steker lurus, dan B mahasiswa yang memiliki laptop dengan steker bengkok.

Di vila tersebut, sayangnya hanya terdapat 1 buah stop kontak pada dinding yang dapat digunakan untuk men-charge laptop-laptop mahasiswa. Tentu saja, satu buah stop kontak 4 lubang harus dihubungkan pada dinding, kemudian stop-stop kontak 4 lubang lainnya dapat dirangkai sedemikian sehingga banyaknya lubang mencukupi untuk semua laptop.

Supaya tidak terjadi arus pendek (atau **saklarnya lompat** pada bahasa daerah tertentu), Pak Fuad ingin memasang stop kontak sesedikit mungkin. Berapakah banyaknya stop-stop kontak paling sedikit yang harus dibeli supaya pada saat penyisihan berlangsung, semua laptop mahasiswa bisa di-*charge* bersamaan?

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Setiap kasus uji terdiri atas sebuah baris berisi tepat dua buah bilangan bulat L dan B.

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah baris berisi sebuah bilangan bulat yang menyatakan banyaknya stop kontak minimum yang harus dibeli.

## Contoh Masukan

    3
    4 0
    0 4
    8 8

## Contoh Keluaran

    1
    2
    5

## Penjelasan

Untuk contoh masukan pertama, tentunya Pak Fuad cukup membeli 1 stop kontak, lalu mencoloknya pada colokan di dinding. Maka akan tersedia 4 buah lubang yang bisa dipasang untuk 4 buah steker lurus.

Untuk contoh masukan kedua, salah satu cara yang mungkin adalah:

![](https://judgels-competition.gemastik.ui.ac.id/contests/3/problems/8/render/saklar_contoh2.png)

Untuk contoh masukan ketiga, salah satu cara yang mungkin adalah:

![](https://judgels-competition.gemastik.ui.ac.id/contests/3/problems/8/render/saklar_contoh3.png)

## Batasan

- 1 ≤ T ≤ 20
- 0 ≤ L, B ≤ 100
- 2 ≤ L + B



# E - Libur Tahun Baru

| Time Limit   | 3s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Tahun baru hampir tiba. Budi, seorang mahasiswa Fasilkom UI, ingin melepas penat dengan pergi berlibur ke kota Astik. Ia sendiri tinggal di kota Asgem. Ia ingin menyusun rencana perjalanan Asgem — Astik. Oleh karena itu, ia segera pergi ke agen perjalanan terdekat untuk berkonsultasi.

Sang agen menawarkan rute yang terdiri atas N kota sepanjang perjalanan Asgem — Astik. Untuk kemudahan, kota-kota dinomori dari 1 sampai dengan N. Asgem dinomori 1 dan Astik dinomori N. Terdapat dua sarana transportasi yang direkomendasikan: kereta dan pesawat terbang.

Tiket kereta hanya tersedia untuk kota-kota yang bersebelahan. Harga tiket kereta dari kota i ke kota i+1 (untuk i < N) adalah K[i]. Jika Budi naik kereta, maka Budi dapat menikmati pemandangan antarkota. Nilai keindahan perjalanan kereta antara kota i dengan kota i+1 adalah V[i]. Sedangkan, karena sedang promo tahun baru, harga tiket pesawat selalu tetap, yakni sebesar P. Tiket pesawat selalu tersedia dari setiap kota menuju kota manapun, tidak hanya dari kota i ke kota i+1. Akan tetapi, jika Budi naik pesawat, maka Budi tidak dapat menikmati pemandangan kota sama sekali karena berada di atas langit.

Selain itu, Budi ingin sampai ke Astik dengan cepat; oleh karena itu, Budi tidak ingin membeli selalu membeli tiket dari suatu kota menuju kota dengan nomor yang lebih besar (tidak pernah mundur).

Budi hanya punya anggaran sebesar S. Bantulah Budi untuk merancang perjalanan dari Asgem ke Astik agar total keindahan perjalanannya sebesar mungkin!

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi tiga buah bilangan bulat N, S, dan P. N - 1 baris berikutnya masing-masing dua buah bilangan bulat K[i] dan V[i].

## Format Keluaran

Lorem ipsum.Untuk setiap kasus uji, keluarkan sebuah baris berisi total keindahan perjalanan maksimum dari Asgem ke Astik, atau -1 apabila Budi tidak mungkin mencapai Astik dengan anggaran yang ada.

## Contoh Masukan

    3
    5 10 5
    1 3
    5 4
    12 3
    4 6
    3 10 11
    2 10
    9 10
    4 10 3
    6 10
    5 12
    7 9

## Contoh Keluaran

    9
    -1
    10

## Penjelasan

Untuk contoh masukan pertama, salah satu rencana perjalanan yang mungkin adalah:

- Pergi dari kota 1 (Asgem) ke kota 2 dengan kereta. Biaya = 1, keindahan = 3.
- Pergi dari kota 2 ke kota 4 dengan pesawat. Biaya = 5, keindahan = 0.
- Pergi dari kota 4 ke kota 5 (Astik) dengan kereta. Biaya = 4, keindahan = 6.
- Total biaya = 6, keindahan = 9.

Untuk contoh masukan kedua, Budi tidak mungkin mencapai Astik dengan anggaran yang ada.

Untuk contoh masukan ketiga, salah satu rencana perjalanan yang mungkin adalah:

- Pergi dari kota 1 (Asgem) ke kota 2 dengan kereta. Biaya = 6, keindahan = 10.
- Pergi dari kota 2 ke kota 4 (Astik) dengan pesawat. Biaya = 3, keindahan = 0.
- Total biaya = 9, keindahan = 10.

## Batasan

- 1 ≤ T ≤ 10
- 2 ≤ N ≤ 1.000
- 0 ≤ K[i], V[i], P, S ≤ 1.000



# F - Kartu Truf

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Truf adalah permainan kartu yang populer di Indonesia. Pada soal ini, Anda akan berhadapan dengan versi truf yang disederhanakan. Anda tidak perlu paham permainan truf yang sesungguhnya untuk menyelesaikan soal ini.

Pada permainan ini, terdapat 4 pemain, termasuk Anda. Setiap pemain pada awalnya memegang 13 kartu. Anda memiliki giliran pertama, dan akan memulai ronde pertama. Ronde pertama dilakukan sebagai berikut. Anda mengeluarkan salah satu kartu dari 13 kartu yang Anda pegang.  Kemudian, masing-masing dari ketiga pemain sisanya mengeluarkan sebuah kartu menurut peraturan berikut:

- Harus memiliki jenis yang sama dengan kartu yang Anda keluarkan.
- Jika tidak terdapat kartu dengan jenis yang sama, kartu apapun boleh dikeluarkan.

Pemenang dari ronde pertama adalah pemain yang mengeluarkan kartu dengan nilai tertinggi yang memiliki jenis yang sama dengan kartu yang Anda keluarkan.

Sebagai pemegang giliran pertama, Anda ingin mengetahui peluang Anda memenangkan ronde pertama, untuk setiap pilihan 13 kartu yang mungkin Anda keluarkan pertama kali. Berhubung Anda baru pertama kali bermain kartu truf, maka: setiap pemain selain Anda ingin Anda menang, dan **akan mengeluarkan kartu sedemikian rupa untuk membantu Anda memenangkan ronde pertama**.

Catatan:

- Terdapat 4 jenis kartu: D (diamond), C (club), H (heart), S (spade).
- Setiap jenis memiliki 13 nilai, dari nilai terkecil ke terbesar: 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A. (Perhatikan bahwa nilai 10 diganti dengan T.)
- 52 kartu tersebut dikocok lalu dibagikan kepada 4 pemain dengan distribusi seragam (uniform).

## Format Masukan

Baris pertama berisi sebuah bilangan bulat B yang menyatakan banyaknya kasus uji.

Setiap kasus uji terdiri atas sebuah baris berisi 13 kartu yang Anda pegang. Setiap kartu terdiri atas tepat 2 karakter: jenis dan nilai. Perhatikan contoh masukan untuk detil formatnya.

## Format Keluaran

Untuk setiap kasus uji:

Keluarkan 13 baris berisi kartu diikuti dengan peluang memenangkan ronde pertama apabila Anda mengeluarkan kartu tersebut, dengan tepat 5 angka di belakang penanda desimal. Kartu-kartu dicetak sesuai urutan pada masukan. Perhatikan contoh keluaran untuk detil formatnya.

Keluaran akan dianggap benar apabila setiap peluang berbeda maksimal 0,00001 dari keluaran juri.

Keluarkan baris kosong di antara kasus-kasus uji.

## Contoh Masukan

    2
    6D 8C 9C TC 9H JH KH AH 3S 4S 7S 9S JS
    6D JD QD 6C 7C JC 3H KH 2S 8S TS JS AS

## Contoh Keluaran

    6D: 48.74964%
    8C: 81.45732%
    9C: 81.45732%
    TC: 81.45732%
    9H: 91.60454%
    JH: 96.80539%
    KH: 100.00000%
    AH: 100.00000%
    3S: 0.00628%
    4S: 0.00628%
    7S: 29.98808%
    9S: 54.97518%
    JS: 73.72181%

    6D: 50.34658%
    JD: 94.89091%
    QD: 94.89091%
    6C: 50.34658%
    7C: 50.34658%
    JC: 89.69690%
    3H: 0.00001%
    KH: 98.87638%
    2S: 0.00000%
    8S: 73.72181%
    TS: 86.49864%
    JS: 86.49864%
    AS: 100.00000%

## Batasan

- 1 ≤ B ≤ 52
- Setiap masukan dijamin merepresentasikan 52 kartu yang valid.
