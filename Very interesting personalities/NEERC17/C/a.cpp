//by paradox & gege & parasat
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

vector<int> g[M];
bool used[M];

int tin[M], tout[M], fup[M], timer;
int ver[M];
map<ll, bool> p;

ll getH(int v, int to) {
	return 1ll * (v - 1) * N + to - 1;
}

void dfs(int v) {
	tin[v] = fup[v] = ++timer;
	ver[timer] = v;
	used[v] = true;
	for (int to : g[v]) {
		if (!used[to]) {
			p[getH(v, to)] = true;
			dfs(to);
		} else {
			fup[v] = min(fup[v], tin[to]);
		}
	}
	tout[v] = timer;
}
 
void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int v, u;
		scanf("%d %d", &v, &u);
		g[v].pb(u);
	}

	dfs(1);
	for (int v = 1; v <= n; v++) {
		if (ver[fup[v]] != v) {
			p[getH(v, ver[fup[v]])] = true;
		}
	}

	vector<pii> ans;
	for (int v = 1; v <= n; v++){
		for (int to : g[v]) {
			ll h = getH(v, to);
			if (p.count(h)) {
				p.erase(h);
			} else {
				ans.pb({v, to});
			}
		}
		g[v].clear();
		used[v] = false;
	}

//	cerr << "not used: " << sz(ans) << "\n";
//	for (auto it : ans)
//		cerr << "! " << it.fi << ' ' << it.se << "\n";
	assert(sz(ans) >= m - 2 * n);
	for (int i = 0; i < m - 2 * n; i++)
		printf("%d %d\n", ans[i].fi, ans[i].se);
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
    	