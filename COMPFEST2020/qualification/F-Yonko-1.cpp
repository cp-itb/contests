/**
 * Contest  : COMPFEST 2020 Qualification
 * Team     : Yonko -1
 * Author   : Kinantan Arya Bagaspati
 * Problem  : F - Fate of Chanek
 */ 

#include<bits/stdc++.h>
using namespace std;

long long l[2000000], r[2000000], curd[100069];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0; i<2000000; i++){
        l[i] = -1;
        r[i] = -1;
    }
    for(int i=0; i<100069; i++){
        curd[i] = 0;
    }
    long long n, q;
    cin >> n >> q;
    long long a[n+1], dup[n+1];
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dup[i] = n+1;
        dup[curd[a[i]]] = i;
        curd[a[i]]=i;
    }
    long long curs, k, rnk[n+1];
    for(int i=1; i<=n; i++){
        rnk[i]=a[i];
    }
    k=0;
    pair <long long, pair <long long, long long> > str[n];
    multiset <long long> ms;
	multiset <long long> :: iterator itr;
	long long del[n];
    for(int i=1; i<=n; i++){
        ms.insert(i);
    }
    long long j, curdel;
    for(int i=0; i<n && k<1000000; i++){
        curs=0;
        curdel=0;
        for(itr = ms.begin(); itr!=ms.end(); ++itr){
            j=*itr;
            if(dup[j]>j+i && j<=n-i){
                str[curs] = {rnk[j], {a[j+i], j}};
                dup[j] = min(dup[j], dup[j+i]);
                curs++;
            }else{
                del[curdel]=j;
                curdel++;
            }
        }
        for(j=0; j<curdel; j++){
            ms.erase(del[j]);
        }
        sort(str, str+curs);
        for(j=0; j<curs; j++){
            l[k+j] = str[j].second.second;
            r[k+j] = l[k+j] + i;
            if(j==0){
                rnk[l[k]] = 1;
            }else{
                if(str[j].first==str[j-1].first && str[j].second.first==str[j-1].second.first){
                    rnk[l[k+j]] = rnk[l[k+j-1]];
                }else{
                    rnk[l[k+j]] = rnk[l[k+j-1]]+1;
                }
            }
        }
        k = k+curs;
    }
    long long ques;
    for(int i=0; i<q; i++){
        cin >> ques;
        cout << l[ques-1] << " " << r[ques-1] << endl;
    }
}