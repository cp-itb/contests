/**
* Contest : Shopee Code League 2021
* Team    : ZopikoDLig
* Author  : Muhammad Hasan
* Problem : A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
 
int n, k;
int v[N];
int bit[N];
 
void add(int x, int val) {
    for ( ; x < N; x += x & -x)
        bit[x] += val;
}
 
int get(int x) {
    int ret = 0;
    for ( ; x > 0; x -= x & -x)
        ret += bit[x];
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> k;
    vector<int> nums(n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] -= k; v[i] += v[i - 1];
        if (v[i] >= 0) ++ans;
        nums[i - 1] = v[i];
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for (int i = 1; i <= n; i++) {
        v[i] = lower_bound(nums.begin(), nums.end(), v[i]) - nums.begin() + 1;
    }
    for (int i = 1; i <= n; i++) {
        ans += get(v[i]);
        add(v[i], 1);
    }
    cout << ans << '\n';
 
    return 0;
}