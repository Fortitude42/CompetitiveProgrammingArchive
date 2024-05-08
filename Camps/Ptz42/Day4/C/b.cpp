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

int n, m, k, t[M], d[M], res[M], rev;
vi g[M], gg[M], gr[M];
bool was[M];
set < pii > q;
 
void Dijkstra(int v) {
	for (int j = 1; j <= n; ++j)
		d[j] = inf*2;
	d[v] = t[v];
	q.insert(mp(t[v], v));

	while (sz(q)) {
		int v = q.begin()->s;
		q.erase(q.begin());

		for (auto to : g[v])
			if (d[to] == inf*2) {
				d[to] = d[v] + t[to];
				q.insert(mp(d[to], to));
			}
	}
}   


void dfs(int v) {
	was[v] = 1;
	for (auto to : gr[v])
		if (!was[to])
			dfs(to);		
}

void solve() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		cin >> t[i];

	for (int i = 1; i <= m; ++i) {
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	Dijkstra(1);

	for (int i = 1; i <= n; ++i)
		for (auto j : g[i])
			if (d[j] == d[i] + t[j]) {
				gr[j].pb(i); 
			}

	dfs(n);
	for (int i = 1; i <= n; ++i)
		if (was[i])
			for (auto j : gr[i])
				if (was[j])
					gg[j].pb(i);
			

	if (k) {
		if (sz(gg[1]) == 1 && gg[1][0] == n) {
			if (k >= 2) {
				res[1] = 1;
				res[n] = 1;
				k -= 2;
				for (int i = 1; i <= n; ++i)
					if (!res[i] && k > 0) {
						res[i] = 1;
						k--;
					}
			} else if (n - k >= 2) {
				for (int i = 2; i < n; ++i)
					if (k > 0) {
						res[i] = 1;
						k--;
					}
			} else {
				cout << "impossible";
				return;
			}
		} else {
			res[1] = 1;
			k--;
			for (auto i : gg[1]) {
				if (!k)
					break;
				k--;
				res[i] = 1;
			}


			for (int i = 1; i <= n; ++i)
				if (!res[i] && k > 0) {
					res[i] = 1;
					k--;
				}
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << (res[i] ? 'N' : 'S');	
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
