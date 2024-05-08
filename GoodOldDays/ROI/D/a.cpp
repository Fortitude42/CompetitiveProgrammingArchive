#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
                       	
#define int long long 
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, k, v, u, ans, d, V, mx, sum, par[N], a[N], b[N], cnt[N];
vpii tmp;
vi g[N];

void dfs (int v, int p = 0) {
	cnt[v] = 1;
	par[v] = p;

	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			cnt[v] += cnt[to];
		}
}

void dfs1 (int v, int p = 0, int d = 0) {
	sum += d;
	for (auto to : g[v])
		if (to != p) 
			dfs1(to, v, d + 1);		
}

void dfs2 (int v, int par = 0, int d = 0) {
	tmp.pb({d, v});
	for (auto to : g[v])
		if (to != par)
			dfs2(to, v, d + 1);
}



main () {
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
	V = 2;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] >= k && (n - cnt[i]) >= k) {
			sum = 0;
			dfs1(i, par[i], 0);
			dfs1(par[i], i, 1);
			if (sum > mx) {
				V = i;
				mx = sum;
			}
		}
	}

	assert(cnt[V] == k);

	dfs2(V, par[V], 0);
	sort(all(tmp));
	reverse(all(tmp));
	for (int i = 1; i <= k; ++i)
		a[i] = tmp[i - 1].s;

	tmp.clear();

	dfs2(par[V], V, 0);
	sort(all(tmp));
	reverse(all(tmp));
	for (int i = 1; i <= k; ++i)
		b[i] = tmp[i - 1].s;

	for (int i = 1; i <= k; ++i)
		cout << a[i] << ' ' << b[i] << endl;
}

