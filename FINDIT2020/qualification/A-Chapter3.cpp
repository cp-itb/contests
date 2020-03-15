/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : A - Battle Royale
 */
#include <iostream>
#include <vector>

using namespace std;

int n, q;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  int root = 1;
  vector<int> par(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      root = i;
    } else {
      par[i] = x;
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    vector<bool> vis(n + 1);
    while (1) {
      vis[u] = 1;
      if (u == root) break;
      u = par[u];
    }
    while (1) {
      if (vis[v]) break;
      vis[v] = 1;
      v = par[v];
    }
    cout << (v == root ? "Tidak" : "Ya") << '\n';
  }

  return 0;
}