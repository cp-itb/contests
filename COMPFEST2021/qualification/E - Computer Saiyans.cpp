/**
 * Contest : Compfest 13 Qualification
 * Team    : Computer Saiyans
 * Author  : Kinantan Arya Bagaspati
 * Problem : Ekosistem Hutan
 */

#include <bits/stdc++.h>
using namespace std;

long long a[200069];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    long long n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] %= m;
    }
    sort(a, a+n);
    long long ans = m+a[0]-a[n-1];
    for(int i=1; i<n; i++){
        ans = max(ans, a[i]-a[i-1]);
    }
    cout << m-ans << endl;
	return 0;
}
