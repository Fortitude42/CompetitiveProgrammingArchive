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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int w, h, n;
double x[M], y[M];
vi g[M];
int c[M];

double getDist(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

void adde(int v, int u) {
	g[v].pb(u);
	g[u].pb(v);
}

void dfs(int v, int color) {
	c[v] = color;
	for (int to : g[v])
		if (!c[to])
			dfs(to, color);
}

bool check(double dist) {
	for (int i = 1; i <= n + 4; i++) {
		c[i] = 0;
		g[i].clear();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (getDist(i, j) < dist * 2.0) {
				adde(i, j);
			}
		}

		if (h - y[i] < dist)
			adde(n + 1, i);
		if (w - x[i] < dist)
			adde(n + 2, i);
		if (y[i] < dist)
			adde(n + 3, i);
		if (x[i] < dist)
			adde(n + 4, i);
	}

	int timer = 0;
	for (int i = 1; i <= n + 4; i++)
		if (!c[i])
			dfs(i, ++timer);
	
	return c[n + 1] != c[n + 2] && c[n + 1] != c[n + 3] && c[n + 4] != c[n + 2] && c[n + 4] != c[n + 3];
}

void solve() {
	scanf("%d %d", &w, &h);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", &x[i], &y[i]);
	}

	double l = 0.0, r = 1e9;
	for (int it = 0; it < 80; it++) {
		double mid = (l + r) / 2.0;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}

	printf("%.6lf", l);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
