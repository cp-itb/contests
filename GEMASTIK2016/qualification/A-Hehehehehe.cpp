/**
 * Contest : Gemastik 2016 Qualification
 * Team    : Hehehehehe
 * Author  : Turfa Auliarachman
 * Problem : A - Membangun Menara
 */
 
#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int mins = 0, maks = 0;

    while(n--){
      int a,b,c;
      cin >> a>> b >> c;
      mins += min(a,min(b,c));
      maks += max(a,max(b,c));
    }

    cout << mins << " " << maks << endl;
  }
}
