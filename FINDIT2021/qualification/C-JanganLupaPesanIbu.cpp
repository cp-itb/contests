/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : Jangan Lupa Pesan Ibu
 * Author  : Fausta Anugrah
 * Problem : Jaga Jarak
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll n, a[NN], d;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> d;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(ll i = 1; i <= n; i++)
        a[i] -= d * i;
    ll has = 0;
    priority_queue<ll> pq;
    for(ll i = 1; i <= n; i++)
    {
        pq.push(a[i]);
        pq.push(a[i]);
        has -= a[i];
        has += pq.top();
        pq.pop();
    }
    cout << has << "\n";

}
    