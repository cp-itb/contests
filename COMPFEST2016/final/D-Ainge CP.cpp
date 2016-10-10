/**
 * Contest : COMPFEST 2016 Final
 * Team    : Ainge CP
 * Author  : Luqman Arifin
 * Problem : D
 */

#include <bits/stdc++.h>

using namespace std;

string normalize(string str) {
  string ret = str;
  for (int i = 0; i < ret.size(); i++) {
    if ('A' <= ret[i] && ret[i] <= 'Z') {
      ret[i] = ret[i] - 'A' + 'a';
    }
  }
  return ret;
}

vector<string> parse(string buf) {
  stringstream ss(buf);
  string buffer;
  vector<string> ret;
  while (ss >> buffer) {
    ret.push_back(normalize(buffer));
  }
  return ret;
}

map<string, vector<int>> MP;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  int id = 0;
  for (int i = 0; i < n; i++) {
    string buffer;
    getline(cin, buffer);
    vector<string> ret = parse(buffer);
    for (auto it : ret) {
      MP[it].push_back(id++);
    }
  }
  int q;
  cin >> q;
  cin.ignore();
  while (q--) {
    string query;
    getline(cin, query);
    vector<string> ret = parse(query);
    int id = 0;
    bool done = 0;
    for (auto it : ret) {
      if (!MP.count(it)) {
        puts("gagal");
        done = 1;
        break;
      }
      int at = lower_bound(MP[it].begin(), MP[it].end(), id) - MP[it].begin();
      if (at == MP[it].size()) {
        puts("gagal");
        done = 1;
        break;
      }
      id = MP[it][at] + 1;
      //printf("%d ", id);
    }
    if (!done) puts("berhasil");
  }

  return 0;
}