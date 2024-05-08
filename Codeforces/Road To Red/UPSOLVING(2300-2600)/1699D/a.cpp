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
const int N = 5e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M], cnt[M], t[M], timer, dp[M];
bool good[M][M];
vi g[M];
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		g[a[i]].pb(i);
	}

	for (int l = 1; l <= n; ++l) {
		++timer;
		int mx = 0;
		for (int r = l; r <= n; ++r) {
			good[l][r] = 0;

			if (t[a[r]] != timer) {
				t[a[r]] = timer;
				cnt[a[r]] = 0;
			}

			++cnt[a[r]];
			mx = max(mx, cnt[a[r]]);
			if (!((r - l + 1) & 1) && mx + mx <= r - l + 1)
				good[l][r] = 1;
		}
	}


	for (int i = 1; i <= n; ++i) {
		if (i == 1 || good[1][i - 1])
			dp[i] = 1;
		else
			dp[i] = -inf;

		for (auto j : g[a[i]]) {
			if (j == i)
				break;
			if (i - 1 < j + 1 || good[j + 1][i - 1])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == n || good[i + 1][n])
			ans = max(ans, dp[i]); 
		g[i].clear();
	}


	cout << ans << endl;
}

main () {
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}