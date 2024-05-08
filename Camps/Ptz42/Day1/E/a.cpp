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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vector<pii> g[M];
bool is_mst[M];
pii edge[M];

int p[M], p_id[M];
int sz[M], par[M], ver[M];

int tin[M], tout[M], timer;
int ans[M];

vi edges;

void dfs(int v) {
	tin[v] = ++timer;
	for (int i = 0; i < sz(g[v]); i++) {
		int to = g[v][i].fi, id = g[v][i].se;
		if (to != p[v]) {
			p[to] = v;
			p_id[to] = id;
			dfs(to);
		}
	}
	tout[v] = timer;
}

bool isParent(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getParent(int v) {
	return v == par[v] ? v : par[v] = getParent(par[v]);
}

void merge(int v, int u) {
	v = getParent(v);
	u = getParent(u);
	if (v == u)
		return;
	
	if (sz[v] < sz[u])
		swap(v, u);
	par[u] = v;
	sz[v] += sz[u];
	ver[v] = (isParent(ver[v], ver[u]) ? ver[v] : ver[u]);
}

void deletePath(int v, int u) {
	v = ver[getParent(v)];
	u = ver[getParent(u)];
	
	while (!isParent(v, u)) {
		edges.pb(p_id[v]);
		merge(v, p[v]);
		v = ver[getParent(v)];
	}
}

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int v, u, c;
		scanf("%d %d %d", &v, &u, &c);
		if (c) {
			g[v].pb({u, i});
			g[u].pb({v, i});
		}
		is_mst[i] = c;
		edge[i] = {v, u};
	}

	for (int v = 1; v <= n; v++) {
		sz[v] = 1;
		par[v] = v;
		ver[v] = v;
	}

	dfs(1);
	int cur = 1;
	for (int i = 1; i <= m; i++) {
		if (ans[i])
			continue;
		if (is_mst[i]) {
			//cerr << "! " << i << ' ' << cur << "\n";
			ans[i] = cur++;
			continue;
		}

		int v = edge[i].fi, u = edge[i].se;
		deletePath(v, u);
		deletePath(u, v);

		sort(all(edges));
		//cerr << i << " | ";
		for (int j : edges) {
			if (!ans[j])
				ans[j] = cur++;
        }
        //cerr << "\n";
		ans[i] = cur++;
		edges.clear();
	}

	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

