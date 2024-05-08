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
const pii base = mp(1e6 + 3, 1e6 + 33), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 500, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, a[M][5], p[M*5], h[M][32], pos[M][32];
int t[5][M], timer, d[M][32], ans[M][M];
vector < pii > g[M*32], gg[M][32];
queue < pii > q;
vi vals;
 
void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; ++i)
		for (int mask = 0; mask < (1 << m); ++mask) {
			
			for (int j = 0; j < m; ++j)
				if (mask & (1 << j))
					add(h[i][mask], p[j*n + a[i][j]]);
			
			vals.pb(h[i][mask]);
		}
		
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i)
		for (int mask = 0; mask < (1 << m); ++mask) {
			h[i][mask] = lower_bound(all(vals), h[i][mask]) - vals.begin(); 
			pos[i][mask] = sz(g[h[i][mask]]);
			g[h[i][mask]].pb({i, mask});
		}

	for (int i = 1; i <= n; ++i) 
		for (int mask = 0; mask < (1 << m); ++mask){
		    //~adding a new condition

			int x = pos[i][mask];
			++timer;


			while (1) {
				int j = g[h[i][mask]][x].f, mask1 = g[h[i][mask]][x].s;

				for (int y = 0; y < m; ++y) {
					if ((mask1 & (1 << y)) || t[y][a[j][y]] == timer)
						continue;

					t[y][a[j][y]] = timer;
					gg[i][mask].pb({j, mask1 | (1 << y)});
				}

				x++;
				if (x == sz(g[h[i][mask]]))
					x = 0;

				if (g[h[i][mask]][x].f == i)
					break;
			}

			//~deleting a condition
			for (int x = 0; x < m; ++x)
				if (mask & (1 << x))
					gg[i][mask].pb({i, mask ^ (1 << x)});
			

			//~left
			x = pos[i][mask] - 1;
			if (x < 0)
				x += sz(g[h[i][mask]]);
			gg[i][mask].pb(g[h[i][mask]][x]);

			//~right
			x = pos[i][mask] + 1;
			if (x == sz(g[h[i][mask]]))
				x = 0;
			gg[i][mask].pb(g[h[i][mask]][x]);
		}

	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= n; ++i) {
		while (sz(q))
			q.pop();
		memset(d, -1, sizeof(d));


		d[i][0] = 0;
		q.push({i, 0});
		int found = 0;

		while (sz(q)) {
			int j = q.front().f, mask = q.front().s;
			q.pop();

			if (ans[i][j] == -1) {
				ans[i][j] = d[j][mask];
				++found;
				if (found == n)
					break;
			}

			for (auto x : gg[j][mask])
				if (d[x.f][x.s] == -1) {
					d[x.f][x.s] = d[j][mask] + 1;
					q.push(x);
				}
		}
	}

	for (int i = 1; i <= n; ++i, printf("\n"))
		for (int j = 1; j <= n; ++j)
			printf("%d ", ans[i][j]);
}

void precalc() {
	p[0] = 1;
	for (int i = 1; i < M*5; ++i)
		p[i] = p[i - 1] * 1ll * base.f % MOD;
}

main () {
	precalc();

	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
