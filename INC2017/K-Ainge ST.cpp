#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int N = 100, C = 100000;
int n;
int ar[N + 5];
bool dp[N + 5][C + 5];
int main(){
  scanf("%d", &n);
  int tot = 0;
  for(int i = 0;i < n; ++i){
    scanf("%d", &ar[i]);
    tot += ar[i];
  }
  if(tot % 3){
    puts("NO");
    return 0;
  }
  else{
    memset(dp, 0,sizeof dp);
    dp[0][0] = 1;
    
    for(int i = 0;i < n - 1; ++i){
      int mins[3] = {-1, -1, -1}, maks[3] = {-1, -1, -1};
      for(int j = ar[i];j >= 0; --j){
        if(dp[i][j]){
          int selisih = ar[i] - j;
          int maks_now = selisih << 1;
          int mins_now = maks_now - (selisih >> 1) * 3;
          int kasus = maks_now % 3;
          if(mins_now > maks[kasus]){
            for(int k = mins_now; k <= min(maks_now, ar[i + 1]); k += 3) dp[i + 1][k] = 1;
          }
          else{
            for(int k = maks[kasus]; k <= min(maks_now, ar[i + 1]); k += 3) dp[i + 1][k] = 1;
          }
          mins[kasus] = mins_now;
          maks[kasus] = maks_now;
        }
      } 
    }

    puts(dp[n - 1][ar[n - 1]] ? "YES" : "NO");
  }
  return 0;
}