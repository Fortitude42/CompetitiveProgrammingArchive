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
const int N = (1 << 19), inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;


 
void add(int &x, int y) {
	x += y;

	if (x >= MOD)
		x -= MOD;

	if (x < 0)
		x += MOD;
}



int n, coeff[M], dp[M], f[M], rf[M];
int cnk(int n, int k) {
	if (n < 0 || k < 0 || k > n)
		return 0;

	return f[n] * 1ll * rf[k] % MOD * rf[n - k] % MOD;
}

template <int M>

 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++dp[x^(N - 1)];
	}

	for (int i = 0; i < 20; ++i)
		for (int mask = 0; mask < N; ++mask)
			if (mask & (1 << i))
				dp[mask] += dp[mask ^ (1 << i)];

	for (int i = 0; i < N; ++i)
		coeff[dp[i]] += (__builtin_popcount(i^(N - 1)) & 1) ? -1 : 1;
	
	vi a(N + 1), b(N + 1);
	for (int i = 0; i <= N; ++i) {
		a[i] = coeff[i] * 1ll * f[i] % MOD;
		if (a[i] < 0)
			a[i] += MOD;
		
		b[i] = rf[N - i];
	}


	vi c = multiply(a, b);
	for (int i = 1; i <= n; ++i) {
		int res = c[i + N];
		res = res * 1ll * rf[i] % MOD;
		printf("%d ", res);
	}
}

int binpow(int a, int n) {
	int res = 1;
	while (n) {
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

main () {
	precalc();

	int TT;
	TT = 1;

	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
