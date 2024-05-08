#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, m, f[N<<1], rf[N<<1], a[N], x[N], y[N], pos[N];
int T[N << 2];


void build(int v = 1, int tl = 1, int tr = N - 1) {
    T[v] = tr - tl + 1;
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void update(int pos, int x, int v = 1, int tl = 1, int tr = N - 1) {
	if (tl == tr) {
		T[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);	
	T[v] = T[v << 1] + T[v << 1 | 1];
}

int get(int k, int v = 1, int tl = 1, int tr = N - 1) {
	if (tl == tr)
		return tl;

	int tm = (tl + tr) >> 1;

	if (T[v << 1] >= k)
		return get(k, v << 1, tl, tm);

	return get(k - T[v << 1], v << 1 | 1, tm + 1, tr);
}

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;	
	}

	return res;
}

void precalc() {
	f[0] = 1;
	for (int i = 1; i < N*2; ++i)
		f[i] = f[i - 1] * 1ll * i % mod;

	rf[2*N - 1] = binpow(f[2*N - 1], mod - 2);
	for (int i = 2*N - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;
}
 

int cnk(int n, int k) {
	return f[n] * 1ll * rf[n - k] % mod * rf[k] % mod;
}

main () {
	precalc();
	build();

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);

		for (int i = 1; i <= m; ++i)
			scanf("%d%d", &x[i], &y[i]);

		int cnt = 0;
		for (int i = m; i > 0; --i) {
			pos[i] = get(y[i]);
			update(pos[i], 0);
			a[pos[i]] = x[i];
		}

		for (int i = m; i > 0; --i) 
			if (!a[pos[i] + 1] || a[pos[i] + 1] < a[pos[i]])
				++cnt;


		printf("%d\n", cnk(2*n - 1 - cnt, n));
		for (int i = 1; i <= m; ++i) {
			update(pos[i], 1);
			a[pos[i]] = 0;
		}
	}
}