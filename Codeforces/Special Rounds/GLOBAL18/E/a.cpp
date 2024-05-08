//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi g[M];
bool was[M];
pii t[M << 2];
int tin[M], tout[M], timer, d[M];
int n, k, add[M << 2], b[M], par[M];


void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = mp(d[b[tl]], b[tl]);
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void dfs(int v, int p = 0) {
	b[++timer] = v;
	tin[v] = timer;
	d[v] = d[p] + 1;
	par[v] = p;

	for (auto to : g[v])
		if (to != p) 
			dfs(to, v);

	tout[v] = timer;
}



void push(int v) {
	if (add[v]) {
		add[v << 1] += add[v];
		t[v << 1].f += add[v];
		
		add[v << 1 | 1] += add[v];
		t[v << 1 | 1].f += add[v];

		add[v] = 0;
		return;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		add[v] += x;
		t[v].f += x;
		return; 
	}

	int tm = (tl + tr) >> 1;
	push(v);
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

pii get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return mp(-inf, -inf);

	if (l <= tl && tr <= r) 
		return t[v];

	push(v);
	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

void del(int v) {
	if (was[v] || !v)
		return;

	was[v] = 1;
	update(tin[v], tout[v], -1);
	del(par[v]);
}
 
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
	build();

	int r = 0, b = n;
	ll ans = -INF;
	while (k--) {
		int v = t[1].s;

		b -= t[1].f;
		r++;
		del(v);
		update(tin[v], tin[v], -inf);
		int bb = min(b, n / 2);

		ans = max(ans, r * 1ll * (n - r) - bb * 1ll * (n - bb));
	}

	printf("%lld\n", ans);
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}