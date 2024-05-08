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


int n, m, c[M], k, t[M], timer, st[M], mn;
bool used[M], has[M];
vi g[M], comp[M], order, gr[M];
bool found;


void clear() {
	k = 0;
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		used[i] = 0;
		c[i] = 0;
		comp[i].clear();
		gr[i].clear();
		has[i] = 0;
	}
	order.clear();
}


void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v])
		if (!used[to])
			dfs(to);

	order.pb(v);
}


void dfs1(int v) {
	c[v] = k;
	comp[k].pb(v);
	for (auto to : gr[v])
		if (!c[to])
			dfs1(to);
}


void check(const vi &vv) {
	++timer;
	int cnt = 0;
	for (auto v : vv) {
		for (int u = v; u <= n; u += v) {
			if (t[u] != timer) {
				t[u] = timer;
				st[u] = 0;
			}

			if (!st[u])
				++cnt;
			else
				--cnt;
			st[u] ^= 1;
		}
	}

	if (cnt <= mn) {
		vi cur = vv;
//		sort(all(cur));
//		cur.resize(unique(all(cur)) - cur.begin());
//		assert(sz(cur) == sz(vv));
		assert(!found && sz(vv) > 0);
		cout << sz(vv) << "\n";
		for (auto v : vv)
			cout << v << ' ';
		cout << "\n";
		found = 1;
		return;
	}

}

 
void solve() {
	cin >> n >> m;
	while (m--) {
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		gr[u].pb(v);
	}


	for (int i = 1; i <= n; ++i)
		if (!used[i])
			dfs(i);
	
	reverse(all(order));
	for (auto v : order)
		if (!c[v]) {
		    ++k;
			dfs1(v);
		}

	mn = (n / 5);

	for (int i = 1; i <= n; ++i)
		for (auto j : g[i])
			if (c[i] != c[j])
				has[c[i]] = 1;

	found = 0;
	for (int i = 1; i <= k; ++i) {
		if (has[i])
			continue;
		if (!found)
			check(comp[i]);
	}  

	vector < int > ord;
	for (int i = 1; i <= k; ++i) {
		if (has[i])
			continue;
		int mn = inf;
		for (auto j : comp[i])
			mn = min(mn, j);

		ord.pb(mn);
	}
	sort(all(ord));
	reverse(all(ord));

	int nn = min(sz(ord), 9	);
	for (int mask = 1; !found && mask < (1 << nn); ++mask) {
		for (int i = 1; i <= n; ++i)
			used[i] = 0;
		order.clear();

		for (int i = 0; i < nn; ++i)
			if (!used[ord[i]] && (mask & (1 << i)))
				dfs(ord[i]);

		check(order);
	}

	if (!found)
		cout << -1 << "\n";
	clear();
}

main () {
  int TT;
  TT = 1;
  	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}