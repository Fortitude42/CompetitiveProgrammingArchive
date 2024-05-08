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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, dp[N][N][2], cnt[N], ok[N], x, y;
vi g[N];

void dfs (int v, int p = 0) {
	cnt[v] = 1;


	dp[v][0][0] = 0;
	int j = 1;

	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			for (int i = 0; i <= cnt[v] + cnt[to] - 1; ++i)
				dp[v][i][j] = inf;

			for (int x = 0; x < cnt[v]; ++x)
				for (int y = 0; y < cnt[to]; ++y) {
					dp[v][x + y + 1][j] = min(dp[v][x + y + 1][j], max({x + y + 1, dp[to][y][ok[to]], dp[v][x][j^1]}));
					dp[v][x][j] = min(dp[v][x][j], max({dp[to][y][ok[to]], y + 1, dp[v][x][j^1]}));
				}

			cnt[v] += cnt[to];
			j ^= 1;
			ok[v] ^= 1;
		}
}
 
main () {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) 
			g[i].clear();
		for (int i = 1; i < n; ++i) {
			cin >> x >> y;
			g[x].pb(y);
			g[y].pb(x);
		}
		
		dfs(1);
		int ans = inf;
		for (int i = 0; i <= n; ++i)
			ans = min(ans, dp[n][i][ok[n]]);
		cout << ans << endl;
	}
}