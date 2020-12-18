/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : A
 */
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 10;
 
int n;
 
int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cout << n - a + 1 << ' ';
    }
    cout << '\n';
 
    return 0;
}