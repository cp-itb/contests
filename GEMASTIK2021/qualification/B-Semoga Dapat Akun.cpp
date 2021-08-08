 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Jauhar Wibisono
  * Problem : B - Laser Iron Man
  */

#include <bits/stdc++.h>
using namespace std;

struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};

struct line{
	pt a, b;
	line() {}
	line(long long ax, long long ay, long long bx, long long by) : a(ax, ay), b(bx, by) {}
	line(pt a, pt b) : a(a), b(b) {} 
};

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

const int maxn = 1005, maxk = 105;
pt kita;
int n, k;
pt robot[maxn];
line bangunan[maxk];
int ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> kita.x >> kita.y;
	cin >> n;
	for (int i=0; i<n; i++) cin >> robot[i].x >> robot[i].y;
	cin >> k;
	for (int i=0; i<k; i++) cin >> bangunan[i].a.x >> bangunan[i].a.y >> bangunan[i].b.x >> bangunan[i].b.y;
	ans = 0;
	for (int i=0; i<n; i++){
		line tembak(kita, robot[i]);
		bool ok = 1;
		for (int j=0; j<k; j++){
			if (check_inter(tembak.a, tembak.b, bangunan[j].a, bangunan[j].b)) ok = 0;
		}
		if (ok) ans++;
	}
	cout << ans << '\n';
	return 0;
}