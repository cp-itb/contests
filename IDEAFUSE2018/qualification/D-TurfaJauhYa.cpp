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
#define DEBUG if (debug)
using namespace std;

const bool debug = false;

map<string, int> score;
pair<int, string> t[10];

bool desc(pair<int, string> a, pair<int, string> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  } return a.first > b.first;
}

int main() {
  for (int i=0; i<8; i++) {
    cin >> t[i].second;
    score[t[i].second] = 0;
  }

  string t1, t2, s1, s2;
  for (int i=0; i<28; i++) {
    cin >> t1 >> s1 >> t2 >> s2 >> t2;
    if (s1 == "2") {
      score[t1]++;
    } else if (s2 == "2") {
      score[t2]++;
    }
  }

  for (int i=0; i<8; i++) {
    t[i].first = score[t[i].second];
  }
  sort(t, t+8, desc);
  for (int i = 0; i<8; i++) {
    cout << t[i].second << " " << t[i].first << "\n";
  }
}