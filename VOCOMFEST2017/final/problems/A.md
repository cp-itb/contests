# A - Cube

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Petruk has infinitely many 1x1x1 white cubes. He then chooses N<sup>3</sup> cubes to be arranged into one NxNxN cube. The resulting NxNxN cube then is painted with 6 different colors (other than white), one color for each side and no two sides are painted with the same color.

Petruk then breaks apart the painted NxNxN cube back into <sup>3</sup>  1x1x1 cubes. He wonders how many 1x1x1 cubes that have 1 color, 2 different colors, 3 different colors, and 4 different colors. He wants you to help him.

## Input Format

The first line of input contains an integer T denoting the number of cases. Each case contains an integer N as explained in the problem description above.

## Output Format

For each case, output “Case #X: A B C D”, where X is the case number starts from 1, and A, B, C, and D are the number of 1x1x1 cubes that has 1 color, 2 different colors, 3 different colors, and 4 different colors, respectively.

## Sample Input

	2
	3
	4

## Sample Output

	Case #1: 1 6 12 8
	Case #2: 8 24 24 8

## Constraint

- 1 ≤ T ≤ 1000
- 2 ≤ N ≤ 10000
