/**
 * Contest : VOCOMFEST 2018 Final
 * Team    : I See The One
 * Author  : Tony / Dicky Novanto
 * Problem : G - Moving Lines
 */

#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define baca getchar_unlocked

typedef long long ll;
 
const ll mod = 1e9+9;
const double pi = acos(-1);
const int maxsz = 10;

struct point{
	ll x, y;
	point(ll a, ll b){
		x = a;
		y = b;
	}
};

struct line{
	ll a, b, c;
	line(point p1, point p2){
		a = p2.x - p1.x;
		b = p1.y - p2.y;
		c = -b*p1.x -a*p1.y;
		ll p = __gcd(llabs(a), __gcd(llabs(b),llabs(c)));
		a /= p;
		b /= p;
		c /= p;
	}
};

ll cross(point a, point b){
	return a.x*b.y - a.y*b.x;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		printf("Case #%d: ", cc);
		int x11, x12, y11, y12;
		int x21, x22, y21, y22;
		scanf("%d %d %d %d", &x11, &y11, &x12, &y12);
		scanf("%d %d %d %d", &x21, &y21, &x22, &y22);
		if(x11 > x12){
			swap(x11, x12);
			swap(y11, y12);
		}
		if(x21 > x22){
			swap(x21, x22);
			swap(y21, y22);
		}
		line l1(point(x11, y11), point(x12, y12));
		line l2(point(x21, y21), point(x22, y22));
		if((l1.a==l2.a && l1.b==l2.b && l1.c==l2.c)||(l1.a==-l2.a && l1.b==-l2.b && l1.c==-l2.c))
			puts("collinear");
		else if((l1.a==l2.a && l1.b==l2.b)||(l1.a==-l2.a && l1.b==-l2.b))
			puts("parallel");
		else{
			ll ps1 = cross(point(x12-x11,y12-y11),point(x21-x11, y21-y11));
			ll ps2 = cross(point(x12-x11,y12-y11),point(x22-x11, y22-y11));
			ll ps3 = cross(point(x22-x21,y22-y21),point(x11-x21, y11-y21));
			ll ps4 = cross(point(x22-x21,y22-y21),point(x12-x21, y12-y21));
			if(ps1==0 || ps2==0){
				if(ps3==0 || ps4==0)
					puts("none");
				else
					puts("move A");
			}
			else if(ps3==0 || ps4==0){
				puts("move B");
			}
			else if((ps1>0)^(ps2>0)){
				if((ps3>0)^(ps4>0))
					puts("none");
				else
					puts("move A");
			}
			else{
				if((ps3>0)^(ps4>0))
					puts("move B");
				else
					puts("move both");
			}
		}
	}
	return 0;
}
