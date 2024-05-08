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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, q, p[N], res[N], t[N*2], l[N], r[N];
vector < pair < pii, int > > g[N];
ll a[N], s[N], b[N];
vector < ll > vals;

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;	
	}

	return res;
}

void inc (int pos, int x) {
//	cerr << " + " << pos << ' ' << x << endl; 
	while (pos < N + N) {
		t[pos] += x;
		if (t[pos] >= mod)
			t[pos] -= mod;
		pos |= pos + 1;
	}
}

int get (int r) {
//	cerr << " = " << r << ' ';

	int res = 0;

	while (r >= 0) {
		res += t[r];
		if (res >= mod)
			res -= mod;
		r = (r & (r + 1)) - 1;
	}

//	cerr << res << endl;
	return res;
}

 
main () {
    p[0] = 1;
    for (int i = 1; i < N; ++i) 
    	p[i] = p[i - 1] * 2 % mod;
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		s[i] = s[i - 1] + a[i];
		b[i] = s[i - 1] - a[i];

		vals.pb(s[i - 1]);
		vals.pb(b[i]);
	}


	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i) {
		s[i - 1] = lower_bound(all(vals), s[i - 1]) - vals.begin();
		b[i] = lower_bound(all(vals), b[i]) - vals.begin();
	}


	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		++l[i], ++r[i];
		g[l[i]].pb({{s[l[i] - 1], i}, 0});
		g[r[i] + 1].pb({{s[l[i] - 1], i}, 1});
//		cerr << s[l[i] - 1] << ' ' << i << ' ' << 0 << endl;
	}


	for (int l = n; l > 0; --l) {
		inc(b[l], p[n - l]);
		for (auto x : g[l]) {
			int pref = x.f.f, i = x.f.s, tp = x.s;
			if (!tp) {
				res[i] += get(pref - 1);
				if (res[i] >= mod)
					res[i] -= mod;
			} else {
				res[i] -= get(pref - 1);
				if (res[i] < 0)
					res[i] += mod;
			}
		}
	}

	for (int i = 1; i <= q; ++i) { 
	    res[i] = res[i] * 1ll * binpow(p[n - r[i]], mod - 2) % mod;
		printf("%d\n", res[i]);    
	}

	

}