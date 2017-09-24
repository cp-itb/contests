# G - Petruk's Sequence

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Petruk's sequence is defined as follows: Hn=a.Hn-1 + b.Hn-2 for n ≥ 2 and H0=c, and H1=d.

Your task in the final of VOCOMFEST 2017 is to compute the value of H0+H1+...+Hk.

## Input Format

The first line of input contains an integer T denoting the number of cases. Each case contains five integers: a, b, c, d, and k as explained in the problem description above.

## Output Format

For each case, output “Case #X: Y”, where X is the case number starts from 1 and Y is the value of H0+H1+...+Hk. As this number could be very large, output Y modulo 1000000007 (109+7).

## Sample Input

	3
	1 1 1 1 1
	1 1 1 1 3
	3 2 2 1 5

## Sample Output

	Case #1: 2
	Case #2: 7
	Case #3: 411

## Constraint

- 1 ≤ T ≤ 100
- 1 ≤ a,b,c,d ≤ 10 
- 0 ≤ k ≤ 10<sup>9</sup>
