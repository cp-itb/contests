# D - Amazing Restaurant

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Petruk is a fresh graduate from a top university. Now he's doing internship at a multinational company. His internship period will be N days long. The company provides free breakfast and lunch for their employees, everyday. So Petruk usually have his dinner at a restaurant near his dormitory. There are 3 amazing restaurants around Petruk's dormitory. Lets call them Restaurant 1, Restaurant 2 and Restaurant 3. For each of the i-th day (i=1,2,...,N), Petruk knows the cost to have dinner at restaurant 1 is Ai, the cost at restaurant 2 is Bi, and the cost at restaurant 3 is Ci.

Each of the three amazing restaurants has a set of special days. Restaurant 1 marks P days, the x1-th, x2-th day,...,xP-th day as special days. Restaurant 2 marks Q days, the y1-th, y2-th day,...,yQ-th day as special days. And Restaurant 3 marks R days, the z1-th, z2-th day,...,zR-th day as special days. On a special day, if Petruk dine at a certain restaurant (by paying or use a free coupon), he will get a free dinner coupon for the next day at the same restaurant.

Petruk has M initial money. He wants to get through his internship period by spending as little as possible money to eat dinner. Help Petruk to determine the minimum cost to eat dinner for N days of his internship!

## Input Format

The first line of input contains an integer T denoting the number of cases.

For each case, the first line contains two integers N and M as stated in the description. The next N lines, each contains three integers Ai, Bi, and Ci (i=1,2,...,N). The next line contains an integer P, followed by P space-separated integers x1, x2,..., xP. The next line contains integer Q, followed by Q space-separated integers y1, y2,..., yQ. And the last line contains integer R, followed by R space-separated integers z1, z2,..., zR.

## Output Format

For each case, output in a line "Case #X:" where X is the case number, starts from 1. Then followed by an integer denoting the minimum cost to eat dinner for N days. If petruk's money does not sufficient to eat dinner for N days, print "Petruk is starving".

## Sample Input

	2
	3 10
	1 1 5
	4 7 12
	9 1 10
	1 2
	1 2
	2 1 2
	4 12
	3 3 4
	4 10 3
	4 9 5
	5 6 3
	0
	2 2 3
	0

## Sample Output

	Case #1: 5
	Case #2: Petruk is starving

## Explanation

For the 1st sample case, Petruk can have dinner for N days with minimum cost of 5. There are 2 available options:

- At day 1, dine at resturant 1 by paying 1. At day 2, dine at restaurant 1 by paying 4 and get free coupon to eat at restaurant 1 for day 3 (because day 2 is special for restaurant 1). At day 3 use the coupon to eat for free at restaurant 1. The total cost is 5.
- At day 1, dine at restaurant 3 by paying 5 and get free dinner coupon at restaurant 3 for day 2. At day 2, use the free coupon to dine at restaurant 3 for free, and get another free dinner coupon at restaurant 3 for day 3. At day 3, use the free coupon to dine at restaurant 3. The total cost is also 5.

For the 2nd sample case, Petruk's money is not enough to dine for N days, no matter how he chooses the restaurant.

## Constraint

- 1 ≤ T ≤ 50
- 1 ≤ N ≤ 200
- 0 ≤ M ≤ 2000
- 0 ≤ Ai, Bi, Ci ≤ 2000
- 0 ≤ P,Q,R < N
- 1 ≤ xi, yi, zi < N
