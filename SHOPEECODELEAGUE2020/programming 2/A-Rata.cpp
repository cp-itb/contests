/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Rata
* Author  : Wiwit Rifai
* Problem : A - Highest Mountain
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int t;
int ar[N + 5];
int n;

int main(){
  scanf("%d", &t);
  for(int tc = 1; tc <= t; ++tc){
    scanf("%d", &n);
    for(int i = 0;i < n; ++i) scanf("%d", &ar[i]);

    int idx = -1;

    for(int i = 0;i < n; ++i){
      if(ar[i] == 1){
        if(idx == -1) idx = i;
        for(int j = i - 1;j >= 0; --j){
          if(ar[j] - ar[j + 1] == 1){
            if(ar[j] > ar[idx]) idx = j;
            else if(ar[j] == ar[idx]) {
              idx = min(idx, j);
            }
          }
          else{
            break;
          }
        }
        for(int j = i + 1; j < n; ++j){
          if(ar[j] - ar[j - 1] == 1){
            if(ar[j] > ar[idx]) idx = j;
            else if(ar[j] == ar[idx]) {
              idx = min(idx, j);
            }
          }
          else{
            break;
          }
        }
      }
    }

    printf("Case #%d: %d %d\n", tc, idx == -1 ? idx : ar[idx], idx);
  }
  return 0;
}