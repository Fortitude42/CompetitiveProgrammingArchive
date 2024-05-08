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

int n, tin[M], tout[M], timer, a[M], p[M];
vector < pii > ans;
set < int > q;
vi g[M], gg[M];


int get1(int v) {
	if (!sz(q) || *q.rbegin() < tin[v])
		return -1;
	
	int x = *q.lower_bound(tin[v]);
	if (x > tout[v])
		return -1;
	return x;
}

void dfs(int v, int p = 0) {	
	tin[v] = ++timer;
	a[timer] = v;

	for (auto to : g[v])
		if (to != p)
			dfs(to, v);

	tout[v] = timer;
}

void dfs1(int v, int p = 0) {
	int prv = -1, To = -1;


	for (auto to : g[v]) {
		if (to == p)
			continue;
		int x = get1(to);
		if (x != -1) {
			if (prv == -1) {
				prv = x;
				To = to;
			} else {
				ans.pb({a[x], a[prv]});
				prv = -1;
			}
			q.erase(x);
		}
	}

	if (prv != -1) {
		for (auto to : g[v]) {
			if (to == p)
				continue;
			int x = get1(to);
			if (x != -1) {
				if (To == to) {
					pii cur = ans.back();
					ans.ppb();
					ans.pb({cur.f, a[x]});
					ans.pb({cur.s, a[prv]});
				} else 
					ans.pb({a[x], a[prv]});
				q.erase(x);
				prv = -1;
				break;
			}
		}
	}

	assert(prv == -1);

	int lst = -1;
	for (auto to : g[v]) {
		if (to == p)
			continue;
		if (lst == -1) {
			lst = to; 
			continue;
		}
		int x = get1(lst);
		if (x == -1) {
			lst = to;
			continue;
		}

		int y = get1(to);
		if (y == -1)
			continue;
		
		while (x != -1 && y != -1) {
			ans.pb({a[x], a[y]});
			q.erase(x);
			q.erase(y);
			x = get1(lst);
			y = get1(to);
		}

		if (x == -1)
			lst = to;
	}

	int cnt = 0;
	for (auto to : g[v])
		if (to != p && get1(to) != -1){
			dfs1(to, v);
			++cnt;
		}

	assert(cnt <= 1);
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
	for (int i = 1; i <= n; ++i) 
		p[i] = i;
	

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

	int root = 1;
	while (sz(gg[root]) == 1)
		++root;

	dfs2(root);

	vi vertices;
	for (int i = 1; i <= n; ++i)
		if (p[i] == i)
			vertices.pb(i);

	for (int i = 1; i <= n; ++i)
		for (auto j : gg[i])
			if (get(i) != get(j))
				g[get(i)].pb(get(j)); 


	root = 0;
	while (sz(g[vertices[root]]) == 1)
		++root;
	dfs(vertices[root]);
	
	for (int i = 1; i <= n; ++i)
		if (sz(g[i]) == 1)
			q.insert(tin[i]);

	if (sz(q) & 1) {
		ans.pb({vertices[root], a[*q.begin()]});
		q.erase(q.begin());
	}

	dfs1(vertices[root]);
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

