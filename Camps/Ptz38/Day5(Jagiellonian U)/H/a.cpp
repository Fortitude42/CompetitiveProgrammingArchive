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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 312;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

long double dp[N][N][2], x[N], y[N];
int t, n, m, v, u;
vi g[N];
 
long double dist (int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

bool in (int l, int r, int x) {
	if (l <= r)
		return (l <= x && x <= r);

	return x >= l || x <= r;
}

long double rec (int l, int r, int tp) {
//	cerr << l << ' ' << r << ' ' << tp << endl;
	long double &res = dp[l][r][tp];
	if (res != -1)
		return res;

	if (l == r)
		return res = 0;

	res = 0;
	if (!tp) {
		for (auto x : g[l])
			if (in(l, r, x)) 
				res = max(res, dist(x, l) + max(rec(x, r, 0), rec((l + 1) % n, x, 1)));		
		return res;
	}

	for (auto x : g[r])
		if (in(l, r, x))
			res = max(res, dist(x, r) + max(rec(l, x, 1), rec(x, (r + n - 1) % n, 0)));

	return res;
}



main () {
	cout << setprecision(7) << fixed;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];     
			g[i].clear();
		}

		cin >> m;
		while (m--) {
			cin >> v >> u;
			--v, --u;
			g[v].pb(u);
			g[u].pb(v);
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				for (int x = 0; x < 2; ++x)
					dp[i][j][x] = -1;
	

					
		long double ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				for (int x = 0; x < 2; ++x)
					ans = max(ans, rec(i, j, x));

		cout << ans << endl;
	}
}