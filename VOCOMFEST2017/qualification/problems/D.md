# D - Friends

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Mr. Blangkon has N friends. Each of them invites him to a meeting at a certain time. Even though Mr. Blangkon is invited, he has to pay for accommodation. Because of the importance of the meeting, Mr. Blangkon can't go to two or more meetings in same day.

For example, Mr. Blangkon has 4 friends, Semar, Gareng, Petruk, and Bagong.

- Semar invites Mr. Blangkon at day 1 until day 3 (inclusive), and Mr. Blangkon has to pay 3 dollars.
- Gareng invites Mr. Blangkon at day 2 until day 5 (inclusive), and Mr. Blangkon has to pay 1 dollars.
- Petruk invites Mr. Blangkon at day 4 until day 7 (inclusive), and Mr. Blangkon has to pay 3 dollars.
- Bagong invites Mr. Blangkon at day 3 until day 5 (inclusive), and Mr. Blangkon has to pay 2 dollars.

Mr. Blangkon wants to come to all meetings that don't overlap each other, and now he has M dollars. Assume that if he comes to a meeting, he will join the meeting from the first day until the last day.

Your task is to determine the maximum number of meetings that Mr. Blangkon can come so that the total amount he has to pay is not greater than M.

## Input Format

The first line of input contains an integer T denoting the number of cases. Each case contains of N+1 lines. First line of each case contains two integers: N and M as explained in the problem description above. Each of next N lines contains three integers: A, B, C, denoting first day of a meeting, last day of a meeting, and the amount Mr. Blangkon has to pay, respectively.

## Output Format

For each case, output “Case #X: Y”, where X is the case number starts from 1, and Y is the maximum number of meetings that Mr. Blangkon can come so that the total amount he has to pay is not greater than M.

## Sample Input

	2
	4 6
	1 3 3
	2 5 1
	4 7 3
	3 5 2
	4 5
	1 3 3
	2 5 1
	4 7 3
	3 5 2

## Sample Output

	Case #1: 2
	Case #2: 1

## Constraint

- 1 ≤ T ≤ 100
- 1 ≤ N,M ≤ 100
- 1 ≤ A,B,C ≤ 100, A ≤ B

## Explanation

Explanation for 1st case:

Mr. Blangkon can go to two meetings: 1st meeting and 3rd meeting, and the total amount he has to pay is 6 dollars.

Explanation for 2nd case:

Mr. Blangkon can only go to one meeting. Note that he can't go to both 1st and 4th meetings, because 1st meeting is still held in day 3 and 4th meeting starts in day 3.
