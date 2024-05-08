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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
const int N = 1e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;


int n, m;
bool bd[M][2], bad[M][2][2][2];


vector < vi > solve1(int l, int r, int len) {
	vector < vi > ans;
	ans.resize(16);
	for (int i = 0; i < 16; ++i)
		ans[i].resize(len + 1);
	for (int mask = 0; mask < (1 << len); ++mask) {
		bool good = 1;
		for (int i = 0; good && i < len; ++i) {
			if (bd[l + i][(mask >> i) & 1]) {
				good = 0;
				break;
			}

			for (int j = 0; j < 2 && l + i + j + 1 <= r; ++j)
				if (bad[l + i][j][(mask >> i) & 1][(mask >> (i + j + 1)) & 1]) {
					good = 0;
					break;
				}
		}

/*		if (good) {
			for (int i = 0; i < len; ++i)
				cerr << ((mask >> i) & 1);
			cerr << endl;
		}
*/
		if (good)
			++ans[(mask & 3) + ((mask >> (len - 2)) & 3)*4][__builtin_popcount(mask)];		
	}

	return ans;
}

const ll mod = (119 << 23) + 1, root = 62; // = 998244353


int modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * 1ll * a % mod;
		n >>= 1;
		a = a * 1ll * a % mod;
	}

	return res;
}

void ntt(vi &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vi rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		int z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) 
			rt[i] = rt[i / 2] * 1ll * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) 
			rep(j,0,k) {
				int z = rt[j + k] * 1ll * a[i + j + k] % mod, &ai = a[i + j];
				a[i + j + k] = ai - z + (z > ai ? mod : 0);
				ai += (ai + z >= mod ? z - mod : z);
			}
}

vi conv(const vi &a, const vi &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vi L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = L[i] * 1ll * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}


void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

vi tmp;

vector < vi > solve(int l, int r) {
	int len = r - l + 1;

	assert(len > 1);
	if (len <= 4) 
		return solve1(l, r, len);
	
	vector < vi > a = solve(l, l + (len + 2) / 2 - 1);
	vector < vi > b = solve(r - (len + 3) / 2 + 1, r);

	vector < vi > res(16);
	for (int i = 0; i < 16; ++i)
		res[i].resize(len + 1);


	for (int a0 = 0; a0 < 4; ++a0)
		for (int m0 = 0; m0 < 4; ++m0)
			for (int b0 = 0; b0 < 4; ++b0) {
				tmp = conv(a[a0 + m0*4], b[m0 + b0*4]);
				int mbp = __builtin_popcount(m0);
				for (int i = mbp; i < sz(tmp); ++i)
					add(res[a0 + b0*4][i - mbp], tmp[i]);
			}

	return res;						
}



int ans[M];
 
void solve() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		int va = 1, vb = 1;
		cin >> a >> b;
		if (a < 0) {
			a = -a;
			va = 0;
		}

		if (b < 0) {
			b = -b;
			vb = 0;
		}

		if (a == b) {
			if (va == vb) {
				bd[a][!va] = 1;
//				cerr << a << ' ' << !va << endl;
			}
		} else {
			if (a > b) {
				swap(a, b);
				swap(va, vb);
			}

			bad[a][b - a - 1][!va][!vb] = 1;
//			cerr << a << ' ' << b - a - 1 << ' ' << !va << ' ' << !vb << endl;
		}
	}

	if (n == 1) {
		cout << !bd[1][0] << '\n' << !bd[1][1] << '\n';
		return;
	}

	vector < vi > res = solve(1, n);
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j <= n; ++j)
			add(ans[j], res[i][j]);

	for (int i = 0; i <= n; ++i)
		cout << ans[i] << '\n';
}

main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}