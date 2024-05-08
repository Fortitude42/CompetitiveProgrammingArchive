//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
const int N = 1e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

 
int n, a[M], dp[2][N];
vi vals[2];

inline void add(int &x, int y) {
	x += y;
	while (x >= MOD)
		x -= MOD;
}

inline void clear(int i) {
	for (auto x : vals[i])
		dp[i][x] = 0;
	vals[i].clear();
}

inline int f(int x, int y) {
	return x / ((x + y - 1) / y);
}


void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	

	clear((n + 1) & 1);
	int ans = 0;

	for (int i = n; i > 0; --i) {
		clear(i & 1);
		vals[(i + 1) & 1].resize(unique(all(vals[(i + 1) & 1])) - vals[(i + 1) & 1].begin());

		for (auto x : vals[(i + 1) & 1]) {
			int y = f(a[i], x);
			add(ans, dp[(i + 1) & 1][x] * 1ll * ((a[i] + x - 1) / x - 1) * i % MOD);
//			cerr << i + 1 << ' ' << x << ' ' << dp[(i + 1) & 1][x] << endl;
			dp[i & 1][y] += dp[(i + 1) & 1][x];
			vals[i & 1].pb(y);
		}		

		dp[i & 1][a[i]]++;
		vals[i & 1].pb(a[i]);
	}

	printf("%d\n", ans);
}

main () {
  	int TT;
  	TT = 1;
  	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
		solve();
  	}
}