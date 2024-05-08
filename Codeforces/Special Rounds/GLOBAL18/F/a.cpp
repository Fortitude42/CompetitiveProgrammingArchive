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
const int N = 2e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, dp[M][M+M], dp1[M][M+M], ans;
string a, b;

inline void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;

	if (x < 0)
		x += MOD;
}
 

void solve() {
	cin >> n >> a >> b;
	a = "#" + a;
	b = "#" + b;

	for (int i = 1; i <= n; ++i) {
		if ((i & 1) && a[i] != '?')
			a[i] = '0' + '1' - a[i];
		if ((i & 1) && b[i] != '?')	
			b[i] = '0' + '1' - b[i];
	}

	for (int x = -n; x <= n; ++x)
		for (int i = 0; i <= n + 1; ++i)
			dp[i][x + M] = dp1[i][x + M] = 0;

	dp[0][M] = 1;

	for (int i = 1; i <= n; ++i) {
		
		int l1, r1, l2, r2;
		if (a[i] == '?') {
			l1 = 0;
			r1 = 1;
		} else 
			l1 = r1 = a[i] - '0';

		if (b[i] == '?') {
			l2 = 0;        
			r2 = 1;
		} else
			l2 = r2 = b[i] - '0';
		
		for (int x = -n; x <= n; ++x)
			for (int i1 = l1; i1 <= r1; ++i1)
				for (int i2 = l2; i2 <= r2; ++i2)
					add(dp[i][x + i1 - i2 + M], dp[i - 1][x + M]);
	}

	
	dp1[n + 1][M] = 1;
	for (int i = n; i > 0; --i) {
		
		int l1, r1, l2, r2;
		if (a[i] == '?') {
			l1 = 0;
			r1 = 1;
		} else 
			l1 = r1 = a[i] - '0';

		if (b[i] == '?') {
			l2 = 0;        
			r2 = 1;
		} else
			l2 = r2 = b[i] - '0';
		
		for (int x = -n; x <= n; ++x)
			for (int i1 = l1; i1 <= r1; ++i1)
				for (int i2 = l2; i2 <= r2; ++i2)
					add(dp1[i][x + i1 - i2 + M], dp1[i + 1][x + M]);
	}

	
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int x = -n; x <= n; ++x)
			add(ans, 1ll * abs(x) * 1ll * dp[i][x + M] % MOD * dp1[i + 1][M - x] % MOD);

	cout << ans << endl;
}

main () {
    fastio

	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}