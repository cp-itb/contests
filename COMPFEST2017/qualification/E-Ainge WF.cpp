/**
 * Contest : COMPFEST 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : E
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ori[N], n, mini;
bool done[N];

bool solve(int add) {
  for (int i = 1; i <= n; i++) a[i] = ori[i];
  memset(done, 0, sizeof(done));
  
  int need = 0;
  int lim = mini + add;
  //cout << add << endl;
  for (int i = 1; i <= n; i++) {
    if (a[i] < lim) {
      need += lim - a[i];
    }
    if (a[i] > lim) {
      //printf("%d need %d\n", i, need);
      if (need > 0) {
        //puts("ke kiri");
        int p = -1;
        for (int j = i - 1; j >= 1; j--) {
          if (done[j]) break;
          if (a[j] < lim) {
            p = j;
            break;
          } else if (a[j] > lim) {
            break;
          }
        }
        //printf("id %d: p %d\n", i, p);
        if (p != -1) {
          for (int j = p; j < i; j++) {
            done[j] = 1;
          }
          a[p]++;
          a[i]--;
          need--;
        } 
      } else {
        //puts("ke kanan");
        int p = -1;
        for (int j = i + 1; j <= n; j++) {
          if (done[j]) break;
          if (a[j] < lim) {
            p = j;
            break;
          } else if (a[j] > lim) {
            break;
          }
        }
        //printf("id %d: p %d\n", i, p);
        if (p != -1) {
          for (int j = i; j < p; j++) {
            done[j] = 1;
          }
          a[p]++;
          a[i]--;
        }
      }
    }
  }
  bool all = 1;
  for (int i = 1; i <= n; i++) {
    //printf("%d ", a[i]);
    if (a[i] < lim) {
      all = 0;
      break;
    }
  }
  //printf("\n");
  return all;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    mini = 2e9;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      mini = min(mini, a[i]);
      ori[i] = a[i];
    }
    if (solve(2)) {
      printf("%d\n", mini + 2);
    } else if (solve(1)) {
      printf("%d\n", mini + 1);
    } else {
      printf("%d\n", mini);
    }
  }

  return 0;
}
