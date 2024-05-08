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

int n, p[M];
vector < pii > g[2];
vector < pair < pii, int > > gg[2];

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
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
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		int c, l, r;
		cin >> c >> l >> r;
		g[c].pb({l, i});
		g[c].pb({r, i});
		gg[c].pb({{l, r}, i});
	}

	for (int i = 0; i < 2; ++i) {
		if (!sz(g[i]))
			continue;

		sort(all(g[i]));
		vi s(sz(g[i]) - 1);
		for (auto x : gg[i ^ 1]) {
			int l = lower_bound(all(g[i]), mp(x.f.f, 0)) - g[i].begin();
			int r = lower_bound(all(g[i]), mp(x.f.s + 1, 0)) - g[i].begin() - 1;

			if (l > r)
				continue;

			merge(x.s, g[i][l].s);
			++s[l];
			if (r < sz(g[i]))
				--s[r];
		}

		for (int j = 0; j + 1 < sz(g[i]); ++j) {
			if (j)
				s[j] += s[j - 1];

			if (s[j])
				merge(g[i][j].s, g[i][j + 1].s);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (i == get(i))
			++ans;

	cout << ans << endl;

	for (int x = 0; x < 2; ++x){
		g[x].clear();
		gg[x].clear();
	}
}

main () {
	int TT;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}

