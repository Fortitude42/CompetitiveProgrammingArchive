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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, par[M], h[M], v1, v2, root, tin[N], tout[N], timer;
map < int, int > d[M];
queue < pii > q;
pii mx[M];
vi g[M];

 
void dfs(int v, int p = 0) {
	par[v] = p;
	h[v] = h[p] + 1;

	tin[v] = ++timer;

	mx[v] = mp(h[v], v);

	for (auto to : g[v])
		if (to != p) {
			dfs(to, v); 
			mx[v] = max(mx[v], mp(mx[to].f, to));
		}

	tout[v] = timer;
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	scanf("%d%d%d", &v1, &v2, &root);
	dfs(root);

	if (v1 > v2)
		swap(v1, v2);

	q.push(mp(v1, v2));
	d[v1][v2] = 0;

	while (sz(q)) {
		v1 = q.front().f, v2 = q.front().s;
		q.pop();

		if (upper(v1, v2)) {
			cout << d[v1][v2] + h[v1] - 1;
			return;
		}

		if (mx[v1].s != v1) {
			int to1 = mx[v1].s, to2 = par[v2];
			if (to1 > to2)
				swap(to1, to2);

			if (!d[to1].count(to2)) {
				d[to1][to2] = d[v1][v2] + 1;
				q.push({to1, to2});
			}
		}

		swap(v1, v2);

		if (upper(v1, v2)) {
			cout << d[v2][v1] + h[v1] - 1;
			return;
		}

		if (mx[v1].s != v1) {
			int to1 = mx[v1].s, to2 = par[v2];
			if (to1 > to2)
				swap(to1, to2);

			if (!d[to1].count(to2)) {
				d[to1][to2] = d[v2][v1] + 1;
				q.push({to1, to2});
			}
		}
	}

	cout << -1 << endl;
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

