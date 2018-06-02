/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : Arurange Code Party
 * Author  : Dewita Sonya Tarabunga
 * Problem : I - Irigation
 */

#include <bits/stdc++.h>

// MACROS SAMPAH
#define Arno using
#define Dewita namespace
#define Jehian std

Arno Dewita Jehian;

// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;

// MACROS FOR ATTRIBUTE
#define fi first
#define se second

// MACROS FOR FUNCTION AND METHOD
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define ALL(x) (x).begin(), (x).end()
#define ALLSIZE(x,n) (x), (x)+(n)
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))

// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

ll tab[2005][2005];
ll data[2005][2005];

ll query(pll A, pll B){
	ll ans = tab[B.fi][B.se];
	if (A.fi > 1){
		ans -= tab[A.fi-1][B.se];
	}
	if (A.se > 1){
		ans -= tab[B.fi][A.se-1];
	}
	if (A.fi > 1 && A.se > 1){
		ans += tab[A.fi-1][A.se-1];
	}
	return ans;
}

ll dist(pll A, pll B){
	return abs(A.fi-B.fi) + abs(A.se-B.se);
}

int main(){
	ll N, M;
	scll(N); scll(M);
	for (ll i = 1; i <= N; ++i){
		for (ll j = 1; j <= M; ++j){
			scll(data[i][j]);
		}
	}
	pll pusat = {(N+1)/2, (M+1)/2};
	for (ll i = 1; i <= N; ++i){
		for (ll j = 1; j <= M; ++j){
			if (i == 1 && j == 1){
				tab[i][j] = data[i][j];
			} else if (i == 1){
				tab[i][j] = data[i][j];
				tab[i][j] += tab[i][j-1];
			} else if (j == 1){
				tab[i][j] = data[i][j];
				tab[i][j] += tab[i-1][j];
			} else {
				tab[i][j] = data[i][j];
				tab[i][j] += tab[i][j-1];
				tab[i][j] += tab[i-1][j];
				tab[i][j] -= tab[i-1][j-1];
			}
		}
	}
	vector< pair<ll, pair<ll, pll> > > ans;
	for (ll i = 2; i < N; ++i){
		for (ll j = 2; j < M; ++j){
			ll sum = 0;
			//cerr << "Anak dari titik: " << i << " " << j << endl;
			if (i > 1 && j > 1){
				//cerr << "Kuadran I" << endl;
				sum += query({1,1}, {i-1,j-1});
				//cerr << 0 << " " << 0 << " -> " << i-1 << " " << j-1 << " = " << query({0,0}, {i-1,j-1}) << endl;
			}
			if (i > 1 && j < M){
				//cerr << "Kuadran II" << endl;
				sum += query({1,j+1}, {i-1,M});
				//cerr << 0 << " " << j+1 << " -> " << i-1 << " " << M-1 << " = " << query({0,j+1}, {i-1,M-1}) << endl;
			}
			if (i < N && j < M){
				//cerr << "Kuadran III" << endl;
				sum += query({i+1,j+1}, {N,M});
				//cerr << i+1 << " " << j+1 << " -> " << i+1 << " " << j+1 << " = " << query({i+1,j+1}, {N-1,M-1}) << endl;
			}
			if (i < N && j > 1){
				//cerr << "Kuadran IV" << endl;
				sum += query({i+1,1}, {N,j-1});
				//cerr << i+1 << " " << 0 << " -> " << N-1 << " " << j-1 << " = " << query({i+1,0}, {N-1,j-1}) << endl;
			}
			//cerr << sum << " -> " << i << " " << j << endl; 
			//cerr << " ==================== " << endl;
			ans.pb({sum, {-dist(pusat, {i,j}), {-i,-j}}});
		}
	}
	pair<ll, pair<ll, pll> > answer = *max_element(ALL(ans));
	printf("%lld\n%lld %lld\n", answer.fi, -answer.se.se.fi, -answer.se.se.se);
	return 0;
}