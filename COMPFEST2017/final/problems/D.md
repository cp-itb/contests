# D - Xor-or

| Time Limit   | 4s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Chanekland adalah salah satu pusat hiburan keluarga terbesar yang pernah ada. Ribuan orang datang tiap harinya untuk menikmati berbagai wahana yang tersedia, termasuk wahana terbaru yang baru saja ditambahkan, yaitu Rumah Xor-or.

Rumah Xor-or adalah rumah hantu yang telah dirancang khusus oleh direktur utama Chanekland, Pak Chanek. Rumah Xor-or ini terdiri dari N ruangan dan M koridor. Di Rumah Xor-or, ruangan hanya berfungsi sebagai tempat istirahat, sedangkan hal-hal yang menakutkan akan dialami jika melewati koridor. Sebuah koridor menghubungkan dua ruangan yang mungkin saja sama, dan memiliki suatu nilai keseraman. Rumah Xor-or memiliki beberapa bagian berbeda, sehingga mungkin saja terdapat ruangan-ruangan yang tidak terhubung melalui koridor-koridor yang ada.

Karena Pak Chanek tidak ingin membuat pengunjungnya bosan, ia telah merancang Rumah Xor-or supaya berbeda dengan rumah hantu lainnya. Untuk membandingkan keunikan Rumah Xor-or dengan rumah hantu lainnya, Pak Chanek menggunakan suatu pengukuran nilai keunikan. Nilai keunikan Rumah Xor-or dapat dihitung sebagai berikut:

- Buat suatu himpunan S(i, j) untuk semua 1 ≤ i < j ≤ N, yang mana anggota dari S(i, j) memuat semua kemungkinan nilai keseraman rute yang mungkin dari ruangan ke-i ke ruangan ke-j. Nilai keseraman rute dihitung dengan melakukan operasi bitwise XOR kepada semua nilai keseraman koridor yang dilewati. Dalam satu rute, suatu ruangan atau koridor dapat dilewati lebih dari sekali.
- Tentukan suatu nilai F(i, j) untuk semua 1 ≤ i < j ≤ N, yang mana F(i, j) merupakan hasil dari operasi bitwise OR kepada semua anggota S(i, j). Apabila S(i, j) adalah himpunan kosong, maka F(i, j) = 0.
- Nilai keunikan Rumah Xor-or adalah total dari F(i, j) untuk semua 1 ≤ i < j ≤ N.

Karena rumitnya perhitungan ini, Pak Chanek tidak bisa menghitungnya sendiri. Anda, sebagai teman baik Pak Chanek, diminta untuk membantu Pak Chanek menghitung nilai keunikan Rumah Xor-or Chanekland.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyak kasus uji. Setiap kasus uji akan dinyatakan sebagai berikut.

Baris pertama berisi dua bilangan bulat N dan M, banyak ruangan dan banyak koridor.

M baris berikutnya masing-masing berisi Ui, Vi, dan Wi, yang menyatakan bahwa koridor ke-i menghubungkan Ui dan Vi dan memiliki nilai keseraman Wi.

## Format Keluaran

Untuk setiap kasus uji, keluarkan satu baris berisi satu bilangan bulat, nilai keunikan dari Rumah Xor-or Chanekland.

## Contoh Masukan

	1
	4 3
	1 2 1
	2 3 2
	3 1 7

## Contoh Keluaran

	18

## Penjelasan

Pada contoh di atas, semua kemungkinan S(i, j) adalah sebagai berikut:

- S(1, 2) = {1, 5}
- S(1, 3) = {3, 7}
- S(1, 4) = {}
- S(2, 3) = {2, 6}
- S(2, 4) = {}
- S(3, 4) = {}

Semua kemungkinan F(i, j) adalah sebagai berikut:

- F(1, 2) = 5
- F(1, 3) = 7
- F(1, 4) = 0
- F(2, 3) = 6
- F(2, 4) = 0
- F(3, 4) = 0

Sehingga nilai keunikan Rumah Xor-or adalah 5 + 7 + 0 + 6 + 0 + 0 = 18.

## Batasan

- 1 ≤ T ≤ 8
- 2 ≤ N ≤ 30.000
- 1 ≤ M ≤ 50.000
- 1 ≤ Ui, Vi ≤ N
- 1 ≤ Wi ≤ 109

## Catatan

Operasi bitwise XOR dari dua buah bilangan bulat non-negatif P dan Q dihitung dengan cara berikut:

- Ubah P dan Q ke dalam biner
- Lakukan operasi XOR untuk setiap pasang bit yang bersesuaian, dimana:

0 XOR 0 = 0

0 XOR 1 = 1

1 XOR 0 = 1

1 XOR 1 = 0

- Ubah hasil XOR yang didapat kembali ke basis sepuluh.

Sebagai contoh, 5 XOR 6 = 3, karena 5 = 101 dalam biner dan 6 = 110 dalam biner. Sehingga didapat XOR nya adalah 011 = 3 dalam basis sepuluh.

Operasi bitwise OR dari dua buah bilangan bulat non-negatif P dan Q dihitung dengan cara berikut:

- Ubah P dan Q ke dalam biner
- Lakukan operasi OR untuk setiap pasang bit yang bersesuaian, dimana:

0 OR 0 = 0

0 OR 1 = 1

1 OR 0 = 1

1 OR 1 = 1

- Ubah hasil OR yang didapat kembali ke basis sepuluh.

Sebagai contoh, 5 OR 6 = 7, karena 5 = 101 dalam biner dan 6 = 110 dalam biner. Sehingga didapat OR nya adalah 111 = 7 dalam basis sepuluh.

