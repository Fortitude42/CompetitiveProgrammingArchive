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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


bool OK;
vector < pii > g[M];
int n, m, col[M];
vector < pair < int, pii > > e;

void dfs(int v, int c) {
	col[v] = c;
	for (auto to : g[v]) {
		if (col[to.f] == -1)
			dfs(to.f, c ^ to.s);
		else if (col[to.f] != (c ^ to.s))
			OK = 0;
	}
}

void clear() {
	for (int i = 1; i <= n; ++i) 
		g[i].clear();
	e.clear();	
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;

		int zz = z;
		if (z != -1) {
			zz = (__builtin_popcount(z) & 1); 
			g[x].pb({y, zz});
			g[y].pb({x, zz});
		}

		e.pb({z, {x, y}});
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}


	for (int i = 1; i <= n; ++i)
		col[i] = -1;

	OK = 1;
	for (int i = 1; i <= n; ++i)
		if (col[i] == -1)
			dfs(i, 0);

	if (!OK) {
		clear();
		cout << "NO\n";
		return;
	}


	cout << "YES\n";
	for (auto x : e) {
		int v = x.s.f, u = x.s.s, z = x.f;
		if (z == -1)
			z = (col[v] ^ col[u]);

		cout << v << ' ' << u << ' ' << z << endl;
	}
	clear();
}

main () {
	int TT;
	fastio
	TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}