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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int z, n, k, d[N][N], was[N], timer, col[N], par[N];
set < pair < ll, int > > q;
pair < int, pii > mn[N][N];
vpii g[N], gr[N]; 
vi order;
ll dp[N];


void dfs (int v) {
	was[v] = timer;
	for (auto x : g[v])
		if (was[x.f] != timer)
			dfs(x.f);

	order.pb(v);
}

void dfs1 (int v) {
	was[v] = timer;
	col[v] = k;
//	cerr << v << ' ' << col[v] << endl;

	for (auto x : gr[v])
		if (was[x.f] != timer)
			dfs1(x.f);
}


main () {
	scanf("%d", &z);
	while (z--) {
		scanf("%d", &n);			

		k = 0;
		order.clear();
		for (int i = 1; i <= n; ++i) {
			g[i].clear();             
			gr[i].clear();
			for (int j = 1; j <= n; ++j) 
				mn[i][j] = {2*inf + 1, {0, 0}};			
		}


		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &d[i][j]);    
				if (d[i][j]) {
					g[j].pb({i, d[i][j]});
					gr[i].pb({j, d[i][j]});
//					cerr << j << ' ' << i << endl;
				}
			}


		if (n == 2) {
			printf("NO\n");
			continue;
		}

		++timer;
		for (int i = 1; i <= n; ++i)
			if (was[i] != timer) 
				dfs(i);
		
		++timer;
		reverse(all(order));
		for (auto v : order) {
			if (was[v] != timer) {
				++k;
				dfs1(v);
			}
//			cerr << v << ' ' << col[v] << ' ' << k << endl;
		}
		
		for (int i = 1; i <= n; ++i)
			for (auto x : g[i]) {
				int v = col[i], u = col[x.f];
//				cerr << v << ' ' << u << ' ' << x.s << endl;
				mn[v][u] = min(mn[v][u], mp(x.s, mp(x.f, i)));
			}

		for (int i = 1; i <= k; ++i)
			dp[i] = INF, par[i] = 0;

		dp[1] = 0;
		q.insert(mp(0, 1));

		while (sz(q)) {
			int v = q.begin()->s;
			q.erase(q.begin());
			for (int u = 1; u <= k; ++u) {
				int cur = u <= v ? 0 : mn[v][u].f;
				ll cost = dp[v] + cur;
				if (cost < dp[u]) {
					q.erase(mp(dp[u], u));
					dp[u] = cost;
					par[u] = v;
					q.insert(mp(dp[u], u));
				}
			}
		}

		vpii ans;
		int v = k;
		while (v > 1) {
			int u = par[v];
			if (dp[u] != dp[v])
				ans.pb(mn[u][v].s);
			v = u;
		}		


		printf("YES\n");
		reverse(all(ans));
		printf("%d %lld\n", sz(ans), dp[k]);
		for (auto x : ans)
			printf("%d %d\n", x.f, x.s);

	}       	
}