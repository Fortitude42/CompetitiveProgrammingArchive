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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 217;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, a[N*3], m, add, dp[N][N][N], b[N*3];
bool good[N][N];
 
main () {
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 1; i <= n * 3; ++i)
		cin >> a[i];
	
	dp[0][a[1]][a[2]] = dp[0][a[2]][a[1]] = 0;

	for (int i = 1; i < n; ++i) {
		for (int x = 1; x <= n; ++x)
			for (int y = 1; y <= n; ++y)
				if (dp[i - 1][x][y] != -1) {
					vi v;
					v.pb(x);
					v.pb(y);
					v.pb(a[i*3]);
					v.pb(a[i*3 + 1]);
					v.pb(a[i*3 + 2]);
					for (int j = 0; j < (1 << sz(v)); ++j) {
						vi v1, v2;
						for (int k = 0; k < sz(v); ++k)
							if(j & (1 << k))
								v1.pb(v[k]);
							else
								v2.pb(v[k]);

							if (sz(v1) != 3)
								continue;

							int cur = dp[i - 1][x][y] + (v1[0] == v1[1] && v1[1] == v1[2]);
							dp[i][v2[0]][v2[1]] = max(dp[i][v2[0]][v2[1]], cur);
							dp[i][v2[1]][v2[0]] = max(dp[i][v2[1]][v2[0]], cur);
					}
				}
	}

	int ans = 0;

	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
			ans = max(ans, dp[n - 1][x][y] + (x == y && x == a[n*3]));

	cout << ans << endl;
}