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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 9, N = 5012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, sum, xsum, bits, dp[31][N], c[N][N];

void precalc () {
	for (int i = 0; i < N; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1]; 
			if (c[i][j] >= mod)
				c[i][j] -= mod;
		}
	}
}

main () {
	precalc();
	cin >> n >> sum >> bits >> xsum;

	
	for (int i = 0; i <= n; ++i)
		if ((xsum & 1) == (i & 1))
			dp[0][i] = c[n][i];


	for (int i = 0; i < bits - 1; ++i)
		for (int s = 0; s <= sum; ++s)
			for (int x = ((xsum >> (i + 1)) & 1); s + x* 1ll * (1 << (i + 1)) <= sum && x <= n; x += 2) {
				dp[i + 1][s + x*(1 << (i + 1))] = (dp[i + 1][s + x*(1 << (i + 1))] + dp[i][s] * 1ll * c[n][x]) % mod;
			}



				
	cout << dp[bits - 1][sum] << endl;
}