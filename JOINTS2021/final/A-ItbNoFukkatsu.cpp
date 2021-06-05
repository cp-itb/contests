 /**
  * Contest : Joints 2021 Final
  * Team    : ItbNoFukkatsu
  * Author  : Farras Faddila
  * Problem : A
  */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<ll> primes;

void sieve(int bat) {
    // primes.clear();
    vector<bool> pr(bat + 1, true);
    for (int i = 2; i <= bat; i++) {
        if (!pr[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j <= bat; j += i) {
            pr[j] = false;
        }
    }
}

int n;

void solve() {
    cin >> n;
    if (n <= 3) {
        cout << 1 << '\n';
        return;
    }
    if (n <= 5) {
        cout << 2 << '\n';
        return;
    }
    sieve(n);
    int cannot = 0;
    int isi = 0;
    int sz = (int) primes.size();
    for (int i = 0; i < sz; i++) {
        if (primes[i] * 3 > n) cannot++;
        if (primes[i] * 2 <= n && primes[i] * 3 > n) isi++;
    }
    cannot -= min(isi, 2);
    cout << n - 1 - cannot << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}