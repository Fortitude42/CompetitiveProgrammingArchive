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
const int N = 5000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, p[M], pe[M], cnt[M], cnt1[M];
int a[M], b[M], c[M], l[M], tmp[M+M], dp[M][M+M];
vi g[M];

void dfs(int v) {
	for (auto i : g[v]) {
		if (i == pe[v])
			continue;

		int to = a[i]^b[i]^v;
		pe[to] = i;
		dfs(to);
	}
}


void dfs1(int v) {
	cnt[v] = 1;
	for (int x = -cnt1[v]; x <= cnt[v]; ++x)
		dp[v][x + M] = 0;

	for (auto i : g[v]) {
		if (i == pe[v])
			continue;

		int to = a[i]^b[i]^v;
		dfs1(to);

		for (int x = -cnt1[v] - cnt1[to]; x <= cnt[v] + cnt[to]; ++x)
			tmp[x + M] = inf;

		for (int x = -cnt1[v]; x <= cnt[v]; ++x) {
			if (dp[v][x+M] == inf)
				continue;

			for (int y = -cnt1[to]; y <= cnt[to]; ++y)
				if (dp[to][y+M] < inf && c[i] == (abs(y) & 1)) 
					tmp[x + y + M] = min(tmp[x + y+M], dp[v][x+M] + dp[to][y+M] + abs(y)*l[i]);							
		}

		cnt[v] += cnt[to];
		cnt1[v] += cnt1[to];
		for (int x = -cnt1[v]; x <= cnt[v]; ++x)
			dp[v][x+M] = tmp[x+M];
	}
	
	
}

 
void solve() {
	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		cin >> a[i] >> b[i] >> l[i] >> c[i];
		g[a[i]].pb(i);
		g[b[i]].pb(i);
	}

	for (int i = 1; i <= m; ++i) {
		cin >> p[i];
		++cnt1[p[i]];
	}

	dfs(1);


	dfs1(1);
	int ans = inf;
	for (int i = -m; i <= 0; ++i)
		ans = min(ans, dp[1][i+M]);

	if (ans == inf)
		ans = -1;
	cout << ans << "\n";


	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		pe[i] = 0;
		cnt[i] = cnt1[i] = 0;
	}
}

main () {
  int TT;
  TT = 1;
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}