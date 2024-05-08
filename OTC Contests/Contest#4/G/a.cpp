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

int n, x[N], y[N], p[N + N]; 
set < int > qx,  qy;
vi valx, valy, g[N];
bool was[N], cycle;
vpii X[N], Y[N];


void dfs (int v, int p = 0) {
	was[v] = 1;
	qx.insert(x[v]);
	qy.insert(y[v]);
	for (auto to : g[v])
		if (to != p) {
			if (was[to])
				cycle = 1;
			else 
				dfs(to, v);			
		}
}

main () {
	p[0] = 1;
	for (int i = 1; i < N*2; ++i)
		p[i] = p[i - 1] * 2 % mod;


	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];      
		valx.pb(x[i]);
		valy.pb(y[i]);
	}

	sort(all(valx));
	sort(all(valy));

	valx.resize(unique(all(valx)) - valx.begin());
	valy.resize(unique(all(valy)) - valy.begin());

	
	for (int i = 1; i <= n; ++i) {
		x[i] = lower_bound(all(valx), x[i]) - valx.begin();
		y[i] = lower_bound(all(valy), y[i]) - valy.begin();
		X[x[i]].pb(mp(y[i], i));
		Y[y[i]].pb(mp(x[i], i));
	}

	for (int i = 0; i < n; ++i) {
		sort(all(X[i]));
		sort(all(Y[i]));
	}

	
	for (int i = 1; i <= n; ++i) {
		int j = upper_bound(all(X[x[i]]), mp(y[i], inf)) - X[x[i]].begin();
		if (j < sz(X[x[i]])) {
			g[i].pb(X[x[i]][j].s);
			g[X[x[i]][j].s].pb(i);
		}
		j -= 2;
		if (j >= 0) {
			g[i].pb(X[x[i]][j].s);
			g[X[x[i]][j].s].pb(i);
		}
		
		j = upper_bound(all(Y[y[i]]), mp(x[i], inf)) - Y[y[i]].begin();
		if (j < sz(Y[y[i]])) {
			g[i].pb(Y[y[i]][j].s);
			g[Y[y[i]][j].s].pb(i);
		}

		j -= 2;
		if (j >= 0) {
			g[i].pb(Y[y[i]][j].s);
			g[Y[y[i]][j].s].pb(i);			
		}
	}

	for (int i = 1; i <= n; ++i) {
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
	}

	int ans = 1;
	for (int i = 1; i <= n; ++i) 
		if (!was[i]) {
			qx.clear();
			qy.clear();
			cycle = 0;
			dfs(i);
			if (cycle)
				ans = ans * 1ll * (p[sz(qx) + sz(qy)]) % mod;
			else
				ans = ans * 1ll * (p[sz(qx) + sz(qy)] - 1) % mod;	
		}

	cout << ans << endl;
}