/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Arurange Love Sadikin Party
* Author  : Dewita Sonya Tarabunga
* Problem : E - Wifi Network
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, ll> pdl;
 
#define fi first
#define se second
 
bool comp(pdl a, pdl b) {
	if (a.fi == b.fi) return a.se <= b.se;
    return a.fi <= b.fi;
};
 
struct cmp {
  bool operator() (const pdl& x, const pdl& y) const {return comp(x, y);}
};
 
typedef tree<
pdl,
null_type,
cmp,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
double dist(ll xa, ll ya, ll xb, ll yb) {
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
 
int main() {
	ll n,x[100010],y[100010],INF=1e9;
	scanf("%lld", &n);
	for (ll i=0;i<n;++i) {
		scanf("%lld %lld", x+i, y+i);
	}
	ll xa,ya,xb,yb;
	scanf("%lld %lld %lld %lld", &xa, &ya, &xb, &yb);
	pair<double, double> dd[100010];
	for (ll i=0;i<n;++i) {
		dd[i] = {dist(xa, ya, x[i], y[i]), dist(xb, yb, x[i], y[i])};
	}
	sort(dd, dd+n);
	ll q,ans[100010];
	pair<pll, ll> qq[100010];
	scanf("%lld", &q);
	for (ll i=0;i<q;++i) {
		ll ra, rb;
		scanf("%lld %lld", &ra, &rb);
		qq[i] = {{ra, rb}, i};
	}
	sort(qq, qq+q);
	ordered_set st;
	ll ind = 0;
	for (ll i=0;i<q;++i) {
		ll ra, rb;
		ra = qq[i].fi.fi;
		rb = qq[i].fi.se;
		while (ind < n && dd[ind].fi <= ra) {
			st.insert({dd[ind].se, ind});
			++ind;
		}
		ans[qq[i].se] = (ll) st.order_of_key({rb, INF});
	}
	for (ll i=0;i<n;++i) {
		dd[i].fi *= -1;
		dd[i].se *= -1;
	}
	sort(dd, dd+n);
	for (ll i=0;i<n;++i) {
		dd[i].fi *= -1;
		dd[i].se *= -1;
	}
	for (ll i=0;i<q;++i) {
		qq[i].fi.fi *= -1;
		qq[i].fi.se *= -1;
	}
	sort(qq, qq+q);
	for (ll i=0;i<q;++i) {
		qq[i].fi.fi *= -1;
		qq[i].fi.se *= -1;
	}
	st.clear();
	ind = 0;
	for (ll i=0;i<q;++i) {
		ll ra, rb;
		ra = qq[i].fi.fi;
		rb = qq[i].fi.se;
		while (ind < n && dd[ind].fi > ra) {
			st.insert({dd[ind].se, ind});
			++ind;
		}
		ll k = (ll) st.order_of_key({rb, INF});
		ans[qq[i].se] += (ll) st.size() - k;
	}
	for (ll i=0;i<q;++i) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}