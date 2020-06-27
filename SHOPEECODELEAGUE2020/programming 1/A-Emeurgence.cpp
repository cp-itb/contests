/**
* Contest : Shopee Code League 2020 - Programming 1
* Team    : Emeurgence
* Author  : Mastre
* Problem : A - Search Engine
*/
#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'
 
using namespace std;
 
const int N = 1e4 + 10;
const int P = 131; 
const int M = 1e9 + 7;
 
int tc;
int n, q;
vector<int> cek[N];
 
int getid(string& s){
    ll ret = 0;
    ll cur = 1;
    int len = s.length();
    for (int i=0;i<len;i++){
        ll dig = (ll)(s[i] - '0' + 1);
        ret = (ret + dig * cur) % M;
        cur = cur * P % M;
    }
    return ((int)ret);
}
 
void init(){
    for (int i=0;i<=n + 1;i++){
        cek[i].clear();
    }
}
 
vector<int> preffunc(vector<int>& s){
    int len = s.size();
    vector<int> ret(len, 0);
    int l = 0;
    for (int r=1;r<len;r++){
        while (l != 0 && s[l] != s[r]) l = ret[l - 1];
        if (s[l] == s[r]) l++;
        ret[r] = l;
    }
    return ret;
}
 
bool cari(vector<int>& s, vector<int>& t){
    int slen = s.size();
    int tlen = t.size();
    if (slen < tlen) return 0;
    vector<int> pref = preffunc(t);
 
    int pt = 0;
    for (int ps=0;ps<slen;ps++){
        while (pt != 0 && t[pt] != s[ps]) pt = pref[pt - 1];
        if (t[pt] == s[ps]) pt++;
        if (pt == tlen) return 1;
    }
    return 0;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> tc;
    for (int cas=1;cas<=tc;cas++){
        cout << "Case " << cas << ":\n";
        cin >> n >> q;
        cin.ignore();
        int id = 0;
        init();
        map<vector<int>, int> ada;
        for (int i=1;i<=n;i++){
            string s;
            getline(cin, s);
            stringstream ss(s);
            string temp;
            while (ss >> temp){
                cek[i].pb(getid(temp));
            }
            int len = cek[i].size();
            map<vector<int>, bool> atemp;
            for (int j=0;j<len;j++){
                vector<int> vtemp;
                for (int k=j;k<len;k++){
                    vtemp.pb(cek[i][k]);
                    atemp[vtemp] = 1;
                }
            }
            for (auto x : atemp){
                ada[x.fi]++;
            }
        }
        while(q--){
            string t;
            getline(cin, t);
            vector<int> v;
            stringstream ss(t);
            string temp;
            while (ss >> temp){
                v.pb(getid(temp));
            }
            cout << ada[v] << el;
        }
    }
 
    return 0;
}