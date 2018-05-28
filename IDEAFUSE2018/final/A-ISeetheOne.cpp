/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : I See the One
 * Author  : Dicky Novanto
 * Problem : A - Biutiful Number
 */
#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
	int tc,n;
	int i;
	set<int> s;
	s.insert(1);
	int sum=1;
	for(i=2;;i++){
		sum+=i;
		s.insert(sum);
	}
	scanf("%d", &tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d", &n);
		if(s.find(n) == s.end()){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0;
}