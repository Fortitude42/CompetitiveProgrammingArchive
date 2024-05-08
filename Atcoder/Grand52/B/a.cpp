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
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, x[N], y[N];
vector < pair < int, pii > > g[N];

void dfs (int v, int p = 0) {
	for (auto X : g[v]) {
		int to = X.f, a = X.s.f, b = X.s.s;
		if (to == p)
			continue;
		
		x[to] = x[v] ^ a;
		y[to] = y[v] ^ b;
		dfs(to, v);
	}
}

main () {
	cin >> n;
	for (int i = 1, a, b, c, d; i < n; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		g[a].pb({b, {c, d}});
		g[b].pb({a, {c, d}});
	}

	dfs(1);	
	int w = 0;
	for (int i = 1; i <= n; ++i) {
		w ^= x[i];
		w ^= y[i];
	}

	for (int i = 1; i <= n; ++i)
		y[i] ^= w;

	sort(x + 1, x + 1 + n);
	sort(y + 1, y + 1 + n);
	for (int i = 1; i <= n; ++i)
		if (x[i] != y[i]) {
			puts("NO");
			return 0;
		}

	puts("YES");
}