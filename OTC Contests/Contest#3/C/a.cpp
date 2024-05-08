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
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5012;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, x, y, cnt[N];
bitset < N > d, dd;
vi g[N], gg;
 
void dfs (int v, int p = 0) {
	cnt[v] = 1;
	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			cnt[v] += cnt[to];
		}
}


void build (vi v) {
	dd.reset();
	dd[0] = 1;
	for (auto x : v)
		dd |= (dd << x);

	for (int i = 0; i < N; ++i)
		d[i] = (d[i] | dd[i]);	
}

main () {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}

	dfs(1);
	for (int i = 1; i <= n; ++i) {
		gg.clear();
		for (auto j : g[i])
			if (cnt[j] < cnt[i])
				gg.pb(cnt[j]);

		gg.pb(n - cnt[i]);
		build(gg);
	}

	vi ans;
	for (int i = 1; i < n - 1; ++i) 
		if (d[i] || d[n - 1 - i]) 
			ans.pb(i);               
	

	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x << ' ' << n - 1 - x << endl;			
}