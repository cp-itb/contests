/**
 * Contest : GEMASTIK 2016 Final
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : I
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int BIG = 1000;
const int mod = 48;

int a[N];
int pw[N];

int bit[N];

int ans[][4] = {{1, 0, 0, 1}, {0, 1, 1, 0}};

int find_bit(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret;
}

void add(int i, int v) {
  for (; i < N; i |= i + 1) {
    bit[i] += v;
  }
}

int cari(int n) {
  int cur = 0;
  memset(bit, 0, sizeof(bit));
  for (int i = 0; i < n; i++) add(i, 1);
  int ok = 1;
  for (int i = 0; i < n; i++) {
    int ada = find_bit(a[i] - 1);
    int k = n - 1 - i;
    if (ada % 2) {
      ok ^= 1;
    }
    add(a[i], -1);
  }
  return ok;
}


int main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = (pw[i - 1] * i) % mod;

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      a[i]--;
    }
    int seem = cari(n);
    //cout << seem << endl;
    puts(seem? "YA" : "TIDAK");
  }

  return 0;
}
