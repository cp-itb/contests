/**
 * Contest : COMPFEST 2017 Practice Session Final
 * Team    : RemahanMalkist
 * Author  : Yonas Adiel Wiguna
 * Problem : C - Iri Itu Tidak Baik
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100005];

void percase() {
  int n,k;
  scanf("%d%d",&n,&k);
  k = n-k;
  for (int i=0; i<n; i++) { scanf("%d",&arr[i]); }

  sort(arr, arr + n);
  int mini = arr[k-1] - arr[0];

  for (int i=0; i+k-1<n; i++) {
    mini = min(mini, arr[i+k-1] - arr[i]);
  }

  printf("%d\n",mini);
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    percase();
  }
}