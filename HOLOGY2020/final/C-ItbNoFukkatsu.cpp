/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan, Muhammad Kamal Shafi
 * Problem : C
 */
#include <bits/stdc++.h>

using namespace std;

const vector<char> same = {'H', 'I', 'M',
    'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'};
const vector<pair<char, char>> dif = {{'p', 'q'}};
string str;

bool check(char x, char y) {
    if (x == y) {
        for (char c : same)
            if (c == x)
                return true;
    } else {
        for (auto e : dif) {
            if (e.first == x && e.second == y)
                return true;
            if (e.first == y && e.second == x)
                return true;
        }
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    int n = str.size();
    bool ok = true;
    for (int i = 0; i < n / 2; i++) {
        if (!check(str[i], str[n - i - 1])) {
            ok = false;
            break;
        }
    }
    if (n % 2 == 1 && !check(str[n / 2], str[n / 2]))
        ok = false;
    cout << (ok ? "DAPAT" : "TIDAK DAPAT") << '\n';

    return 0;
}
