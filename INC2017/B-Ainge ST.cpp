#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], gain[N];
bool done[N];

// dapet eksklusif
int got(int d) {
  return d / 2;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  set<int> un;
  for (int i = 1; i <= m; i++) {
    scanf("%d", a + i);
    un.insert(a[i]);
  }
  m = un.size();
  for (int i = 1; i <= m; i++) {
    a[i] = *(un.begin());
    un.erase(un.begin());
  }
  if (k >= m) {
    cout << n << endl;
    return 0;
  }
  set<pair<int, int> > s;
  gain[1] = a[1] + got(a[2] - a[1]);
  gain[m] = n - a[m] + 1 + got(a[m] - a[m-1]);
  s.insert({gain[1], 1});
  s.insert({gain[m], m});
  for (int i = 2; i < m; i++) {
    gain[i] = got(a[i] - a[i - 1]) + got(a[i + 1] - a[i]) + 1;
    s.insert({gain[i], i});
  }
  long long ans = 0;
  while (k--) {
    auto it = s.end();
    it--;
    ans += it->first;
    int id = it->second;
    s.erase(it);
    done[id] = 1;
    if (id + 1 <= m) {
      if ((a[id + 1] - a[id]) % 2 == 0 && !done[id + 1]) {
        s.erase({gain[id+1], id+1});
        gain[id+1]--;
        s.insert({gain[id+1], id+1});
      }
    }
    if (id - 1 >= 1) {
      if ((a[id] - a[id - 1]) % 2 == 0 && !done[id - 1]) {
        s.erase({gain[id-1], id-1});
        gain[id-1]--;
        s.insert({gain[id-1], id-1});
      }
    }
  }
  cout << ans << endl;
  return 0;
}
