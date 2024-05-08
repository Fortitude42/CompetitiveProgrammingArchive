#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "dreaming.h" 

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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int up[N][17], d[N], s[N], v, u;
vpii g[N];
vi V, vv;

void dfs (int v, int p = 0) {
    V.pb(v);
    d[v] = d[p] + 1;
	up[v][0] = p;
	for (int i = 1; i < 17; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (auto x : g[v]) {
		int to = x.f;
		if (to != p) {
		    s[to] = s[v] + x.s;
			dfs(to, v);
		}
	}
}


int lca (int v, int u) {
	if (d[v] < d[u])
		swap(v, u);

	for (int i = 16; i >= 0; --i)
		if (d[v] - (1 << i) >= d[u])
			v = up[v][i];

	if (v == u)
		return v;

	for (int i = 16; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			v = up[v][i];
			u = up[u][i];
		}

	return up[v][0];
}

int dist (int v, int u) {
	int l = lca(v, u);
	return s[v] + s[u] - 2*s[l];
}

int travelTime(int n, int m, int L, int a[], int b[], int w[]) {
	for (int i = 0; i < m; ++i)  {
		++a[i], ++b[i];
		g[a[i]].pb({b[i], w[i]});
		g[b[i]].pb({a[i], w[i]});
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) 
		if (!d[i]) {
			V.clear();
			dfs(i);		 
			v = i;
			for (auto j : V)
				if (s[j] > s[v])
					v = j;

			V.clear();
			dfs(v);
			int u = v;
			for (auto j : V)
				if (s[j] > s[u]) 
					u = j;

			int mn = inf + inf;
			for (auto j : V)
				mn = min(mn, max(dist(v, j), dist(u, j)));
//			cerr << i << ' ' << v << ' ' << u << ' ' << mn << endl;
			ans = max(ans, dist(v, u));
			vv.pb(mn);
		}

	assert(sz(vv) == n - m);
//	assert(n - m == 2);

	sort(all(vv));
	reverse(all(vv));
	if (sz(vv) == 1)
		return max(ans, vv[0]);
	if (sz(vv) == 2)
		return max(ans, vv[0] + vv[1] + L);

	return max({ans, vv[0] + vv[1] + L, vv[1] + vv[2] + L + L});	
}
