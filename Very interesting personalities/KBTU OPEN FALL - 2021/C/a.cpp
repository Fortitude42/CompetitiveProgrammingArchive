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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, d[M], cnt[M], pos[M], col[M], Sz, ans[M], mx[M];
pair < pii, pii > pref[M];
vector < pii > g[M];
bool was[M];
vi vals;

inline pair < pii, pii > merge(const pair < pii, pii > &a, const pair < pii, pii > &b) {
	pair < pii, pii > c = max(a, b);
	c.s = mp(-inf, -inf);
	if (a.f.s != c.f.s)
		c.s = max(c.s, a.f);

	if (a.s.s != c.f.s)
		c.s = max(c.s, a.s);

	if (b.f.s != c.f.s)
		c.s = max(c.s, b.f);

	if (b.s.s != c.f.s)
		c.s = max(c.s, b.s);

	return c;
}


void dfs(int v, int p = 0) {
	vals.pb(v);
	cnt[v] = 1;
	for (auto to : g[v])
		if (to.f != p && !was[to.f]) {
			dfs(to.f, v);
			cnt[v] += cnt[to.f];
		}			
}

int Find(int v, int p = 0) {
	for (auto to : g[v])
		if (!was[to.f] && to.f != p && cnt[to.f]*2 >= Sz)
			return Find(to.f, v);

	return v;
}

void dfs1(int v, int c, int p, int lst) {
	mx[v] = max(v, mx[p]);
	d[v] = d[p] + 1;
	pref[pos[mx[v]]] = max(pref[pos[mx[v]]], mp(mp(d[v], c), mp(-inf, -inf)));
	col[v] = c;

	for (auto to : g[v])
		if (!was[to.f] && to.f != p && to.s != lst)
			dfs1(to.f, c, v, to.s);
}



void centroid(int v) {
	vals.clear();
	dfs(v);
	Sz = cnt[v];
	v = Find(v);

	sort(all(vals));
	for (int i = 0; i < sz(vals); ++i) {
		pos[vals[i]] = i + 1;
		col[vals[i]] = -1;
	}


	for (int i = 0; i <= sz(vals) + 1; ++i)
		pref[i] = mp(mp(-inf, -inf), mp(-inf, -inf));

	d[v] = 0;
	mx[v] = v;

	for (auto to : g[v])
		if (!was[to.f])
			dfs1(to.f, to.s, v, to.s);

	pref[0] = mp(mp(0, 0), mp(-inf, -inf));

	for (int i = 1; i <= sz(vals); ++i)
		pref[i] = merge(pref[i], pref[i - 1]);

	for (int i = 1; i <= sz(vals); ++i) {
		int x = vals[i - 1];
		if (col[x] == -1)
			continue;

		pair < pii, pii > cur = pref[pos[mx[x]] - 1];
/*		if (v == 2) {
			cerr << x << ' ' << col[x] << ' '<< (cur.f.s == col[x] ? cur.s.f : cur.f.f) << ' ' << d[x] << endl;
			cerr << cur.f.f << ' ' << cur.f.s << ' ' << cur.s.f << ' ' << cur.s.s << endl << endl;
		}*/
		ans[mx[x]] = max(ans[mx[x]], (cur.f.s == col[x] ? cur.s.f : cur.f.f) + d[x]);
	}

	was[v] = 1;
	for (auto to : g[v])
		if (!was[to.f])
			centroid(to.f);
	
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x, c;
		scanf("%d%d", &x, &c);
		g[i + 1].pb({x, c});
		g[x].pb({i + 1, c});
	}

	centroid(1);
	for (int i = 2; i <= n + 1; ++i) {
		ans[i] = max(ans[i - 1], ans[i]); 
		printf("%d\n", ans[i]);	
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
