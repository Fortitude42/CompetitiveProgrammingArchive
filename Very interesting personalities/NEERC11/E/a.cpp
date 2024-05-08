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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

char gen[M];
bool dead[M];
vi g[M];

int alive_count[M], value[M];
int color[M];

void add_edge(int v, int u) {
	g[v].pb(u);
	g[u].pb(v);
}

void dfs(int v, int colors) {
//	cerr << "color of " << v << " is " << colors << "\n";
	color[v] = colors;
	alive_count[colors] += !dead[v];
	for (int to : g[v])
		if (!color[to])
			dfs(to, colors);
}
 
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("\n%c", &gen[i]);
	
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int v = 0, u = 0;
		char c;

		scanf("%d", &v);
		if (v < 0) {
			dead[-v] = true;
		} else {
			scanf("%d %c", &u, &c);
			gen[++n] = c;
			if (gen[v] == 'F')
				add_edge(v, n);
			else
				add_edge(u, n);
		}
	}
	
//	cerr << "before dfs: ok\n";
	int colors = 0;
	for (int i = 1; i <= n; i++)
		if (!color[i])
			dfs(i, ++colors);

//	cerr << "after dfs: ok\n";

	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		int v, val;
		scanf("%d %d", &v, &val);
		value[color[v]] = val;
	}

	bool unknown = false;
	vi values;
	int count = 0;

	for (int c = 1; c <= colors; c++) {
		if (alive_count[c]) {
//			cerr << "alive: " << c << " | " << value[c] << "\n";
			count++;
			if (value[c])
				values.pb(value[c]);
			else
				unknown = true;
		}
	}

	sort(all(values));
	if (sz(values) && values[0] != values.back()) {
		printf("NO\n");
	} else if (count > 1 && unknown) {
		printf("POSSIBLY\n");
	} else {
		printf("YES\n");
	}
}

main () {
	file("eve")
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

