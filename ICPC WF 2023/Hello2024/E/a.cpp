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
const int N = 1e4, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, p[M], out[M+M], in[M+M], nxt[M+M], prv[M+M], sh[M+M];
int cnt[M + M], f[M], rf[M];

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
	if (n < 0 || k < 0 || k > n)
		return 0;


	return f[n] * 1ll * rf[k] % MOD * rf[n - k] % MOD;
}
 
void solve() {
	memset(cnt, 0, sizeof cnt);

	cin >> n;
	int mn = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		++cnt[p[i] + M];
		mn = min(mn, p[i]);
	}


	if (n == 1) {
		cout << abs(p[1]) << "\n";
		return;
	}


	int ans = 0;
	for (int s = -1; s <= 1; s += 2)
		for (int t = -n; t <= n; ++t) {
			if (s < mn || t < mn)
				continue;

			for (int i = -n; i <= n; ++i) {
				out[i + M] = cnt[i + M];
				in[i + M] = 0;
				sh[i + M] =	 0;
			}


			//sh = out - in
			out[t + M]--;
			if (out[t + M] < 0)
				continue;
			if (out[s + M] <= 0)
				continue;

			sh[s + M]++;
			sh[t + M]--;

			prv[mn + M] = 0;

			bool bad = 0;
			for (int i = mn; i <= n; ++i) {
				nxt[i + M] = out[i + M] - prv[i + M];

				if (nxt[i + M] < 0 || nxt[i + M] > out[i + M]) {
					bad = 1;
					break;
				}

				in[i + 1 + M] += nxt[i + M];
				prv[i + 1 + M] = out[i + M] - in[i + M] - sh[i + M];
			}


			if (bad || nxt[n + M] > 0) 
				continue;
			
			int cur = 1;
//			for (int i = -n; i <= n; ++i)
//				cerr << out[i + M] << ' ' << sh[i + M] << endl;

			for (int i = -n; i <= n; ++i) {
				if (!out[i + M])
					continue;
				cur = cur * 1ll * f[out[i + M] - 1] % MOD;
//				cerr << out[i + M] << ' ' << nxt[i + M] << endl;
			}
//			cerr << endl;

			ans += cur;
//			cerr << "-->" << s << ' ' << t << ' ' << cur << endl;
			if (ans >= MOD)
				ans -= MOD;
		}

	cout << ans << "\n";
	
}

main () {
	precalc();
  int TT;
  TT = 1;
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}