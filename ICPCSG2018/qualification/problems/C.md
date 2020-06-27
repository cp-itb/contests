# C - Making Palindromes

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 1024MB |

An alphabetical string is a string consisting of 0 or more capital letters (i.e. [‘A’..‘Z’]). Given an alphabetical string S[1..N], determine the number of palindromic alphabetical strings of length 2N that contains S as a subsequence (not necessarily contiguous). A string is palindromic if it is equal to its reverse.

## Input

The first line of input is an integer representing N, constrained to 0≤N≤200.

The second line of input is an alphabetical string S
of length N.

## Output

Output the number of palindromic alphabetical strings of length 2N containing S as a subsequence. As this could be rather large, output it modulo 10^9+7.

## Sample Input 1

	2
	AA


## Sample Output 1

	51


## Sample Input 2

	2
	AB

## Sample Output 2

	2

