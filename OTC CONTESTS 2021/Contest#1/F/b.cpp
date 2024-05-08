#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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

int n, c, d, a[N], b[N], mx[N], mx1[N][2], mx2[N], D[N];
int tin[N], tout[N], timer, Mx, up[N][18], s[N][2], s1[N];
bool was[N];
vi g[N];
 
void dfs(int v, int p = 0) {
	D[v] = D[p] + 1;
	tin[v] = ++timer;
	mx[v] = a[v];

	up[v][0] = p;
	for (int i = 1; i < 18; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			if (mx[to] > mx[v]) {
				mx1[v] = mx[v];
				s1[v] = s[v];
				mx[v] = mx[to];
				s[v] = to;
			} else if (mx[to] > mx1[v]){
				mx1[v] = mx[to];         
				s1[v] = to;
			}
		}

	tout[v] = ++timer;
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
	if (D[v] < D[u])
		swap(v, u);
	for (int i = 17; i >= 0; --i)
		if (D[v] - (1 << i) >= D[u])
			v = up[v][i];

	if (v == u)
		return v;

	for (int i = 17; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			v = up[v][i];
			u = up[u][i];
		}

	return up[v][0];			
}


main () {
	scanf("%lld%lld%lld", &n, &c, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		b[a[i]] = i;
	}
	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%lld%lld", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
	for (int i = 2; i <= n; ++i) {
		int p = up[i][0];
		mx2[i] = max(mx2[p], mx[i] == mx[p] ? mx1[p] : mx[p]);
	}
	ll ans = (n - 1) * 1ll * d + c;

	was[b[0]] = 1;
	int v = b[0], u = b[0];

	for (int i = 1; i < n; ++i) {
		if (D[v] > D[u])
			swap(v, u);

		int j = b[i];
		int l = lca(v, u);
//		cerr << j << ' ' << v << ' ' << u << ' ' << l << endl;


		if (!was[j]) {
			if (!upper(l, j)) {
				if (l != v)
					break;				
				while (!upper(l, j)) {
					l = up[l][0];
					was[l] = 1;
					Mx = max(Mx, a[l]);
				}
				v = l;
			}

			assert(upper(l, j));
			//upper(l, j) is true;
			int jj = j;
			while (!was[j]) {
				was[j] = 1;
				Mx = max(Mx, a[j]);
				j = up[j][0];
			}

			if (j == v) {
				v = jj;
			} else if (j == u) {
				u = jj;
			} else
				break;
		}

		int curMx = Mx;
		if (D[v] > D[u])
			swap(v, u);

		if (v == l)
			curMx = max(curMx, mx2[v]);

		curMx = max(curMx, was[s[v]] ? mx1[v] : mx[v]);
		curMx = max(curMx, was[s[u]] ? mx1[u] : mx[u]);
//		cerr << curMx << ' ' << i << endl;
		ans = max(ans, c * 1ll * (i + 1) + curMx * 1ll * d);
	}

	cout << ans << endl;
	cerr << ans << endl;
}