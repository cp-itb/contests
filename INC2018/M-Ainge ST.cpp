/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Wiwit Rifa'i
 * Problem : M - Moving Around
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
const long long inf = 1e18;

int l[N], r[N];
int n, s;

vector<int> ans;
vector<int> tmp;
bool used[N];

void add(int x) {
  assert(!used[x]);
  used[x] = 1;
  tmp.push_back(x);
}

void init() {
  tmp.clear();
  memset(used, 0, sizeof used);
}

// s = 0
// s >>>>> (n-1)
long long solve0() {
  if (s != 0)
    return inf;
  init();
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    add(i);
    ret += r[i];
  }
  assert(tmp.size() == n);
  return ret;
}
// s = 0
// 0 >>>>> rig
//   1 <<< rig
//   1 >>>>>>>>> (n-1)
long long solve1() {
  if (s != 0)
    return inf;
  int rig = -1;
  for (int i = 1; i < n; ++i) {
    if (l[i] <= r[i])
      rig = i;
  }
  if (rig <= 1)
    return inf;
  init();
  long long ret = 0;
  add(0);
  ret += r[0];
  for (int i = 2; i < rig; ++i) {
    if (l[i] >= r[i]) {
      add(i);
      ret += r[i];
    }
  }
  add(rig);
  ret += l[rig];
  for (int i = rig-1; i > 1; --i) {
    if (used[i]) continue;
    if (l[i] <= r[i]) {
      add(i);
      ret += l[i];
    }
  }
  for (int i = 1; i < n; ++i) {
    if (used[i]) continue;
    ret += r[i];
    add(i);
  }
  assert(tmp.size() == n);
  return ret;
}

// arah kanan paling kiri = 0
// arah kiri paling kanan = s
// 0 <<< s
// 0 >>>>>>>> (n-1)
long long solve2() {
  if (s == 0)
    return inf;
  init();
  long long ret = 0;
  add(s);
  ret += l[s];
  for (int i = s-1; i > 0; --i) {
    if (l[i] <= r[i]) {
      ret += l[i];
      add(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      ret += r[i];
      add(i);
    }
  }
  assert(tmp.size() == n);
  return ret;
}

// arah kanan paling kiri = 0
// arah kiri paling kanan > s
// s arah ke kanan
//     s >>> rig
// 0 <<<<<<< rig
// 0 >>>>>>>>>>>>>> (n-1)
long long solve3() {
  if (s <= 0 || s >= n-1)
    return inf;
  init();
  int rig = s+1;
  for (int i = s+2; i < n; ++i) {
    if (l[i] <= r[i] || (l[i] - r[i] < l[rig] - r[rig]))
      rig = i;
  }
  long long ret = 0;
  add(s);
  ret += r[s];
  for (int i = s+1; i < rig; ++i) {
    if (r[i] <= l[i]) {
      add(i);
      ret += r[i];
    }
  }
  add(rig);
  ret += l[rig];
  for (int i = rig-1; i > 0; --i) {
    if (used[i]) continue;
    if (l[i] <= r[i]) {
      ret += l[i];
      add(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    ret += r[i];
    add(i);
  }
  assert(tmp.size() == n);
  return ret;
}

// arah kanan paling kiri = 0
// arah kiri paling kanan > s
// s arah ke kiri
// 0 <<< s
// 0 >>>>>>>>>> rig
//      lef <<< rig
//      lef >>>>>>>>>>> (n-1)
// 0 < lef < s or lef == s+1

long long solve4() {
  if (s <= 0 || s >= n-1 || n < 4)
    return inf;
  int lef = -1, rig = -1;
  for (int i = s+1; i < n; ++i) {
    if (l[i] <= r[i]) {
      rig = i;
    }
  }
  if (rig == -1)
    return inf;
  for (int i = 1; i < s; ++i) {
    if (r[i] <= l[i]) {
      lef = i;
      break;
    }
  }
  if (lef == -1) {
    for (int i = 1; i <= s+1 && i < rig; ++i) {
      if (i == s) continue;
      if (lef == -1 || r[i] - l[i] < r[lef] - l[lef])
        lef = i;
    }
    if (lef == -1)
      return inf;
  }
  init();
  long long ret = 0;
  add(s);
  ret += l[s];
  for (int i = s-1; i > 0; --i) {
    if (i == lef) continue;
    if (l[i] <= r[i]) {
      add(i);
      ret += l[i];
    }
  }
  add(0);
  ret += r[0];
  for (int i = 1; i < rig; ++i) {
    if (i == lef) continue;
    if (used[i]) continue;
    if (r[i] <= l[i] || i < lef) {
      add(i);
      ret += r[i];
    }
  }
  add(rig);
  ret += l[rig];
  for (int i = rig-1; i > lef; --i) {
    if (used[i]) continue;
    if (l[i] <= r[i]) {
      add(i);
      ret += l[i];
    }
  }
  add(lef);
  ret += r[lef];
  for (int i = lef+1; i < n; ++i) {
    if (used[i]) continue;
    add(i);
    ret += r[i];
  }
  assert(tmp.size() == n);
  return ret;
}

vector<int> revs(vector<int> & v) {
  vector<int> ret(n);
  for (int i = 0; i < n; ++i)
    ret[i] = n-1-v[i];
  return ret;
}

int main() {
  scanf("%d %d", &n, &s);
  --s;
  for (int i = 0; i < n; ++i)
    scanf("%d %d", l+i, r+i);
  long long best = inf, cur;
  cur = solve0();
  if (cur < best) {
    best = cur;
    ans = tmp;
  }
  cur = solve1();
  if (cur < best) {
    best = cur;
    ans = tmp;
  }
  cur = solve2();
  if (cur < best) {
    best = cur;
    ans = tmp;
  }
  cur = solve3();
  if (cur < best) {
    best = cur;
    ans = tmp;
  }
  cur = solve4();
  if (cur < best) {
    best = cur;
    ans = tmp;
  }
  for (int i = 0, j = n-1; i < j; ++i, --j) {
    swap(l[i], l[j]);
    swap(r[i], r[j]);
  }
  for (int i = 0; i < n; ++i)
    swap(l[i], r[i]);
  s = n-1-s;
  cur = solve0();
  if (cur < best) {
    best = cur;
    ans = revs(tmp);
  }
  cur = solve1();
  if (cur < best) {
    best = cur;
    ans = revs(tmp);
  }
  cur = solve2();
  if (cur < best) {
    best = cur;
    ans = revs(tmp);
  }
  cur = solve3();
  if (cur < best) {
    best = cur;
    ans = revs(tmp);
  }
  cur = solve4();
  if (cur < best) {
    best = cur;
    ans = revs(tmp);
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i]+1, i == n-1 ? '\n' : ' ');
  return  0;
}
