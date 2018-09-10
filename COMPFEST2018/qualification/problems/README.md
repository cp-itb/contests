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





# C - Mencari Tempat

| Time Limit   | 4s    |
|--------------|-------|
| Memory Limit | 256MB |

## Deskripsi

CFX merupakan negara yang makmur dan sejahtera. Mereka memiliki sistem transportasi yang sangat baik berupa rel kereta dan stasiun yang tersedia di setiap N kota. Berkat sistem ini, siapapun bisa pergi dari tiap kota ke kota lainnya. Uniknya, sistem transportasi tersebut tidak memiliki loops dan hanya ada tepat satu jalan antar dua buah kota.

Pak Chanek selaku pemimpin CFX telah meminta M walikota dari kota-kota yang berbeda untuk berkumpul membahas suatu proyek. Pak Chanek meminta mereka untuk berkumpul di satu kota tertentu. Akan tetapi, para walikota ini merupakan orang-orang yang sibuk sehingga mereka tidak mau pergi terlalu jauh dari kota asalnya. Lebih tepatnya, para walikota ini hanya mau pergi ke kota lain jika dan hanya jika mereka tidak melewati lebih dari K stasiun (tidak terhitung stasiun kota asal mereka). Pak Chanek menjadi bingung karena ia tidak tahu kota mana saja yang bisa dijadikan tempat berkumpul. Anda sebagai peserta CompFest X ditugaskan membantu Pak Chanek untuk menghitung berapa banyak kota yang dapat dijadikan tempat berkumpul sesuai syarat tersebut.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Setiap kasus uji diawali dengan 3 buah bilangan bulat N, M, K, yang menyatakan banyaknya kota, banyaknya walikota yang akan berkumpul, serta banyaknya stasiun maksimal yang dapat dilewati para walikota sesuai deskripsi soal.
N-1 baris berikutnya masing-masing berisi 2 buah bilangan bulat Ui dan Vi yang menyatakan bahwa terdapat rel kereta dua arah yang menghubungkan kota Ui dan kota Vi.
Baris terakhir di setiap kasus uji berisi M buah bilangan bulat Wi yang menyatakan kota asal dari para walikota yang akan berkumpul.

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah bilangan bulat berupa banyaknya kota yang dapat dijadikan tempat berkumpul sesuai deskripsi soal.

## Contoh Masukan

	1
	8 3 2
	1 2
	1 3
	1 6
	3 4
	3 5
	6 7
	7 8
	1 4 5

## Contoh Keluaran

	4

## Penjelasan

Walikota dari kota 1 bisa pergi ke semua kota kecuali kota 8. Walikota dari kota 4 dan 5 masing-masing dapat pergi ke kota 1, 3, 4, dan 5. Jadi, ketiga walikota tersebut dapat berkumpul di kota 1, 3, 4, dan 5.

## Batasan

- 1 ≤ T ≤ 12
- 1 ≤ M ≤ N ≤ 50.000
- 1 ≤ K ≤ 50.000
- 1 ≤ Ui, Vi ≤ N
- 1 ≤ Wi ≤ N
- Ui ≠ Vi untuk tiap 1 ≤ i ≤ N-1
- Untuk tiap i dan j dengan i ≠ j dan 1 ≤ i,j ≤ M, Wi ≠ Wj








# D - Memperpanjang Barisan 

| Time Limit   | 4s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pak Chanek sangat menyukai angka. Ia bahkan memiliki sebuah angka favorit, yaitu N. Selain itu, Pak Chanek juga sangat menyukai barisan bilangan. Saat ini ia memiliki sebuah barisan bilangan yang berisi N2 bilangan bulat berbeda. Bilangan ke-i di barisan tersebut dilambangkan dengan Ai.

Pak Chanek baru saja selesai membaca suatu artikel tentang LIS (Longest Increasing Subsequence) dan LDS (Longest Decreasing Subsequence). Dalam artikel tersebut, Pak Chanek menandai beberapa informasi penting diantaranya:

