/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Luqman Arifin
 * Problem : H - Plate Parity
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> pos[20];

// <, =
long long dp[20][2];

long long get(vector<int> a) {
  for (int i = 0; i < a.size(); i++) pos[i].clear();
  for (int i = 0; i < a.size(); i++) {
    if (i + 1 < a.size()) {
      for (int j = 0; j < 10; j++) pos[i].push_back(j);
    } else {
      for (int j = 1; j < 10; j += 2) pos[i].push_back(j);
    }
  }
  memset(dp, 0, sizeof(dp));
  for (auto it : pos[0]) {
    if (it < a[0]) {
      dp[0][0]++;
    } else if (it == a[0]) {
      dp[0][1]++;
    }
  }
  for (int i = 0; i + 1 < a.size(); i++) {
    for (auto it : pos[i + 1]) {
      dp[i + 1][0] += dp[i][0];

      if (it < a[i + 1]) {
        dp[i + 1][0] += dp[i][1];
      } else if (it == a[i + 1]) {
        dp[i + 1][1] += dp[i][1];
      }
    }
  }
  return dp[a.size() - 1][0] + dp[a.size() - 1][1];
}

long long get_odd(long long n) {
  vector<int> a;
  while (n > 0) {
    a.push_back(n % 10);
    n /= 10;
  }
  reverse(a.begin(), a.end());
  long long ans = 0;
  for (int sz = 1; sz <= a.size(); sz++) {
    vector<int> now;
    for (int i = 0; i < sz; i++) {
      now.push_back(a[i]);
    }
    ans += get(now);
  }
  return ans;
}

int main() {
  long long a, b;
  cin >> a >> b;
  long long odd = get_odd(b) - get_odd(a - 1);
  long long even = (b - a + 1) - odd;
  printf("%lld %lld\n", odd, even);

  return 0;
}
