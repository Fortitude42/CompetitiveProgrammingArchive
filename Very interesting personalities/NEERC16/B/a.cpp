//by paradox & gege & parasat
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
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17, maxn = 4e6;
const ll INF = 1e18;


int n, m, k, C, nxt[M*2][2], x[M*2], nx[M*2], y[M*2], z[M*2], pos[M];
int v[M], u[M], a[M], b[M], na[M], nb[M], comp[maxn];
vi g[maxn], gr[maxn], order;
vector < pii > gg[M*2];
bool was[maxn];
string s[M];
 
int get(const string &s) {
	int v = 0;
	for (int i = 0; i < sz(s); ++i) {
		if (nxt[v][s[i] - '0'] == -1) {
			nxt[v][s[i] - '0'] = ++m;
			x[m] = ++k;
			nx[m] = ++k;
			y[m] = ++k;
			z[m] = ++k;
		}
		v = nxt[v][s[i] - '0'];
	}

	return v;
}

void addEdge(int v, int u) {
	g[v].pb(u);
	gr[u].pb(v);
}

void dfs(int v, int p = -1) {
	if (v > 0) {
		addEdge(x[v], y[v]);
		addEdge(x[v], z[v]);
		for (int i = 0; i < sz(gg[v]); ++i) {
			addEdge(nx[v], gg[v][i].s); 
			addEdge(gg[v][i].f, x[v]);
		}


		vi pref(sz(gg[v])), suff(sz(gg[v]));
		for (int i = 0; i < sz(pref); ++i) {
			pref[i] = ++k; 
			if (i > 0)
				addEdge(pref[i], pref[i - 1]);
			addEdge(pref[i], gg[v][i].s);
		}

		for (int i = sz(suff) - 1; i >= 0; --i) {
			suff[i] = ++k;
			if (i + 1 < sz(suff))
				addEdge(suff[i], suff[i + 1]);
			addEdge(suff[i], gg[v][i].s);
		}

		for (int i = 0; i < sz(gg[v]); ++i) {
			if (i > 0)
				addEdge(gg[v][i].f, pref[i - 1]);
			
			if (i + 1 < sz(gg[v]))
				addEdge(gg[v][i].f, suff[i + 1]);
		}
			

	}
	
	if (p > 0) {
		addEdge(z[v], nx[p]);
		addEdge(z[v], z[p]);
		addEdge(y[p], y[v]);
		addEdge(y[p], nx[v]);
	}

	for (int i = 0; i < 2; ++i) {
		int to = nxt[v][i];
		if (to != -1)
			dfs(to, v);
	}
}

void dfs1(int v) {
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to])
			dfs1(to);
	order.pb(v);
}

void dfs2 (int v) {
	comp[v] = C;
	for (auto to : gr[v])
		if (!comp[to])
			dfs2(to);
}

void solve() {
	memset(nxt, -1, sizeof(nxt));

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		pos[i] = -1;
		for (int j = 0; j < sz(s[i]); ++j)
			if (s[i][j] == '?') {
				pos[i] = j;
				break;
			}

		a[i] = ++k;
		na[i] = ++k;

		if (pos[i] == -1) {
			v[i] = get(s[i]);
			addEdge(na[i], a[i]);
			gg[v[i]].pb({a[i], na[i]});
		} else {
			s[i][pos[i]] = '0';
			v[i] = get(s[i]);
			gg[v[i]].pb({a[i], na[i]});
		
			b[i] = ++k;
			nb[i] = ++k;
			s[i][pos[i]] = '1';
			u[i] = get(s[i]);
			gg[u[i]].pb({b[i], nb[i]});
			addEdge(na[i], b[i]);
			addEdge(nb[i], a[i]);
		}
	}

	dfs(0);
	for (int i = 1; i <= k; ++i)
		if (!was[i])
			dfs1(i);

	reverse(all(order));

	for (auto i : order)
		if (!comp[i]) {
			++C;
			dfs2(i);
		}

	for (int i = 1; i <= m; ++i) {
		if (comp[x[i]] == comp[nx[i]]) {
			cout << "NO";
			return;
		}

	}

	for (int i = 1; i <= n; ++i)
		if (comp[a[i]] == comp[na[i]] || (b[i] > 0 && comp[b[i]] == comp[nb[i]])) {
			cout << "NO";
			return;
		}

	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		if (pos[i] != -1) {
			if (comp[a[i]] > comp[na[i]])
				s[i][pos[i]] = '0';
			else
				s[i][pos[i]] = '1';
		}

		cout << s[i] << endl;

	}
}

main () {
//	file("binary");
	fastio
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
