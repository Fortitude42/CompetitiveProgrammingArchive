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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, m, x[N], opt[N][N]; 
ll dp[N][N], s[N][N];
pii a[N];

int get (int l, int r, int i) {
	return s[i][r] - s[i][l - 1];
}


main () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	sort(x + 1, x + 1 + n);

	for (int i = 1; i <= m; ++i)
		cin >> a[i].f >> a[i].s;

	sort(a + 1, a + 1 + m);
	for (int j = 1; j <= m; ++j) 
		for (int i = 1; i <= n; ++i)
			s[j][i] = s[j][i - 1] + abs(a[j].f - x[i]);
	

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			dp[i][j] = INF;

	dp[0][0] = 0;

	for (int j = 1; j <= m; ++j)
		for (int i = n; i >= 0; --i) {
			int L = j == 1 ? 0 : opt[i][j - 1], R = i == n ? n : opt[i + 1][j];
			L = max(0, L - 10), R = min(n, R + 10);
			dp[i][j] = dp[i][j - 1];
			opt[i][j] = i;
			for (int x = max(L, i - a[j].s); x <= min(R, i); ++x) {
				if (dp[i][j] > dp[x][j - 1] + get(x, i, j)) {
					dp[i][j] = dp[x][j - 1] + get(x, i, j);
					opt[i][j] = x;
				}
			}

//			if (j == 2 && i == 3)
//				cerr << L << ' ' << R << ' ' << dp[i][j] << endl;
		}

//	for (int j = 0; j <= m; ++j) {
//		for (int i = 0; i <= n; ++i)
//			cout << dp[i][j] << ' ';
//		cout << endl;
//	}
	cout << dp[n][m] << endl;
				
		
}