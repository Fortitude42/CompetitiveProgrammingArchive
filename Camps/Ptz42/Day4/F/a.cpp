//by paradox & gege & parasat
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
typedef vector < double > vd;
typedef vector < vector < double > > vvd;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 64, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 5, K = 6;
const ll INF = 1e18;

inline vvd mult(vvd &a, vvd &b) {
	vvd c (sz(a), vd(sz(b[0]), 0.0));
	for (int i = 0; i < sz(c); i++) {
		for (int j = 0; j < sz(c[i]); j++) {
			for (int k = 0; k < sz(a[i]); k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

inline vvd sum(vvd a, vvd b) {
	vvd c (sz(a), vd(sz(a[0]), 0.0));
	for (int i = 0; i < sz(c); i++) {
		for (int j = 0; j < sz(c[i]); j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return c;
}

void prt(vvd a, string s = "") {
	cerr << "matrix " + s + " (" << sz(a) << ", " << sz(a[0]) << ")\n";
	for (int i = 0; i < sz(a); i++) {
		for (int j = 0; j < sz(a[i]); j++)
			cerr << a[i][j] << ' ';
		cerr << "\n";
 	}
 	cerr << "\n";
}
 
void solve() {
	int n, k;
	double pr;
	scanf("%d %d %lf", &n, &k, &pr);
		
	int m = (1 << n);
	vvd dp (m, vd(m, 0.0));
	vvd p (m, vd(m, 0.0));

	for (int mask = 0; mask < m; mask++) {
		if (__builtin_popcount(mask) == k)
			continue;
		for (int to = 0; to < m; to++) {
			if (((mask << 1) & (m - 1)) == to) {
				dp[mask][to] = p[mask][to] = 1.0 - pr;
			} else if (((mask << 1) & (m - 1)) + 1 == to) {
				dp[mask][to] = p[mask][to] = pr;
			}
		}
	}

	vvd pin = p;
	vvd pd = p;

	double ans = 0.0;
	
	for (int i = 0; i <= 2; i++) {

		cerr << "i = " << i << "\n";
		prt(dp, "dp");
		prt(p, "p");

		for (int mask = 0; mask < m; mask++)
			if (__builtin_popcount(mask) == k)
				ans += dp[0][mask];
	
	    vvd nxt(m, vd(m, 0.0));
	    for (int a = 0; a < m; a++) {
	    	for (int c = 0; c < m; c++) {
	    		for (int b = 0; b < m; b++) {
	    			nxt[a][c] += dp[a][b] * p[b][c] + dp[b][c] * p[a][b];
	    		}
	    		nxt[a][c] += pin[a][c];
	    	}
	    }
	    dp = nxt;

		p = sum(p, mult(p, pd));
		pd = mult(pd, pd);
	}

	printf("%.10lf\n", ans);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

