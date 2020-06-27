/**
 * Contest : ITFESTUSU 2020
 * Team    : OTWF21
 * Author  : Muhammad Hasan, Muhammad Kamal Shafi
 * Problem : D - Proses Editing
 */
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e2 + 10;

int n;
string s[N];

string low(string temp){
    for (int i=0;i<(int)temp.length();i++){
        temp[i] = tolower(temp[i]);
    }
    return temp;
}

int main () {
    cin >> n;
    cin.ignore();
    int j = 0;
    while(getline(cin, s[++j])) {
            stringstream ss(s[j]);
            string temp;
            vector <string> ans;
            while (ss >> temp){
                for (auto e : temp) {
                    if (e >= 'a' && 'z' >= e) continue;
                    if (e >= 'A' && 'Z' >= e) continue;
                    assert(false);
                    continue;
                }
                if (ans.empty()){
                    ans.pb(temp);
                    continue;
                }
                if (low(ans.back()) == low(temp)) continue;
                else{
                    ans.pb(temp);
                }
            }
            int len = ans.size();
            for (int i=0;i<len;i++){
                cout << ans[i] << " ";
            }
            cout << el;
    }
    // assert(j == n);

    return 0;
}