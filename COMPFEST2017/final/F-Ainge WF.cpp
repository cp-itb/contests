/**
 * Contest : COMPFEST 2017 Final
 * Team    : Ainge WF
 * Author  : Luqman Arifin
 * Problem : F - Pasti Menang!
 */

#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 600;
const int N = 1e5 + 5;
const long long mod = 1e9 + 8;

long long a[MAGIC], temp[MAGIC][MAGIC], t[MAGIC][MAGIC], ret[MAGIC][MAGIC];
int nim_pol;

void one() {
  memset(temp, 0, sizeof(temp));
  for (int i = 0; i < nim_pol; i++) temp[i][i] = 1;
}

void temptemp() {
  memset(ret, 0, sizeof(ret));
  for (int i = 0; i < nim_pol; i++) {
    for (int j = 0; j < nim_pol; j++) {
      for (int k = 0; k < nim_pol; k++) {
        ret[i][j] += temp[i][k] * temp[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  for (int i = 0; i < nim_pol; i++) {
    for (int j = 0; j < nim_pol; j++) {
      temp[i][j] = ret[i][j];
    }
  }
}

void ttemp() {
  memset(ret, 0, sizeof(ret));
  for (int i = 0; i < nim_pol; i++) {
    for (int j = 0; j < nim_pol; j++) {
      for (int k = 0; k < nim_pol; k++) {
        ret[i][j] += t[i][k] * temp[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  for (int i = 0; i < nim_pol; i++) {
    for (int j = 0; j < nim_pol; j++) {
      temp[i][j] = ret[i][j];
    }
  }
}

void atemp() {
  memset(ret, 0, sizeof(ret));
  for (int j = 0; j < nim_pol; j++) {
    for (int k = 0; k < nim_pol; k++) {
      ret[0][j] += a[k] * temp[k][j];
      ret[0][j] %= mod;
    }
  }
  for (int j = 0; j < nim_pol; j++) {
    a[j] = ret[0][j];
  }
}

void power(int b) {
  if (b == 0) {
    one();
    return;
  }
  power(b / 2);
  temptemp();
  if (b & 1) ttemp();
}

vector<int> edge[N];
int nim[N], cnt[MAGIC];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    for (int i = 0; i < N; i++) edge[i].clear();
    memset(cnt, 0, sizeof(cnt));

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
    }
    nim_pol = 0;
    for (int i = 1; i <= n; i++) {
      set<int> s;
      for (auto it : edge[i]) {
        s.insert(nim[it]);
      }
      for (int v = 0; ; v++) {
        if (!s.count(v)) {
          nim[i] = v;
          nim_pol = max(nim_pol, nim[i]);
          break;
        }
      }
    }
    ++nim_pol;
    while (__builtin_popcount(nim_pol) != 1) nim_pol++;
    for (int i = 1; i <= n; i++) {
      cnt[nim[i]]++;
    }
    for (int i = 0; i < nim_pol; i++) {
      a[i] = cnt[i];
      //if (cnt[i]) printf("%d ada %d\n", i, cnt[i]);
    }
    for (int i = 0; i < nim_pol; i++) {
      for (int j = 0; j < nim_pol; j++) {
        int to = j;
        int from = i;
        t[i][j] = cnt[from ^ to];
      }
    }
    power(k - 1);
    atemp();
    long long ans = 0;
    for (int i = 1; i < nim_pol; i++) ans += a[i];
    cout << ans % mod << endl;
  }

  return 0;
}
