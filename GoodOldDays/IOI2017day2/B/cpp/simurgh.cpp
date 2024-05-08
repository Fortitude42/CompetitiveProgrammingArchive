#include "simurgh.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int p[N], m, n, pp[N];
bool used[N*N];
vi g, comp[N], T;
set < int > good, bad;

int get1 (int v) {
	return v == pp[v] ? v : pp[v] = get1(pp[v]);
}

void merge1 (int v, int u) {
	v = get1(v), u = get1(u);
	
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	pp[u] = v;
}


int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge (int v, int u, int i) {
	v = get(v), u = get(u);
	
	if (sz(comp[v]) < sz(comp[u]))
		swap(v, u);

	while (sz(comp[u])) {
		comp[v].pb(comp[u].back());
		comp[u].ppb();
	}
	comp[v].pb(i);

	p[u] = v;
}

void build () {
	for (int i = 0; i < n; ++i)
		pp[i] = i;
}


vi find_roads(int _n, vi u, vi v) {		
	n = _n;	
	m = sz(v);
	
	if (m == n - 1) {
		vi c;
		for (int i = 0; i < m; ++i)
			c.pb(i);
		return c;
	}

	build();
	for (int i = 0; i < m; ++i) {
		g.pb(i);                 
		if (get1(v[i]) != get1(u[i])) {
			merge1(v[i], u[i]);
			T.pb(i);
		}
	}

	while (sz(g)) {
		for (int i = 0; i < n; ++i) {
			comp[i].clear();          
			p[i] = i;
		}
		bool run = 0;

		for (auto i : g)
			if (get(v[i]) != get(u[i]))
				merge(v[i], u[i], i);
			else {
				run = 1;
				int vv = get(v[i]);
				comp[vv].pb(i);
				build();
				for (auto j : comp[vv])
					merge1(v[j], u[j]);
				
				vi q;
				for (auto j : T)
					if (get1(v[j]) != get1(u[j])) {
						q.pb(j);                   
						merge1(v[j], u[j]);
					}

				vpii res;
				for (auto j : comp[vv]) {
					vi cur;
					for (auto x : q)
						cur.pb(x);
					for (auto x : comp[vv])
						if (x != j)
							cur.pb(x);
					res.pb(mp(count_common_roads(cur), j));							
				}

				sort(all(res));
				for (auto x : res) {
					if (x.f == res.back().f) 
						bad.insert(x.s);	
					else
						good.insert(x.s);
					used[x.s] = 1;
				}
				break;
			}

		for (int i = 0; i < sz(g); ++i)
			if (used[g[i]]) {
				swap(g[i], g.back());
				g.ppb();
				--i;
			}

	   	if (!run)
	   		break;
	}

	


	vi V;
	for (int i = 0; i < m; ++i)
		if (!used[i])
			V.pb(i);
		else
			g.pb(i);

	for (auto x : V) {
		for (int i = 0; i < n; ++i) {
			comp[i].clear();          
			p[i] = i;
		}

		for (auto i : g)
			if (get(v[i]) != get(u[i]))
				merge(v[i], u[i], i);
			else {
				int vv = get(v[i]);
				comp[vv].pb(i);
				bool ok = 0;

				for (auto i : comp[vv])
					if (i == x) {
						ok = 1;
						break;
					}

				if (!ok) {
					comp[vv].ppb();
					continue;
				}

				build();
				for (auto j : comp[vv])
					merge1(v[j], u[j]);
				
				vi q;
				for (auto j : T)
					if (get1(v[j]) != get1(u[j])) {
						q.pb(j);                   
						merge1(v[j], u[j]);
					}

				vpii res;
				for (auto j : comp[vv]) {
					vi cur;
					for (auto x : q)
						cur.pb(x);
					for (auto x : comp[vv])
						if (x != j)
							cur.pb(x);
					res.pb(mp(count_common_roads(cur), j));							
				}

				sort(all(res));
				for (auto x : res) {
					if (x.f == res.back().f) 
						bad.insert(x.s);	
					else
						good.insert(x.s);
					used[x.s] = 1;
				}
				break;
			}

		for (int i = 0; i < sz(g); ++i)
			if (used[g[i]]) {
				swap(g[i], g.back());
				g.ppb();
				--i;
			}
	}        

	vi ans;
	for (auto x : good) {
		ans.pb(x);       
		cerr << x << ' ';
	}
	cerr << endl;
	return ans;
}

                                	   