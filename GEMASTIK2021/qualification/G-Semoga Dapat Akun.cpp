 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Kinantan Arya Bagaspati
  * Problem : G - Jalan Jalan Virtual
  */

#include<bits/stdc++.h>
using namespace std;

long long x[150069], y[150069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n=0, m=0;
    x[0] = 0; y[0] = 0;
    for(int i=1; i<100000; i+=m){
        m++;
        for(int j=0; j<m; j++){
            if(m%4 == 1){
                x[i+j] = x[i+j-1] + 1;
                y[i+j] = y[i+j-1];
            }else if(m%4 == 2){
                x[i+j] = x[i+j-1];
                y[i+j] = y[i+j-1] + 1;
            }else if(m%4 == 3){
                x[i+j] = x[i+j-1] - 1;
                y[i+j] = y[i+j-1];
            }else{
                x[i+j] = x[i+j-1];
                y[i+j] = y[i+j-1] - 1;
            }
        }
    }
    cin >> n;
    while(n--){
        cin >> m;
        cout << x[m] << " " << y[m] << endl;
    }

}

