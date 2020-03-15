/**
 * Contest : FINDIT 2020
 * Team    : mufraswid
 * Author  : Jun Ho Choi Hedyatmo
 * Problem : C - Hyper Power
 */
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 25;

long long p25[10], p4[3];

long long binpow(long long x, long long y, long long mod){
    if(y == 0){
        return 1;
    } else {
        long long re = (binpow(x, y / 2, mod) * binpow(x, y / 2, mod)) % mod;
        if(y & 1){
            re = (re * x) % mod;
        }
        return re;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    p25[1] = 25;
    p25[2] = 20;
    p25[3] = 8;
    p25[4] = 4;
    p25[5] = 2;
    while(t--){
        long long a, b;
        cin >> a >> b;
        long long h = a % 4;
        if(a == 5 && b == 1){
            cout << "05\n";
        } else if(a % 25 == 0 || (a == 5 && b > 1)){
            cout << h * 25 << '\n';
        } else {
            long long hehe = min(b, 5LL);
            long long re = 1;
            while(hehe > 0){
                re = binpow(a, re, p25[hehe]);
                hehe--;
            }

            re = re % 25;
            long long hay = (re - h) % 25;
            while(hay < 0){
                hay += 25;
            }
            hay = hay % 25;
            hay = (19 * hay) % 25;
            long long res = (h + 4 * hay) % 100;

            if(res < 10){
                cout << "0" << res << '\n';
            } else {
                cout << res << '\n';
            }

        }
    }
    return 0;
}