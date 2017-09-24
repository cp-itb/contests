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
