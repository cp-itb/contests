# F - Road Trip

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

It's holiday season! Many families have been waiting for this season for various reasons. And one of the most popular reason is: Road trip.

Consider a highway that everyone use for road trip that has N rest areas, placed one after another. A rest area is a place to rest, with gas station, restaurants, etc. Each of the rest areas is numbered 1 to N, inclusive, with rest area number 1 is the nearest from highway's entry gate and number N is the farthest.

Let's say that every family who goes on a road trip has a car (those who don't will rent a car). They will use the highway for their road trip. But there's a catch: their mobile's gas tank can't carry enough gas for the whole trip. They must visit at a gas station to refill their gas exactly once (because refilling twice would be overkill). For each family, they will visit a gas station in rest area between Ai and Bi, inclusive. Unfortunately, each gas station has different price, denoted by Pi. Every family is wondering, what is the expected price they will have to pay for the gas, assuming they pick a random rest area between Ai and Bi?

## Input Format

Input started with two integer N and M, denoting the number of rest areas in the highway, and the number of families going on road trip.
On the second line, there will be N integer, Pi, denoting the gas price for gas station in rest area-i.
the next M+2 line contains Ai and Bi, denoting the rest area family-i wants to visit.

## Output Format

For each family i, print the expected price for the gas in a line, with 6 decimal places. Your answer will be considered as correct if it has an absolute or relative error less than 1e-3 (10-3).

## Sample Input

	5 4
	1 1 3 4 5
	1 2
	2 4
	3 5
	1 3

## Sample Output

	1.000000
	2.666667
	4.000000
	1.666667

## Constraint

- 1 ≤ N ≤ 100000
- 1 ≤ M ≤ 100000
- 1 ≤ Ai ≤ Bi ≤ N
- 1 ≤ Pi ≤ 10000
