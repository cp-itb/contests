/**
 * Contest : Maranatha 2018 Qualification
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : C - Academic Journal
 */
#include <bits/stdc++.h>
#define book pair<string, pair<string, pair<string, pair<int, pair<int, int> > > > >
#define f1 first
#define f2 second.first
#define f3 second.second.first
#define f4 second.second.second.first
#define f5 second.second.second.second.first
#define f6 second.second.second.second.second
using namespace std;

book a[1000];
char dmp;

bool comp(book u, book v) {
    if (u.f3 != v.f3) { return u.f3 < v.f3; }
    if (u.f6 != v.f6) { return u.f6 < v.f6; }
    if (u.f4 != v.f4) { return u.f4 < v.f4; }
    if (u.f5 != v.f5) { return u.f5 < v.f5; }
    if (u.f1 != v.f1) { return u.f1 < v.f1; }
    return u.f2 < v.f2;
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        getline(cin, a[i].f1);
        getline(cin, a[i].f2);
        getline(cin, a[i].f3);
        scanf("%d\n", &a[i].f4);
        scanf("%d\n", &a[i].f5);
        scanf("%d\n", &a[i].f6);
    }

    sort(a, a+n, comp);
    for (int i=0; i<n; i++) {
        cout << "title: " << a[i].f1 << "\n";
        cout << "subtitle: " << a[i].f2 << "\n";
        cout << "journal info\n";
        cout << "_name: " << a[i].f3 << "\n";
        cout << "_volume: " << a[i].f4 << "\n";
        cout << "_issue: " << a[i].f5 << "\n";
        cout << "_publication year: " << a[i].f6 << "\n";
        if (i != n-1) cout << "\n";
    }
}