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
const int N = 3e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, dp[M], f[M], rf[M], dp1[M];
 
int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		n >>= 1;
		a = a * 1ll * a % MOD;
	}

	return res;
}

int cnk(int n, int k) {
	return f[n] * 1ll * rf[k] % MOD * rf[n - k] % MOD;
}

void precalc() {
	dp[0] = dp[1] = 1;
	for (int i = 2; i < M; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] * 1ll * (i - 1))  % MOD;

	dp1[0] = 1;
	for (int i = 1; i < M; ++i) {
		dp1[i] = dp1[i - 1]; 
		if (i & 1)
			dp1[i] = dp1[i] * 2ll * i % MOD;
	}

	f[0] = 1;
	for (int i = 1; i < M; ++i)
		f[i] = f[i - 1] * 1ll * i % MOD;

	rf[M - 1] = binpow(f[M - 1], MOD - 2);
	for (int i = M - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % MOD;
}

void solve() {
	cin >> n;
	int ans = 0;
	for (int k = 0; k <= (n / 4); ++k) 
		ans = (ans + dp[n - 4*k] * 1ll * cnk(n - 2*k, 2*k) % MOD * dp1[2*k])% MOD;
	
	cout << ans << endl;
}

main () {
	int TT = 1;
	precalc();
	fastio
	cin >> TT;	
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}