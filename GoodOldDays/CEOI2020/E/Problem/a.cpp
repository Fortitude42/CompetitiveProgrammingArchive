
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, Q, v, u, d, x[N], cnt[N], up[N][17], l[N], s[N], ans, l1, l2;
int tin[N], tout[N], timer, par[N], res, ss[N], root;
vi g[N], V, G[N];
set < pii > q;
 
 
void dfs (int v, int p = 0) {
	tin[v] = ++timer;
	cnt[v] = (sz(g[v]) == 1);
	l1 += cnt[v];
	
	l[v] = l[p] + 1;
	up[v][0] = p;
	for (int i = 1; i < 17; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
 
	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			cnt[v] += cnt[to];
		}
	    
	if (!(cnt[v] & 1) && v != root) {
		++s[v];          
		++ans;
	}
 
 
	tout[v] = ++timer;
}
 
void dfs2 (int v, int p = 0) {
	s[v] += s[p];
 
	for (auto to : g[v])
		if (to != p)
			dfs2(to, v);
}
 
 
int lca (int v, int u) {
	if (l[v] < l[u])
		swap(v, u);
 
	for (int i = 16; i >= 0; --i)
		if (l[v] - (1 << i) >= l[u])
			v = up[v][i];
 
	if (v == u)
		return v;
 
	for (int i = 16; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			v = up[v][i];
			u = up[u][i];
		}
 
	return up[v][0];
}
 
 
bool cmp (int i, int j) {
	return tin[i] < tin[j];
}

bool upper (int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}
 
 
void dfs1 (int v) {
    ss[v] = 0;
	if ((sz(g[v]) == 1 && cnt[v] > 1 && cnt[v] % 2 == 0) || (sz(g[v]) > 1 && (cnt[v] & 1)))
		ss[v] = 1;
 
	for (auto to : G[v])  {
		dfs1(to);            
		ss[v] += ss[to];
	}
}
 
main () {
	fastio
	cin >> n >> Q;
	for (int i = 1; i < n; ++i) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	root = 1;
	while (sz(g[root]) == 1)
		++root;
 
	ans = n - 1;
	dfs(root);
	dfs2(root);
 
	memset(cnt, 0, sizeof(cnt));
	while (Q--) {
		V.clear();
		q.clear();
		
		cin >> d;
 
		res = ans + d;
		l2 = l1 + d;

		V.pb(root);
		for (int i = 1; i <= d; ++i) {
			cin >> x[i];              
			V.pb(x[i]);
		}
  
		sort(x + 1, x + 1 + d, cmp);
 
		for (int i = 2; i <= d; ++i) {
			int L = lca(x[i - 1], x[i]);
			V.pb(L);
		}
 
 
		sort(all(V), cmp);
		V.resize(unique(all(V)) - V.begin());

		for (auto x : V)
			cnt[x] = 0;

		for (int i = 1; i <= d; ++i)
			++cnt[x[i]];
 
		for (auto x : V) {
			if (sz(q))
				par[x] = q.lower_bound(mp(tin[x], inf))->s;
			else
				par[x] = 0;	

//			assert(x == root || par[x] == root);
//		    assert(upper(par[x], x));
 
			q.insert(mp(tout[x], x));
			G[x].clear();
		}
		
 
		for (auto x : V) {
			if (par[x])
				G[par[x]].pb(x); 
			if (sz(g[x]) == 1 && cnt[x])
				--l2;
		}
 
		if (l2 % 2 == 1) {
			cout << -1 << endl;
			continue;
		}
 
 
		dfs1(V[0]);
			
		for (auto x : V) {
			if (x == root || ss[x] % 2 == 0)
				continue;	
 
			res += (l[x] - l[par[x]]) - 2*(s[x] - s[par[x]]);						 		
		}
		
 
		cout << res << endl;
	}	
 
}
