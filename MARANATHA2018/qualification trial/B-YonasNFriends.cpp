/**
 * Contest : Maranatha 2018 Qualification Trial
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : B - Freckles
 */
#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int n;
pair<double,double> titik[105];
vector<pair<double, pair<int,int> > > edge;

double jarak(int i, int j) {
  return sqrt((titik[i].fi-titik[j].fi)*(titik[i].fi-titik[j].fi) + (titik[i].se-titik[j].se)*(titik[i].se-titik[j].se));
}

int prnt[105];

int ayah(int anak) {
  if (prnt[anak] == anak) return anak;
  else {
    int ayahbaru = ayah(prnt[anak]);
    prnt[anak] = ayahbaru;
    return ayahbaru;
  }
}

void mst() {
  double ret = 0;
  int hitung = 0;

  for (int i=0; i<105; i++) { prnt[i] = i; }

  sort(edge.begin(), edge.end());
  for (int i=0; i<edge.size() && hitung < n-1; i++) {
    pair<double, pair<int,int> > cur = edge[i];

    int ayah_i = ayah(cur.se.fi);
    int ayah_j = ayah(cur.se.se);
    if (ayah_i != ayah_j) {
      ret += cur.fi;
      prnt[ayah_i] = ayah_j;

      hitung++;
    }
  }
  printf("%.2lf\n", ret);
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    edge.clear();
    scanf("%d",&n);
    for (int i=0; i<n; i++) { scanf("%lf%lf",&titik[i].fi, &titik[i].se); }
    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        edge.push_back(mp(jarak(i,j),mp(i,j)));
      }
    }
    mst();
    if (t) printf("\n");
  }
}