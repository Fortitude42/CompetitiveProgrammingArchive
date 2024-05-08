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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


unordered_map < int, short > cnt[N][N], dp[N][N];
vector < pair < pii, int > > gg[N][N][30];
queue < pair < pii, int > > q;
int n, m;
vpii g[N];


main () {
	cin >> n >> m;
	while (m--) {
		int v, u;
		char c;
		cin >> v >> u >> c;
		g[v].pb({u, c - 'a'});
//		g[u].pb({v, c - 'a'});	
	}

	for (int v = 1; v <= n; ++v)
		for (int u = 1; u <= n; ++u) {
		    bool ok = 0;
			for (auto x : g[v]) {
				bool ok1 = 1;
				for (auto y : g[u]) 
					if (x.s == y.s) {
						ok1 = 0;
						break;
					}
				ok |= ok1;
			}      

			if (ok) {
				dp[v][u][26] = 1;
				q.push({{v, u}, 26});
//				cerr << v << ' ' << u << endl;
			}
		}
					

		
	for (int v = 1; v <= n; ++v) 
		for (int u = 1; u <= n; ++u) {
			for (auto x : g[v]) {
				++cnt[v][u][26];
				gg[x.f][u][x.s].pb({{v, u}, 26});
			}

			for (auto x : g[u]) {
				++cnt[v][u][x.s];
				gg[v][x.f][26].pb({{v, u}, x.s});
			}
		}

				


	while (sz(q)) {
		int a = q.front().f.f, b = q.front().f.s, c = q.front().s;
		q.pop();
		for (auto d : gg[a][b][c]) {
			int x = d.f.f, y = d.f.s, z = d.s;
			if (dp[x][y].count(z))
				continue;
			if (dp[a][b][c] == 2) 
				dp[x][y][z] = 1;
			else if (--cnt[x][y][z] == 0)
				dp[x][y][z] = 2;
			else
				continue;
			q.push(mp(mp(x, y), z));	
		}
	}


	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			ans += (dp[i][j].count(26) && dp[i][j][26] == 1);
//			if (dp[i][j][26] == 1)
//				cerr << i << ' ' << j << endl;
		}


	cout << ans << endl;
}