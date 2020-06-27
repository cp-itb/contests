/**
 * Contest : COMPFEST 2018 Qualification
 * Team    : Tukang Nasi Goreng
 * Author  : Wiwit Rifa'i
 * Problem : D - Memperpanjang Barisan 
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int a[N];
int lis[N], lds[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int nn = n * n;
    for (int i = 0; i < nn; ++i) {
      scanf("%d", a+i);
    }
    int p = 0;
    for (int i = 0; i < nn; ++i) {
      int id = lower_bound(lis, lis+p, a[i]) - lis;
      lis[id] = a[i];
      p += id == p;
    }
    int q = 0;
    for (int i = 0; i < nn; ++i) {
      int id = lower_bound(lds, lds+q, -a[i]) - lds;
      lds[id] = -a[i];
      q += id == q;
    }
    if (p > n || q > n) {
      puts("0");
    }
    else {
      assert(p == n && q == n);
      set<int> st;
      for (int i = 0; i < nn; ++i) {
        if (a[i] > 0)
          st.insert(a[i]);
        st.insert(i+1);
        if (a[i]+1 > 0)
          st.insert(a[i]+1);
      }
      st.insert(nn+1);
      for (int i = 0; i < nn; ++i)
        st.erase(a[i]);
      int v = *st.begin();
      if (v < -lds[q-1]) {
        printf("1\n%d\n", v);
      }
      else {
        auto it = st.upper_bound(lis[p-1]);
        assert(it != st.end());
        printf("1\n%d\n", *it);
      }
    }
  }
  return 0;
}
