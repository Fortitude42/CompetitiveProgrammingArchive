#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vector < pair < pii, int > > ans;
int t, n, a[N], b[N], c[N];
vpii g[N];
vi gg[2];


void dfs(int v, int p = 0) {
	c[v] = c[p] ^ 1;
	gg[c[v]].pb(v);
	for (auto to : g[v])
		if (to.f != p)
			dfs(to.f, v);
}

void clear() {
	for (int i = 1; i <= n; ++i) {
		g[i].clear();              
		b[i] = 0;
	}

	gg[0].clear();
	gg[1].clear();

	ans.clear();
}

void answer(int x, int y, int w) {
	ans.pb({{x, y}, w});
//	cerr << x << ' ' << y << ' ' << w << endl;
	a[x] ^= w;
	a[y] ^= w;
	b[x] += w;
	b[y] += c[x] == c[y] ? -w : w;
}

main () {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++i) 
			scanf("%lld", &a[i]);        

		if (n == 1) {
			clear();
			printf(!a[1] ? "YES\n0\n" : "NO\n");
			continue;
		}

		for (int i = 1; i < n; ++i) {
			int v, u, w;
			scanf("%lld%lld%lld", &v, &u, &w);
			g[v].pb({u, w});
			g[u].pb({v, w});
		}


		dfs(1);	
		for (int i = 1; i <= n; ++i) 
			for (auto x : g[i])
				b[i] += x.s;


		bool ok = 1;
		for (int i = 1; i <= n; ++i)
			if ((a[i] & 1) != (b[i] & 1)) 
				ok = 0;
		

		if (!ok) {
			printf("NO\n");
			clear();
			continue;
		}

		for (int j = 0; j < 2; ++j) {
			for (int x = 1; x < sz(gg[j]); ++x) {
				int y = gg[j][x];
				if (b[y] > a[y]) {
					int w = (b[y] - a[y]) / 2;
					answer(gg[j][0], y, w);
					answer(gg[j][0], y, w);
				} else {
					int w = (a[y] - b[y]) / 2;
					answer(y, gg[j][0], w);
					answer(y, gg[j][0], w);
				}

				answer(gg[j][0], y, b[y]);
			}
		}
		
		int i0 = gg[0][0];
		int i1 = gg[1][0];

		if (a[i0] != a[i1] || b[i1] != b[i0] || a[i0] > -b[i0]) {
			clear();
			printf("NO\n");
			continue;
		}

		int w = -(a[i0] + b[i1]) / 2;
		answer(i0, i1, w);
		answer(i0, i1, w);
		answer(i0, i1, a[i0]);
		printf("YES\n%lld\n", sz(ans));
		for (auto x : ans)
			printf("%lld %lld %lld\n", x.f.f, x.f.s, x.s);

		clear();
	}
}