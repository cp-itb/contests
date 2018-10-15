# A - Knight Search

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 1024MB |

Alice is a chess knight living in Chessland (an N×N board). The cells in Chessland are numbered from 1 to N2 in row major order. Each cell has an UPPERCASE alphabet character assigned to it. The Chessland is described by a string S of length N2 (in row major order). For example for N=5 and S = “IXIXXXXCXAXSXXPXXCSXAGXXX”, the Chessland that Alice lives in looks like this:

	  12345
	  -----
	1|IXIXX
	2|XXCXA
	3|XSXXP
	4|XXCSX
	5|AGXXX

As Alice is a chess knight, she can only move from cell (a,b)
to cell (c,d) in Chessland if and only if (a−c)2+(b−d)2=5. Alice wonder if she can find her favorite string “ICPCASIASG” in Chessland by starting from a cell with character ‘I’ and finds the other 9

characters by jumping around in Chessland using chess knight movements. Alice can visit the same cell more than once.

You are of course Bob the computing bee and your job is to help her decide the answer.

## Input

The first line of input consists of 1 integer: N (1≤N≤100). The second line contains a string S of N2 UPPERCASE characters [‘A’..‘Z’] that describe Chessland.

## Output

Print “YES” if Alice can find string “ICPCASIASG” in Chessland or print “NO” otherwise.

## Sample Input 1

	5
	IXIXXXXCXAXSXXPXXCSXAGXXX

## Sample Output 1

	YES

## Sample Input 2

	5
	THEQUICKBROWNFOXJUMPSOVER

## Sample Output 2

	NO

