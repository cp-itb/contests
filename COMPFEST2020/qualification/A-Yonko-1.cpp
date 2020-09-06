/**
 * Contest  : COMPFEST 2020 Qualification
 * Team     : Yonko -1
 * Author   : Kinantan Arya Bagaspati
 * Problem  : A - Angka Cantik
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    long long z=0;
    while((m%2==0)||(m%5==0)){
        if(m%2==0){
            m = m/2;
        }
        if(m%5==0){
            m = m/5;
        }
        z++;
    }
    long long cur=1;
    long long md=0;
    for(int i=0; i<n; i++){
        md = (md+cur*a[i])%m;
        cur = (cur*10)%m;
    }
    long long x=1;
    long long md2=md;
    long long cur2=cur;
    while(md2!=0){
        md2 = (md2+cur2*md)%m;
        cur2 = (cur2*cur)%m;
        x++;
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<n; j++){
            cout << a[n-1-j];
        }
    }
    for(int i=0; i<z; i++){
        cout << 0;
    }
    cout << endl;
}