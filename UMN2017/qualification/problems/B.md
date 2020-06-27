# B - Half-Life 3 Confirmed

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 512MB |

## Deskripsi

Pak Umon gemar bermain Half-Life dan Half-Life 2. Namun, ia terlebih gemar bermain dengan poligon kesayangannya. Poligon tersebut berbentuk konveks (cembung) dan memiliki N sisi. Belakangan ini, ia mendengar gosip bahwa akan dirilis Half-Life 3. Pak Umon ingin merayakannya bersama dengan poligon kesayangannya dengan menggambar pola segitiga pada poligon tersebut. Pak Umon mengambil spidol dan melukis beberapa garis yang menghubungkan
titik-titik sudut dari poligon tersebut. Hasilnya adalah sebagai berikut.

![b-1](https://user-images.githubusercontent.com/5902356/30779920-9fccabf8-a128-11e7-9541-14d188b2560e.png)

Garis-garis yang dilukis tidak boleh saling berpotongan. Perhatikan bahwa untuk poligon dengan N sisi, harus tepat dibagi menjadi (N-2) segitiga.

Untuk garis sepanjang r, Pak Umon memerlukan waktu sebanyak r2 untuk melukisnya. Waktu total yang diperlukan untuk melukisi seluruh poligon tersebut jelas merupakan akumulasi dari waktu untuk melukis setiap garis yang diperlukan. Namun, Pak Umon ingin segera memainkan Half-Life 3 sehingga ia tak punya banyak waktu. Bantulah Pak Umon untuk menghitung waktu tersingkat yang ia perlukan untuk melukisi poligon kesayangannya.

## Format Masukan

Soal ini terdiri atas T kasus. T diberikan di baris pertama berkas masukan.

Setiap kasus diawali dengan baris berisi sebuah integer N.
N baris berikutnya merupakan pasangan integer (xi, yi) yang merupakan koordinat poligon Pak Umon.

## Format Keluaran

Untuk setiap kasus, keluarkan sebaris output dengan format berikut.
Case #c: ans
c merupakan nomor kasus (dimulai dari 1), dan ans merupakan sebuah integer yang nilainya
merupakan waktu tersingkat seperti yang diminta soal.

## Contoh Masukan

	2
	4
	0 0
	0 4
	8 4
	5 0
	5
	-2 -2
	-5 0
	0 3
	5 0
	2 -2

## Contoh Keluaran

	Case #1: 41
	Case #2: 58

## Penjelasan

Berikut garis yang dilukis Pak Umon untuk kedua contoh kasus uji.

![b-2](https://user-images.githubusercontent.com/5902356/30779917-9fb6ae0c-a128-11e7-994d-27a5520b3077.png)


## Batasan

- 1 <= T <= 100
- 4 <= N <= 100
- -1000 <= xi, yi <= 1000
- Dijamin titik-titik diberikan secara searah jarum jam dan membentuk sebuah poligon konveks.
- Dijamin tidak ada tiga titik yang segaris.
