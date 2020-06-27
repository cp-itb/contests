/**
 * Contest : INC 2018
 * Team    : Ainge ST
 * Author  : Alfonsus Raditya Arsadjaja
 * Problem : D - Substring Permutation
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int countS[30];
int countP[30];

string s, p;
int main(){
  ios::sync_with_stdio(false);
  cin >> s >> p;
  for(int i = 0;i < (int) s.length(); ++i){
    countS[s[i] - 'a']++;
  }
  for(int i = 0;i < (int) p.length(); ++i){
    countP[p[i] - 'a']++;
  }
  for(int i = 0;i < 26; ++i){
    if(countP[i] > countS[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
