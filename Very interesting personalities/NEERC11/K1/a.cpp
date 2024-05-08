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

vi g[M];
pii pair_in[M];
int lft[M];

int p[M];

void dfs(int v, int par = 0) {
	vector<pii> with_pairs;
	vector<int> alone;
	bool isLeaf = true;

	for (int to : g[v]) {
		if (to == par)
			continue;

		isLeaf = false;

		dfs(to, v);
		if (pair_in[to].fi)
			with_pairs.pb(pair_in[to]);
		if (lft[to])
			alone.pb(lft[to]);
	}

	for (int i = 0; i < sz(with_pairs); i++) {
		int a = with_pairs[i].se;
		int b = with_pairs[(i + 1) % sz(with_pairs)].fi;
		p[a] = b;
		p[b] = a;

		pair_in[v] = {a, b};
	}

	for (int i = 1; i < sz(alone); i += 2) {
		int a = alone[i];
		int b = alone[i - 1];
		p[a] = b;
		p[b] = a;

		pair_in[v] = {a, b};
	}

	if (sz(alone) & 1)
		lft[v] = alone.back();
	
	if (isLeaf)
		lft[v] = v;
}
 
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d %d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);

	if (lft[1]) {
		p[1] = lft[1];
		p[lft[1]] = 1;
	} else if (sz(g[1]) == 1) {
		p[1] = 2;
		p[2] = 1;
	}

	vector<pii> ans;
	for (int v = 1; v <= n; v++)
		if (p[v] && p[v] > v)
			ans.pb({v, p[v]});
	
	printf("%d\n", sz(ans));
	for (auto &cur : ans) {
		printf("%d %d\n", cur.fi, cur.se);
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
