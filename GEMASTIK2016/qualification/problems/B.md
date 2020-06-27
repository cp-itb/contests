# B - Kode Keras

| Time Limit   | 1s    |
|--------------|-------|
| Memory Limit | 256MB |

## Deskripsi

Niken adalah seorang gadis yang sedang amat mendambakan pasangan hidup. Niken sebenarnya punya banyak teman yang ia harapkan bisa menjadi pasangan hidupnya. Namun, Niken adalah tipe orang yang tidak berkata langsung, melainkan melalui kode-kode.

Niken melakukan kode dengan cara menulis status-status bertemakan cinta pada sosial media (misalnya Facebook), dan berharap sang pujaan hati melihat postingan tersebut dan tergerak hatinya. Jika Niken menulis status pada suatu waktu tertentu, maka semua teman Niken yang online pada waktu tersebut akan melihat status tersebut. Tentu Niken tidak mau kode ini salah sasaran. Oleh karena itu, ia berniat menulis status berkali-kali, dengan tujuan sang pujaan hati melihat kode Niken lebih banyak dibandingkan teman-teman Niken yang lain. Tetapi Niken juga tidak mau menulis status terlalu banyak, karena khawatir dinilai terlalu galau oleh teman- temannya.

Anda diberikan N yang menyatakan banyaknya teman Niken, serta rentang waktu kapan teman ke-i tersebut online dalam S[i] dan E[i]. Suatu status akan dibaca oleh teman ke-i apabila status tersebut ditulis pada waktu X yang memenuhi

S[i] ≤ X < E[i]

Karena Niken merahasiakan kepada Anda siapa pujaan hatinya, Anda harus mencari tahu untuk setiap i, berapa status minimum yang harus ditulis jika Niken ingin melakukan kode terhadap teman ke-i. Dengan kata lain, Anda ingin mencari tahu untuk setiap i, berapa status minimum yang harus ditulis agar teman ke-i melihat status Niken **lebih banyak** daripada setiap teman lainnya.

## Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi sebuah bilangan bulat N. N baris berikutnya masing-masing berisi dua buah string S[i] dan E[i], yang ditulis dalam format waktu `hh:mm:ss`. Waktu paling awal adalah 00:00:00 dan waktu paling akhir adalah 23:59:59.

## Format Keluaran

Untuk setiap kasus uji:

Keluarkan sebuah baris berisi banyaknya status minimum yang harus ditulis untuk melakukan kode kepada teman ke-i, atau -1 apabila hal tersebut tidak mungkin.

## Contoh Masukan

    2
    4
    08:00:00 09:00:00
    08:20:00 08:45:00
    08:05:00 09:40:00
    08:15:00 10:00:00
    3
    00:00:00 00:00:01
    00:00:01 00:00:10
    00:00:02 00:00:10

## Contoh Keluaran

    1
    -1
    2
    1
    1
    1
    -1

## Penjelasan

Untuk contoh masukan pertama:

1. Untuk memberi kode pada teman 1, Niken dapat menulis status pada 08:00:00:
    - Teman 1 melihat status Niken 1 kali.
    - Teman 2, 3, dan 4 tidak pernah melihat status Niken.
2. Niken tidak mungkin memberi kode pada teman 2 karena setiap kali teman 2 melihat status Niken, teman 1 dan 3 pasti juga melihatnya. Tidak mungkin membuat teman 2 melihat status Niken lebih banyak daripada teman 1 dan 3.
3. Untuk memberi kode pada teman 3, Niken dapat menulis status pada 08:10:00 dan 09:20:00:
    - Teman 1 dan 4 melihat status Niken 1 kali.
    - Teman 2 tidak pernah melihat status Niken.
    - Teman 3 melihat status Niken 2 kali.
4. Untuk memberi kode pada teman 4, Niken dapat menulis status pada 09:59:59:
    - Teman 1, 2, dan 3 tidak pernah melihat status Niken.
    - Teman 4 melihat status Niken 1 kali.

Untuk contoh masukan kedua:

1. Untuk memberi kode pada teman 1, Niken dapat menulis status pada suatu waktu sebelum 00:00:01 (tidak harus bulat).
2. Untuk memberi kode pada teman 2, Niken dapat menulis status pada 00:00:01.
3. Niken tidak mungkin memberi kode pada teman 3.


## Batasan

- 1 ≤ T ≤ 10
- 1 ≤ N ≤ 50.000
- Waktu yang direpresentasikan oleh S[i] < waktu yang direpresentasikan oleh E[i]
