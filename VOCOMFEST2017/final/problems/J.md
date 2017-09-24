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
