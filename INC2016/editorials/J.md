# J - Rational Number

*Author: @azaky*

Misalkan pecahan $a/b$ adalah pecahan yang sudah dalam bentuk paling sederhana, dengan $gcd(a, b) = 1$. Misalkan pula $c$ adalah faktor terbesar $b$ sehingga $gcd(c, 10) = 1$. Maka, soal ini sama saja dengan mencari bilangan bulat nonnegatif $k$ terkecil sehingga $c | 10^k - 1$. (Mengapa?)

$k$ disebut juga dengan *multiplicative order of 10 modulo c*, atau $ord\_c(10)$. Properti penting dari order yang bisa dipakai di sini adalah $ord\_n(x) | \phi(n)$. [(Sumber)](https://en.wikipedia.org/wiki/Multiplicative_order)

Maka, yang perlu dilakukan adalah menghitung $\phi(c)$. Setelah mendapatkan nilai $\phi(c)$, cukup dilakukan iterasi terhadap faktor-faktor $\phi(c)$. Faktor terkecil $k$ yang memenuhi $10^k \equiv 1 \mod c$ adalah jawabannya.

Kompleksitas: $O(\sqrt{b} \log b)$.