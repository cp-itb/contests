/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan, Muhammad Kamal Shafi
 * Problem : D
 */
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
 
void done(int ans){
    cout << "! " << ans << endl;
    exit(0);
}
vector<int> ask(int l, int r) {
    assert(l <= r);
    cout << "? "; cout << r - l + 1 << ' ';
    for (int i = l; i <= r; i++) {
        cout << i;
        if (i == r) cout << endl;
        else cout << ' ';
    }
    vector<int> ret;
    int len;
    cin >> len;
    ret.resize(len);
    for (int i = 0; i < len; i++) {
        cin >> ret[i];
    }
    return ret;
}
 
int l, r;
int outl, outr;
int main() {
    cin >> n >> m;
    if (n < m){
        l = 1;
        r = n;
        outl = n + 1;
        outr = n + m;
    } else{
        outl = 1;
        outr = n;
        l = n + 1;
        r = n + m;
    }
    auto vec = ask(l, r);
    {
        vector<bool> temp(n + m + 1, 0);
        for (auto x : vec){
            temp[x] = 1;
        }
        for (int i=outl;i<=outr;i++){
            if (!temp[i]){
                done(i);
            }
        }
    }
    while (l < r){
        int m = (l + r) / 2;
        auto vec = ask(l, m);
        if ((int)vec.size() <= m - l + 1){
            l = m + 1;
        } else{
            r = m;
        }
    }
    done(l)
 
    return 0;
}
 