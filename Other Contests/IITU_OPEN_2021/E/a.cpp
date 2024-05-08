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
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 316;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
 
pii mx;
vi g[N];
int n, m, cnt, d[N];
set < pii > q;
int was[N], ok, timer;
unordered_map < int, bool > gg[N];
 

bool check () {
	vi v;
	for (int i = 1; i <= n; ++i) {
		if (sz(g[i]) < block) {
			for (auto j : g[i])
				for (auto x : g[i])
					if (gg[j].count(x))
						return 1;
		} else  {
			++timer;
			for (auto j : g[i])
				was[j] = timer;

			for (int j = 1; j <= n; ++j)
				for (auto x : g[j])
					if (was[j] == timer && was[x] == timer)
						return 1;
		}
	}

	return 0;
}
 
void dfs1 (int v) {
	++cnt;
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to])
			dfs1(to);			
}
 
main () {
	cin >> n >> m;
	while (m--) {
		int v, u;
		cin >> v >> u;
		if (v < u)
			swap(v, u);
		if (q.count(mp(v, u)))
			continue;
 
		q.insert(mp(v, u));	
		g[v].pb(u);
		g[u].pb(v);
		gg[v][u] = gg[u][v] = 1;
	}
 
	if (check()) {
		cout << 3 << endl;
		return 0;
	}
 
	memset(was, 0, sizeof(was));
	int cnt1 = 0;
 
	for (int i = 1; i <= n; ++i)
		for(auto j : g[i])
		    if(g[i].size() >= 2 && g[j].size() >= 2){
				cout << 4 << endl;
				return 0;
		    }

	for (int i = 1; i <= n; ++i)
		if (!was[i]) {
			cnt = 0;
			dfs1(i);
			if (cnt >= 2)
				++cnt1;
		}

	if (cnt1 > 1) {
		cout << 4 << endl;
		return 0;
	}
	
 
	cout << -1 << endl;
}