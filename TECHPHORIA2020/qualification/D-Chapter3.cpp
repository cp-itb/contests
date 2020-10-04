/**
 * Contest : Techphoria 2020 - Qualification
 * Team    : Chapter3
 * Author  : Muhammad Hasan
 * Problem : D
 */
#include <bits/stdc++.h>
using namespace std;

int p;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p;
    while (p--) {
        cin >> s;
        string ans = "";
        int point = 0, len = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '<') {
                if (point > 0) point--;
            } else if (s[i] == '>') {
                point++;
                if (point > len) point = len;
            } else if (s[i] == '-') {
                if (point == 0) continue;
                ans.erase(ans.begin() + point - 1);
                point--;
                len--;
            } else {
                if (point < len) {
                    ans.insert(ans.begin() + point, s[i]);
                } else {
                    ans += s[i];
                }
                len++;
                point++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
