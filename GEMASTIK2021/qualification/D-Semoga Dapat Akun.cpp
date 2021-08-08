 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Kinantan Arya Bagaspati + Jauhar Wibisono
  * Problem : D - Sihir Loki
  */

#include<bits/stdc++.h>
using namespace std;

long long offset_pq(string s, long long m){
    // s = 10eP+Q
    long long p = 0, q = 0;
    long long pls = 0;
    while (s[pls] != '+') pls++;
    for (long long i=3; i<pls; i++){
        if (s[i] >= '0' && s[i] <= '9'){
            p *= 10;
            p += s[i]-'0';
        }
    }
    for (long long i=pls+1; i<(long long)s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            q *= 10;
            q += s[i]-'0';
        }
    }
    long long ret = 1, mul = 10;
    for (; p; p>>=1){
        if (p&1){
            ret *= mul;
            ret %= m;
        }
        mul *= mul;
        mul %= m;
    }
    ret += q;
    ret %= m;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, k, l;
    string sl;
    long long q;
    cin >> n;
    string s[n], cpy[n], dummy;
    for(long long i=0; i<n; i++) cin >> s[i];
    cin >> q;
    for (long long qq=0; qq<q; qq++){
        //Mulai cycle
        cin >> k >> sl;
        long long source, target[n];
        bool vis[n];
        for(long long i=0; i<n; i++){
            vis[i] = false;
            target[i] = i;
        }
        while(k--){
            cin >> source >> dummy;
            source--;
            cin >> target[source];
            target[source]--;

        }
        for(long long i=0; i<n; i++){
            if(!vis[i]){
                vector<long long> cycle;
                long long cur = i;
                cycle.push_back(cur);
                vis[cur] = true;
                while(target[cur]!=i){
                    cur = target[cur];
                    vis[cur] = true;
                    cycle.push_back(cur);
                }
                long long sz = cycle.size();
                if (sl.length() < 3 || sl[2] != 'e') l = stoll(sl)%sz;
                else l = offset_pq(sl, sz);
                for(long long j=0; j<sz; j++){
                    cpy[cycle[(l + j)%sz]] = s[cycle[j]];
                }
            }
        }
        for(long long i=0; i<n; i++){
            cout << cpy[i] << " ";
        }
        cout << '\n';
    }
}