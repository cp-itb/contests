/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : 0xD
 * Author  : Marcello Faria
 * Problem : Antrean
 */


#include <bits/stdc++.h>
using namespace std;


#define ll long long 
const ll mod =  1e9+7;
ll factInv[100005];
ll natInv[100005];
ll fact[100005];

void InvNum()
{
    natInv[0] = natInv[1] = 1;
    for (int i = 2; i <= 100000; i++)
        natInv[i] = natInv[mod % i] * (mod - mod / i) % mod;
}

void InvFact()
{
    factInv[0] = factInv[1] = 1;
 
    for (int i = 2; i <= 100000; i++)
        factInv[i] = (natInv[i] * factInv[i - 1]) % mod;
}
 
void factorial()
{
    fact[0] = 1;
 
    for (int i = 1; i <= 100000; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
 
ll Binomial(ll N, ll R)
{
    ll ans = ((fact[N] * factInv[R]) % mod * factInv[N - R]) % mod;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    InvNum();
    InvFact();
    factorial();
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ll arrm[m],total = 0,kombin = 1, totalm = 0;
        memset(arrm,0,sizeof(arrm));
        for(int i =0;i<m;i++)
        {
            cin>>arrm[i];
            total += arrm[i];
        }
        totalm = total + (m-1);
        if(n < totalm)
        {
            cout<<"Oi oi, Jaga Jarak"<<endl;
            continue;
        }
        for(int i =0;i<m;i++)
        {
            kombin *= fact[arrm[i]];
            kombin %= mod;
        }
        n = n-2;
        cout<<(Binomial(n - total + 2, m - 1)%mod * kombin%mod)%mod <<endl;
    }
}