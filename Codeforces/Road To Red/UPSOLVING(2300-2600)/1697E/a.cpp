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
const int N = 100, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;


int n, x[M], y[M], l[M], f[M], rf[M], cnt[5];
vi g[M], comp;
bool was[M];


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

int dist(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int cnk(int n, int k) {
	return f[n] * 1ll * rf[k] % MOD * 1ll * rf[n - k] % MOD;
}


void precalc() {
	f[0] = 1;
	for (int i = 1; i < M; ++i) 
		f[i] = f[i - 1] * 1ll * i % MOD;
	

	rf[M - 1] = binpow(f[M - 1], MOD - 2);
	for (int i = M - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % MOD;
}
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; ++i){
		l[i] = inf;
		for (int j = 1; j <= n; ++j)
			if (i != j)
				l[i] = min(l[i], dist(i, j));

		g[i].pb(i);
		for (int j = 1; j <= n; ++j)
			if (i != j && l[i] == dist(i, j))
				g[i].pb(j); 
		sort(all(g[i]));
				
	}

	int ans = 1, m = n;

	for (int i = 1; i <= m; ++i)
		if (!was[i]) {
			bool bad = 0;
			for (auto j : g[i])
				if (l[j] != l[i] || g[j] != g[i]) {
					bad = 1;
					break;
				}

			if (bad) {
				ans = ans * 1ll * n % MOD;
				n--;
				was[i] = 1;
				continue;
			}

			assert(sz(g[i]) <= 4);
			++cnt[sz(g[i])];
			for (auto j : g[i])
				was[j] = 1;
		}

	int sum = 0;
	for (int x = 0; x <= cnt[2]; ++x)
		for (int y = 0; y <= cnt[3]; ++y)
			for (int z = 0; z <= cnt[4]; ++z) {
				int m = cnt[2] + x + cnt[3] + y*2 + cnt[4] + z*3;
				sum = (sum + cnk(cnt[2], x) * 1ll * cnk(cnt[3], y) % MOD * cnk(cnt[4], z) % MOD * cnk(n, m) % MOD * f[m] % MOD) % MOD;
			}
	cout << ans * 1ll * sum % MOD << endl;
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
