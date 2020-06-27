/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : I See the One
 * Author  : Tony
 * Problem : D - Memperpanjang Barisan 
 */
 
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int a[40002], m;
set<int> exist;

int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		exist.clear();
		scanf("%d", &n);
		m = n*n;
		for(i=0;i<m;++i){
			scanf("%d", a+i);
			if(a[i]>0)
				exist.insert(a[i]);
		}
		vector<int> lis, lds;
		for(i=0;i<m;++i){
			vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), a[i]);
			if(it == lis.end())
				lis.pb(a[i]);
			else
				*it = a[i];
			vector<int>::iterator dt = lower_bound(lds.begin(), lds.end(), a[i], greater<int>());
			if(dt == lds.end())
				lds.pb(a[i]);
			else
				*dt = a[i];
		}
		if(lis.size()>n || lds.size()>n){
			puts("0");
			continue;
		}
		vector<int> alis, alds;
		int c;
		for(i=lis.size()-1, c=n+1-lis.size();i>=0;--i, c++){
			int rem = c;
			for(j=max(lis[i]+1, 1);rem;++j, --rem){
				while(exist.count(j))
					j++;
				alis.pb(j);
			}
			if(!rem)
				break;
			alis.clear();
		}
		if(alis.size()==0){
			int rem = n+1;
			for(j=1;rem;++j, --rem){
				while(exist.count(j))
					j++;
				alis.pb(j);
			}
		}
		for(i=lds.size()-1, c=n+1-lds.size();i>=0;--i, c++){
			int rem = c;
			for(j=1;rem;++j, --rem){
				while(exist.count(j))
					j++;
				if(j > lds[i])
					break;
				alds.pb(j);
			}
			if(!rem)
				break;
			alds.clear();
		}
		if(alds.size()==0){
			int rem = n+1;
			for(j=1;rem;++j, --rem){
				while(exist.count(j))
					j++;
				alds.pb(j);
			}
		}
		reverse(alds.begin(), alds.end());
		if(alis.size() < alds.size()){
			printf("%d\n%d", (int)alis.size(), alis[0]);
			for(i=1;i<alis.size();++i)
				printf(" %d", alis[i]);
			puts("");
		}
		else if(alis.size()>alds.size()){
			printf("%d\n%d", (int)alds.size(), alds[0]);
			for(i=1;i<alds.size();++i)
				printf(" %d", alds[i]);
			puts("");
		}
		else{
			int cmp = 1;
			for(i=0;i<alis.size();++i){
				if(alis[i] != alds[i]){
					cmp = alis[i] < alds[i];
					break;
				}
			}
			if(cmp){
				printf("%d\n%d", (int)alis.size(), alis[0]);
				for(i=1;i<alis.size();++i)
					printf(" %d", alis[i]);
				puts("");
			}
			else{
				printf("%d\n%d", (int)alds.size(), alds[0]);
				for(i=1;i<alds.size();++i)
					printf(" %d", alds[i]);
				puts("");
			}
		}
	}
	return 0;
}