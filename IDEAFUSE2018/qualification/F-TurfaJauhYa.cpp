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
  int n,s;
  scanf("%d%d", &n,&s);
  if ((n&1) == (s&1)
       && abs(s) <= n) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}