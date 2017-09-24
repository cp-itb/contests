# E - Triangles

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

You are given two triangles, triangle ABC and triangle DEF. Point A is located in (xA, yA), point B is located in (xB, yB), point C is located in (xC, yC), point D is located in (xD, yD), point E is located in (xE, yE), and point F is located in (xF, yF).

Your task is to compute the area of intersection between triangle ABC and DEF.

## Input Format

The first line of input contains an integer T denoting the number of cases. Each case contains two lines: First line contains six integers, xA, yA, xB, yB, xC, yC, and the second line also contains six integers, xD, yD, xE, yE, xF, yF as explained in the problem description above.

## Output Format

For each case, output “Case #X: Y”, where X is the case number starts from 1, and Y is the area of intersection between triangle ABC and triangle DEF, in 6 decimal places. The answer will be considered as correct if it has an absolute or relative error less than 1e-4 (10-4).​

## Sample Input

	2
	-1 1 3 -2 6 1
	3 -1 1 4 4 2
	-1 1 3 -2 6 1
	1 4 4 4 3 3

## Sample Output

	Case #1: 1.466667
	Case #2: 0.000000

## Constraint

- 1 ≤ T ≤ 1000
- -1000 ≤ xA, yA, xB, yB, xC, yC, xD, yD, xE, yE, xF, yF ≤ 1000
- It is guarenteed that ABC and DEF have positive areas.
