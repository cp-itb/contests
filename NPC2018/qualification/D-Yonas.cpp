#include<bits/stdc++.h>
using namespace std;

long long arr[100005];

int main () {
    int n = 0;
    long long x;
    while (cin >> x) {
        arr[n] = x;
        n++;
    }
    n--;

    bool ada = false;
    for (int i=0; i<n && !ada; i++) {
        int y = x - arr[i];
        if (y == arr[i]) {
            int range = upper_bound(arr, arr+n, y) - lower_bound(arr, arr+n, y);
            if (range > 1) {
                ada = true;
            }
        } else {
            if (binary_search(arr, arr+n, y)) {
                ada = true;
            }
        }
    }
    if (ada) {
        printf("ADA\n");
    } else {
        printf("TIDAK ADA\n");
    }
}