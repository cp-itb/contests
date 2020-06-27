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
