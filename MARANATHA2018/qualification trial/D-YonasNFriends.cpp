/**
 * Contest : Maranatha 2018 Qualification Trial
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : D - Periodic Strings
 */
#include <cstdio>
#include <iostream>
using namespace std;

string s;

int main() {
  int t;
  scanf("%d\n",&t);

  while (t--) {
    scanf("\n");
    cin>>s;
    int n = s.length();
    for (int i=1; i<=n; i++) {
      if (n%i == 0) {
        bool cek = true;
        for (int j=1; j<n/i; j++) {
          for (int k=j*i; k<(j+1)*i; k++) {
            if (s[k] != s[k-j*i]) {
              cek = false;
            }
          }
        }
        if (cek) {
          printf("%d\n",i);
          if (t) { printf("\n"); }
          break;
        }
      }
    }
  }

}