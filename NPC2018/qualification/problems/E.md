# E - Bermain Tanah

| Time Limit   | 2s    |
|--------------|-------|
| Memory Limit | 64MB  |

## Deskripsi

Suatu hari, MusMus, MangMang dan GasGas sedang berpetualang di hutan Schema. Tiba-tiba mereka menemukan N petak tanah dengan ketinggian berbeda yang telah dinomori 1 sampai N. Melihat tanah tersebut, mereka tergoda untuk memainkannya. Permainan dimainkan dengan peraturan:

1.  Jika GasGas berkata '1'dan diikuti dengan 3 bilangan l, r, dan v maka  MusMus dan MangMang  akan menambah tanah setinggi v meter pada rentang l sampai r (inklusif). Jika v negatif, maka mereka menggali tumpukan tanah sebanyak v meter.
2. Jika GasGas berkata '2' diikuti 2 bilangan l dan r, maka MusMus harus memosisikan di petak tertinggi dan MangMang harus memosisikan di petak terendah antara petak l dan r (inklusif). Setelah itu, GasGas akan menghitung dan mencatat berapa selisih ketinggian dari petak yang ditempati MusMus dan petak yang ditempati MangMang. Karena GasGas malas, maka ia meminta bantuanmu untuk membuat program untuk mensimulasikan permainan tersebut.

## Format Masukan

Baris pertama berisi sebuah bilangan N yang merupakan banyak petak tanah yang ada.
Baris berikutnya berisi N bilangan Ai yang ketinggian dari petak tanah tersebut.
Baris berikutnya berisi sebuah bilangan Q yang merupakan banyak instruksi yang akan diberikan.
Q baris berikutnya berisi instruksi-instruksi dengan ketentuan sebagai berikut:
    1 l r v     yaitu menambahkan tanah setinggi v meter ke masing-masing petak tanah dalam rentang l sampai r (inklusif)
    2 l r        yaitu mencari selisih ketinggian terbesar petak tanah dalam rentang l sampai r (inklusif)

## Format Keluaran

Untuk setiap perintah dengan bilangan pertama  '2', cetak selisih terbesarnya.

## Contoh Masukan

    5
    1 2 3 4 5
    5
    2 1 5
    1 4 5 10
    2 1 5
    1 1 2 -10
    2 1 5

## Contoh Keluaran

    4
    14
    24

## Batasan

- 1 ≤ Q ≤ 10^5
- 1 ≤ N ≤ 10^5
- 1 ≤ l ≤ r ≤ N
- -2^32 ≤ v, Ai ≤ 2^32
