/**
 * Contest : Penyisihan SCPC COMPFEST 12
 * Team    : Korean Forest Stonks
 * Author  : Jun Ho Choi Hedyatmo
 * Problem : I - Illusory Tree
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k, l, par[N], siz[N];

int find(int v){
    if(par[v] == v){
        return v;
    } else {
        return (par[v] = find(par[v]));
    }
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(siz[a] < siz[b]){
            swap(a, b);
        }
        siz[a] += siz[b];
        par[b] = a;
    }
}

set<pair<int, int>> st1, st2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        siz[i] = 1;
        par[i] = i;
    }
    for(int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        st1.insert({min(a, b), max(a, b)});
    }
    cin >> l;
    for(int i = 1; i <= l; i++){
        int a, b;
        cin >> a >> b;
        st2.insert({min(a, b), max(a, b)});
    }

    set<pair<int, int>> st3;
    for(auto x : st1){
        if(st2.count(x) == 0){
            st3.insert(x);
        }
    }
    for(auto y : st2){
        if(st1.count(y) == 0){
            if(st3.count(y) == 0){
                st3.insert(y);
            }
        }
    }
    
    int sizs = st3.size();
    if(sizs == n - 1){
        for(auto x : st3){
            unite(x.first, x.second);
        }

        if(siz[find(1)] == n){
            cout << "Pohon\n";
        } else {
            cout << "Bukan pohon\n";
        }
    } else {
        cout << "Bukan pohon\n";
    }

    return 0;
}