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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, Q[N][N], k, s[N][N], sum[N][N][N];
ll dp[N][N], cost, value;
vector < pll > g[N];

struct line {
	ll k, b;
	line () {}

	line (int k1, int b1) {
		k = k1;
		b = b1;
	}
}; 

db inter (line a, line b) {
	return (a.b - b.b + 0.0) / (b.k - a.k);
}

struct CHT {
	vector < line > v;
	void add (line L) {
		while (sz(v) > 1 && inter(v.back(), v[sz(v) - 2]) > inter(L, v.back()))
			v.ppb();
		v.pb(L);	
	}

	ll get (int x) {
		int l = 0, r = sz(v) - 2;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (inter(v[mid], v[mid + 1]) <= (x + 0.0))
				l = mid + 1;
			else
				r = mid - 1;
		}

		return v[l].k * x + v[l].b;
	}
} C[N];


ll rec (int l, int r) {		
	ll &res = dp[l][r];

	if (res != -INF)
		return res;

	if (l > r)
		return res = 0;

	for (int x = l; x <= r; ++x)  {
		res = max(res, rec(l, x - 1) + rec(x + 1, r) + C[x].get(sum[x][l][r])); 
	}

	return res;
}

main () {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			scanf("%lld", &Q[i][j]);

	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &k);
		while (k--) {
			scanf("%lld%lld", &value, &cost);
			g[i].pb({value, -cost});
		}
	}


	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			s[i][j] = s[i - 1][j] + Q[i][j];
	
	for (int i = 1; i <= n; ++i)
		for (int l = 1; l <= i; ++l)
			for (int r = i; r <= n; ++r) {
				sum[i][l][r] = sum[i][l][r - 1] + s[i][r] - s[l - 1][r];
			}
	
	for (int i = 1; i <= n; ++i) {
		sort(all(g[i]));

		for (int j = 0; j < sz(g[i]); ++j) {
			if (j < sz(g[i]) - 1 && g[i][j].f == g[i][j + 1].f)
				continue;
//			cerr << i << ' ';
			C[i].add(line(g[i][j].f, g[i][j].s));
		}		
//		cerr << endl;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dp[i][j] = -INF;

	cout << rec(1, n) << endl;
}