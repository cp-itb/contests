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
