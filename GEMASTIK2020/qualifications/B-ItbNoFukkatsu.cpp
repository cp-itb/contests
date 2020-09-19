/**
 * Contest  : GEMASTIK 2020 Qualification
 * Team     : ItbNoFukkatsu
 * Author   : Muhammad Kamal Shafi
 * Problem  : B
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

const int N = 100;

int n, m;
string ar[N];

pii daw, cep;
bool vis[N][N];

int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};

void bfs(pii aw){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            vis[i][j] = 0;
        }
    }
    vis[aw.fi][aw.se] = 1;
    queue<pii> qu;
    qu.push(aw);
    while (!qu.empty()){
        auto node = qu.front();
        qu.pop();
        for (int i=0;i<4;i++){
            int nr = node.fi + di[i];
            int nc = node.se + dj[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m){
                if (vis[nr][nc] || ar[nr][nc] == 'x') continue;
                vis[nr][nc] = 1;
                qu.push(mp(nr, nc));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin.ignore();
    for (int i=0;i<n;i++){
        getline(cin, ar[i]);
        for (int j=0;j<m;j++){
            if (ar[i][j] == '|' || ar[i][j] == '-') ar[i][j] = 'x';
            else if (ar[i][j] == 'D') daw = mp(i, j);
            else if (ar[i][j] == 'C') cep = mp(i, j); 
        }
    }   
    bfs(daw);
    if (vis[cep.fi][cep.se]) cout << "Dawala bertemu Cepot" << el;
    else cout << "Dawala tidak bertemu Cepot" << el;
    bfs(cep);
    bool ok = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && vis[i][j]) ok = 1;
        }
    }
    if (ok) cout << "ada jalan Cepot lumpat" << el;
    else cout << "tidak ada jalan Cepot lumpat" << el;

    return 0;
}