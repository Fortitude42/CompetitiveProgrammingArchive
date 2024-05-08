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
const int N = 1e3, inf = 2e9 + 7, MOD = 1e9 + 7, maxn = 3e4 + 11;
const int M = N + 17;
const ll INF = 1e18;

int tin[M], fup[M], timer, par[M], p[M], pp[M];
int n, m, s, t, a[maxn], b[maxn], c[maxn];
pair < int, vi > ans;
vi g[M];

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

void dfs(int v, int p = -1) {
	par[v] = p;
	for (auto x : g[v]) {
		int to = (a[x]^b[x]^v);
		if (!par[to])
			dfs(to, x);
	}	
}

void dfs1(int v, int e, int p = 0) {
	tin[v] = fup[v] = ++timer;
	for (auto x : g[v]) {
		if (x == e || x == p)
			continue;

		int to = (a[x]^b[x]^v);
		if (!tin[to]) {
			dfs1(to, e, x);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] <= tin[v]) 
				merge(v, to);			
		} else {
			fup[v] = min(fup[v], tin[to]); 
			merge(v, to);
		}
		
	}
}

void Try(int e) {
	timer = 0;
	memset(tin, 0, sizeof(tin));
	memset(fup, 0, sizeof(fup));
	memset(pp, 0, sizeof(pp));
	for (int i = 1; i <= n; ++i)
		p[i] = i;

	

	dfs1(s, e);
	if (!tin[t]) {
		pair < int, vi > cur;
		cur.f = c[e];
		cur.s.pb(e);
		ans = min(ans, cur);
		return;
	}

	for (int i = 1; i <= m; ++i) {
		if (i == e)
			continue;
		int aa = get(a[i]), bb = get(b[i]);
		if (aa == bb)
			continue;
		
		if (tin[a[i]] > tin[b[i]])
			swap(aa, bb);
		
		pp[bb] = i;
	}
	int ss = s, tt = t;
	ss = get(ss), tt = get(tt);
	while (ss != tt) {
		int x = pp[tt];
		pair < int, vi > cur;
		cur.f = c[e] + c[x];
		cur.s.pb(e);
		cur.s.pb(x);
		ans = min(ans, cur);
		tt = (get(a[x])^get(b[x])^tt);
	}	
}

void solve() {
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		g[a[i]].pb(i);
		g[b[i]].pb(i);
	}

	dfs(s);
	if (!par[t]) {
		cout << 0 << endl << 0;
		return;
	}

	int tt = t;
	while (tt != s) {
		int e = par[tt];
		Try(e);
		tt = (a[e] ^ b[e] ^ tt);
	}

	if (ans.f == inf) {
		cout << -1 << endl;
		return;
	}

	cout << ans.f << endl << sz(ans.s) << endl;
	for (auto x : ans.s)
		cout << x << ' ';
}

main () {
	ans.f = inf;
  int TT;
  TT = 1;
	fastio
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}
