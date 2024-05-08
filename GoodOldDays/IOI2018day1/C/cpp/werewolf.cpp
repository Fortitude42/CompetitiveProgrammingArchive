#include "werewolf.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 4e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, q, p[N], tin[N][2], tout[N][2], timer;
vi g[N], gg[N], G[N];

struct node {
	node *l, *r;
	int sum;

	node () {
		l = r = NULL;
		sum = 0;
	}

	node (int x) {
		l = r = NULL;
		sum = x;
	}

	node (node *L, node *R) {
		l = L, r = R;
		sum = (!l ? 0 : l->sum) + (!r ? 0 : r->sum);	
	}
};

typedef node* pnode;
pnode root[N];

pnode build1 (int tl = 1, int tr = n) {
	if (tl == tr) 
		return new node(0);
	int tm = (tl + tr) >> 1;
	return new node(build1(tl, tm), build1(tm + 1, tr));
}

int get (pnode t, int l, int r, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t->sum;
	
	int tm = (tl + tr) >> 1;
	return get(t->l, l, r, tl, tm) + get(t->r, l, r, tm + 1, tr);
}

pnode update (pnode t, int pos, int x, int tl = 1, int tr = n) {
	if (tl == tr) 
		return new node(t->sum + x);

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		return new node(update(t->l, pos, x, tl, tm), t->r);
	return new node(t->l, update(t->r, pos, x, tm + 1, tr));
}



int get (int v) {
	return p[v] == v ? v : p[v] = get(p[v]);              	
}


void build () {
	timer = 0;
	for (int i = 0; i < n; ++i) {
		p[i] = i;                
		gg[i].clear();
		G[i].clear();
	}                
} 

void dfs (int v, int i) {
	tin[v][i] = ++timer;
	for (auto to : gg[v])
		dfs(to, i);
	tout[v][i] = timer;
}

vi check_validity (int _n, vi x, vi y, vi s, vi e, vi l, vi r) {
	n = _n;
	m = sz(x);
	q = sz(l);

	for (int i = 0; i < m; ++i) {
		if (x[i] > y[i])
			swap(x[i], y[i]);
		g[x[i]].pb(y[i]);
		g[y[i]].pb(x[i]);
	}

	build();
	for (int i = 0; i < q; ++i) 
		G[l[i]].pb(i);

	for (int i = n - 1; i >= 0; --i) {
		for (auto j : g[i]) {
			if (get(i) == get(j) || j < i)
				continue;

			gg[i].pb(get(j));
			p[get(j)] = i;	
		}

		for (auto j : G[i]) 
			s[j] = get(s[j]);
	}
	dfs(0, 0);

	build();
	for (int i = 0; i < q; ++i)
		G[r[i]].pb(i);

	for (int i = 0; i < n; ++i) {
		for (auto j : g[i]) {
			if (get(i) == get(j) || j > i)
				continue;

			gg[i].pb(get(j));
			p[get(j)] = i;
		}         

		for (auto j : G[i]) 
			e[j] = get(e[j]);
	}
	
	
	
	dfs(n - 1, 1);	
	
	build();
	root[0] = build1();
	for (int i = 0; i < n; ++i) 
		G[tin[i][0]].pb(i);

	for (int i = 1; i <= n; ++i) {
		root[i] = root[i - 1];
		for (auto j : G[i])
			root[i] = update(root[i], tin[j][1], 1);	
	}


	vi E;
	for (int i = 0; i < q; ++i) { 
  		E.pb(min(1, get(root[tout[s[i]][0]], tin[e[i]][1], tout[e[i]][1]) - get(root[tin[s[i]][0] - 1], tin[e[i]][1], tout[e[i]][1])));		
	}
	
	return E;
}
               	