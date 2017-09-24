# E - Legendary Dance

| Time Limit   | 4s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Once upon a time, there was a legendary and very beautiful dance in ancient time performed only in king's coronation ceremony. The time of kings has passed and now we have a president as the head of our beloved nation. However, as a computer science student who loves art and history, Sandy is very interested in this legend and wanted to know more about this dance. He spent the whole afternoons during his short-term break in his school library, and finally found out that someone has resurrected the legendary dance. The details are put in two video records.

Let's agree on some definitions first so that explaining the problem becomes easier.

- A dance consists of one or more dance-moves in order, or simply "move".
- Each move is represented by an integer. Two integers of the same value represent a same move.
- A sequence of moves contains one or more moves in order, but not necessarilly continuous moves. For example, let a dance represented by a (complete) sequence of moves: 1 – 2 – 2 – 3 – 4 – 5. In this dance, 1 – 2 – 4 is one valid sequence, while 5 – 3 is not.

Let's get back to the main story. The two video records, each contains one sequence of moves which is believed to be part of the legendary dance. Now, Sandy is curious; assuming the dance sequence in these videos are indeed part of the legendary dance, how many dance moves in total will there be in the complete legendary dance? As there are no indication that these two videos are complete, Sandy is only interested in the minimum possible number of moves of the legendary dance. Note that however these two videos may contain an overlapping dance moves.

For example, let the two sequences be A = 10 – 17 – 10, and B = 17 – 12 – 10 – 10 – 15. Then, the minimum possible number of moves in the complete dance will be 6 (as shown below).

	A :  10 17    10
	B :     17 12 10 10 15
	----------------------
	C :  10 17 12 10 10 15

Of course C is not necessarily the legendary dance, but any legendary dance will have at least 6 moves as shown in C.

Your task in this problem is, given two sequence of moves which are part of the legendary dance, determine the minimum possible number of moves in the complete legendary dance.

## Input

The first line of input contains an integer T (1 ≤ T ≤ 100) denoting the number of cases. Each case begins with two integers in a line N and M (1 ≤ N, M ≤ 1,000) denoting the number of moves recorded in both video records. The second line of each case contains N integers Ai (1 ≤ Ai ≤ 2,000) representing the a sequence of dance moves in the first record. The third line of each case contains M integers Bi (1 ≤ Bi ≤ 2,000) representing a sequence of dance moves in the second record.

## Output

For each case, output in a line "Case #X:" where X is the case number, starts from 1, and Y is the minimum possible number of moves in the legendary dance for that particular case.

## Sample Input

	4
	3 5
	10 17 10
	17 12 10 10 15
	4 4
	1 2 3 4
	5 6 7 8
	4 4
	1 2 3 4
	1 2 3 4
	4 4
	1 2 3 4
	2 3 4 5

## Sample Output

	Case #1: 6
	Case #2: 8
	Case #3: 4
	Case #4: 5

## Explanation

*Explanation for 2nd sample case*

There are no common moves recorded on both records. Any possible legendary dance should consist of at least 8 moves.


*Explanation for 3rd sample case*

Both records contain the same dance moves. It might be possible that both of them are the complete legendary dance.
