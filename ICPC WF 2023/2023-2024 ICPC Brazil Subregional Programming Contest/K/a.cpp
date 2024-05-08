#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 #define rep(i, a, b) for(int i = a; i < (b); ++i)

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
 


const ll mod = (119 << 23) + 1, root = 62; // = 998244353

int modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) 
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;
	}

	return res;
}
// For p < 2^30 there is a lso e . g . 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root) . The l as t two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) 
			rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) 
		rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) 
		if (i < rev[i]) 
			swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) 
			rep(j,0,k) {
				ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
				a[i + j + k] = ai - z + (z > ai ? mod : 0);
				ai += (ai + z >= mod ? z - mod : z);
			}
}


vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) 
		out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

const int N = 1e5;
const int M = N + 12;

int n, k, f[M], rf[M];
int a[2][M], ans[M];

void precalc() {
	f[0] = 1;
	for (int i = 1; i < M; ++i)
		f[i] = f[i - 1] * 1ll * i % mod;

	rf[M - 1] = modpow(f[M - 1], mod - 2);
	for (int i = M - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;
}


void solve(int k, int ind) {
	vl x, y;
	for (int i = 0; i < n; ++i)
		x.pb(a[ind][i]*1ll*f[i]%mod);

	int pk = 1;			
	for (int j = 0; j < n; ++j) {
		y.pb(pk*1ll*rf[j]%mod);
		pk = pk*1ll*k % mod;
	}

	reverse(all(y));

	vl z = conv(x, y);
	for (int i = 0; i < n; ++i) {
		ans[i] += z[n -  1 + i];
		if (ans[i] >= mod)
			ans[i] -= mod;
	}
}

void solve() {
	cin >> n >> k;
	n++;
	if (k < 0)
		k += mod;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	solve(k, 0);
	solve((mod - k) % mod, 1);

	for (int i = 0; i < n; ++i) {
	    ans[i] = ans[i] * 1ll * rf[i] % mod;
		cout << ans[i] << " ";
	}
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