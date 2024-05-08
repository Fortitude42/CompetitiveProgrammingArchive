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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int K = 18;

vi g[M];
int p[M][K], h[M];
int tin[M], tout[M], timer;
int par[M], sz[M], up[M], down[M];
int root[M];
int qv[M], qu[M], qd[M];

void dfs(int v, int par = 1) {
	p[v][0] = par;
	for (int i = 1; i < K; i++)
		p[v][i] = p[p[v][i - 1]][i - 1];

	tin[v] = ++timer;
	for (int to : g[v]) {
		if (to != par) {
			h[to] = h[v] + 1;
			dfs(to, v);
		}
	}
	tout[v] = timer;
}

bool isParent(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
	if (isParent(v, u))
		return v;
	if (isParent(u, v))
		return u;
	for (int i = K - 1; i >= 0; i--)
		if (!isParent(p[v][i], u))
			v = p[v][i];
	return p[v][0];
}

int getParent(int v) {
	return par[v] == v ? v : par[v] = getParent(par[v]);
}

int getDist(int v, int u) {
	int lc = lca(v, u);
	return h[v] - h[lc] + h[u] - h[lc];
}

bool check(int v, int a, int b, int dist) {
	v = getParent(v);
	return (dist == getDist(a, up[v]) + getDist(up[v], down[v]) + getDist(down[v], b)) || 
	(dist == getDist(b, up[v]) + getDist(up[v], down[v]) + getDist(down[v], a));
}

bool mergeTwo(int v, int u, int a, int b, int dist) {
//	cerr << "merge: " << v << ' ' << u << " | " << a << ' ' << b << " | " << dist << "\n";
	v = getParent(v);
	u = getParent(u);

	if (!check(v, a, b, dist) || !check(u, a, b, dist))
		return false;

	if (sz[v] < sz[u])
		swap(v, u);

	if (v == u)
		return true;

	sz[v] += sz[u];
	par[u] = v;

	root[v] = tin[root[v]] <= tin[root[u]] ? root[v] : root[u];
	down[v] = tin[down[v]] >= tin[down[u]] ? down[v] : down[u];
	up[v] = tin[up[v]] <= tin[up[u]] ? up[v] : up[u];
	return true;
}

bool merge(int v, int u) {
	int a = v, b = u;
	int dist = getDist(v, u);

	v = getParent(v);
	u = getParent(u);
	bool res = true;

	while (!isParent(root[v], root[u]) && res) {
		res = mergeTwo(v, p[root[v]][0], a, b, dist);
  		v = getParent(v);
  		u = getParent(u);
	}
//	cerr << "ok!\n";
//	cerr << root[1] << ' ' << root[2] << "\n";
	while (!isParent(root[u], root[v]) && res) {
//		cerr << v << ' ' << u << " | " << root[u] << ' ' << p[root[u]][0] << "\n";
		res = mergeTwo(u, p[root[u]][0], a, b, dist);
		u = getParent(u);
		v = getParent(v);
	}

	mergeTwo(a, b, a, b, dist);
//	cerr << "ok!\n";
	return res;
}
 
void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d %d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for (int v = 1; v <= n; v++) {
		par[v] = v;
		sz[v] = 1;
		up[v] = v;
		down[v] = v;
		root[v] = v;
	}

	dfs(1);

	vi ord;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &qv[i], &qu[i]);
		qd[i] = getDist(qv[i], qu[i]);
		ord.pb(i);
	}
	sort(all(ord), [](const int &i, const int &j) {
		return qd[i] < qd[j];
	});

	for (int i : ord) {
		int v = qv[i], u = qu[i];
		if (tin[v] > tin[u])
			swap(v, u);	
			
		if (!merge(v, u)) {
			printf("No\n");
			return;
		}
	}

	printf("Yes\n");
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

