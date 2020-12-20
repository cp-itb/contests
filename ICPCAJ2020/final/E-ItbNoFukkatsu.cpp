/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : E
 */
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int N = 1e5 + 10;
 
int n;
bool gud[N];
int last = 0;
 
int main(){
    cin >> n;
    for (int i=2;i<=n;i++){
        cin >> gud[i];
        if (gud[i]){
            last = i;
        }
    }
    int cnt1 = 0;
    for (int i=2;i<=last;i++){
        if (!gud[i]){
            cnt1++;
        }
    }
    int ans = 0;
    if (last == 0){
        cout << n - 1 << '\n';
        return 0;
    }
    if (cnt1 == 0) ans = 1;
    else{
        if (cnt1 >= 2) ans = 2;
        else{
            if (!gud[2]) ans = 1;
            else ans = 2;
        } 
    }
    ans = max(ans, n - last + 1);
    cout << ans << '\n';
 
    return 0;
}