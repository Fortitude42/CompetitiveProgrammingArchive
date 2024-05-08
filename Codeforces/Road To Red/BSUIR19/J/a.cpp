#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
int n, dp[M][10];

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		x += MOD;
}

void solve() {
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int mask = 0; mask < (1 << 2); ++mask) {
			int l0 = mask & 1;
			int l1 = (mask >> 1) & 1;
		
			add(dp[i][mask], dp[i - 1][mask]);
			if (i > 1)
				add(dp[i][mask], dp[i - 2][mask]);
			if (i > 2)
				add(dp[i][mask], dp[i - 3][mask]);

			if (i == 1)
				continue;

			if (!(i & 1)) {//l0, r0
				if (l0) {
					add(dp[i][mask], dp[i - 2][mask ^ 1]);
					add(dp[i][mask], dp[i - 2][mask]*2ll%MOD);
				}
			} else {
				if (l1) {
					add(dp[i][mask], )
				}
			}
			
		}
	}	

	dp[0][0] = 0;
	cout << (0ll + dp[n][0] + dp[n - 1][0] + dp[n][1] + dp[n - 1][1]) % MOD;
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}