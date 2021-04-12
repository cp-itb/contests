#include <bits/stdc++.h>

using namespace std;

const string euy = "halo dunia!";

string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, str);
    int len = str.size();
    bool ok = true;
    if (len == (int) euy.size()) {
        for (int i = 0; i < len; i++) {
            if (tolower(euy[i]) == tolower(str[i])) continue;
            ok = false;
            break;
        }
    } else {
        ok = false;
    }
    cout << (ok ? "YA" : "TIDAK") << '\n';

    return 0;
}