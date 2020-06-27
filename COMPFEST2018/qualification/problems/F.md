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

