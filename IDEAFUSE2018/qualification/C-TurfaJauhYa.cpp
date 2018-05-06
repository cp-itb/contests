#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define INF 1000000
#define DEBUG if (debug)
using namespace std;

const bool debug = false;
int n,m,c;
char dummy;
int pet[105][105];

pair<int,int> dp[105][5][1005];
pair<int,int> min2(pair<int,int> a, pair<int,int> b) {
  if (a.first == b.first) {
    if (a.second < b.second) return b;
    else return a;
  } else {
    if (a.first < b.first) return a;
    else return b;
  }
}

pair<int,int> play(int level, bool left, int rem) {
  pair<int,int> &ret = dp[level][left][rem];
  if (ret.first != -1) return ret;

  if (level == n+1) {
    if (rem == 0) {
      ret = mp(0, 0);
    } else {
      ret = mp(INF, 0);
    }
  } else {
    int sum = 0;
    for (int j=0; j<m; j++)
      if (pet[level][j] > 0)
        sum += pet[level][j] - '0';

    pair<int,int> t1, t2;
    t1 = play(level+1, left, rem);             t1.first += 1;
    t2 = play(level+1, !left, max(0,rem-sum)); t2.first += m + 2; t2.second += sum;
    ret = min2(t1, t2);

    int summ = 0;
    for (int j=0; j<m; j++) {
      if (pet[level][j] > '0' && pet[level][j] <= '9') {
        int oldsum = summ;
        summ += pet[level][j] - '0';
        if (left) {
          t1 = play(level+1, left, max(0, rem - summ)); t1.first += 2 * (j + 1) + 1; t1.second += summ;
          ret = min2(ret, t1);
        } else {
          t1 = play(level+1, left, max(0, rem - (sum - oldsum))); t1.first += 2 * (m - j) + 1; t1.second += sum - oldsum;
          ret = min2(ret, t1);
        }
      }
    }
  }
  //for (int i=0; i< level; i++) printf(" "); printf("%d %d %d <%d,%d>\n", level, left, rem, ret.first, ret.second);
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d%d\n", &n,&m,&c);
  for (int i=n; i>=1; i--) {
    scanf("%c", &dummy);
    for (int j=0; j<m; j++) {
      scanf("%c", &pet[i][j]);
    }
    scanf("%c\n", &dummy);
  }
  pair<int,int> t = play(1, true, c);
  printf("%d\n", t.first-1);
}