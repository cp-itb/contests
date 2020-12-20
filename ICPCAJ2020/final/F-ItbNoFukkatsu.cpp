/**
 * Contest : ICPC 2020 Asia Jakarta
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : F
 */
#include <bits/stdc++.h>
 
#define pb push_back
#define mp make_pair
#define se second
#define fi first
 
using namespace std;
using ll = long long;
using pil = pair<int, ll>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
 
const int N = 5e5 + 5;
 
int n, m;
int a[N];
vector<int> b[N];
 
struct BIT {
    vector<int> bit;
    BIT() {
        bit.assign(N, 0);
    }    
 
    void add(int x, int val) {
        for (int i = x; i < N; i += i & -i) {
            bit[i] += val;
        }
    }
 
    int get(int x) {
        int ret = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ret += bit[i];
        }
        return ret;
    }
} A, B;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
 
    vector<int> nums;
 
    auto getId = [&](int x) -> int {
        return (int) (lower_bound(nums.begin(), nums.end(), x) - nums.begin()) + 1;    
    };
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums.emplace_back(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int len; cin >> len;
        b[i].resize(len);
        for (int& j : b[i]) {
            cin >> j;
            nums.emplace_back(j);
        }
    }
 
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
 
    for (int i = 1; i <= n; i++) {
        a[i] = getId(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int& j : b[i]) {
            j = getId(j);
        }
    }
 
    long long initInverse = 0;
    for (int i = 1; i <= n; i++) {
        initInverse += ((i - 1) - A.get(a[i]));
        A.add(a[i], 1); B.add(a[i], 1);
    }
 
    auto getAnswer = [&](vector<int>& v) -> long long {
        long long cur = initInverse;
        int it = n + 1;
        for (int x : v) {
            cur += ((it - 1) - A.get(x));
            A.add(x, 1);
            it++;
        }
        long long ret = cur;
        for (int x : v) {
            cur += B.get(x - 1) - (n - B.get(x));
            ret = min(ret, cur);
        }
        for (int x : v) {
            A.add(x, -1);
        }
        return ret;
    };
 
    for (int i = 1; i <= m; i++) {
        cout << getAnswer(b[i]) << '\n';
    }
 
    return 0;
}