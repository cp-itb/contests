/**
 * Contest : Maranatha 2018 Qualification Trial
 * Team    : YonasNFriends
 * Author  : Yonas Adiel
 * Problem : C - I Love Strings
 */
#include<bits/stdc++.h>
using namespace std;
string s,s1;
int t,q;
int main(){
    cin>>t;
    while(t--){
        cin>>s>>q;
        for(int i=0;i<q;i++){
            cin>>s1;
            if(s.find(s1)>s.length()-1){
                printf("n\n");
            }
            else{
                printf("y\n");
            }
        }
    }
}
