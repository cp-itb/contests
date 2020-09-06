/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : F - Fate of Chanek
 */
#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}

const int N = 1e5;
const int K = 1e6;

vector<int> sort_cyclic_shifts(vector<int> const& s) {
    int n = s.size();
    const int alphabet = N + 5;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(vector<int> s) {
    s.emplace_back(0);
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(vector<int> const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

const int MAXN = (1 << 18);
const int MAXLOG = 18;

struct sparse_table {
    vector<vector<int>> dp;
    vector<int> prec_lg2;
    int n;

    sparse_table(vector<int> &a)
    {
        dp.resize(MAXN, vector<int>(MAXLOG));
        prec_lg2.resize(MAXN);
        n = a.size();
        for(int i = 2; i < MAXN; i++) prec_lg2[i] = prec_lg2[i >> 1] + 1;
        for(int i = 0; i < n; i++) dp[i][0] = a[i];
        for(int j = 1; (1 << j) <= n; j++)
            for(int i = 0; i < n; i++) {
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
    }

    int query(int l, int r)
    {
        int k = prec_lg2[r - l + 1];
        return max(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

int main() {
    int n, q;
    inpos(n), inpos(q);
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        inpos(s[i]);
    }

    /** Finding max distinct length **/
    vector<int> last(N + 5, n);
    vector<int> last_pos(n, n), lens(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            last_pos[i] = last_pos[i + 1];
        }
        last_pos[i] = min(last_pos[i], last[s[i]]);
        lens[i] = last_pos[i] - i;
        last[s[i]] = i;
    }
    // debug(lens, last_pos);

    /** Create suffix array **/
    vector<int> suf = suffix_array_construction(s);
    // debug(suf);

    /** Create max length distinct **/
    vector<int> len_dist(n);
    for (int i = 0; i < n; i++) {
        len_dist[i] = lens[suf[i]];
    }
    // debug(len_dist);

    /** Create LCP **/
    vector<int> lcp = lcp_construction(s, suf);

    /** Create Sparse Table (maximum) for length **/
    sparse_table sp_len(len_dist);

    /** Precompute Answer **/
    vector<pair<int, int>> ans(K + 2, make_pair(-1, -1));

    /** Try every length possible **/
    int cur_k = 0;
    for (int len = 1; len <= n; len++) {
        if (cur_k == K) break; 
        int last_pos = 0;
        while (1) {
            if (cur_k == K) break;
            /** Find first position **/
            int l = last_pos, r = n - 1;
            int first_pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sp_len.query(last_pos, mid) >= len) {
                    r = mid - 1;
                    first_pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (first_pos == -1) break;
            // debug(len, last_pos, first_pos);

            /** Find new last position **/
            int new_last_pos = first_pos;
            priority_queue<int, vector<int>, greater<int>> pq;
            for (int it = first_pos; it < n; it++) {
                new_last_pos = it;
                pq.emplace(suf[it]);
                if (it < n - 1 && lcp[it] >= len) {
                    continue;
                } else {
                    break;
                }
            }
            // debug(len, first_pos, new_last_pos);
            for (int it = first_pos; it <= new_last_pos; it++) {
                int min_L = pq.top(); pq.pop();
                ans[++cur_k] = make_pair(min_L + 1, min_L + len);
                // debug(cur_k, ans[cur_k]);
                if (cur_k == K) break;
            }
            /** Continue Finding **/
            last_pos = new_last_pos + 1;
        }
    }

    while (q--) {
        int k;
        inpos(k);
        outpos(ans[k].first, ' '); outpos(ans[k].second, '\n');
    }
    return 0;
}