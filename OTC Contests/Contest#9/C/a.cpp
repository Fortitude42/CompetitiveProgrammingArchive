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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, k, q;
int xa, ya, xb, yb;
vi c[2][N], dp[N];
 
main () {
	scanf("%d%d%d", &n, &m, &k);
	
	for (int x = 0; x < 2; ++x)
		for (int i = 1; i <= n; ++i) 
			c[x][i].resize(m + 1);		

	for (int i = 1; i <= n; ++i)
		dp[i].resize(m + 1);


	for (int i = 1; i <= k; ++i) {
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);

		if (xa > xb) {
			swap(xa, xb);
			swap(ya, yb);
		}

		if (ya > yb) {
			swap(xa, xb);
			swap(ya, yb);
		}

		if (xa != xb)
			++c[0][xa][ya];
		else
			++c[1][xa][ya];	
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + c[0][i][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + c[1][i][j]);
			cerr << i << ' ' << j << endl;
		}


 	scanf("%d", &q);

	while (q--) {
		scanf("%d%d", &xa, &ya);
		int dist = xa + ya - 2, ans = 0;

		for (int i = 1; i <= xa; ++i)
			for (int j = 1; j <= ya; ++j)
				if (i + j - 2 == (dist + 1) / 2 && xa + ya - i - j == dist / 2) 
					ans = max(ans, dp[i][j]);

		printf("%d\n", ans);
	}
}