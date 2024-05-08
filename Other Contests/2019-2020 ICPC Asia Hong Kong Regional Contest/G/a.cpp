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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int k, n, c[N], p[N], dp[N], d[N];
vi g[N];

void dfs (int v) {
	d[v] = 0;
	if (!sz(g[v])) {
		dp[v] = c[v];
		d[v] = 1;
		return;
	}

	int sum = 0;
	for (auto to : g[v]) {
		dfs(to);
		sum += dp[to];
	}
	
	dp[v] = min(c[v], sum);
	if (dp[v] == c[v])
		++d[v];

	if (dp[v] == sum) {
		int p = 1;
		for (auto to : g[v])
			p *= d[to];

		d[v] += p;
	}
}   	


void build (int v, int cost, int k) {
	c[v] = cost + 1;
	if (k & 1) {
		c[v]--;  
		k--;
	}
	
	if (!k)
		return;

	p[++n] = v;
	p[++n] = n - 1;
	c[n] = c[n - 1] = 1;
	
	p[++n] = v;
	build(n, cost - 1, k / 2);
}

main () {
	fastio
	srand(time(0));
	for (int k = 2; k < N; ++k) {
		for (int x = 0; x < 1000; ++x)
			g[x].clear();

		
		n = 1;

		build(1, inf - 1, k);
/*		cout << n << endl;
		for (int i = 2; i <= n; ++i)
			cout << p[i] << ' ';
		cout << endl;
		for (int i = 1; i <= n; ++i)
			cout << c[i] << ' ';*/
		dfs(1);

		if (d[1] != k) {
			cout << k << ' ' << d[1] << endl;
			return 0;
		}
	}
}