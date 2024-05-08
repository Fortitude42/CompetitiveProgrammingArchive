#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
                       	
//#define int long long 
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 

int t, n, m, a[N], b[N], v, u, found;
bool was[N];
pii d[N];
vi g[N];

void dfs (int v, int av) {	
	was[v] = 1;
	a[v] = min(a[v], av);
	for (auto to : g[v])
		if (!was[to] && b[to] <= av && av <= a[to])
			dfs(to, av);	
}


	
main () {
	fastio
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);  
			d[i] = {a[i], i};
			g[i].clear();
		}
		

		int ans = 1;

		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]); 
			if (b[i] > a[i]) 
				ans = 0;							
		}

	    int mm = m;
		while (m--) {
			scanf("%d%d", &v, &u);
			g[v].pb(u);
			g[u].pb(v);
		}	


		
		sort(d + 1, d + 1 + n);
		reverse(d + 1, d + 1 + n);

		for (int i = 1; i <= n; ++i) {
			int j = d[i].s;
			for (int x = 1; x <= n; ++x)
				was[x] = 0;

			dfs(j, a[j]);
		}

		for (int i = 1; i <= n; ++i)
			if (a[i] != b[i])			
				ans = 0;
				

		printf("%d\n", ans);
	}
}