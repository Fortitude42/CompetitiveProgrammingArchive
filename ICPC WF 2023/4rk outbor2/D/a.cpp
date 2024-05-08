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
const int N = 1000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, d[M*M*2];
int a[M][M];
bool used[M*M*2];
vi g[M*M*2], order;

bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

int get(int x, int y, int d) {
	if (d == 1)
		x--;
	if (d == 3)
		y--;
	
	assert(in(x, y));
	int cur = (x - 1)*m + y;
	if (d > 1)
		cur += n*m;
	return cur;
}

void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v])
		if (!used[to])
			dfs(to);
	order.pb(v);
}
 
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			cin >> a[i][j];
		

	int ans = 1;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			vector < pii > ds[2];
			for (int d = 0; d < 4; ++d) {
				int pi = i + dx[d], pj = j + dy[d];
				if (!in(pi, pj))
					continue;
				if (a[pi][pj] < a[i][j]) {
					ds[0].pb({get(i, j, d), a[i][j] - a[pi][pj]});
					ans = 2;
				}
				if (a[pi][pj] > a[i][j]) {
					ds[1].pb({get(i, j, d), a[pi][pj] - a[i][j]});
					ans = 2;
				}
			}

			for (auto v0 : ds[0]) 				
				for (auto v1 : ds[1]) 
					if (v0.s < v1.s) {
						g[v0.f].pb(v1.f);
//						cerr << v0.f << ' ' << v1.f << endl;
					}
				
		}
		
	int s = 2*n*m;
	for (int i = 1; i <= s; ++i)
		if (!used[i])
			dfs(i);

//	reverse(all(order));
	for (auto i : order) {
		for (auto j : g[i]) {
			d[i] = max(d[i], d[j] + 1);
			ans = max(ans, d[i] + 2);
		}
	}				

	cout << ans << "\n";
}

main () {
  int TT;
  TT = 1;
  	fastio
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}