- "Subsequence dari suatu barisan bilangan merupakan sebuah barisan bilangan baru yang diperoleh dengan menghapus nol atau lebih elemen-elemen anggota barisan awal tersebut tanpa mengubah urutan anggota lainnya. Sebagai contoh, [2, 6, 5] merupakan subsequence dari [2, 1, 7, 6, 5] karena barisan [2, 6, 5] dapat diperoleh dengan menghapus bilangan kedua yaitu 1 dan bilangan ke-3 yaitu 7 pada barisan [2, 1, 7, 6, 5]. Namun, [2, 5, 6] bukan merupakan subsequence dari [2, 1, 7, 6, 5]. Begitu pula dengan [2, 1, 8] yang bukan merupakan subsequence dari [2, 1, 7, 6, 5]."
- "Longest Increasing Subsequence (LIS) merupakan subsequence terpanjang dimana untuk setiap indeks i dan j pada subsequence tersebut yang memenuhi i < j, berlaku bilangan pada indeks ke-i < bilangan pada indeks ke-j. Sebagai contoh, [2, 6] merupakan salah satu LIS dari barisan [2, 1, 7, 6, 5]. "
- "Longest Decreasing Subsequence (LDS) merupakan subsequence terpanjang dimana untuk setiap indeks i dan j pada subsequence tersebut yang memenuhi i < j, berlaku bilangan pada indeks ke-i > bilangan pada indeks ke-j. Sebagai contoh, [7, 6, 5] merupakan LDS dari barisan [2, 1, 7, 6, 5]."

Setelah membaca artikel tersebut, Pak Chanek merasa bosan. Ia kemudian memutuskan untuk bermain dengan bilangan-bilangan yang dimilikinya. Ia ingin barisan bilangan yang ia miliki memiliki LIS atau LDS setidaknya sepanjang N + 1 bilangan dengan menambahkan sesedikit mungkin bilangan bulat positif di belakang barisan tersebut. Jika terdapat beberapa cara untuk melakukan hal tersebut, Pak Chanek akan memilih cara yang mana bilangan-bilangan yang ditambahkannya merupakan barisan bilangan bulat positif terkecil yang mungkin. Barisan bilangan bulat positif terkecil yang dimaksud merupakan barisan bilangan bulat positif yang memiliki urutan leksikografis terkecil yang jika ditambahkan ke belakang barisan tersebut berhasil membuat barisan tersebut memenuhi persyaratan-persyaratan sebelumnya. Tidak hanya itu, Pak Chanek juga ingin agar bilangan-bilangan di barisan tersebut tetap berbeda satu sama lain setelah ia menambahkan bilangan-bilangan di belakang barisan tersebut. Bantulah Pak Chanek untuk menemukan bilangan apa saja yang harus ditambahkan ke belakang barisan tersebut agar barisan tersebut memenuhi syarat yang telah ia buat!

## Format Masukan

Baris pertama berisi sebuah bulangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji dinyatakan sebagai berikut.

Baris pertama berisi sebuah bilangan bulat N yang menyatakan bilangan favorit Pak Chanek.
Baris kedua berisi N2 bilangan bulat Ai, bilangan-bilangan yang terdapat dalam barisan Pak Chanek.

## Format Keluaran

Untuk setiap kasus uji, keluarkan jawaban dengan format sebagai berikut.

Jika tidak ada bilangan yang perlu ditambahkan, cukup keluarkan sebuah baris berisi "0" tanpa tanda kutip.

Jika ada bilangan yang perlu ditambahkan, keluarkan dua buah baris.
Baris pertama berisi sebuah bilangan bulat K yang menyatakan banyaknya bilangan yang harus ditambahkan ke barisan.
Baris kedua berisi K buah bilangan bulat yang menyatakan bilangan-bilangan yang harus ditambahkan ke barisan awal secara terurut.

## Contoh Masukan

	3
	2
	1 3 2 4
	2
	4 2 3 1
	2
	2 4 1 3

## Contoh Keluaran

	0
	0
	1
	5

## Batasan


- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 200
- -109 ≤ Ai ≤ 109, untuk setiap 1 ≤ i ≤ N

## Catatan

Sebuah barisan bilangan A disebut memiliki urutan leksikografis yang lebih kecil dibanding barisan bilangan B jika dan hanya jika terdapat suatu indeks i yang menyebabkan untuk setiap indeks j < i berlaku Aj = Bj, dan Ai < Bi.









# E - Mari Membaca 

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pak Chanek sangat senang membaca. Ia selalu menyempatkan setiap harinya untuk membaca buku. Saat ini, ia memiliki koleksi N buah buku untuk dibaca. Buku ke-i memiliki Hi halaman. 

