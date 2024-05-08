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
const int N = 300, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, ans[M*M];
int a[M*M], b[M*M], c[M*M], d[M], p[M], col[M];
bool used[M];
vi g[M], gg[M];


void dfs(int v, int cc) {
	col[v] = cc;
	for (auto id : gg[v]) {
		int to = a[id]^b[id]^v;
		dfs(to, cc);
	}


	for (auto id : g[v]) {
		int to = a[id]^b[id]^v;
		if (col[to] == col[v] || col[to] == -1)
			continue;
		ans[col[v]] = min(ans[col[v]], d[v] + d[to] + c[id] - c[col[v]]);
		ans[col[to]] = min(ans[col[to]], d[v] + d[to] + c[id] - c[col[to]]);
	}
}
 
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		g[a[i]].pb(i);
		g[b[i]].pb(i);
	}

	for (int i = 1; i <= m; ++i)
		ans[i] = inf;


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[j] = inf;
			used[j] = 0;
			col[j] = p[j] = -1;
			gg[j].clear();
		}

		d[i] = 0;
		while (1) {
			int j = - 1;
			for (int x = 1; x <= n; ++x)
				if (!used[x] && (j == -1 || d[x] < d[j]))
					j = x;

			if (j == -1 || d[j] == inf)
				break;

			used[j] = 1;
			for (auto id : g[j]) {
				int to = (a[id]^b[id]^j);
//				cerr << j << ' ' << to << endl;
				if (d[to] > d[j] + c[id]) {
					d[to] = d[j] + c[id];
					p[to] = id;
				}
			}
		}

//		for (int j = 1; j <= n; ++j)
//			cerr << d[j] << ' ';
//		cerr << endl;

		for (int j = 1; j <= n; ++j)
			if (p[j] != -1) {
				int par = a[p[j]]^b[p[j]]^j;
				gg[par].pb(p[j]);
//				cerr << j << ' ' << par << endl;
			}

		for (auto id : g[i]) {
			int to = a[id]^b[id]^i;
			if (p[to] == id) {//edge id is used in our tree
				dfs(to, id);
			} else {
				ans[id] = min(ans[id], d[to]);
			}
		}
//		break;
	}


	for (int i = 1; i <= m; ++i)  {
		if (ans[i] == inf)
			ans[i] = -1;
		cout << ans[i] << "\n";
	}		
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}