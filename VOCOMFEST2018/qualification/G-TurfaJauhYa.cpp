/**
 * Contest : VOCOMFEST 2018 Qualification
 * Team    : TurfaJauhYa
 * Author  : Turfa Auliarachman
 * Problem : G - Schedule
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Time {
public:
  ll second;

  Time() {
    second = 0;
  }

  Time(ll year, ll month, ll day, ll hour, ll minute, ll second_x) {
    month += year * 20 - 1;
    day += month * 50 - 1;
    hour += day * 24;
    minute += hour * 60;

    second = second_x + minute * 60;
  }

  bool operator<(Time sana) {
    return second < sana.second;
  }

  bool operator>(Time sana) {
    return second > sana.second;
  }
};

class Interval {
public:
  Time satu;
  Time dua;

  Interval(Time x, Time y) {
    satu = x;
    dua = y;
  }

  bool tabrakan(Interval sana) {
    return (!((sana.satu < satu && sana.dua < satu) || (sana.satu > dua && sana.dua > dua)));
  }
};

int main() {
  ll t;
  cin >> t;

  for (ll kas = 1; kas <= t; kas++) {
    vector<Interval> p;

    for (ll i = 0; i < 4; i++) {
      ll d1, m1, y1, h1, mi1, s1, d2, m2, y2, h2 ,mi2, s2;

      cin >> d1 >> m1 >> y1 >> h1 >> mi1 >> s1 >> d2 >> m2 >> y2 >> h2 >> mi2 >> s2;

      p.push_back(Interval(Time(y1, m1, d1, h1, mi1, s1), Time(y2, m2, d2, h2, mi2, s2)));
    }

    bool tab = false;
    for(ll i = 0; i < 3; i++) {
      if (p[3].tabrakan(p[i])) {
        tab = true;
      }
    }

    if (tab) {
      cout << "Case #" << kas << ": COLLIDE" << endl;
    }
    else {
      cout << "Case #" << kas << ": OK" << endl;
    }
  }
}
