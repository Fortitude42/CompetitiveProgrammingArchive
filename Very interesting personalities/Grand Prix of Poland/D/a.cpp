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
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 1000;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const double eps = 1e-12;

double dp[M];
int n, m, c;
vi g[M];

inline int R () {
	char c;
	bool is_negative = 0, started = 0;
	int ans = 0;
	while (1) {
		c = getchar();
		if ((c > '9' || c < '0') && c != '-' && !started)
			continue;
		if ((c > '9' || c < '0') && c != '-' && started)
			break;
		started = 1;
		if (c == '-')
			is_negative = 1;
		else
			ans = ans * 10 + c - '0';
	}
 
	return ans;
}



 
void solve() {
	n = R();
	c = R();
	for (int i = 1; i < n; ++i) {
		int v, u;
		v = R(), u = R();
		g[v].pb(u);
		g[u].pb(v);
	}
	dp[c] = 1;
	double ans = 0;
	m = R();


	while (m--) {
		int v;
		v = R();

		ans += dp[v];

		dp[v] /= sz(g[v]);
		if (dp[v] < eps) {
		    dp[v] = 0;
			continue;
		}

		for (auto to : g[v])
			dp[to] += dp[v];
		dp[v] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		dp[i] = 0;
		g[i].clear();
	}


	cout << fixed << setprecision(8) << ans << endl;
}   	

main () {
	int TT;
	TT = 1;
	TT = R();
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

