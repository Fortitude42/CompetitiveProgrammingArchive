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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 4e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

pii a[N];
int n, m, t;
vector < pll > b, c;
ll dp[N][2], x[N], xa[N], xb[N];



 
main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) 
			scanf("%lld", &x[i]);     
		sort(x + 1, x + 1 + n);

		for (int i = 1; i <= m; ++i)
			scanf("%d%d", &a[i].f, &a[i].s); 

		sort(a + 1, a + 1 + m);
		  
		b.clear();
		for (int i = 1; i <= m; ++i) {
			while (sz(b) && b.back().s >= a[i].s)
				b.ppb();
			b.pb(a[i]);	          
		}

		c.clear();
		for (auto X : b) {
			int Y = lower_bound(x + 1, x + 1 + n, X.f) - x;
			if (Y > n || x[Y] > X.s)
				c.pb(X);
		}


		
		dp[0][0] = dp[0][1] = 0;
		x[0] = -INF;
		x[n + 1] = INF;

		int l = 0, r = 0;
		for (int i = 1; i <= n + 1; ++i) {
			while (l < sz(c) && c[l].s < x[i - 1])
				++l;

			while (r < sz(c) && c[r].s < x[i])
				++r;

			if (l == r) {
				dp[i][0] = dp[i - 1][1];
				dp[i][1] = dp[i - 1][1];
				continue;
			}

			//l..r - 1
			dp[i][1] = dp[i - 1][1] + x[i] - c[l].s;
			dp[i][0] = dp[i - 1][1] + (x[i] - c[l].s) * 2;

			for (int j = l; j < r; ++j) {
				ll dist = (j == r - 1 ? 0 : x[i] - c[j + 1].s);
				ll cur = min(dp[i - 1][0] + c[j].f - x[i - 1], dp[i - 1][1] + 2*(c[j].f - x[i - 1]));
				dp[i][1] = min(dp[i][1], cur + dist);
				dp[i][0] = min(dp[i][0], cur + dist*2);
			}

//			cerr << dp[i][0] << ' ' << dp[i][1] << endl;
		}

		printf("%lld\n", dp[n + 1][1]);
	}
}