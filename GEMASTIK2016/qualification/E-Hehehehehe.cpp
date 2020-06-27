/**
 * Contest : Gemastik 2016 Qualification
 * Team    : Hehehehehe
 * Author  : Turfa Auliarachman
 * Problem : E - Libur Tahun Baru
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;

int memo[maxn+10][maxn+10][2];
int n,s,P;
int harga[maxn+10], indah[maxn+10];

int dp(int kota, int sisa, int dalam){
  if (kota==n) return 0;
  int &mem = memo[kota][sisa][dalam];
  if (mem!=-1) return mem;

  if (dalam==0){
    if (sisa >= P){
      mem = max(mem, dp(kota+1,sisa-P, 1));
    }
  }
  else{
    mem = max(mem, dp(kota+1,sisa, 1));
  }

  if (sisa >= harga[kota])  {
    int bawah = dp(kota+1,sisa-harga[kota],0);
    if (bawah>=0){
      mem = max(mem,bawah+indah[kota]);
    }
  }

  if (mem<0) return mem=INT_MIN;
  else return mem;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
      cin >> n >> s >> P;
      memset(memo,-1,sizeof memo);

      for(int i=1;i<n;i++){
        cin >> harga[i] >> indah[i];
      }
      int ans = dp(1,s,0);
      if (ans<0) cout << -1 << endl;
      else cout << ans << endl;
  }
}
