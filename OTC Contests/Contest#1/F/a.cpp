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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

bool was[N];
int n, m, a, b, k, c[N], ans, cnt;
vi g[N], gr[N], order, col[N], gg[N];
 
void dfs (int v) {
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to])
			dfs(to);

	order.pb(v);
}

void dfs1 (int v) {
	was[v] = 1;
	col[k].pb(v);
	for (auto to : gr[v])
		if (!was[to])
			dfs1(to);
}

void dfs2 (int v) {
	was[v] = 1;
	ans += sz(col[v]) - 1;

	for (auto to : gg[v])
		if (!was[to]) 
			dfs2(to);

	order.pb(v);
}


void dfs3 (int v) {
	was[v] = 1;
	if (sz(col[v]) > 1)
		++cnt;

	for (auto x : gr[v])
		if (!was[x]) {
			dfs3(x);
			++ans;
		}

	for (auto x : gg[v])
		if (!was[x]) {
			dfs3(x);
			++ans;
		}
}

main () {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		gr[b].pb(a);
	}

	for (int i = 1; i <= n; ++i)
		if (!was[i])
			dfs(i);

	reverse(all(order));
	memset(was, 0, sizeof(was));

	for (auto x : order)
		if (!was[x]) {
			++k;
			dfs1(x);
			for (auto y : col[k])
				c[y] = k;
		}

	for (int i = 1; i <= n; ++i)			
		gr[i].clear();

	for (int i = 1; i <= n; ++i)
		for (auto j : g[i]) {
			gg[c[i]].pb(c[j]); 
			gr[c[j]].pb(c[i]);
		}

	memset(was, 0, sizeof(was));
	order.clear();

	for (int i = 1; i <= k; ++i)
		if (!was[i])
			dfs2(i);

	memset(was, 0, sizeof(was));
	for (auto x : order)
		if (!was[x]) {
			cnt = 0;
			dfs3(x);
			ans += min(1, cnt);
		}

	cout << ans << endl;
}