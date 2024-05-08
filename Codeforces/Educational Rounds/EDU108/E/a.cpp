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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, d[N*2];
pll e[N], f[N];
bool used[N*2];
vpii g[N*2], ans;
map < pll, int > id;

int dfs (int v, int p = 0, int e = 0) {
	used[v] = 1;
	d[v] = d[p] + 1;
	int lst = -1;
	for (auto x : g[v]) {
		int to = x.f, i = x.s;
		if (!used[to]) 
			i = dfs(to, v, i);

		if (d[to] < d[v] || i == -1)
			continue;
		
		if (lst == -1) 
			lst = i;
		else {
			ans.pb({lst, i});
			lst = -1;
		}
	}

	if (p) {
		if (lst == -1)
			lst = e;
		else {
			ans.pb({lst, e});
			lst = -1;
		}
	}

	return lst;
} 


main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		
		ll A = (a + b) * 1ll * d;
		ll B = b * 1ll * c;
		ll G = __gcd(A, B);
		A /= G;
		B /= G;
		if (B < 0) {
			A = -A;
			B = -B;
		}

		e[i] = {A, B};

		A = a * 1ll * d;
		B = b * 1ll * (c + d);
		G = __gcd(A, B);
		A /= G;
		B /= G;
		if (B < 0) {
			A = -A;
			B = -B;
		}

		f[i] = {A, B};
	}

	for (int i = 1; i <= n; ++i) {
		if (!id.count(e[i]))
			id[e[i]] = ++m;
		if (!id.count(f[i]))
			id[f[i]] = ++m;

		g[id[e[i]]].pb({id[f[i]], i});
		g[id[f[i]]].pb({id[e[i]], i});
	}

	for (int i = 1; i <= m; ++i)
		if (!used[i]) 
			dfs(i);

	printf("%d\n", sz(ans));
	for (auto x : ans)	
		printf("%d %d\n", x.f, x.s);
		
}