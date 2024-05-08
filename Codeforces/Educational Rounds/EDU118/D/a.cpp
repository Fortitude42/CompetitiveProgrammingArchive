//by parasat
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
const int N = 5e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M], dp[M][2]; 

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);        

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			dp[i][j] = 0;

	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		if (a[i]) 
			add(dp[a[i] - 1][1], (dp[a[i] - 1][0] + dp[a[i] - 1][1]) % MOD);


		for (int x = 0; x < 2; ++x)
			add(dp[a[i] + 1][x], dp[a[i] + 1][x]);
		add(dp[a[i] + 1][0], dp[a[i]][0]);
	}

	int ans = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			add(ans, dp[i][j]);
	ans--;
	if (ans < 0)
		ans += MOD;

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