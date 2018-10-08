/**
 * Contest : GEMASTIK 2018 Qualification
 * Team    : Hikikomori
 * Author  : Wiwit Rifa'i
 * Problem : A2
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a+1, a+n);
  long long now = a[0];
  bool ok = 1;
  for (int i = 1; i < n; ++i) {
    if (now < a[i]) {
      ok = false;
      break;
    }
    now = abs(now - a[i]);
  }
  if (ok) {
    puts("menang");
    for (int i = 0; i < n; ++i)
      printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
  }
  else
    puts("kalah");
  return 0;
}
