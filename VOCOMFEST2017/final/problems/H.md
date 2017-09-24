# H - Amazing String

| Time Limit   | 2s    |
|--------------|-------|
| Memory Limit | 128MB |

## Description

Given two strings p and q, we define p + q to be their concatenation. For example, if p = "abc" and q = "def" then p + q = "abcdef". The other operation is multiplication (*), a string can multiplied by an integer m, the result is the string concatenated by its original self m times. For example, "abk" multiplied by 3 becomes "abkabkabk".

Mr. Blangkon has a string S. He wants to play with his four friends, Petruk, Gareng, Semar, and Bagong. Each of his friends chooses three positive integers.

- Petruk chooses la1, ra1, and ma1.
- Gareng chooses lb1, rb1, and mb1.
- Semar chooses la2, ra2, and ma2.
- Bagong chooses lb2, rb2, and mb2.

Each of his friends creates a string pi that is a substring of S with index li until ri (inclusive) where i is an element from {a1, b1, a2, b2}. For example, if S = "vocomfest", li=2, and ri=5, then pi will be "ocom".

Now that Petruk has string pa1, Gareng has string pb1, Semar has string pa2, and Bagong has string pb2, Mr. Blangkon will check whether string pa1 * ma1 + pb1 * mb1 is equal to string pa2 * ma2 + pb2 * mb2.

## Input Format

The first line of input contains a string S. The next line of input contains an integer T denoting the number of cases. Then each of the next T lines contains 12 integers: la1, ra1, ma1, lb1, rb1, mb1, la2, ra2, ma2, lb2, rb2, mb2, as explained the problem description above.

## Output Format

For each case, output “Case #X: Y”, where X is the case number starts from 1 and Y is "YES" if it satisfies the condition that string pa1 * ma1 + pb1 * mb1 is equal to string pa2 * ma2 + pb2 * mb2 , and "NO" otherwise.

## Sample Input

	sukasuka
	3
	1 2 1 1 2 1 1 2 1 5 6 1
	1 1 1 4 4 2 2 2 1 1 1 1
	3 6 1 7 8 3 1 4 1 3 6 1

## Sample Output

	Case #1: YES
	Case #2: NO
	Case #3: NO

## Explanation

In the first case, Petruk string is "su", Gareng is "su", Semar is "su", and Bagong is "su", and concatenation of Petruk and Gareng string is "susu" , equals with the concatenation of string of Semar and Bagong, "susu".

In the second case, "saa" is compared with "us" in the end.

In the third case, "kasukakaka" is compared with "sukakasu" in the end.

## Constraint

- 1 ≤ |S| ≤ 200,000
- S consists of only lowercase alphabet ('a'..'z')
- 1 ≤ T ≤ 100,000
- 1 ≤ li ≤ ri ≤ |S| for all i element {a1, b1, a2, b2}
- 1 ≤ mi ≤100,000 for all i element {a1, b1, a2, b2}
