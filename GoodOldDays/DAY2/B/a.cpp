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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, c, x, ans, m;
bool was[N];
vi g[N];

void dfs (int v, int mask) {
	was[v] = 1;
	m |= (1 << v);
	for (auto to : g[v])
		if (!was[to] && (mask & (1 << to))) 
			dfs(to, mask);						
}

main () {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		while (c--) {
			cin >> x;
			--x;
			g[i].pb(x);
		}
	}


	ans = inf;
	for (int mask = 0; mask < (1 << n); ++mask) {
		if (!(mask & 1) || !(mask & (1 << (n - 1))))
			continue;

		memset(was, 0, sizeof(was));
		m = 0;
		dfs(0, mask);
		if (m != mask)	
			continue;
		
		memset(was, 0, sizeof(was));
		dfs(n - 1, mask);
		if (was[0]) 
			ans = min(ans, __builtin_popcount(mask));		
	}

	ans %= inf;
	cout << ans - 1 << endl;
}