#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 150;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
 
int n, d, u, q, h[N], x, y, v, was[N], timer, pos[N];
vector < pair < int, vi > > gg[N];
vpii g[N];
vi tmp;

void upd (int x) {
	if (was[x] != timer) {
		was[x] = timer;
		tmp.pb(x);
		pos[x] = sz(tmp) - 1;
	} else {
		was[x] = 0;
		pos[tmp.back()] = pos[x];
		swap(tmp.back(), tmp[pos[x]]);
		tmp.ppb();
	}
}

 
vi get (int x, int v) {
	tmp.clear();
	++timer;
			 
	for (int j = 0; j < sz(gg[x]); ++j)
		if (j == sz(gg[x]) - 1 || gg[x][j + 1].f > v) {
			if (j) {
				for (auto y : gg[x][j - 1].s)
					upd(y);
			}
 
			int jj = j*block;
			while (jj < sz(g[x]) && g[x][jj].f <= v) 
				upd(g[x][jj++].s);		
			break;
		}
 
	vi vv;
	for (auto x : tmp)
		vv.pb(h[x]);
 
	return vv;
}
 
 
main () {
	fastio
	scanf("%d%d%d%d", &n, &d, &u, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", &h[i]);
 
	for (int i = 1; i <= u; ++i) {
		scanf("%d%d", &x, &y);
		g[x].pb({i, y});
		g[y].pb({i, x});
	}
 
	for (int i = 0; i < n; ++i) {
		tmp.clear();        
		++timer;

		gg[i].resize((sz(g[i]) + block - 1) / block);
		
		for (int j = 0; j < sz(g[i]); ++j) {
			upd(g[i][j].s);
 
			if (j % block == 0)
				gg[i][j / block].f = g[i][j].f;
			if (j % block == block - 1 || j == sz(g[i]) - 1) {
				for (auto x : tmp)
					gg[i][j / block].s.pb(x);
			}
		}
	}
 
 
 
	while (q--) {
		scanf("%d%d%d", &x, &y, &v);
		if (!sz(gg[x]) || !sz(gg[y]) || gg[x][0].f > v || gg[y][0].f > v) {
			printf("%d\n", inf);
			fflush(stdout);
			continue;
		}
 
		vi X = get(x, v);
		vi Y = get(y, v);
		sort(all(Y));
 
		int ans = inf;
 
		for (auto x : X) {
			int i = lower_bound(all(Y), x) - Y.begin();
			if (i < sz(Y))
				ans = min(ans, abs(x - Y[i]));
			if (i)
				ans = min(ans, abs(x - Y[i - 1]));
		}
 
		printf("%d\n", ans);
		fflush(stdout);
	}
}