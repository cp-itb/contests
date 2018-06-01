/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : TurfaJauhYa
 * Author  : Yonas Adiel
 * Problem : J - Raon and Voting
 */
#include <bits/stdc++.h>
using namespace std;

int n,q;
int a,b,c;
int parent[100005];
int size[100005];

int find_parent(int a) {
  if (parent[a] == a) return a;
  int p = find_parent(parent[a]);
  parent[a] = p;
  return p;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i=1; i<=n; i++) {
    parent[i] = i;
    size[i] = 1;
  }

  set<int> max_indx; max_indx.insert(1);
  int max_size = 1;
  while (q--) {
    int qs;
    scanf("%d", &qs);
    if (qs == 1) {
      scanf("%d%d", &a,&b);
      int pa = find_parent(a);
      int pb = find_parent(b);
      int pc;
      if (size[pa] == size[pb]) {
        if (pa < pb) pc = pa;
        else         pc = pb;
      } else if (size[pa] < size[pb]) { pc = pb; }
      else { pc = pa; }

      parent[pa] = parent[pb] = pc;
      size[pc] = size[pa] + size[pb];
      
      if (size[pc] > max_size) {
        max_size = size[pc];
        max_indx.clear();
        max_indx.insert(pc);
      } else if (size[pc] == max_size) {
        max_indx.insert(pc);
      }
    } else if (qs == 2) {
      scanf("%d", &c);
      int pc = find_parent(c);
      parent[pc] = c;
      size[c] = size[pc];
      parent[c] = c;

      if (max_indx.count(pc) > 0) {
        max_indx.erase(pc);
        max_indx.insert(c);
      }
    } else {
      printf("%d %d\n", *max_indx.begin(), max_size);
    }
  }
}