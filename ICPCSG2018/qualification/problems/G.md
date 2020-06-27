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

