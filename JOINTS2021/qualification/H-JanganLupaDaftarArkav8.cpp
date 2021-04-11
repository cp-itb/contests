 /**
  * Contest : Joints 2021 Qualification
  * Team    : Jangan Lupa Daftar Arkav 8
  * Author  : Marcello Faria
  * Problem : H - Aliansi
  */


#include <bits/stdc++.h>
using namespace std;

int n; 
vector<int>adj[1005]; 
vector<int>adjl[1005];
int nodeW[1005];
int nodeWeight[1005];
int N,M,nodeSource,nodeDest;
int dp[1005];
vector<bool> vis,reachable;
vector<int> ans;

void dfs(int v) 
{
    vis[v] = true;
    for (auto u : adj[v]) 
    {
        if (!vis[u])
        {
            dfs(u);
        }
    }
    ans.push_back(v);
}

void dfs2(int v) 
{
    reachable[v] = true;
    for (auto u : adj[v]) 
    {
        if (!reachable[u])
        {
            dfs2(u);
        }
    }
}

void toposort() 
{
    vis.assign(N, 0);
    ans.clear();
    for (int i = 0; i < N; ++i) 
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);   
   cin>>N>>M;
   for(int i = 0;i<N;i++)
   {
    cin>>nodeWeight[i];
   }
   for(int i = 0;i<M;i++)
   {
    int u,v;
    cin>>u>>v;
    adj[--u].push_back(--v);
    adjl[v].push_back(u);
   }    
   cin>>nodeSource>>nodeDest;
   --nodeSource;
   --nodeDest;
   toposort();
   reachable.assign(N, 0);
   dfs2(nodeSource);

   for(int i = 0;i<N;i++)
   {
    dp[i] = -(1e9+7);
   }

   dp[nodeSource] = nodeWeight[nodeSource];
   for(int v : ans)
   {
       for(int u : adjl[v])
       {
        if(reachable[u])
        {
            dp[v] = max(dp[u] + nodeWeight[v],dp[v]);
        }
       }
   }
   int ans = -1;
   for(int x : adjl[nodeDest])
   {
    ans = max(ans,dp[x]);
   }
   if(ans <= nodeWeight[nodeDest]) 
   {
       cout<<"TIDAK"<<endl;
   }
   else
   {
        cout<<"YA "<< ans <<endl;
   }
   return 0;
}