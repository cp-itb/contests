/**
 * Contest  : COMPFEST 2020 Qualification
 * Team     : Yonko -1
 * Author   : Kinantan Arya Bagaspati
 * Problem  : Distribudi Kelompok
 */ 

#include<bits/stdc++.h>
using namespace std;

long long n, f[1000069], b[1000069];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long mod=998244353;
    f[0]=1;
    b[0]=0;
    for(int i=1; i<1000069; i++){
        f[i] = (f[i-1]*i)%mod;
        b[i]=0;
    }
    cin >> n;
    long long a[n], bil, seb;
    bil=0;
    seb=1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[a[i]]++;
        bil = bil+a[i];
        seb = (seb*f[a[i]])%mod;
    }
    bil = f[bil];
    for(int i=1; i<1000069; i++){
        seb = (seb*f[b[i]])%mod;
    }
    long long pw[30], cur, fer;
    fer = mod-2;
    pw[0]=seb;
    for(int i=1; i<30; i++){
        pw[i] = (pw[i-1]*pw[i-1])%mod;
    }
    seb=1;
    cur=0;
    while(fer>0){
        if(fer%2==1){
            seb = (seb*pw[cur])%mod;
        }
        cur++;
        fer = fer/2;
    }
    cout << ((bil*seb)%mod) << endl;
}