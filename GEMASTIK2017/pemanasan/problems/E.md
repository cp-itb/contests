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
