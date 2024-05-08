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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, a[N], ans, p[N], rp[N], r[N];
vi g[N], dp[N];

inline int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;
	}

	return res;
}

inline void sub(int &x, int y) {
	x -= y;
	if (x < 0)
		x += mod;
}

inline void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}


inline int f(int x, int y) {
	int res = 0;

	int j = 0, sum = 0;

	for (int i = 0; i < sz(g[x]); ++i) {
		while (j < sz(g[y]) && g[y][j] <= g[x][i]) {
			add(sum, dp[y][j]);
			++j;
		}
		add(res, dp[x][i] * 1ll * sum % mod * r[g[x][i]] % mod);  
	}

	j = 0, sum = 0;
	for (int i = 0; i < sz(g[y]); ++i) {
		while (j < sz(g[x]) && g[x][j] < g[y][i]) {
			add(sum, dp[x][j]);
			++j;
		}
		add(res, dp[y][i] * 1ll * sum % mod * r[g[y][i]] % mod);
	}
		
	res = res * 1ll * rp[x] % mod * rp[y] % mod;
	return res;
}

inline void precalc() {
	p[0] = 1;
	r[0] = 0;
	for (int i = 1; i < N; ++i)	{
		p[i] = p[i - 1] * 1ll * 26 % mod;
		r[i] = binpow(i, mod - 2);
	}

	rp[N - 1] = binpow(p[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i)
		rp[i] = rp[i + 1] * 1ll * 26 % mod;

	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			g[j].pb(i);

	for (int i = 1; i < N; ++i) {
	    dp[i].resize(sz(g[i]));
		for (int j = 0; j < sz(g[i]); ++j) {
			int d = g[i][j];
			dp[i][j] = p[d];
			for (int jj = 0; jj < j; ++jj)
				if (g[i][j] % g[i][jj] == 0)
					sub(dp[i][j], dp[i][jj]);
		}
	}
}
 
main () {
	precalc();
	scanf("%d", &n);
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int ans = 0;
	for (int i = 0; i < n; ++i)
		add(ans, f(a[i], a[(i + 1) % n]));
	cout << ans << endl;
}