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

int n, m, k, w, d[N][N], p[N], res;
vector < pair < int, pii > > e;
char c[N][20][20];
bool was[N];
vpii ans;
vi g[N];

int get (int a, int b) {
	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			res += (c[a][i][j] != c[b][i][j]);

	return res * w;
} 

int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}


void merge (int v, int u, int c) {
	int V = get(v), U = get(u);

	if (V == U)
		return;

	if (rand() & 1)
		swap(v, u);

	p[U] = V;
	res += c;

	g[v].pb(u);
	g[u].pb(v);
}

void dfs (int v, int p) {
	ans.pb({v, p});
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to])
			dfs(to, v);

}




main () {
	cin >> n >> m >> k >> w;
	for (int x = 1; x <= k; ++x)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> c[x][i][j];

	for (int i = 1; i <= k; ++i)
		p[i] = i;

	for (int i = 1; i <= k; ++i)
		for (int j = i + 1; j <= k; ++j) {
			int c = get(i, j);
			if (c < n*m)
				e.pb(mp(c, mp(i, j)));
		}

	sort(all(e));

	for (auto i : e) 
		merge(i.s.f, i.s.s, i.f);
	

	for (int i = 1; i <= k; ++i) 
		if (!was[i]) {
			res += n*m;
			dfs(i, 0);
		}

	cout << res << endl;
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;
}