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
