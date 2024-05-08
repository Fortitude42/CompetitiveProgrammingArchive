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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, a[M], b[M], was[M], timer, ans[M], id[M], d[M][2];
queue < int > q[2];
vi g[M], v;


	
void calc(const vi &v, const vi &vv) {
	int len = sz(vv);
	if (len == 3) {
		for (auto x : v)
			ans[x] = 1; 	
		return;
	}

	++timer;
	for (int i = 0; i < len; ++i) {
		was[vv[i]] = timer; 
		id[vv[i]] = i;
	}
	vector < pii > edges;
	
	for (auto x : vv)
		for (int j = 0; j < sz(g[x]); ++j) {
			int y = g[x][j];
			if (was[y] != timer) {
				edges.pb({x, y});
				swap(g[x][j], g[x].back());
				g[x].ppb();
				j--;
			}
		}

	
	pair < int, pii > dv = mp(-1, mp(-1, -1));
	for (auto x : vv)
		for (auto y : g[x]) {
//			if (was[y] != timer)
//				continue;
			int idx = id[x], idy = id[y];
			if (idx < idy)
				swap(idx, idy);

			int len1 = idx - idy + 1;
			len1 = min(len1, len - len1 + 2);

			dv = max(dv, mp(len1, mp(idx, idy)));
		}

	
	int idx = dv.s.f, idy = dv.s.s;

	for (auto x : vv)
		for (int j = 0; j < 2; ++j)
			d[x][j] = -1;
	
	q[0].push(vv[idx]);
	d[vv[idx]][0] = 0;

	q[1].push(vv[idy]);
	d[vv[idy]][1] = 0;

	for (int j = 0; j < 2; ++j) 
		while (sz(q[j])) {
			int v = q[j].front();


			q[j].pop();

			for (auto to : g[v]) {
				if (d[to][j] == -1) {
					d[to][j] = d[v][j] + 1;
					q[j].push(to);
				} 
			}
		}
	
	vi va, vb;
	for (auto x : v) {
		int ida = id[a[x]], idb = id[b[x]];
		if (ida < idb)
			swap(ida, idb);

		if (ida == idx && idb == idy) {
			ans[x] = 1;
			continue;
		}

		bool pa = (idy <= ida && ida <= idx);
		bool pb = (idy <= idb && idb <= idx);

		if (pa != pb) {
			ans[x] = min(d[vv[ida]][0] + d[vv[idb]][0], d[vv[ida]][1] + d[vv[idb]][1]);
			continue;
		}

		if (pa)
			va.pb(x);
		else
			vb.pb(x);	
	}

	vi vva, vvb;
	for (int i = idy; i <= idx; ++i)
		vva.pb(vv[i]);

	for (int i = 0; i <= idy; ++i)
		vvb.pb(vv[i]);
	for (int i = idx; i < sz(vv); ++i)
		vvb.pb(vv[i]);

	calc(va, vva);
	calc(vb, vvb);

	for (auto e : edges)
		g[e.f].pb(e.s);
}
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n - 3; ++i) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	vi v, vv;
	for (int i = 0; i < n; ++i) {
		vv.pb(i);
		g[i].pb((i + 1) % n); 
		g[i].pb((i + n - 1) % n);
	}


	cin >> m;
	for (int i = 1; i <= m; ++i) {
	    cin >> a[i] >> b[i];
	    a[i]--, b[i]--;
	    if (a[i] != b[i])
			v.pb(i); 		
	}
		
	calc(v, vv);
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << endl;
}

main () {
//	file("distance");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

