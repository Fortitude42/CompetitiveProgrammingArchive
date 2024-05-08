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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int T, n, m, nxt[N][26], Sz, tt[N], timer, dp[N][2], was[N];
vi g[N], vals;
string s[N];
char t[N];


void addVertex (int i) {
	int v = 0;
	for (int j = 0; j < sz(s[i]); ++j) {
		int x = s[i][j] - 'a';

		if (nxt[v][x] == -1)
			nxt[v][x] = ++Sz;
		v = nxt[v][x];
		tt[v] = timer;
		vals.pb(v);
	}
}

void addEdges (int i) {
	int v = 0, u = 0;
	for (int j = 0; j < sz(s[i]); ++j) {
		int x = s[i][j] - 'a';

		v = nxt[v][x];
		if (j && u != -1)
			u = nxt[u][x];
		
		if (u != -1 && tt[u] == timer) {
			g[v].pb(u);
			g[u].pb(v);
		}
	}
}

void dfs (int v, int p = 0) {
	was[v] = timer;
	dp[v][0] = 0;
	dp[v][1] = 1;
	sort(all(g[v]));
	g[v].resize(unique(all(g[v])) - g[v].begin());

	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			dp[v][0] += max(dp[to][0], dp[to][1]);
			dp[v][1] += dp[to][0];
		}	
}


main () {
	memset(nxt, -1, sizeof(nxt));
	scanf("%d", &T);
	
	while (T--) {
		tt[0] = ++timer;
		vals.clear();
		vals.pb(0);

		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("\n%s", t);
			m = strlen(t);

			s[i] = "";


			for (int j = 0; j < m; ++j)
				s[i] += t[j];			
			addVertex(i);
		}

		for (int i = 1; i <= n; ++i)
			addEdges(i);

		dfs(0);
		int ans = dp[0][0];
		for (auto x : vals)
			if (was[x] != timer) {
				dfs(x);           
				ans += max(dp[x][0], dp[x][1]);
			}

		printf("%d\n", ans);

		for (auto x : vals)
			g[x].clear();
	}
}