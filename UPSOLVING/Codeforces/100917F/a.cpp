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
const int N = 300, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 

vi gg[M];
set < pii > q;
vector < pii > g[M];
int n, d[M], p[M], tin[M], tout[M], timer;

void dfs(int v) {
	tin[v] = ++timer;
	for (auto to : gg[v])
		dfs(to);
	tout[v] = timer;
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
	while (!upper(v, u))
		v = p[v];
	return v;
}

int get(int v) {
	set < pii > Q;
	timer = 0;
	for (int i = 1; i <= n; ++i) {
		d[i] = inf; 
		p[i] = -1;
		gg[i].clear();
		tin[i] = 0;
	}

	d[v] = 0;
	q.insert(mp(0, v));
	while (sz(q)) {
		int v = q.begin()->s;
		q.erase(q.begin());

		for (auto x : g[v]) {
			int to = x.f, w = x.s;
			if (d[to] > d[v] + w) {
				if (p[to] != -1) {
					Q.erase(mp(p[to], to));
					Q.erase(mp(to, p[to]));
				}
				d[to] = d[v] + w;
				p[to] = v;
				q.insert(mp(d[to], to));
				Q.insert(mp(p[to], to));
				Q.insert(mp(to, p[to]));
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		if (p[i] != -1)
			gg[p[i]].pb(i);
	dfs(v);

	int vv = v;
	int ans = inf;
	for (int v = 1; v <= n; ++v)
		for (auto x : g[v]) {
		    int to = x.f, w = x.s;
			if (d[v] < inf && d[to] < inf && (lca(v, to) == vv) && !Q.count(mp(v, to))) {
				ans = min(ans, d[to] + d[v] + w); 
			}
		}

	return ans == inf ? -1 : ans;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int x;
			cin >> x;
			if (x > 0) {
				g[i].pb({j, x}); 
//				if (i > j)
//					cout << i << ' ' << j << ' ' << x << endl;
			}
		}

	for (int i = 1; i <= n; ++i)
		cout << get(i) << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}