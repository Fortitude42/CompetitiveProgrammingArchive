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

int n, a[M], b[M], x[M], y[M], lp[M], ans[M], h[M]; 
vector < pair < pii, int > > gg[M];
int tin[M], tout[M], timer;
vi g[M];

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

void precalc() {
	for (int i = 2; i < M; ++i)
		if (!lp[i])
			for (int j = i; j < M; j += i)
				lp[j] = i;
}

void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	for (auto x : g[v]) {
		if (x == p)
			continue;
		int to = (v ^ a[x] ^ b[x]);
		dfs(to, x);
	}

	tout[v] = timer;
}

void dfs1(int v, int p = 0) {
	for (auto x : g[v]) {
		if (x == p)
			continue;
		int to = (v ^ a[x] ^ b[x]);
		ans[to] = ans[to] * 1ll * ans[v] % MOD;
		dfs1(to, x);
	}
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%d%d", &a[i], &b[i], &x[i], &y[i]);
		g[a[i]].pb(i);
		g[b[i]].pb(i);

		int g = __gcd(x[i], y[i]);
		x[i] /= g;
		y[i] /= g;
	}


	
	dfs(1);
	vi primes;
	for (int i = 1; i <= n; ++i)
		ans[i] = 1;

	for (int i = 1; i < n; ++i) {
		if (!upper(a[i], b[i])) {
			swap(a[i], b[i]);
			swap(x[i], y[i]); 			
		}
		
		while (x[i] > 1 || y[i] > 1) {
			int p = x[i] == 1 ? lp[y[i]] : lp[x[i]];
			int cnt = 0;

			while (!(x[i] % p)) {
				x[i] /= p;
				cnt--;
			}

			while (!(y[i] % p)) {
				y[i] /= p;
				cnt++;
			}


			if (cnt < 0) 
				ans[b[i]] = ans[b[i]] * 1ll * binpow(binpow(p, -cnt), MOD - 2) % MOD;
			else
				ans[b[i]] = ans[b[i]] * 1ll * binpow(p, cnt) % MOD;
			

			gg[p].pb(mp(mp(tin[b[i]], b[i]), cnt));
			primes.pb(p);
		}
	}

	sort(all(primes));
	primes.resize(unique(all(primes)) - primes.begin());

	for (auto p : primes) {
		vi v;
		v.pb(1);
		
		int mn = 0;
		sort(all(gg[p]));

		for (auto x : gg[p]) {
			int y = x.f.s;
			while (!upper(v.back(), y))
				v.ppb();

			h[y] = h[v.back()] + x.s;
			mn = min(mn, h[y]);
			v.pb(y);
		}
		ans[1] = ans[1] * 1ll * binpow(p, -mn) % MOD;
	}

	dfs1(1);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += ans[i];
		if (sum >= MOD)
			sum -= MOD;
	}

	printf("%d\n", sum);

	timer = 0;
	for (auto p : primes)
		gg[p].clear();
	for (int i = 1; i <= n; ++i)
		g[i].clear();	
}

main () {
	precalc();

	int TT;
	TT = 1;
  	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}