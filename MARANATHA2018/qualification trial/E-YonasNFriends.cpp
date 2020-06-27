/**
 * Contest : Maranatha 2018 Qualification Trial
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : E - Rails
 */
#include <cstdio>
#include <stack>
using namespace std;

int n;
int arr[1005];
stack<int> st;

void f() {
  while (true) {
    scanf("%d",&arr[0]);
    if (arr[0] != 0) {
      for (int i=1; i<n; i++) { scanf("%d",&arr[i]); }

      int cur = 0;
      int cur_st = 1;

      while (cur < n && cur_st <= n) {
        st.push(cur_st++);

        while (!st.empty() && st.top() == arr[cur]) {
          //printf("DEBUG : st %d arr %d\n",st.top(), arr[cur]);
          st.pop();
          cur++;
        }
      }

      if (st.empty()) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }

    } else {
      printf("\n");
      break;
    }

    while (!st.empty()) {
      st.pop();
    }
  }
}

int main() {
  while (true) {
    scanf("%d",&n);
    if (n!=0) {
      f();
    } else {
      break;
    }
  }
}