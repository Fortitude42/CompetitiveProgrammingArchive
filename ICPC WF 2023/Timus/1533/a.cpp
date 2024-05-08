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
const int N = 200, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


vi g[M], gg[M];
int n, mt[M], p[M]; 
bool used[M], vc[M];

void dfs(int v, int p) {
	if (v != p)	
		g[p].pb(v + n);

	used[v] = 1;
	for (auto to : gg[v])
		if (!used[to])
			dfs(to, p);
}


bool kuhn(int v) {
	if (used[v])
		return 0;

	used[v] = 1;
	for (auto to : g[v])
		if (mt[to] == -1) {
			mt[to] = v;
			p[v] = to;
			return 1;
		}

	for (auto to : g[v])
		if (kuhn(mt[to])) {
			mt[to] = v;
			p[v] = to;
			return 1;
		}

	return 0;
}


void dfs1(int v) {
	used[v] = 1;
	for (auto to : gg[v])
		if (!used[to])
			dfs1(to);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int x;
			cin >> x;
			if (x == 1)
				gg[i].pb(j);
		}

	// ~build new graph
	for (int i = 1; i <= n; ++i) {
		memset(used, 0, sizeof used);
		dfs(i, i);
	}
	
	
	// ~finding max matching
	memset(mt, -1, sizeof mt);
	memset(p, -1, sizeof p);
	bool run;
	do {
		run = 0;
		memset(used, 0, sizeof used);
		for (int i = 1; i <= n; ++i)
			if (p[i] == -1 && kuhn(i))
				run = 1;
	} while (run);


	// ~building min vertex cover
	for (int i = 1; i <= n; ++i)
		gg[i].clear();
	for (int v = 1; v <= n; ++v) 
		for (auto to : g[v])
			if (mt[to] != v) 
				gg[v].pb(to);
			else
				gg[to].pb(v);
	
		
	memset(used, 0, sizeof used);
	for (int i = 1; i <= n; ++i)
		if (p[i] == -1)
			dfs1(i);
	
	for (int i = 1; i <= n + n; ++i)
		if ((!used[i] && i <= n) || (used[i] && i > n))
			vc[i] = 1;

	// ~all vertices that are not in min vertex cover are in max independent set
	
	vi ans;
	for (int i = 1; i <= n; ++i)
		if (!vc[i] && !vc[i + n]) {
			ans.pb(i);
		}
	cout << sz(ans) << endl;
	for (int i : ans)
		cout << i << ' ';
}

main () {
  	int TT;
  	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}