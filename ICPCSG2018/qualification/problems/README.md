# Problems

- [A - Knight Search](#a---knight-search)
- [B - Swap to Sort](#b---swap-to-sort)
- [C - Making Palindromes](#c---making-palindromes)
- [D - Cave Exploration](#d---cave-exploration)
- [E - Grid Game](#e---grid-game)
- [F - Modulo Data Structures](#f---modulo-data-structures)
- [G - Fooling Around](#g---fooling-around)
- [H - Bee House Perimeter](#h---bee-house-perimeter)
- [I - Classical Counting](#i---classical-counting)
- [J - Unicyclic Count](#j---unicyclic-count)



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




# B - Swap to Sort

| Time Limit   | 2s     |
|--------------|--------|
| Memory Limit | 1024MB |

You are given an array A[1...N] with integers in decreasing order and a list of pairs (a1,b1), (a2,b2), …, (aK,bK). You wish to sort the array A in increasing order, each turn you choose an i (i can be chosen multiple times) and swap A[ai] with A[bi]. Determine whether this is possible.

## Input

The first line contains two integers, representing N and K respectively (1≤N,K≤106). The following K lines each contains two integers, representing ai and bi respectively (1≤ai<bi≤N).

## Output

Output “Yes” if it is possible to sort the array in increasing order, “No” otherwise.

## Sample Input 1

	5 2
	1 5
	2 4


## Sample Output 1

	Yes


## Sample Input 2

	5 4
	1 4
	2 3
	4 5
	1 5

## Sample Output 2

	No




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





# D - Cave Exploration

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 1024MB |

Alice is a soccer coach who occasionally bring her soccer team to explore Caveland (that can be modeled as an undirected unweighted connected graph) for special event, e.g. for initiation ceremony, to celebrate birthdays, etc. Caveland has N junctions and M tunnels.

Caveland is quite prone to flooding, but that does not stop Alice and her soccer team from doing what they enjoy. You are Bob, Alice’s good friend. You want to ensure Alice and her soccer team are as safe as possible by letting her know which junction(s) is/are safe(r) than the rest. You decide that a junction v
is considered to be safe(r) if any one tunnel is flooded, Alice and her soccer team can still go out from junction v to the entrance of Caveland (which is always junction 0) via a non-flooded path.

![img-0001](https://user-images.githubusercontent.com/8296835/46619775-2cd6e000-cb4d-11e8-994d-7ffb78aba063.png)

For this example, junctions {0,1,2,3} are considered safe(r). If tunnel 0–2 is flooded for example, Alice and her soccer team can detour via path 2→3→1→0 to reach Caveland entrance. However junctions {4,5,6,7,8} are quite dangerous. If tunnel 2–8 (or tunnel 3–4) is flooded, Alice and her soccer team will be trapped (cannot reach safety/junction 0).

## Input

The first line of input consists of 2 integers: N and M. (2≤N≤10000, 1≤M≤min(N(N−1)/2,100000)). The next M lines contains M pairs of integers u and v that describe 0-based indices of the two junctions that are connected with a tunnel in Caveland (0≤u,v<N, and u≠v). You are guaranteed that junction 0 can reach all the other N−1 junctions (if there is no flood).

## Output

Print an integer in one line: The total number of junction(s) in Caveland that is/are safe(r) for Alice and her soccer team to explore. The actual junction numbers are not needed.

## Sample Input 1

	9 10
	0 1
	0 2
	1 3
	2 3
	2 8
	3 4
	4 5
	4 6
	5 7
	6 7


## Sample Output 1

	4




# E - Grid Game

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 1024MB |

Given a N×N grid of integers, we can choose a combination of N numbers where no two in the same row and no two in the same column. We aim to find a combination of N numbers whose minimum is maximized.

## Input

The first line of input consists of an integer N, where 1≤N≤30. The next N lines each contains N integers, representing the grid. Each integer is in the range [1..10^6].

## Output

Output a single integer, representing the maximum possible value of the minimum.

## Sample Input 1

	3
	3 1 4
	1 5 1
	2 9 1


## Sample Output 1

	2

## Sample Input 2

	5
	17 24 1 8 15
	23 5 7 14 16
	4 6 13 20 22
	10 12 19 21 3
	11 18 25 2 9


## Sample Output 2

	21



# F - Modulo Data Structures

| Time Limit   | 2s     |
|--------------|--------|
| Memory Limit | 1024MB |

You have an array, Arr[1...N]. Initially, all values of Arr[i]=0. The array supports the following two types of queries
1. Increase all Arr[k] by C for all k≡A (mod B);
2. Output Arr[D] for a given D.

## Input

The first two lines of input consists of two integers, N and Q, representing the length of the array and the number of queries, respectively. Note that 1≤N,Q≤200000. The following Q lines all begin with an integer T representing the type of query. If T=1, then it will be followed by three integers representing A, B and C respectively. Note that 1≤C≤10000, 0≤A<B≤N. Else, T will be 2, and it will be followed by one integer representing D, subjected to 1≤D≤N.

## Output

For each query of type 2, output the integer value of Arr[D] on a separate line.

## Sample Input 1

	5 10
	1 1 2 7
	1 4 5 6
	1 2 3 3
	2 1
	2 2
	2 3
	1 3 4 3
	2 3
	2 4
	2 5


## Sample Output 1

	7
	3
	7
	10
	6
	10


# G - Fooling Around

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 1024MB |

Alice and Bob take turns playing a game, with Alice going first. They begin with a pile of N stones, each turn removing one less than a prime number of stones. The person who removes the last stone wins. Given N, determine who wins the the game.

## Input

The first line of input consists of a integer Q, the number of testcases, with 1≤Q≤100. The next Q lines each contains a single integer N, representing the number of stones in the pile, where 1≤N≤10^9.

## Output

For each test case, output the winner “Alice” or “Bob”. Each testcase’s output should be printed on their own line.

## Sample Input 1

	6
	1
	2
	3
	5
	8
	13	

## Sample Output 1

	Alice
	Alice
	Bob
	Alice
	Bob
	Alice




# H - Bee House Perimeter

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 1024MB |

Alice is a queen bee living in Beeland (a honeycomb structure described by R, the number of cells of the side of honeycomb). The cells in Beeland are numbered from 1 to R3−(R−1)3 in row major order. For example for R=3, the Beeland that Alice lives in looks like this:


![img-0001](https://user-images.githubusercontent.com/8296835/46620218-55aba500-cb4e-11e8-8ce8-a24b653e8d42.png)

Now Alice lives in a house that occupies K adjacent cells in Beeland. You are Bob, the knight bee. You need to protect Alice’s house, but first you need to know the length of its outer perimeter (the number of outermost sides of Alice’s house). The illustration below shows the visualizations of Sample Inputs/Outputs 2 and 3.

![img-0002](https://user-images.githubusercontent.com/8296835/46620234-5d6b4980-cb4e-11e8-920a-ab3329ccaf27.png)

## Input

The first line of input consists of two integers: R and K. (1≤R≤50, 1≤K≤R3−(R−1)3). The second line contains K unique integers that describe the indices of Alice’s house, where each integer is in the range [1,R3−(R−1)3].

## Output

Print an integer in one line: The perimeter of Alice’s house.

## Sample Input 1

	3 1
	7

## Sample Output 1

	6

## Sample Input 2

	3 6
	5 6 7 11 15 18

## Sample Output 2

	24

## Sample Input 3

	3 7
	5 6 11 15 18 14 9

## Sample Output 3

	20




# I - Classical Counting

| Time Limit   | 1s     |
|--------------|--------|
| Memory Limit | 1024MB |

You have N objects, each with M copies. How many ways are there to take exactly K of them?

## Input

The first line of input contains three integers, N, M and K respectively, subjected to 1≤N,M,K≤10^5.

## Output

Output the number of ways. As the number of ways could be large, output them modulo 10^6+7.

## Sample Input 1

	10 1 2

## Sample Output 1

	45

## Sample Input 2

	3 3 3

## Sample Output 2

	10

## Sample Input 3

	3 2 7

## Sample Output 3

	0





# J - Unicyclic Count

| Time Limit   | 2s     |
|--------------|--------|
| Memory Limit | 1024MB |

A unicyclic graph is a graph with exactly one cycle. A spanning subgraph of a graph G is a subgraph that has one component and includes all the vertices of G. Given a simple graph G, count the number of spanning unicyclic subgraphs. The illustration below shows the visualization of Sample Input/Output 1.

![hai](https://user-images.githubusercontent.com/8296835/46620527-2e090c80-cb4f-11e8-9882-3556d6fa2dec.png)

## Input

The first line of the input contains two integers, V and E, representing the number of vertices and edges of the graph G respectively. (1≤V≤17,0≤E≤V(V−1)/2.)

The following E lines each contains two integers Ai and Bi, representing an edge (Ai,Bi). It is guaranteed that 1≤Ai<Bi≤V and as the graph is simple, no two pairs represent the same edge.

## Output

Output one integer, representing the number of spanning unicylic subgraphs. As the number can be rather big, output it modulo 10^9+7.

## Sample Input 1

	4 5
	1 2
	1 3
	2 3
	1 4
	2 4

## Sample Output 1

	5

## Sample Input 2

	4 2
	1 2
	3 4

## Sample Output 2

	0



