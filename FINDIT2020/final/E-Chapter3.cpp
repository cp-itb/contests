/**
 * Contest : FINDIT 2020
 * Team    : Chapter3
 * Author  : Muhammad Kamal Shafi
 * Problem : E - WA Image
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

const int N = 60, K = 10;

struct subfolder{
    string nama;
    int cnt = 0;
    vector<string> foto;
    subfolder() {};
};

bool comp(const subfolder& a, const subfolder& b){
    return (a.nama < b.nama);
}

int n, k;
unordered_map<string, bool> ada;

subfolder ar[N];

void prints(const vector<string>& s){
    for (int i=0;i<k;i++){
        for (int j=0;j<k;j++){
            cout << s[i][j];
        }
        cout << el;
    }
}

vector<string> rot90(const vector<string>& s){
    vector<string> ret(k);

    for (int i=0;i<k;i++){ // kolom
        for (int j=k - 1;j>=0;j--){
            ret[i].pb(s[j][i]);
        }
    }
    return ret;
}

string vec_to_string(const vector<string>& s){
    string ret;
    for (auto x : s){
        for (auto y : x){
            ret.pb(y);
        }
    }
    return ret;
}

string get_canon(vector<string> s){
    string ret = vec_to_string(s);

    for (int i=0;i<3;i++){
        s = rot90(s);
        ret = min(ret, vec_to_string(s));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        int len;
        cin >> ar[i].nama; 
        cin >> len;
        for (int j=0;j<len;j++){
            vector<string> vec;
            for (int kk=0;kk<k;kk++){
                string temp;
                cin >> temp;
                vec.pb(temp);
            }
            string temp2 = get_canon(vec);
            ar[i].foto.pb(temp2);
        }
    }
    sort(ar + 1, ar + n + 1, &comp);
    for (int i=1;i<=n;i++){
        for (auto x : ar[i].foto){
            if (ada[x]) continue;
            ada[x] = 1;
            ar[i].cnt++;
        }
    }
    for (int i=1;i<=n;i++){
        cout << ar[i].nama << " " << ar[i].cnt << el;
    }

    return 0;
}