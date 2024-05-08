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

int n, d[M], cnt[M], sz;
vector < pii > vv;
pii ans[M];
vi g[M];
bool was[M];


void dfs(int v, int p = 0) {
	cnt[v] = 1;
	for (auto to : g[v])
		if (!was[to] && to != p) {
			dfs(to, v);
			cnt[v] += cnt[to];
		}	
}


int Find(int v, int p = 0) {
	for (auto to : g[v])
		if (!was[to] && to != p && cnt[to] > sz - cnt[to])
			return Find(to, v);

	return v;
}


void dfs1(int v, int p = 0) {
	d[v] = d[p] + 1;
	vv.pb(mp(v, d[v]));
	for (auto to : g[v])
		if (!was[to] && to != p)
			dfs1(to, v);
}


void Centroid(int v) {
	dfs(v);
	sz = cnt[v];

	v = Find(v);

	dfs1(v);
	sort(all(vv));
	pii mn = mp(inf, inf);
	for (int i = sz(vv) - 1; i >= 0; --i) {
		ans[vv[i].f] = min(ans[vv[i].f], mp(vv[i].s + mn.f, mn.s));
		mn = min(mn, mp(vv[i].s, vv[i].f));
	}
	vv.clear();
	
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to])
			Centroid(to);
}

 
void solve() {
	fastio
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	for (int i = 1; i <= n; ++i)
		ans[i] = mp(inf, i);

	Centroid(1);

	for (int i = 1; i <= n; ++i)
		cout << ans[i].s << ' ';
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}