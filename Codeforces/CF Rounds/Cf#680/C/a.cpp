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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, k, c[N], cl[N], cl1[N], kk;
vi g[N], cc[N], gg[N]; 
map < int, vpii > G[N], GG[N];
bool bad[N];
int v, u;

void dfs (int v, int C) {
	cl[v] = C;
	cl1[v] = kk;

	for (auto to : g[v]) {
		if (c[v] != c[to])
			continue;
		if (cl[to] == -1)
			dfs(to, C ^ 1);
		else if (cl[to] == cl[v]) 
			bad[c[to]] = 1;
	}
}   	

main () {
	memset(cl, -1, sizeof(cl));

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);       
		cc[c[i]].pb(i);
	}

	while (m--) {
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);

		if (c[v] == c[u])
			continue;

		if (c[v] > c[u])
			swap(v, u);


		gg[c[v]].pb(c[u]);
		G[c[v]][c[u]].pb({v, u});
	}			                                                 


	
	for (int i = 1; i <= k; ++i)
		for (auto j : cc[i])
			if (cl[j] == -1) {
			    ++kk;
				dfs(j, 0);    
			}


	ll ans = k * 1ll * (k - 1) / 2;
	int cnt = 0;
	for (int i = 1; i <= k; ++i)
		if (bad[i])
			++cnt;

	ans -= cnt * 1ll * (k - 1);
	ans += cnt * 1ll * (cnt  - 1) / 2;


	for (int i = 1; i <= k; ++i) {
		sort(all(gg[i]));
		gg[i].resize(unique(all(gg[i])) - gg[i].begin());

		for (auto j : gg[i]) {
			if (bad[i] || bad[j]) 
				continue;			
			bool badd = 0;

			set < pii > q;
			for (auto x : G[i][j]) {
				GG[cl1[x.f]][cl1[x.s]].pb({cl[x.f], cl[x.s]});
				q.insert(mp(cl1[x.f], cl1[x.s]));
			}

			for (auto x : q) {
				bool ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0;
				for (auto y : GG[x.f][x.s]) {
					if (y.f == 0 && y.s == 0)
						ok1 = 1;
					if (y.f == 0 && y.s == 1)
						ok2 = 1;
					if (y.f == 1 && y.s == 0)
						ok3 = 1;
					if (y.f == 1 && y.s == 1)
						ok4 = 1;
				}

				if ((ok1 && ok2) || (ok3 && ok4))	
					badd = 1;
			}

			if (badd)
				--ans;
			else
				cerr << i << ' ' << j << endl;	
		}
	}

	cout << ans << endl;
}