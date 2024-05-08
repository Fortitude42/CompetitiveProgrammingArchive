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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, a[N], b[N], ans;
vi order, comp, g[N];
bool was[N];


void dfs (int v) {
    was[v] = 1;
	if (b[v] != -1 && !was[b[v]])
		dfs(b[v]);

	order.pb(v);	
}

void dfs1 (int v) {
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to])
			dfs1(to);

	order.pb(v);				
}


main () {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &b[i]); 
		if (b[i] == i)
			b[i] = -1;
	}

	for (int i = 1; i <= n; ++i)
		if (!was[i])
			dfs(i);



	reverse(all(order));

	for (auto v : order) {
		ans += a[v];
		if (b[v] != -1 && a[v] > 0) {
			g[v].pb(b[v]);
			a[b[v]] += a[v]; 
		} else if (b[v] != -1) 
			g[b[v]].pb(v);				
	}	

	order.clear();
	memset(was, 0, sizeof(was));
	for (int i = 1; i <= n; ++i)
		if (!was[i])
			dfs1(i);
	

	reverse(all(order));
	cout << ans << endl;
	for (auto x : order)
		cout << x << ' ';
}