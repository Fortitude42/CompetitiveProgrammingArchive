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


vi nodes;
ll dp[N][2];
bool bad[N];
vi g[N], G[N];
int n, q, a[N], b[N];
int tin[N], tout[N], timer, up[N][19], D[N];


void dfs(int v, int p = 0) {
	D[v] = D[p] + 1;
	up[v][0] = p;
	for (int i = 1; i < 19; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	tin[v] = ++timer;

	for (auto to : g[v])
		if (to != p)
			dfs(to, v);
	tout[v] = timer;
}

int lca(int v, int u) {
	if (D[v] < D[u])
		swap(v, u);

	for (int i = 18; i >= 0; --i)
		if (D[v] - (1 << i) >= D[u])
			v = up[v][i];

	if (v == u)
		return v;

	for (int i = 18; i >= 0; --i)
		if (up[v][i] != up[u][i]) {
			v = up[v][i];
			u = up[u][i];
		}

	return up[v][0];
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tin[u] <= tout[v];
}

int f(int v, int u){
	int l = lca(v, u);
	if (l == v)
		return up[u][0];
	if (l == u)
		return up[v][0];

	return l;
}

bool cmp(int v, int u) {
	return tin[v] < tin[u];
}

void dfs1(int v) {
	if (!sz(G[v])) {
		dp[v][0] = 0;
		dp[v][1] = bad[v] ? inf : 0;
//		cerr << v << ' ' << dp[v][0] << ' ' << dp[v][1] << endl;
		return;
	}

	dp[v][1] = 1;

	ll mx = 0;
	ll sum1 = 0;
	for (auto to : G[v]) {
		dfs1(to);
		sum1 += dp[to][1];
		dp[v][1] += min(dp[to][0], dp[to][1]);
		mx = max(mx, dp[to][1] - dp[to][0]);
	}

	if (bad[v]) {
		dp[v][0] = sum1;
		dp[v][1] = inf;
	} else {
		dp[v][1] = min(dp[v][1], sum1);
		dp[v][0] = sum1 - mx;
	}
	dp[v][0] = min(dp[v][0], (ll)inf);
	dp[v][1] = min(dp[v][1], (ll)inf);
	
//cerr << v << ' ' << dp[v][0] << ' ' << dp[v][1] << endl;
}   	

void clear() {
	for (auto x : nodes) {
		G[x].clear();
		bad[x] = 0;
	}
	nodes.clear();
}

main () {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
	scanf("%d", &q);
	while (q--)	{
		set < int > Q;
		int k;
		scanf("%d", &k);
		
		Q.insert(1);
		while (k--) {
			int v;
			scanf("%d", &v);
			Q.insert(v);
			bad[v] = 1;
		}

		for (auto x : Q)
			nodes.pb(x);
		sort(all(nodes), cmp);


		for (int i = 1; i < sz(nodes); ++i) {
			int l = lca(nodes[i], nodes[i - 1]);
			Q.insert(l);
			if (up[nodes[i]][0])
				Q.insert(up[nodes[i]][0]);
			if (up[nodes[i - 1]][0])
			Q.insert(up[nodes[i - 1]][0]);
		}

		nodes.clear();
		for (auto x : Q)
			nodes.pb(x);
		sort(all(nodes), cmp);

		stack < int > st;
		for (auto v : nodes) {
			while (sz(st) && tout[st.top()] < tin[v])
				st.pop();

			if (sz(st)) {
//			    cerr << v << ' ' << st.top() << endl;
				G[st.top()].pb(v); 
			}
			st.push(v);
		}                                       	


		dfs1(1);                    	
		ll ans = min(dp[1][0], dp[1][1]);
		if (ans == inf)
			ans = -1;
		printf("%lld\n", ans);
		clear();
	}
}