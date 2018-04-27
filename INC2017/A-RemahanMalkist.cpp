/**
 * Contest : INC 2017
 * Team    : RemahanMalkist
 * Author  : Yonas Adiel
 * Problem : A - Simple Operations in Matrix
 */

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n,m,q;
int arr[105][105];
string str;
int k,val;

int main() {
  scanf("%d%d",&n,&m);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%d",&arr[i][j]);
    }
  }
  scanf("%d",&q);
  for (int i=0; i<q; i++) {
    cin >> str;
    scanf("%d%d", &k, &val);
    k--;
    if (str == "row") {
      for (int j=0; j<m; j++) {
        arr[k][j] += val;
      }
    } else {
      for (int j=0; j<n; j++) {
        arr[j][k] += val;
      }
    }
  }

  int sum = 0, minm = arr[0][0], makm = arr[0][0];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      sum += arr[i][j];
      minm = min(minm, arr[i][j]);
      makm = max(makm, arr[i][j]);
    }
  }

  printf("%d %d %d\n", sum, minm, makm);
}