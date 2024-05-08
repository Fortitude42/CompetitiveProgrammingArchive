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
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi g[M], order, comp;
int n, cnt[M];
bool was[M];

void dfs(int v) {
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to])
			dfs(to);

	order.pb(v);
}

void dfs1(int v) {
	comp.pb(v);
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to]) {
			dfs1(to);
			++cnt[v];
			++cnt[to];
		}
}
 
void solve(int tt) {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		v++, u++;
		g[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
		if (!was[i])
			dfs(i);
	
	reverse(all(order));
	memset(was, 0, sizeof(was));
	int ans = 0;

	for (auto x : order)
		if (!was[x]) {
			comp.clear();
			dfs1(x);
			cerr << x << endl;
			if (sz(comp) == 1)
				++ans;
			else {
				int ls = 0;
				for (auto y : comp)
					if (cnt[y] == 1)
						++ls;
				ans += (ls + 1) / 2;
			}
		}
			
	printf("Case %d: %d\n", tt, ans);

	order.clear();
	for (int i = 1; i <= n; ++i) {
		was[i] = 0;
		cnt[i] = 0;
		g[i].clear();
	}
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve(tt);
	}
}

