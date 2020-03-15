/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Farras Mohammad Hibban Faddila
 * Problem : C - Hyper Power
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll powmod(ll a, ll b, ll c){
	ll res = 1;
	while(b>0){
		if(b&1) res = res * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--){
		ll a, b;
		cin >> a >> b;

		ll mod4, mod25, mod5, mod20;

		if(b==1) {

			ll ans = a%100;
			cout << ((ans<10) ? "0" : "") << ans;

		} else {

			if(a%4==1) mod4 = 1;
			else if(a%4==3) mod4 = 3;
			else mod4 = 0;

			if(a%5==0) {
				mod25 = 0;
			} else {

				if(b==2){
					mod25 = powmod(a,a,25);
				} else {

					if(a%5==0) mod5 = 0;
					else {
						int poww;
						if(b==3) poww = a%4;
						else poww = mod4;
						mod5 = powmod(a,poww,5);
					}

					mod20 = ((5*mod4 - 4*mod5)%20+20)%20;
					mod25 = powmod(a,mod20,25);

				}

			}

			ll ans = ((25*mod4 - 24*mod25)%100+100)%100;

			cout << ((ans<10) ? "0" : "") << ans;

		}

		cout << "\n";

	}

}
