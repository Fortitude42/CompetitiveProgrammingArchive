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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, q, x, y, a[N], b[N];
map < pii, vi > g;
pii dp[N][4];
char s[N];
 
main () {
	scanf("%d\n%s", &n, s);
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i - 1];
		b[i] = b[i - 1];
		if (s[i - 1] == 'L')
			--a[i];
		else if (s[i - 1] == 'R')			
			++a[i];
		else if (s[i - 1] == 'U')
			++b[i];
		else
			--b[i];

		g[mp(a[i], b[i])].pb(i);
	}



	for (int j = 0; j < 4; ++j)
		dp[n + 1][j] = mp(dx[j], dy[j]);

	for (int i = n; i > 0; --i) 
		for (int j = 0; j < 4; ++j) {
			pii cur = mp(a[i - 1] - dx[j], b[i - 1] - dy[j]);
			if (!sz(g[cur]) || g[cur].back() < i) {
				dp[i][j] = mp(dx[j] + a[n] - a[i - 1], dy[j] + b[n] - b[i - 1]);
				continue;
			}

			int x = *lower_bound(all(g[cur]), i);

			if (s[x - 1] == 'L')
				dp[i][j] = dp[x + 1][1];
			else if (s[x - 1] == 'R')
				dp[i][j] = dp[x + 1][0];
			else if (s[x - 1] == 'D')
				dp[i][j] = dp[x + 1][3];
			else
				dp[i][j] = dp[x + 1][2];
		}

	
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
		if (!sz(g[mp(-x, -y)])) 
			printf("%d %d\n", x + a[n], y + b[n]);
		else {
			int i = g[mp(-x, -y)][0], tp;
			if (s[i - 1] == 'L')
				tp = 1;
			else if (s[i -  1] == 'R')	
				tp = 0;
			else if (s[i - 1] == 'D')	
				tp = 3;
			else
				tp = 2;	
			printf("%d %d\n", dp[i + 1][tp].f, dp[i + 1][tp].s);
		}
	}
	
}