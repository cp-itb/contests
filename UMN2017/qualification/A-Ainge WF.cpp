/**
 * Contest : UMN 2017 Qualification
 * Team    : Ainge WF
 * Author  : Luqman A. Siswanto
 * Problem : A - ENCODING
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 205;

char s[N];

char print(int a) {
  if (a < 26) return a + 'A';
  if (a < 52) return a - 26 + 'a';
  if (a < 62) return a - 52 + '0';
  if (a == 62) return '+';
  if (a == 63) return '/';
  assert(0);
}

int main(){
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    
    printf("Case #%d: ", tt);
    int n = strlen(s);
    for (int i = 0; i < n; i += 6) {
      int num = 0;
      for (int j = 0; j < 6; j++) {
        num = num * 2 + s[i + j] - '0';
      }
      printf("%c", print(num));
    }
    printf("\n");
  }
  
  return 0;
}
