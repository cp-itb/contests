# F - Kill The Goats

| Time Limit   | 3s    |
|--------------|-------|
| Memory Limit | 512MB |

## Description

Mr. Blangkon is monitoring his backyard garden using a drone. He has N goats in his garden. He usually addressed them as "Wedhus". Each of those goats is located in a cartesian coordinate (xi, yi).

Because of the exceedingly large number of goats in his garden, Mr. Blangkon wants to kill a pair of goats, which consists of exactly two goats. He only has a bomb with an explosive radius of R. When this bomb has exploded and killed exactly two goats nearest to the explosion point, the other goats will not be affected by the explosion even though they are still within the radius of explosion. Of course, it is possible that the bomb will not kill a pair of two goats. So Mr. Blangkon will drop the bomb right in the middle of two goats that has the nearest distance to each other. If there are many possible explosion points, Mr. Blangkon will choose the one with the smallest xi value. If there are more than one explosion point with the smallest xi, he will choose the one with smallest yi value. Help Mr. Blangkon to determine the explosion point of his bomb.

## Input Format

The first line of input consists of an integer T, denoting the number of cases. For each case, the first line consists of two integers N and R. The next N lines, each consists of two integers xi and yi (i=1,2,...,N) separated by a whitespace, denoting the position of the i-th goat.

## Output Format

For each case output in a line "Case #Z: ", where Z is the case number, starts from 1. Then followed two numbers X and Y (with one decimal place), denoting the coordinate of explosion point for the corresponding case. If there is no possible explosion point, output -1.

## Sample Input

	2
	4 2
	0 0
	10 10
	0 4
	20 20
	4 1
	0 0
	10 10
	0 4
	20 20

## Sample Output

	Case #1: 0.0 2.0
	Case #2: -1

## Explanation

In the 1st case, the bomb will be exploded at (0, 2) to kill the goats at position (0, 0) and (0, 4).

In the 2nd case, there is no possible explosion point because the explosive radius would not kill any pair of two goats.

## Constraint

- 1 ≤ T ≤ 100
- 2 ≤ N ≤ 10000
- 0 ≤ R ≤ 10000000
- 0 ≤ xi,yi ≤ 1000000
- It is guaranteed that all goats have different position.
