/**
 * Contest : COMPFEST 2016 Qualification
 * Team    : Ainge CP
 * Author  : Wiwit Rifa'i
 * Problem : C - Menyelamatkan Mbak Miku
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e6  + 5;
pair< long long, pair< int, int > > val[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int r, c;
    long long k, h;
    scanf("%d %d %lld %lld", &r, &c, &k, &h);
    int n = 0, rc = r * c;
    if (r == 1 || c == 1) {
      if (rc > 200) {
        for (int i = 1; i <= 100; i++)
          printf("%07d\n", ((((i * k) % rc) + h) % rc) + 1);
        for (int i = rc - 99; i <= rc; i++)
          printf("%07d\n", ((((i * k) % rc) + h) % rc) + 1);
      }
      else {
        for (int i = 1; i <= rc; i++)
          printf("%07d\n", ((((i * k) % rc) + h) % rc) + 1);
      }
      continue;
    }
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        val[n++] = {((((((c * (i-1) + j) % rc) * k) % rc) + h) % rc) + 1, {i, j}}; 
      }
    }
    sort(val, val+n);
    set < pair< int, int > > st;
    st.clear();
    int cnt = r + c - 1;
    for (int i = 0; i < n; i++) {
      if (st.size() >= cnt)
        break;
      auto it = st.lower_bound(val[i].second);
      bool ok = true;
      if (it != st.end() && it->second < val[i].second.second)
        ok = false;
      if (it != st.begin()) {
        it--;
        if (it->second > val[i].second.second)
          ok = false;
      }
      if (ok)
        st.insert(val[i].second);
    }
    assert(st.size() == cnt);
    if (st.size() <= 200) {
      for (auto it = st.begin(); it != st.end(); it++) {
        int id = ((((((c * ((it->first)-1) + it->second) % rc) * k) % rc) + h) % rc) + 1;
        printf("%07d\n", id);
      }
    }
    else {
      int baris = 0;
      for (auto it = st.begin(); it != st.end() && baris < 100; it++) {
        int id = ((((((c * ((it->first)-1) + it->second) % rc) * k) % rc) + h) % rc) + 1;
        printf("%07d\n", id);        
        baris++;
      }
      auto it = st.end();
      baris = 100;
      while(baris--)
        it--;
      baris = 0;
      for (; it != st.end(); it++) {
        int id = ((((((c * ((it->first)-1) + it->second) % rc) * k) % rc) + h) % rc) + 1;
        printf("%07d\n", id);        
        baris++;        
      }
      assert(baris == 100);
    }
  }

  return 0;
}