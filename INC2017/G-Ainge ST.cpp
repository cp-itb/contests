#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
const int N = 305;

vector<pair<int, int>> p[MAX];
int a[N][N];

int bit[N][N];

void add(int p, int q, int v) {
  for (int i = p; i < N; i |= i + 1) {
    for (int j = q; j < N; j |= j + 1) {
      bit[i][j] += v;
    }
  }
}

int find(int p, int q) {
  int ret = 0;
  for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
    for (int j = q; j >= 0; j = (j & (j + 1)) - 1) {
      ret += bit[i][j];
    }
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      p[a[i][j]].emplace_back(i, j);
    }
  }  
  //puts("jancok");
  long long ans = 0;
  for (int v = MAX - 1; v >= 0; v--) {
    sort(p[v].begin(), p[v].end());
    for (auto it : p[v]) {
      int i = it.first;
      int j = it.second;
      if (find(i, j)) {
        cout << v << endl;
        return 0;
      }
      add(i, j, 1);
    }
    for (auto it : p[v]) {
      add(it.first, it.second, -1);
    }
  }
  puts("-1");
  return 0;
}
