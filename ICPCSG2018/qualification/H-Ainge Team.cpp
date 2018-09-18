/**
 * Contest : ICPC SG 2018 - Qualification
 * Team    : Ainge Team
 * Author  : Luqman Arifin
 * Problem : H - Bee House Perimeter
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 60;

int ada[2 * N][2 * N], out[2 * N][2 * N];
int r, k;

vector<pair<int, int>> edge[2 * N][2 * N];

pair<int, int> r_to_r1(int i, int j) {
  return make_pair(i + 1, j + 1);
}

pair<int, int> num_to_r(int num) {
  num--;
  int row = 0;
  for (int now = 0; now < k; now++) {
    int s = k + now;
    if (num < s) {
      return make_pair(row, num);
    }
    row++;
    num -= s;
  }
  for (int now = k - 2; now >= 0; now--) {
    int s = k + now;
    if (num < s) {
      return make_pair(row, num);
    }
    row++;
    num -= s;
  }
}

bool valid(int i, int j) {
  return 0 <= i && i < 2 * N && 0 <= j && j < 2 * N;
}

void dfs(int i, int j) {
  if (ada[i][j]) return;
  if (out[i][j]) return;
  out[i][j] = 1;
  for (auto it : edge[i][j]) {
    dfs(it.first, it.second);
  }
}

void add(int i, int j, int p, int q) {
  if (valid(i, j) && valid(p, q)) {
    edge[i][j].emplace_back(p, q);
    edge[p][q].emplace_back(i, j);
  }
}

int main() {
  int value;
  scanf("%d %d", &k, &value);
  for (int i = 0; i < value; i++) {
    int v;
    scanf("%d", &v);
    auto it = num_to_r(v);
    // printf("bef %d %d\n", it.first, it.second);
    it = r_to_r1(it.first, it.second);
    ada[it.first][it.second] = 1;
    // printf("%d %d\n", it.first, it.second);
  }
  /** generate edge **/

  // bawah dan atas
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 2 * N; j++) {
      add(i, j, i + 1, j);
      add(i, j, i + 1, j + 1);
    }
  }
  for (int i = k; i < 2*k; i++) {
    for (int j = 0; j < 2 * N; j++) {
      add(i, j, i + 1, j);
      add(i, j, i + 1, j - 1);
    }
  }

  // samping
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < 2 * N; j++) {
      add(i, j, i, j + 1);
    }
  }

  // generate donat
  dfs(0, 0);
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < 2 * N; j++) {
      if (!out[i][j] && !ada[i][j]) {
        ada[i][j] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < 2 * N; j++) {
      if (ada[i][j] == 0) continue;
      for (auto it : edge[i][j]) {
        int x = it.first;
        int y = it.second;
        if (ada[x][y] == 0) {
          ans++;
          // printf("%d %d: %d %d\n", i, j, it.first, it.second);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
