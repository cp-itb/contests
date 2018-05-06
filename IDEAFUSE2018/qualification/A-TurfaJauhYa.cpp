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

int n,x;
vector<int> v;

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int sum = 0;
  for (int i=1; i<n; i++) {
    sum += v[i];
  }
  printf("%d\n", sum);
}