//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int up[M][20], tin[M], tout[M], d[M], timer;
int n, m, p[M], s[M];
vector < pii > e;
vi g[M];

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}


void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	d[v] = d[p] + 1;
	up[v][0] = p;
	for (int i = 1; i < 20; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (auto to : g[v])
		if (to != p)
			dfs(to, v);		

	tout[v] = timer;
}

int lca(int v, int u) {
	if (d[v] < d[u])
		swap(v, u);

	for (int i = 19; i >= 0; --i)
		if (d[v] - (1 << i) >= d[u])
			v = up[v][i];

	if (v == u)
		return v;

	for (int i = 19; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			v = up[v][i];
			u = up[u][i];
		}

	return up[v][0];			
}

int getson(int v, int p) {
	for (int i = 19; i >= 0; --i)
		if (d[v] - (1 << i) > d[p])
			v = up[v][i];

	return v;
}




void inc_subtree(int v) {
	++s[tin[v]];
	--s[tout[v] + 1];
}

void inc_supertree(int v) {
	++s[1];
	--s[tin[v]];

	++s[tout[v] + 1];
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		p[i] = i;

	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		if (get(a) == get(b))
			e.pb({a, b});
		else {
			g[a].pb(b);
			g[b].pb(a);
			merge(a, b);
		}
	}

	dfs(1);
	for (auto x : e) {
		int a = x.f, b = x.s;
		int c = lca(a, b);

		if (a == c)
			inc_supertree(getson(b, c));
		else
			inc_subtree(a);

		if (b == c)
			inc_supertree(getson(a, c));
		else
			inc_subtree(b);	
	}

	for (int i = 1; i <= n; ++i)
		s[i] += s[i - 1];

	for (int i = 1; i <= n; ++i)
		cout << (s[tin[i]] == sz(e));
	cout << endl;

}

main () {
	int TT = 1;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}