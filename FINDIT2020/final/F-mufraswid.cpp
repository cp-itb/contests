/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Morgen Sudyanto
 * Problem : F - Tukar Kartu
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;



int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int arr[n+5];
        for (int i=0;i<n;i++) cin >> arr[i];
        pair<int, int> arrPos[n]; 
        for (int i = 0; i < n; i++) 
        { 
            arrPos[i].first = arr[i]; 
            arrPos[i].second = i; 
        } 
    
        sort(arrPos, arrPos + n); 
    
        vector<bool> vis(n, false); 
    
        int ans = 0; 
    
        for (int i = 0; i < n; i++) 
        { 
            if (vis[i] || arrPos[i].second == i) 
                continue; 
    
            int cycle_size = 0; 
            int j = i; 
            while (!vis[j]) 
            { 
                vis[j] = 1; 
    
                j = arrPos[j].second; 
                cycle_size++; 
            } 
    
            if (cycle_size > 0) 
            { 
                ans += (cycle_size - 1); 
            } 
        } 
    
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}