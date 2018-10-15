/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Luqman Arifin
 * Problem : E - Grid Game
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 35;

int a[N][N];
int n;

bool mark[N];
vector<int> adj[N];
int match[N], matched[N];

// The code below finds a augmenting path:
bool dfs(int v){// v is in X, it returns true if and only if there is an augmenting path starting from v
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : adj[v])
    if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return matched[v] = u, match[u] = v, true;
  return false;
}

bool can(int mini) {
  memset(matched, -1, sizeof(matched));
  memset(match, -1, sizeof(match));
  for (int i = 0; i < N; i++) adj[i].clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] >= mini) {
        adj[i].push_back(j);
      }
    }
  }

  while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 0;i < n;i ++) if(matched[i] == -1 && !mark[i])
      fnd |= dfs(i);
    if(!fnd)
      break;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) if (matched[i] != -1) ans++;
  return ans == n;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int l = 0, r = 1e6 + 6;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
