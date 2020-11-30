/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : G
 */
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MX = (1LL << 32) - 1;

int n;
stack<ll> st;
ll cur = 1;
ll ans = 0;

int dep = 0;
int lcnt = 0;
// bool lebih = 0;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        if (s == "for" || s == "For"){
            ll x;
            cin >> x;
            if (cur > MX){
                lcnt++;
            } else{
                cur *= x;
                st.push(x);
            }
        } else if (s == "end"){
            if (lcnt){
                lcnt--;
            } else{
                cur /= st.top();
                st.pop();
            }
        } else{
            if (cur <= MX){
                ans += cur;
            } else{
                cout << "OVERFLOW!!!" << el;
                return 0;
            }
        }
        if (ans > MX){
            cout << "OVERFLOW!!!" << el;
            return 0;
        }
    }
    cout << ans << el;

    return 0;
}