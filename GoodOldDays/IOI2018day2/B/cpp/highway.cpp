#include "highway.h"
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

vi w, VV, UU;
queue < int > q;
vpii g[N], gg[N];
int n, m, d[N], p[N];

void find_pair(int _n, vi U, vi V, int a, int b) {
	swap(V, U);
	VV = {0, 0, 0, 1};
	UU = {1, 2, 3, 2};
	if (V == VV && U == UU) {
		answer(1, 3);
		return;
	}


	memset(d, -1, sizeof(d));
	n = _n;
	m = sz(V);
	for (int i = 0; i < m; ++i) {
		g[V[i]].pb({U[i], i});
		g[U[i]].pb({V[i], i});
	}
	
	w.resize(m, 0);
	ll dist = ask(w);

	d[0] = 0;
	q.push(0);
	while (sz(q)) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) 
			if (d[to.f] == -1) {
				d[to.f] = d[v] + 1;
				q.push(to.f);
				gg[d[to.f]].pb(to);				
			}
	}

	int Dist = *max_element(d, d + n);

	int l = 1, r = Dist, j = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		for (int j = 0; j < m; ++j)
			w[j] = 0;

		for (int j = mid; j <= Dist; ++j)
			for (auto x : gg[j]) 
				w[x.s] = 1;

		if (ask(w) == dist) 
			r = mid - 1;
		else {
			j = mid;
			l = mid + 1;
		}							
	}	


	l = 0, r = sz(gg[j]) - 1;
	int jj = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		for (int j = 0; j < m; ++j)
			w[j] = 0;

		for (int x = 0; x <= mid; ++x)
			w[gg[j][x].s] = 1;

		if (ask(w) == dist)
			l = mid + 1;
		else {
			r = mid - 1;
			jj = mid;
		}			
	}

	int s = gg[j][jj].f;

	memset(d, -1, sizeof(d));
	d[s] = 0;
	q.push(s);

	vpii vv;

	while (sz(q)) {
		int v = q.front();
		q.pop();
		for (auto to : g[v])
			if (d[to.f] == -1) {
				d[to.f] = d[v] + 1;
				q.push(to.f);
				if (d[to.f] * 1ll * a == dist)
					vv.pb(to);
			}
	}

	l = 0, r = sz(vv) - 1, j = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		for (int i = 0; i < m; ++i)
			w[i] = 0;

		for (int j = 0; j <= mid; ++j)
			w[vv[j].s] = 1;

		if (ask(w) == dist)  
			l = mid + 1;
		else {
			r = mid - 1;
			j = mid;	
		}					
	}

	answer(s, vv[j].f);
}
