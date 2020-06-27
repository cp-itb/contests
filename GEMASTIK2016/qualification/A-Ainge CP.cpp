/**
 * Contest : GEMASTIK 2016 Qualification
 * Team    : Ainge CP
 * Author  : M. Visat Sutarno
 * Problem : A - Membangun Menara
 */

#include <bits/stdc++.h>

using namespace std;



int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v;
        int minnn = 0, maxxx = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> x;
            int minn = 1001, maxx = 0;
            for (int j = 0; j < 3; ++j) {
                int z; cin >> z;
                if (z < minn) minn = z;
                if (z > maxx) maxx = z;
            }
            minnn += minn;
            maxxx += maxx;
        }
        printf("%d %d\n", minnn, maxxx);
    }

    return 0;
}