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

