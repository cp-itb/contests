/**
 * Contest : ITFESTUSU 2020
 * Team    : OTWF21
 * Author  : Morgen Sudyanto, Muhammad Kamal Shafi
 * Problem : B - Ice Breaking
 */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bitset<100005> prima;
vector<int> p;  //bil. prima (OPTIONAL)

void sieve(int x) {
    prima.set();
    prima[0]=0;
    prima[1]=0;
    for (int i=2;i*i<=x;i++) {
        for (int j=i*i;j<=x;j+=i) {
            prima[j]=0;
        }
    }
    //masukin bilangan prima ke vector p (OPTIONAL)
    for (int i=2;i<=x;i++) {
        if (prima[i]) p.pb(i);
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // sieve(50000);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        if (n == 1) {
            if (a[1] == 1) cout << "YA" << endl;
            else cout << "TIDAK" << endl;
            continue;
        }
        int cnt[n+5];
        memset (cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            // if (a[i] > 1) notzero++;
            // for (int j=0;j<p.size();j++) {
            //     while (a[i]%p[j] == 0) {
            //         cnt[i]++;
            //         a[i] /= p[j];
            //     }
            //     if (a[i] == 1) break;
            //     if (a[i] < p[j]) break;
            // }
            // if (a[i] != 1) cnt[i]++;
            if (a[i] == 0) continue;
            while (a[i]%2 == 0) {
                cnt[i]++;
                a[i]/=2;
            }
            for (int j=3;j*j <= a[i]; j+=2) {
                while (a[i]%j == 0) {
                    cnt[i]++;
                    a[i] /= j;
                }
            }
            if (a[i]>2) cnt[i]++;
        }
        int x = 0;
        for (int i=1;i<=n;i++) {
            x ^= cnt[i];
            // cerr << cnt[i] << " ";
        }
        // cerr << endl;
        if (x == 0) {
            cout << "YA" << endl;
        } else {
            cout << "TIDAK" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}