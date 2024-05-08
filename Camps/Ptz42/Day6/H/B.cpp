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
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 2e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, dp[M][M];

int c[M][M];
 
int get(int n, int k){
	return c[n + 1][k + 1];
}

void solve() {
	cin >> n >> m;
	c[0][0] = 1;
	for(int i = 1; i < M; i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	for (int i = 1; i <= m; ++i)
		dp[1][i] = i * (i + 1) / 2;
	
	//dp[1][1] = 1;
	
	/*for (int i = 2; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int x = 1; x <= j; ++x)
				dp[i][j] += j*dp[i - 1][x];
	*/

	for (int i = 1; i <= n; ++i, cout << endl)
		for (int j = 1; j <= m; ++j) {
			if(i > 1)
				dp[i][j] += dp[i][j - 1] + dp[i - 1][j] * j;
			
			//cout << dp[i][j] << " ";
			int delta = dp[i][j] - dp[i][j - 1];
			cout << i << " : " << j << " -> " << delta << " " << get(j, i - 1) << "\n"; 
		}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

