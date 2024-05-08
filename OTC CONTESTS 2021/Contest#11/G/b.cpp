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
const int N = (1 << 14), inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
string t[16];
vector < ll > dp[M][16];
 
void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> t[i];
	

	for (int mask = 1; mask < (1 << n); ++mask)
		for (int i = 0; i < n; ++i)
			dp[mask][i].resize((1 << (__builtin_popcount(mask) - 1)));	

	for (int i = 0; i < n; ++i)
		dp[(1 << i)][i][0] = 1;

	for (int mask = 0; mask < (1 << n); ++mask)  {
	    int k = __builtin_popcount(mask);
		for (int i = 0; i < n; ++i) {
			if (!(mask & (1 << i)))
				continue;
			for (int s = 0; s < (1 << (k - 1)); ++s) {
				if (!dp[mask][i][s])
					continue;
				for (int j = 0; j < n; ++j)
					if (!(mask & (1 << j))) 
						dp[mask | (1 << j)][j][s | ((1 << (k - 1)) * (t[i][j] == '1'))] += dp[mask][i][s]; 					
			}
		}
	}

	for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
		ll sum = 0;
		for (int i = 0; i < n; ++i)
			sum += dp[(1 << n) - 1][i][mask];
		cout << sum << ' ';;
	}
	
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}