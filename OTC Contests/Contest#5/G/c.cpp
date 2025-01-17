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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

        	
int n, k, v, u, d[N], up[N][18], tin[N], timer, Sz, ans;
vi g[N];


void dfs (int v, int p = 0) {
	d[v] = d[p] + 1;
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i < 18; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (auto to : g[v])
		if (to != p) 
			dfs(to, v);		
}


int lca (int v, int u) {
	if (d[v] < d[u])
		swap(v, u);

	for (int i = 17; i >= 0; --i)
		if (d[v] - (1 << i) >= d[u])
			v = up[v][i];

	if (v == u)
		return v;
			
	for (int i = 17; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			v = up[v][i];
			u = up[u][i];
		}

	return up[v][0];		
}

int dist (int v, int u) {
	int l = lca(v, u);
	return d[v] + d[u] - d[l]*2;
}

set < pii > q;

int getNxt (int v) {
	auto it = q.upper_bound(mp(tin[v], v));
	if (it == q.end())
		return q.begin()->s;
	return it->s;
}

int getPrv (int v) {
	auto it = q.lower_bound(mp(tin[v], v));
	if (it == q.begin())
		return (*q.rbegin()).s;

	--it;
	return it->s;
}


void add (int v) {
	q.insert(mp(tin[v], v));
	int a = getPrv(v), b = getNxt(v);
	Sz += (dist(v, a) + dist(v, b) - dist(a, b)) / 2;
//	cout << " + " << v << ' ' << Sz << endl;
}

void del (int v) {
	q.erase(mp(tin[v], v));
	int a = getPrv(v), b = getNxt(v);
	Sz -= (dist(v, a) + dist(v, b) - dist(a, b)) / 2;
//	cout << " - " << v << ' ' << Sz << endl;
}


main () {
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);

	int r = 2;
	Sz = 1;
	q.insert(mp(tin[1], 1));

	ans = 1;
	for (int l = 1; l < n; ++l) {
		while (r <= n && Sz <= k) {
		    ans = max(ans, r - l);
//			cerr << l << ' ' << r << ' ' << Sz << endl;
			add(r++);               
		}
		if (Sz <= k)
			ans = max(ans, r - l);

		del(l);
	}
	cout << ans << endl;
}