 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Jauhar Wibisono
  * Problem : F - Pencerminan Prefix Suffix
  */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+4;
string s, t;
int n, q;

const long long base = 101, mod[] = {998244353, 1000000007};
long long bit_s[2][maxn], bit_t[2][maxn];

long long mod_pow(long long a, int b, long long m){
	long long ret = 1;
	for (; b; b>>=1){
		if (b&1){
			ret *= a;
			ret %= m;
		}
		a *= a;
		a %= m;
	}
	return ret;
}

void bit_s_update(int i, int j, long long val){
	while (j < maxn){
		bit_s[i][j] += val;
		bit_s[i][j] %= mod[i];
		j += j&-j;
	}
}

void bit_t_update(int i, int j, long long val){
	while (j < maxn){
		bit_t[i][j] += val;
		bit_t[i][j] %= mod[i];
		j += j&-j;
	}
}

void build(){
	memset(bit_s, 0, sizeof bit_s);
	memset(bit_t, 0, sizeof bit_t);
	for (int i=0; i<2; i++){
		for (int j=1; j<=n; j++){
			bit_s_update(i, j, (1LL*s[j-1]*mod_pow(base, j, mod[i]))%mod[i]);
			bit_t_update(i, j, (1LL*t[j-1]*mod_pow(base, j, mod[i]))%mod[i]);
		}
	}
}

long long bit_s_query(int i, int j, long long m){
	long long ret = 0;
	while (j > 0){
		ret += bit_s[i][j];
		ret %= m;
		j -= j&-j;
	}
	return ret;
}

long long bit_t_query(int i, int j, long long m){
	long long ret = 0;
	while (j > 0){
		ret += bit_t[i][j];
		ret %= m;
		j -= j&-j;
	}
	return ret;
}

int query(int l, int r){
	int ll = 1, rr = r-l+1, ans = 0;
	int ss = l, st = n-r+1;
	while (ll <= rr){
		int mid = (ll+rr)/2;
		pair<long long, long long> hs, ht;
		hs.first = (bit_s_query(0, ss+mid-1, mod[0]) - bit_s_query(0, ss-1, mod[0]) + mod[0]) % mod[0];
		hs.second = (bit_s_query(1, ss+mid-1, mod[1]) - bit_s_query(1, ss-1, mod[1]) + mod[1]) % mod[1];
		ht.first = (bit_t_query(0, st+mid-1, mod[0]) - bit_t_query(0, st-1, mod[0]) + mod[0]) % mod[0];
		ht.second = (bit_t_query(1, st+mid-1, mod[1]) - bit_t_query(1, st-1, mod[1]) + mod[1]) % mod[1];
		// normalize
		hs.first *= mod_pow(base, st-1, mod[0]);
		hs.first %= mod[0];
		hs.second *= mod_pow(base, st-1, mod[1]);
		hs.second %= mod[1];
		ht.first *= mod_pow(base, ss-1, mod[0]);
		ht.first %= mod[0];
		ht.second *= mod_pow(base, ss-1, mod[1]);
		ht.second %= mod[1];
		if (hs == ht){
			ans = mid;
			ll = mid+1;
		}
		else rr = mid-1;
	}
	return ans;
}

void update(int x, char c){
	for (int i=0; i<2; i++){
		long long news = (1LL*c*mod_pow(base, x, mod[i]))%mod[i];
		long long newt = (1LL*c*mod_pow(base, n-x+1, mod[i]))%mod[i];
		long long olds = (1LL*s[x-1]*mod_pow(base, x, mod[i]))%mod[i];
		long long oldt = (1LL*t[n-x]*mod_pow(base, n-x+1, mod[i]))%mod[i];
		long long diffs = (news - olds + mod[i]) % mod[i];
		long long difft = (newt - oldt + mod[i]) % mod[i];
		bit_s_update(i, x, diffs);
		bit_t_update(i, n-x+1, difft);
	}
	s[x-1] = c;
	t[n-x] = c;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> q;
	t = s;
	reverse(t.begin(), t.end());
	n = s.length();
	build();
	while (q--){
		int type;
		cin >> type;
		if (type == 0){
			int l, r;
			cin >> l >> r;
			cout << query(l+1, r+1) << '\n';
		}
		else{
			int x; char c;
			cin >> x >> c;
			update(x+1, c);
		}
	}
	return 0;
}