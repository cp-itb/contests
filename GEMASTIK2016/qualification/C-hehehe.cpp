/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : hehehe
 * Author  : Aufar Gilbran
 * Problem : C - Menggemaskan dan Cantik
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

string name[MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        int n;
        scanf("%d", &n);
        vector<pair<long long,long long>> A, B;
        for (int i = 0; i < n; ++i ) {
            char n[25];
            int a,b;
            scanf("%s%d%d", n, &a, &b);
            name[i] = n;
            A.push_back(make_pair(a, i));
            B.push_back(make_pair(b, i));
        }
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        sort(B.begin(), B.end());
        reverse(B.begin(), B.end());

        long long ans = 0;
        vector<int> ansIdx;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    if (i == j || i == k || j == k) continue;
                    long long G = A[i].first * A[j].first * A[k].first;
                    long long C = 1;
                    int cnt = 0;
                    vector<int> cp;
                    for (int x = 0; x < n && cnt < 3; ++x) {
                        int id = B[x].second;
                        if (id == A[i].second || id == A[j].second || id == A[k].second) continue;
                        C *= B[x].first;
                        cp.push_back(id);
                        ++cnt;
                    }
                    if (ans < G+C) {
                        ans = G+C;
                        ansIdx.clear();
                        ansIdx.push_back(A[i].second);
                        ansIdx.push_back(A[j].second);
                        ansIdx.push_back(A[k].second);
                        for (int x = 0; x < cp.size(); ++x) {
                            ansIdx.push_back(cp[x]);
                        }
                    }
                }
            }
        }
        assert(ansIdx.size() == 6);
        printf("%lld\n", ans);
        for (int i = 0; i < 3; ++i) {
            if (i) cout << " ";
            cout << name[ansIdx[i]];
        }
        cout << endl;
        for (int i = 3; i < 6; ++i) {
            if (i != 3) cout << " ";
            cout << name[ansIdx[i]];
        }
        cout << endl;
    }
    return 0;
}
