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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e3 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, l, r, lf[N], dp[N][N], sum, s[N], r3, s1[N], p[N];

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}

void upd (int i, int j, int x) {
	add(sum, x);
	add(s[i], x);
	add(dp[i][j], x);
} 

main () {
	p[0] = 1;
	for (int i = 1; i < N; ++i)
		p[i] = p[i - 1] * 6ll % mod;
	r3 = 333333336;

	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 1; i <= n; ++i)
			lf[i] = 0;

		while (m--) {
			scanf("%d%d", &l, &r);
			lf[r] = max(lf[r], l);
		}

		dp[0][0] = s[0] = sum = 1;
		for (int i = 1; i <= n; ++i) {
			s[i] = 0;
			for (int j = 0; j <= i; ++j)
				dp[i][j] = 0;
		}

		int last = 0;

		for (int i = 1; i <= n; ++i) {
			int sum1 = sum;
			for (int j = 0; j < i; ++j)
				s1[j] = s[j];

			while (last < lf[i]) {
				for (int j = 0; j < i; ++j)
					upd(j, last, -dp[j][last]); 
				++last;
			}
			
			for (int j = last; j < i; ++j) 
				upd(i, j, s1[j] * 1ll * r3 % mod);			
			
			upd(i, i, sum1 * 1ll * r3 % mod);
		}

		printf("%d\n", sum * 1ll * p[n] % mod);
	}
}                