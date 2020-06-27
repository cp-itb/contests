/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Luqman Arifin
 * Problem : J - A Study on Groups
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int ada[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  long long mn = 0;
  for (int i = 0; i < min(n, m); i++) mn += a[i];
  for (int i = 0; i < m; i++) {
    ada[i] = n / m;
  }
  for (int i = 0; i < n % m; i++) ada[i]++;
  // for (int i = 0; i < n; i++) printf("%d ", ada[i]); printf("\n");
  long long mx = 0;
  for (int i = 1; i < m; i++) ada[i] += ada[i - 1];
  mx += a[0];
  for (int i = 1; i < m; i++) {
    mx += a[ada[i-1]];
    // printf("%d: %d\n", i, ada[i-1]);
  }
  printf("%lld %lld\n", mn, mx);
  return 0;
}
