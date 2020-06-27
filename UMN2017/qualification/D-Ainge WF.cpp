/**
 * Contest : UMN 2017 Qualification
 * Team    : Ainge WF
 * Author  : Aufar Gilbran
 * Problem : D - Lift Menyebalkan
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int d[MAXN+5];

int main(){
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		memset(d,-1,sizeof(d));

		int N, X, Y, A, B;
		scanf("%d%d%d%d%d", &N,&X,&Y,&A,&B);
		
		queue<int> Q;
		Q.push(X);
		d[X] = 0;

		printf("Case #%d: ", itc);
		while (!Q.empty()) {
			int v = Q.front();
			Q.pop();
			if (v == Y) break;
			for (int dir = 0; dir < 4; ++dir) {
				if (v+A <= N && d[v+A] == -1) {
					Q.push(v+A);
					d[v+A] = d[v] + 1;
				}
				if (v-B > 0 && d[v-B] == -1) {
					Q.push(v-B);
					d[v-B] = d[v] + 1;
				}
			}
		}

		if (d[Y] == -1)
			puts("Pakai tangga saja");
		else
			printf("%d\n", d[Y]);

	}
}
