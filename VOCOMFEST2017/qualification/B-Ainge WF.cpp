/**
 * Contest : VOCOMFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Wiwit Rifa'i
 * Problem : B - Family Reunion
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int par[N], lv[N];
vector< int > child[N];
string name[N];
map< string, int > mp;

void dfs(int v) {
  for (int u : child[v]) {
    lv[u] = lv[v] + 1;
    dfs(u);
  }
}

int main() {
  int tt, n;
  scanf("%d %d", &n, &tt);
  int m = 0;
  memset(par, -1, sizeof par);
  for (int i = 1; i < n; i++) {
    string a, b;
    cin >> a >> b;
    int u, v;
    if (mp.count(a))
      u = mp[a];
    else {
      name[m] = a;
      mp[a] = u = m++;
    }
    if (mp.count(b))
      v = mp[b];
    else {
      name[m] = b;
      mp[b] = v = m++;
    }
    par[u] = v;
    child[v].push_back(u);
  }
  int blangkon = 0, root = 0;
  for (int i = 0; i < n; i++) if (name[i] =="Blangkon")
    blangkon = i;
  for (int i = 0; i < n; i++) if (par[i] == -1)
    root = i;
  lv[root] = 0;
  dfs(root);
  for (int tc = 1; tc <= tt; tc++) {
    if (tc != 1)
      puts("");
    string who;
    cin >> who;
    printf("Case #%d:\n", tc);
    stack< int > a, b;
    int u = blangkon, v = mp[who];
    while (u != v) {
      if (lv[u] > lv[v]) {
        a.push(u);
        u = par[u];
      }
      else {
        b.push(v);
        v = par[v];
      }
    }
    if (a.empty() || a.top() != u)
      a.push(u);
    if (b.empty() || b.top() != v)
      b.push(v);
    while (!a.empty()) {
      cout << name[a.top()];
      a.pop();
      if (!a.empty())
        cout << "->";
    }
    cout << endl;
    while (!b.empty()) {
      cout << name[b.top()];
      b.pop();
      if (!b.empty())
        cout << "->";
    }
    cout << endl;
  }
  return 0;
}
