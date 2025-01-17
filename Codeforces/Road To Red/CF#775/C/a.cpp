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
const int N = 2e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;


int n, m, t[M], f[M], cnt[M]; 

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

void inc(int pos, int x) {
	while (pos < M) {
		t[pos] += x;
		pos |= pos + 1;
	}
}

int rev(int x) {
	return binpow(x, MOD - 2);
}

int get(int r) {
	int res = 0;
	while (r >= 0) {
		res += t[r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void precalc() {
	f[0] = 1;
	for (int i = 1; i < M; ++i)
		f[i] = f[i - 1] * 1ll * i % MOD;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int s;
		cin >> s;
		++cnt[s];
	}

	int pr = 1;
	for (int i = 1; i < M; ++i) {
		pr = pr * 1ll * f[cnt[i]] % MOD; 
		inc(i, cnt[i]);
	}

	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		int t;
		cin >> t;
		add(ans, f[n - i] * 1ll * rev(pr) % MOD * get(t - 1) % MOD);

		if (!cnt[t]) {
		    if (i == n + 1)
		    	add(ans, 1);
			break; 
		}

		inc(t, -1);
		pr = pr * 1ll * rev(cnt[t]) % MOD;
		--cnt[t];
	}

	cout << ans << endl;
}

main () {
	precalc();
	int TT = 1;
	fastio

  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}