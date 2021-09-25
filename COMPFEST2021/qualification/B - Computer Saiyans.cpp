/**
 * Contest : Compfest 13 Qualification
 * Team    : Computer Saiyans
 * Author  : Kinantan Arya Bagaspati
 * Problem : Bantu Pecahkan Sandi
 */

#include <bits/stdc++.h>
using namespace std;

long long a[100069], b[100069], totb, init;
pair<long long, long long> stck[100069];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    long long n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] %= m;
    }
    totb = 0;
    init = 0;
    for(int i=0; i<n; i++){
        cin >> b[i];
        totb += b[i];
        init += a[i]*b[i];
    }
    for(int i=0; i<n; i++){
        stck[i] = {m - a[i], b[i]};
    }
    sort(stck, stck+n);
    long long reduce = 0, ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, init + totb*(stck[i].first-1) - reduce*m);
        reduce += stck[i].second;
    }
    cout << ans << endl;
	return 0;
}
