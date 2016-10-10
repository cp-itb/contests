/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : I
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 105, inf = 1005;

char s[N][N];
int dist[2][N][N], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int vis[N][N], deg[N][N];
pair<int , int > pre[2][N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%s", s[i]);
    int xa, xb, ya, yb;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (s[i][j] == 'A')
          xa = i, ya = j;
        else if (s[i][j] == 'B')
          xb = i, yb = j;
    }
    for (int i = 0; i < 2; i++) {
      memset(vis, 0, sizeof vis);
      queue< pair<int, int> > q;
      q.push(make_pair(xa, ya));
      dist[i][xa][ya] = 0;
      pre[i][xa][ya] = {xa, ya};
      vis[xa][ya] = true;
      while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int j = 0; j < 4; j++) {
          int xx = x + dx[j], yy = y + dy[j];
          if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && s[xx][yy] != 'x') {
            q.push(make_pair(xx, yy));
            dist[i][xx][yy] = dist[i][x][y] + 1;
            vis[xx][yy] = true;
            pre[i][xx][yy] = {x, y};
          }
        }
      }
      swap(xa, xb);
      swap(ya, yb);
    }
    if (dist[0][xb][yb] & 1)
      printf("%d\n", dist[0][xb][yb]);
    else {
      int ans = inf;
      int ans2 = inf;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (s[i][j] != 'x' && ((dist[0][i][j] == dist[1][i][j]) || (dist[0][i][j] == dist[1][i][j] + 1)) && pre[0][i][j] != pre[1][i][j]) {
            int tot = dist[0][i][j] + dist[1][i][j];
            if (ans > tot) {
              ans2 = ans;
              ans = tot;
            }
            else 
              ans2 = min(ans2, tot);
          }
      if(ans2 < inf)
        printf("%d\n", ans2);
      else {
        ans = inf;
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++) if (s[i][j] != 'x') {
            deg[i][j] = 0;
            for (int k = 0; k < 4; k++) {
              int x = i + dx[k], y = j + dy[k];
              if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != 'x')
                deg[i][j]++;
            }
          }
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++) if (s[i][j] != 'x') {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
              int x = i + dx[k], y = j + dy[k];
              if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != 'x' && deg[x][y] > 1)
                cnt++;
            }
            if (cnt > 2) {
              if (dist[0][i][j] == dist[1][i][j]) {
                auto pre1 = pre[0][i][j], pre2 = pre[1][i][j];
                if (pre1.first != pre2.first && pre1.second != pre2.second && s[pre1.first][pre2.second] != 'x' && s[pre2.first][pre1.second] != 'x')
                  ans = min(ans, 2 * dist[0][i][j] + 2);
                else
                  ans = min(ans, 2 * dist[0][i][j] + 4);
              }
              else 
                ans = min(ans, 2 * max(dist[0][i][j], dist[1][i][j]) + 2);
            }
          }
        // assert(ans < inf);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}