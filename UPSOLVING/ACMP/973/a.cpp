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
const int N = 2e4, inf = 2e9 + 7, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

bool was[M];
set < pii > q;
vi g[M], gg[M], gr[M], order;
int n, m, A[M*5], B[M*5], C[M*5], d[M][2], dp[M][2];
set < int > has[M];
void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void Dijkstra(int v, int i) {
	for (int j = 1; j <= n; ++j)
		d[j][i] = inf;

	d[v][i] = 0;
	dp[v][i] = 1;
	q.insert(mp(0, v));

	while (sz(q)) {
		int v = q.begin()->s;
		q.erase(q.begin());

		for (auto x : g[v]) {
			int to = (A[x]^B[x]^v), w = C[x];
			if (d[to][i] > d[v][i] + w) {
				q.erase(mp(d[to][i], to));
				d[to][i] = d[v][i] + w;
				dp[to][i] = dp[v][i];
				q.insert(mp(d[to][i], to));
			} else if (d[to][i] == d[v][i] + w) 
				add(dp[to][i], dp[v][i]); 			
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		g[A[i]].pb(i);
		g[B[i]].pb(i);
	}
	

	Dijkstra(1, 0);
	Dijkstra(n, 1);
	vi ans;
	for (int i = 1; i <= m; ++i) {
		if (d[A[i]][0] + C[i] + d[B[i]][1] == d[n][0] && dp[A[i]][0] * 1ll * dp[B[i]][1] % MOD == dp[n][0])
			ans.pb(i);
		else {
			swap(A[i], B[i]);
			if (d[A[i]][0] + C[i] + d[B[i]][1] == d[n][0] && dp[A[i]][0] * 1ll * dp[B[i]][1] % MOD == dp[n][0])
				ans.pb(i);
		}
	}

	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x << ' ';
}


main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}