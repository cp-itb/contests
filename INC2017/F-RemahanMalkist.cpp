/**
 * Contest : INC 2017
 * Team    : RemahanMalkist
 * Author  : Yonas Adiel
 * Problem : F - Maximum Subset
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
int arr[100005];

int check(int x) {
  // membuat subset yang minimum diff nya lebih dari sama dengan x
  int last = arr[0];
  int cnt = 1;
  for (int i=1; i<n; i++) {
    if (arr[i] - last >= x) {
      cnt++;
      last = arr[i];
    }
  }

  if (cnt >= k) return 1;
  return 0;
}

int main() {
  scanf("%d%d",&n,&k);
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  sort(arr, arr+n);

  int lo = 0;
  int hi = 2000000000;
  while (lo <= hi) {
    //printf("%d %d\n", lo, hi);
    int mi = (lo+hi)/2;
    int checkmi = check(mi);
    int checkmi1 = check(mi+1);

    if (checkmi == 1 && checkmi1 == 0) {
      lo = mi;
      hi = mi;
      break;
    } else if (checkmi == 1) {
      lo = mi+1;
    } else {
      hi = mi-1;
    }
  }

  printf("%d\n", lo);
}