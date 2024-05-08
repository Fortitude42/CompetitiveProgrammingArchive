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

int n, m, q, p[N], ok, c[N], tp;
map < string, int > id;
string a[N], s, t;
vi comp[N];

int get (int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}

void merge (int v, int u, int x) {
	int V = v, U = u;
	v = get(v), u = get(u);

	if (v == u) {
	    if (c[V]^c[U] != x) 
			ok = 0;
		return;
	}

	if (sz(comp[v]) < sz(comp[u]))
		swap(v, u);

	p[u] = v;

	int tt = ((c[V]^c[U]) != x);
	while (sz(comp[u])) {
		int x = comp[u].back();
		c[x] ^= tt;
		comp[v].pb(x);	
		comp[u].ppb();
	}
	
}

main () {
	fastio
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];             
		id[a[i]] = i;
		p[i] = i;
		comp[i].pb(i);
	}

	while (m--) {
		cin >> tp >> s >> t;
		--tp;
		ok = 1;
		merge(id[s], id[t], tp);
		puts(ok ? "YES" : "NO");
	}                                                 
	
	while (q--) {
		cin >> s >> t;
		int S = id[s], T = id[t];
		if (get(S) != get(T))
			puts("3");
		else if (c[S] == c[T]) 
			puts("1");	
		else 
			puts("2");
	}
}