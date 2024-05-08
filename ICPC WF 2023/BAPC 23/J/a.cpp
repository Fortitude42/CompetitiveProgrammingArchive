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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, p[M], dp[M][M], tmp[M], cnt[M], ans[M];
vi g[M];

void dfs(int v) {
	dp[v][1] = 1;
	cnt[v] = 1;

	for (auto to : g[v]) {
		dfs(to);

		for (int i = 1; i <= cnt[v] + cnt[to]; ++i)
			tmp[i] = 0;

		for (int i = 1; i <= cnt[v]; ++i)
			for (int j = 1; j <= cnt[to]; ++j)
				tmp[i + j] = (tmp[i + j] + 0ll + dp[v][i] * 1ll * dp[to][j]) % MOD;
		
		cnt[v] += cnt[to];
		for (int i = 1; i <= cnt[v]; ++i) {
			dp[v][i] += tmp[i];
			if (dp[v][i] >= MOD)
				dp[v][i] -= MOD;
		}
	}

	for (int i = 1; i <= cnt[v]; ++i) {
		ans[i] += dp[v][i];
		if (ans[i] >= MOD)
			ans[i] -= MOD;
	}
		
}
 
void solve() {
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		++p[i];
		g[p[i]].pb(i);
	}


	dfs(1);

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << '\n';
}

main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}