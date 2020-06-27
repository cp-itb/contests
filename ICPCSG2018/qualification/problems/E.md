# E - Grid Game

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 1024MB |

Given a N×N grid of integers, we can choose a combination of N numbers where no two in the same row and no two in the same column. We aim to find a combination of N numbers whose minimum is maximized.

## Input

The first line of input consists of an integer N, where 1≤N≤30. The next N lines each contains N integers, representing the grid. Each integer is in the range [1..10^6].

## Output

Output a single integer, representing the maximum possible value of the minimum.

## Sample Input 1

	3
	3 1 4
	1 5 1
	2 9 1


## Sample Output 1

	2

## Sample Input 2

	5
	17 24 1 8 15
	23 5 7 14 16
	4 6 13 20 22
	10 12 19 21 3
	11 18 25 2 9


## Sample Output 2

	21

