#include "swap.h"

#include <vector>
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int p[N], cnt[N], t[N], up[N][17], d[N], mx[N][17];
bool was[N];
vi comp[N];
vpii g[N];

int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void F (int v, int timer) {
	for (auto x : comp[v])
		t[x] = timer;
	was[v] = 1;	
}

void merge (int v, int u, int timer) {
	int V = v, U = u;

	v = get(v), u = get(u);
	if (v == u) {
		if (!was[v])
			F(v, timer);
		return;
	}

	++cnt[V], ++cnt[U];
	if (cnt[V] == 3 && !was[v]) 
		F(v, timer);

   	if (cnt[U] == 3 && !was[u])
   		F(u, timer);

   	if (!was[v] && was[u])
   		F(v, timer);

	if (was[v] && !was[u])
		F(u, timer);


	if (sz(comp[v]) < sz(comp[u]))
		swap(v, u);                   
	
	while (sz(comp[u])) {
		comp[v].pb(comp[u].back());
		comp[u].ppb();
	}

	p[u] = v;
}


void dfs (int v, int p = 0, int w = 0) {
	up[v][0] = p;
	mx[v][0] = w;

	for (int i = 1; i < 17; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1]; 
		mx[v][i] = max(mx[v][i - 1], mx[up[v][i - 1]][i - 1]);
	}

	d[v] = d[p] + 1;
	for (auto to : g[v])
		if (to.f != p) 
			dfs(to.f, v, to.s);		
}

int getMax (int v, int u) {
	int res = 0;
	if (d[v] < d[u])
		swap(v, u);

   	for (int i = 16; i >= 0; --i)
   		if (d[v] - (1 << i) >= d[u]) {
   			res = max(res, mx[v][i]);
   			v = up[v][i];
   		}

	if (v == u)
		return res;

	for (int i = 16; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			res = max({res, mx[v][i], mx[u][i]});
			v = up[v][i];
			u = up[u][i];
		}

	return max({res, mx[v][0], mx[u][0]});

}

void init(int n, int m, vi U, vi V, vi W) {
	vector < pair < int, pii > > E;
	for (int i = 0; i < m; ++i) {
		++V[i], ++U[i];
		E.pb({W[i], {V[i], U[i]}}); 
	}

	sort(all(E));

	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		comp[i].pb(i);
	}

	for (auto x : E) {
		if (get(x.s.f) != get(x.s.s)) {
			g[x.s.f].pb(mp(x.s.s, x.f));
			g[x.s.s].pb(mp(x.s.f, x.f));
		}

		merge(x.s.f, x.s.s, x.f);
	}

	dfs(1);			

}

int getMinimumFuelCapacity(int v, int u) {
	++v, ++u;
	if (!t[v] || !t[u])
		return -1;
	return max({t[v], t[u], getMax(v, u)});
}