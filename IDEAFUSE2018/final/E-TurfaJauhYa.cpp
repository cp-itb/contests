/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : TurfaJauhYa
 * Author  : Yonas Adiel
 * Problem : E - Dependency Hell
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1000000007;
ll fact[100005];
vector<int> adj[100005];
int node_dibawah[100005];

ll pangkat(ll base, ll top) {
  ll ans = 1;
  ll ttop = 1;
  for (int i=0; i<60; i++) {
    if (top & ttop) {
      ans *= base;
      ans %= mod;
    }
    ttop <<= 1;
    base *= base;
    base %= mod;
  }
  return ans;
}

void calc_fact() {
  fact[0] = 1;
  for (int i=1; i<100005; i++)
    fact[i] = ((ll) i * fact[i-1]) % mod;
}

int dfs(int node) {
  node_dibawah[node] = 1;
  for (int i=0; i<adj[node].size(); i++)
    node_dibawah[node] += dfs(adj[node][i]);
  return node_dibawah[node];
}

ll hitung(int node) {
  if (adj[node].size() == 0)
    return 1;
  int cnt_sum = 0;
  ll ans = 1;
  for (int i=0; i<adj[node].size(); i++) {
    cnt_sum += node_dibawah[adj[node][i]];
    ans *= hitung(adj[node][i]);
    ans %= mod;
    ans *= pangkat(fact[node_dibawah[adj[node][i]]], mod-2);
    ans %= mod;
  }
  ans *= fact[cnt_sum];
  ans %= mod;
  return ans;
}

void solve(int tc) {
  int n,a,b;
  scanf("%d", &n);
  for (int i=0; i<=n; i++) adj[i].clear();
  for (int i=0; i<n-1; i++) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
  }
  dfs(1);
  printf("Case #%d: %lld\n", tc, hitung(1));
}

int main() {
  calc_fact();
  int t;
  scanf("%d", &t);
  for (int i=1; i<=t; i++) solve(i);
}