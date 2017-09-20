/**
 * Contest : UMN 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : F - Sensus Rekayasa
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const long long mod = 1e9 + 7;

// num - taruh
long long take[N][N];
int p[N], r[N], s[N];

int main(){
  for (int i = 1; i < N; i++) take[0][i] = 1;
  for (int i = 1; i < N; i++) {
    long long cur = 0;
    for (int j = 1; j < N; j++) {
      cur += take[i-1][j];
      cur %= mod;
      take[i][j] = cur;
      //if (i < 5 && j < 5) printf("%d %d: %lld\n", i, j, take[i][j]);
    }
  }
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
      scanf("%d %d", p + i, r + i);
      s[i] = r[i];
    }
    printf("Case #%d: ", tt);
    
    if (k == 0) {
      int slot = m;
      int num = n;
      int wajib = num;
      long long ans = 1;
      if (slot < wajib) {
        ans = 0;
      } else {
        ans *= take[slot-wajib][num];
        ans %= mod;
      }
      printf("%lld\n", ans);
      continue;
    }
    
    sort(s, s + k);
    bool done = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] != r[i]) {
        puts("0");
        done = 1;
        break;
      }
    }
    if (done) continue;
    long long ans = 1;
    
    // depan
    int slot = p[0] - 1;
    int num = r[0];
    int wajib = num - 1;
    if (slot < wajib) {
      ans *= 0;
    } else {
      //printf("awal %lld\n", take[slot-wajib][num]);
      ans *= take[slot-wajib][num];
      ans %= mod;
    }
    
    // di antara 2
    for (int i = 1; i < k; i++) {
      slot = p[i] - p[i-1] - 1;
      num = r[i] - r[i-1] + 1;
      wajib = (r[i-1] + 1 >= r[i]? 0 : r[i] - r[i-1] - 1);
      //printf("%d %d %d\n", slot, wajib, num);
      if (slot < wajib) {
        ans *= 0;
      } else {
        //printf("tengah %lld\n", take[slot-wajib][num]);
        ans *= take[slot-wajib][num];
        ans %= mod;
      }
    }
    
    // belakang
    slot = m - p[k-1];
    num = n - r[k-1] + 1;
    wajib = num - 1;
    if (slot < wajib) {
      ans *= 0;
    } else {
      //printf("blkg %lld\n", take[slot-wajib][num]);
      ans *= take[slot-wajib][num];
      ans %= mod;
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}
