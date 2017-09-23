# J - Rational Number

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

A rational number is any real number which can be written as the fraction a/b of two whole numbers (integers) a and b. One property of a rational number is it either terminates after a finite number of digits or it has a repeating decimal digits (r). Example of rational numbers are:

- 100	a = 100	b = 1	(terminates)
- -1.875	a = -15	b = 8	(terminates)
- 2.16	a = 13	b = 6	r = 6
- 7.27	a = 80	b = 11	r = 27
- 0.285714	a = 2	b = 7	r = 285714

The overlined numbers in above examples represent the repeating decimal digits, e.g., 2.16 means the number is 2.166666..., while 0.285714 means the number is 0.285714285714285714285714...; 100 and -1.875 do not have repeating decimal digits as they terminate.

In this problem, you are challenged to find the length of the repeating decimal digits of a rational number. In the examples above, when a = 13 and b = 6, then the length of its repeating decimal digits is 1; while, when a = 2 and b = 7, the length of its repeating decimal digits is 6.

## Input

The first line of input contains an integer T (T ≤ 100) denoting the number of cases. Each case contains two integers in a line: a b (-1,000,000,000 ≤ a, b ≤ 1,000,000,000; b ≠ 0) which represent the numerator and denominator of the rational number, respectively.

## Output

For each case, output in a line "Case #X:" where X is the case number, starts from 1, and Y is the length of the repeating decimal digits for that particular case.

## Sample Input

	5
	100 1
	-15 8
	13 6
	80 11
	2 7

## Sample Output

	Case #1: 0
	Case #2: 0
	Case #3: 1
	Case #4: 2
	Case #5: 6
