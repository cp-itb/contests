/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : A
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    vector<long long> nums;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        nums.emplace_back(v[i].first - 1);
        nums.emplace_back(v[i].first);
        nums.emplace_back(v[i].first + 1);
        nums.emplace_back(v[i].second - 1);
        nums.emplace_back(v[i].second);
        nums.emplace_back(v[i].second + 1);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int len = nums.size();
    for (int i = 0; i < n; i++) {
        v[i].first = lower_bound(nums.begin(), nums.end(), v[i].first) - nums.begin() + 1;
        v[i].second = lower_bound(nums.begin(), nums.end(), v[i].second) - nums.begin() + 1;
    }
    vector<int> cnt(len + 5);
    for (int i = 0; i < n; i++) {
        cnt[v[i].first]++;
        cnt[v[i].second + 1]--;
    }
    for (int i = 1; i <= len + 1; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<long long> ans(n + 5);
    int last = 0;
    for (int i = 1; i <= len; i++) {
        if (cnt[i] != cnt[i - 1]) {
            last = i;
        }
        if (cnt[i] != cnt[i + 1] && cnt[i] > 0) {
            ans[cnt[i]] += nums[i - 1] - nums[last - 1] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}