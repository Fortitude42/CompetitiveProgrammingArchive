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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vi g[N];
int n, v, u, cnt[N];
db l[N], r[N], x[N], y[N];

db get (db xa, db ya, db xb) {
	return ya - sqrt(1 - (xa - xb) * (xa - xb));
}

void dfs (int v, int p = 0) {
	cnt[v] = 1;
	for (auto to : g[v])
		if (to != p) {
			dfs(to, v); 
			cnt[v] += cnt[to];
		}
}

void dfs1 (int v, int p = 0) {
	if (cnt[v] == 1)
		return;

	db X = (r[v] - l[v]) / (cnt[v] - 1);
	db L = l[v];
	for (auto to : g[v])
		if (to != p) {
			l[to] = L, r[to] = L + X*cnt[to];
			x[to] = (l[to] + r[to]) / 2;
			y[to] = get(x[v], y[v], x[to]);

			dfs1(to, v);
			L += X*cnt[to];
		}
}
 
main () {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >>  v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
	
	l[1] = -1, r[1] = 1;
	x[1] = 0, y[1] = 0;

	dfs1(1);
	cout << setprecision(9) << fixed;
	cerr << setprecision(9) << fixed;
	for (int i = 1; i <= n; ++i)
		cout << x[i] << ' ' << y[i] << endl;
//	for (int i = 1; i <= n; ++i)
//		cerr << l[i] << ' ' << r[i] << endl;
}