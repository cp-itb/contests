/**
 * Contest : COMPFEST 2017 Practice Session Final
 * Team    : RemahanMalkist
 * Author  : Yonas Adiel Wiguna
 * Problem : B - Palindromisme
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100005];
int cnt[50];

void percase() {
  int n;
  memset(cnt, 0, sizeof cnt);
  scanf("%d",&n);
  scanf("%s",s);


  for (int i=0; i<n; i++) {
    cnt[s[i] - 'a']++;
  }

  int ans = 0;
  for (int i=0; i<26; i++) {
    ans = max(ans, cnt[i]);
  }
  printf("%d\n", n-ans);
}

int main() {
  int t;
  scanf("%d",&t);
  while (t--) {
    percase();
  }
}