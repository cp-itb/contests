#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long a[N][N];
char s[10];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      sum += a[i][j];
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int k, v;
    scanf("%s %d %d", s, &k, &v);
    if (s[0] == 'r') {
      sum += v * m;
      for (int j = 1; j <= m; j++) a[k][j] += v;
    } else {
      sum += v * n;
      for (int i = 1; i <= n; i++) a[i][k] += v;
    }
  }
  long long mini = 1e18, maxi = -1e18;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mini = min(mini, a[i][j]);
      maxi = max(maxi, a[i][j]);
    }
  }
  printf("%lld %lld %lld\n", sum, mini, maxi);
  return 0;
}
