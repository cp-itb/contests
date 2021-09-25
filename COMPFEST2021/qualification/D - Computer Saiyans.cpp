/**
 * Contest : Compfest 13 Qualification
 * Team    : Computer Saiyans
 * Author  : Kinantan Arya Bagaspati
 * Problem : Desa Maling Bagian Kedua
 */

#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    long long x, y, n;
    cin >> x >> y >> n;
    long long xl=0, xr=x, yl=0, yr=y;
    long long xm, ym, resp;
    char c;
    while(xr-xl>1 || yr-yl>1){
        xm = (xl+xr+1)/2;
        ym = (yl+yr+1)/2;
        cout << "? " << xm << " " << ym << endl;
        cout << flush;
        cin >> resp;
        if(resp%4 < 2){xl = xm;}
        else{xr = xm;}
        if(resp < 3){yl = ym;}
        else{yr = ym;}
        cin >> c;
        if(c == 'U'){
            yl = min(y-1, yl+1);
            yr = min(y, yr+1);
        }
        if(c == 'L'){
            xl = max(0ll, xl-1);
            xr = max(1ll, xr-1);
        }
        if(c == 'D'){
            yl = max(0ll, yl-1);
            yr = max(1ll, yr-1);
        }
        if(c == 'R'){
            xl = min(x-1, xl+1);
            xr = min(x, xr+1);
        }
    }
    cout << "! " << xr << " " << yr << endl;
	return 0;
}
