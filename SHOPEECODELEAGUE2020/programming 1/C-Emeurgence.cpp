/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Emeurgence
* Author  : Muhammad Kamal Shafi
* Problem : C - Sequence
*/
#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'
 
using namespace std;
 
const int M = 31, N = 5e3 + 10, K = 2e3 + 10;
const ll MOD = 1e9 + 7;
 
ll n, m, k;
ll cnt[31][N];
 
void process(ll a, ll b, ll c){
    for (ll j=1;j<=min(k, c);j++){
        ll temp = (a * j * j % k + b) % k;
        ll isi = (c - j) / k + 1LL;
        cnt[0][temp] = (cnt[0][temp] + isi) % MOD;
    }
}
void init(){
    for (int i=1;i<M;i++){
        for (int j=0;j<k;j++){
            for (int jj=0;jj<k;jj++){
                int njj = ((k + j) - jj) % k;
                cnt[i][j] = (cnt[i][j] + cnt[i - 1][jj] * cnt[i - 1][njj] % MOD) % MOD;
            }
        }
    }
}
vector<ll> ubah(vector<ll>& ans, vector<ll>& temp){
    vector<ll> ret(k, 0);
    for (int i=0;i<k;i++){
        for (int j=0;j<k;j++){
            int nj = ((k + i) - j) % k;
            ret[i] = (ret[i] + ans[j] * temp[nj] % MOD) % MOD;
        }
    }
    return ret;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m >> k;
    for (ll i=1;i<=n;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        process(a, b, c);
    }
    init();
    vector<ll> ans(k, 0);
    ans[0] = 1;
    for (int i=0;i<M;i++){
        ll bit = (1LL << i);
        if (m & bit){
            vector<ll> temp(k);
            for (int j=0;j<k;j++){
                temp[j] = cnt[i][j];
            }
            ans = ubah(ans, temp);
        }
    }
    cout << ans[0] << el;
 
    return 0;
}