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

int n, m, a[M], b[M], d[M], par[M];
bool was[M], res[M];
vector < pii > e;
vi g[M];
 
void dfs(int v, int p = 0) {
	was[v] = 1;
	d[v] = d[p] + 1;
	for (auto i : g[v]) {
		int to = (a[i] ^ b[i] ^ v);
		if (to == p)
			continue;
		
		if (!was[to]) {
			par[to] = i;
			dfs(to, v);
		} else if (d[v] > d[to]){
			res[i] = 1;
			e.pb({par[v], i});
		}
	}
}


bool is_cycle() {
	assert(sz(e) < 4);
	if (sz(e) != 3)
		return 0;

	set < int > q;			
	for (int i = 1; i <= m; ++i)
		if (res[i]) {
			q.insert(a[i]);
			q.insert(b[i]);
		}

	if (sz(q) != 3)
		return 0;
	return 1;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i];
		g[a[i]].pb(i);
		g[b[i]].pb(i);
	}

	dfs(1);
	if (is_cycle()) {
		res[e[0].f] = 1;
		res[e[0].s] = 0;
	}

	for (int i = 1; i <= m; ++i)
		cout << res[i];
	cout << endl;
	e.clear();
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		was[i] = 0;
	}

	for (int i = 1; i <= m; ++i)
		res[i] = 0;
}

main () {
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}