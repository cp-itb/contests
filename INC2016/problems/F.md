# F - Shady Antique Collector

| Time Limit   | 10s   |
|--------------|------|
| Memory Limit | 64MB |

## Description

Blue is a shady antique collector. Recently, through his shady connection, he managed to get himself a map of a certain dungeon which is known to be the home of some antique treasures. Fortunately for him, the map also came with the location of each treasure. The dungeon can be represented as a grid map of R rows and C columns. Each character in the map is:

- 'E' – represents the entrance/exit to the dungeon (you're also able to pass through this cell without exiting),
- '.' – represents an empty cell,
- '#' – represents an obstacle (you cannot go through this cell),
- '0' .. '9' – represents a cell with treasure (different number means different kind of treasure).

You always starts from the cell indicated by character 'E', which also serves as your exit point. From any cell, you can only move to its adjacent cells (north, south, west, east) given the destination cell is not an obstacle or out of the map.

Blue is a shady antique collector; he is neither an explorer nor hunter. He can hire one or more explorers from the Association for Collector and Marvel. However, the price of hiring explorers does not depend on the number of explorers being hired (he can hire all the available explorers if he want), but strictly depends on the time used by the explorers to do the exploring; specifically, the longest time spent by any explorer. Moreover, the explorers accept the direction given by Blue, in other words, the explorers movement are fully determined by Blue.

Blue decides to get at least K unique treasures from this dungeon. Note that there may be more than one of each treasure which are identical (represented by the same number in the map), but Blue's only concern is K unique treasures regardless of the total quantity. Help him to determine the minimum time required to collect at least K unique treasures when there are M explorers available for hire. Assume moving to adjacent cell cost 1 unit of time and picking any treasure cost no time.

For example, let's consider the following map of 5 x 5:

	E#1.0
	.##.#
	....#
	###.4
	32442

There are 5 unique treasures in this map (0, 1, 2, 3, and 4) with some duplicates (e.g., there are two treasure 2, and three treasure 4).

Let K = 4, if there is only 1 available explorer, then he needs 24 unit of times. Follow is one example path. Blue color represents the starting point, red color represents the path; notice that there are 24 red marks on this example. The collected treasures are 0, 1, 2, and 4.

	E#1.0   E#1.0   E#1.0   E#1.0   E#1.0
	.##.#   .##.#   .##.#   .##.#   .##.#
	....#   ....#   ....#   ....#   ....#
	###.4   ###.4   ###.4   ###.4   ###.4
	32442   32442   32442   32442   32442

If there are 2 available explorers (and K = 4), then they need 18 unit of time. Follow is one example to achieve that. Explorer #1 collects treasure 0 and 1 in 18 unit of time, while Explorer #2 collects treasure 2 and 4 in 16 unit of time. Thus, the total time is max(18, 16) = 18 unit of time.

Path for Explorer #1 (collecting treasure 0 and 1) – 18 unit of time:

	E#1.0   E#1.0   E#1.0
	.##.#   .##.#   .##.#
	....#   ....#   ....#
	###.4   ###.4   ###.4
	32442   32442   32442

Path for Explorer #2 (collecting treasure 2 and 4) – 16 unit of time:

	E#1.0   E#1.0   E#1.0
	.##.#   .##.#   .##.#
	....#   ....#   ....#
	###.4   ###.4   ###.4
	32442   32442   32442

## Input

The first line of input contains an integer T (T ≤ 100) denoting the number of cases. Each case begins with four integers: R, C, K, M (2 ≤ R, C ≤ 30; 0 ≤ K ≤ 10; 1 ≤ M ≤ 50) denoting the number of rows and columns of the map, minimum number of unique treasures required by Blue, and number of available explorers, respectively. The next R following lines each contains C characters representing the given map. Each character in the map is one of the following: E0123456789.# which meaning can be found in the problem statement. There will be exactly one 'E' in the map.

## Output

For each case, output in a line "Case #X: Y" where X is the case number, starts from 1, and Y is the minimum time required to collect at least K unique treasures with M explorers for that particular case, or -1 if it's not possible to do so.

## Sample Input

	4
	5 5 4 1
	E#1.0
	.##.#
	....#
	###.4
	32442
	5 5 4 2
	E#1.0
	.##.#
	....#
	###.4
	32442
	3 5 5 5
	..E.3
	.###0
	.73#3
	7 7 4 4
	..#321.
	2.#.#..
	3##.###
	0..E..2
	###.##1
	..#.#.0
	.301#..

## Sample Output

	Case #1: 24
	Case #2: 18
	Case #3: -1
	Case #4: 6

## Explanation

*Explanation for 3rd sample case*

There are only 3 unique treasures in the given map (0, 3, and 7), thus, there's no way to get 5 unique treasures in this case.


*Explanation for 4th sample case*

Dispatch each explorer to different direction and collects only the nearest treasure.
