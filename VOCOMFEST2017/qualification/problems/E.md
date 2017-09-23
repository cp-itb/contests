# E - JogJek

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

To improve transportation in Jogja, the government deployed a new transportation method called "JogJek". JogJek allows passengers to order for a driver to take them from one place to another. To order for a driver, passenger needs to use the application called "JogJek".

Assume that Jogja is represented as 2D cartesian coordinate system. There are N JogJek Drivers, numbered from 1,2,...N. Each of the i-th driver has a name and initial position (xi, yi). Also there are M orders, numbered 1,2,...,M. Each order consists of the position of the passenger (ai, bi) and the destination of the passenger (ci, di). The orders will be processed sequentially, starting from 1st order. The application will process each of the i-th order according to the following steps:

1. Select a driver who has the position with smallest manhattan distance from (ai, bi). If there are more than one driver with smallest distance, select the one with smallest name lexicographically. Recall that the manhattan distance between two coordinates (x1,y1) and (x2,y2) is |x2-x1|+|y2-y1|.
2. Assign the driver to the current order, giving the information about (ai, bi) and (ci, di) to the driver. The driver then will come to the passenger and transport him to the destination,
3. Wait for the selected driver to finish transporting the current passenger before processing the (i+1)-th order.
Note that when a driver reached the destination of an order, he will drop the passenger off and stay there to wait for another order. Your task is to output the names of driver that will be assigned to each order.

Some of you may wonder about the fee. Well, it's free! Because this is Jogja :)

## Input Format

The first line of input contains an integer T denoting the number of cases.

For each case, the first line contains integer N,M. Each of the next N lines contain a string si and two integer xi,yi denoting the name and initial position of the i-th driver (i=1..N, respectively). Then each of the next M lines contains integer aj,bj,cj,dj  denoting the passenger's position and destination on the j-th order (j=1..M, respectively). It is guaranteed that there is no j such that aj=cj and bj=dj. That is, the initial position and destination of an order is always different.

## Output Format

For each case, output in a line "Case #X:" where X is the case number, starts from 1. Each of the next M lines contains a string denoting the name of driver that will be assigned to the i-th order, i=1,2,...,M.

## Sample Input

	2
	3 2
	gareng 0 1
	bagong 2 3
	petruk -2 4
	0 0 3 2
	1 2 5 5
	2 3
	semar 0 0
	blangkon 2 2
	1 1 5 5
	1 2 -5 5
	-3 2 1 1

## Sample Output

	Case #1:
	gareng
	bagong
	Case #2:
	blangkon
	semar
	semar

## Explanation for 1st Case

There are 3 drivers and 2 orders.

First, process order 1. The position of passenger is at (0,0). The distance from each driver:

- gareng is at (0,1), distance = |0-0|+|0-1| =1
- bagong is at (2,3), distance = |0-2|+|0-3| =5
- petruk is at (-2,4), distance = |0-(-2)|+|0-4| =6
- gareng has the smallest distance to (0,0). So gareng will be assigned to order 1.
- When order 1 has finished, gareng's position will change to (3,2).
Second, process order 2. The position of passenger is at (1,2). The distance from each driver:

- gareng is at (3,2), distance = |1-3|+|2-2| = 2
- bagong is at (2,3), distance = |1-2|+|2-3| = 2
- petruk is at (-2,4), distance = |1-(-2)|+|2-4| = 5
- Both gareng and bagong has the smallest distance to (1,2). Because "bagong" is lexicographically smaller than "gareng", bagong will be assigned to order 2.
- When order 2 has finished, bagong's position will change to (5,5).

## Constraint

- 1 ≤ T ≤ 100
- 1 ≤ N,M ≤100
- -10<sup>5</sup> ≤ xi,yi ≤ 10<sup>5</sup>
- -10<sup>5</sup> ≤ aj,bj,cj,dj ≤ 10<sup>5</sup>
- All drivers have different names. Each name consists of lowercase letter only and has no more than 100 characters length.
