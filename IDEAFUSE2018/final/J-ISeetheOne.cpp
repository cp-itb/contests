/**
 * Contest : IDEAFUSE 2018 Final
 * Team    : I See the One
 * Author  : Dicky Novanto, Devin Alvaro
 * Problem : J - Raon and Voting
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

class UF{
private:
	vi rank, p, setSize;
	int numset, i;
public:
	UF(int n){
		numset = n; setSize.assign(n, 1);
		rank.assign(n, 0); p.assign(n, 0);
		for(i=0;i<n;i++){p[i] = i;};
	}
	
	int findSet (int i) {return (p[i] == i)? i : (p[i] = findSet(p[i]));}
	
	bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
	
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			numset--;
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]){
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if(rank[x]==rank[y]){rank[y]++;}
			}
		}
	}
	
	int numDisjointSet(){return numset;}
	
	int sizeSetOf(int i){return setSize[findSet(i)];}
};

int leader[100010];

int main(){
	int n,q,i,j;
	scanf("%d %d", &n, &q);
	UF uf(n+1);
	int maksUkuran = 1;
	for(i=1;i<=n;++i)
		leader[i] = i;
	
	set<int> s;
	s.insert(1);
	
	while(q--){
		int com, a, b;
		scanf("%d", &com);
		if(com == 1){
			scanf("%d %d", &a, &b);
			
			int ukuranA  = uf.sizeSetOf(a);
			int ukuranB  = uf.sizeSetOf(b);
			
			int leaderA = leader[uf.findSet(a)];
			int leaderB = leader[uf.findSet(b)];
			
			uf.unionSet(a, b);
			int indeksKepala = uf.findSet(a);
			if(ukuranA > ukuranB)
				leader[indeksKepala] = leaderA;
			else if(ukuranB > ukuranA)
				leader[indeksKepala] = leaderB;
			else
				leader[indeksKepala] = min(leaderA, leaderB);
			
			int ukuran = uf.sizeSetOf(a);
			if(ukuran > maksUkuran){
				maksUkuran = ukuran;
				
				s.clear();
				s.insert(leader[indeksKepala]);
			}else if(ukuran == maksUkuran){
				s.insert(leader[indeksKepala]);
			}
		}else if(com==2){
			int idx;
			scanf("%d", &idx);
			
			int indeksKepala = uf.findSet(idx);
			
			int ukuran = uf.findSet(idx);
			if(ukuran == maksUkuran){
				s.erase(leader[indeksKepala]);
				s.insert(idx);
			}
			
			leader[indeksKepala] = idx;
		}else{
			int currentWinning = *s.begin();
			printf("%d %d\n", currentWinning, uf.sizeSetOf(currentWinning));
		}
	}
	return 0;
}