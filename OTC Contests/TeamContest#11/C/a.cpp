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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, v, u, t[N], timer, p[N], tt[N], ttimer;
vi g[N], gg[N]; 

bool try_kuhn (int v) {
	if (tt[v] == ttimer)
		return 0;

	tt[v] = ttimer;
	for (auto to : gg[v])
		if (p[to] == -1) {
			p[to] = v;
			p[v] = to;
			return 1;	
		}

	for (auto to : gg[v])
		if (try_kuhn(p[to])) {
			p[to] = v;
			p[v] = to;
			return 1;
		}	

	return 0;
}

main () {
	cin >> n >> m;
	while (m--) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	for (int i = 1; i <= n; ++i) {
		if (sz(g[i]) * 2 < n - 1)
			continue;
		
		++timer;
		for (auto j : g[i])
			t[j] = timer;

		for (int i = 1; i <= n; ++i) 
			gg[i].clear();
		
		for (int j = 1; j <= n; ++j)
			for (auto x : g[j]) {
			    if (j == i || x == i)
			    	continue;
				if ((t[j] == timer && t[x] != timer) || (t[x] == timer && t[j] != timer))
					gg[x].pb(j); 
			}


		memset(p, -1, sizeof(p));

		bool run;

		do {
			run = 0;
			++ttimer;
			for (int j = 1; j <= n; ++j)
				if (i != j && p[j] == -1 && try_kuhn(j))
					run = 1;
		} while (run);

		bool ok = 1;

		for (int j = 1; j <= n; ++j)
			if (i != j && t[j] != timer && p[j] == -1) {
				ok = 0;
				break;
			}

		if (ok) {
			cout << "Yes\n";
			vpii ans;
			for (int j = 1; j <= n; ++j)
				if (p[j] != -1 && j < p[j])
					ans.pb({j, p[j]});
				else if (p[j] == -1 && j != i)
					ans.pb({j, -1});	

			cout << i << ' ' << sz(ans) << endl;
			for (auto x : ans)
				cout << x.f << ' ' << x.s << endl;

			return 0;
		}
	}

	cout << "No";
}