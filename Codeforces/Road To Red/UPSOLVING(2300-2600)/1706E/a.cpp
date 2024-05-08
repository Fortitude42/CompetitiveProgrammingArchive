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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, q, p[M], d[M], up[M][20], mx[M][20], t[M << 2];
vector < pii > g[M];



void update(int pos, int x, int v = 1, int tl = 1, int tr = n - 1) {
	if (tl == tr) {
		t[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get(int l, int r, int v = 1, int tl = 1, int tr = n - 1) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);
	p[u] = v;
}


void dfs(int v, int p = 0) {
	d[v] = d[p] + 1;
	for (int i = 1; i < 20; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		mx[v][i] = max(mx[v][i - 1], mx[up[v][i - 1]][i - 1]);
	}


	for (auto x : g[v]) {
		int to = x.f, w = x.s;
		if (to == p)
			continue;

		mx[to][0] = w;
		up[to][0] = v;
		dfs(to, v);
	}
}

int getmax(int v, int u) {
	if (d[v] < d[u])
		swap(v, u);

	int ans = 0;
	for (int i = 19; i >= 0; --i)
		if (d[v] - (1 << i) >= d[u]) {
			ans = max(ans, mx[v][i]);
			v = up[v][i];
		}

	if (v == u)
		return ans;

	for (int i = 19; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			ans = max({ans, mx[v][i], mx[u][i]});
			v = up[v][i];
			u = up[u][i];
		}

	return max({ans, mx[v][0], mx[u][0]});
			
}

 
void solve() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		g[i].clear();
	}

	for (int i = 1; i <= m; ++i) {
		int v, u;
		cin >> v >> u;
		if (get(v) == get(u))
			continue;
		merge(v, u);
		g[v].pb({u, i});
		g[u].pb({v, i});
	}

	dfs(1);

	for (int i = 1; i < n; ++i)
		update(i, getmax(i, i + 1));

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << get(l, r - 1) << ' ';
	}

	cout << endl;
}   

main () {
	fastio
	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}