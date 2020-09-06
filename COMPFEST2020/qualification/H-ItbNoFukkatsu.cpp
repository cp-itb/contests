/**
 * Contest : COMPFEST 2020 Qualification
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Kamal Shafi
 * Problem : H - Harta Karun Stompfec
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

const int M = 1e5 + 10;
const int MOD = 1e9 + 9;
const int base = 71;
const int MOD2 = 1e9 + 7;
const int base2 = 31;

ll pw[M + 5], pw2[M + 5];

void init_base() {
  pw[0] = 1;
  pw2[0] = 1;
  for(int i = 1; i <= M; i++) {
    pw[i] = (pw[i - 1] * base) % MOD;
    pw2[i] = (pw2[i - 1] * base2) % MOD2;
  }
}

inline ll get_hash(const string& S) {
  ll a = 0, b = 0;
  for(int i = 0; i < (int)S.length(); i++) {
    ll cur = (S[i] - 'a') + 1;
    a = (a + pw[i] * cur) % MOD;
    b = (b + pw2[i] * cur) % MOD2;
  }
  return a + (b << 31);
}
ll gab_hash(ll h1, ll h2, ll pp){
    ll b = (h1 >> 31);
    ll a = h1 - (b << 31);
    ll b2 = (h2 >> 31);
    ll a2 = h2 - (b2 << 31);
    ll aret = (a + a2 * pw[pp]) % MOD;
    ll bret = (b + b2 * pw2[pp]) % MOD2;
    return aret + (bret << 31); 
}

int m;
int n, q;
string st;
int len;
vector<string> katas;
int pre[M];

unordered_map<ll, bool> ada;
bool cek(ll a){
    if (ada.count(a)) return 1;
    return 0;
}

struct Node{
    int count = 0;
    int ckata = 0;
    int le, ri;
    int sle, sri;
    vector<ll> hash;
    Node() {}
    Node(char c, int pos){
        hash.clear();
        if (c == ' '){
            count = 0;
            le = ri = pos;
            sle = sri = 0;
            ckata = 0;
            return;
        }
        string temp = "";
        temp.pb(c);
        ll hh = get_hash(temp);
        hash.pb(hh);
        if (cek(hh)) count = 1;
        le = ri = pos;
        sle = sri = 1;
        ckata = 1;
    }
    void merge(const Node& a, const Node& b){
        hash.clear();
        if (st[a.ri] == ' ' || st[b.le] == ' '){
            count = a.count + b.count;
            le = a.le;
            ri = b.ri;
            sle = a.sle;
            sri = b.sri;
            if (a.hash.size()) hash.pb(a.hash[0]);
            if (b.hash.size()) hash.pb(b.hash.back());
            ckata = a.ckata + b.ckata;
            return;
        }
        count = a.count + b.count;

        // int nhh = (a.hash.back() + (1LL * b.hash[0] * pw[a.sri]) % MOD) % MOD;
        ll nhh = gab_hash(a.hash.back(), b.hash[0], a.sri);
        ckata = a.ckata + b.ckata - 1;
        if (cek(a.hash.back())) count--;
        if (cek(b.hash[0])) count--;
        if (cek(nhh)) count++;
        le = a.le;
        ri = b.ri;
        sle = a.sle;
        sri = b.sri;
        if (a.ckata > 1) hash.pb(a.hash[0]);
        hash.pb(nhh);
        if (b.ckata > 1) hash.pb(b.hash.back());
        if (a.ckata == 1 && a.sle){
            sle = a.sle + b.sle;
        }
        if (b.ckata == 1 && b.sri){
            sri = a.sri + b.sri;
        }
    }
};

Node t[4 * M];
void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = Node(st[tl], tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v].merge(t[v * 2], t[v * 2 + 1]);
}
void update(int v, int tl, int tr, int pos, char nc){
    if (tr < pos || pos < tl) return;
    if (tl == tr){
        st[pos] = nc;
        t[v] = Node(nc, tl);
        return;
    } 
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, pos, nc);
    update(v * 2 + 1, tm + 1, tr, pos, nc);
    t[v].merge(t[v * 2], t[v * 2 + 1]);
}
Node ask(int v, int tl, int tr, int l, int r){
    if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (r < tl || tm < l){
        return ask(v * 2 + 1, tm + 1, tr, l, r);
    } else if (r < tm + 1 || tr < l){
        return ask(v * 2, tl, tm, l, r);
    }
    Node ret;
    ret.merge(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    {
        cin.ignore();
        getline(cin, st);
        len = st.size();
        stringstream ss(st);
        string temp;
        while (ss >> temp){
            katas.pb(temp);
        }
        for (int i=1;i<=m;i++){
            pre[i] = pre[i - 1] + katas[i - 1].size();
            if (i != 1) pre[i]++;
        }
    }    
    init_base();
    cin >> n >> q;
    while (n--){
        string s;
        cin >> s;
        ada[get_hash(s)] = 1;
    }
    build(1, 0, len - 1);

    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 0){
            int i, j;
            char nc;
            cin >> i >> j >> nc;
            int pos = pre[i] - (int)katas[i - 1].size() + j;
            // cout << pos << el;
            update(1, 0, len - 1, pos - 1, nc);
        } else{
            int l, r;
            cin >> l >> r;
            cout << ask(1, 0, len - 1, l - 1, r - 1).count << el;
        }
    }

    return 0;
}