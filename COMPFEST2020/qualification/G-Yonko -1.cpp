/**
 * Contest	: COMPFEST 2020 Qualification
 * Team		: Yonko -1
 * Author	: Jauhar Wibisono
 * Problem	: G - Gajah Malas
 */

#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int>in[100002];

bool cmp(pair<int,int>&a, pair<int,int>&b){
	return a.second<b.second;
}

int main(){
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> in[i].first;
		in[i].second=i;
	}	
	sort(in,in+n);
	for (int i=0;i<n;i++) in[i].first=i+1;
	sort(in,in+n,cmp);
	int cur1=1;
	for (int i=0;i<n;i++){
		if (cur1==in[i].first) cur1++;
	}
	for (int i=n-1;i>=0;i--){
		if (cur1==in[i].first) cur1++;
	}
	int cur2=1;
	for (int i=n-1;i>=0;i--){
		if (cur2==in[i].first) cur2++;
	}
	for (int i=0;i<n;i++){
		if (cur2==in[i].first) cur2++;
	}
	cout << ((cur2==n+1 || cur1==n+1) ? "Ya\n" : "Tidak\n");
}