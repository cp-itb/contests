/**
 * Contest : COMPFEST 2016 Final
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : G
 */

#include <bits/stdc++.h>

using namespace std;

const int BIG = 1e7 + 6;
const int N = 1e5 + 5;
const long long mod = 2e9 + 89;

vector<int> p;
bool is[BIG];

int h[N], cnt[N];
vector<int> edge[N];
long long val[N];

int dfs(int now) {
  if (edge[now].empty()) {
    cnt[now] = 1;
    val[now] = 1;
    return h[now] = 0;
  }
  h[now] = 0;
  cnt[now] = 1;
  for (auto it : edge[now]) {
    h[now] = max(h[now], dfs(it) + 1);
  }
  val[now] = 0;
  for (auto it : edge[now]) {
    cnt[now] += cnt[it];
    val[now] += val[it] * p[h[now]];
    val[now] %= mod;
  }
  return h[now];
}

int main() {
  for (int i = 2; i < BIG; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (long long j = 1LL * i * i; j < BIG; j += i) {
        is[j] = 1;
      }
    }
  }
  vector<int> tmp;
  for (auto it : p) {
    if (it > N) {
      tmp.push_back(it);
    }
  }
  srand(time(NULL));
  int shuffle = rand() % 10;
  while (shuffle--) random_shuffle(tmp.begin(), tmp.end());
  p = tmp;

  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) edge[i].clear();

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
    }
    dfs(1);
    map<pair<int, int>, int> MP;
    for (int i = 1; i <= n; i++) {
      //printf("hash %d %lld\n", cnt[i], val[i]);
      MP[{cnt[i], val[i]}]++;
    }
    pair<int, int> ans = {-1, -1};
    MP[ans] = -1;
    for (auto it : MP) {
      if (it.second < 2) continue;
      if (it.first.first > ans.first) {
        ans = it.first;
      } else if (it.first.first == ans.first && it.second > MP[ans]) {
        ans = it.first;
      }
    }
    printf("%d %d\n", ans.first, MP[ans]);
  }
  return 0;
}