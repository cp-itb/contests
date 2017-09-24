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
