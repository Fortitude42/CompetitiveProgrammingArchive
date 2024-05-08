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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, k, par[N]; 
vi g[N], gg[N];
bool good[N];

void clear () {
//	cerr << t << endl;
	for (int i = 1; i <= n; ++i) {
		par[i] = 0;
		good[i] = 0;
		g[i].clear();             
		gg[i].clear();
	}
}

void dfs (int v, int p, int vv) {
	par[v] = p;
	if (sz(g[v]) == 1) {
		gg[vv].pb(v);
		return;
	}

	for (auto to : g[v])
		if (to != p)
			dfs(to, v, vv);
}

void up (int v) {
	good[v] = 1;
	if (!good[par[v]])
		up(par[v]);
}


main () {
	fastio

	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; ++i) {
			int v, u;
			cin >> v >> u;
			g[v].pb(u);
			g[u].pb(v);
		}

		if (k == 1) {
			cout << "Yes" << endl;
			cout << 1 << endl << 1 << endl;
			clear();
			continue;
		}
		if (n == 2) {
			cout << "Yes" << endl;
			cout << 2 << endl << 1 << ' ' << 2 << endl;
			clear();
			continue;
		}

		int root = 1;
		while (sz(g[root]) == 1)
			++root;

		
		for (auto to : g[root]) 
			dfs(to, root, to);

	    good[root] = 1;

		int to1 = g[root][1];
		up(gg[to1].back());
		gg[to1].ppb();
		k--;

		for (auto to : g[root])
			for (auto too : gg[to])
				if (k) {
					up(too);
					k--;
				}
		
		if (k) {
			cout << "No" << endl;
			clear();
			continue;
		}

		vi ans;
		for (int i = 1; i <= n; ++i)
			if (good[i])
				ans.pb(i);

		cout << "Yes\n";
		cout << sz(ans) << endl;
		for (auto x : ans)
			cout << x << ' ';
		cout << endl;

		clear();

	}
}