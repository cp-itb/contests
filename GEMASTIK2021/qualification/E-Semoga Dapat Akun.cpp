 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Kinantan Arya Bagaspati
  * Problem : E - Bitcoin
  */

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, ans = 0;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=1; i<n; i++){
        ans += max(0ll, a[i]-a[i-1]);
    }
    cout << ans << endl;
}