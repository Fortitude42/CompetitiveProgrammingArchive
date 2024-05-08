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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
int n, m, a[M], cnt[6];
pii h[M], p[M];
vi g[M];


void add(int &x, int y, int m) {
	x += y;
	if (x >= m)
		x -= m;
	if (x < 0)
		x += m;
}




void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);        
		g[i].clear();
		h[i] = {0, 0};
	}


	while (m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);

		add(h[v].f, p[u].f, mod.f);
		add(h[v].s, p[u].s, mod.s);

		add(h[u].f, p[v].f, mod.f);
		add(h[u].s, p[v].s, mod.s);
	}

	for (int v = 1; v <= n; ++v) {
		memset(cnt, 0, sizeof(cnt));
		vi vals;

		for (auto u : g[v]) {
			if (cnt[a[u]] < 2) {
				++cnt[a[u]];
				vals.pb(a[u]);
			}
			if ((a[v] + a[u]) % 4 == 0) {
				puts("YES");
				return;
			}
		}


		for (int i = 0; i < sz(vals); ++i)
			for (int j = i + 1; j < sz(vals); ++j)
				if ((a[v] + vals[i] + vals[j]) % 4 == 0) {
					puts("YES");
					return;
				}
	}

	for (int v = 1; v <= n; ++v)
		for (auto u : g[v]) {
			pii hv = h[v], hu = h[u];
			add(hv.f, -p[u].f, mod.f);
			add(hv.s, -p[u].s, mod.s);

			add(hu.f, -p[v].f, mod.f);
			add(hu.s, -p[v].s, mod.s);

			if ((hv != hu && sz(g[v]) > 1 && sz(g[u]) > 1) || (sz(g[v]) > 2  && sz(g[u]) > 2)) {
				puts("YES");
				return;
			}
		}   


	puts("NO");
}

void precalc() {
	p[0] = {1, 1};
	for (int i = 1; i < M; ++i)
		p[i] = {p[i - 1].f * 1ll * base.f % mod.f, p[i - 1].s * 1ll * base.s % mod.s};
}

main () {
	precalc();

	int TT;
	TT = 1;
  	scanf("%d", &TT);
  	
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}