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

int n, q, par[N], tp, p[N], tin[N], tout[N], timer, v, u, up[N][18], d[N], s[N][18], col[N], C;
unordered_map < int, int > gg[N];
vi g[N];
 

void dfs (int v) {
	tin[v] = ++timer;
	col[v] = C;
	for (auto to : g[v]) {
		up[to][0] = v;
		s[to][0] = gg[v][to];

		for (int i = 1; i < 18; ++i) {
			up[to][i] = up[up[to][i - 1]][i - 1];
			s[to][i] = s[to][i - 1] + s[up[to][i - 1]][i - 1];
		}

		d[to] = d[v] + 1;

		dfs(to);          
	}

	tout[v] = ++timer;
}

bool upper (int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

pii lca (int v, int u) {
    int res = 0;
	if (d[v] < d[u])
		swap(v, u);

	for (int i = 17; i >= 0; --i)
		if (d[v] - (1 << i) >= d[u]) {
		    res += s[v][i];
			v = up[v][i];             
		}

	if (v == u)
		return {v, res};

	for (int i = 17; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			res += s[v][i];
			res += s[u][i];

			v = up[v][i];
			u = up[u][i];
		}

	return {up[v][0], res + s[v][0] + s[u][0]};
}


main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		p[i] = i;

	for (int i = 1; i <= n; ++i) {
		cin >> par[i] >> tp;
		if (par[i] == -1)
			continue;
		g[par[i]].pb(i);
		gg[par[i]][i] = tp ^ 1;			
	}

	for (int i = 1; i <= n; ++i)
		if (!tin[i]) {
		    ++C;
			dfs(i);   
		}
	
	cin >> q;
	while (q--) {
		cin >> tp >> v >> u;
		if (v == u || col[v] != col[u]) {
			puts("NO");
			continue;
		}

		if (tp == 1) {
			if (!upper(v, u) || lca(v, u).s != d[u] - d[v]) {
				puts("NO");
			} else 
				puts("YES");			
		} else { 
			int l = lca(v, u).f;
			cerr << lca(l, u).s << ' ' << lca(l, v).s << endl;
			if (l == u || lca(l, u).s > 0 || lca(l, v).s != d[v] - d[l]) 
				puts("NO");
			else
				puts("YES");
		}
	}
}