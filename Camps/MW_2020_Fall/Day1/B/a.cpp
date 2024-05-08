#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, a[N], b[N], c[N], w, dist[N][N];
set < pair < pair < ll, int >, pii > > q;
vi vals, g[N], gg[N][N];
ll d[N][11][N];


main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i];

	cin >> w >> m;

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j)  {
			if (i == j)
				continue;			
			dist[i][j] = abs(a[i] - a[j]) + abs(b[i] - b[j]);
			if (dist[i][j] > w)
				dist[i][j] = -1;
			else
				vals.pb(dist[i][j]);
		}	

	vals.pb(0);
	vals.pb(w);

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && dist[i][j] != -1) {
				dist[i][j] = lower_bound(all(vals), dist[i][j]) - vals.begin();
				g[i].pb(dist[i][j]);
			}

	g[2].pb(0);

	for (int i = 1; i <= n; ++i) {
		g[i].pb(sz(vals) - 1);//w
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());

		for (int j = 1; j <= n; ++j)
			if (i != j && dist[i][j] != -1) {
				int dd = lower_bound(all(g[i]), dist[i][j]) - g[i].begin();
				gg[i][dd].pb(j);
			}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < sz(g[i]); ++j)
			for (int x = 1; x <= m + 1; ++x)
				d[i][x][j] = INF;

	d[1][1][0] = vals[g[1][0]] * 1ll * c[1];
	q.insert(mp(mp(d[1][1][0], 1), mp(1, 0)));

	while (sz(q)) {
		pair < pair < ll, int >, pii > cur = *q.begin();
		q.erase(q.begin());

		ll curd = cur.f.f;
		int v = cur.f.s, i = cur.s.f, j = cur.s.s;
		
		if (v == 2) {
			cout << curd << endl;
			return 0;
		}

		if (i == m + 1)
			continue;


		if (j < sz(g[v]) - 1) {
			ll cost = curd + (vals[g[v][j + 1]] - vals[g[v][j]]) * 1ll * c[v];
			if (d[v][i][j + 1] > cost) {
				q.erase(mp(mp(d[v][i][j + 1], v), mp(i, j + 1)));
				d[v][i][j + 1] = cost;
				q.insert(mp(mp(d[v][i][j + 1], v), mp(i, j + 1)));
			}
		} else {
			for (int u = 1; u <= n; ++u)
				if (u != v && dist[v][u] != -1) {
					int tmp = w - vals[dist[v][u]];
					int jj = lower_bound(all(vals), tmp) - vals.begin();
					jj = lower_bound(all(g[u]), jj) - g[u].begin();
					
					ll cost = curd + (vals[g[u][jj]] - tmp) * 1ll * c[u];
					if (d[u][i + 1][jj] > cost) {
						q.erase(mp(mp(d[u][i + 1][jj], u), mp(i + 1, jj)));
						d[u][i + 1][jj] = cost;
						q.insert(mp(mp(d[u][i + 1][jj], u), mp(i + 1, jj)));
					}
				}
		}
		
//		if (i < m) {
			for (auto u : gg[v][j]) {
				ll cost = curd + vals[g[u][0]] * 1ll * c[u];
				if (d[u][i + 1][0] > cost) {
					q.erase(mp(mp(d[u][i + 1][0], u), mp(i + 1, 0)));
					d[u][i + 1][0] = cost;
					q.insert(mp(mp(d[u][i + 1][0], u), mp(i + 1, 0)));
				}
			}
//		}
	}

	cout << -1 << endl;
}