/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Alfonsus Raditya Arsadjaja
 * Problem : G - Discs
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 16;
const double PI = acos(-1);
const double EPS = 1e-9;
const double INF = 1e15;

double bitmask[N][(1 << N) + 5];
pii ar[N + 5];
double dist[N + 5][N + 5];

LL sqr(LL a){
  return a * a;
}

LL dist2(pii a, pii b){
  int distX = abs(a.fi - b.fi);
  int distY = abs(a.se - b.se);
  LL ans = sqr(distX) + sqr(distY);
  return ans;
}

bool vis[N][1 << N];

int n;  
double rek(int last, int bits){
  if(vis[last][bits]) return bitmask[last][bits];
  vis[last][bits] = 1;
  double &ret = bitmask[last][bits];
  bits ^= 1 << last;
  for(int i = 0;i < n; ++i){
    if(i != last && (bits & (1 << i))){
      int oldbits = bits;
      double jarak = rek(i, oldbits);
      double newrad = __builtin_popcount(oldbits) * dist[last][i];
      if(ret > jarak + newrad){
        ret = jarak + newrad;
      }
    }
  }
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i = 0;i < n; ++i){
    scanf("%d%d", &ar[i].fi, &ar[i].se);
  }
  for(int i = 0;i < n; ++i){
    for(int j = 0;j < n; ++j) dist[i][j] = sqrtl(dist2(ar[i], ar[j]));
  }
  for(int i = 0;i < n; ++i) for(int j = 0;j < (1 << n); ++j) bitmask[i][j] = INF;

  for(int i = 0;i < n; ++i) bitmask[i][(1 << i)] = 0, vis[i][1 << i] = 1;


  double mins = 1e18;
  for(int i = 0;i < n; ++i) {
    mins = min(mins, rek(i, (1 << n) - 1));
  }
  printf("%.10lf\n", mins);
  return 0;
}
