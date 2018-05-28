/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : I See the One
 * Author  : Tony
 * Problem : B - Raon and Ice Cream
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

int n;
int hitung[500002][26];
char s[500002];

int main(){
	int t;
	scanf("%d", &t);
	for(int cc=1;cc<=t;cc++){
		printf("Case #%d: ", cc);
		memset(hitung, 0, 27*4);
		scanf("%d", &n);
		getchar();
		for(int i=1;i<=n;++i){
			s[i] = getchar();
			for(int j=0;j<26;++j)
				hitung[i][j] = hitung[i-1][j];
			++hitung[i][s[i]-'A'];
		}
		int ans = 0;
		int pem = 0;
		for(int i=0;i<26;++i)
			pem = __gcd(pem, hitung[n][i]);
		vector<int> coba;
		for(int i=1;i<=sqrt(pem);++i){
			if(pem%i==0){
				coba.pb(i);
				int tmp = pem/i;
				if(tmp!=i)
					coba.pb(tmp);
			}
		}
		for(int x : coba){
			bool bisa = true;
			int y = n/x;
			for(int i=2*y;bisa&&i<=n;i+=y){
				for(int j=0;j<26;++j){
					if(hitung[i][j] - hitung[i-y][j] != hitung[y][j]){
						bisa = false;
						break;
					}
				}
			}
			if(bisa)
				ans = max(ans, x);
		}
		printf("%d\n", ans);
	}
	return 0;
}