/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Junho Choi Hedyatmo
 * Problem : B - Bitwise
 */
#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while(t--){
        int n, p, q, z;
        cin >> n >> p >> q >> z;

        int arr[n + 5];
        int mark[n + 5];
        for(int i = 1; i <= n; i++){
            cin >> arr[i];

            int a = arr[i] & p;
            int b = arr[i] ^ q;

            if(a < z && b > z){
                mark[i] = 1;
            } else {
                mark[i] = 0;
            }

        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(mark[i]){
            bool can = true;
                for(int j = 2 * i; j <= n; j += i){
                    if(mark[j] == 0){
                        can = 0;
                    }
                }
            if(can) cnt++;
            }
        }

        cout << cnt << " ";


    }
    cout << '\n';
    return 0;
}