
/**
 * Contest : FIND IT! 2021 Qualification
 * Team    : 0xD
 * Author  : Jauhar Wibisono
 * Problem : Penghuni Pulau
 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007; // faster if const

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

int matInv(vector<vector<ll>>& A) {
	int n = sz(A); vi col(n);
	vector<vector<ll>> tmp(n, vector<ll>(n));
	rep(i,0,n) tmp[i][i] = 1, col[i] = i;

	rep(i,0,n) {
		int r = i, c = i;
		rep(j,i,n) rep(k,i,n) if (A[j][k]) {
			r = j; c = k; goto found;
		}
		return i;
found:
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		rep(j,0,n) swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		ll v = modpow(A[i][i], mod - 2);
		rep(j,i+1,n) {
			ll f = A[j][i] * v % mod;
			A[j][i] = 0;
			rep(k,i+1,n) A[j][k] = (A[j][k] - f*A[i][k]) % mod;
			rep(k,0,n) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]) % mod;
		}
		rep(j,i+1,n) A[i][j] = A[i][j] * v % mod;
		rep(j,0,n) tmp[i][j] = tmp[i][j] * v % mod;
		A[i][i] = 1;
	}

	for (int i = n-1; i > 0; --i) rep(j,0,i) {
		ll v = A[j][i];
		rep(k,0,n) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]) % mod;
	}

	rep(i,0,n) rep(j,0,n)
		A[col[i]][col[j]] = tmp[i][j] % mod + (tmp[i][j] < 0 ? mod : 0);
	return n;
}

vector<pii> generalMatching(int N, vector<pii>& ed) {
	vector<vector<ll>> mat(N, vector<ll>(N)), A;
	for (pii pa : ed) {
	// cout << __LINE__ << "\n";
		int a = pa.first, b = pa.second, r = rand() % mod;
		// cout << a << " " << b << "\n";
		mat[a][b] = r, mat[b][a] = (mod - r) % mod;
	}
	int r = matInv(A = mat), M = 2*N - r, fi, fj;
	assert(r % 2 == 0);

	if (M != N) do {
		mat.resize(M, vector<ll>(M));
		rep(i,0,N) {
			mat[i].resize(M);
			rep(j,N,M) {
				int r = rand() % mod;
				mat[i][j] = r, mat[j][i] = (mod - r) % mod;
			}
		}
	} while (matInv(A = mat) != M);

	vi has(M, 1); vector<pii> ret;
	rep(it,0,M/2) {
		rep(i,0,M) if (has[i])
			rep(j,i+1,M) if (A[i][j] && mat[i][j]) {
				fi = i; fj = j; goto done;
		} assert(0); done:
		if (fj < N) ret.emplace_back(fi, fj);
		has[fi] = has[fj] = 0;
		rep(sw,0,2) {
			ll a = modpow(A[fi][fj], mod-2);
			rep(i,0,M) if (has[i] && A[i][fj]) {
				ll b = A[i][fj] * a % mod;
				rep(j,0,M) A[i][j] = (A[i][j] - A[fi][j] * b) % mod;
			}
			swap(fi,fj);
		}
	}
	return ret;
}

const int maxn = 22;
int n, m;
bool a[maxn][maxn], aa[maxn][maxn];
vector<int> ans;
const int dr[] = {0, -1, -1, -1, 0, 1, 1, 1}, dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> a[i][j];
			aa[i][j] = a[i][j];
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (aa[i][j]){
				vector<pair<int, int>> edgl;
				queue<pair<pair<int, int>, int>> q;
				map<int, int> mp;
				q.push({{i, j}, -1});
				int cur = 0;
				while (!q.empty()){
					int r = q.front().first.first;
					int c = q.front().first.second;
					int pre = q.front().second;
					q.pop();
					if (r < 0 || c < 0 || r >= n || c >= m || !aa[r][c]) continue;
					aa[r][c] = 0;
					mp[r*m+c] = cur;
					cur++;
					for (int k=0; k<8; k++){
						if (r+dr[k] >= 0 && r+dr[k] < n && c+dc[k] >= 0 && c+dc[k] < m && aa[r+dr[k]][c+dc[k]]){
							edgl.emplace_back(r*m+c, (r+dr[k])*m+(c+dc[k]));
						}
						q.push({{r+dr[k], c+dc[k]}, r*m+c});
					}
				}
				for (auto &e : edgl){
					e.first = mp[e.first];
					e.second = mp[e.second];
				}
				ans.push_back(generalMatching((int)mp.size(), edgl).size());
			}
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) cout << 0 << "\n";
	else{
		for (int u : ans) cout << u << " ";
		cout << "\n";
	}
}