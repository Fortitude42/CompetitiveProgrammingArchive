//template by paradox & gege & parasat
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

ll ans;
bool f;
int n, m, p[M];
set < int > q, g[M];
vector < pair < int, pii > > e;

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u, int w, bool ok = 0) {
	v = get(v), u = get(u);

	if (v == u) {
	    if (!w)
			f |= ok;
		return;   
	}

	ans += w;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}

void dfs(int v) {
	q.erase(v);
	
	g[v].insert(v);
	while (sz(g[v])) {
		int u = *g[v].begin();
		g[v].erase(u);
		
		while (sz(q) && *q.rbegin() > u) {
			int x = *q.upper_bound(u);
			if (g[v].count(x))
				break;


			merge(v, x, 0);
			dfs(x);
		}
	}
}
 
void solve() {
	scanf("%d%d", &n, &m);
	int S = 0;
	while (m--) {
		int v, u, x;
		scanf("%d%d%d", &v, &u, &x);
		e.pb({x, {v, u}});
		S ^= x;

		g[v].insert(u);
		g[u].insert(v);
	}

	for (int i = 1; i <= n; ++i) {
		q.insert(i); 
		p[i] = i;
	}

	int a = 1, b = 2;
	while (!f) {
		++b;
		if (b == n + 1) {
			if (a == n - 1)
				break;

			a++;
			b = a + 1;
			continue;
		}

		if (g[a].count(b))
			continue;
		merge(a, b, 0, 1);
	}

	for (int i = 1; i <= n; ++i)
		if (q.count(i))
			dfs(i);
	
	sort(all(e));
	for (auto x : e)
		merge(x.s.f, x.s.s, x.f);

	if (!f)
		ans += S;
	printf("%lld\n", ans);
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}