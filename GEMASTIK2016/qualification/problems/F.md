# F - Kartu Truf

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Deskripsi

Truf adalah permainan kartu yang populer di Indonesia. Pada soal ini, Anda akan berhadapan dengan versi truf yang disederhanakan. Anda tidak perlu paham permainan truf yang sesungguhnya untuk menyelesaikan soal ini.

Pada permainan ini, terdapat 4 pemain, termasuk Anda. Setiap pemain pada awalnya memegang 13 kartu. Anda memiliki giliran pertama, dan akan memulai ronde pertama. Ronde pertama dilakukan sebagai berikut. Anda mengeluarkan salah satu kartu dari 13 kartu yang Anda pegang.  Kemudian, masing-masing dari ketiga pemain sisanya mengeluarkan sebuah kartu menurut peraturan berikut:

- Harus memiliki jenis yang sama dengan kartu yang Anda keluarkan.
- Jika tidak terdapat kartu dengan jenis yang sama, kartu apapun boleh dikeluarkan.

Pemenang dari ronde pertama adalah pemain yang mengeluarkan kartu dengan nilai tertinggi yang memiliki jenis yang sama dengan kartu yang Anda keluarkan.

Sebagai pemegang giliran pertama, Anda ingin mengetahui peluang Anda memenangkan ronde pertama, untuk setiap pilihan 13 kartu yang mungkin Anda keluarkan pertama kali. Berhubung Anda baru pertama kali bermain kartu truf, maka: setiap pemain selain Anda ingin Anda menang, dan **akan mengeluarkan kartu sedemikian rupa untuk membantu Anda memenangkan ronde pertama**.

Catatan:

- Terdapat 4 jenis kartu: D (diamond), C (club), H (heart), S (spade).
- Setiap jenis memiliki 13 nilai, dari nilai terkecil ke terbesar: 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A. (Perhatikan bahwa nilai 10 diganti dengan T.)
- 52 kartu tersebut dikocok lalu dibagikan kepada 4 pemain dengan distribusi seragam (uniform).

## Format Masukan

Baris pertama berisi sebuah bilangan bulat B yang menyatakan banyaknya kasus uji.

Setiap kasus uji terdiri atas sebuah baris berisi 13 kartu yang Anda pegang. Setiap kartu terdiri atas tepat 2 karakter: jenis dan nilai. Perhatikan contoh masukan untuk detil formatnya.

## Format Keluaran

Untuk setiap kasus uji:

Keluarkan 13 baris berisi kartu diikuti dengan peluang memenangkan ronde pertama apabila Anda mengeluarkan kartu tersebut, dengan tepat 5 angka di belakang penanda desimal. Kartu-kartu dicetak sesuai urutan pada masukan. Perhatikan contoh keluaran untuk detil formatnya.

Keluaran akan dianggap benar apabila setiap peluang berbeda maksimal 0,00001 dari keluaran juri.

Keluarkan baris kosong di antara kasus-kasus uji.

## Contoh Masukan

    2
    6D 8C 9C TC 9H JH KH AH 3S 4S 7S 9S JS
    6D JD QD 6C 7C JC 3H KH 2S 8S TS JS AS

## Contoh Keluaran

    6D: 48.74964%
    8C: 81.45732%
    9C: 81.45732%
    TC: 81.45732%
    9H: 91.60454%
    JH: 96.80539%
    KH: 100.00000%
    AH: 100.00000%
    3S: 0.00628%
    4S: 0.00628%
    7S: 29.98808%
    9S: 54.97518%
    JS: 73.72181%

    6D: 50.34658%
    JD: 94.89091%
    QD: 94.89091%
    6C: 50.34658%
    7C: 50.34658%
    JC: 89.69690%
    3H: 0.00001%
    KH: 98.87638%
    2S: 0.00000%
    8S: 73.72181%
    TS: 86.49864%
    JS: 86.49864%
    AS: 100.00000%

## Batasan

- 1 ≤ B ≤ 52
- Setiap masukan dijamin merepresentasikan 52 kartu yang valid.
