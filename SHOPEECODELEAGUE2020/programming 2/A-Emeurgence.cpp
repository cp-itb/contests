/**
* Contest : Shopee Code League 2020 - Programming 2
* Team    : Emeurgence
* Author  : Muhammad Hasan
* Problem : A - Highest Mountain
*/
#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

pair<int, int> getAnswer(const vector<int>& v, bool ok) {
    pair<int, int> ret = {-1, -1};
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (v[i] == cur) {
            ++cur;
        } else {
            if (cur > 1) {
                if (ret.first < cur - 1)
                    ret = make_pair(cur - 1, (ok ? i - 1 : n - i));
            }
            cur = 1;
            if (v[i] == 1) --i;
        }
    }
    if (cur > 1) {
        if (ret.first < cur - 1)
            ret = make_pair(cur - 1, (ok ? n - 1 : 0));
    }
    return ret;
}

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    pair<int, int> answer = getAnswer(v, true);
    reverse(v.begin(), v.end());
    pair<int, int> cur = getAnswer(v, false);
    if (cur.first > answer.first)
        answer = cur;
    else if (cur.first == answer.first)
        answer.second = min(answer.second, cur.second);
    cout << answer.first << " " << answer.second << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}