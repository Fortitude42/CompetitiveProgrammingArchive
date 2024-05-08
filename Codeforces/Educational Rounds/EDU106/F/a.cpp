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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 5012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, dp[N][N], dp1[N][N], pref[N], suff[N];
vi g[N];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;
	}

	return res;
}

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

void dfs (int v, int p = 0) {
	for (int i = 0; i < sz(g[v]); ++i)
		if (g[v][i] == p) {
			swap(g[v][i], g[v].back());
			g[v].ppb();
		}

	for (auto to : g[v])
		dfs(to, v);

	dp[v][0] = 1;
	for (auto to : g[v])
		if (to != p) 
			dp[v][0] = dp[v][0] * 1ll * dp1[to][k] % mod;

	dp1[v][0] = dp[v][0];
		
	
	for (int len = 1; len <= k; ++len) {
		int cur = 1, cnt = 0;
		for (int i = 0; i < sz(g[v]); ++i) {
			int to = g[v][i];
			pref[i] = !i ? 1 : pref[i - 1];
//			if (v == 6 && len == 2 && to == 5)
//				cerr << dp1[to][k]  << ' ' <<  ((len == 1 || len == k) ? 0 : dp1[to][min(k - len - 1, len - 2)]) << endl;
			pref[i] = pref[i] * 1ll * (dp1[to][k] + (len == 1 || len == k? 0 : dp1[to][min(k - len - 1, len - 2)])) % mod;
		}

		suff[sz(g[v])] = 1;
		for (int i = sz(g[v]) - 1; i >= 0; --i) {
			int to = g[v][i];
			suff[i] = suff[i + 1] * 1ll * (dp1[to][k] + (len == k ? 0 : dp1[to][min(k - len - 1, len - 1)])) % mod; 
		}

		for (int i = 0; i < sz(g[v]); ++i) {
			int to = g[v][i];
//			if (v == 6 && len == 2)
//				cerr << "-->" << to << ' ' << dp[to][len - 1] << ' ' << (!i ? 1 : pref[i - 1]) << ' ' << suff[i + 1] << endl;
			add(dp[v][len], (!i ? 1 : pref[i - 1]) * 1ll * suff[i + 1] % mod * dp[to][len - 1] % mod);
		}

		dp1[v][len] = dp[v][len] + dp1[v][len - 1];
		if (dp1[v][len] >= mod)
			dp1[v][len] -= mod;
	}
}
 
main () {
	cin >> n >> k;
	for (int i = 1, v, u; i < n; ++i) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
//	for (int i = 1; i <= n; ++i, cerr << endl)
//		for (int len = 0; len <= k; ++len)
//			cerr << dp[i][len] << ' ';

	cout << dp1[1][k] << endl;
}