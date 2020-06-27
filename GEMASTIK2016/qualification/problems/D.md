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
