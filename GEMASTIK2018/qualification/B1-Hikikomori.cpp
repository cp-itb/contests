/**
 * Contest : GEMASTIK 2018 Qualification
 * Team    : Hikikomori
 * Author  : Wiwit Rifa'i
 * Problem : B1
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

int bit[N];

int get(int x) {
  int ret = 0;
  for (++x; x; x -= x&-x)
    ret += bit[x];
  return ret;
}

void upd(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}

int a[N];
int cnt[N];

long long calc(int n) {
  memset(bit, 0, sizeof bit);
  for (int i = 0; i < n; ++i) {
    cnt[i] = get(a[i]);
    upd(a[i], +1);
  }
  memset(bit, 0, sizeof bit);
  long long ans = 0;
  for (int i = n-1; i >= 0; --i) {
    int now = get(a[i]);
    ans += 1LL * cnt[i] * now;
    upd(a[i], +1);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    long long ans = calc(n);
    for (int i = 0; i < n; ++i)
      a[i] = 10001 - a[i];
    ans += calc(n);
    printf("%lld\n", ans);
  }
  return 0;
}
