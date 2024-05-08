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


int n, m, d[N], a[N], c[N];
vi g[N];

bool check (int x) {	
	memset(c, 0, sizeof(c));

	for (int i = 1; i <= m; ++i) {
		if (!sz(g[i]) || g[i][0] > x)
			return 0;
		int j = upper_bound(all(g[i]), x) - g[i].begin() - 1;
		c[g[i][j]] = a[i];
	}

	int bal = 0;
	for (int i = 1; i <= n; ++i) {
		if (!c[i])
			++bal;
		else {
			if (c[i] > bal)
				return 0;
			bal -= c[i];	
		}
	}

	return 1;
}

main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);        
		if (d[i] > 0)
			g[d[i]].pb(i);
	}

	for (int i = 1; i <= m; ++i)
		scanf("%d", &a[i]);

	int l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;	
	}

	if (r == n)
		cout << -1;
	else
		cout << r + 1;	
}