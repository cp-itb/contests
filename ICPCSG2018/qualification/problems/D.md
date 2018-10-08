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

