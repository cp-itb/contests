/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : Arurange Code Party
 * Author  : Dewita Sonya Tarabunga
 * Problem : J - Raon and Voting
 */
#include <bits/stdc++.h>

using namespace std;

int n,q,t,a,b;
int p[100010], s[100010];
int nw;
set<int> cn;

int root(int x) {
  if (p[x] == x) return x;
  else return (p[x] = root(p[x]));
}

int uni(int x, int y) {
  x = root(x); y = root(y);
  int r;
  if (s[x]>s[y] || (s[x]==s[y] && x<y)) {
    p[y] = x;
    s[x] += s[y];
    r = x;
  } else {
    p[x] = y;
    s[y] += s[x];
    r = y;
  }
  if (s[r]>nw) {
    nw = s[r];
    cn.clear();
    cn.insert(r);
  } else if (s[r]==nw) cn.insert(r);
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i=1;i<=n;++i) {
    p[i] = i;
    s[i] = 1;
    cn.insert(i);
  }
  nw = 1;
  while (q--) {
    scanf("%d", &t);
    if (t==1) {
      scanf("%d %d", &a, &b);
      uni(a, b);
    } else if (t==2) {
      scanf("%d", &a);
      b = root(a);
      s[a] = s[b];
      p[b] = p[a] = a;
      if (s[a] == nw) {
        cn.erase(b);
        cn.insert(a);
      }
    } else {
      a = (*cn.begin());
      printf("%d %d\n", a, s[a]);
    }
  }
}