/**
 * Contest : INC 2016
 * Team    : Ainge WF
 * Author  : Aufar Gilbran
 * Problem : I - Irpin's Walk
 */

#include <bits/stdc++.h>

using namespace std;

#define INF 100000000000LL
#define MAXN 10000
#define MAXLOG 27

long long dist[MAXN+5][MAXLOG+5];
vector<int> edge[MAXN+5], cost[MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {
        int n, m, a, b;
        scanf("%d%d%d%d", &n, &m, &a, &b);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= MAXLOG; ++j) dist[i][j] = INF;
            edge[i].clear();
            cost[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back(v);
            cost[u].push_back(w);
            edge[v].push_back(u);
            cost[v].push_back(w);
        }

        priority_queue<pair<long long, pair<int, int> > > PQ;
        PQ.push(make_pair(0, make_pair(a, 0)));
        dist[a][0] = 0;
        while (!PQ.empty()) {
            pair<int, pair<int,int> > top = PQ.top();
            PQ.pop();
            long long d = -top.first;
            int v = top.second.first;
            int r = top.second.second;
            /* printf("%d %d %d\n", d, v, r); */
            if (dist[v][r] != d) continue;
            int nr = min(r+1, MAXLOG);
            for (int i = 0; i < edge[v].size(); ++i) {
                int u = edge[v][i];
                int c = cost[v][i];
                //printf("%d %d %d\n", u, d, c);
                if (dist[u][nr] > d + c) {
                    dist[u][nr] = d + c;
                    PQ.push(make_pair(-(d+c), make_pair(u, nr)));
                }
            }
        }
        long long ans = INF;
        for (int i = 0; i <= MAXLOG; ++i) {
            ans = min(ans, (((1LL<<i) <= dist[b][i]) ? dist[b][i]*2 : dist[b][i]));
        }
        printf("Case #%d: ", itc);
        if (ans == INF) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}
