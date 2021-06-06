/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : 0xD
 * Author  : Kinantan Arya Bagaspati
 * Problem : SuperComb
 */

#include<bits/stdc++.h>
using namespace std;

long long t, ans, ad, i1, i2, r, c1, c2;

int main(){
    cin >> t;
    while(t--){
        cin >> r;
        r*=2;
        ans = floor(sqrt((r*r - 1)/3));
        ans = (ans - 1)/2 * 2 + 1;
        for(long long i=1; 3*i+2 <= r; i++){
            c1 = (r*r - (3*i + 2)*(3*i + 2))/3;
            c2 = (r*r - (3*i + 1)*(3*i + 1))/3;

            i1 = floor(sqrt(c1));
            i2 = floor(sqrt(c2));
            if(i%2 == 0){
                ad = i1/2 *2 +1;
                ad = min(ad, (i2-1)/2 * 2 + 1);
            }else{
                ad = i2/2 * 2;
                ad = min(ad, (i1+1)/2 * 2);
            }
            ans += 2*ad;
        }
        cout << ans << endl;
    }
}