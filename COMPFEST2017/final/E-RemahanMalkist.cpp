/**
 * Contest : COMPFEST 2017 Final
 * Team    : RemahanMalkist
 * Author  : Yonas Adiel Wiguna
 * Problem : E - Menginap
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

void percase() {
  int n,a,b;
  long long dur = 0;
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    scanf("%d%d",&a,&b);
    dur += (b-a);
  }

  printf("%.1lf\n", (double) dur*1.0/2);
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    percase();
  }
}