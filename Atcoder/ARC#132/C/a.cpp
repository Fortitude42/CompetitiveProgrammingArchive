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
const int N = 500, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;


int n, d, a[M], dp[M][2070];
 
void solve() {
	fastio
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	dp[0][32] = 1;
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < (1 << 11); ++mask) {
			if (!dp[i][mask])
				continue;			
//			cerr << i << ' ' << mask << endl;
			int mask1 = (mask >> 1);

			for (int x = 5 - d; x <= d + 5; ++x) {
				if ((mask1 & (1 << x)) || (i + 1 + x - 5) < 1 || (i + 1 + x - 5) > n || (a[i + 1] != -1 && i + 1 + x - 5 != a[i + 1]))
					continue;

				dp[i + 1][mask1 | (1 << x)] += dp[i][mask];
				if (dp[i + 1][mask1 | (1 << x)] >= MOD)
					dp[i + 1][mask1 | (1 << x)] -= MOD;
			}
		}                        
	}

	int ans = 0;
	for (int mask = 0; mask < (1 << 11); ++mask) {
		ans += dp[n][mask];                        
		if (ans >= MOD)
			ans -= MOD;
	}

	cout << ans << endl;
}       	

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}