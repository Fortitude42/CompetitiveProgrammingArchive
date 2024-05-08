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

vi g[M];
int a[M], c[M];
ll value_of[M];

int parent[M];
int heavy[M];
int head[M], pos[M], tail[M];
int cur_pos, in_pos[M];

ll t[M << 2], tq[M << 2];
multiset<ll> values;

int dfs(int v) {
	value_of[v] = a[v] - c[v];
	int size = 1;
	int max_subtree = 0;
	for (int to : g[v]) {
		int to_size = dfs(to);
		value_of[v] += value_of[to];
		size += to_size;
		if (to_size > max_subtree) {
			max_subtree = to_size;
			heavy[v] = to;
		}
	}
	return size;
}

void decompose(int v, int h) {
	head[v] = h;
	pos[v] = ++cur_pos;
	in_pos[cur_pos] = v;

	if (heavy[v])
		decompose(heavy[v], h);
	else
		tail[h] = v;

	for (int to : g[v])
		if (to != heavy[v])
			decompose(to, to);
}

void push(int v, int tl, int tr) {
	if (!tq[v])
		return;
	
	t[v] += tq[v];
	if (tl != tr) {
		tq[v << 1] += tq[v];
		tq[v << 1 | 1] += tq[v];
	}
	tq[v] = 0;
}

void upd(int v) {
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void build(int v = 1, int tl = 1, int tr = N) {
	if (tl == tr) {
		int ver = in_pos[tl];
		t[v] = value_of[ver];
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	upd(v);
}

void upd(int l, int r, ll val, int v = 1, int tl = 1, int tr = N) {
 	push(v, tl, tr);
 	if (tl > r || l > tr || l > r)
 		return;
	if (l <= tl && tr <= r) {
		tq[v] += val;
		push(v, tl, tr);
		return;
	}

	int tm = (tl + tr) >> 1;
	upd(l, r, val, v << 1, tl, tm);
	upd(l, r, val, v << 1 | 1, tm + 1, tr);
	upd(v);
}

ll get(int l, int r, int v = 1, int tl = 1, int tr = N) {
	push(v, tl, tr);
	if (l > r || tl > r || l > tr)
		return INF;
	if (l <= tl && tr <= r)
		return t[v];
	
	int tm = (tl + tr) >> 1;
	ll le = get(l, r, v << 1, tl, tm);
	ll ri = get(l, r, v << 1 | 1, tm + 1, tr);
	return min(le, ri);
}

void dfs_values(int v) {
	if (!heavy[v]) {
		values.insert(get(pos[head[v]], pos[v]));
//		cerr << "insert: " << head[v] << ' ' << v << " | " << get(pos[head[v]], pos[v]) << "\n";
	}
	for (int to : g[v])
		dfs_values(to);
}

void update(int v, int val) {
//	cerr << "!!! update(" << v << "):\n";
	while (v) {
//		cerr << "get(" << head[v] << ", " << tail[head[v]] << ")\n";
		ll old_value = get(pos[head[v]], pos[tail[head[v]]]);
//		cerr << "old value = " << old_value << "\n";
		values.erase(values.find(old_value));
//		cerr << "erased!\n";
		upd(pos[head[v]], pos[v], val);
//		cerr << "upd(" << head[v] << ", " << v << ")\n";
		values.insert(get(pos[head[v]], pos[tail[head[v]]]));
//		cerr << "inserted!\n";
		v = parent[head[v]];
//		cerr << "new v = " << v << "\n";
	}
}
 
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int par;
		scanf("%d", &par);
		g[par].pb(i);
		parent[i] = par;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);	
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}

	dfs(1);
//	cerr << "dfs: ok!\n";
	decompose(1, 1);
//	cerr << "decompose: ok!\n";
	build();
//	cerr << "build: ok!\n";
	dfs_values(1);
//	cerr << "dfs_values: ok!\n";

//	cerr << "values size: " << sz(values) << "\n";
	
	printf(*values.begin() >= 0 ? "Yes\n" : "No\n");
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int t, v, x;
		scanf("%d %d %d", &t, &v, &x);

//		cerr << "? " << t << ' ' << v << ' ' << x << "\n";

		if (t == 1) {
			update(v, x - a[v]);
			a[v] = x;
		} else {
			update(v, c[v] - x);
			c[v] = x;
		}
//		cerr << "update: ok!\n";

		printf(*values.begin() >= 0 ? "Yes\n" : "No\n");
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

