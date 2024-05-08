//by paradox & gege & parasat
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
const int N = 150, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi g[M];
ll dp[M][M][M][4];
int n, a[M], par[M][M];
int dist[M][M], f[M][M], cnt[M];
 
void dfs(int root, int v, int p = 0) {
	cnt[v] = 1;

	for (auto to : g[v]) {
		if (to == p)
			continue;

		dist[root][to] = dist[root][v] + 1;
		par[root][to] = v;

		dfs(root, to, v);	
		cnt[v] += cnt[to];
	}
}

void dfs1(int root, int v, int p = 0) {
	for (auto to : g[v]) {
		if (to == p)
			continue;

		f[root][to] = v == root ? 0 : (f[root][v] + (cnt[v] - cnt[to] - 1));
		dfs1(root, to, v);
	}
}

void solve() {
	scanf("%d", &n);

	for (int i = 1; i <= n + 1; ++i)
		g[i].clear();

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	if (n == 1) {
		printf("%d\n", a[1]);
		return;
	}
	
	for (int i = 1; i <= n + 1; ++i) {
		dfs(i, i);
		dfs1(i, i);
	}

	for (int x = 1; x <= n + 1; ++x)
		for (int y = 1; y <= n + 1; ++y)
			for (int k = 1; k <= n + 1; ++k)
				for (int tp = 0; tp < 4; ++tp)
					dp[x][y][k][tp] = -INF;


	for (int i = 1; i <= n + 1; ++i)
		for (auto j : g[i])
			for (auto k : g[i]) {
				if (j == k)
					continue;
				dp[j][k][1][0] = 0;
				dp[j][k][1][1] = a[1];
				dp[j][k][1][2] = a[1];
//				cerr << j << ' ' << k << ' ' << a[1] << endl;
			}


	for (int k = 2; k <= n; ++k)
		for (int mask = 3; mask >= 0; --mask) 
			for (int x = 1; x <= n + 1; ++x)
				for (int y = 1; y <= n + 1; ++y) {
					if (dist[x][y] < 2)
						continue;

					int used = dist[x][y];

					if (!(mask & 1))
						--used;
					if (!(mask & 2))
						--used;


					if (used + f[x][y] >= k)
						dp[x][y][k][mask] = dp[x][y][k - 1][mask]; 


					if (mask & 1) 
						dp[x][y][k][mask] = max(dp[x][y][k][mask], dp[x][y][k - 1][mask ^ 1] + a[k]);
					else
						dp[x][y][k][mask] = max(dp[x][y][k][mask], dp[par[y][x]][y][k][mask ^ 1]);

					if (mask & 2)
						dp[x][y][k][mask] = max(dp[x][y][k][mask], dp[x][y][k - 1][mask ^ 2] + a[k]);
					else
						dp[x][y][k][mask] = max(dp[x][y][k][mask], dp[x][par[x][y]][k][mask ^ 2]);
				}


	ll ans = 0;
	for (int a = 1; a <= n + 1; ++a)
		for (int b = 1; b <= n + 1; ++b)
			ans = max(ans, dp[a][b][n][3]);

	printf("%lld\n", ans);
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
