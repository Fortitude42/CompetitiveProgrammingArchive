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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, m, v, u, ans, col[N], k;
bool was[52][52][52];
vi g[N];
 
void dfs (int v, int p) {
	col[v] = k;
	for (auto to : g[v])
		if (to != p && !col[to])
			dfs(to, p);
}
 
 
main () {
	fastio
	cin >> n >> m;
	while (m--) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
 
	int ans = n*(n - 1)*(n - 2);
	int res = 0;	
 
	for (int v = 1; v <= n; ++v) {
	    memset(col, 0, sizeof(col));
 
		for (int i = 1; i <= n; ++i)
			if (i != v && !col[i]) {
			    ++k;
				dfs(i, v); 
			}
 
		for (int s = 1; s <= n; ++s)
			for (int c = 1; c <= n; ++c)
				if (c != v && col[s] != col[c])
					for (int f = 1; f <= n; ++f)
						if (f != s && col[c] != col[f] && !was[s][c][f]) {
							--ans;
							cout << c <<  ' ' << s << ' ' << f << endl;
							++res; 							
							was[s][c][f] = 1;
						}
	}

 	cerr << ans << endl; 	
	cout << ans << endl;
}