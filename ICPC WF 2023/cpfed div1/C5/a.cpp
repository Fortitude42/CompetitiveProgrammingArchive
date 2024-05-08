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
const int N = 3e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int id[M], q, c[M];
int n, a[M], b[M], up[M][20], mx[M][20], d[M], p[M];
vi g[M], comp[M];

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (sz(comp[v]) < sz(comp[u]))
		swap(v, u);

	p[u] = v;
	for (auto x : comp[u])
		comp[v].pb(x);
	comp[u].clear();
}


void dfs(int v, int p = 0) {
	for (auto i : g[v]) {
		int to = a[i]^b[i]^v;
		if (to == p)
			continue;

		d[to] = d[v] + 1;
		up[to][0] = v;
		mx[to][0] = i;
		for (int i = 1; i < 20; ++i) {
			up[to][i] = up[up[to][i - 1]][i - 1];
			mx[to][i] = max(mx[to][i - 1], mx[up[to][i - 1]][i - 1]);
		}

	    dfs(to, v);
	}
}

int dist(int v, int u) {
	int res = 0;
	if (d[v] < d[u])
		swap(v, u);

	for (int i = 19; i >= 0; --i)
		if (d[v] - (1 << i) >= d[u]) {
			res = max(res, mx[v][i]);
			v = up[v][i];
		}


	if (v == u)
		return res;

	for (int i = 19; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			res = max({res, mx[v][i], mx[u][i]});
			v = up[v][i];
			u = up[u][i];
		}

	res = max({res, mx[v][0], mx[u][0]});
	return res;
}


bool cmp(int a, int b) {
	return id[a] < id[b];
}

 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		comp[i] = {i};
	}		

	for (int i = 1; i < n; ++i) {
		cin >> a[i] >> b[i];
		g[a[i]].pb(i);
		g[b[i]].pb(i);
		merge(a[i], b[i]);
	}

	dfs(1);
	int root = get(1);
	for (int i = 0; i < sz(comp[root]); ++i)
		id[comp[root][i]] = i;
	
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; ++i)
			cin >> c[i];

		sort(c + 1, c + 1 + k, cmp);

		int ans = 1;
		for (int i = 1; i <= k; ++i) {
			int cur = n;
			if (i > 1)	{
				cur = min(cur, dist(c[i], c[i - 1]));
//				cerr << c[i] << ' ' << c[i - 1] << ' ' << dist(c[i], c[i - 1]) << endl;
			}

			if (i < k) {
				cur = min(cur, dist(c[i], c[i + 1]));
//				cerr << c[i] << ' ' << c[i + 1] << ' ' << dist(c[i], c[i + 1]) << endl;
			}
			ans = ans * 1ll * cur % MOD;
		}

		cout << ans << '\n';
	}
}

main () {
	fastio
  	int TT;
  	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}