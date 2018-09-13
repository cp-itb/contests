#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int n, k;

bool can(int d) {
  int p = 0, last = a[0];
  for (int i = 1; i < k; i++) {
    p = lower_bound(a, a + n, last + d) - a;
    if (p >= n) return 0;
    last = a[p];
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
