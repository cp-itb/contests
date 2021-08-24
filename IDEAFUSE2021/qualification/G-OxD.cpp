/**
 * Contest : Ideafuse 2021 Qualification
 * Team    : OxD
 * Author  : Marcello Faria
 * Problem : G - Pokemon Battle
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T, N;
  cin >> T;
  double chart[5][5] = {{0.5, 0.5, 2, 1, 1}, {2, 0.5, 0.5, 2, 1}, {0.5, 2, 0.5, 2, 0.5}, {2, 1, 0.5, 1, 0}, {1, 1, 2, 1, 1}};
  string type[5] = {"FIRE", "WATER", "GRASS", "GROUND", "FLYING"};
  for (int t = 1; t <= T; t++)
  {
    string ans, str1, str2;
    int x, y;
    cin >> str1 >> str2;
    for (int i = 0; i < 5; i++)
    {
      if (str1 == type[i])
      {
        x = i;
      }
      if (str2 == type[i])
      {
        y = i;
      }
    }
    if (chart[x][y] == 0)
    {
      ans = "not effective";
    }
    else if (chart[x][y] == 0.5)
    {
      ans = "not very effective";
    }
    else if (chart[x][y] == 1)
    {
      ans = "effective";
    }
    else if (chart[x][y] == 2)
    {
      ans = "super effective";
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}