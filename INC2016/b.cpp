/**
 * Contest : INC 2016
 * Team    : GituKanYa
 * Author  : Jauhar Arifin
 * Problem : B - Compact Bag
 */

#include <bits/stdc++.h>

using namespace std;

int t,n,k,x,y,h,b[1000];

int main() {
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		sort(b, b + n);
		x = 0;
		y = 0;
		h = 0;
		while (x < n) {
			while (y < n && b[y] - b[x] <= k)
				y++;
			h = max(h, y - x);
			x++;
		}
		printf("Case #%d: %d\n", tc, h);
	}
	return 0;
}
