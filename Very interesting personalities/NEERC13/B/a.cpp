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
const int N = 3e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

double dp[2][M][M];

 
void solve() {
	int n, a[2], b[2];
	scanf("%d %d %d", &n, &a[0], &b[0]);
	a[0]++;
	a[1] = a[0] - 1;
	b[1] = b[0] + 1;

	n = min(n, a[0] + b[0]);

	for (int t = 0; t < 2; t++) {
		dp[t][0][0] = 1.0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j > a[t] || i - j > b[t])
					continue;
				int lefta = a[t] - j;
				int leftb = b[t] - (i - j);

				dp[t][i + 1][j + 1] += dp[t][i][j] * (2.0 * lefta / (2LL * lefta + leftb));
				dp[t][i + 1][j] += dp[t][i][j] * (1.0 * leftb / (2LL * lefta + leftb));
			}
		}
	}
	
	double ans[2] = {0.0, 0.0};
	for (int j = 0; j <= n; j++) {
		ans[0] += dp[0][n][j] * j / a[0];
		ans[1] += dp[1][n][j] * (n - j) / b[1];
	}

	printf("%.10lf\n%.10lf", ans[0], ans[1]);
}


main () {
//	file("bonus");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