Setiap buku memiliki jenis-jenis tertentu, misalnya ada yang berjenis novel, ensiklopedia, manga, dan lainnya. Total Pak Chanek memiliki M jenis buku berbeda. Buku ke-i memiliki jenis buku yang dapat direpresentasikan dengan suatu bilangan bulat Ti dengan 1 ≤ Ti ≤ M.

Selain itu, Pak Chanek memiliki batas tertentu dalam membaca suatu jenis buku karena ia juga akan bosan apabila terlalu lama membaca. Lebih tepatnya, untuk jenis buku i, Pak Chanek maksimal hanya akan membaca Vi halaman perhari untuk jenis buku tersebut. Pak Chanek ingin menyelesaikan semua bacaannya secepat mungkin. Oleh karena itu, ia menjadi penasaran, jenis buku apa yang membutuhkan hari paling banyak untuk dibaca?

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi sebuah bilangan bulat N dan M, banyaknya buku dan banyaknya jenis buku.
Baris kedua berisi N bilangan bulat Hi, jumlah halaman buku ke-i.
Baris ketiga berisi N bilangan bulat Ti, jenis buku ke-i.
Baris keempat berisi M bilangan bulat Vi, jumlah maksimal halaman yang dapat Pak Chanek baca dalam sehari untuk jenis buku i.

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah bilangan bulat yang menyatakan jenis buku yang membutuhkan hari paling banyak untuk dibaca Pak Chanek. Apabila ada lebih dari satu jenis buku, keluarkan jenis buku yang direpresentasikan dengan bilangan terkecil.

## Contoh Masukan

	2
	4 2
	4 5 6 7
	1 2 1 2
	2 5
	3 3
	10 10 10
	1 2 3
	5 2 1

## Contoh Keluaran

	1
	3

## Penjelasan

Untuk contoh masukan 1, Pak Chanek membutuhkan 5 hari untuk membaca semua buku jenis ke-1, yaitu 2 hari untuk buku ke-1 dan 3 hari untuk buku ke-3. Sementara itu, untuk buku jenis ke-2, Pak Chanek membutuhkan waktu 3 hari, yaitu 1 hari untuk buku ke-2 dan 2 hari untuk buku ke-4. Jadi, jenis buku yang membutuhkan hari paling banyak untuk dibaca adalah jenis ke-1.

## Batasan


- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 100.000
- 1 ≤ M ≤ N
- 1 ≤ Hi ≤ 10^9, untuk tiap 1 ≤ i ≤ N
- 1 ≤ Ti ≤ M, untuk tiap 1 ≤ i ≤ N
- 1 ≤ Vi ≤ 10^9, untuk tiap 1 ≤ i ≤ M



# F - Jelajah Kota 

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pak Chanek sedang berencana untuk berwisata di Provinsi Compfest yang memiliki N buah kota. Uniknya, kota-kota di Provinsi Compfest terhubung secara linear melalui jalan dua arah sehingga kota 1 terhubung dengan kota 2, kota 2 terhubung dengan kota 3, dan seterusnya hingga kota N-1 terhubung dengan kota N. Lebih lanjut, kota i dihubungkan dengan kota i+1 dengan jalan berjarak Di km. Pak Chanek berencana untuk naik pesawat ke salah satu kota di Provinsi Compfest, lalu meneruskan perjalanannya ke kota-kota lain dengan mobil.

Pak Chanek ingin berwisata di Provinsi Compfest tentu bukan tanpa alasan. Setiap kota memiliki nilai kebahagiaan Ri yang menunjukkan besarnya kebahagiaan Pak Chanek jika berwisata (berhenti) di kota tersebut. Tentu Pak Chanek ingin mengunjungi semua kota, namun Pak Chanek hanya memiliki izin yang membuatnya hanya dapat mengunjungi maksimum K kota. Pak Chanek tetap dapat mengunjungi suatu kota berkali-kali dan hanya dihitung sekali pada perhitungan K kota itu maupun nilai kebahagiaan. Selain mempertimbangkan besarnya nilai kebahagiaan, Pak Chanek tentu mempertimbangkan biaya perjalanannya. Untuk sampai ke kota i dengan pesawat, Pak Chanek harus mengeluarkan biaya tiket sebesar Ci. Saat berpergian dengan mobil, Pak Chanek harus mengeluarkan biaya bensin yang besarnya sama dengan jarak yang ditempuh. Selain itu, kapasitas bensin mobil juga menyebabkan Pak Chanek tidak dapat mengendarai mobil sepanjang lebih dari L km tanpa berhenti sekali pun.

