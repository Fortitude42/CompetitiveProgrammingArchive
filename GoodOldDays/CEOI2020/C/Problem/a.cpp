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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e3 + 12;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, d, v, u, dp[N][N], ans;
vi g[N];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n % 2 == 1)
			res = res * a % mod;
		n /= 2;
		a = a * a % mod;
	}

	return res;
}

void dfs (int v, int u, int p = 0) {
    dp[u][v] = 0;
	for (auto to : g[v]) 
		if (to != p) {
			dfs(to, u, v);
			if (!dp[u][to])
				dp[u][v] = 1;
		}
}

void dfs1 (int v, int u, int p = 0) {
    dp[n + 1][v] = (v == u);

	for (auto to : g[v]) 
		if (to != p) {
			dfs1(to, u, v);
			if (!dp[n + 1][to])
				dp[n + 1][v] = 1;
		}
}

main () {
	cin >> n >> d;
	for (int i = 1; i < n; ++i) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	if (n == 2) {
		cout << (binpow(2, d*2 )) % mod << endl;
		return 0;
	}

	if (d == 1) {
		for (int i = 1; i <= n; ++i) 
			dfs(i, i);                 
		
		for (int a = 1; a <= n; ++a) {
			dfs1(1, a);
			for (int b = 1; b <= n; ++b) {
				if (!dp[b][b]) {
					if (dp[n + 1][1])
						++ans;
				} else	if (dp[1][1])
					++ans;
			}                         
		}
		cout << ans << endl;
		return 0;
	}

}