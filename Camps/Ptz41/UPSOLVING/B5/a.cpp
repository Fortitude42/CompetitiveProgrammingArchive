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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, p, q, prv[N], nxt[N], par[N];
queue < int > Q;
vi g[N];

int get(int v) {
	return par[v] == v ? v : par[v] = get(par[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);

	if (v == u)
		return;

	if (sz(g[v]) < sz(g[u]))
		swap(v, u);

	while (sz(g[u])) {
		int x = g[u].back();
		g[v].pb(x);
		Q.push(x);
		Q.push(x - p);
		Q.push(x + p);
		Q.push(x + q);
		Q.push(x - q);
		g[u].ppb();
	}

	par[u] = v;
}

int Nxt(int pos) {
	vi v;
	if (pos + p < n && (prv[pos + p] == -1 || prv[pos + p] == pos) && get(pos + p) != get(pos))
		v.pb(pos + p);

	if (pos - q >= 0 && (prv[pos - q] == -1 || prv[pos - q] == pos) && get(pos - q) != get(pos))
		v.pb(pos - q);
	return sz(v) == 1 ? v[0] : -1;
}


void add(int v) {
	if (v < 0 || v >= n || nxt[v] != -1)
		return;

	nxt[v] = Nxt(v);
	if (nxt[v] != -1) {
		prv[nxt[v]] = v;
		merge(v, nxt[v]);
	}
}

main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &p, &q);
		for (int i = 0; i < n; ++i) {
			prv[i] = nxt[i] = -1;    
			par[i] = i;
			g[i].clear();
			g[i].pb(i);
		}

		for (int i = 0; i < n; ++i) 
			Q.push(i);

		while (sz(Q)) {
	 		add(Q.front());
			Q.pop();
		}
		

		int fst = -1;
		for (int i = 0; i < n && fst != -2; ++i)
			if (prv[i] == -1) 
				fst = fst == -1 ? i : -2;

		if (fst == -2) 
			printf("-1\n");
		else {
			while (fst != -1) {
				printf("%d ", fst); 
				fst = nxt[fst];
			}
			printf("\n");
		}
	}
}