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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, q, a[N][N], x, y, z;
ll sx[N], sy[N], Sx[N], Sy[N], Px[N], Py[N];

ll FindX () {
	for (int i = 1; i <= n; ++i)
		Px[i] = Px[i - 1] + sx[i];

	for (int i = 1; i <= n; ++i)
		Px[i] += Px[i - 1];

	for (int i = n; i > 0; --i)
		Sx[i] = Sx[i + 1] + sx[i];

	for (int i = n; i > 0; --i)
		Sx[i] += Sx[i + 1];

	ll ans = INF;
	for (int i = 1; i <= n; ++i)
		ans = min(ans, Px[i - 1] + Sx[i + 1]);

	return ans;
}

ll FindY () {
	for (int i = 1; i <= m; ++i)
		Py[i] = Py[i - 1] + sy[i];

	for (int i = 1; i <= m; ++i)
		Py[i] += Py[i - 1];

	for (int i = m; i > 0; --i)
		Sy[i] = Sy[i + 1] + sy[i];

	for (int i = m; i > 0; --i)
		Sy[i] += Sy[i + 1];

	ll ans = INF;
	for (int i = 1; i <= m; ++i)
		ans = min(ans, Py[i - 1] + Sy[i + 1]);

	return ans;
}
		
main () {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);    
			sx[i] += a[i][j];
			sy[j] += a[i][j];
		}

	printf("%lld ", FindX() + FindY());
	while (q--) {
		scanf("%d%d%d", &x, &y, &z);
		sx[x] -= a[x][y];
		sy[y] -= a[x][y];
		a[x][y] = z;
		sx[x] += a[x][y];
		sy[y] += a[x][y];
		printf("%lld ", FindX() + FindY());
	}

	
}