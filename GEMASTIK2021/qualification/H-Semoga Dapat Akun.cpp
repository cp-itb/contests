 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Kinantan Arya Bagaspati
  * Problem : H - Soal Gemastik
  */

#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long inv2 = 500000004;
long long inv3 = 333333336;
long long inv4 = 250000002;
long long inv6 = 166666668;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, a, b, c, d, ans = 1;
    cin >> n;
    cin >> a >> b;
    cin >> c >> d;
    for(int i=1; i<=n; i++){
        ans = ans*i%mod;
    }
    if(a == c || b == d){
        ans = ans * inv3 % mod;
    }else if(a == d || b == c){
        ans = ans * inv6 % mod;
    }else{
        ans = ans * inv4 % mod;
    }
    cout << ans << endl;
}

