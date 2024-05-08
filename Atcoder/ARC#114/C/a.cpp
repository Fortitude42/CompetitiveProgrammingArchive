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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 5012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


void add (int &x, int y) {	
	x += y;
	if (x >= mod)
		x -= mod;
}

int n, m, dp[N][N], pw[N][N], s[N];
 
main () {	
	cin >> n >> m;

	pw[0][0] = 1;
	for (int i = 1; i < N; ++i)  {
		pw[i][0] = 1;
		for (int j = 1; j < N; ++j)
			pw[i][j] = pw[i][j - 1] * 1ll * i % mod;
	}


	for (int len = 1; len < N; ++len)
		for (int i = 1; i <= m; ++i) {
			dp[len][i] = pw[m - 1][len] - pw[m - i][len];
			if (dp[len][i] < 0)
				dp[len][i] += mod;
			add(s[len], dp[len][i]);
		}



	int ans = 0;
	for (int l = 1; l <= n; ++l) {
		for (int r = l + 2; r <= n; ++r)
			add(ans, pw[m][l - 1] * 1ll * s[r - l - 1] % mod * pw[m][n - r] % mod);

		add(ans, pw[m - 1][l - 1] * 1ll * m % mod * pw[m][n - l] % mod);
	}

	cout << ans << endl;
			
}