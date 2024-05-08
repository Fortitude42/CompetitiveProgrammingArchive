//by paradox & gege & parasat
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, tin[M], tout[M], timer, a[M], d[M], p[M];
vector < pii > ans;
pii t[M << 2];
vi g[M], gg[M];

void build(int v = 1, int tl = 1, int tr = n) {	
	t[v] = mp(inf, -1);
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void update(int pos, pii x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);

	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

pii get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return mp(inf, inf);

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return min(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

int getNode(int v) {
	return get(tin[v], tout[v]).s;
}


void dfs(int v, int p = 0) {	
	tin[v] = ++timer;
	d[v] = d[p] + 1;
	a[timer] = v;

	for (auto to : g[v])
		if (to != p)
			dfs(to, v);

	tout[v] = timer;
}

void dfs1(int v, int p = 0) {
	int prv = -1, To = -1, cnt1 = 0;

	for (auto to : g[v]) {
		if (to == p)
			continue;
		int x = getNode(to);
		if (x != -1) {
			++cnt1;
			if (prv == -1) {
				prv = x;
				To = to;
			} else {
				ans.pb({a[x], a[prv]});
				prv = -1;
			}
			update(x, mp(inf, -1));
		}
	}


	if (prv != -1) {
		for (auto to : g[v]) {
			if (to == p)
				continue;
			int x = getNode(to);
			if (x != -1) {
				if (To == to) {
					pii cur = ans.back();
					ans.ppb();
					ans.pb({cur.f, a[x]});
					ans.pb({cur.s, a[prv]});
				} else 
					ans.pb({a[x], a[prv]});
				update(x, mp(inf, -1));
				prv = -1;
				break;
			}
		}
	}
	
	int lst = -1;
	for (auto to : g[v]) {
		if (to == p)
			continue;
		if (lst == -1) {
			lst = to; 
			continue;
		}
		int x = getNode(lst);
		if (x == -1) {
			lst = to;
			continue;
		}

		int y = getNode(to);
		if (y == -1)
			continue;
		
		while (x != -1 && y != -1) {
			ans.pb({a[x], a[y]});
			update(x, mp(inf, -1));
			update(y, mp(inf, -1));
			x = getNode(lst);
			y = getNode(to);
		}

		if (x == -1)
			lst = to;
	}

	int cnt = 0;
	for (auto to : g[v])
		if (to != p && getNode(to) != -1){
			dfs1(to, v);
			++cnt;
		}
}

int get(int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}

void dfs2(int v, int p = 0) {
	int deg = sz(gg[v]) - (p > 0);
	
	for (auto to : gg[v])
		if (to != p){ 
			if (deg == 1 && sz(gg[to]) > 1)
				merge(v, to);
			dfs2(to, v);
		}
}
 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		gg[v].pb(u);
		gg[u].pb(v);
	}

	if (n == 2) {
		cout << 1 << endl;
		cout << 1 << ' ' << 2 << endl;
		return;
	}

	for (int i = 1; i <= n; ++i) 
		p[i] = i;

	int root = 1;
	while (sz(gg[root]) == 1)
		++root;

	dfs2(root);
	for (int i = 1; i <= n; ++i)
		for (auto j : gg[i])
			if (get(i) != get(j))
				g[get(i)].pb(get(j));

	root = 1;
	while (sz(g[root]) <= 1)
		++root;
	dfs(root);

	build();
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (sz(g[i]) == 1) {
			update(tin[i], mp(-d[i], tin[i])); 
			++cnt;
		}

	if (cnt & 1) {
		int x = getNode(root);
		ans.pb({root, a[x]});
		update(x, mp(inf, -1));
	}

	dfs1(root);
	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;
}

main () {
//    file("kingdom")
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

