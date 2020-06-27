/**
 * Contest : COMPFEST 2017 Final
 * Team    : RemahanMalkist
 * Author  : Yonas Adiel Wiguna
 * Problem : C - Kuota Maksimum
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <map>

#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll long long
#define MAXN 100005
#define INF 1e9
#define EPS 1e-9

using namespace std;

int n;
long long m;
pll arr[100005];

void percase() {
  scanf("%d%lld",&n,&m);
  for (int i=0; i<n; i++) { scanf("%lld",&arr[i].fi); }
  for (int i=0; i<n; i++) { scanf("%lld",&arr[i].se); }

  sort(arr, arr+n);

  for (int i=1; i<n; i++) {
    arr[i].se = max((arr[i].fi / arr[i-1].fi)*arr[i-1].se, arr[i].se);
  }

  long long ans = 0;
  int i = n-1;
  while (m && i>=0) {
    long long ambil = (long long) m / arr[i].fi;
    ans += (long long) ambil*arr[i].se;
    m -= ambil*arr[i].fi;
    i--;
  }

  printf("%lld\n",ans);
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    percase();
  }
}