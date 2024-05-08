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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
 
set < pair < pair < ll, int >, pii > > q;
int n, m, v, u, w;
ll d[N][2][2];
vpii g[N];
 
 
 
main () {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &v, &u, &w);
		g[v].pb({u, w});
		g[u].pb({v, w});
	}
 
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			for (int x = 0; x < 2; ++x)
				d[i][j][x] = INF;
 
	d[1][0][0] = 0;
	q.emplace(mp(mp(0, 1), mp(0, 0)));
 
	while (sz(q)) {
		pair < pair < ll, int >, pii > cur = *q.begin();
		q.erase(q.begin());
 
		int v = cur.f.s, x = cur.s.f, y = cur.s.s;
		ll z = cur.f.f;
		if (d[v][x][y] != z)
			continue;

		for (auto to : g[v]) {
			u = to.f, w = to.s;
			if (d[u][x][y] > z + w) {
				d[u][x][y] = d[v][x][y] + w;
				q.emplace(mp(mp(d[u][x][y], u), mp(x, y)));
			}
 
			if (!x && d[u][1][y] > z) {
				d[u][1][y] = d[v][x][y];
				q.emplace(mp(mp(d[u][1][y], u), mp(1, y)));
			}
			                                         
			if (!y && d[u][x][1] > z + 2*w) {
				d[u][x][1] = d[v][x][y] + 2*w;
				q.emplace(mp(mp(d[u][x][1], u), mp(x, 1)));
			}
		}		
	}
 
	for (int i = 2; i <= n; ++i)
		printf("%lld ", min(d[i][0][0], d[i][1][1]));
}