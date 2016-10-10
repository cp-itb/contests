/**
 * Contest : INC 2016
 * Team    : GituKanYa
 * Author  : Jauhar Arifin
 * Problem : E - Legendary Dance
 */

#include <bits/stdc++.h>

using namespace std;

int t,n,m,a[2000],b[2000],memo[2000][2000];

int main() {
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		memo[0][0] = a[0] == b[0];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (i == 0 && j == 0)
					continue;
				else if (a[i] == b[j])
					memo[i][j] = 1 + (i > 0 && j > 0 ? memo[i-1][j-1] : 0);
				else
					memo[i][j] = max(i > 0 ? memo[i-1][j] : 0, j > 0 ? memo[i][j-1] : 0);
		printf("Case #%d: %d\n", tc, m + n - memo[n-1][m-1]);
	}
	return 0;
}
