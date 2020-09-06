/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : G - Gajah Malas
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
int ar[N];

map<int, int> getid;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        getid[ar[i]] = 1;
    }
    {
        int tempid = 0;
        for (auto& x : getid){
            x.se = ++tempid;
        }
        for (int i=1;i<=n;i++){
            ar[i] = getid[ar[i]];
        }
    }
    {
        int cur = 1;
        for (int i=1;i<=n;i++){
            if (ar[i] == cur) cur++;
        }
        for (int i=n;i>=1;i--){
            if (ar[i] == cur) cur++;
        }
        if (cur == n + 1){
            cout << "Ya" << el;
            return 0;
        } 
    }
    {
        int cur = n;
        for (int i=n;i>=1;i--){
            if (ar[i] == cur) cur--;
        }
        for (int i=1;i<=n;i++){
            if (ar[i] == cur) cur--;
        }
        if (cur == 0){
            cout << "Ya" << el;
            return 0;
        } 
    }
    cout << "Tidak" << el;

    return 0;
}