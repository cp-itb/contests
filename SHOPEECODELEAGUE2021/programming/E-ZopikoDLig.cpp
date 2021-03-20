/**
* Contest : Shopee Code League 2021
* Team    : ZopikoDLig
* Author  : Muhammad Kamal Shafi
* Problem : E
* (Partial Score)
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
 
const int D = 1e3 + 10;
const int K = 12;
const int WD = 7;
 
int d;
int C[K + 22][WD + 2];
 
vector<vector<int>> adj = {
    {},
    {22,25,26,27,28}, //1
    {17,19,21,22,25}, //2
    {18,19,22,23,26}, //3
    {14,15,17,18,19}, //4
    {23,24,26,28,30}, //5
    {20,21,25,27,29}, //6
    {27,28,29,30,31}, //7
    {13,14,17,20,21}, //8 
    {15,16,18,23,24}, //9
    {13,14,15,16,32}, //10
    {16,24,30,31,32}, //11
    {13,20,29,31,32}, //12
    {10,14,8,20,12,32}, //13
    {13,10,15,4,17,8}, //14
    {10,16,9,18,4,14}, //15
    {10,15,9,24,11,32}, //16
    {14,4,19,2,21,8}, //17
    {4,15,9,23,3,19}, //18
    {17,4,18,3,22,2}, //19
    {8,21,6,29,12,13}, //20
    {8,17,2,25,6,20}, //21
    {2,19,3,26,1,25}, //22
    {3,18,9,24,5,26}, //23
    {9,23,5,30,11,16}, //24
    {21,2,22,1,27,6}, //25
    {22,3,23,5,28,1}, //26
    {25,1,28,7,29,6}, //27
    {1,26,5,30,7,27}, //28
    {20,6,27,7,31,12}, //29
    {28,5,24,11,31,7}, //30 
    {12,29,7,30,11,32}, //31
    {10,16,11,31,12,13} //32
};
unordered_map<string, int> dp[2];
 
int lastid[K + 22];
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> d;
    for (int i=1;i<=12;i++){
        for (int j=1;j<=7;j++){
            cin >> C[i][j];
        }
    }
    fill(lastid, lastid + K + 22, 7);
    {
        string temp = "";
        for (auto x : {22, 0, 0, 0, 0, 0}){
            temp.pb(char(x));
        }
        dp[0][temp] = 0;
    }
    int ans = 0;
    for (int i=1;i<=d;i++){
        int cur = (i & 1); // current
        int bef = (cur ^ 1); // before
 
        for (auto &keyval : dp[bef]){
            int node = (int)keyval.fi[0];
            for (int j=5;j>=0;j--){
                lastid[(int)keyval.fi[j]] = j + 1;
            }
            for (auto &nnode : adj[node]){
                string nstate = "";
                nstate.pb((char)nnode);
                for (int j=0;j<5;j++){
                    nstate.pb((char)keyval.fi[j]);
                }
                int temp;
                temp = dp[cur][nstate] = max(dp[cur][nstate], keyval.se + C[nnode][lastid[nnode]]);
                ans = max(ans, temp);
            }
            for (int j=5;j>=0;j--){
                lastid[(int)keyval.fi[j]] = 7;
            }
        }
        dp[bef].clear();
    }
    cout << ans << el;
 
    return 0;
}
Language: C++14