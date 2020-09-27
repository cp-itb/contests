/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Farras Hibban
 * Problem : F
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

int ar[N + 5], pre[N + 5];
int n;

int ask(int a, int b) {
  int ret;
  cout << "? " << a << " " << b << endl;
  cin >> ret;
  return ret;
}

void ans() {
  cout << "!";
  for(int i = 1; i <= n; i++) {
    cout << " " << ar[i];
  }
  cout << endl;
  exit(0);
}

void solve() {
  cin >> n;
  for(int i = 2; i <= n; i++) {
    pre[i] = ask(1, i);
  }
  int lol = ask(2, 3);
  for(int i = 3; i <= n; i++) {
    ar[i] = pre[i] - pre[i - 1];
  }
  ar[2] = lol - ar[3];
  ar[1] = pre[2] - ar[2];
  ans();
}

int main() {

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}