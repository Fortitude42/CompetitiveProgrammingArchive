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
const int N = 7e5, inf = 1e9, MOD = 998244353;
const int M = N + 17, K = 3e5;
const ll INF = 1e18;

int add(const int a, const int b) {
	return (a + b + (a + b >= MOD ? -MOD : 0));
}

int mult(const int a, const int b) {
	return 1ll * a * b % MOD;
}

int sub(const int a, const int b) {
	return a - b + (a < b ? +MOD : 0);
}

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = mult(res, a);
		a = mult(a, a);
		n >>= 1;
	}

	return res;
}

int divide(int a, int b) {
	return mult(a, binpow(b, MOD - 2));
}

int ord[3];
int fact[M], revf[M];
int dp[M];

int C(int k, int n) {
	return mult(mult(fact[n], revf[k]), revf[n - k]);
}

void solve() {
	fact[0] = 1;
	revf[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mult(fact[i - 1], i);
		revf[i] = binpow(fact[i], MOD - 2);
	}

	int x[4];
	for (int i = 1; i <= 3; i++) {
		scanf("%d", &x[i]);
		x[i] += K;
		ord[i] = i;
	}

	int k, p;
	scanf("%d %d", &k, &p);
	p = divide(p, 100);
	int q = sub(1, p);

	for (int x = 0; x <= k; x++)
		dp[k - x - x + K] = add(dp[k - x - x + K], mult(C(x, k), mult(binpow(q, x), binpow(p, k - x))));

	cerr << dp[K - 1] << ' ' << dp[K] << ' ' << dp[K + 1] << "\n";
	
	int ans = 0;
	do {
		int A = 0, B = 0, C = 0, D = 0, E = 0;
		for (int l = N; l >= 0; l--) {
			C = add(C, dp[l - x[ord[3]] + K]);
			A = add(A, add(mult(D, dp[K + l - x[ord[3]]]), mult(mult(l, dp[K + l - x[ord[2]]]), C)));
			D = add(D, mult(l, dp[K + l - x[ord[2]]]));
			B = add(B, add(mult(dp[K + l - x[ord[3]]], E), mult(dp[K + l - x[ord[2]]], C)));
			E = add(E, dp[K + l - x[ord[2]]]);
			
			int cur = sub(mult(dp[K + l - x[ord[1]]], A), mult(l, B));
			ans = add(ans, cur);

//			cur = mult(mult(dp[K + l - x[ord[1]]], dp[K + l - x[ord[2]]]), dp[K + l - x[ord[3]]]);
//			ans = add(ans, cur);
		}

		A = B = 0;
		for (int l = N; l >= 0; l--) {
			A = add(A, dp[K + l - x[ord[3]]]);
			B = add(B, mult(dp[K + l - x[ord[2]]], dp[K + l - x[ord[3]]]));

			int cur = mult(mult(dp[K + l - x[ord[1]]], dp[K + l - x[ord[2]]]), A);
			ans = sub(ans, cur);

			cur = mult(dp[K + l - x[ord[1]]], B);
			ans = sub(ans, cur);
		}
	} while (next_permutation(ord + 1, ord + 4));
	
	ans = divide(ans, 3);
	printf("%d\n", ans);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
