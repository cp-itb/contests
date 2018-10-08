/**
 * Contest : GEMASTIK 2018 Qualification Trial
 * Team    : Hikikomori
 * Author  : Luqman Arifin
 * Problem : B
 */

#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> s;

int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    p -= x;
    q -= y;
    int f = __gcd(abs(p), abs(q));
    p /= f;
    q /= f;
    s.insert(make_pair(p, q));
  }
  cout << s.size() << endl;
  return 0;
}
