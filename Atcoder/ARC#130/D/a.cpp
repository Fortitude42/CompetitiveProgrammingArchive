//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 3e3, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, dp[M][M], cnt[M], c[M][M], tmp[M];
vi g[M];

void precalc() {
	for (int i = 0; i < M; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			if (c[i][j] >= MOD)
				c[i][j] -= MOD;
		}
	}
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		x += MOD;
}


void dfs(int v, int p = 0) {
	cnt[v] = 1;
	dp[v][1] = 1;

	for (auto to : g[v]) { 
		if (to == p)
			continue;

	   	dfs(to, v);

		for (int i = 1; i <= cnt[v]; ++i)
			for (int j = 1; j <= cnt[to]; ++j) {
				add(tmp[i + j], dp[v][i] * 1ll * (dp[to][cnt[to]] - dp[to][cnt[to] - j]) % MOD * c[i + j - 1][i - 1] % MOD * c[cnt[v] - i + cnt[to] - j][cnt[v] - i] % MOD);
			}

			
		cnt[v] += cnt[to];


		for (int i = 1; i <= cnt[v]; ++i) {
			dp[v][i] = tmp[i];              
			tmp[i] = 0;
		}
	}

	for (int i = 1; i <= cnt[v]; ++i)
		add(dp[v][i], dp[v][i - 1]);
}
 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}


	dfs(1);

	printf("%d\n", dp[1][n] * 2 % MOD);
}

main () {
	precalc();
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}