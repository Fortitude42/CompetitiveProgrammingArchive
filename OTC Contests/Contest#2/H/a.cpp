#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

bool was[N];
vi g[N], vals;
int n, c[N], v, u, res;
int l[N], r[N], timer, p[N];
map < int, vector < pair < int, pii > > > e;

void dfs (int v, int p = 0) {
    if (sz(g[v]) == 1 && p) {
    	l[v] = r[v] = ++timer;
    	return;
    }          

	l[v] = inf;

	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			l[v] = min(l[v], l[to]);
			r[v] = max(r[v], r[to]);
		}		
}

int get (int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}


void merge (int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}

 
main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	for (int i = 1; i < n; ++i) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
	for (int i = 1; i <= n; ++i) {
		e[c[i]].pb({i, {l[i] - 1, r[i]}});	
		vals.pb(c[i]);
	}

	for (int i = 0; i <= timer; ++i)
		p[i] = i;

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (auto x : vals) {
		for (auto y : e[x])
			if (get(y.s.f) != get(y.s.s)) 
				was[y.f] = 1;
		
		for (auto y : e[x]) 
			if (get(y.s.f) != get(y.s.s)) {
				merge(y.s.f, y.s.s);
				res += x;
			}
	}

	vi ans;
	for (int i = 1; i <= n; ++i)
		if (was[i])	
			ans.pb(i);

	cout << res << ' ' << sz(ans) << endl;
	for (auto x : ans)
		cout << x << ' ';

	return 0;
}