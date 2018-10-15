/**
 * Contest : COMPFEST 2018 Final
 * Team    : Tukang Nasi Goreng
 * Author  : Luqman Arifin
 * Problem : C - Pak Chanek dan Stack    
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

deque<int> v[N];
int at[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) v[i].clear();
    for (int i = 0; i < N; i++) at[i] = i;

    int n, q;
    scanf("%d %d", &n, &q);
    while (q--) {
      int t, i, x, j;
      scanf("%d", &t);
      if (t == 1) {
        scanf("%d %d", &i, &x);
        v[at[i]].push_back(x);
      } else if (t == 2) {
        scanf("%d", &i);
        if (!v[at[i]].empty()) {
          v[at[i]].pop_back();
        }
      } else if (t == 3) {
        scanf("%d %d", &i, &j);
        if (v[at[i]].size() >= v[at[j]].size()) {
          for (auto it : v[at[j]]) {
            v[at[i]].push_back(it);
          }
          v[at[j]].clear();
        } else {
          for (int p = (int)v[at[i]].size() - 1; p >= 0; p--) {
            v[at[j]].push_front(v[at[i]][p]);
          }
          v[at[i]].clear();
          swap(at[i], at[j]);
        }
      } else {
        scanf("%d", &i);
        if (v[at[i]].empty()) {
          printf("-1\n");
        } else {
          printf("%d\n", v[at[i]].back());
        }
      }
    }
  }

  return 0; 
}
