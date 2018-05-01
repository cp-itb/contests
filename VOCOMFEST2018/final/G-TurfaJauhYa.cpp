/**
 * Contest : VOCOMFEST 2018 Final
 * Team    : Turfa Jauh Ya
 * Author  : Jauhar Arifin
 * Problem : G - Moving Lines
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LD;
inline bool eq(LD a, LD b) { return a == b; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }
struct point {
	LD x, y;
	point(LD x = 0, LD y = 0) : x(x), y(y) {}
	point operator-(const point& p) const { return point(x-p.x, y-p.y); }
	LD operator%(const point& p) const { return x*p.y - y*p.x; }
	bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
	bool operator<(const point& p) const { return eq(y, p.y)? x< p.x : y<p.y; }
};

struct line {
	point a, ab;
	line(point ta, point tb) {
		if (tb < ta) swap(ta, tb);
		a = ta; ab = tb-ta;
	}
	bool onLine(point p) {
		if (ab == point()) return a==p;
		return eq(ab % (p-a), 0);
	}
	bool areParallel(line l) {
		return eq(ab % l.ab, 0);
	}
	bool areSame(line l) {
		return areParallel(l) && onLine(l.a) && l.onLine(a);
	}
};

int ccw(point a, point b, point c) { return sign((b-a) % (c-b)); }

void solve(int tc) {
	int x1, x2, y1, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	line l1 = line(point(x1, y1), point(x2, y2));
	int x3, y3, x4, y4;
	scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
	line l2 = line(point(x3, y3), point(x4, y4));

	printf("Case #%d: ", tc);
	if (l1.areSame(l2)) {
		printf("collinear\n");
	} else if (l1.areParallel(l2)) {
		printf("parallel\n");
	} else {
		bool a = (ccw(point(x1, y1), point(x2, y2), point(x3, y3)) * ccw(point(x1, y1), point(x2, y2), point(x4, y4))) == 1;
		bool b = (ccw(point(x3, y3), point(x4, y4), point(x1, y1)) * ccw(point(x3, y3), point(x4, y4), point(x2, y2))) == 1;

		if (!a && !b) {
			printf("none\n");
		} else if (a && !b) {
			printf("move B\n");
		} else if (!a && b) {
			printf("move A\n");
		} else {
			printf("move both\n");
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		solve(i);
	}
}