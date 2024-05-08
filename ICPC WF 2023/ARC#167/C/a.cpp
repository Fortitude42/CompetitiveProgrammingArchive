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
const int N = 5e3, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;


int a[M], f[M], rf[M];
int n, k;
int dp[M];


int binpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * 1ll * a % MOD;

		a = a * 1ll * a % MOD;
		n >>= 1;
	}

	return res;
}


void precalc() {
	f[0] = 1;
	for (int i = 1; i < M; ++i)
		f[i] = f[i - 1] * 1ll * i % MOD;

	rf[M - 1] = binpow(f[M - 1], MOD - 2);
	for (int i = M - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % MOD;
}

int cnk(int n, int k) {
	if (k < 0 || k > n)
		return 0;
	return f[n] * 1ll * rf[k] % MOD * rf[n - k] % MOD;
}


void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}
 
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	

	for (int x = 1; x <= n; ++x) {
		int l = max(1, x - k);
		int r = min(n, x + k);

		for (int y = l; y < x; ++y) {
			int l1 = y + k;
			if (l1 <= r)
				add(dp[x], (r - l1 + 1));
		}
	}

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int x = 1; x <= n; ++x) {
			int l = max(1, x - k);
			int r = min(n, x + k);

			int out = (l - 1) + (n - r);
			int in = n - out - 1;

			int cur = dp[x] * 2ll * cnk(i, 2) % MOD * 1ll * cnk(out, i - 2) % MOD;
			add(ans, a[i] * 1ll * cur % MOD);
//			cerr << i << ' ' << cur << endl;
			
			cur = cnk(out, i - 1)*1ll*in % MOD;
			add(ans, a[i] * 1ll * cur % MOD);
//			cerr << i << ' ' << cur << endl;
		}
	}

	cout << ans << "\n";
}

main () {
	precalc();
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}