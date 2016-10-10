/**
 * Contest : Gemastik 2016 Qualification
 * Team    : Hehehehehe
 * Author  : Turfa Auliarachman
 * Problem : D - Saklar Lhompat
 */
 
#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int l,b;
    cin >> l >> b;

    int ans  = 1;
    int pinggir = 2, tengah = 2;

    while(l+b>0){
      if (b > 0 && pinggir > 0){
        int kurang = min(b,pinggir);
        pinggir -= kurang;
        b -= kurang;
      }
      else if (b*2 + l <= tengah){
        break;
      }
      else if (b==0 && l <= pinggir+tengah){
        break;
      }else{
        int kurang = min(tengah-1,l);
        l -= kurang; tengah -= kurang+1;
        pinggir += 2; tengah += 2; ans++;
      }

    }

    cout << ans << endl;
  }
}
