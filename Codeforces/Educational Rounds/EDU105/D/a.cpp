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
const int inf = 1e9, maxn = 1e5 + 11, mod = 1e9 + 7, N = 512;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, a[N][N], k, b[maxn], ans[maxn];
vi gg[N], G[maxn];
vpii g[maxn];
bool was[N];

void dfs (int v) {
//	cerr << k << ' ' << v << endl;
	G[v].pb(k);
	was[v] = 1;
	for (auto to : gg[v])
		if (!was[to])
			dfs(to);
}

main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (i == j)
				b[i] = a[i][j];
			else
				g[a[i][j]].pb({i, j});
		}

	k = n;
	for (int i = 1; i < maxn; ++i) {
		for (auto x : g[i]) {
			gg[x.f].clear();
			gg[x.s].clear();
		}

		memset(was, 0, sizeof(was));
		for (auto x : g[i]) {
			gg[x.f].pb(x.s);
			gg[x.s].pb(x.f);
		}

		for (auto x : g[i]) {
			if (!was[x.f]) {
				b[++k] = i;
				dfs(x.f);
			}

			if (!was[x.s]) {
				b[++k] = i;
				dfs(x.s);
			}
		}			
	}

	for (int i = 1; i <= n; ++i) {
		sort(all(G[i]));
		G[i].resize(unique(all(G[i])) - G[i].begin());
		ans[i] = G[i][0];
		for (int j = 1; j < sz(G[i]); ++j)
			ans[G[i][j - 1]] = G[i][j];
	}

	cout << k << endl;
	for (int i = 1; i <= k; ++i)
		cout << b[i] << ' ';

	cout << endl << k << endl;

	for (int i = 1; i < k; ++i)
		cout << i << ' ' << ans[i] << endl;
}