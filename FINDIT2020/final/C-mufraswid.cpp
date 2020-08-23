/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Junho Choi Hedyatmo
 * Problem : C - Mewarnai Papan
 */
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<vector<ll>> matrix;

#define el '\n'
#define MOD 1000000007

ll n,m, mem[4];
matrix T;

matrix mul(matrix A, matrix B){
    int siz = A[0].size();
    matrix C;
    for(int i=0;i<siz;i++){
        vector<ll> g;
        for(int j=0;j<siz;j++){
            g.push_back(0);
        }
        C.push_back(g);
    }
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++){
            for(int k=0;k<siz;k++){
                C[i][j] += ((A[i][k]%MOD)*(B[k][j]%MOD)) % MOD;
            }
        }
    }
    return C;
}

matrix mpow(matrix A, ll p){
    if(p==1){
        return A;
    }
    if(p%2==1){
        return mul(A, mpow(A, p-1));
    }
    matrix X = mpow(A, p/2);
    return mul(X, X);
}

ll func(int n, matrix T){
    if(n >= 4){
        ll power = n-3;

        matrix l = mpow(T, power);

        ll res=0;
        int siz = T[0].size();
        for(int i=0;i<siz;i++){
            res += (l[0][i]*mem[siz-i])%MOD;
            res = res%MOD;
        }
        return res;

    } else {
        return mem[n];
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    matrix mat;
    for(int i = 0; i < 3; i++){
        vector<long long> a;
        for(int j = 0;j  < 3; j++){
            a.push_back(0);
        }
        mat.push_back(a);
    }

    mat[0][0] = 3;
    mat[0][2] = -2;
    mat[1][0] = 1;
    mat[2][1] = 1;
    mem[0] = 0;
    mem[1] = 3;
    mem[2] = 11;
    mem[3] = 33;

    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;

        ll haha = (func(r, mat) - func(l - 1, mat)) % MOD;
        while(haha < 0) {
            haha += MOD;
            haha = haha % MOD;
        }
        cout << haha << '\n';
    }
    return 0;
}