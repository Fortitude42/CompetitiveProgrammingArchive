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

int n, x, tin[N][2], tout[N][2], timer[2];
vi g[N][2], t[N << 2];
 
void dfs (int v, int i) {
	tin[v][i] = ++timer[i];
	for (auto to : g[v][i]) 
		dfs(to, i);

	tout[v][i] = timer[i];
}

void update (int pos, int x, int v = 1, int tl = 1, int tr = n) {
	t[v].pb(x);
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);	
}

int f (int i, int l, int r) {
	if (t[i][0] > r || t[i].back() < l)
		return 0;

	int lf = lower_bound(all(t[i]), l) - t[i].begin();
	int rg = upper_bound(all(t[i]), r) - t[i].begin();

	return rg - lf;
}

int get (int l, int r, int a, int b, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r) 
		return f(v, a, b);

	int tm = (tl + tr) >> 1;
	return get(l, r, a, b, v << 1, tl, tm) + get(l, r, a, b, v << 1 | 1, tm + 1, tr);
}

main () {
	scanf("%d", &n);
	for (int j = 0; j < 2; ++j) 
		for (int i = 2; i <= n; ++i) {
			scanf("%d", &x);
			g[x][j].pb(i);
		}

	dfs(1, 0);
	dfs(1, 1);

	for (int i = 1; i <= n; ++i)
		update(tin[i][0], tin[i][1]);

	for (int i = 0; i < (N << 2); ++i)
		sort(all(t[i]));
	
	for (int i = 1; i <= n; ++i) 
		printf("%d ", get(tin[i][0], tout[i][0], tin[i][1], tout[i][1]) - 1);	
}