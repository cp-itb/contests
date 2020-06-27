# F - Saklar Ajaib

| Time Limit   | $1$s     |
|--------------|--------|
| Memory Limit | $1536$MB |

Sudiro merupakan mahasiswa semester akhir yang sering pulang larut malam dari kampus. Suatu malam ia ingin mematikan semua lampu dari salah satu ruangan di DTETI. Setiap lampu tersebut terhubung dengan sebuah saklar. Karena kesalahan instalasi, Jika suatu saklar ditekan maka kondisi lampu tersebut beserta semua lampu di kanannya berubah dari yang semula hidup menjadi mati dan sebaliknya.

Misalnya terdapat $4$ buah lampu berturut turut dengan kondisi $(0 1 0 1)$.
- $0$ melambangkan lampu tersebut mati
- $1$ melambangkan lampu tersebut hidup

Saklar ke-$0$ tidak perlu ditekan karena kondisi lampu sudah mati. Saklar ke-$1$ ditekan dan kondisi lampu berubah menjadi $(0 0 1 0)$. Saklar ke-$2$ ditekan dan kondisi lampu berubah menjadi $(0 0 0 1)$. Saklar ke $3$ ditekan dan kondisi lampu berubah menjadi $(0 0 0 0)$.

Berapakah jumlah minimum saklar yang harus ditekan Sudiro untuk mematikan semua lampu pada ruangan tersebut

## Input

- Baris pertama berupa bilangan $N$ yang merupakan banyaknya lampu pada ruangan tersebut
- Baris kedua merupakan kondisi tiap-tiap $N$ lampu tersebut. $0$ melambangkan lampu tersebut mati dan $1$ melambangkan lampu tersebut hidup.

## Output

Menampilkan jumlah minimum saklar yang harus ditekan

## Batasan

$1 \leq N \leq 10^5$

## Sample Input 1

	5
	1 0 0 1 0
  

## Sample Output 1

	4


<br>
<br>