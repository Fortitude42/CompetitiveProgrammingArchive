//by paradox & gege & parasat
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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int dp[M][3];
vi g[M];

void dfs(int v, int par = 0) {
	int sum = 0, sum2 = 0;
	vector<pii> vec;

	dp[v][0] = 0;
	for (int to : g[v]) {
		if (to == par)
			continue;
	
	    dfs(to, v);
		dp[v][0] += min({dp[to][1], dp[to][2], dp[to][0] + 1});
		sum += min(dp[to][0], dp[to][2]) + 1;
		vec.pb({dp[to][0] - (dp[to][2] + 1), to});
		sum2 += min(dp[to][0], dp[to][2] + 1);
	}

	sort(all(vec));
	if (sz(vec) >= 2) {
		for (int i = 0; i < 2; i++) {
			int to = vec[i].se;
			sum2 += dp[to][0] - min(dp[to][0], dp[to][2] + 1);
		}
		dp[v][2] = sum2;
	}

	for (int to : g[v])
		if (to != par)
			dp[v][1] = min(dp[v][1], dp[to][0] + (sum - (min(dp[to][0], dp[to][2]) + 1)));

//	cerr << v << " | " << dp[v][0] << ' ' << dp[v][1] << ' ' << dp[v][2] << "\n";
}
 
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d %d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = inf;
	dfs(1);

	int ans = min(dp[1][0], dp[1][2]);
	printf("%d\n", ans);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
