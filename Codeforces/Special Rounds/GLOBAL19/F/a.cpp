//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, h[M], tin[M], tout[M], par[M], timer, pref[M], suff[M];
int mx[M], mx1[M], a[M];
ll s[M];
vi g[M];

void add(int l, int r, int x) {
	if (l > r)
		return;

	s[l] += x;
	s[r + 1] -= x;
}

void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	a[timer] = v;
	mx[v] = h[v];
	par[v] = p;

	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			mx[v] = max(mx[v], mx[to]);
		}
		
	tout[v] = timer;
}

void solve() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &h[i]);

	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%lld%lld", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
	for (int i = 1; i <= n; ++i)
		pref[i] = max(pref[i - 1], h[a[i]]);

	for (int i = n; i > 0; --i)
		suff[i] = max(suff[i + 1], h[a[i]]);
	for (int i = 1; i <= n; ++i)
		mx1[i] = max(pref[tin[i] - 1], suff[tout[i] + 1]);

	for (int v = 1; v <= n; ++v) {		
		vector < pii > vv;
		for (auto u : g[v])
			if (u == par[v])
				vv.pb({mx1[v], u});
			else
				vv.pb({mx[u], u});
		
		sort(all(vv));
		for (int i = 0; i < sz(vv); ++i) {
			int u = vv[i].s, x;
			if (sz(vv) == 1)
				x = h[v];
			else if (i == sz(vv) - 1) 
				x = max(0ll, h[v] - vv[sz(vv) - 2].f);
			else
				x = max(0ll, h[v] - vv.back().f);
			
			if (u == par[v]) {
				add(1, tin[v] - 1, x);
				add(tout[v] + 1, n, x);				
			} else
				add(tin[u], tout[u], x);
		}
		            
		add(tin[v], tin[v], max(0ll, h[v] - vv.back().f));
	}

	ll ss = 0;
	for (int i = 2; i <= n; ++i)
		ss += h[i];

	ll ans = INF, mx = 0;
	for (int i = 1; i <= n; ++i) {
		s[i] += s[i - 1];
		mx = max(mx, (ll)h[i]);
		ans = min(ans, s[i]);
	}

	cout << ans + mx << endl;
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}