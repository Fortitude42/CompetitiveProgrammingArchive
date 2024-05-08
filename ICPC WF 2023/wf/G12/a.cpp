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
const int N = 400, inf = 2e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int maxn = 5e4 + 11;


int x[M], y[M], z[M], k[M], Z;
int n, m, a[maxn], b[maxn];
int c, col[M], cnt[M];
double d[M][2], dst[M][M];
bool used[M][2], good[M][M];
vi g[M];


double dist(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]));
}

void dfs(int v) {
	col[v] = c;
	cnt[c] += k[v];
	for (auto to : g[v])
		if (!col[to] && good[v][to])
			dfs(to);
}


void solve(int tt) {
	cin >> m;

	vi vals;

	for (int i = 1; i <= n; ++i)  {
		cin >> x[i] >> y[i] >> z[i] >> k[i];
		vals.pb(z[i]);
	}

	vals.resize(unique(all(vals)) - vals.begin());
	reverse(all(vals));

	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i];
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dst[i][j] = dist(i, j);

	double ans = INF;
	for (int ind = 0; ind < sz(vals); ++ind) {
		Z = vals[ind];
		if (Z < z[1] || Z < z[n])
			continue;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				good[i][j] = z[j] <= max(Z, z[i]);


		for (int i = 1; i <= n; ++i) {
			col[i] = 0;
			cnt[i] = 0;
		}

		c = 1;
		dfs(1);
		for (int i = 1; i <= n; ++i)
			if (!col[i] && z[i] <= Z) {
				++c;
				dfs(i);				
			}

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 2; ++j) {
				d[i][j] = INF;
				used[i][j] = 0;
			}

			if (col[i] == 1)
				d[i][0] = d[i][1] = cnt[1] / 2.0;			
		}

		while (1) {
			int i = -1, tp;
			for (int j = 1; j <= n; ++j)
				for (int _tp = 0; _tp < 2; ++_tp)
					if (!used[j][_tp] && (i == -1 || d[i][tp] > d[j][_tp])) {
						i = j;
						tp = _tp;
					}


			if (i == -1 || d[i][tp] == INF)
				break;

			used[i][tp] = 1;//0 came from other comp to this vert
							//1 came from its own comp to this vert

			if (!tp) {
				for (int j = 1; j <= n; ++j)
					if (i != j && col[i] == col[j]) 
						d[j][1] = min(d[j][1], d[i][0]);					
			}

			int need = 2 - tp;
			if (need <= k[i]) {
				for (int j = 1; j <= n; ++j)
					if (good[i][j] && k[j] > 0 && col[i] != col[j])
						d[j][0] = min(d[j][0], d[i][tp] + dist(i, j) + cnt[col[j]] / 2.0 - 1.0);
			}				
		}

		ans = min(ans, d[n][0]);
		ans = min(ans, d[n][1]);
	}

	cout << "Case " << tt << ": ";

	if (ans == INF)
		cout << "impossible\n";
	else
		cout << ans << "\n";

	for (int i = 1; i <= n; ++i)
		g[i].clear();
	


}

main () {
	cout << setprecision(4) << fixed;
	fastio
	int tt = 0;
	while (cin >> n)
		solve(++tt);
}