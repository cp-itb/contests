# C - Beautiful Quadruple

| Time Limit   | 5s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

In a matrix of integers M, mi,j denotes the element of the matrix at ith row and jth column. A quadruple ⟨a, b, c, d⟩ of M is considered beautiful if and only if (a < b), (c < d), and ma,c = ma,d = mb,c = mb,d in matrix M.

Given a matrix of integers M, determine how many beautiful quadruple of M there are.

For example, consider the following matrix of 3 x 4:

![inc16-c-quad-1](https://user-images.githubusercontent.com/5902356/30779884-fbdf9f0a-a127-11e7-8932-1551edb07bce.jpg)

There are two beautiful quadruples, i.e. ⟨1, 3, 2, 4⟩ and ⟨2, 3, 2, 3⟩, as shown in the following figures.

![inc16-c-quad-2](https://user-images.githubusercontent.com/5902356/30779889-209ddaa0-a128-11e7-9bc8-a889c8edeac1.jpg)

There are no other quadruples which are beautiful, thus, in this example, the output is 2.

## Input

The first line of input contains an integer T (T ≤ 100) denoting the number of cases. Each case begins with two integers R and C (2 ≤ R, C ≤ 150) denoting the size of the matrix (row and column respectively). The next R lines each contains C integers mi,j (1 ≤ mi,j ≤ 10^9) representing the matrix's element, respectively for i = 1..R and j = 1..C.

## Output

For each case, output in a line "Case #X: Y" where X is the case number, starts from 1, and Y is the output for that particular case.

## Sample Input

	4
	3 4
	7 5 7 5
	1 5 5 7
	7 5 5 5
	2 3
	1 1 1
	1 1 1
	4 5
	1 2 3 4 5
	6 7 8 9 10
	11 12 13 14 15
	16 17 18 19 20
	3 4
	2 8 3 2
	2 3 3 2
	2 3 3 2

## Sample Output

	Case #1: 2
	Case #2: 3
	Case #3: 0
	Case #4: 4
