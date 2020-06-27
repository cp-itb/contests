# Problems

- [A - Cube](#a---cube)
- [B - Amazing Labyrinth](#b---amazing-labyrinth)
- [C - Amazing Sequence](#c---amazing-sequence)
- [D - Amazing Restaurant](#d---amazing-restaurant)
- [E - Triangles](#e---triangles)
- [F - Road Trip](#f---road-trip)
- [G - Petruk's Sequence](#g---petruks-sequence)
- [H - Amazing String](#h---amazing-string)
- [I - JogJek's Order](#i---jogjeks-order)
- [J - Signal Strength](#j---signal-strength)

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



# B - Amazing Labyrinth

| Time Limit   | 2s    |
|--------------|-------|
| Memory Limit | 128MB |

## Description

There is a group of N people, each of them has ID card labelled from 1,2,..N. They are going to enter the "Amazing Labyrinth". The labyrinth is an undirected graph with V vertices and E edges. Each vertex is labelled with number 1,2,...,V. The group will start at vertex 1. They will walk together as a group to reach the finish at vertex V.

The vertices in the labyrinth has a unique (yet deadly) rule. To be able to enter vertex k (k=1,2,...,V), all of the person with ID of rk,1, rk,2,...,rk,pk must be present and alive. If the requirement is not met, the group cannot enter the particular vertex. There are also sacrifices needed when exiting a vertex. To be able to exit from vertex k and move to another vertex, all of the person with ID of sk,1, sk,2,...,sk,qk must be sacrificed to death. Your task is to determine the maximum number of people in the group that can survive and enter the finish at vertex V.

## Input Format

The first line of input contains three integers V, E, and N. The next E lines, each contains two integers u and v, denoting that there is an edge from vertex u to vertex v (and vice versa). The next V lines, each contains an integer pk (k=1,2,...,V) followed by pk space-separated integers rk,1, rk,2,...,rk,pk. The next V lines, each contains an integer qk, followed by qk space-separated integers sk,1, sk,2,...,sk,qk.

## Output Format

Output a single integer, denoting the maximum number of people who can survive and enter the finish at vertex V. Output 0 if there is no person who can survive to enter the finish or there is no way to enter the finish at all.

## Sample Input 1

	4 4 5
	1 2
	1 3
	2 4
	3 4
	0
	2 2 3
	0
	0
	1 5
	2 1 4
	1 4
	0

## Sample Output 1
 
	3

## Sample Input 2

	4 3 4
	1 2
	2 3
	3 4
	0
	2 2 3
	2 1 2
	0
	0
	1 2
	2 3 4
	0

## Sample Output 2
 
	0

## Constraint

- 2 ≤ V ≤ 500
- 1 ≤ E ≤ 5000
- 1 ≤ N ≤ 16
- 0 ≤ pk, qk ≤ N
- 1 ≤ ri,j, si,j ≤ N



# C - Amazing Sequence

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

A sequence of non-negative integers (a1,a2,...,aN) is called "Amazing" if there exists a simple bipartite graph with N vertices (labeled from 1,2,...,N) with degrees of d1,d2,...,dN where di denotes the degree of vertex i and (d1,d2,...,dN) is a permutation of (a1,a2,...,aN).

Degree of a vertex in a graph is the number of edges connected to that vertex. Bipartite graph is a graph whose vertices can be divided into two disjoint sets U and V such that every edge connects a vertex in U to one in V.

Given a sequence of non-negative integers, determine whether that sequence is Amazing or no.

## Input Format

The first line of input contains an integer T denoting the number of cases.

For each case, the first line contains an integer N, denoting the length of the sequence. The next line contains N non-negative integers a1,a2,...,aN separated by space.

## Output Format

For each case, output in a line "Case #X:" where X is the case number, starts from 1. Followed by a string "YES" if the given sequence is Amazing, or a string "NO" if the sequence is not Amazing.

## Sample Input

	2
	3
	1 2 1
	3
	1 1 1

## Sample Output

	Case #1: YES
	Case #2: NO

## Explanation

For the 1st case, the graph below is a bipartite graph with 3 vertices with degree of 1,2,1.

![graph](https://user-images.githubusercontent.com/8296835/30779992-ad54229a-a12a-11e7-9477-dbb42178efba.jpg)

For the 2nd case, there is no bipartite graph that satisfies the condition.

## Constraint

- 1 ≤ T ≤ 10
- 2 ≤ N ≤ 16
- 0 ≤ ai < N



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




# G - Petruk's Sequence

| Time Limit   | 2s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Petruk's sequence is defined as follows: Hn=a.Hn-1 + b.Hn-2 for n ≥ 2 and H0=c, and H1=d.

Your task in the final of VOCOMFEST 2017 is to compute the value of H0+H1+...+Hk.

## Input Format

The first line of input contains an integer T denoting the number of cases. Each case contains five integers: a, b, c, d, and k as explained in the problem description above.

## Output Format

For each case, output “Case #X: Y”, where X is the case number starts from 1 and Y is the value of H0+H1+...+Hk. As this number could be very large, output Y modulo 1000000007 (109+7).

## Sample Input

	3
	1 1 1 1 1
	1 1 1 1 3
	3 2 2 1 5

## Sample Output

	Case #1: 2
	Case #2: 7
	Case #3: 411

## Constraint

- 1 ≤ T ≤ 100
- 1 ≤ a,b,c,d ≤ 10 
- 0 ≤ k ≤ 10<sup>9</sup>




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





# I - JogJek's Order

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

To improve transportation in Jogja, the government deployed a new transportation method called "JogJek". JogJek allows passengers to order for a driver to take them from one place to another. To order for a driver, passenger needs to use the application called "JogJek".

Now Mr. Blangkon is a "Jogjek" driver. Unfortunately, there are several crime done by some passengers against "Jogjek" drivers. The modus operandi is simple: a passenger orders a "Jogjek" driver, then the passenger will ask the driver to take the passenger to a quiet destination, and then the passenger will attack the driver. Because of it, Mr. Blangkon becomes more cautious.

On a midnight, he suddenly has an order to take a passenger to a destination (xt, yt). Because the order is in midnight, he is afraid that the order is dangerous. If he thinks that the order is dangerous, it is better for him to deny the order. He assumes that an order is dangerous if the destination of the order is not in a crowded place.

![img](https://user-images.githubusercontent.com/8296835/30780063-443a68d0-a12c-11e7-96b2-16592a7a7852.png)

Assume that a destination is a circle centered in (x, y) with radius R. A crowded place is the union between three or more connected destinations that was ordered before midnight (the circles intersect or touch another circle). See the figure above, Destination A is safe because it intersect with crowded place, but Destination B (only intersect with the union between two destination) and C are not.

Given N destinations visited by Mr. Blangkon during the day before midnight. Please help him determine whether the new destination intersects or touches a crowded place.

## Input Format

The first line of input contains an integer T denoting the number of cases. Each case contains of N+2 lines. First line of each case contains an integer, N, and a real number, R, denoting number of destinations visited by Mr. Blangkon during the day before midnight and the radius of destination, respectively. Each of next N lines contains two real numbers xi and yi, denoting the coordinate of each destination ordered before midnight, followed by a line contains two real numbers the coordinate of order's location, xt and yt.

## Output Format

For each case, output “Case #X: Y”, where X is the case number starts from 1, and Y is a string "ACCEPT", if the order's location is safe, or "DENY" otherwise

## Sample Input

	1
	3 1
	1 0
	0 1
	-1 0
	0 0

## Sample Output

	Case #1: ACCEPT

## Constraint

- 1 ≤ T ≤ 20
- 1 ≤ N ≤ 50000
- 1 ≤ R ≤ 100
- 1 ≤ |xi|, |yi|, |xt|, |yt| ≤ 1000





# J - Signal Strength

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Mr. Blangkon has a new job as a salesman. His job requires him to move around between places and his cellphone must be ready at anytime to receive a call or contacting someone. In his first job he is placed in a remote area where there are few mobile cell tower. Mobile cell tower emits signal around certain radius. For some reasons, each mobile cell tower in that area has different radius.

Mr. Blangkon wants to visit all of the places  in a day. He is interested in what is the worst signal strength on his cellphone while visiting places. Signal strength is defined as number of mobile cell tower signal that can be received by cellphone.

## Input Format

The first line consists of an integer T  denoting the number of test case that follow. For each test case, the line starts with two integer N and M each denoting number of places and number of cell tower respectively. The next N lines follow, each line contains two integer Xi and Yi denoting 2D coordinate of the place. Then M lines follow, each line contains three integer Xj, Yj and Rj, denoting tower location and its signal radius.

## Output Format

For each test case, output "Case #A: B" where A is test case number and B is an integer denoting the worst signal strength while Mr. Blangkon visiting places.

## Sample Input

	2
	2 2
	0 0
	2 2
	0 2 2
	2 0 2
	2 1
	2 0
	0 2
	1 1 2

## Sample Output

	Case #1: 2
	Case #2: 1

## Constraint

- 1 <= T <= 100
- 1 <= N <= 1000
- 1 <= M <= 10
- 0 <= Xi, Yi, Xj, Yj <= 1000
- 1 <= Ri <= 500
