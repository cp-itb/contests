/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : TurfaJauhYa
 * Author  : Yonas Adiel
 * Problem : K - Echo Signal
 */
#include <bits/stdc++.h>
using namespace std;

int t, n, cnt[2000];
long long a[2000],b[2000];
long long r;

long long jarak(int i, int j) {
  return (a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j])*(b[i] - b[j]);
}

int main() {
  scanf("%d", &t);
  for (int tc=1; tc<=t; tc++) {
    scanf("%d%lld",&n,&r); r*=r;
    for (int i=0; i<n; i++)
      scanf("%lld%lld", a+i, b+i);

    int maks = 0;
    for (int i=0; i<n; i++) {
      int cnt = 0;
      for (int j=0; j<n; j++)
        if (i!=j && jarak(i,j) <= r)
          cnt++;
      maks = max(maks, cnt);
    }
    printf("Case #%d: %d\n", tc, maks);
  }
}