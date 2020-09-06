/**
 * Contest	: COMPFEST 2020 Qualification
 * Team		: Yonko -1
 * Author	: Jauhar Wibisono
 * Problem	: H - Harta Karun Stomfec
 */

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

struct node{
	pair<long long,long long> sl, sr;
	long long ssl, ssr;
	int ans;
	bool space;
};

const long long mod1=1e9+7, mod2=998244353, g=101;
const int maxn=200002;

int n, m, k, q;
string s;
set<pair<long long,long long>>kamus;
node tree[maxn*4];
int mulai[maxn];

long long modpow(long long x, long long y, long long mod){
	long long ret=1;
	for (;y>0;y>>=1){
		if (y&1){
			ret*=x;
			ret%=mod;
		}
		x*=x;
		x%=mod;
	}
	return ret;
}

pair<long long, long long> concat(pair<long long,long long> a, pair<long long,long long> b, long long sa){
	pair<long long, long long>ret=a;
	ret.first+=(modpow(g,sa,mod1)*b.first)%mod1;
	ret.first%=mod1;
	ret.second+=(modpow(g,sa,mod2)*b.second)%mod2;
	ret.second%=mod2;
	return ret;
}

pair<long long, long long> hashh(string t){
	pair<long long, long long>ret={0,0};
	for (int i=0;i<(int)t.size();i++){
		ret.first+=(t[i]*modpow(g,i,mod1))%mod1;
		ret.first%=mod1;
		ret.second+=(t[i]*modpow(g,i,mod2))%mod2;
		ret.second%=mod2;
	}
	return ret;
}

node make(char c){
	node ret;
	if (c=='#'){
		ret.sl=ret.sr={'#','#'};
		ret.ans=0;
		ret.space=0;
		ret.ssl=ret.ssr=0;
	}
	else if (c==' '){
		ret.sl=ret.sr={0,0};
		ret.ans=0;
		ret.space=1;
		ret.ssl=ret.ssr=0;
	else{
		ret.sl=ret.sr={c,c};
		ret.ans=kamus.count(ret.sl);
		ret.space=0;
		ret.ssl=ret.ssr=1;
	}
	return ret;
}

node combine(node l, node r){
	if (l.sl==make_pair((long long)'#',(long long)'#') || l.sr==make_pair((long long)'#',(long long)'#')) return r;
	if (r.sl==make_pair((long long)'#',(long long)'#') || r.sr==make_pair((long long)'#',(long long)'#')) return l;
	node ret;
	if (l.sr==make_pair(0LL,0LL) || r.sl==make_pair(0LL,0LL)) ret.ans=l.ans+r.ans;
	else ret.ans=l.ans+r.ans-kamus.count(l.sr)-kamus.count(r.sl)+kamus.count(concat(l.sr,r.sl,l.ssr));
	if (!l.space) ret.sl=concat(l.sl,r.sl,l.ssl), ret.ssl=l.ssl+r.ssl;
	else ret.sl=l.sl, ret.ssl=l.ssl;
	if (!r.space) ret.sr=concat(l.sr,r.sr,l.ssr), ret.ssr=l.ssr+r.ssr;
	else ret.sr=r.sr, ret.ssr=r.ssr;
	ret.space=(l.space|r.space);
	return ret;
}

void build(int l, int r, int v){
	if (l==r) tree[v]=make(s[l]);
	else{
		int mid=(l+r)/2;
		build(l,mid,v*2);
		build(mid+1,r,v*2+1);
		tree[v]=combine(tree[v*2],tree[v*2+1]);
	}
}

void update(int l, int r, int v, int pos, char c){
	if (l==r) tree[v]=make(c);
	else{
		int mid=(l+r)/2;
		if (pos<=mid) update(l,mid,v*2,pos,c);
		else update(mid+1,r,v*2+1,pos,c);
		tree[v]=combine(tree[v*2],tree[v*2+1]);
	}
}

node query(int l, int r, int v, int lb, int rb){
	if (r<lb || l>rb) return make('#');
	if (l>=lb && r<=rb) return tree[v];
	int mid=(l+r)/2;
	return combine(query(l,mid,v*2,lb,rb),query(mid+1,r,v*2+1,lb,rb));
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> m;
	cin.ignore();
	getline(cin,s);
	n=s.length();
	cin >> k >> q;
	for (int i=0;i<k;i++){
		string t;
		cin >> t;
		kamus.insert(hashh(t));
	}
	build(0,n-1,1);
	int idx=0;
	for (int i=0;i<n;i++){
		if (i==0 || s[i-1]==' '){
			mulai[idx]=i;
			idx++;
		}
	}
	while (q--){
		bool type;
		cin >> type;
		if (!type){
			int i, j;
			char c;
			cin >> i >> j >> c;
			update(0,n-1,1,mulai[i-1]+j-1,c);
		}
		else{
			int l, r;
			cin >> l >> r;
			node ans=query(0,n-1,1,l-1,r-1);
			cout << ans.ans << "\n";
		}
	}
}