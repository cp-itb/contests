# B - Compact Bag

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

In mathematics, a bag (or multiset) refers to a collection of objects/elements. This concept is similar to set, but it allows multiple instances of the same object. For example, {2, 4, 4} and {2, 2, 4} are two different bags even though they are the same set of {2, 4}.

Similar to subset, subbag is a partial bag where each element of it is taken from a bag. For example, follows are all different subbags of a bag {2, 4, 4}:

- { } – empty bag (∅)
- {2}
- {4}
- {2, 4}
- {4, 4}
- {2, 4, 4}

Likewise, the size of a bag or subbag is the number of objects in the bag/subbag.

Given a bag B of N elements and a threshold integer K, your task is to determine the size of the largest-size subbag of B where the difference between any two elements in that subbag is no more than K.

## Input

The first line of input contains an integer T (T ≤ 100) denoting the number of cases. Each case begins with two integers: N and K (1 ≤ N ≤ 1,000; 0 ≤ K ≤ 2,000,000,000) denoting the size of the given bag and the threshold integer as explained in the problem statement, respectively. The next line contains N integers Bi (-1,000,000,000 ≤ Bi ≤ 1,000,000,000) representing the elements in the bag.

## Output

For each case, output in a line "Case #X: Y" where X is the case number, starts from 1, and Y is the output for that particular case.

## Sample Input

	4
	3 1
	2 4 4
	3 2
	2 4 4
	7 3
	19 17 21 21 -10 17 18
	9 10
	20 100 100 20 20 103 20 105 100

## Sample Output

	Case #1: 2
	Case #2: 3
	Case #3: 4
	Case #4: 5

## Explanation

*Explanation for 1st sample case*

The largest subbag is {4, 4} of size 2. We cannot have {2, 4, 4} as the answer because the difference between 2 and 4 is 2, which is larger than 1.

*Explanation for 2nd sample case*

The largest subbag is {2, 4, 4} of size 3.

*Explanation for 3rd sample case*

The largest subbag is {19, 17, 17, 18} of size 4.

*Explanation for 4th sample case*

The largest subbag is {100, 100, 103, 105, 100} of size 5. The largest difference between any two elements in this subbag is 5 (100 and 105), and it's no more than 10.
