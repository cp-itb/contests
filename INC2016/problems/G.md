# G - Beautiful Triple

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

In a sequence of N integers A1..N, a triple ⟨a, b, c⟩ is considered beautiful if Aa = Ac and 1 ≤ a < b < c ≤ N.

For example, a sequence A1..6 = {3, 1, 3, 7, 3, 7} has 6 beautiful triples:

- ⟨1, 2, 3⟩ – A1 = 3, A2 = 1, A3 = 3.
- ⟨1, 2, 5⟩ – A1 = 3, A2 = 1, A5 = 3.
- ⟨1, 3, 5⟩ – A1 = 3, A3 = 3, A5 = 3.
- ⟨1, 4, 5⟩ – A1 = 3, A4 = 7, A5 = 3.
- ⟨3, 4, 5⟩ – A1 = 3, A4 = 7, A5 = 3.
- ⟨4, 5, 6⟩ – A4 = 7, A5 = 3, A6 = 7.

Given a sequence of integers, determine how many beautiful triples are there in the sequence. Modulo the output with 1,000,000,007.

## Input

The first line of input contains an integer T (T ≤ 50) denoting the number of cases. Each case begins with an integer N (1 ≤ N ≤ 100,000) denoting the size of the integer sequence. The next line contains N integers Ai (1 ≤ Ai ≤ 100,000) representing the elements in A, for i = 1..N respectively.

## Output

For each case, output in a line "Case #X: Y" where X is the case number, starts from 1, and Y is the output for that particular case.

## Sample Input

	4
	6
	3 1 3 7 3 7
	3
	5 5 5
	7
	35 35 35 35 35 35 35
	4
	102 38 173 25

## Sample Output

	Case #1: 6
	Case #2: 1
	Case #3: 35
	Case #4: 0
