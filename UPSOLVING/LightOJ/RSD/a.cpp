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
const int N = 200*200, inf = 1e9, MOD = 1e9 + 7, maxn = 200 + 11;
const int M = N + 17;
const ll INF = 1e18;

int n, m, a[M], b[M], c[M], d[maxn], p[maxn], par[maxn];
int ans[M], id[maxn][maxn], D[maxn];
bool used[maxn];
vi gg[maxn], g[maxn];

void dfs(int v) {
	for (auto to : gg[v]){
		dfs(to);
		D[v] = min(D[v], D[to]);
	}


	if (p[v] > 0)
		ans[id[v][p[v]]] = min(ans[id[v][p[v]]], D[v]);
} 

void Dijkstra(int v) {
	for (int i = 1; i <= n; ++i) {
		p[i] = par[i] = 0;
		used[i] = 0;
		d[i] = D[i] = inf;
		gg[i].clear();
	}
	
	d[v] = 0;
	p[v] = -1;
	par[v] = -1;

	while (1) {
		int j = -1;
		for (int i = 1; i <= n; ++i)
			if (d[i] < inf && !used[i] && (j == -1 || d[i] < d[j]))
				j = i;

		if (j == -1)
			break;

		used[j] = 1;
		for (auto x : g[j]) {
			int to = (a[x] ^ b[x] ^ j);
			if (d[to] > d[j] + c[x]) {
				d[to] = d[j] + c[x];
				p[to] = j;
				par[to] = p[to] == v ? to : par[p[to]];
			}
		}
	}



	for (int i = 1; i <= n; ++i)
		if (p[i] > 0)
			gg[p[i]].pb(i); 		
	
	for (int i = 1; i <= n; ++i)
		for (auto x : g[i]) {
			int j = (i^a[x]^b[x]);
			if (i != p[j] && j != p[i] && par[i] && par[j] && par[i] != par[j]) {
				ans[x] = min(ans[x], c[x] + d[i] + d[j]);
				D[i] = min(D[i], c[x] + d[i] + d[j]);
				D[j] = min(D[j], c[x] + d[i] + d[j]);
			}
		}

	dfs(v);
}

void solve(int tt) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		a[i]++, b[i]++;
		g[a[i]].pb(i);
		g[b[i]].pb(i);
		ans[i] = inf;
		id[a[i]][b[i]] = id[b[i]][a[i]] = i;
	}
	
	for (int i = 1; i <= n; ++i)
		Dijkstra(i);

	printf("Case %d:\n", tt);
	for (int i = 1; i <= m; ++i)
		if (ans[i] == inf)
			printf("impossible\n");
		else
			printf("%d\n", ans[i] - c[i] + 1);

	for (int i = 1; i <= n; ++i)
		g[i].clear();
}

main () {
  int TT;
  TT = 1;
  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve(tt);
  }
}