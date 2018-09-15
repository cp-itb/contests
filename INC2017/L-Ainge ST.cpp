/**
 * Contest : INC 2017
 * Team    : Ainge ST
 * Author  : Wiwit Rifa'i
 * Problem : L - Pretty Table
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

struct polynom {
  vector<int> x;
  polynom() {
    x.clear();
  }
  polynom(vector<int> vx) : x(vx) {
  }
  int & operator[](int id) {
    return x[id];
  }
  polynom operator*(polynom vp) {
    polynom res;
    res.x.assign((int)vp.x.size() + (int)x.size() - 1, 0);
    for (int i = 0; i < x.size(); i++) {
      for (int j = 0; j < vp.x.size(); j++) {
        res.x[i+j] += 1LL * x[i] * vp.x[j] % mod;
        if (res.x[i+j] >= mod)
          res.x[i+j] -= mod;
      }
    }
    return res;
  }
  polynom operator*(long long v) {
    polynom res;
    res.x.assign((int)x.size(), 0);
    for (int i = 0; i < x.size(); i++) {
      res[i] = v * x[i] % mod;
    }
    return res;
  }
  polynom operator-(long long z) {
    polynom cur = *this;
    if (cur.x.size() == 0)
      cur.x.push_back(0);
    cur.x[0] = (cur.x[0] + mod - z) % mod;
    return cur;
  }
  polynom operator+(polynom vp) {
    polynom res;
    res.x.assign(max(vp.x.size(), x.size()), 0);
    for (int i = 0; i < res.x.size(); i++) {
      if (i < x.size())
        res.x[i] = (res.x[i] + x[i]) % mod;
      if (i < vp.x.size())
        res.x[i] = (res.x[i] + vp.x[i]) % mod;
    }
    return res;
  }
  long long get(long long v) {
    long long ret = 0, now = 1;
    for (int i = 0; i < x.size(); i++) {
      ret = (ret + now * x[i]) % mod;
      now = (now * v) % mod;
    }
    return ret;
  }
};

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

polynom sum[10];

long long calc(polynom p, long long l, long long r) {
  polynom rumus;
  for (int i = 0; i < p.x.size(); i++) {
    rumus = rumus + (sum[i] * p.x[i]);
  }
  long long ret = rumus.get(r) - rumus.get(l-1);
  ret %= mod;
  if (ret < 0)
    ret += mod;
  return ret;
}

polynom arith(polynom a, polynom n) {
  long long inv2 = (mod + 1) / 2;
  return n * (a * 2 + (n - 1)) * inv2;
}

long long kiriatas(long long r, long long c) {
  int m = min(r, c);
  if (m <= 0)
    return 0;
  long long ret = 0;
  // atas
  polynom rumus = arith(polynom({1, mod-2,4}), polynom({0, 1})); 
  ret += calc(rumus, 1, m);
  // kiri
  rumus = arith(polynom({2, mod-3,4}), polynom({-1, 1})); 
  ret += calc(rumus, 1, m);
  if (r > c) {
    rumus = arith(polynom({1-c, mod-1,4}), polynom({c, 0})); 
    ret += calc(rumus, m+1, r);
  }
  else if (c > r) {
    rumus = arith(polynom({2, mod-3,4}), polynom({r, 0})); 
    ret += calc(rumus, m+1, c);
  }
  // cerr << "kiri atas " << r << " " << c << " " << ret << endl;
  return ret;
}
long long kananatas(long long r, long long c) {
  int m = min(r, c);
  if (m <= 0)
    return 0;
  long long ret = 0;
  // atas
  polynom rumus = arith(polynom({2, mod-1,4}), polynom({0, 1})); 
  ret += calc(rumus, 1, m);
  // kanan
  rumus = arith(polynom({2, 0, 4}), polynom({-1, 1})); 
  ret += calc(rumus, 1, m);
  if (r > c) {
    rumus = arith(polynom({2, mod-1,4}), polynom({c, 0})); 
    ret += calc(rumus, m+1, r);
  }
  else if (c > r) {
    rumus = arith(polynom({1-r, 1,4}), polynom({r, 0})); 
    ret += calc(rumus, m+1, c);
  }
  // cerr << "kanan atas " << r << " " << c << " " << ret << endl;
  return ret;
}
long long kiribawah(long long r, long long c) {
  int m = min(r, c);
  if (m <= 0)
    return 0;
  long long ret = 0;
  // bawah
  polynom rumus = arith(polynom({2, 3, 4}), polynom({0, 1})); 
  ret += calc(rumus, 1, m);
  // kiri
  rumus = arith(polynom({2, mod-4,4}), polynom({-1, 1})); 
  ret += calc(rumus, 1, m);
  if (r > c) {
    rumus = arith(polynom({2, 3, 4}), polynom({c, 0})); 
    ret += calc(rumus, m+1, r);
  }
  else if (c > r) {
    rumus = arith(polynom({1-r, mod-3,4}), polynom({r, 0})); 
    ret += calc(rumus, m+1, c);
  }
  // cerr << "kiri bawah " << r << " " << c << " " << ret << endl;
  return ret;
}
long long kananbawah(long long r, long long c) {
  int m = min(r, c);
  if (m <= 0)
    return 0;
  long long ret = 0;
  // bawah
  polynom rumus = arith(polynom({1, 2, 4}), polynom({0, 1})); 
  ret += calc(rumus, 1, m);
  // kanan
  rumus = arith(polynom({2, 1, 4}), polynom({-1, 1})); 
  ret += calc(rumus, 1, m);
  if (r > c) {
    rumus = arith(polynom({1-c, 3,4}), polynom({c, 0})); 
    ret += calc(rumus, m+1, r);
  }
  else if (c > r) {
    rumus = arith(polynom({2, 1, 4}), polynom({r, 0})); 
    ret += calc(rumus, m+1, c);
  }
  // cerr << "kanan bawah " << r << " " << c << " " << ret << endl;
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    sum[0].x = {0, 1};
    sum[1].x = {0, (mod + 1) / 2, (mod + 1) / 2};
    sum[2].x = {0, powmod(6, mod-2), (mod + 1) / 2, powmod(3, mod-2)};
    sum[3].x = {0, 0, powmod(4, mod-2), (mod+1)/2, powmod(4, mod-2)};
    sum[4].x = {0, (mod-powmod(30, mod-2)) % mod, powmod(3, mod-2), (mod + 1)/2, powmod(5, mod-2)};
    sum[5].x = {0, 0, (mod - powmod(12, mod-2)) % mod, 0, (5 * powmod(12, mod-2)) % mod, (mod + 1) / 2, powmod(6, mod-2)};
    long long n, a, b, c, d;
    scanf("%lld %lld %lld %lld %lld", &n, &a, &c, &b, &d);
    long long mid = n/2 + 1;
    long long ans = 0;
    if (a <= mid) {
      if (b <= mid)
        ans += kiriatas(mid-a, mid-b);
      else
        ans -= kananatas(mid-a, b-mid-1);

      if (d <= mid)
        ans -= kiriatas(mid-a, mid-d-1);
      else
        ans += kananatas(mid-a, d-mid);
    }
    else {
      if (b <= mid)
        ans -= kiribawah(a-mid-1, mid-b);
      else
        ans += kananbawah(a-mid-1, b-mid-1);

      if (d <= mid)
        ans += kiribawah(a-mid-1, mid-d-1);
      else
        ans -= kananbawah(a-mid-1, d-mid);
    }
    if (c <= mid) {
      if (b <= mid)
        ans -= kiriatas(mid-c-1, mid-b);
      else
        ans += kananatas(mid-c-1, b-mid-1);

      if (d <= mid)
        ans += kiriatas(mid-c-1, mid-d-1);
      else
        ans -= kananatas(mid-c-1, d-mid);
    }
    else {
      if (b <= mid)
        ans += kiribawah(c-mid, mid-b);
      else
        ans -= kananbawah(c-mid, b-mid-1);

      if (d <= mid)
        ans -= kiribawah(c-mid, mid-d-1);
      else
        ans += kananbawah(c-mid, d-mid);
    } 
    if (a <= mid && mid <= c && b <= mid && mid <= d) {
      ans++;
    }
    if (a <= mid && mid <= c) {
      if (b < mid && mid < d) {
        ans += calc(polynom({1, -3, 4}), 1, mid-b);
        ans += calc(polynom({1, 1, 4}), 1, d-mid);
      }
      else if (b < mid) {
        ans += calc(polynom({1, -3, 4}), max(1LL, mid-d), mid-b);
      }
      else if (mid < d) {
        ans += calc(polynom({1, 1, 4}), max(1LL, b-mid), d-mid);
      }
    }
    if (b <= mid && mid <= d) {
      if (a < mid && mid < c) {
        ans += calc(polynom({1, -1, 4}), 1, mid-a);
        ans += calc(polynom({1, 3, 4}), 1, c-mid);
      }
      else if (a < mid) {
        ans += calc(polynom({1, -1, 4}), max(1LL, mid-c), mid-a);
      }
      else if (mid < c) {
        ans += calc(polynom({1, 3, 4}), max(1LL, a-mid), c-mid);
      }
    }
    ans %= mod;
    if (ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}
