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

double dp[M][M];

void precalc() {
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		dp[i][i] = 1.0 / i;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = (i - j - 1)*dp[i - 2][j] / (i + 0.0);
			dp[i][j] += (j - 1) * dp[i - 2][j - 1] / (i + 0.0);		
		}
	}
}

int n, m;
vi g[M];
double d[M];
 
void solve() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
	}

	d[n] = 1;
	for (int i = n - 1; i > 0; --i) {
		d[i] = 0;
		vector < double > cur;
		for (auto j : g[i])
			cur.pb(d[j]);

		sort(all(cur));
		for (int j = 1; j <= sz(cur); ++j)
			d[i] += cur[j - 1] * dp[sz(cur)][j];
	}

	cout << d[1] << "\n";

	for (int i = 1; i <= n; ++i)
		g[i].clear();
}

main () {
	cout << fixed << setprecision(12);
	fastio
	precalc();
  int TT;
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}