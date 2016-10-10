/**
 * Contest : INC 2016
 * Team    : nagazaky
 * Author  : Ahmad Zaky
 * Problem : H - Negotiation Game
 */

#include <stdio.h>

int max(int a, int b) {
	return (a < b) ? b : a;
}
int min(int a, int b) {
	return (a > b) ? b : a;
}

#define MAXN 2200

int ntc, n, a[MAXN];
int dpagglmin[MAXN], dpaggrmin[MAXN], dpagglmax[MAXN], dpaggrmax[MAXN], dpmax, dpmin;

int itc, i, l, r, len, ans;

int main(){
	scanf("%d", &ntc);
	for(itc = 1; itc <= ntc; ++itc) {
		scanf("%d", &n);
		for(i = 1; i <= n; ++i) scanf("%d", &a[i]);

		for(i = 1; i <= n; ++i) {
			dpagglmax[i] = dpaggrmax[i] = dpagglmin[i] = dpaggrmin[i] = a[i];
		}
		ans = a[1];
		for(len = 2; len <= n; ++len) {
			for (l = 1, r = len; r <= n; ++l, ++r) {
				dpmax = max(dpagglmin[l], dpaggrmin[r]);
				dpmin = min(dpagglmax[l], dpaggrmax[r]);
				if (dpagglmin[l] < dpmin) {
					dpagglmin[l] = dpmin;
				}
				if (dpaggrmin[r] < dpmin) {
					dpaggrmin[r] = dpmin;
				}
				if (dpagglmax[l] > dpmax) {
					dpagglmax[l] = dpmax;
				}
				if (dpaggrmax[r] > dpmax) {
					dpaggrmax[r] = dpmax;
				}
				if (len == n) {
					ans = dpmin;
				}
			}
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	
	return 0;
}