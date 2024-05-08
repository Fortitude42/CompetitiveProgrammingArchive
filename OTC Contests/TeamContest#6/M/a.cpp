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
typedef vector < 	pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, m, c[N], ok, v, u;
vi g[N];
vpii e;

bool dfs (int v, int cc) {
	c[v] = cc;
	for (auto to : g[v])
		if (!c[to]) 
			dfs(to, 3 - cc);
		else if (c[to] == c[v]) {
			cout << 0 << endl;
			exit(0);
		}
}

 
main () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		g[i*2].pb(i*2 + 1);
		g[i*2 + 1].pb(i*2);
	}

		
	while (m--) {
		cin >> v >> u;
		int v1, v2, u1, u2;
		v1 = abs(v)*2 + 1, u1 = abs(u)*2 + 1; 
		v2 = abs(v)*2, u2 = abs(u)*2;

		if (v < 0)
			swap(v1, v2);
		
		if (u < 0)	
			swap(u1, u2);

		if (v < 0 && u < 0)
			ok = 1;

		cerr << v1 << ' ' << v2 << endl;
		cerr << u1 << ' ' << u2 << endl << endl;
		g[v1].pb(u2);
		g[u2].pb(v1);

		g[v2].pb(u1);
		g[u1].pb(v2);
	}


	if (!ok) {
		cout << -1 << endl;
		return 0;
	}


	for (int i = 1; i <= 2*n + 1; ++i)
		if (!c[i]) 
			dfs(i, 1);
		
	
	cout << 1 << endl;	
}