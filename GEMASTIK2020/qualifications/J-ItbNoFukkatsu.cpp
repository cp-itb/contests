/**
 * Contest  : GEMASTIK 2020 Qualification
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : J
 */
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 100, M = 8, MX = 1e4;

int k;
int n, m;
vector<pii> va[M], vb[M];

string conv[MX];

int to_menit(string s){
    int jj = stoi(s);
    
    string temp;
    bool ok = 0;
    for (auto x : s){
        if (ok){
            temp.pb(x);
        }
        if (x == '.') ok = 1;
    }
    int ret = stoi(temp) + jj * 60;
    conv[ret] = s;
    return ret;
}
pii iris(pii a, pii b){
    int ra = max(a.fi, b.fi);
    int rb = min(a.se, b.se);
    return mp(ra, rb);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    cin >> n;
    for (int i=1;i<=n;i++){
        int day;
        string a, b;
        cin >> day >> a >> b;
        va[day].pb(mp(to_menit(a), to_menit(b)));
    }
    cin >> m;
    for (int i=1;i<=m;i++){
        int day;
        string a, b;
        cin >> day >> a >> b;
        vb[day].pb(mp(to_menit(a), to_menit(b)));
    }
    for (int i=0;i<M;i++){
        sort(va[i].begin(), va[i].end());
        sort(vb[i].begin(), vb[i].end());
    }
    vector<string> ans;
    for (int day=0;day<M;day++){
        vector<pii> temp;
        for (auto x : va[day]){
            for (auto y : vb[day]){
                pii temp2 = iris(x, y);
                if (temp2.se - temp2.fi >= k){
                    temp.pb(temp2);
                }
            }
        }
        sort(temp.begin(), temp.end());
        for (auto x : temp){
            string sans;
            sans.pb(char(day + '0'));
            sans = sans + " " + conv[x.fi] + " " + conv[x.se];
            ans.pb(sans);
        }
    }
    if (ans.empty()){
        cout << "ikhlaskan saja" << el;
        return 0;
    }
    for (auto x : ans){
        cout << x << el;
    }

    return 0;
}