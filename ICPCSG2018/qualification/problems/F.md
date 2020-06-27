# F - Modulo Data Structures

| Time Limit   | 2s     |
|--------------|--------|
| Memory Limit | 1024MB |

You have an array, Arr[1...N]. Initially, all values of Arr[i]=0. The array supports the following two types of queries
1. Increase all Arr[k] by C for all k≡A (mod B);
2. Output Arr[D] for a given D.

## Input

The first two lines of input consists of two integers, N and Q, representing the length of the array and the number of queries, respectively. Note that 1≤N,Q≤200000. The following Q lines all begin with an integer T representing the type of query. If T=1, then it will be followed by three integers representing A, B and C respectively. Note that 1≤C≤10000, 0≤A<B≤N. Else, T will be 2, and it will be followed by one integer representing D, subjected to 1≤D≤N.

## Output

For each query of type 2, output the integer value of Arr[D] on a separate line.

## Sample Input 1

	5 10
	1 1 2 7
	1 4 5 6
	1 2 3 3
	2 1
	2 2
	2 3
	1 3 4 3
	2 3
	2 4
	2 5


## Sample Output 1

	7
	3
	7
	10
	6
	10

