# A - Dadu Joris

| Time Limit   | 1s    |
|--------------|-------|
| Memory Limit | 128MB |

## Deskripsi

Suatu hari, Joris pergi ke SchemaStore untuk membeli oleh oleh untuk Tutut, temannya. Disana banyak sekali barang barang unik. Setelah berjalan-jalan cukup lama, Joris melihat banner :

"DISKON 99,999% DADU EV-PISI, SEHARGA 1000 RUPIAH"

![](img/dadu_joris_dadu.png)

Dadu EV-PISI adalah dadu yang memiliki M - sisi, di masing masing sisi terdapat nilai Ai dimana 1 ≤ Ai ≤ 8. Cara memainkan dadu EV-PISI adalah setiap kali dadu ini dilemparkan pemain akan mendapatkan poin dari :

![](img/dadu_joris_persamaan1.gif)

Dimana ai merupakan nilai dadu yang muncul dan x merupakan hasil dari :

**x = rand() % N**

Fungsi rand mengembalikan nilai antara 1 - 10 trilyun, dimana terdistribusi secara uniform.

Joris pun tertarik dan ingin membeli dadu EV-PISI. Tetapi untuk membeli dadu EV-PISI dengan harga diskon Joris harus mendapatkan Expectation Value dari poin pelemparan dadu tersebut! Joris sedang dilanda kebingungan karena dia tidak bisa memecahkan masalah tersebut. Kemudian Joris ingat bahwa Joris mempunyai teman yaitu Anda, sang programmer profesional, Joris meminta bantuan Anda untuk mendapatkan Expectation Value dari Dadu tersebut!

## Format Masukan

Pada baris pertama terdapat sebuah bilangan T, yang melambangkan banyak kasus uji.

Setiap kasus uji, diawali dengan bilangan M dan N , baris berikutnya terdapat M bilangan yang mewakili nilai Ai yang unik.

## Format Keluaran

Untuk setiap kasus uji, keluarkan *Expectation Value* dari Dadu tersebut, dengan ketelitian 4 angka dibelakang koma.

## Contoh Masukan

    1
    6 10
    1 2 3 4 5 6

## Contoh Keluaran

	4.5147

## Batasan

- 1 ≤ T ≤ 100000
- 4 ≤ M ≤ 8
- 1 ≤ Ai ≤ 8
- 1 ≤ N ≤ 1000000
