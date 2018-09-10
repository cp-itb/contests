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

