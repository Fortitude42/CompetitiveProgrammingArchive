#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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
typedef double db;
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, k, mt[M], par[M];
bool used[M];
vi g[M];

bool dfs(int v) {
	if (used[v])
		return 0;

	used[v] = 1;
	for (auto to : g[v])
		if (mt[to] == -1) {
			mt[to] = v;
			par[v] = to;
			return 1;
		}

	for (auto to : g[v])
		if (dfs(mt[to])) {
			mt[to] = v;
			par[v] = to;
			return 1;          
		}

	return 0;
}

void solve() {
	cin >> n >> m >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
	}

	memset(mt, -1, sizeof(mt));
	memset(par, -1, sizeof(par));

	bool run;
	do {
		run = 0;
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= n; ++i)
			if (par[i] == -1 && dfs(i))
				run = 1;
	} while (run);

	int ans = n + m;
	for (int i = 1; i <= n; ++i)
		if (par[i] != -1)
			--ans;

	cout << ans << endl;
}   




main () {
	fastio
  	int TT;
  	TT = 1;
//	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}
