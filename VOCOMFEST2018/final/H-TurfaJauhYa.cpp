/**
 * Contest : VOCOMFEST 2018 Final
 * Team    : Turfa Jauh Ya
 * Author  : Yonas Adiel
 * Problem : H - The Multiplier Kendi
 */

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll lcm(ll a, ll b) {
	return a/__gcd(a,b)*b;
}

void solve() {
	int n, a[20];
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	ll ans = (ll) a[n-1];
	ll last = ans;
	for (int i=n-1; i>=0; i--) {
		ll g = lcm(a[i], last);
		ans *= g/last;
		last = g/a[i];
		last += ans;
	}
	last -= ans;

	printf("%lld\n", last);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		printf("Case #%d: ", t);
		solve();
	}
}