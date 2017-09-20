/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : J
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int MAX = 2000;

int a[N], b[N], n;
long long k;
map<long long, int> id;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    id.clear();
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d %d", a + i, b + i);
    sort(a, a + n);
    sort(b, b + n);
    long long res = 0;
    long long suma = 0, sumb = 0;
    
    int cnt = 0;
    long long tmp = 0;
    for (int i = 0; i < n; i++) {
      cnt++;
      tmp += a[i];
      res += 1LL * cnt * a[i] - tmp;
      suma += a[i];
    }
    
    cnt = 0;
    tmp = 0;
    for (int i = 0; i < n; i++) {
      cnt++;
      tmp += b[i];
      res += 1LL * cnt * b[i] - tmp;
      sumb += b[i];
    }
    
    k -= res;
    
    int j = 0;
    cnt = 0;
    tmp = 0;
    for (int i = 0; i <= MAX; i++) {
      while (j < n && a[j] == i) {
        cnt++;
        tmp += a[j];
        j++;
      }
      long long add = 0;
      add += 1LL * cnt * i - tmp;
      add += (suma - tmp) - 1LL * (n - cnt) * i;
      id[add] = i;
    }
    
    bool done = 0;
    
    j = 0;
    cnt = 0;
    tmp = 0;
    for (int i = 0; i <= MAX; i++) {
      while (j < n && b[j] == i) {
        cnt++;
        tmp += b[j];
        j++;
      }
      long long add = 0;
      add += 1LL * cnt * i - tmp;
      add += (sumb - tmp) - 1LL * (n - cnt) * i;
      if (id.count(k - add)) {
        printf("%d %d\n", id[k - add], i);
        done = 1;
        break;
      }
    }
    if (!done) {
      puts("-1 -1");
    }
  }

  return 0;
}
