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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, k, c[M], d[M][2], res[M][M][104];
queue < pii > q;
vi g[M];
 
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	while (m--) {
		int s, t;
		cin >> s >> t;
		g[s].pb(t);
		g[t].pb(s);
	}

	for (int i = 1; i <= n; ++i)
		for( int j = 1; j <= n; ++j)
			for (int x = 0; x <= k; ++x)
				res[i][j][x] = inf;


	for (int i = 1; i <= n; ++i) {
		memset(d, -1, sizeof d);
		d[i][0] = 0;
		q.push(mp(i, 0));
		while (sz(q)) {
			int v = q.front().f, tp = q.front().s;
			q.pop();

			int cur = !tp ? 0 : k;
			for (int b = 0; b <= k; ++b)
				res[i][v][b] = min(res[i][v][b], d[v][tp] + abs(cur - b));


			for (auto to : g[v]) {
				int tp1 = tp ^ (c[v] != c[to]);
				if (d[to][tp1] == -1) {
					d[to][tp1] = d[v][tp] + 1;
					q.push(mp(to, tp1));
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			for (int x = 0; x <= k; ++x)
				ans = max(ans, res[i][j][x]); 
		
		

	cout << ans << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}