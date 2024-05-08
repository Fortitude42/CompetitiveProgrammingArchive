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
const int N = 1e2, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, a[M], b[M]; 
ll dp[M][M*M];

void solve() {
	cin >> n;
	ll s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
		s += (n - 1) * 1ll * a[i]*a[i];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> b[i]; 
		s += (n - 1) * 1ll * b[i]*b[i];
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < M*M; ++j)
			dp[i][j] = INF;

	dp[0][0] = 0;

	ll sum = 0, res = INF;
	for (int i = 1; i <= n; ++i) {
		for (int sa = 0, sb = sum; sa <= sum; ++sa, --sb)
			if (dp[i - 1][sa] != INF) {
				dp[i][sa + a[i]] = min(dp[i][sa + a[i]], dp[i - 1][sa] + sa*1ll*a[i] + sb*1ll*b[i]);
				dp[i][sa + b[i]] = min(dp[i][sa + b[i]], dp[i - 1][sa] + sa*1ll*b[i] + sb*1ll*a[i]);
				if (i == n)
					res = min({res, dp[i][sa + a[i]], dp[i][sa + b[i]]}); 				
			}
		sum += a[i] + b[i];
	}

	cout << res*2 + s << endl;
}

main () {
	int TT;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}