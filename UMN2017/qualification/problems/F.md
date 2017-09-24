# F - Sensus Rekayasa

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 512MB |

## Deskripsi

Kemarin, Pak Umon ditugaskan untuk melakukan sensus penduduk tahunan di kompleks rumahnya. Bentuk kompleks ini memanjang, sehingga rumah diberikan nomor terurut mulai dari
1 hingga N dari Barat ke Timur. Pak Umon mendata setiap rumah, dan menulis nama setiap penduduk ke dalam suatu daftar yang panjang. Namun, ketika menyerahkan daftar yang berisi M nama tersebut ke bosnya, Pak bos bingung karena daftar tersebut hanya berisi nama-nama penduduk saja. Padahal ia juga memerlukan data mengenai penduduk mana yang tinggal di rumah yang mana.

Pak Umon mencoba untuk mengingat-ingat kejadian kemarin. Ia ingat bahwa ia mulai dari rumah nomor 1, dan selalu terus bergerak ke rumah bernomor N. Karena nama-nama yang ditulisnya dalam daftar juga selalu berurut ke bawah, maka nama yang terletak lebih ke bawah pada daftar tidak mungkin memiliki nomor rumah yang lebih kecil dibandingkan dengan nama yang terletak lebih atas. Ia juga ingat bahwa tidak ada rumah yang tidak berpenghuni. Selain itu, Pak Umon juga memiliki K kenalan yang ia hapal nomor rumahnya.

Berdasarkan data-data tersebut, Pak Umon mencoba untuk mengarang laporan mengenai penduduk mana yang tinggal di rumah yang mana. Namun, ia ingin terlebih dahulu menghitung ada berapa konfigurasi berbeda yang mungkin untuk hal tersebut. Dua konfigurasi dikatakan
berbeda apabila dalam dua konfigurasi tersebut terdapat suatu rumah yang jumlah penghuninya
berbeda.

## Format Masukan

Baris pertama berisi sebuah integer T, banyaknya kasus uji untuk soal ini. Untuk setiap kasus uji, baris pertama berisi 3 integer M N K (banyaknya penduduk, banyaknya rumah, dan banyaknya kenalan Pak Umon). K baris berikutnya berisi sepasang integer Pi Ri. Artinya, penduduk ke-i pada daftar memiliki
nomor rumah Ri.

## Format Keluaran

Untuk setiap kasus uji, keluarkan sebaris berisi 2 integer dengan format berikut.
	Case #c: ans
Dengan c adalah nomor kasus uji (dimulai dari 1), dan ans adalah banyaknya konfigurasi berbeda seperti yang dijelaskan soal, dimodulus 1000000007 (109 + 7). Apabila tidak terdapat satupun konfigurasi yang mungkin, maka nilai ans = 0.

## Contoh Masukan

	5
	4 3 2
	1 1
	4 3
	5 2 4
	1 1
	2 1
	3 2
	5 2
	5 3 3
	1 1
	2 2
	4 1
	10 4 2
	5 1
	7 4
	5 3 3
	1 1
	3 2
	5 3

## Contoh Keluaran

	Case #1: 3
	Case #2: 1
	Case #3: 0
	Case #4: 0
	Case #5: 4

## Penjelasan

Pada kasus pertama, diketahui bahwa penduduk 1 berada di rumah 1, dan penduduk 4 di rumah 3. Dengan demikian, maka konfigurasinya adalah sebagai berikut.

	1 ? ? 3
Ketiga konfigurasi yang memungkinkan adalah
	1 1 2 3
	1 2 2 3
	1 2 3 3
Perhatikan bahwa konfigurasi berikut tidak memungkinkan.
	1 1 3 3 (rumah 2 tidak berpenghuni)
	1 2 1 3 (nomor rumah tidak terurut naik)
Pada kasus kedua, satu-satunya konfigurasi yang mungkin adalah 1 1 2 2 2.

## Batasan

- 1 <= T <= 100
- 1 <= M <= 5000
- 1 <= N <= 5000
- 0 <= K <= M
- 1 <= Pi <= M
- 1 <= Ri <= N
- Untuk setiap i < j, Pi < Pj (semua penduduk yang nomor rumahnya Pak Umon hapal, akan diberikan secara menaik (ascending)).
