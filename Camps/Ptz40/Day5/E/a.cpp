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
 
const int inf = 1e9, maxn = (1 << 19) + 20, mod = 1e9 + 7, N = 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, v[N], u[N], col[N], k, dp[maxn], f[N], rf[N], cnt[maxn];
queue < int > q;
int msk[N][N];
vpii g[N];

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

int ank (int n, int k) {
	return f[n] * 1ll * rf[n - k] % mod;
}

void precalc () {
	f[0] = 1;
	for (int i = 1;  i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % mod;

	rf[N - 1] = binpow(f[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;
}

main () {
	precalc();

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> v[i] >> u[i];
		if (i < n - 1) {
			g[v[i]].pb({u[i], i});
			g[u[i]].pb({v[i], i});
		}
	}

	memset(msk, -1, sizeof(msk));

	for (int v = 1; v <= n; ++v) {
		q.push(v);
		msk[v][v] = 0;

		while (sz(q)) {
			int u = q.front();
			q.pop();
			for (auto x : g[u]) 
				if (msk[v][x.f] == -1) {
					msk[v][x.f] = msk[v][u] | (1 << x.s);
					q.push(x.f);
				}			 
		}
	}

	for (int i = n - 1; i < m; ++i)
		for (int mask = 0; mask < (1 << (n - 1)); ++mask)
			if ((mask & msk[v[i]][u[i]]) == msk[v[i]][u[i]])
				++cnt[mask];
	
	dp[0] = ank(m, cnt[0]);
	for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
		for (int i = 0; i < (n - 1); ++i) 
			if (!(mask & (1 << i))) {
				int cur = cnt[mask | (1 << i)] - cnt[mask];
				add(dp[mask | (1 << i)], dp[mask] * 1ll * ank(m - __builtin_popcount(mask) - cnt[mask] - 1, cur) % mod);
			}		
	}

	cout << dp[(1 << (n - 1)) - 1] << endl;
}                              