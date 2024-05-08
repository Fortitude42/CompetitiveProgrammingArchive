#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 54;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, v, u, w, s, m, x, gg[N][N], tmp[N][N], dp[N][N][N][N], cnt[N];
vi g[N];

void dfs (int v, int p = 0) {
	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			cnt[v] += cnt[to];
		}			
}

int calc (int v, int u, int a, int b) {
	int &res = dp[v][u][a][b];
	if (res != -1)
		return res;

	if ((!a || sz(g[u]) == 1) && !b)
		return res = 0;

	if (sz(g[u]) == 1)
		return calc(u, v, b, 0) + gg[v][u];

	vector < vi > tmp(sz(g[u]) + 1, vi(a + 1, -inf));
	tmp[0][0] = inf;

	int tt = 0;
	for (auto i : g[u])
		if (i != v) {
			for (int j = 0; j <= a; ++j) 
				if (tmp[tt][j] > -inf) {
					for (int k = 1; k <= a - j; ++k)
						tmp[tt + 1][j + k] = max(tmp[tt + 1][j + k], min(tmp[tt][j], calc(u, i, k, a + b - k) + gg[u][i]));
					tmp[tt + 1][j] = max(tmp[tt + 1][j], tmp[tt][j]);
				}

			++tt;
		}
//	cerr << tt << ' ' << a << ' ' << v << ' ' << u << ' ' << endl;
//	cerr << tmp[tt][a] << endl;			
			
	return res = tmp[tt][a];
}
 
main () {
	memset(dp, -1, sizeof(dp));
	cin >> n;

	for (int i = 1; i < n; ++i) {
		cin >> v >> u >> w;
		g[v].pb(u);
		g[u].pb(v);
		gg[v][u] = gg[u][v] = w;
	}

	cin >> s >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x;                 
		++cnt[x];
	}

	dfs(s);
	int ans = inf;
	for (auto i : g[s])
		ans = min(ans, calc(s, i, cnt[i], m - cnt[i]) + gg[s][i]);
		
	cout << ans << endl;	
}