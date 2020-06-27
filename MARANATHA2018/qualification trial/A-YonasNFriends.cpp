/**
 * Contest : Maranatha 2018 Qualification Trial
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : A - Pancake Fever
 */
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    int n;
    int arr[105];
    int brr[105];

    scanf("%d",&n);
    for (int i=0; i<n; i++) {
      scanf("%d",&arr[i]);
      brr[i] = arr[i];
    }

    sort(brr,brr+n);

    for (int j=n-1; j>=0; j--) {
      if (arr[j] != brr[j]) {

        //search for correct level
        int ind = -1;
        for (int k = j-1; k >= 0; k--) {
          if (arr[k] == brr[j]) {
            ind = k;
          }
        }

        // balik sekali
        if (ind != 0) {
          printf("%d ", n-ind);
          reverse(arr, arr+ind+1);
        }
        reverse(arr, arr+j+1);
        printf("%d ", n-j);
      }
    }

    printf("0\n");
  }
}