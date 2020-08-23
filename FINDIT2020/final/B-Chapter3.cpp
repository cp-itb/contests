/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Farras Mohammad Hibban Faddila
 * Problem : B - Bitwise
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e4;

int n, p, q, z;
int ar[N + 5];

void solve() {
  cin >> n >> p >> q >> z;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    bool ok = true;
    for(int j = i; j <= n; j += i) {
      if (!((p & ar[j]) < z)) ok = false;
      if (!((q ^ ar[j]) > z)) ok = false;
    }
    if(ok){
      ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}