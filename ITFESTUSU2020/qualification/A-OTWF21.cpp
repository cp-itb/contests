/**
 * Contest : ITFESTUSU 2020
 * Team    : OTWF21
 * Author  : Muhammad Hasan, Muhammad Kamal Shafi
 * Problem : A - Buku Rahasia
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int tc, n;
int a[N];
int bit[N];

void add(int x, int val) {
  for ( ; x > 0; x -= x & -x) {
    bit[x] += val;
  }
}

int get(int x) {
  int ret = 0;
  for ( ; x < N; x += x & -x) {
    ret += bit[x];
  }
  return ret;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    memset(bit, 0, sizeof(bit));
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int temp = get(a[i] + 1);
      res += temp;
      add(a[i], 1);
    }
    cout << (res % 2 == 0 ? "YA" : "TIDAK") << '\n';
  }

  return 0;
}