/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : B - Baskom Mania
 */


#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long m, k;
    int n;
    scanf("%I64d %d %I64d", &m, &n, &k);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    if (m == 0) {
      puts("0");
      continue;
    }
    long long lowest = 0;
    long long now = m;
    for (int i = 0; i < n; i++) {
      now += k - a[i];
      lowest = max(lowest, m - now);
    }
    if (m - lowest <= 0) {
      int ans = 0;
      now = m;
      for (int i = 0; i < n; i++) {
        if (now + k - a[i] >= 0) {
          ans++;
          now += k - a[i];
        } else {
          break;
        }
        if (now == 0) break;
      }
      printf("%d\n", ans);
      continue;
    }
    long long d = now - m;
    if (d >= 0) {
      puts("-1");
      continue;
    }
    long long lowest_per = m - lowest;
    long long full = lowest_per / abs(d) + (lowest_per % abs(d)? 1 : 0);
    //printf("full %I64d\n", full);
    long long ans = full * n;
    now = m + d * full;
    if (now > 0)
    for (int i = 0; i < n; i++) {
      if (now + k - a[i] >= 0) {
        ans++;
        now += k - a[i];
      } else {
        break;
      }
      if (now == 0) break;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
