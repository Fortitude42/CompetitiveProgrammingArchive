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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, q, cnt[N], p[N], d[N];
int tin[N], tout[N], timer, par[N];
vpii e, ee;
vi g[N];

int get(int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
} 

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}

void dfs(int v, int p = 0) {
	par[v] = p;
	d[v] = d[p] + 1;
	tin[v] = ++timer;

	for (auto to : g[v])
		if (to != p) 
			dfs(to, v);
		
	tout[v] = timer;
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}


main () {
	scanf("%d%d", &n, &m);
	while (m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		e.pb({v, u});
	}
	
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		ee.pb({a, b});
		++cnt[a], ++cnt[b];
	}

	int cnt1 = 0;
	for (int i = 1; i <= n; ++i)
		if (cnt[i] & 1)
			++cnt1;
	
	if (cnt1) {
		cout << "NO\n";
		cout << cnt1 / 2 << endl;
		return 0;
	}


	for (int i = 1; i <= n; ++i)
		p[i] = i;


	for (auto x : e) 
		if (get(x.f) != get(x.s)) {
			merge(x.f, x.s);
			g[x.f].pb(x.s);
			g[x.s].pb(x.f);
//			cerr << x.f << ' ' << x.s << endl;
		}

	dfs(1);			
	cout << "YES\n";
	
	for (auto x : ee) {
		int a = x.f, b = x.s;
		vi aa, bb;

		while (b != a && upper(b, a)) {
			aa.pb(a);
			a = par[a];
		}

		while (!upper(a, b)) {
			aa.pb(a);
			a = par[a];
		}
		aa.pb(a);

		while (b != a) {
			bb.pb(b);
			b = par[b];
		}
		printf("%d\n", sz(aa) + sz(bb));

    	for (auto x : aa)
			printf("%d ", x);
		reverse(all(bb));
		for (auto x : bb)
			printf("%d ", x);
		printf("\n");
    }
}	
