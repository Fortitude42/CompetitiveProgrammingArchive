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
const pii base = mp(1e6 + 3, 1e6 + 33), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 800, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, x[42], y[42], p[42], k;
pii c[M];
vi g[M];

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void dfs(int v, int cc = 0) {
	c[v].f = k;
	c[v].s = cc;
	for (auto to : g[v])
		if (!c[to].f)
			dfs(to, cc ^ 1);
		else if (c[to].s == cc) {
			cout << -1;
			exit(0);
		}
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;
	if (rand() & 1)
		swap(v, u);
	p[u] = v;
}
 
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i]; 
		p[i] = i;
	}


	for (int i = 1; i <= m; ++i) {
		cin >> l[i] >> r[i] >> s[i]; 
		if (!s[i])
			merge(l[i] - 1, r[i]);		
	}

	for (int i = 1; i <= m; ++i)
		if (s[i])
			g[get(l[i] - 1)].pb(get(r[i]));

	for (int i = 0; i <= n; ++i) {
	    int j = get(i);

		if (!c[j].f) {
			++k;
			dfs(j);
		}
	}
}

main () {
	precalc();
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}