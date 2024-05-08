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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
set < pair < int, pair < int, pii > > > q;
set < pair < pii, pii > > qq;
int n, v, u, d[N][20][2], m;
vi g[N], gr[N];
pii dd[N][2];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n % 2 == 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n /= 2;		
	}

	return res;
}



main () {      
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &v, &u);    
		g[v].pb(u);
		gr[u].pb(v);
	}

	
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 20; ++j)
			for (int x = 0; x < 2; ++x)
				d[i][j][x] = inf;

	d[1][0][0] = 0;
	q.insert(mp(0, mp(1, mp(0, 0))));

	while (sz(q)) {
		int v = q.begin()->s.f, j = q.begin()->s.s.f, tp = q.begin()->s.s.s;
		q.erase(q.begin());

		for (auto to : g[v]) 
			if (j + tp < 20 && d[to][j + tp][0] > d[v][j][tp] + 1 + (1 << j)*tp) {
				q.erase(mp(d[to][j + tp][0], mp(to, mp(j + tp, 0))));
				d[to][j + tp][0] = d[v][j][tp] + 1 + (1 << j)*tp;
				q.insert(mp(d[to][j + tp][0], mp(to, mp(j + tp, 0))));
			}
		
		for (auto to : gr[v])
			if (j + (tp ^ 1) < 20 && d[to][j + (tp ^ 1)][1] > d[v][j][tp] + 1 + (1 << j)*(tp ^ 1)) {
				q.erase(mp(d[to][j + (tp ^ 1)][1], mp(to, mp(j + (tp ^ 1), 1))));
				d[to][j + (tp ^ 1)][1] = d[v][j][tp] + 1 + (1 << j)*(tp ^ 1);
				q.insert(mp(d[to][j + (tp ^ 1)][1], mp(to, mp(j + (tp ^ 1), 1))));
			}			
	}

	cerr << d[2][1][1] << endl;


	int ans = inf;
	for (int j = 0; j < 20; ++j)
		for (int x = 0; x < 2; ++x)	
			ans = min(ans, d[n][j][x]);

	if (ans != inf) {
		cout << ans << endl;
		return 0;
	}


	
	
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			dd[i][j] = {inf, inf};

	dd[1][0] = {0, 0};
	qq.insert(mp(dd[1][0], mp(1, 0)));


	while (sz(qq)) {
		int v = qq.begin()->s.f, tp = qq.begin()->s.s;
		qq.erase(qq.begin());

		for (auto to : g[v]) {
			if (dd[to][0] > mp(dd[v][tp].f + tp, dd[v][tp].s + 1)) {
				qq.erase(mp(dd[to][0], mp(to, 0)));
				dd[to][0] = mp(dd[v][tp].f + tp, dd[v][tp].s + 1);
				qq.insert(mp(dd[to][0], mp(to, 0)));
			}                 

		}

		for (auto to : gr[v])
			if (dd[to][1] > mp(dd[v][tp].f + (tp ^ 1), dd[v][tp].s + 1)) {
				qq.erase(mp(dd[to][1], mp(to, 1)));
				dd[to][1] = mp(dd[v][tp].f + (tp ^ 1), dd[v][tp].s + 1);
				qq.insert(mp(dd[to][1], mp(to, 1)));
			}
	}
	
	pii res = min(dd[n][0], dd[n][1]);
	
	
	ans = binpow(2, res.f) - 1 + res.s;

	ans = (ans + mod) % mod;
	ans = (ans + mod) % mod;
	cout << ans << endl;
	
}