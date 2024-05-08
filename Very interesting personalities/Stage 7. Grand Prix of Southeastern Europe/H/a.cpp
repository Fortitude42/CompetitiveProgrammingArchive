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
const int N = 3e3, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, c[M], dp[M][M+M], cnt[M], tmp[M + M], cnt1[M];
vi g[M];

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void dfs(int v, int p, int col) {
    cnt1[v] = 1;

	for (int i = -cnt[col]; i <= cnt[col]; ++i)
		dp[v][i + M] = 0;

	int cur = c[v] == col ? 1 : -1;
	dp[v][cur + M] = 1;

	for (auto to : g[v]) {
		if (to == p)
			continue;

		dfs(to, v, col);

		for (int x = max(-cnt[col], -cnt1[v] - cnt1[to]); x <= min(cnt[col], cnt1[v] + cnt1[to]); ++x) 
			tmp[x + M] = 0;


		for (int x = -cnt[col]; x <= cnt[col]; ++x)
			if (dp[to][x + M]) 
				for (int y = max(-cnt[col], -cnt1[v]); y <= min(cnt[col], cnt1[v]); ++y)
					add(tmp[x + y + M], dp[to][x + M] * 1ll * dp[v][y + M] % MOD);

		cnt1[v] += cnt1[to];


		for (int x = max(-cnt[col], -cnt1[v]); x <= min(cnt[col], cnt1[v]); ++x) 
		    add(dp[v][x + M], tmp[x + M]);
		
	}


}
 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);        
		++cnt[c[i]];
	}

	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!cnt[i])
			continue;

		dfs(1, 0, i);
		for (int v = 1; v <= n; ++v)
			for (int j = 1; j <= cnt[i]; ++j) 
				add(ans, dp[v][j + M]);
	}

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

