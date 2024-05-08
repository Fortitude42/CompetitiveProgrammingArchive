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
const int N = 1e2, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, x, a[M];
double dp[M][M*M], c[M][M];
 
void solve() {
	c[0][0] = 1;
	for (int i = 1; i < M; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)	
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}

	cin >> n >> x;
	double s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
		s += a[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int x = n; x > 0; --x)
			for (int j = 0; j + a[i] < M*M; ++j)
				dp[x][j + a[i]] += dp[x - 1][j];

	
	double ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < M*M; ++j) {
			if (!dp[i][j])
				continue;
			ans += (dp[i][j] / c[n][i]) * min((s - j + 0.0) / (n - i), ((2*n - i)*x + 0.0) / (2*(n - i)));
		}

	cout << fixed << setprecision(10);
	cout << ans << endl;
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

