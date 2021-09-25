/**
 * Contest : Ideafuse 2021 Final
 * Team    : Computer Saiyans
 * Author  : Marcello Faria
 * Problem : A - Indivisible Bracket
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    int tot = INT_MIN;
    int curr = 0;
    string str;
    cin >> str;
    map<int, int> mp;
    int cur = 0;
    int ans = 0;
    mp[0] = -1;
    for (int j=0; j<str.size(); j++){
      cur += (str[j] == '(' ? 1 : -1);
      if (str[j] == ')' && mp.count(cur)) ans = max(ans, j - mp[cur]);
      mp[cur] = j;
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
}