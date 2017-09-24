/**
 * Contest : GEMASTIK 2016 Final
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : F
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 32000;

int a[N];
bool is[N];
vector<int> p;

int ada[N];

vector<long long> A({2, 3, 5, 7, 11, 13, 17, 19, 23});

long long fastexp(long long a, long long b, long long n) {
  if (b == 0) {

  }
}

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (long long j = i; j < N; j += i) {
        is[j] = 1;
        ada[j]++;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int nim = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      int cur = 0;
      for (auto it : p) {
        while (a[i] % it == 0) {
          a[i] /= it;
          cur++;
        }
      }
      if (a[i] > 1) cur++;
      nim ^= cur;
    }
    puts(nim? "TIDAK" : "YA");
  }
  return 0;
}
