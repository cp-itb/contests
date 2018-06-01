/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : TurfaJauhYa
 * Author  : Jauhar Arifin
 * Problem : B - Raon and Ice Cream
 */
#include <bits/stdc++.h>
using namespace std;

int t,n;
char s[500001];

void populate(int start, int p, int *b) {
  memset(b, 0, sizeof(int) * 26);
  for (int i=0; i<p; i++)
    b[s[start+i] - 'A'] += 1;
}

int b[26], c[26];
bool check(int p) {
  populate(0, p, b);
  for (int i=p; i<n; i+=p) {
    populate(i, p, c);
    for (int j=0; j<26; j++)
      if (b[j] != c[j])
        return 0;
  }
  return 1;
}

int main() {
  scanf("%d", &t);
  for (int tc=1; tc<=t; tc++) {
    scanf("%d", &n);
    scanf("%s", s);

    vector<int> fact;
    for (int i=1; i*i<=n; i++)
      if (n%i == 0) {
        fact.push_back(i);
        fact.push_back(n/i);
      }
    sort(fact.begin(), fact.end());
    int ans = 1;
    for (int v: fact)
      if (check(v)) {
        ans = n/v;
        break;
      }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}