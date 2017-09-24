# B - Family Reunion

| Time Limit   | 1s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

One day, Mr.Blangkon attended his family reunion. There are N people who attend that reunion, including Mr.Blangkon. Suddenly a mysterious person approached Mr.Blangkon. Then the following conversation occurs:

Mysterious Person: "Hey Blangkon! long time no see. Remember me?"
Blangkon: *Surprised* "Oh hey! I'm sorry, who are you?"
Mysterious Person: "Oh! What's wrong with you? It's me, Tejo. We have the same grandfather."
Blangkon: "Tejo? Ah, long time no see. You look fatter, though.."
After finishing his conversation with Tejo, Mr.Blangkon thinks, "Hmm, I even forgot my own cousin. What should I do?"

Fortunately, Mr.Blangkon have a list of the people who attend the reunion, along with the father's name of each person (All members of Blangkon's family attended the reunion).

Mr.Blangkon thinks if he is called by someone, how could he determine the relationship between that person and himself? Please help Mr.Blangkon!

## Input Format

The first line of input contains two integer N and T, denoting the number of people who attended the reunion and the number of people who called Mr.Blangkon, respectively.

The next N-1 lines, each consists of two string A and B. A denotes the name of a person and B denotes the name of that person's father.

The next T lines, each consists of a string C, denoting the name of a person who called Mr.Blangkon.

## Output Format

For each person C who called Mr.Blangkon, assume that the Lowest Common Ancestor between Mr.Blangkon and C is Y, then:

In the first line, output "Case #X:", where X is the case number starts from 1;
In the second line, output the lineage from Y to Mr.Blangkon;
In the third line, output the lineage from Y to C.
There should be a line break between two consecutive cases. See sample cases for the output format.

## Sample Input 1

	5 1
	Ahmad Abdul
	Adi Abdul
	Tejo Ahmad
	Blangkon Adi
	Tejo

## Sample Output 1
 
	Case #1:
	Abdul->Adi->Blangkon
	Abdul->Ahmad->Tejo

## Sample Input 2

	2 1
	Blangkon Adi
	Adi

## Sample Output 2
 
	Case #1:
	Adi->Blangkon
	Adi

## Sample Input 3

	7 2
	Ahmad Abdul
	Adi Abdul
	Asep Abdul
	Tejo Ahmad
	Surti Adi
	Blangkon Adi
	Surti
	Tejo

## Sample Output 3
 
	Case #1:
	Adi->Blangkon
	Adi->Surti

	Case #2:
	Abdul->Adi->Blangkon
	Abdul->Ahmad->Tejo


## Constraint

- 1 < N ≤ 1000
- 1 ≤ T < N
- 1 ≤ |A|, |B| ≤ 20
- The name of person who attends the reunion is a string that consists of alphabets only (A-Z, a-z), and all names are unique to each other.
- There is only one person who doesn't have a father.
- It is guaranteed that the list of names contains the name of Mr.Blangkon and the person who called him.
