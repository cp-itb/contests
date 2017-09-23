# G - Wireless Internet Connection

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Mr. Blangkon wants to install internet connection at his home. He decided to use wireless internet connection. Wireless internet needs a receiver tower to be installed in Mr. Blangkon's house. This tower must be located within the range of transmitter tower owned by the internet provider. Mr. Blangkon plans to install a receiver tower on his housetop. It is also required that there is no obstacle between the receiver and transmitter tower. A building is considered an obstacle if that building intersects the straight line drawn from the top of receiver tower to the top of transmitter tower. If there is an obstacle between the receiver and transmitter, the connection cannot be established, so the receiver tower must be built with a larger height.

Mr. Blangkon wants to know the minimum height of receiver tower needed to be able to connect with the transmitter tower. Because he lives in a crowded city, there are many buildings that could become obstacles, blocking the signal from transmitter tower. Then he collected the data about the height of buildings around his house and the height of transmitter tower to help in calculating the height of receiver.

When calculating, Mr. Blangkon assumes that the distance between adjacent building is constant, and each building has a very small width so it can be ignored.

## Input Format

The first line of input contains an integer T denoting the number of cases. For each case, the first line consists of 3 integers N denoting the number of buildings (including Mr. Blangkon's house and the transmitter tower), A denoting the index of Mr.Blankon's house, and B denoting the index of transmitter tower. The second line, each contains N integers Hi denoting the height of building at the i-th index (i=1,2,...N). 

## Output Format

For each case, output in a line "Case #X: Y" where X is the case number, starts from 1 and Y is an integer denoting the minimum height of receiver tower that must be built to establish internet connection.

## Sample Input

	2
	3 1 3
	2 1 3
	5 2 4
	1 2 3 4 5

## Sample Output

	Case #1: 0
	Case #2: 1

## Constraint

- 1 ≤ T ≤ 100
- 2 ≤ N ≤ 100000
- 1 ≤ A,B ≤ N
- 1 ≤ Hi ≤ 1000000000

