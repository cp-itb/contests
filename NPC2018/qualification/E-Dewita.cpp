/**
 * Contest : NPC 2018 Qualification
 * Team    : Dewita Sonya
 * Author  : Dewita Sonya
 * Problem : E - Bermain Tanah
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tree[400010], tree2[400010], lazy[400010], a[100005], n, m=0;
ll INF = 1e18;

void updateRangeUtil(ll si, ll ss, ll se, ll us, ll ue, ll diff)
{
	if (lazy[si])
	{
		tree[si] += lazy[si];
		tree2[si] += lazy[si];
		if (ss != se)
		{
			lazy[si*2+1] += lazy[si];
			lazy[si*2+2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss>se || ss>ue || se<us) return;
	if (ss>=us && se<=ue)
	{
		tree[si] += diff;
		tree2[si] += diff;
		if (ss != se)
		{
			lazy[si*2+1] += diff;
			lazy[si*2+2] += diff;
		}
		return;
	}
	ll mid = (ss+se)/2;
	updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
	updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
	tree[si] = min(tree[si*2+1], tree[si*2+2]);
	tree2[si] = max(tree2[si*2+1], tree2[si*2+2]);
}

void updateRange(ll us, ll ue, ll diff)
{
	updateRangeUtil(0, 0, n-1, us, ue, diff);
}

ll getMinUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
	if (lazy[si])
	{
		tree[si] += lazy[si];
		tree2[si] += lazy[si];
		if (ss != se)
		{
			lazy[si*2+1] += lazy[si];
			lazy[si*2+2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss>se || ss>qe || se<qs) return INF;
	if (ss>=qs && se<=qe) return tree[si];
	ll mid = (ss+se)/2;
	return min(getMinUtil(ss, mid, qs, qe, 2*si+1), getMinUtil(mid+1, se, qs, qe, 2*si+2));
}

ll getMin(ll qs, ll qe)
{
	return getMinUtil(0, n-1, qs, qe, 0);
}

ll getMaxUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
	if (lazy[si])
	{
		tree[si] += lazy[si];
		tree2[si] += lazy[si];
		if (ss != se)
		{
			lazy[si*2+1] += lazy[si];
			lazy[si*2+2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss>se || ss>qe || se<qs) return -INF;
	if (ss>=qs && se<=qe) return tree2[si];
	ll mid = (ss+se)/2;
	return max(getMaxUtil(ss, mid, qs, qe, 2*si+1), getMaxUtil(mid+1, se, qs, qe, 2*si+2));
}

ll getMax(ll qs, ll qe)
{
	return getMaxUtil(0, n-1, qs, qe, 0);
}

void constructUtil(ll ss, ll se, ll si)
{
	if (ss>se) return;
	if (ss==se)
	{
		tree2[si] = tree[si] = a[ss];	
		return;
	}
	ll mid = (ss+se)/2;
	constructUtil(ss, mid, si*2+1);
	constructUtil(mid+1, se, si*2+2);
	tree[si] = min(tree[si*2+1], tree[si*2+2]);
	tree2[si] = max(tree2[si*2+1], tree2[si*2+2]);
	m = (si>m)?m:si;
}

void construct()
{
	constructUtil(0, n-1, 0);
	for (ll i=0;i<m;++i) lazy[i] = 0;
}

int main()
{
	scanf("%lld", &n);
	for (ll i=0;i<n;++i) {
		scanf("%lld", a+i);
	}
	construct();
	ll q;
	scanf("%lld", &q);
	ll tt, ll, rr, vv;
	while (q--) {
		scanf("%lld", &tt);
		if (tt==1) {
			scanf("%lld %lld %lld", &ll, &rr, &vv);
			--ll; --rr;
			updateRange(ll, rr, vv);
		} else {
			scanf("%lld %lld", &ll, &rr);
			--ll; --rr;
			printf("%lld\n", getMax(ll, rr) - getMin(ll, rr));
		}
	}
	return 0;
}