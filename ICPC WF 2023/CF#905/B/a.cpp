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

int n, t, k;
vector < pii > g[M];
bool used[M];
vector < pii > gg[M];


void add(int v) {
	if (used[v])
		return;

	used[v] = 1;
	for (auto e : g[v]) {
		int u = e.f;
		int i = e.s;
		gg[i].pb({v, u});
	}
}

void clear() {
	for (int i = 1; i <= n; ++i)
		g[i].clear();


	for (int i = 1; i <= t; ++i)
		gg[i].clear();
}
 
void solve() {
	cin >> n >> t;
	for (int i = 1; i <= t; ++i) {
		int m;
		cin >> m;
		while (m--) {
			int v, u;
			cin >> v >> u;
			g[v].pb({u, i});
			g[u].pb({v, i});
		}
	}

	add(1);
	cin >> k;
	int ans = 0;
	while (k--) {
		int i;
		cin >> i;
		vector < pii > tmp = gg[i];
		gg[i].clear();

		while (sz(tmp)) {
			int v = tmp.back().f, u = tmp.back().s;
			add(v);
			add(u);
			tmp.ppb();
		}

		++ans;
		if (used[n]) {
			cout << ans << "\n";
			clear();
			return;
		}
	}

	clear();
	cout << -1 << "\n";
}

main () {
  int TT;
  TT = 1;
	fastio
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}              