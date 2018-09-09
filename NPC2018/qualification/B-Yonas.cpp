#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int fibo[200];
int n_fibo;
vector<pair<long long, int> > q;
vector<pair<long long, int> > ans;

bool secondary(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void com_fibo() {
    fibo[0] = 13;
    fibo[1] = 21;
    n_fibo = 1;
    while (fibo[n_fibo] <= 100000000) {
        n_fibo++;
        fibo[n_fibo] = fibo[n_fibo-1] + fibo[n_fibo-2];
    }
}

int main() {
    com_fibo();
    int t, x;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        scanf("%d", &x);
        q.push_back(make_pair((long long) x, i));
    }
    sort(q.begin(), q.end());
    long long tans = 4;
    long long inc = 2;
    int p = 0;
    for (int i=0; i<t; i++) {
        int n = q[i].first;
        if (binary_search(fibo, fibo + n_fibo, n)) {
            ans.push_back(make_pair(-1LL, q[i].second));
        } else {
            while (p < n) {
                if (n - p  >= 10000000) {
                    tans += inc*255718401; tans %= MOD;
                    inc *= 255718402;      inc  %= MOD;
                    p += 10000000;
                } else if (n - p  >= 1000000) {
                    tans += inc*235042058; tans %= MOD;
                    inc *= 235042059;      inc  %= MOD;
                    p += 1000000;
                } else if (n - p  >= 100000) {
                    tans += inc*607723519; tans %= MOD;
                    inc *= 607723520;      inc  %= MOD;
                    p += 100000;
                } else if (n - p  >= 10000) {
                    tans += inc*905611804; tans %= MOD;
                    inc *= 905611805;      inc  %= MOD;
                    p += 10000;
                } else if (n - p  >= 1000) {
                    tans += inc*688423209; tans %= MOD;
                    inc *= 688423210;      inc  %= MOD;
                    p += 1000;
                } else if (n - p  >= 100) {
                    tans += inc*976371284; tans %= MOD;
                    inc *= 976371285;      inc  %= MOD;
                    p += 100;
                } else if (n - p  >= 10) {
                    tans += inc*1023; tans %= MOD;
                    inc  *= 1024;     inc  %= MOD;
                    p += 10;
                } else {
                    tans += inc; tans %= MOD;
                    inc <<= 1;   inc  %= MOD;
                    p++;
                }
            }
            ans.push_back(make_pair(tans, q[i].second));
        }
    }
    sort(ans.begin(), ans.end(), secondary);

    for (int i=0; i<t; i++) {
        if (ans[i].first == -1) {
            printf("YEY\n");
        } else {
            printf("%lld\n", ans[i].first);
        }
    }
}
