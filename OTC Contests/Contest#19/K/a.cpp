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
 
const int inf = 1e9, maxn = 15e6 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
//shift, level, 

int n, a[N], p[N], l[N], d[N], dp[maxn][2];
bool was[N];
vi g[N];

void dfs (int v) {
	if (!sz(g[v]))
		return;

	l[g[v][0]] = l[v] + 1;
	d[g[v][0]] = d[v] + p[l[v]];

	l[g[v][1]] = l[v] + 1;
	d[g[v][1]] = d[v] + p[l[v]] * 2;

	dfs(g[v][0]);
	dfs(g[v][1]);
}

int rec (int v, int ok, int shift, int lvl, int block) {

}

main () {
	scanf("%d", &n);
	int lvl = 0;
	while ((1 << lvl) - 1 < n)
		++lvl;

	for (int i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d%d%d", &l, &r, &a[i]);
		if (l)
			g[i].pb(l);
		if (r)
			g[i].pb(r);
		was[l] = was[r] = 1;
	}

	int root = 1;
	while (was[root])
		++root;
	dfs(root);


	p[0] = 1;
	for (int i = 1; i <= lvl; ++i)
		p[i] = p[i - 1] * 3;

	for (int i = 1; i <= n; ++i) {
		puts(rec(d[i], b[i], 1, l[i], 1) ? "Ksusha" : "Sasha");
	}
	

	
}