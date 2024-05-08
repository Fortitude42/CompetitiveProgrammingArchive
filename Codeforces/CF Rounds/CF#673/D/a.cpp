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
 
const int inf = 1e9, maxn = 3e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, m, q, p[N], w[N], a[N], b[N], tp[N], v[N], u[N];
int tin[N], tout[N], timer;
pii t[N], T[N << 2];
bool used[N];
vi g[N];
 
void dfs (int v) {
	tin[v] = ++timer;
	for (auto to : g[v])
		dfs(to);
 
	tout[v] = timer;
}
 
int get (int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}
 
void merge (int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;
	  
	++n;
	p[n] = n;
	p[v] = n;
	p[u] = n;
	g[n].pb(v);
	g[n].pb(u);
}
 
void update (int pos, pii x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		T[v] = x;
		return;
	}
 
	int tm = (tl + tr) >> 1;
 
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);
 
	T[v] = max(T[v << 1], T[v << 1 | 1]);
}
 
pii get (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return mp(0, 0);
 
	if (l <= tl && tr <= r)
		return T[v];
 
	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}
 
 
main () {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);       
		p[i] = i;
	}
 
	for (int i = 1; i <= m; ++i) 
		scanf("%d%d", &a[i], &b[i]);
	
	for (int i = 1; i <= q; ++i) { 
		scanf("%d%d", &tp[i], &v[i]);
		if (tp[i] == 2) 
			used[v[i]] = 1;
	}
 
	for (int i = 1; i <= m; ++i)
		if (!used[i]) 
			merge(a[i], b[i]);
		
 
	for (int i = q; i > 0; --i) {
		if (tp[i] == 1) 
			u[i] = get(v[i]);
		else
			merge(a[v[i]], b[v[i]]);
	}
 
	for (int i = 1; i <= n; ++i)
		if (get(i) == i)
			dfs(i);
	
	for (int i = 1; i <= n; ++i)
		update(tin[i], mp(w[i], tin[i]));
 
 
	for (int i = 1; i <= q; ++i) 
		if (tp[i] == 1) {
			pii cur = get(tin[u[i]], tout[u[i]]);
			int pos = cur.s;
//			cerr << tin[u[i]] << ' ' << tout[u[i]] << ' ' << pos << endl;
			printf("%d\n", cur.f);
			if (pos)
				update(pos, mp(0, 0));	
		}
	
}