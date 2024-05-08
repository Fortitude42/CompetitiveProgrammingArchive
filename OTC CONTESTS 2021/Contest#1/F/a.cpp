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

int n, c, d, a[N], b[N], p[N], mx1[N], mx2[N];
int tin[N], tout[N], timer;
bool was[N];
vi g[N];

void dfs(int v, int par = 0) {
	p[v] = par;
	mx1[v] = a[v];
	tin[v] = ++timer;

	for (auto to : g[v])
		if (to != par) {
			dfs(to, v);
			if (mx1[to] > mx1[v]) {
				mx2[v] = mx1[v];
				mx1[v] = mx1[to];
			} else if (mx1[to] > mx2[v])
				mx2[v] = mx1[to];
		}

	tout[v] = timer;
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}


main (){
	scanf("%d%d%d", &n, &c, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);       
		b[a[i]] = i;
	}

	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	was[b[0]] = 1;
	dfs(b[0]);

	ll ans = 0;
	int x = b[0], y = b[0], Mx = 0, s = 0;

	for (int i = 0; i < n; ++i) {
		int v = b[i];

		if (!was[v]) {
			if (upper(x, v)) {
				int xx = x;
				x = v;
				while (!was[v]) {
					was[v] = 1;
					Mx = max(Mx, a[v]);
					if (p[v] == b[0])
						s = v;
					v = p[v];
				}
				if (v != xx) 
					break;    
			} else if (upper(y, v)) {
				int yy = y;
				y = v;
				while (!was[v]) {
					was[v] = 1;
					Mx = max(Mx, a[v]);
					if (p[v] == b[0])
						s = v;
					v = p[v];
				}
				if (v != yy)
					break;
			} else
				break;
		}

		int cur = max(Mx, mx1[x]);
		cur = max(cur, (y == b[0] && mx1[y] == mx1[s]) ? mx2[y] : mx1[y]);
		ans = max(ans, (i + 1) * 1ll * c + d * 1ll * cur);
	}
	cout << ans << endl;
}