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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, dp[M][M];
string s, t;
vi a, b;
 
void solve() {
	fastio
	cin >> n >> m >> s >> t;
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] == '1')
			a.pb(i + 1);                  
		
		if (t[i] == '1')
			b.pb(i + 1);
	}

	for (int i = 0; i <= n + m; ++i)
		for (int j = 0; j <= m + n; ++j)
			dp[i][j] = inf;

	dp[0][0] = 0;
	for (int j = 1; j <= n + m; ++j)
		dp[0][j] = 1;

	for (int i = 1; i <= m; ++i) {
		int l = a[i - 1], r = b[i - 1];
		if (l > r)
			swap(l, r);

//		cerr << l << ' ' << r << endl;

		for (int j = l; j <= r; ++j) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); 
			for (int jj = 0; jj < j - 1; ++jj)
				dp[i][j] = min(dp[i][j], dp[i - 1][jj] + (!jj ? 1 : 2));
		}

		if (i == 2) {
			for (int j = 1; j <= n + m; ++j)
				if (dp[i][j] == 3)
				cerr << j << ' '; 
			for (int j = 1; j <= n + m; ++j)
				if (dp[i][j] != inf)
				cerr << j << ' ' << dp[i][j] << endl; 		
		}
	}
	cout << endl << endl;

	int ans = inf;
	for (int j = 1; j <= n + m; ++j)
		ans = min(ans, dp[m][j] + (j < (n + m)));
	
	cout << n + m - ans - 1 << endl;
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}