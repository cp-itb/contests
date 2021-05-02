 /**
  * Contest : Joints 2021 Final
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Marcello Faria
  * Problem : K - Dua Kubu
  */

#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
ll knapSack(ll W, ll wt[], ll val[], ll n)
{
    int i,j;
    ll dp[n+1][W+1];
 	
 	for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
        	dp[i][j] = 0;
       	}
    }
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)  
            {
                dp[i][j] = 0;
            } 
            else if (wt[i - 1] <= j)  
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            if(i>0)
            	dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    return dp[n][W];
}

int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);   
   
   ll E,W;
   ll Ae,Be,Aw,Bw,tot1 = 0,tot2 = 0;
   ll saya[1005],musuh[1005];
   cin>>E>>W;
   cin>>Aw>>Bw;
   for(int i = 0;i<Aw;i++)
   {
   	cin>>saya[i];
   	tot1+=saya[i];
   }
   cin>>Ae>>Be;
   for(int i = 0;i<Ae;i++)
   {
   	cin>>musuh[i];
   	tot2+=musuh[i];
   }
   ll me = knapSack(Bw,musuh,musuh,Ae);
   ll him = knapSack(Be,saya,saya,Aw);
   ll totme = E+me+(tot1-him);
   ll tothim = W+him+(tot2-me);

   if(totme > tothim) {
   	cout<<"Menang"<<endl;
   	cout<<totme<<" "<<tothim<<endl;
   } 
   else if(totme == tothim) {
   	cout<<"Seri"<<endl;
   	cout<<totme<<" "<<tothim<<endl;
   }
   else {
   	cout<<"Kalah"<<endl;
   	cout<<totme<<" "<<tothim<<endl;
   }
   return 0;
}