#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int best = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    if (s[i] == 'a') {
      while (j + 1 < n && s[j + 1] == 'a') {
        j++;
      }
      best = max(best, j - i + 1);
    }
    j = i;
  }
  for (int i = 0; i <= best; i++) printf("a"); printf("\n");
  return 0;
}
