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

int n, m, d[M], par[M];
bool used[M];
pair < int, pii > mn[M], mn1[M], mx[M], mn2[M], mx1[M];
vi g[M];

void dfs(int v, int p = 0) {
	par[v] = p;
	d[v] = d[p] + 1;
	mn[v] = mp(d[v], mp(v, v));
	mx[v] = mx1[v] = mp(-inf, mp(-inf, -inf));
	mn1[v] = mp(d[v], mp(v, v));
	mn2[v] = mp(d[v], mp(v, v));
	used[v] = 1;

	for (auto to : g[v])
		if (to != par[v]) {
			if (used[to]) {
				pair < int, pii > cur = mp(d[to], mp(to, v));
				mn[v] = min(mn[v], cur);
				if (d[to] < d[v]) {
					if (cur > mx[v]) {
						mx1[v] = mx[v];
						mx[v] = cur;
					} else
						mx1[v] = max(mx1[v], cur);
				}
			} else {
				dfs(to, v);
				if (mn[to] < mn1[v]) {
					mn2[v] = mn1[v];
					mn1[v] = mn[to];
				} else
					mn2[v] = min(mn2[v], mn[to]);
			}
		}

	mn[v] = min(mn[v], mn1[v]);
}

vi getPath(int a, int b) {
	bool rev = 0;
	if (d[a] < d[b]) {
		swap(a, b);
		rev = 1;
	}
	vi p;
	while (a != b) {
		p.pb(a);
		a = par[a];
	}

	p.pb(a);
	if (rev)
		reverse(all(p));
	return p;
}

 
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		used[i] = 0;
	}

	while (m--) {
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	for (int i = 1; i <= n; ++i)
		if (!used[i])
			dfs(i);

	for (int v = 1; v <= n; ++v) {
		int a = mx[v].s.f;
		int b = mn1[v].s.f;
		int to = mn1[v].s.s;

		if (a == -inf || d[b] > d[a])
			continue;

		vi p[3], tmp;

		p[0] = {v, a};

		p[1] = getPath(v, a);

		p[2] = getPath(v, to);
		tmp = getPath(b, a);
		
		for (auto x : tmp)
			p[2].pb(x);

		cout << v << ' ' << a << endl;
		for (int i = 0; i < 3; ++i) {
			cout << sz(p[i]) << ' ';
			for (auto j : p[i])
				cout << j << ' ';
			cout << endl;
		}
		return;
	}

	for (int v = 1; v <= n; ++v) {
		int a = mx[v].s.f;
		int b = mn1[v].s.f;               
		int to = mn1[v].s.s;

		if (a == -inf || d[b] >= d[v])
			continue;

		vi p[3], tmp;

		p[0] = getPath(v, b);

		p[1] = {v};
		tmp = getPath(a, b);
		for (auto x : tmp)
			p[1].pb(x);

		p[2] = getPath(v, to);
		p[2].pb(b);

		cout << v << ' ' << b << endl;
		for (int i = 0; i < 3; ++i) {
			cout << sz(p[i]) << ' ';
			for (auto j : p[i])
				cout << j << ' ';
			cout << endl;
		}
		return;
	}
//	cerr << "hello\n";

	for (int v = 1; v <= n; ++v) {
		int a = mn1[v].s.s;
		int pa = mn1[v].s.f;
		int b = mn2[v].s.s;
		int pb = mn2[v].s.f;

		if (a == v || b == v || d[pb] >= d[v])
			continue;

		vi p[3], tmp;
		p[0] = getPath(v, pb);
		p[1] = getPath(v, b);
		p[1].pb(pb);

		p[2] = getPath(v, a);
		tmp = getPath(pa, pb);
		for (auto x : tmp)
			p[2].pb(x);

		cout << v << ' ' << pb << endl;
		for (int i = 0; i < 3; ++i) {
			cout << sz(p[i]) << ' ';
			for (auto j : p[i])
				cout << j << ' ';
			cout << endl;
		}
		return;
	}

	for (int v = 1; v <= n; ++v) {
		int a = mx[v].s.f, b = mx1[v].s.f;
		if (b == -inf)
			continue;
		vi p[3], tmp;
		p[0] = getPath(v, a);
		p[1] = {v, a};
		p[2] = {v};
		tmp = getPath(b, a);
		for (auto x : tmp)
			p[2].pb(x);

		cout << v << ' ' << a << endl;
		for (int i = 0; i < 3; ++i) {
			cout << sz(p[i]) << ' ';
			for (auto j : p[i])
				cout << j << ' ';
			cout << endl;
		}
		return;		
	}


		
	cout << -1 << endl;
}

main () {
	//file("grand")
  int TT = 1;
  	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}