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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, x[M], y[M], p[M];
vi valx, valy;
vi gx[M], gy[M];


bool cmp(int i, int j) {
	return mp(x[i], y[i]) < mp(x[j], y[j]);
}

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
	for (int i = 1; i <= n; ++i){ 
		p[i] = i;
		cin >> x[i] >> y[i];
		valx.pb(x[i]);
		valy.pb(y[i]);
	}

	sort(all(valx));
	valx.resize(unique(all(valx)) - valx.begin());

	sort(all(valy));
	valy.resize(unique(all(valy)) - valy.begin());

	for (int i = 1; i <= n; ++i) {
		x[i] = lower_bound(all(valx), x[i]) - valx.begin();
		y[i] = lower_bound(all(valy), y[i]) - valy.begin();

		gx[x[i]].pb(i);
		gy[y[i]].pb(i);
	}

	ll ans = 0;
	vector < pair < int, pii > > e;
	for (int i = 0; i < n; ++i) {
		sort(all(gx[i]), cmp);
		sort(all(gy[i]), cmp);  


		if (sz(gx[i]) % 2 == 1) {
			cout << 0;
			return;
		}
		                          
		for (int j = 0; j < sz(gx[i]); j += 2) {
			merge(gx[i][j], gx[i][j + 1]);
			ans += abs(valy[y[gx[i][j]]] - valy[y[gx[i][j + 1]]]);
			if (j + 2 < sz(gx[i]))
				e.pb(mp(abs(valy[y[gx[i][j + 2]]] - valy[y[gx[i][j + 1]]]), mp(gx[i][j + 2], gx[i][j + 1])));			
		}

		if (sz(gy[i]) & 1) {
			cout << 0;
			return;
		}

		for (int j = 0; j < sz(gy[i]); j += 2) {
			merge(gy[i][j], gy[i][j + 1]);
			ans += abs(valx[x[gy[i][j]]] - valx[x[gy[i][j + 1]]]);
			if (j + 2 < sz(gy[i]))
				e.pb(mp(abs(valx[x[gy[i][j + 2]]] - valx[x[gy[i][j + 1]]]), mp(gy[i][j + 2], gy[i][j + 1])));			
		}
	}



	sort(all(e));
	for (auto x : e)
		if (get(x.s.f) != get(x.s.s)) {
			merge(x.s.f, x.s.s);
			ans += 2*x.f;
		}

	for (int i = 2; i <= n; ++i)
		if (get(i) != get(1)) {
			cout << 0;
			return;
		}

	cout << ans << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}