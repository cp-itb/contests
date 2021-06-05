 /**
  * Contest : Joints 2021 Final
  * Team    : ItbNoFukkatsu
  * Author  : Muhammad Hasan
  * Problem : B
  */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
string s[N];

bool cmp(string& a, string& b) {
    return a + b < b + a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + 1 + n, cmp);
    string res = "";
    for (int i = 1; i <= n; i++) {
        res += s[i];
    }
    int len = res.size();
    int fst = len - 1;
    for (int i = 0; i < len - 1; i++) {
        if (res[i] != '0') {
            fst = i;
            break;
        }
    }
    for (int i = fst; i < len; i++) {
        cout << res[i];
    }
    cout << '\n';

    return 0;
}