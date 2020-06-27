/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : TurfaJauhYa
 * Author  : Yonas Adiel
 * Problem : F - Ocarth
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll todec(ll oct) {
  ll dec = 0;
  ll base = 1;
  while (base <= oct) base *= 10;
  while (base > 0) {
    dec *= 8;
    dec += (oct/base);
    oct %= base;
    base /= 10;
  }
  return dec;
}

ll tooct(ll dec) {
  ll oct = 0;
  ll base = 1;
  while (base <= dec) base *= 8;
  while (base > 0) {
    oct *= 10;
    oct += (dec/base);
    dec %= base;
    base /= 8;
  } return oct;
}

string tostring(ll num) {
  string res = "";
  while (num > 0) {
    res = (char) (num %10+'0') + res;
    num /= 10;
  }
  return res;
}

pair<ll, ll> kth(ll a) {
  ll panjang = 7;
  ll old = 0;
  ll base = 1;
  ll i = 1;
  ll ans = 0;
  while (panjang < a) {
    base *= 8;
    i++;
    old = panjang;
    panjang += i*base*7;
    ans += (base/8)*7;
  }
  return make_pair(tooct(ans+(a-old+i-1)/i),1+((a-old-1)%i));
}

void solve(int tc) {
  ll o,d;
  cin >> o;
  d = todec(o);

  pair<ll, ll> ans = kth(d);
  string anss = tostring(ans.first);
  cout << "Case #" << tooct(tc) << ": ";
  for (int i=0; i<anss.length(); i++) {
    if (i == ans.second-1) cout << "(";
    cout << anss[i];
    if (i == ans.second-1) cout << ")";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  t = todec(t);
  for (int i=1; i<=t; i++) solve(i);
}