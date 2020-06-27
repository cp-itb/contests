/**
 * Contest : IDEAFUSE 2018 Qualification
 * Team    : ISeetheOne
 * Author  : Devin Alvaro
 * Problem : D - Aota and Tournament
 */

#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, string> &a, const pair<int, string> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    for (int i = 0; i < 8; i++) {
        string team;
        cin >> team;
    }

    map<string, int> wins;
    for (int i = 0; i < 28; i++) {
        string team1, team2, dash;
        int score1, score2;

        cin >> team1 >> score1 >> dash >> score2 >> team2;

        string winner;
        if (score1 > score2) {
            winner = team1;
        } else {
            winner = team2;
        }

        if (wins.find(winner) == wins.end()) {
            wins[winner] = 1;
        } else {
            wins[winner] += 1;
        }
    }

    vector<pair<int, string>> result;
    for (auto it = wins.begin(); it != wins.end(); it++) {
        result.push_back({it->second, it->first});
    }

    sort(result.begin(), result.end(), cmp);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i].second << ' ' << result[i].first << '\n';
    }

    return 0;
}
