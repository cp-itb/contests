/**
 * Contest : GEMASTIK 2018 Qualification
 * Team    : Hikikomori
 * Author  : Wiwit Rifa'i
 * Problem : E1
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, t, d, l;
  scanf("%d %d %d %d", &n, &m, &t, &d);
  scanf("%d", &l);
  assert(l == 0);
  int cnt = (t * t + 1) / 2;
  int cn = ((n + d) / (d + t));
  int cm = ((m + d) / (d + t));
  long long ans = 1LL * cn * cm * cnt;
  int sisan = max(n - cn * (d + t), 0);
  int sisam = max(m - cm * (d + t), 0);
  if (sisan > 0) {
    int genap = sisan/2, ganjil = sisan - genap;
    int vganjil = (t+1)/2 * cm + (sisam+1)/2, vgenap = t/2 * cm + sisam / 2;
    ans += 1LL * ganjil * vganjil + genap * vgenap;
  }
  if (sisam > 0) {
    int genap = sisam/2, ganjil = sisam - genap;
    int vganjil = (t+1)/2 * cn, vgenap = t/2 * cn;
    ans += 1LL * ganjil * vganjil + genap * vgenap;
  }
  printf("%lld\n", ans);
  return 0;
}
