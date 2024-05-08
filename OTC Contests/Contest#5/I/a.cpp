#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, q, a[N], l, r, res[N], m, p[N], prv[N], pw[N], s[N], sum[N], ss[N];
vpii g[N];

int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge (int v, int u) {
	if (v - prv[v] > 31 && sum[u] > 0)
		sum[u] = mod;
	else if (sum[v] + (1ll << (v - prv[v])) * sum[u] > mod)
		sum[u] = mod;
	else
		sum[u] = sum[v] + (1 << (v - prv[v])) * sum[u];

	p[v] = p[u];
	prv[u] = prv[v];
}

int get (int l, int r) {
	return (s[l] - pw[r - l + 1] * 1ll * s[r + 1] % mod + mod) % mod;
}


main () {
	scanf("%lld%lld", &n, &q);
	pw[0] = 1;

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);       
		p[i] = i;
		prv[i] = i - 1;
		pw[i] = pw[i - 1] * 2 % mod;
	}

	for (int i = n; i > 0; --i)
		s[i] = (s[i + 1] * 2 + a[i]) % mod;
	


	for (int i = 1; i <= q; ++i) {
		scanf("%lld%lld", &l, &r);
		g[r].pb({l, i});
	}

	for (int r = 1; r <= n; ++r) {
		sum[r] = a[r];
		while (sum[r] >= 0 && prv[r]) {
			merge(prv[r], r);
//			cerr << r << ' ' << prv[r] << endl;
		}

		ss[r] = (ss[prv[r]] + 2ll * get(prv[r] + 1, r)) % mod;

		for (auto i : g[r]) {
			res[i.s] = ((ll)(ss[r] - ss[get(i.f)] + get(i.f, get(i.f))) % mod + mod) % mod;
		}
	}

	for (int i = 1; i <= q; ++i)
		printf("%lld\n", res[i]);	
}