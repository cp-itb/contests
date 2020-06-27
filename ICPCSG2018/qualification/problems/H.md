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


