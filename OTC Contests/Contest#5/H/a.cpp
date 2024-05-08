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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 32;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, q, a[14][N], tp, x, y, m, mask[N][13];
bitset < (1 << 12) + 10 > u[N];
 
main () {
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < k; ++i) 
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < k; ++j) {
			for (int x = 0; x < k; ++x)
				if (a[x][i] >= a[j][i])
					mask[i][j] |= (1 << x);
		}

	for (int i = 0; i < (1 << k); ++i)
		for (int j = 0; j < k; ++j)
			u[j][i] = ((i >> j) & 1);

	

	m = k;
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d", &tp, &x, &y);			
		--x, --y;
		if (tp == 1) 
			u[m++] = u[x] | u[y];
		else if (tp == 2) 
			u[m++] = u[x] & u[y];
		else {
			++y;
			int ans = 0;
			for (int j = 0; j < k; ++j)
				if (u[x][mask[y][j]])
					ans = max(ans, a[j][y]);
			printf("%d\n", ans);				
		}
	}
			
}