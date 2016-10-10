/**
 * Contest : INC 2016
 * Team    : GituKanYa
 * Author  : Jauhar Arifin
 * Problem : J - Rational Number
 */
 
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int t;
ll a,b;

long long pangkat(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % c;
	ll t = pangkat((a*a)%c, b/2, c);
	if (b % 2 == 1)
		return (a * t) % c;
	return t % c;
}

int phi(ll n){    
    ll result = n;
    for (ll p=2; p*p<=n; ++p){
		if (n % p == 0){
			while (n % p == 0)
				n /= p;
			result -= result / p;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	for (int tc = 1; tc <= t; tc++) {
		cin>>a>>b;
		
		if (a == 0) {
			cout<<"Case #"<<tc<<": "<<0<<endl;
			continue;
		}
		
		a = abs(a);
		b = abs(b);
		
		ll x = __gcd(a,b);
		a /= x;
		b /= x;
		
		if (__builtin_popcount(b) == 1) {
			cout<<"Case #"<<tc<<": "<<0<<endl;
			continue;
		}
		while (b % 2 == 0)
			b /= 2;
		while (b % 5 == 0)
			b /= 5;
		if (b == 1) {
			cout<<"Case #"<<tc<<": "<<0<<endl;
			continue;
		}
		
		bool yes = 0;
		ll p = phi(b);
		stack<ll> tmp;
		for (ll i = 1; i*i <= p; i++)
			if (p % i == 0) {
				tmp.push(p/i);
				if (pangkat(10LL,i,b) == 1LL) {
					cout<<"Case #"<<tc<<": "<<i<<endl;
					yes = 1;
					break;
				}
			}
		if (!yes)
			while (!tmp.empty()) {
				ll i = tmp.top(); tmp.pop();
				if (pangkat(10LL,i,b) == 1) {
					cout<<"Case #"<<tc<<": "<<i<<endl;
					break;
				}
			}
	}
	return 0;
}
