/**
  * Contest : Joints 2021 Qualification
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Hasan
  * Problem : C
***/
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

long long ceil(long long a, long long b) {
    return (a + b - 1) / b;
}

long long get_min(vector<long long> v) {
    int len = v.size();
    for (int i = len - 3; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            v[i] = v[i] * ceil(v[i + 1], v[i]);
        }
    }
    return v[0];
}

bool simul(long long n, vector<long long>& v) {
    int len = v.size();
    for (int i = 0; i < len; i++) {
        n = n - n % v[i];
        if (n == 0 && i < len - 1) return false;
    }
    return n == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << 0 << ' ' << v[0] - 1 << '\n';
        return 0;
    }
    if (v[n - 2] >= v[n - 1]) {
        cout << -1 << '\n';
        return 0;
    }
    long long x = get_min(v);
    if (!simul(x, v)) {
        cout << -1 << '\n';
        return 0;
    }
    long long l = x, r = INF, y = x;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (simul(mid, v)) {
            l = mid + 1;
            y = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << x << " " << y << '\n';

    return 0;
}