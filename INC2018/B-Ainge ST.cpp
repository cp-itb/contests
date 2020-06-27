/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Wiwit Rifa'i
 * Problem : B - Linked List
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, S = sqrt(N);

int l[N], r[N];

void slide(int v, int u) {
  if (r[u] == v)
    return;
  int x = l[v], y = r[v];
  int z = r[u];
  r[x] = y;
  l[y] = x;

  r[u] = v;
  l[v] = u;

  r[v] = z;
  l[z] = v;
}

int pos[N];
int a[N], b[N];
int upd[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", a+i, b+i);
  }
  for (int i = 0; i <= n; ++i) {
    r[i] = i+1;
    l[i+1] = i;
  }
  memset(upd, -1, sizeof upd);
  for (int i = 0; i < q; i += S) {
    int to = min(q, i+S);
    vector<int> node;
    for (int j = i; j < to; ++j) {
      node.push_back(a[j]);
      node.push_back(b[j]);
    }
    int now = r[0];
    pos[now] = 1;
    int cnt = 0;
    while (now <= n && cnt <= n) {
      pos[now] = ++cnt;
      now = r[now];
    }
    assert(cnt == n);
    for (int j = i; j < to; ++j) {
      int x = pos[a[j]], y = pos[b[j]];
      slide(a[j], b[j]);
      if (x < y) {
        printf("%d\n", y-x);
        for (int v : node) {
          if (upd[v] >= j) continue;
          upd[v] = j;
          if (pos[v] <= x || pos[v] > y) continue;
          --pos[v];
        }
      }
      else {
        printf("%d\n", y+1-x);
        for (int v : node) {
          if (upd[v] >= j) continue;
          upd[v] = j;
          if (pos[v] <= y || pos[v] >= x) continue;
          ++pos[v];
        }
      }
      pos[a[j]] = pos[b[j]]+1;
    }
  }
  int now = r[0];
  printf("%d", now);
  now = r[now];
  int cnt = 1;
  while (now <= n) {
    ++cnt;
    printf(" %d", now);
    now = r[now];
  }
  assert(cnt == n);
  printf("\n");
  return 0;
}
