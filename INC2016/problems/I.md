# I - Irpin's Walk

| Time Limit   | 7s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Irpin loves to walk around in the city where he lives. There are N intersections (numbered from 1 to N) and M bidirectional roads in the city where each road connects exactly two different intersections. Two intersections may have more than one roads connecting them because the mayor wants people to have many alternatives for their journey in the city, e.g., one can use a shorter and posibly boring road, or one can use a longer road with nice scenery.

A walk in the city is defined as an alternating sequence of intersections and roads (starting and ending at an intersection), in which each road in the sequence is incident to both of its adjacent roads. Note that, unlike a path, a walk may have repeating intersections and roads in its sequence.

Let W (walk's length) be the sum of all road's length in the walk, and R be the number of roads in the walk. If 2^R ≤ W, then the cost of the walk is 2\*W; otherwise the cost will simply be W. If you're wondering why such confusing method to calculate the walk cost, Irpin felt a short walk (walk which uses only few number of roads) is kind of "cheating"; therefore, he doubles the cost of any short walks, i.e. become 2\*W instead of W.

Suppose Irpin wants to have a walk from intersection A to intersection B, help him determine the minimum cost walk among all possible walks from A to B.

## Input

The first line of input contains an integer T (T ≤ 50) denoting the number of cases. Each case begins with four integers: N M A B (2 ≤ N ≤ 10,000; 1 ≤ M ≤ 100,000; 1 ≤ A, B ≤ N; A ≠ B) representing the number of intersections, the number of roads, intersection in which the walk starts, and intersection in which the walk ends, respectively. The following M lines each contains three integers: u v w (1 ≤ u, v ≤ N; u ≠ v; 1 ≤ w ≤ 1,000) representing a bidirectional road of length w which connects intersection u and v.

## Output

For each case, output in a line "Case #X:" where X is the case number, starts from 1, and Y is the cost of the walk with minimum cost from A to B for that particular case. If there is no possible walk from A to B, then output -1 for Y.

## Sample Input

	3
	5 5 1 3
	1 2 2
	2 3 1
	1 4 2
	4 5 2
	5 3 1
	5 5 1 3
	1 2 3
	2 3 2
	1 4 3
	4 5 2
	5 3 2
	3 1 1 3
	1 2 3

## Sample Output

	Case #1: 3
	Case #2: 7
	Case #3: -1

## Explanation

*Explanation for 1st sample case*

The walk with minimum cost is 1 - 2 - 3. The walk length W is 2 + 1 = 3, while the number of roads R is 2. As 2R = 22 = 4 is larger than W = 3, then the cost is 3.

*Explanation for 2nd sample case*

Follows are two possible walks (among many other) from intersection 1 to 3:
1 - 2 - 3; in this walk, W = 3 + 2 = 5, and R = 2. Since 2^R = 2^2 = 4 is no more than W = 5, then cost for this walk is 2 * W = 2 * 5 = 10.
1 - 4 - 5 - 3; in this walk, W = 3 + 2 + 2 = 7, and R = 3. Since 2^R = 2^3 = 8 is more than W = 7, then cost for this walk is W = 7.
Of course there are infinitely many other walks from intersection 1 to 3, but among all of them, walk 1 - 4 - 5 - 3 has the lowest cost of 7.

*Explanation for 3rd sample case*

There are no possible walk from intersection 1 to 3.
