#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define DEBUG if (debug)
using namespace std;

const bool debug = false;

int main() {
  int x=0, y=0;
  string s;
  cin >> s;
  for (int i=0; i<s.length(); i++) {
    if (s[i] == 'N') y++;
    if (s[i] == 'S') y--;
    if (s[i] == 'W') x--;
    if (s[i] == 'E') x++;
  }
  printf("%d\n", abs(x)+abs(y));
}