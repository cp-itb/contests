/**
 * Contest : COMPFEST 2020 Final
 * Team    : ItbNoFukkatsu
 * Author  : Farras Hibban
 * Problem : D
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e3;
const ll MOD = 1e9 + 7;
const int GRID = 1e3;
const int MX = 1e3 + 10;

ll fc[N + 10], ifc[N + 10];
ll pref[MX][MX], cpref[MX][MX];
ll ar[MX][MX];
ll danger[N + 10];
ll banyak[N + 10][N + 10];
pair<int, int> pos[N + 10];
int n, m, R;

ll fastexpo(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) { ret = (ret * a) % MOD; }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) {
  return fastexpo(a, MOD - 2);
}

void init_fac() {
  fc[0] = 1;
  for(int i = 1; i <= N; i++) {
    fc[i] = fc[i - 1] * i % MOD;
  }
  ifc[N] = inv(fc[N]);
  for(int i = N - 1; i >= 0; i--) {
    ifc[i] = ifc[i + 1] * (i + 1) % MOD;
  }
}

ll C(ll a, ll b) {
  if(a < b || a < 0 || b < 0) return 0;
  ll ret = fc[a];
  ret = ret * ifc[b] % MOD;
  ret = ret * ifc[a - b] % MOD;
  return ret;
}

ll crange(int ra, int ca, int rb, int cb){
  if(ra > rb || ca > cb) return 0;
  ra = max(ra, 1);
  ca = max(ca, 1);
  rb = min(rb, MX - 1);
  cb = min(cb, MX - 1);
  return cpref[rb][cb] - cpref[ra - 1][cb] - cpref[rb][ca - 1] + cpref[ra - 1][ca - 1];
}

void solve() {

  init_fac();

  cin >> n >> m >> R;
  for(int i = 1; i <= n; i++) {
    int r, c;
    ll b;
    cin >> r >> c >> b;
    ar[r][c] = b;
    pos[i] = make_pair(r, c);
    danger[i] = b;
  }
  for (int i=1;i<MX;i++){
    // ll tot = 0;
    ll ctot = 0;
    for (int j=1;j<MX;j++){
      // tot += ar[i][j];
      ctot += (ar[i][j] > 0);
      // pref[i][j] = pref[i - 1][j] + tot;
      cpref[i][j] = cpref[i - 1][j] + ctot;
    }
  }

  ll ans = 0;

  for(int i = 1; i <= n; i++) {
    int rmin, cmin, rmax, cmax;
    rmin = max(1, pos[i].first - R);
    rmax = min(GRID, pos[i].first + R);
    cmin = max(1, pos[i].second - R);
    cmax = min(GRID, pos[i].second + R);
    ll temp = crange(rmin, cmin, rmax, cmax);
    banyak[i][i] = temp;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      int rmin = 1, cmin = 1, rmax = GRID, cmax = GRID;
      rmin = max(rmin, pos[i].first - R);
      rmin = max(rmin, pos[j].first - R);
      rmax = min(rmax, pos[i].first + R);
      rmax = min(rmax, pos[j].first + R);
      cmin = max(cmin, pos[i].second - R);
      cmin = max(cmin, pos[j].second - R);
      cmax = min(cmax, pos[i].second + R);
      cmax = min(cmax, pos[j].second + R);

      ll temp = crange(rmin, cmin, rmax, cmax);
      banyak[i][j] = temp;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      if(i == j) {
        ll cur = danger[i] * danger[i] % MOD;
        ll jum = (C(n, m) - C(n - banyak[i][i], m)) % MOD;
        ans = (ans + cur * jum) % MOD;
      } else {
        ll cur = 2LL * danger[i] * danger[j] % MOD;
        ll a = banyak[i][i] - banyak[i][j];
        ll b = banyak[i][j];
        ll c = banyak[j][j] - banyak[i][j];
        ll jum = (C(n, m) - C(n - a - b, m) - C(n - b - c, m) + C(n - a - b - c, m)) % MOD;
        ans = (ans + cur * jum) % MOD;
      }
    }
  }
  if(ans < 0) ans += MOD;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}