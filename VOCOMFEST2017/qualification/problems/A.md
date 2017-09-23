# A - Goats Competition

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Mr. Blangkon and his goats are following Goats Competition in Yogyakarta. The competition is simple, a goat will go up to the stage one by one, and the judges will give scores based on its cuteness, smell, attitude, and other criterias. The winner is a goat with the highest score among the others. Mr. Blangkon compete does not only wants to win the competition but he also wants to set a new record as the highest score of all time.

You will be given four total scores from contestants and an integer R the current highest score. Print "new record!" if the winner set a new record (the winner total score greater than the current highest score), and "no new record" otherwise.

## Input Format

The first line of input contains an integer T, denoting the number of cases. Each case consists of a line contains of five Integers: G1, G2, G3, G4, and R. G1, G2, G3, and G4 denote the score of all four contestants.

## Output Format

For each case, output in a line "Case #X: Y", where X is the case number, starts from 1, and Y is a string as explained above.

## Sample Input

	2
	73 62 81 74 75
	73 62 81 74 82

## Sample Output

	Case #1: new record!
	Case #2: no new record

## Constraint

- 1 ≤ T ≤ 100
- 1 ≤ G1, G2, G3, G4, R. ≤ 100
