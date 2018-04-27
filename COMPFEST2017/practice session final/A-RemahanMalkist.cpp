/**
 * Contest : COMPFEST 2017 Practice Session Final
 * Team    : RemahanMalkist
 * Author  : Restu Wahyu Kartiko
 * Problem : A - Restoran Chanek
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100005];

void percase() {
  int n,k,x;
  long long ans = 0;
  scanf("%d%d",&n,&k);
  for (int i=0; i<n; i++){
    for ( int j = 0 ; j<k;j++){
      scanf("%d",&x);
      ans += x;
    }
  }

  printf("%lld\n",ans);
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    percase();
  }
}