# B - Swap to Sort

| Time Limit   | 2s     |
|--------------|--------|
| Memory Limit | 1024MB |

You are given an array A[1...N] with integers in decreasing order and a list of pairs (a1,b1), (a2,b2), …, (aK,bK). You wish to sort the array A in increasing order, each turn you choose an i (i can be chosen multiple times) and swap A[ai] with A[bi]. Determine whether this is possible.

## Input

The first line contains two integers, representing N and K respectively (1≤N,K≤106). The following K lines each contains two integers, representing ai and bi respectively (1≤ai<bi≤N).

## Output

Output “Yes” if it is possible to sort the array in increasing order, “No” otherwise.

## Sample Input 1

	5 2
	1 5
	2 4


## Sample Output 1

	Yes


## Sample Input 2

	5 4
	1 4
	2 3
	4 5
	1 5

## Sample Output 2

	No

