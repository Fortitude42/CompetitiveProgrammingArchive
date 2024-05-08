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

int n, q, a[N<<1], b[N<<1], c[N<<1], id[N];
int tin[N], tout[N], timer, tp, v, u, t[N << 2], add[N << 2];
vi g[N];

void push (int v) {
	if (add[v]) {
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		t[v << 1] += add[v];
		t[v << 1 | 1] += add[v];
		
		add[v] = 0;
		return;
	}
}


void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;
	
	if (l <= tl && tr <= r) {
		t[v] += x;
		add[v] += x;
		return;
	}
	
	int tm = (tl + tr) >> 1;
	push(v);
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return INF;
	if (l <= tl && tr <= r)
		return t[v];
	
	int tm = (tl + tr) >> 1;
	
	push(v);
	return min(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}



bool upper (int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void dfs (int v) {
	tin[v] = ++timer;
	for (auto to : g[v])
		dfs(to);

	tout[v] = timer;					
}
 
main () {
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= 2*n - 2; ++i) 
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);

	for (int i = 1; i < n; ++i) 
		g[a[i]].pb(b[i]);

	dfs(1);			
	for (int i = n; i <= 2*n - 2; ++i) {
		id[a[i]] = i;                   
		update(tin[a[i]], tin[a[i]], c[i]);
	}

	for (int i = 1; i < n; ++i)
		update(tin[b[i]], tout[b[i]], c[i]);
	
	
	while (q--) {
		scanf("%lld%lld%lld", &tp, &v, &u);
		if (tp == 1) {
			if (v < n) {
				update(tin[b[v]], tout[b[v]], -c[v]);
				update(tin[b[v]], tout[b[v]], u);
			} else {
				update(tin[a[v]], tin[a[v]], -c[v]);
				update(tin[a[v]], tin[a[v]], u);
			}
			c[v] = u;			
		} else {
			if (upper(v, u)) {
				printf("%lld\n", (get(tin[u], tin[u]) - c[id[u]]) - (get(tin[v], tin[v]) - c[id[v]]));
				continue;
			}
//			if (!q)
//				cerr << get(tin[v], tout[v]) << ' ' << - (get(tin[v], tin[v]) - c[id[v]]) << ' ' << get(tin[u], tin[u]) << ' ' <<  - c[id[u]] << endl;
			printf("%lld\n", get(tin[v], tout[v]) - (get(tin[v], tin[v]) - c[id[v]]) + (get(tin[u], tin[u]) - c[id[u]]));
		}
	}
	
}