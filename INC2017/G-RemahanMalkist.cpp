/**
 * Contest : INC 2017
 * Team    : RemahanMalkist
 * Author  : Yonas Adiel
 * Problem : G - Largest Exotic Number
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[305][305];
int min_col_on_row[305][100005];
int min_row_on_col[305][100005];

int main() {
  memset(min_col_on_row, -1, sizeof min_col_on_row);
  memset(min_row_on_col, -1, sizeof min_row_on_col);

  scanf("%d",&n);
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      scanf("%d",&arr[i][j]);
      int val = arr[i][j];
      if (min_col_on_row[i][val] == -1) {
        min_col_on_row[i][val] = j;
      } else {
        min_col_on_row[i][val] = min(j, min_col_on_row[i][val]);
      }
      if (min_row_on_col[j][val] == -1) {
        min_row_on_col[j][val] = i;
      } else {
        min_row_on_col[j][val] = min(i, min_row_on_col[j][val]);
      }
    }
  }

  for (int val=0; val<100005; val++){
    for (int k=0; k<n; k++) {
      if (min_col_on_row[k][val] == -1 && k>0) {
        min_col_on_row[k][val] = min_col_on_row[k-1][val];
      } else if (k>0 && min_col_on_row[k-1][val] != -1) {
        min_col_on_row[k][val] = min(min_col_on_row[k][val], min_col_on_row[k-1][val]);
      }
    }
    for (int k=0; k<n; k++) {
      if (min_row_on_col[k][val] == -1 && k>0) {
        min_row_on_col[k][val] = min_row_on_col[k-1][val];
      } else if (k>0 && min_row_on_col[k-1][val] != -1) {
        min_row_on_col[k][val] = min(min_row_on_col[k][val], min_row_on_col[k-1][val]);
      }
    }
  }
/*
  for (int i=0; i<n; i++) {
    printf("%d ", min_row_on_col[i][0]);
  } printf("\n");
  for (int i=0; i<n; i++) {
    printf("%d ", min_col_on_row[i][0]);
  } printf("\n");
*/
  int maks = -1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      int val = arr[i][j];
      if (min_col_on_row[i][val] != -1 && min_row_on_col[j][val] != -1 &&
        min_col_on_row[i][val] <= j && min_row_on_col[j][val] <= i &&
        !(min_col_on_row[i][val] == j && min_row_on_col[j][val] == i)) {
        maks = max(val, maks);
      }
    }
  }

  printf("%d\n", maks);
}