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

int d[M], tin[M], tout[M], timer;
ll s1[M], s2[M], ans[M];
int n, k;
int c[M];
vi g[M];
int up[M][20];
vector < pii > r, b;

void clear() {
	r.clear();
	b.clear();
	timer = 0;
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		ans[i] = 0;
	}
}


void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	d[v] = d[p] + 1;

	up[v][0] = p;
	for (int i = 1; i < 20; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (auto to : g[v]) {
		if (to == p)
			continue;
		dfs(to, v);						
	}

	tout[v] = timer;
}


int lca(int v, int u) {
	if (d[v] < d[u])
		swap(v, u);


	for (int i = 19; i >= 0; --i)
		if (d[v] - (1 << i) >= d[u])
			v = up[v][i];

	if (v == u)
		return v;

	for (int i = 19; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			v = up[v][i];
			u = up[u][i];
		}

	return up[v][0];		
}


int dist(int v, int u) {
	int l = lca(v, u);
	return d[v] + d[u] - 2*d[l];
}


void deletion() {
	int k1 = (k - 1) / 2;

	for (int i = 0; i < k / 2 + 1; ++i) {
		s1[i] = (!i ? 0 : s1[i - 1]) + dist(r[i].s, r[i + k1].s);
		s2[i] = (!i ? 0 : s2[i - 1]) + (i < k/2 ? dist(r[i].s, r[i + k1 + 1].s) : 0);
	}

	for (int i = 0; i < k; ++i) {
		if (i <= k/2)
			ans[r[i].s] = (i - 1 >= 0 ? s2[i - 1] : 0) + (s1[k/2]-s1[i]);
		else {
			ans[r[i].s] = s1[i - k1 - 1] + s2[k/2-1]-s2[i - k1 - 1];
		}
	}
}


void insertion() {
	int i = -1;
	int k1 = (k - 1) / 2;
	for (auto x : b) {
		while (i + 1 < sz(r) && r[i + 1].f < x.f)
			++i;

		if (i < k/2) {
			int ii = i + 1;
			ans[x.s] = (!ii ? 0 : s1[ii - 1]) + dist(x.s, r[ii + k1].s) + (s2[k/2-1]-s2[ii-1]);
		} else
			ans[x.s] = dist(x.s, r[i-k/2].s) + (i==k/2 ? 0 : s2[i-k/2-1]) + (s1[k/2] - s1[i-k/2]);
	}
}

 
void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	dfs(1);
	for (int i = 1; i <= n; ++i) {
		if (c[i])
			r.pb(mp(tin[i], i));
		else
			b.pb(mp(tin[i], i));
	}

	sort(all(r));
	sort(all(b));

	deletion();
	insertion();

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << "\n";

	clear();
}

main () {
  int TT;
  TT = 1;
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}