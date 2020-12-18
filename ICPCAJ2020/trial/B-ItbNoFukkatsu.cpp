/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : B
 */
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 510;
 
int r, c;
char mat[N][N];
 
void done(int ans){
    cout << ans << '\n';
    exit(0);
}
 
int main(){
    cin >> r >> c;
    if (r > c){
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                cin >> mat[j][i];
            }
        }
        swap(r, c);
    } else{
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                cin >> mat[i][j];
            }
        }
    }
    int ans = 0;
    if (r == 1){
        if (c <= 2){
            done(0);
        } else{
            for (int i=2;i<=c - 1;i++){
                if (mat[1][i] == '.') ans++;
            }
            done(ans);
        }
    } else if (r == 2){
        if (c <= 2){
            done(0);
        } else{
            for (int i=2;i<=c - 1;i++){
                if (mat[1][i] == '.' && mat[2][i] == '.') ans++;
            }
            done(ans);
        }
    } else{
        for (int i=2;i<=r - 1;i++){
            for (int j=2;j<=c - 1;j++){
                if (mat[i][j] == '.') ans++;
            }
        }
        bool ok = 1;
        for (int i=2;i<=r - 1;i++){
            if (mat[i][1] == '#' || mat[i][c] == '#') ok = 0;
        }
        for (int i=2;i<=c - 1;i++){
            if (mat[1][i] == '#' || mat[r][i] == '#') ok = 0;
        }
        if (ok) ans++;
        done(ans);
    }
 
    return 0;
}