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
#define rep(i, a, b) for(int i = a; i < b; ++i)
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
 

const int mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is a lso e . g . 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root) . The l as t two are > 10^9.
typedef vector<int> vl;


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


void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
	rt.resize(n);
	int z[] = {1, modpow(root, mod >> s)};
	rep(i,k,2*k) rt[i] = rt[i / 2] * 1ll * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);

	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) 
			rep(j,0,k) {
				int z = rt[j + k] * 1ll * a[i + j + k] % mod, &ai = a[i + j];
				a[i + j + k] = 0ll + ai - z + (z > ai ? mod : 0);
				ai += (ai + z >= mod ? z - mod : z);
			}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s),
	n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n)
		out[-i & (n - 1)] = L[i] * 1ll * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}

const int N = 1e3 + 11;

int n[2], m[2];
int a[2][N][N];
 
void solve() {
	for (int x = 0; x < 2; ++x) {
		cin >> n[x] >> m[x];
		for (int i = 1; i <= n[x]; ++i)
			for (int j = 1; j <= m[x]; ++j)
				cin >> a[x][i][j];
	}

	if (n[0] > n[1] || m[0] > m[1]) {
		cout << 0 << "\n";
		return;
	}


	int s3 = 0;
	for (int i = 1; i <= n[0]; ++i)
		for (int j = 1; j <= m[0]; ++j)
			add(s3, a[0][i][j] * 1ll * a[0][i][j] % mod * a[0][i][j] % mod);

	vi t, t2, p, p2;
	for (int i = 1; i <= n[1]; ++i)
		for (int j = 1; j <= m[1]; ++j) {
			p.pb(a[0][i][j]);
			p2.pb(a[0][i][j] * 1ll * a[0][i][j] % mod);

			t.pb(a[1][i][j]);
			t2.pb(a[1][i][j] * 1ll * a[1][i][j] % mod);
		}


	reverse(all(p));
	reverse(all(p2));
	vi s1 = conv(t2, p);
	vi s2 = conv(t, p2);

	int sz = n[1]*m[1];
	vector < pii > ans;
	for (int i = 1; i + n[0] - 1 <= n[1]; ++i)
		for (int j = 1; j + m[0] - 1 <= m[1]; ++j) {
			int ind = (i - 1) * m[1] + j - 1;
			int cur = s1[ind + sz - 1];
			add(cur, -2*s2[ind + sz - 1] % mod);	
			add(cur, s3);
/*
			int ss1 = 0, ss2 = 0, ss3 = 0;
			for (int j = 0; j + ind < sz; ++j) {
				add(ss1, t2[ind + j] * 1ll * p[sz - 1 - j] % mod);
				add(ss2, t[ind + j] % mod * p2[sz - 1 - j] % mod);
				add(ss3, p[sz - 1 - j] * 1ll * p[sz - 1 - j] % mod * p[sz - 1 - j] % mod);
			}


			int s = ss1;
			add(s, -2*ss2 % mod);
			add(s, ss3);
*/			

			if (!cur)
				ans.pb({i, j});
		}

	cout << sz(ans) << "\n";
	for (auto x : ans)
		cout << x.f << ' ' << x.s << "\n";
	
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}