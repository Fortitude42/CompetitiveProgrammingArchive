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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int T, n, m, dp[N][20];
char s[N], t[N];
 
main () {
	scanf("%d", &T);
	while (T--) {
		scanf("\n%s\n%s", s, t);
		n = strlen(s), m = strlen(t);
 
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j < 20; ++j)
				dp[i][j] = inf;
 
		dp[0][10] = 0;
		for (int i = 1; i <= n; ++i)
			for (int x = 0; x < 20; ++x) {
				if (i - 1 + x - 10 < 0 || i - 1 + x - 10 >= m)
					continue;
				if (s[i - 1] == t[i - 1 + x - 10]) {
					dp[i][x] = dp[i - 1][x];
					continue;
				}
 
				dp[i][x] = dp[i - 1][x] + 1;
				if (x < 20)
					dp[i][x] = min(dp[i][x], dp[i - 1][x + 1] + 1);
				if (x)
					dp[i][x] = min(dp[i][x], dp[i][x - 1] + 1);
			}
 
		int ans = inf;
		for (int x = 0; x < 20; ++x)
			ans = min(ans, dp[n][x] + abs(m - (n + x - 10)));
 
		if (!ans)
			puts("You're logged in!");
		else if (ans == 1)
			puts("You almost got it. You're wrong in just one spot.");
		else if (ans == 2)
			puts("You almost got it, but you're wrong in two spots.");
		else if (ans == 3)
			puts("You're wrong in three spots.");			
		else
			puts("What you entered is too different from the real password.");			
	}
}