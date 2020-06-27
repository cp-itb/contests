/**
 * Contest : UMN 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : C - Ledakan Terbesar
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N][N];
bool vis[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int dfs(int i, int j) {
  if (!valid(i, j) || s[i][j] != '*' || vis[i][j]) return 0;
  vis[i][j] = 1;
  int ret = 1;
  for (int k = 0; k < 4; k++) {
    int ti = i + dx[k];
    int tj = j + dy[k];
    ret += dfs(ti, tj);
  }
  return ret;
}

int main(){
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(vis, 0, sizeof(vis));
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] == 0 && s[i][j] == '*') {
          ans = max(ans, dfs(i, j));
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
