/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : I - Illusory Tree
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

const int N = 1e5 + 10;

int n;
set<pii> setdah;

int par[N], sz[N];
int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    init();
    {
        int k;
        cin >> k;
        for (int i=1;i<=k;i++){
            int a, b;
            cin >> a >> b;
            setdah.insert(mp(a, b));
        }
    }
    {
        int k;
        cin >> k;
        for (int i=1;i<=k;i++){
            int a, b;
            cin >> a >> b;
            if (setdah.find(mp(a, b)) != setdah.end()) setdah.erase(mp(a, b));
            else setdah.insert(mp(a, b));
        }
    }
    if (setdah.size() == n - 1){
        for (auto x : setdah){
            make(x.fi, x.se);
        }
        if (sz[find(1)] == n) cout << "Pohon" << el;
        else cout << "Bukan pohon" << el;
    } else{
        cout << "Bukan pohon" << el;
    }

    return 0;
}