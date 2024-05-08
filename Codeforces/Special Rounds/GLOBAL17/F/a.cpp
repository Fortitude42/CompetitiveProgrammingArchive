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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17, maxn = 1e6 + 11;
const ll INF = 1e18;

int n, m, mm, lst[M][2], par[maxn], from[maxn], to[maxn], ans[M];
int tin[M], tout[M], timer, used[maxn], deg[M];
vi g[maxn], gg[M];
 
void addEdge(int a, int b, int c, int ind) {
//	cerr << a << ' ' << b << ' ' << c << ' ' << ind << endl;
	from[ind] = a;
	to[ind] = b;

	for (int tt = 1; tt <= 2; ++tt) {
		swap(a, b);
		if (lst[a][c] > 0) {
			int e = lst[a][c];
	
			int d = (from[e] ^ to[e] ^ a);
			lst[a][c] = lst[d][c] = 0;

			if (b == d) {
				if (to[e] != a && e <= mm)
					++ans[e];
				if (to[ind] != b && ind <= mm)
					++ans[ind];
				to[e] = from[ind] = a;
				from[e] = to[ind] = b;
				used[e] = used[ind] = 2;
				return;
			}

			used[e] = used[ind] = 1;

			g[++m].pb(e);
			g[m].pb(ind);
		
			addEdge(b, d, c, m);
			return;
		}
	}


	lst[a][c] = ind;
	lst[b][c] = ind;
}

void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	for (auto x : gg[v]) {
		if (x == p)
			continue;

		int u = (from[x] ^ to[x] ^ v);
		
		if (!tin[u] || tin[v] < tin[u]) {
			if ((!tin[u] && from[x] == v) || (tin[u] && from[x] != v)) {
				swap(from[x], to[x]);
				if (x <= mm)
					++ans[x];
			}
		}

		if (!tin[u])
			dfs(u, x);

	}
}

void dfs1(int v) {
	for (auto u : g[v]) {
		if (from[v] != from[u] && to[v] != to[u]) {
			if (u <= mm)
				++ans[u]; 			
			swap(to[u], from[u]);
		}
		dfs1(u);
	}
}

void solve() {
	cin >> n >> m;
	mm = m;
	for (int i = 1; i <= mm; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		deg[a] += c;
		deg[b] += c;
		c--;
		addEdge(a, b, c, i);
	}

	for (int i = 1; i <= m; ++i) 
		if (!used[i]) {
			gg[from[i]].pb(i);
			gg[to[i]].pb(i);
//			cerr << from[i] << ' ' << to[i] << endl;
		}

	for (int i = 1; i <= n; ++i)
		if (sz(gg[i]) == 1 && !tin[i])
			dfs(i); 
		

	for (int i = 1; i <= n; ++i)
		if (!tin[i])
			dfs(i); 		

	for (int i = 1; i <= m; ++i)
		if (used[i] != 1)
			dfs1(i); 
		

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (deg[i] & 1)
			++cnt;

	cout << cnt << endl;
	for (int i = 1; i <= mm; ++i)
		cout << ans[i] + 1;
}

main () {
	
  	int TT;
  	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}