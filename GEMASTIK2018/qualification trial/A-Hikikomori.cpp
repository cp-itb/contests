/**
 * Contest : GEMASTIK 2018 Qualification Trial
 * Team    : Hikikomori
 * Author  : Luqman Arifin
 * Problem : A
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

string a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    reverse(a[i].begin(), a[i].end());
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    reverse(a[i].begin(), a[i].end());
    printf("%s\n", a[i].c_str());
  }

  return 0;
}
