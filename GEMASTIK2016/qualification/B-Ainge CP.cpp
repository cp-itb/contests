/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : B - Kode Keras
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int POL = 1e5 + 5;

int ans[N];
int from[N], to[N];
vector<int> in[POL], out[POL];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) ans[i] = 2;
    for (int i = 0; i < POL; i++) {
      in[i].clear();
      out[i].clear();
    }
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int a, b, c, d, e, f;
      scanf("%d:%d:%d %d:%d:%d", &a, &b, &c, &d, &e, &f);
      from[i] = a * 60 * 60 + b * 60 + c;
      to[i] = d * 60 * 60 + e * 60 + f;
      in[from[i]].push_back(i);
      out[to[i]].push_back(i);
    }
    set<int> now;
    multiset<int> until;
    until.insert(-1);
    for (int i = 0; i < POL; i++) {
      for (auto it : in[i]) {
        now.insert(it);
        until.insert(to[it]);
      }
      for (auto it : out[i]) {
        now.erase(it);
      }
      
      if (now.size() == 1) {
        for (auto it : now) {
          ans[it] = 1;
        }
      }
      for (auto it : in[i]) {
        until.erase(until.find(to[it]));
        int best = *(until.rbegin());
        if (to[it] <= best) {
          ans[it] = -1;
        }
        until.insert(to[it]);
      }
    }
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  }

  return 0;
}