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
 

const int N = 2005;

vi g[N];
int n, q, a[N], b[N], c[N];
ll pref[N][N], suff[N][N], dist[N][N], mx[N][N], dd[N][N];
int d[N][N], up[N][N][11], tin[N][N], tout[N][N];

void dfs(int v, int root, int p = 0, ll dep = 0) {
	tin[root][v] = ++tin[root][0];
	pref[root][tin[root][0]] = dep;
	dist[root][v] = dep;
	mx[root][v] = dep;


	d[root][v] = d[root][p] + 1;
	up[root][v][0] = p;
	for (int i = 1; i < 11; ++i)
		up[root][v][i] = up[root][up[root][v][i - 1]][i - 1];	

	for (auto i : g[v]) {
	    int to = a[i]^b[i]^v;
		if (to != p) {
			dfs(to, root, v, dep + c[i]);
			mx[root][v] = max(mx[root][v], mx[root][to]);
		}
	}

	tout[root][v] = tin[root][0];
	dd[root][v] = mx[root][v] - 2*dep;
}

void dfs1(int v, int root, int p = 0) {
	dd[root][v] = max(dd[root][v], dd[root][p]);
	for (auto i : g[v]) {
	    int to = a[i]^b[i]^v;
		if (to != p) {
			dfs1(to, root, v);
		}
	}
}


int lca(int v, int u, int root) {
	if (d[root][v] < d[root][u])
		swap(v, u);

	for (int i = 10; i >= 0; --i)
		if (d[root][v] - (1 << i) >= d[root][u])
			v = up[root][v][i];

	if (v == u)
		return v;

	for (int i = 10; i >= 0; --i)
		if (up[root][v][i] != up[root][u][i]) {
			v = up[root][v][i];
			u = up[root][u][i];
		}

	return up[root][v][0];
}
 
void solve() {
	cin >> n >> q;
	ll sum = 0;
	for (int i = 1; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		sum += c[i];
		g[a[i]].pb(i);
		g[b[i]].pb(i);
	}

	for (int v = 1; v <= n; ++v) {
		dfs(v, v);
		dfs1(v, v);

		suff[v][n] = pref[v][n];
		for (int u = n - 1; u > 0; --u)
			suff[v][u] = max(suff[v][u + 1], pref[v][u]);

		for (int u = 2; u <= n; ++u)
			pref[v][u] = max(pref[v][u - 1], pref[v][u]);
	}
	

	while (q--) {
		int s, k, t;
		cin >> s >> k >> t;
		int kk = k;

		int l = lca(k, t, s);
		if (l == t) {
			cout << "impossible\n";
			continue;
		}

		if (l == k) {
			cout << sum*2 - pref[s][n] << "\n";			
			continue;
		}

		int delta = d[s][k] - d[s][l] - 1;
		for (int i = 10; i >= 0; --i)
			if (delta >= (1 << i)) {
				delta -= (1 << i);
				k = up[s][k][i];
			}

		ll mx = max(pref[s][tin[s][k] - 1], suff[s][tout[s][k] + 1]);
		mx = max(mx, dd[s][kk] + 2*dist[s][l]);

		
		cout << sum*2 - mx << "\n";
	}
}

main () {
  int TT;
  TT = 1;
  fastio
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}