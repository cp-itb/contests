/**
 * Contest : INC 2016
 * Team    : GituKanYa
 * Author  : Turfa Auliarachman
 * Problem : G - Beautiful Triple
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;

  cin >> t;

  for(int tc=1;tc<=t;tc++){
    cout << "Case #" << tc << ": ";
    int n;
    const int maxn = 100000;
    const long long mod = 1000000007;

    long long banyak[maxn+10];
    long long ans = 0;
    long long jumlah[maxn+10];

    memset(banyak,0,sizeof banyak);
    memset(jumlah,0,sizeof jumlah);

    cin >> n;
    for(int i=0;i<n;i++){
      int x;
      cin >> x;

      ans += banyak[x]*i-jumlah[x] - banyak[x];

      banyak[x]++;
      jumlah[x]+=i;

      if (ans>=mod) ans%=mod;
    }

    cout << ans << endl;
  }
}
