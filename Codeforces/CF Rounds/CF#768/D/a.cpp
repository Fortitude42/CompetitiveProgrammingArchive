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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, a[M], b[M];
vi g[M];
 
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	

	int x = 0;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
		x = __gcd(x, b[i]);
	}

	for (int i = 0; i < x; ++i)
		g[i].clear();

	for (int i = 1; i <= n; ++i) 
		g[i % x].pb(a[i]);
	
	ll s0 = 0, s1 = 0;
	for (int i = 0; i < x; ++i) {
		ll mx0 = -INF, mx1 = -INF;

		ll sum = 0, sum1 = 0;
		sort(all(g[i]));
		for (auto y : g[i])
			sum += y;

		for (int j = 0; j <= sz(g[i]); ++j) {
			if (j & 1)
				mx1 = max(mx1, sum - sum1);
			else
				mx0 = max(mx0, sum - sum1);

			if (j < sz(g[i])) {
				sum -= g[i][j];
				sum1 += g[i][j];
			}
		}

		s0 += mx0;
		s1 += mx1;
	}
	
	printf("%lld\n", max(s0, s1));
}

main () {
	fastio
	int TT;
	TT = 1;
	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}