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

int x, dp[N][N];

int get (string s, string t) {
	int n = sz(s), m = sz(t);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			dp[i][j] = -1;

	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
			if (i < n && j < m && s[i] == t[j])
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
		}

	return dp[n][m];
}

string toString (int x) {
	if (!x)
		return "0";
	string res = "";
	while (x) {
		res += x % 10 + '0';
		x /= 10;
	}

	reverse(all(res));
	return res;
}
 

main () {
	fastio
	cin >> x;
	int res = -1, yy = -1;

	for (int y = 0; y <= x; ++y) {
		int cur = get(toString(y), toString(x - y));
		if (cur > res) {
			yy = y;     
			res = cur;
		}
	}

	cout << yy << ' ' << x - yy << ' '  << res << endl;
}