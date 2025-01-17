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
const int N = 1e6, inf = 2e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 3e18;

vi g[M], gr[M];
int n, m, k, h[M];
pii ans[M], dp[M], pref[M], suff[M];
 
void solve() {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &h[i]);
	

	while (m--) {
		int a, b;
		scanf("%lld%lld", &a, &b);
		g[a].pb(b);
		gr[b].pb(a);
	}

	for (int v = 1; v <= n; ++v) {
		ans[v] = mp(0, 0);
		for (auto to : gr[v])
			ans[v] = max(ans[v], ans[to]);

		if (ans[v].s <= h[v])
			ans[v].s = h[v];
		else {
			ans[v].f++;
			ans[v].s = h[v];
		}
	}

	for (int v = n; v > 0; --v) {
		pii mn = mp(2*n, inf);

		for (auto to : g[v])
			mn = min(mn, ans[to]);		
		
		assert(ans[v] <= mn);
		if (ans[v].f < mn.f - 1)
			ans[v].f = mn.f - 1;

		while (mp(ans[v].f + 1, ans[v].s) <= mn)
			ans[v].f++;

		assert(ans[v] <= mn);
	}

	for (int v = n; v > 0; --v) {
		dp[v] = ans[v];
		for (auto to : g[v])
			dp[v] = max(dp[v], dp[to]);	
	}

	ll res = INF;

	vector < pair < int, pii > > vv;
	for (int i = 1; i <= n; ++i) {
		assert(dp[i].f == 2*n);
		vv.pb(mp(dp[i].s, ans[i]));
	}


		
	sort(all(vv));
	pref[0] = vv[0].s;
	for (int i = 1; i < sz(vv); ++i)
		pref[i] = min(pref[i - 1], vv[i].s);
	
	suff[sz(vv)] = mp(inf, inf);
	for (int i = sz(vv) - 1; i >= 0; --i)
		suff[i] = min(suff[i + 1], vv[i].s);

	for (int i = 0; i < sz(vv); ++i) {
		ll e = (2*n + 1)*1ll*k + vv[i].f;
		pii curmn = min(suff[i + 1], mp(pref[i].f + 1, pref[i].s));
		ll s = curmn.f * 1ll * k + curmn.s;
		assert(s <= e);
		res = min(res, e - s);
	}

	printf("%lld\n", res);


	for (int i = 0; i <= n+n; ++i) {
		g[i].clear();
		gr[i].clear();
		ans[i] = mp(0, 0);
		dp[i] = mp(0, 0);
		pref[i] = mp(0, 0);
		suff[i] = mp(0, 0);
	}
}

main () {
  int TT;
  TT = 1;
	fastio
	scanf("%lld", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve(tt);
  }
}