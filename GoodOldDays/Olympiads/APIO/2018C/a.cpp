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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 

int n, m, v, u, k, col[N], kk, cnt1[N];
int tin[N], fup[N], timer, cnt[N];
stack < int > st;
vi g[N], gg[N];
bool was[N];
ll ans;

void addEdge (int v, int u) {
	gg[v].pb(u);
	gg[u].pb(v);
	col[u] = col[v];
}


void dfs (int v, int p = 0) {
    if (p)
		st.push(v);
	
	tin[v] = fup[v] = ++timer;
	col[v] = kk;
	++cnt1[kk];

	for (auto to : g[v])
		if (to != p) {
			if (tin[to])
				fup[v] = min(fup[v], tin[to]);
			else {
				dfs(to, v);
				fup[v] = min(fup[v], fup[to]);
				if (fup[to] >= tin[v]) {
					++k;
					addEdge(v, k);
					while (1) {
						int u = st.top();
						st.pop();
						addEdge(u, k);
						if (u == to)
							break;
					}
				}
			}
		}

}

ll get (int x) {
	return x * 1ll * (x - 1);
}


void dfs1 (int v, int p = 0) {
	was[v] = 1;
	cnt[v] = (v <= n);

	for (auto to : gg[v])
		if (to != p) {
			dfs1(to, v);
			cnt[v] += cnt[to];
		}

	if (v <= n) {
		for (auto to : gg[v])
			if (to == p) {
//				cerr << v << ' ' << to << ' ' << get(cnt[v]) << ' ' << (sz(gg[to]) - 1) << endl;
				ans -= get(cnt[v]) * (sz(gg[to]) - 1);
			} else {
//				cerr << v << ' ' << to << ' ' << get(cnt1[col[v]] - cnt[to]) << ' ' << (sz(gg[to]) - 1) << endl;
				ans -= get(cnt1[col[v]] - cnt[to]) * (sz(gg[to]) - 1);
			}		
	}
}


main () {
	fastio
	cin >> n >> m;
	while (m--) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	k = n;
	
	for (int i = 1; i <= n; ++i)
		if (!tin[i]) {
			++kk;
			dfs(i);			
			ans += 1ll * cnt1[kk] * (cnt1[kk] - 1) * (cnt1[kk] - 2);
		}


	for (int i = 1; i <= n; ++i)
		if (!was[i]) {
			dfs1(i); 
		}

	cout << ans << endl;
}