Sekarang Pak Chanek bertanya-tanya, berapa keuntungan (total nilai kebahagiaan dikurang biaya perjalanan) maksimal yang dapat dia peroleh pada kunjungannya ke Provinsi Compfest?

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji yang diberikan. Setiap kasus uji dinyatakan sebagai berikut.

Baris pertama berisi 3 bilangan yaitu N, K, dan L yang berturut-turut menyatakan banyak kota, jumlah maksimum kota yang dapat dikunjungi, dan batas panjang perjalanan dengan mobil tanpa berhenti.

Baris kedua berisi N bilangan yaitu Ci (1 ≤ i ≤ N) yang menyatakan biaya perjalanan pesawat untuk sampai pada kota ke-i.

Baris ketiga berisi N bilangan yaitu Ri (1 ≤ i ≤ N) yang menyatakan nilai kebahagiaan Pak Chanek jika berhenti pada kota ke-i.

Baris keempat berisi N-1 bilangan yaitu Di (1 ≤ i < N) yang menyatakan jarak antara kota ke-i dengan kota ke-(i+1).

## Format Keluaran

Sebuah bilangan yang menyatakan keuntungan maksimal yang dapat diperoleh Pak Chanek.

## Contoh Masukan

	2
	5 3 3
	3 2 4 1 4
	8 12 11 9 12
	1 1 4 2
	4 1 3
	7 10 15 6
	10 11 9 8
	6 3 6

## Contoh Keluaran

	26
	3

## Penjelasan Contoh

Untuk contoh masukan 1, Pak Chanek akan mendarat pada kota 2 dengan biaya 2, lalu pergi ke kota 3, kembali ke kota 2, lalu pergi ke kota 1. Total nilai kebahagiaan yang diperoleh adalah 12 + 11 + 8 = 31 sedangkan biaya pesawat ditambah mobil sebesar 2 + 1 + 1 + 1 = 5. Total keuntungan Pak Chanek adalah 31 - 5 = 26.

Untuk contoh masukan 2, Pak Chanek akan mendarat pada kota 1 dengan biaya 7 dan mendapat kebahagiaan 10 sehingga mendapat keuntungan 10 - 7 = 3.

## Batasan


- 1 ≤ T ≤ 6
- 2 ≤ N ≤ 2.000
- 1 ≤ K ≤ N
- 1 ≤ L, Ci, Ri, Di ≤ 109


# G - FPB Terbesar 

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Pak Chanek sekarang menjadi pelatih olimpiade informatika di SMA COMPFEST X. SMA tersebut baru saja menerima murid-murid baru. Pak Chanek mulai mencari murid-murid baru yang mempunyai potensi untuk memenangkan olimpiade informatika dengan membuat tantangan yang diumumkan di papan pengumuman sekolah.

Pak Chanek akan memberikan N buah bilangan bulat positif, kemudian pada tantangan tersebut Anda harus mencari FPB (Faktor Persekutuan Terbesar) yang terbesar apabila Anda mengambil tepat M buah bilangan dari bilangan yang diberikan Pak Chanek.

Tugas Anda adalah membuat program untuk menyelesaikan tantangan Pak Chanek.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji yang diberikan. Setiap kasus uji dinyatakan sebagai berikut.

Baris pertama berisi 2 bilangan yaitu N dan M. N menandakan banyaknya bilangan bulat yang diberikan oleh Pak Chanek, dan M menandakan banyaknya bilangan yang harus Anda ambil.

Baris kedua berisi N bilangan bulat positif Ai, bilangan-bilangan yang diberikan Pak Chanek.

## Format Keluaran

Keluarkan sebuah baris berisi sebuah bilangan bulat, yaitu FPB terbesar yang bisa didapatkan.

## Contoh Masukan

	2
	5 3
	6 4 7 8 10
	5 2
	486 567 891 456 532

## Contoh Keluaran

	2
	81

## Penjelasan Contoh

Untuk kasus uji pertama, ambil 3 buah bilangan genap apa saja sehingga FPB yang didapat adalah 2. Tidak ada konfigurasi lain yang menghasilkan FPB lebih besar dari 2.

## Batasan

- 1 ≤ T ≤ 8
- 1 ≤ N ≤ 100.000
- 1 ≤ M ≤ N
- 1 ≤ Ai ≤ 1.000.000

