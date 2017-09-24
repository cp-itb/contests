# D - Arithmetic Sequence

| Time Limit   | 4s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

A sequence of integers ( x1, x2, ..., xm ) is an arithmetic sequence if the difference between any two consecutive elements are the same. In other words, xi - xi+1 = xj - xj+1 for any 1 ≤ i ≤ j < m. By definition, any sequence with less than three integers is also an arithmetic sequence.

Given a sequence of integers a1, a2, ..., an and Q queries, where each query is one of the following:

1. 1 p q : change the value of ap into q.
2. 2 s t : output whether ( as, as+1, ..., at ) is an arithmetic sequence.

For each query of the first type (i), the change is reflected in the original sequence and may affect any future queries. For each query of the second type (ii), you should ouput "YES" or "NO" whether it satisfies the query.

For example, let there be a sequence a1..5 = ( 2, 4, 8, 14, 20 ) and 5 queries:

- 2 3 5 : is a3..5 = ( 8, 14, 20 ) an arithmetic sequence? output: YES.
- 2 1 3 : is a1..3 = ( 2, 4, 8 ) an arithmetic sequence? output: NO.
- 1 3 6 : change a3 into 6, so the sequence becomes a1..5 = ( 2, 4, 6, 14, 20 )
- 2 1 3 : is a1..3 = ( 2, 4, 6 ) an arithmetic sequence? output: YES.
- 2 3 5 : is a3..5 = ( 6, 14, 20 ) an arithmetic sequence? output: NO.

## Input

The first line of input contains an integer T (T ≤ 10) denoting the number of cases. Each case begins with two integers N and Q (1 ≤ N, Q ≤ 50,000) denoting the number of integers in the sequence and the number of queries, respectively. The next line contains N integers a1, a2, ..., aN (1 ≤ ai ≤ 1,000,000,000) each separated by a single space, representing the given sequence. The next Q lines represent the queries, where each line is one of the following:

1. 1 p q (1 ≤ p ≤ N; 1 ≤ q ≤ 1,000,000,000).
2. 2 s t (1 ≤ s ≤ t ≤ N).

## Output

For each case, output in a line "Case #X:" where X is the case number, starts from 1. For each query of the second type (ii), output "YES" or "NO" (without quotes) in a single line whether the query is satisfied.

## Sample Input

	2
	5 5
	2 4 8 14 20
	2 3 5
	2 1 3
	1 3 6
	2 1 3
	2 3 5
	10 4
	1 2 3 4 5 6 7 8 9 10
	2 1 10
	1 4 6
	2 4 5
	2 3 5

## Sample Output

	Case #1:
	YES
	NO
	YES
	NO
	Case #2:
	YES
	YES
	NO

## Explanation

*Explanation for 2nd sample case*

The original sequence a1..10 = ( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ); and there are 4 queries:

- 2 1 10 : is a1..10 = ( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ) an arithmetic sequence? output: YES.
- 1 4 6 : change a4 into 6, so the sequence becomes a1..10 = ( 1, 2, 3, 6, 5, 6, 7, 8, 9, 10 ).
- 2 4 5 : is a4..5 = ( 6, 5 ) an arithmetic sequence? output: YES.
- 2 3 5 : is a3..5 = ( 3, 6, 5 ) an arithmetic sequence? output: NO.
