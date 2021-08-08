 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : DryCr1TiKaL
  * Author  : Jun Ho Choi Hedyatmo
  * Problem : C - Portal dan Monster
  */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k, val[N];
bool vis[N];
vector<int> adj[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> val[i];
  }

  for(int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  vector<long long> vc;
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      int sum = 0;
      vis[i] = 1;
      q.push(i);
      while(!q.empty()) {
        int fr = q.front();
        q.pop();
        sum += val[fr];

        for(auto x : adj[fr]){
          if(!vis[x]){
            vis[x] = 1;
            q.push(x);
          }
        }
      }
      vc.push_back((long long) sum);

    }
  }

  sort(vc.begin(), vc.end());

  long long g = vc.size();

  long long ans = 0;
  for(auto x : vc) {
    ans += g * x;
    g--;
  }

  cout << ans << '\n';



  return 0;
}