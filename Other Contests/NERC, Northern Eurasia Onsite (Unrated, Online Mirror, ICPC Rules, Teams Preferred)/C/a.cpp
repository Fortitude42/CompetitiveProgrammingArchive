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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, par[M], tin[M], timer, dp[M], parr[M];
vi g[M], gg[M];
vector < pii > ans;

void f(int v, int p) {
	while (v != p) {
		par[v] = 0;
		v = parr[v];
	}
}
 
void dfs(int v, int p = 0) {
	parr[v] = par[v] = p;
	tin[v] = ++timer;

	for (auto to : g[v])
		if (to != p) {
			if (!tin[to])
				dfs(to, v);
			else if (tin[to] < tin[v]) {
//			    cerr << v << ' ' << to << endl;
				f(v, to);                
			}
		}
}

void dfs1(int v) {
	vi a, b;
	for (auto to : gg[v]) {
		dfs1(to);
		if (dp[to] == to)
			a.pb(to);   	
		else
			b.pb(to);	
	}

	while (sz(b) > 1) {
		int x = b.back();
		b.ppb();

		int y = b.back();
		b.ppb();

		ans.pb({dp[x], dp[y]});		
	}

	if (sz(b) && sz(a) > 1) {
		ans.pb({dp[b[0]], dp[a.back()]});
		a.ppb();
		b.ppb();
	}

	while (sz(b) + sz(a) > 2) {
		int x = a.back();
		a.ppb();

		int y = a.back();
		a.ppb();

		ans.pb({dp[x], dp[y]});
	}

	dp[v] = !sz(a) ? v : dp[a[0]];
	dp[v] = !sz(b) ? dp[v] : dp[b[0]];

	if (!par[v] && sz(b)) //v is a root
		ans.pb({v, dp[v]});
	if (!par[v] && sz(a) == 2)
		ans.pb({a[0], a[1]});
}

void solve() {
	cin >> n >> m;
	if (!n && !m)
		exit(0);


	while (m--) {
		int s;
		cin >> s;
		int prv = 0;
		while (s--) {
			int x;
			cin >> x;
			if (prv) {
				g[prv].pb(x);
				g[x].pb(prv);
			}

			prv = x;
		}
	}

	dfs(1);
	vi roots;
	for (int i = 1; i <= n; ++i)
		if (!par[i])
			roots.pb(i);
		else
			gg[par[i]].pb(i);

	for (auto v : roots)
		dfs1(v);
	
	cout << sz(ans) << endl;
	for (auto x : ans) {
	    assert(x.f != x.s);
		cout << x.f << ' ' << x.s << endl; 
	}

	timer = 0;
	ans.clear();
	for (int i = 1; i <= n; ++i) {
		tin[i] = dp[i] = par[i] = parr[i] = 0;
		g[i].clear();
		gg[i].clear();
	}			
}

main () {
	fastio
	int TT = inf;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}