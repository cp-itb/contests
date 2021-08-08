 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Kinantan Arya Bagaspati
  * Problem : I - Plagiarisme
  */

#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long s[n][m], t[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> s[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> t[i][j];
        }
    }
    long long com[4][n], maxcom[4], mincom[4], ans = -1e18;
    for(int j=0; j<m; j++){
        for(int k=0; k<4; k++){
            maxcom[k] = -1e18;
            mincom[k] = 1e18;
        }
        for(int i=0; i<n; i++){
            com[0][i] = i + s[i][j] + t[i][j];
            com[1][i] = i + s[i][j] - t[i][j];
            com[2][i] = i - s[i][j] + t[i][j];
            com[3][i] = i - s[i][j] - t[i][j];
            for(int k=0; k<4; k++){
                maxcom[k] = max(maxcom[k], com[k][i]);
                mincom[k] = min(mincom[k], com[k][i]);
            }
        }
        for(int k=0; k<4; k++){
            ans = max(ans, maxcom[k]-mincom[k]);
        }
    }
    cout << ans << endl;
}

