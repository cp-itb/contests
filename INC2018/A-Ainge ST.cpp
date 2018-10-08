/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Alfonsus Raditya Arsadjaja
 * Problem : A - Tour de BINUS
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 1e5;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INFL = 1e15;

int ar[N + 5];
int prefA[N + 5];
int prefB[N + 5];
int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &ar[i]);
    prefA[i] = prefA[i - 1] + ar[i];
    prefB[i] = prefB[i - 1] + (ar[i] == 0);
  }
  int x;
  char arr[N];
  int ans1 = -1, ans2 = -1;
  scanf("%d%s", &x, arr);
  if(arr[0] == 'l'){
    ans1 = prefA[x];
  }
  else{
    ans1 = prefA[n] - prefA[x - 1];
  }

  scanf("%d%s", &x, arr);
  if(arr[0] == 'l'){
    ans2 = prefB[x];
  }
  else{
    ans2 = prefB[n] - prefB[x - 1];
  }
  printf("%d %d\n", ans1, ans2);
  

  return 0;
}
